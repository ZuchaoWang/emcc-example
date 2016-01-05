# emcc-example

Showing how to compile c++ project into javascript library using emscripten.

### Features

* Export a function <code>mysqrt</code>
* Pass float argument to/from a function <code>mysqrt</code>
* Pass array argument to/from a function <code>mysqrtArray</code>
* Construct/destruct a class <code>MyClass</code> and call its member function
* Wrap the compiled asmjs code for easy access using <code>pre.js & post.js</code>
* Build the project using <code>./build.sh</code>

### Build

Enter the main directory and run <code>./build.sh</code> (works only in UNIX-like system)

### Repository overview

* src & include directory: the C++ project
* wrap directory: a javascript wrapper which will provide more friendly access to the built library, following [umd pattern](https://github.com/umdjs/umd)
* dist directory: the built javascript library will be here
* test directory: html testing files that call the built javascript library
* build.sh: a shell script that reads C++ project and javascript wrapper, then build the javascript library