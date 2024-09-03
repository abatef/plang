cmake_minimum_required(VERSION 3.5)

project(plang LANGUAGES C)

include_directories(include)

add_executable(
  plang
  src/main.c
  include/common.h
  include/chunk.h
  src/chunk.c
  include/memory.h
  src/memory.c
  include/debug.h
  src/debug.c
  include/value.h
  src/value.c
  include/vm.h
  src/vm.c
  include/compiler.h
  src/compiler.c
  include/scanner.h
  src/scanner.c
  src/object.c
  include/object.h
  include/table.h
  src/table.c)

include(GNUInstallDirs)
install(
  TARGETS plang
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
