# -*- mode:python; coding:utf-8; -*-

import os
import platform
import re

unameResult = platform.uname()
osName = unameResult[0]
archName = unameResult[4].replace('sun4u', 'sparc')
archName = re.sub('i.86', 'ix86', archName)

# Alisander is an ancient MacBook running OS X Snow Leopard which has 64-bit processor but Snow Leopard
# always runs 32-bit due to the boot PROM being 32-bit.  Must use 64-bit libraries for the MacPort installed
# GCC 4.7.

if unameResult[1].startswith('alisander'):
    archName = 'x86_64'

homeDirectory = os.environ['HOME']
libDirectory = homeDirectory + '/lib.' + osName + '.' + archName

buildDirectory = 'build_' + osName + '_' + archName

docsConfigFile = 'doxygen.conf'

environment = Environment(
    tools=['c++', 'link'],
    CPPPATH=['#source'],
    #  Lots of shadowing in the libraries so dispense with this option.
    #CXXFLAGS=['-Wall', '-Wundef', '-Wshadow', '-Wcast-align', '-Wredundant-decls', '-std=c++1y'],
    CXXFLAGS=['-Wall', '-Wundef', '-Wcast-align', '-Wredundant-decls', '-std=c++1y'],
    ENV = os.environ,
   )
environment.SConsignFile('.sconsign_' + osName + '_' + archName)
if osName == 'Darwin':
    environment.Append(CPPPATH=['/opt/local/include'])
    environment['CXX'] = '/opt/local/bin/g++-mp-4.7'

boostEnvironment = environment.Clone(LIBS=['boost_unit_test_framework'])
if osName == 'Darwin':
    boostEnvironment.Append(LIBPATH=['/opt/local/lib'])

cuteEnvironment = environment.Clone()
cuteEnvironment.Append(CPPPATH=[homeDirectory + '/include'])

catchEnvironment = environment.Clone()
catchEnvironment.Append(CPPPATH=[homeDirectory + '/include/'])

Export('boostEnvironment', 'cuteEnvironment', 'catchEnvironment')

boostProgram, cuteProgram, catchProgram = SConscript('tests/SConscript', variant_dir=buildDirectory, duplicate=0)

executionCommand = './$SOURCES'

boostTest = Command('boost', boostProgram, executionCommand)
cuteTest = Command('cute', cuteProgram, executionCommand)
catchTest = Command('catch', catchProgram, executionCommand)

Command('docs', docsConfigFile, 'doxygen ' + docsConfigFile)

Default(boostTest, cuteTest, catchTest)

Clean('.', Glob('*~') + Glob('*/*~') + ['Documentation', buildDirectory])
