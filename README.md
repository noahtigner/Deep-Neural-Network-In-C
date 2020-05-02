
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


Steps:
- c -> Python
- Neuron
- Basic NN
- Activaton Functions
- Options (layers etc)




- Neural Network written in C
- Python wrapper