from distutils.core import setup, Extension
hello_module = Extension('_hello',
   sources=['hello_wrap.c', 'hello.c'],
)
setup (name = 'hello',
   version = '0.1',
   author = "Noah Tigner",
   description = """says hello""",
   ext_modules = [hello_module],
   py_modules = ["hello"],
)