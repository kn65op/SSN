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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Neuron.o \
	${OBJECTDIR}/Entry.o \
	${OBJECTDIR}/Input.o \
	${OBJECTDIR}/Link.o \
	${OBJECTDIR}/Bias.o \
	${OBJECTDIR}/Output.o \
	${OBJECTDIR}/Exit.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuron.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuron.so: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuron.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Neuron.o: Neuron.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Neuron.o Neuron.cpp

${OBJECTDIR}/Entry.o: Entry.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Entry.o Entry.cpp

${OBJECTDIR}/Input.o: Input.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Input.o Input.cpp

${OBJECTDIR}/Link.o: Link.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Link.o Link.cpp

${OBJECTDIR}/Bias.o: Bias.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Bias.o Bias.cpp

${OBJECTDIR}/Output.o: Output.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Output.o Output.cpp

${OBJECTDIR}/Exit.o: Exit.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Exit.o Exit.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/NeuronTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/NeuronTest.o: tests/NeuronTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/NeuronTest.o tests/NeuronTest.cpp


${OBJECTDIR}/Neuron_nomain.o: ${OBJECTDIR}/Neuron.o Neuron.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Neuron.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Neuron_nomain.o Neuron.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Neuron.o ${OBJECTDIR}/Neuron_nomain.o;\
	fi

${OBJECTDIR}/Entry_nomain.o: ${OBJECTDIR}/Entry.o Entry.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Entry.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Entry_nomain.o Entry.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Entry.o ${OBJECTDIR}/Entry_nomain.o;\
	fi

${OBJECTDIR}/Input_nomain.o: ${OBJECTDIR}/Input.o Input.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Input.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Input_nomain.o Input.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Input.o ${OBJECTDIR}/Input_nomain.o;\
	fi

${OBJECTDIR}/Link_nomain.o: ${OBJECTDIR}/Link.o Link.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Link.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Link_nomain.o Link.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Link.o ${OBJECTDIR}/Link_nomain.o;\
	fi

${OBJECTDIR}/Bias_nomain.o: ${OBJECTDIR}/Bias.o Bias.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Bias.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Bias_nomain.o Bias.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Bias.o ${OBJECTDIR}/Bias_nomain.o;\
	fi

${OBJECTDIR}/Output_nomain.o: ${OBJECTDIR}/Output.o Output.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Output.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Output_nomain.o Output.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Output.o ${OBJECTDIR}/Output_nomain.o;\
	fi

${OBJECTDIR}/Exit_nomain.o: ${OBJECTDIR}/Exit.o Exit.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Exit.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Exit_nomain.o Exit.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Exit.o ${OBJECTDIR}/Exit_nomain.o;\
	fi

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
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libNeuron.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
