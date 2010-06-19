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

buildDirectory = 'build_' + osName + '_' + archName

docsConfigFile = 'doxygen.conf'

isMissingStandardBoostOnLinux = osName == 'Linux' and not os.path.isdir ( '/usr/include/boost' )

environment = Environment (
    CPPPATH = [ '#source' ] ,
    CXXFLAGS = [ '-Wall' , '-Wundef' , '-Wshadow' , '-Wcast-align' , '-Wredundant-decls' ] ,
    )
environment.SConsignFile ( '.sconsign_' + osName + '_' + archName )
#  Things may be supplied via MacPorts so add its include area.
if osName == 'Darwin' :
     environment.Append ( CPPPATH = [ '/opt/local/include' ] )
if isMissingStandardBoostOnLinux :
    #  Assume installation of Boost in my peronal library area.
    environment.Append ( CPPPATH = [ libDirectory + '/Boost/include' ] )

aerynEnvironment = environment.Clone ( LIBS = [ 'aeryn_core' ] , LIBPATH = [ libDirectory ] )
aerynEnvironment.Append ( CPPPATH = [ installBase + '/include' ] )

boostEnvironment = environment.Clone ( LIBS = [ 'boost_unit_test_framework' ] )
#  Things may be supplied via MacPorts so add its include area.
if osName == 'Darwin' :
    boostEnvironment.Append ( LIBPATH = [ '/opt/local/lib' ] )
if isMissingStandardBoostOnLinux :
    #  Assume installation of Boost in my peronal library area.
    boostEnvironment.Append ( LIBPATH = [ libDirectory + '/Boost/lib' ] )

Export ( 'aerynEnvironment' , 'boostEnvironment' )

aerynProgram , boostProgram = SConscript ( 'tests/SConscript' , variant_dir = buildDirectory , duplicate = 0 )

aerynTest = Command ( 'test.Aeryn' , aerynProgram , ( 'DY' if osName == 'Darwin' else '' ) + 'LD_LIBRARY_PATH=' + libDirectory + ' ./$SOURCES' )

boostCommand = './$SOURCES'
if isMissingStandardBoostOnLinux :
    boostCommand = ( 'DY' if osName == 'Darwin' else '' ) + 'LD_LIBRARY_PATH=' + libDirectory + '/Boost/lib ' + boostCommand
boostTest = Command ( 'test.Boost' , boostProgram , boostCommand )

Command ( 'docs' , docsConfigFile , 'doxygen ' + docsConfigFile )

Default ( aerynTest , boostTest )

Clean ( '.' , Glob ( '*~' ) + Glob ( '*/*~' ) + [ 'Documentation' , buildDirectory ] )
