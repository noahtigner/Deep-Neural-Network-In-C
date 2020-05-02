from distutils.core import setup, Extension
neuron_module = Extension('_neuron',
   sources=['neuron_wrap.c', 'neuron.c', 'vectord.c'],
)
setup (name = 'neuron',
   version = '0.1',
   author = "Noah Tigner",
   description = """neuron""",
   ext_modules = [neuron_module],
   py_modules = ["neuron"],
)