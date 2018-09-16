#include "hel_wrapper.h"
#include "../hel_lib/hel_execute.h"
#include "../hel_lib/scores_example.h"

void bruteforce(void *scores, unsigned char *pt1, unsigned char *pt2,
                unsigned char *ct1, unsigned char *ct2, int *found,
                int merge_value, int nb_bins, int bit_bound_start,
                int bit_bound_end) {

  // NOTE: this code was mainly adapted from the example
  // hel_lib/main_example.cpp
  
  int i;

  double **log_proba = NULL; // will contain the initial log probas
  int *real_key =
      NULL; // will contain the real key (optional for key enumeration)
  hel_result_t *result = NULL; // will contain the results of either rank
                               // estimation or key enumeration

  unsigned char kk[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  // real key of the simulated results

  unsigned char **texts = (unsigned char **)malloc(4 * sizeof(unsigned char *));
  for (i = 0; i < 4; i++) {
    texts[i] = (unsigned char *)malloc(16 * sizeof(unsigned char));
  }
  for (i = 0; i < 16; i++) {
    texts[0][i] = pt1[i];
    texts[1][i] = pt2[i];
    texts[2][i] = ct1[i];
    texts[3][i] = ct2[i];
  }
  // load the plaintext ciphertext into a single unsigned char**
  // the form is the following => texts[0] contains the first plaintext, and
  // tests[1] the associated ciphertext
  // texts[2] contains the 2nd plaintext and test[3] the associated ciphertext

  real_key = (int *)malloc(16 * sizeof(int));
  for (i = 0; i < 16; i++) {
    real_key[i] = (int)kk[i];
  }
  // load the real subkey dval_to_printues

  // log_proba = get_scores_from_example(21);
  log_proba = (double **)malloc(NB_SUBKEY_INIT * sizeof(double *));

  for (i = 0; i < NB_SUBKEY_INIT; i++) {
    log_proba[i] = (double *)malloc(NB_KEY_VALUE_INIT * sizeof(double));
  }

  for (int i = 0; i < NB_SUBKEY_INIT; i++)
    for (int j = 0; j < NB_KEY_VALUE_INIT; j++)
      log_proba[i][j] = ((double *)scores)[i * NB_KEY_VALUE_INIT + j];

  // load log probas from examples where the real key depth is around 2^21
  // function defined in score_example.cpp
  // parameter: the approximated rank of the real key.
  // 6 possibles log probas are provided with a key depth of (approximatively)
  // 10,21,25,29,34 and 39.

  // one can instead load its own attack result (and the associated true subkeys
  // if needed and the associated plaintexts/ciphertexts for key testing on the
  // fly

  // STARTING DECLARATION OF INPUT PARAMETERS
  /*int nb_bin;*/
  /*int merge;*/
  ZZ bound_start;
  ZZ bound_stop;
  int to_bound;
  int test_key;
  int to_real_key;
  // ENDING DECLARATION OF INPUT PARAMETERS

  // STARTING DECLARATION OF OUTPUT PARAMETERS
  ZZ rank_estim_rounded, rank_estim_min, rank_estim_max;
  double time_rank;
  double time_preprocessing;
  double time_enum;
  ZZ rank_enum_rounded, rank_enum_min, rank_enum_max;
  // ENDING DECLARATION OF OUTPUT PARAMETERS

  ZZ two;
  two = 2; // used to compute the bound_start and bound_end using two^(integer)
  // note that the bounds can be any number (not especially a power of two)

  RR rval_to_print; // to convert some ZZ to RR
  RR rr_log2 = log(conv<RR>(two)); // log2 as RR
  //(5) => enumerate up to the real key if it is ranked less than "bound_stop".
  // keys are tested with AES and (thus) defactorized

  /*nb_bin = 2048;*/
  /*merge = 1;*/
  test_key = 1; // has no effect with "to_real_key > 0"
  to_bound = 0; // has no effect with "to_real_key > 0"
  to_real_key = 0;
  bound_start = power(two, bit_bound_start);
  bound_stop = power(two, bit_bound_end);
  // setting enumeration parameters

  cout << "nb_bins = " << nb_bins << endl;
  cout << "merge_value = " << merge_value << endl;
  cout << "bound_start = 2^" << log2(conv<double>(bound_start)) << endl;
  cout << "bound_end = 2^" << log2(conv<double>(bound_stop)) << endl;
  cout << "test_key = " << test_key << endl;
  cout << "to_bound = " << to_bound << endl;
  cout << "to_real_key = " << to_real_key << endl;

  result = hel_execute_enum(merge_value, nb_bins, log_proba, real_key, bound_start,
                            bound_stop, test_key, texts, to_real_key,
                            to_bound); // launch enumeration

  if (hel_result_is_key_found(result)) { // print results if the key is found
    *found = 1;
    rank_enum_rounded = hel_result_get_enum_rank(result);
    rank_enum_min = hel_result_get_enum_rank_min(result);
    rank_enum_max = hel_result_get_enum_rank_max(result);
    time_enum = hel_result_get_enum_time(result);
    // these result accessors are in hel_init.cpp/h

    rval_to_print = conv<RR>(rank_enum_min);
    cout << "min: 2^" << log(rval_to_print) / rr_log2 << endl;
    rval_to_print = conv<RR>(rank_enum_rounded);
    cout << "actual rounded: 2^" << log(rval_to_print) / rr_log2 << endl;
    rval_to_print = conv<RR>(rank_enum_max);
    cout << "max: 2^" << log(rval_to_print) / rr_log2 << endl;
    cout << "time enum: " << time_enum << " seconds" << endl;
  } else {
    *found = 0;
    cout << "key not found" << endl;
  }
  time_preprocessing = hel_result_get_enum_time_preprocessing(result);
  cout << "time preprocessing: " << time_preprocessing << " seconds" << endl;
  cout << endl
       << endl;
  hel_free_result(result);

  free_scores_example(log_proba);
  free(real_key);
  for (i = 0; i < 4; i++) {
    free(texts[i]);
  }
  free(texts);

}

