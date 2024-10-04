# DSA

## TestSuite (GoogleTest)

### Installation
```
git clone https://github.com/arrowten/DSA.git
cd DSA
cd TestSuite
mkdir _build && cd _build
cmake -DCMAKE_CXX_COMPILER={g++/clang++} -DCMAKE_C_COMPILER={gcc/clang} ..
make
```

### Testing
```
cd DSA
{g++/clang++} <filename> -o <outfile> -lgtest -lgtest_main -pthread -I<path/to/gtest/include> -L<path/to/build>
./<outfile>
```