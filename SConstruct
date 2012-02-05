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

boostEnvironment = environment.Clone ( LIBS = [ 'boost_unit_test_framework' ] )
#  Things may be supplied via MacPorts so add its include area.
if osName == 'Darwin' :
    boostEnvironment.Append ( LIBPATH = [ '/opt/local/lib' ] )

googleEnvironment = environment.Clone ( LIBS = [ 'gtest' , 'pthread' ] )
#  Things may be supplied via MacPorts so add its include area.
if osName == 'Darwin' :
    googleEnvironment.Append ( LIBPATH = [ '/opt/local/lib' ] )

cuteEnvironment = environment.Clone ( )
cuteEnvironment.Append ( CPPPATH = [ homeDirectory + '/include' ] )

Export ( 'boostEnvironment' , 'googleEnvironment' , 'cuteEnvironment' )

boostProgram , googleProgram , cuteProgram = SConscript ( 'tests/SConscript' , variant_dir = buildDirectory , duplicate = 0 )

executionCommand = './$SOURCES'

boostTest = Command ( 'test.Boost' , boostProgram , executionCommand )
googleTest = Command ( 'test.Google' , googleProgram , executionCommand )
cuteTest = Command ( 'test.CUTE' , cuteProgram , executionCommand )

Command ( 'docs' , docsConfigFile , 'doxygen ' + docsConfigFile )

#  Google test fails to work on Alisander, my ancient OS X (Snow Leopard) MacBook.  The problem is:
#
#  google(995) malloc: *** error for object 0x7fff701c9500: pointer being freed was not allocated
#
#  which is vaguely incomprehensible.

if osName == 'Darwin' :
     Default ( boostTest , cuteTest )
else :
     Default ( boostTest , googleTest , cuteTest )

Clean ( '.' , Glob ( '*~' ) + Glob ( '*/*~' ) + [ 'Documentation' , buildDirectory ] )
