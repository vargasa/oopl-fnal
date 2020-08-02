.DEFAULT_GOAL := all

ASTYLE        := astyle
CHECKTESTDATA := checktestdata
CPPCHECK      := cppcheck
DOXYGEN       := doxygen
VALGRIND      := valgrind

ifeq ($(shell uname -s), Darwin)
    BOOST    := /usr/local/include/boost
    CXX      := g++-10
    CXXFLAGS := --coverage -pedantic -std=c++17 -O3 -I/usr/local/include -Wall -Wextra
    GCOV     := gcov-10
    GTEST    := /usr/local/include/gtest
    LDFLAGS  := -lgtest -lgtest_main
else ifeq ($(shell uname -p), unknown)
    BOOST    := /usr/include/boost
    CXX      := g++
    CXXFLAGS := --coverage -pedantic -std=c++17 -O3 -Wall -Wextra
    GCOV     := gcov
    GTEST    := /usr/include/gtest
    LDFLAGS  := -lgtest -lgtest_main -pthread
else
    BOOST    := /usr/include/boost
    CXX      := g++-9
    CXXFLAGS := --coverage -pedantic -std=c++17 -O3 -Wall -Wextra
    GCOV     := gcov-9
    GTEST    := /usr/local/include/gtest
    LDFLAGS  := -lgtest -lgtest_main -pthread
endif

FILES :=                    \
    Hello                   \
    UnitTests3              \
    Coverage1               \
    Coverage2               \
    Coverage3               \
    IsPrime                 \
    Variables               \
    Arguments               \
    Returns                 \
    Exceptions              \
    Operators               \
    Consts                  \
    Arrays1                 \
    Arrays2                 \
    Types                   \
    Iterators               \
    Iteration               \
    Functions               \
    FunctionOverloading     \
    Move                    \
    LocalVariables          \
    Classes                 \
    InstanceVariables       \
    ClassVariables          \
    InstanceMethods         \
    ConstMethods            \
    ClassMethods            \
    OperatorOverloading     \
    Conversions             \
    Initializations         \
    InitializerList         \
    MethodOverriding1       \
    MethodOverriding2

%: %.cpp
	-$(CPPCHECK) $<
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

%.cppx: %
	./$<

%.cppy: %
	./$<
	$(GCOV) $<.cpp | grep -B 2 "cpp.gcov"

%.cppz: %
	$(VALGRIND) ./$<
	$(GCOV) $<.cpp | grep -B 2 "cpp.gcov"

all: $(FILES)

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.plist
	rm -f $(FILES)

docker:
	docker run -it -v $(PWD):/usr/gcc -w /usr/gcc gpdowning/gcc

run: $(FILES:=.cppz)

sync:
	make clean
	@echo ~/examples/cpp/
	@rsync -p -r -t -u -v --delete         \
    --include "Hello.cpp"                  \
    --include "Assertions.cpp"             \
    --include "UnitTests1.cpp"             \
    --include "UnitTests2.cpp"             \
    --include "UnitTests3.cpp"             \
    --include "Coverage1.cpp"              \
    --include "Coverage2.cpp"              \
    --include "Coverage3.cpp"              \
    --include "Variables.cpp"              \
    --include "Arguments.cpp"              \
    --include "Returns.cpp"                \
    --include "Exceptions.cpp"             \
    --include "Operators.cpp"              \
    --include "Consts.cpp"                 \
    --include "Arrays1.cpp"                \
    --include "Arrays2.cpp"                \
    --include "Types.cpp"                  \
    --include "Iterators.cpp"              \
    --include "Iteration.cpp"              \
    --include "Functions.cpp"              \
    --include "FunctionOverloading.cpp"    \
    --include "Move.cpp"                   \
    --include "UniquePtr.cpp"              \
    --include "UniquePtrs.cpp"             \
    --include "LocalVariables.cpp"         \
    --include "Classes.cpp"                \
    --include "InstanceVariables.cpp"      \
    --include "ClassVariables.cpp"         \
    --include "InstanceMethods.cpp"        \
    --include "ConstMethods.cpp"           \
    --include "ClassMethods.cpp"           \
    --include "OperatorOverloading.cpp"    \
    --include "Conversions.cpp"            \
    --include "Initializations.cpp"        \
    --include "InitializerList.cpp"        \
    --include "Factorial.cpp"              \
    --include "MethodOverriding1.cpp"      \
    --include "MethodOverriding2.cpp"      \
    --exclude "*"                          \
    ~/examples/cpp/ .
	@echo ~/exercises/cpp/
	@rsync -p -r -t -u -v --delete         \
    --exclude "*"                          \
    ~/exercises/cpp/ .
	@rsync -p -r -t -u -v --delete         \
    --include "makefile"                   \
    --include "*.cpp"                      \
    --exclude "*"                          \
    . gpdowning@$(OOPL):oopl/git/fnal/cpp/

versions:
	@echo "% shell uname -p"
	@echo  $(shell uname -p)
	@echo
	@echo "% shell uname -s"
	@echo  $(shell uname -s)
	@echo
	@echo "% which $(ASTYLE)"
	@which $(ASTYLE)
	@echo
	@echo "% $(ASTYLE) --version"
	@$(ASTYLE) --version
	@echo
	@echo "% grep \"#define BOOST_LIB_VERSION \" $(BOOST)/version.hpp"
	@grep "#define BOOST_LIB_VERSION " $(BOOST)/version.hpp
	@echo
	@echo "% which $(CHECKTESTDATA)"
	@which $(CHECKTESTDATA)
	@echo
	@echo "% $(CHECKTESTDATA) --version"
	@$(CHECKTESTDATA) --version
	@echo
	@echo "% which cmake"
	@which cmake
	@echo
	@echo "% cmake --version"
	@cmake --version
	@echo
	@echo "% which $(CXX)"
	@which $(CXX)
	@echo
	@echo "% $(CXX) --version"
	@$(CXX) --version
	@echo "% which $(CPPCHECK)"
	@which $(CPPCHECK)
	@echo
	@echo "% $(CPPCHECK) --version"
	@$(CPPCHECK) --version
	@echo
	@$(CXX) --version
	@echo "% which $(DOXYGEN)"
	@which $(DOXYGEN)
	@echo
	@echo "% $(DOXYGEN) --version"
	@$(DOXYGEN) --version
	@echo
	@echo "% which $(GCOV)"
	@which $(GCOV)
	@echo
	@echo "% $(GCOV) --version"
	@$(GCOV) --version
	@echo
	@echo "% cat $(GTEST)/README"
	@cat $(GTEST)/README
ifneq ($(shell uname -s), Darwin)
	@echo
	@echo "% which $(VALGRIND)"
	@which $(VALGRIND)
	@echo
	@echo "% $(VALGRIND) --version"
	@$(VALGRIND) --version
endif
