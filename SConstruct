# -*- mode:python; coding:utf-8; -*-

import os
import platform
import re

unameResult = platform.uname()
osName = unameResult[0]
archName = unameResult[4].replace('sun4u', 'sparc')
archName = re.sub('i.86', 'ix86', archName)

homeDirectory = os.environ['HOME']
buildDirectory = 'build_' + osName + '_' + archName

docsConfigFile = 'doxygen.conf'

environment = Environment(
    tools=['c++', 'link'],
    CPPPATH=['#source'],
    #  Lots of shadowing in the libraries so dispense with this option.
    #CXXFLAGS=['-Wall', '-Wundef', '-Wshadow', '-Wcast-align', '-Wredundant-decls', '-std=c++14'],
    CXXFLAGS=['-Wall', '-Wundef', '-Wcast-align', '-Wredundant-decls', '-std=c++14'],
    ENV = os.environ,
   )
environment.SConsignFile('.sconsign_' + osName + '_' + archName)
if osName == 'Darwin':
    environment.Append(CPPPATH=['/opt/local/include'])
    environment['CXX'] = '/opt/local/bin/g++-mp-4.9'

boostEnvironment = environment.Clone(LIBS=['boost_unit_test_framework'])
if osName == 'Darwin':
    boostEnvironment.Append(LIBPATH=['/opt/local/lib'])

catchEnvironment = environment.Clone()
catchEnvironment.Append(CPPPATH=[homeDirectory + '/include/'])

Export('boostEnvironment', 'catchEnvironment')

boostProgram, catchProgram = SConscript('tests/SConscript', variant_dir=buildDirectory, duplicate=0)

executionCommand = './$SOURCES'

boostTest = Command('boost', boostProgram, executionCommand)
catchTest = Command('catch', catchProgram, executionCommand)

Command('docs', docsConfigFile, 'doxygen ' + docsConfigFile)

Default(boostTest, catchTest)

Clean('.', Glob('*~') + Glob('*/*~') + ['Documentation', buildDirectory])
