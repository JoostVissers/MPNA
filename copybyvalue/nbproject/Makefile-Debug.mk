#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/verander.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/copybyvalue

dist/Debug/GNU-Linux-x86/copybyvalue: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/copybyvalue ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/verander.o: verander.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/verander.o verander.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/copybyvalue

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
