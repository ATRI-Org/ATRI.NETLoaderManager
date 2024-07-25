# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "F:/EndStoneMC/Plugin/cpp-example-plugin/build/_deps/endstone-src"
  "F:/EndStoneMC/Plugin/cpp-example-plugin/build/_deps/endstone-build"
  "F:/EndStoneMC/Plugin/cpp-example-plugin/build/_deps/endstone-subbuild/endstone-populate-prefix"
  "F:/EndStoneMC/Plugin/cpp-example-plugin/build/_deps/endstone-subbuild/endstone-populate-prefix/tmp"
  "F:/EndStoneMC/Plugin/cpp-example-plugin/build/_deps/endstone-subbuild/endstone-populate-prefix/src/endstone-populate-stamp"
  "F:/EndStoneMC/Plugin/cpp-example-plugin/build/_deps/endstone-subbuild/endstone-populate-prefix/src"
  "F:/EndStoneMC/Plugin/cpp-example-plugin/build/_deps/endstone-subbuild/endstone-populate-prefix/src/endstone-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "F:/EndStoneMC/Plugin/cpp-example-plugin/build/_deps/endstone-subbuild/endstone-populate-prefix/src/endstone-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "F:/EndStoneMC/Plugin/cpp-example-plugin/build/_deps/endstone-subbuild/endstone-populate-prefix/src/endstone-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
