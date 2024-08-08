cmake_minimum_required(VERSION 3.5)

project(vlang LANGUAGES C)

add_executable(
  vlang
  main.c
  common.h
  chunk.h
  chunk.c
  memory.h
  memory.c
  debug.h
  debug.c
  value.h
  value.c
  vm.h
  vm.c
  compiler.h
  compiler.c
  scanner.h
  scanner.c object.c object.h)

include(GNUInstallDirs)
install(
  TARGETS vlang
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
