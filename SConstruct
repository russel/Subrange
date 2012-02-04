# -*- mode:python; coding:utf-8; -*-

import os
import platform
import re

unameResult = platform.uname ( )
osName = unameResult[0]
archName = unameResult[4].replace ( 'sun4u' , 'sparc' )
archName = re.sub ( 'i.86' , 'ix86' , archName )

# Alisander is an ancient MacBook which has 64-bit processor but Snow Leopard always runs 32-bit due to the
# boot PROM being 32-bit.  Must use 64-bit libraries for the MacPort installed GCC 4.6.

if unameResult[1].startswith ( 'alisander' ) :
     archName = 'x86_64'

homeDirectory = os.environ [ 'HOME' ]
libDirectory = homeDirectory + '/lib.' + osName + '.' + archName

buildDirectory = 'build_' + osName + '_' + archName

docsConfigFile = 'doxygen.conf'

environment = Environment (
    CPPPATH = [ '#source' ] ,
    CXXFLAGS = [ '-Wall' , '-Wundef' , '-Wshadow' , '-Wcast-align' , '-Wredundant-decls' , '-std=c++0x' ] ,
    )
environment.SConsignFile ( '.sconsign_' + osName + '_' + archName )
#  GCC 4.6 is supplied via MacPorts on Mac OS X .
if osName == 'Darwin' :
     environment.Append ( CPPPATH = [ '/opt/local/include' ] )
     environment['CXX'] = '/opt/local/bin/g++-mp-4.6'

aerynEnvironment = environment.Clone ( LIBS = [ 'aeryn_core' ] , LIBPATH = [ libDirectory ] )
aerynEnvironment.Append ( CPPPATH = [ homeDirectory + '/include' ] )

boostEnvironment = environment.Clone ( LIBS = [ 'boost_unit_test_framework' ] )
#  Things may be supplied via MacPorts so add its include area.
if osName == 'Darwin' :
    boostEnvironment.Append ( LIBPATH = [ '/opt/local/lib' ] )

googleEnvironment = environment.Clone ( LIBS = [ 'gtest' , 'pthread' ] )

cuteEnvironment = environment.Clone ( )
cuteEnvironment.Append ( CPPPATH = [ homeDirectory + '/include' ] )

Export ( 'aerynEnvironment' , 'boostEnvironment' , 'googleEnvironment' , 'cuteEnvironment' )

aerynProgram , boostProgram , googleProgram , cuteProgram = SConscript ( 'tests/SConscript' , variant_dir = buildDirectory , duplicate = 0 )

aerynTest = Command ( 'test.Aeryn' , aerynProgram , ( 'DY' if osName == 'Darwin' else '' ) + 'LD_LIBRARY_PATH=' + libDirectory + ' ./$SOURCES' )

boostCommand = './$SOURCES'
boostTest = Command ( 'test.Boost' , boostProgram , boostCommand )

googleTest = Command ( 'test.Google' , googleProgram , ( 'DY' if osName == 'Darwin' else '' ) + 'LD_LIBRARY_PATH=' + libDirectory + '/GoogleTest/lib ./$SOURCES' )

cuteTest = Command ( 'test.CUTE' , cuteProgram , './$SOURCE' )

Command ( 'docs' , docsConfigFile , 'doxygen ' + docsConfigFile )

Default ( aerynTest , boostTest , googleTest )#, cuteTest )

Clean ( '.' , Glob ( '*~' ) + Glob ( '*/*~' ) + [ 'Documentation' , buildDirectory ] )
