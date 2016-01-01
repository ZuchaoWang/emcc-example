# emcc-example

Showing how to compile c++ project into javascript library using emscripten

To build the javascript library, enter the main directory and run <code>./build.sh</code> (works only in UNIX-like system)

Below is the content of the repository:

  * src & include directory: the C++ project
  * wrap directory: a javascript wrapper which will provide more friendly access to the built library, following [umd pattern](https://github.com/umdjs/umd)
  * html directory: html testing files that call the built javascript library
  * dist directory: the built javascript library will be here, testing html files are also copied here for convenience
  * build.sh: a shell script that reads C++ project and javascript wrapper, then build the javascript library