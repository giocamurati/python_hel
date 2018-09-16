#ifndef HEL_WRAPPER_H
#define HEL_WRAPPER_H

extern "C" {
void bruteforce(void *scores, unsigned char *pt1, unsigned char *pt2,
                unsigned char *ct1, unsigned char *ct2, int *found,
                unsigned char *found_key, int merge_value, int nb_bins,
                int bit_bound_start, int bit_bound_end);
}
#endif
