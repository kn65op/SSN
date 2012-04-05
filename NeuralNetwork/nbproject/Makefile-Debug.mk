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
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES=

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x
CXXFLAGS=-std=c++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../Neuron/dist/Debug/GNU-Linux-x86/libNeuron.so ../LibHelper/dist/Debug/GNU-Linux-x86/libHelper.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuralNetwork.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuralNetwork.so: ../Neuron/dist/Debug/GNU-Linux-x86/libNeuron.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuralNetwork.so: ../LibHelper/dist/Debug/GNU-Linux-x86/libHelper.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuralNetwork.so: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -std=c++0x -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuralNetwork.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/NeuralNetworkTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}  -lpthread -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} ../../gtest/libgtest.a 


${TESTDIR}/tests/NeuralNetworkTest.o: tests/NeuralNetworkTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -I../../gtest/gtest_src/include -I../Neuron -I../LibHelper -MMD -MP -MF $@.d -o ${TESTDIR}/tests/NeuralNetworkTest.o tests/NeuralNetworkTest.cpp


# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuralNetwork.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
