# -*- mode:python; coding:utf-8; -*-

import os
import platform
import re

unameResult = platform.uname ( )
osName = unameResult[0]
archName = unameResult[4].replace ( 'sun4u' , 'sparc' )
archName = re.sub ( 'i.86' , 'ix86' , archName )

installBase = os.environ [ 'HOME' ]
libDirectory = installBase + '/lib.' + osName + '.' + archName

buildDirectory = 'build'
sourceDirectory = 'source'
testDirectory = 'test'

environment = Environment (
    CPPPATH = [ '#' + sourceDirectory , installBase + '/include' ] ,
    CXXFLAGS = [ '-O3' , '-W' , '-Wall' , '-Wundef' , '-Wcast-align' , '-Wno-unused-parameter' , '-Wshadow' , '-Wredundant-decls' ] ,
    LIBPATH = libDirectory ,
    LIBS = 'aeryn_core'
    )

environment.SConsignFile ( '.sconsign_' + osName + '_' + archName )

Export ( 'environment' )

testProgram = SConscript ( testDirectory + '/SConscript' , variant_dir = buildDirectory , duplicate = 0 )

Default ( Command ( 'runTest' , testProgram , 'LD_LIBRARY_PATH=' + libDirectory + ' ./$SOURCES' ) )

Clean ( '.' , Glob ( '*/*~' ) + Glob ( '*~' ) + [ buildDirectory ] )
