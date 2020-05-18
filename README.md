
A Deep Neural Network written from scratch in C with the standard library.

# TODO:
- Loss Calculation
- Backpropagation & Optimization
- Dataset Parsing (Python or C?)
- Python Library

# Build Python Package (not currently supported)

.c, .h, .i
setup.py

swig -python -py3 example.i
    -> example_wrap.c
    -> example.py
python3 setup.py build_ext --inplace
    -> _example...so
    -> /build

Cross Compile:
or sh build.sh
python3 main.py

Test:
gcc -o neuron neuron.c
./neuron
