# Python bindings for the Histogram Enumeration Library

This repository provides Python bindings for the **Histogram Enumeration Library**,
for key enumeration/ranking after a side channel attack.

All credits for the development of this algorithm and library go to the original
authors. Have a look at their [paper](https://ia.cr/2015/536)
and [code](http://perso.uclouvain.be/fstandae/PUBLIS/172.zip).

Please feel free to contact us ([Giovanni Camurati](mailto://camurati@eurecom.fr)) for any comment, issue, or question.

# Index

* [Files](#Files)
* [Explanation](#Explanation)
* [Installation](#Installation)
* [Examples](#Examples)
* [License](#License)

## <a name="Files"></a>Files

├── aes_ni # Intel AES NI instruction to speed up bruteforcing
│   └── aes_ni.cpp
├── hel_lib # The original HEL code
│   ├── aes.cpp
│   ├── aes.h
│   ├── hel_enum.cpp
│   ├── hel_enum.h
│   ├── hel_execute.cpp
│   ├── hel_execute.h
│   ├── hel_histo.cpp
│   ├── hel_histo.h
│   ├── hel_init.cpp
│   ├── hel_init.h
│   ├── hel_struct.h
│   ├── hel_util.cpp
│   ├── hel_util.h
│   ├── main_example.cpp
│   ├── makefile
│   ├── README.txt
│   ├── scores_example.cpp
│   ├── scores_example_data.cpp
│   └── scores_example.h
├── hel_wrapper # Our wrapper
│   ├── aes_cryptopp.cpp
│   ├── hel_wrapper.cpp
│   ├── hel_wrapper.h
│   └── Makefile
├── LICENSE
├── meson.build # Compilation with meson
├── meson_options.txt
├── python_hel # Our Python wrapper
│   ├── python_hel
│   │   ├── example_data.py
│   │   ├── hel.py
│   │   ├── __init__.py
│   └── setup.py
└── README.md

## <a name="Explanation"></a>Explanation

Please refer to the original [paper](https://ia.cr/2015/536) for a detailed
explanation of the algorithm.

## <a name="Installation"></a>Installation

We tested this on Ubuntu18.04.

To check whether your machine has the Intel AES NI instruction or not, you can
use the following command:
```
cpuid | grep -i aes
```
If it is not available, you can chose to use the software version as a
compilation option.

Requirements.
```
apt install libntl-dev
apt install libgmp-dev
```

Clone the repository.
```
git clone https://github.com/eurecom-s3/python-hel
cd python-hel
```

Compile and install the library.
```
cd hel_wrapper
make AES_TYPE=aes_ni # Intel AES NI
# make TYPE=aes_simple  # Software AES
sudo make install
sudo ldconfig
```

Run the following to uninstall.
```
sudo make uninstall
```

Alternatively, you can build the library with meson and ninja (Credits to
[Sebastian Poeplau](https://github.com/sebastianpoeplau)).
```
apt install meson
apt install ninja-build
```

```
cd python-hel
meson --buildtype release build -D aes_type=aes_ni
# meson --buildtype release build2 -D aes_type=aes_simple
cd build
ninja
sudo ninja install
sudo ldconfig
```

Run the following to uninstall.
```
sudo ninja uninstall
```

Then, you have to install the python module.
```
cd python_hel/python_hel
python2 setup.py install
# python2 setup.py install --user # To install locally instead of system wide
# python2 setup.py develop # To make changes to the source effective immediately
```

## <a name="Examples"></a>Examples

Quick test.
```
python2 python_hel/python_hel/hel.py
```

This project was developed to be used with the
[Screaming Channels attack code](https://eurecom-s3.github.io/screaming_channels/),
you can find more examples there.

## <a name="License"></a>License

Copyright (C) EURECOM
Copyright (C) Giovanni Camurati

Certain files in this project may have specific licenses or copyright
restrictions, as this project uses multiple open-source projects.
Files in this project without any specific license can be assumed
to follow the following general clause:

Python bindings for the Histogram Enumeration Library
is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Python bindings for the Histogram Enumeration Library
is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with screaming_channels.  If not, see <http://www.gnu.org/licenses/>.


