#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Version5.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Version5.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=FrameFunction.c HoldingReg.c packet_parser.c main.c forcemultiplecoils.c forcesinglecoil.c ReadInputRegisters.c TestingFunction.c modbuserror.c presetmultipleregisters.c presetsingleregister.c readcoilstatus.c readinputstatus.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/FrameFunction.o ${OBJECTDIR}/HoldingReg.o ${OBJECTDIR}/packet_parser.o ${OBJECTDIR}/main.o ${OBJECTDIR}/forcemultiplecoils.o ${OBJECTDIR}/forcesinglecoil.o ${OBJECTDIR}/ReadInputRegisters.o ${OBJECTDIR}/TestingFunction.o ${OBJECTDIR}/modbuserror.o ${OBJECTDIR}/presetmultipleregisters.o ${OBJECTDIR}/presetsingleregister.o ${OBJECTDIR}/readcoilstatus.o ${OBJECTDIR}/readinputstatus.o
POSSIBLE_DEPFILES=${OBJECTDIR}/FrameFunction.o.d ${OBJECTDIR}/HoldingReg.o.d ${OBJECTDIR}/packet_parser.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/forcemultiplecoils.o.d ${OBJECTDIR}/forcesinglecoil.o.d ${OBJECTDIR}/ReadInputRegisters.o.d ${OBJECTDIR}/TestingFunction.o.d ${OBJECTDIR}/modbuserror.o.d ${OBJECTDIR}/presetmultipleregisters.o.d ${OBJECTDIR}/presetsingleregister.o.d ${OBJECTDIR}/readcoilstatus.o.d ${OBJECTDIR}/readinputstatus.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/FrameFunction.o ${OBJECTDIR}/HoldingReg.o ${OBJECTDIR}/packet_parser.o ${OBJECTDIR}/main.o ${OBJECTDIR}/forcemultiplecoils.o ${OBJECTDIR}/forcesinglecoil.o ${OBJECTDIR}/ReadInputRegisters.o ${OBJECTDIR}/TestingFunction.o ${OBJECTDIR}/modbuserror.o ${OBJECTDIR}/presetmultipleregisters.o ${OBJECTDIR}/presetsingleregister.o ${OBJECTDIR}/readcoilstatus.o ${OBJECTDIR}/readinputstatus.o

# Source Files
SOURCEFILES=FrameFunction.c HoldingReg.c packet_parser.c main.c forcemultiplecoils.c forcesinglecoil.c ReadInputRegisters.c TestingFunction.c modbuserror.c presetmultipleregisters.c presetsingleregister.c readcoilstatus.c readinputstatus.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Version5.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24EP128GP202
MP_LINKER_FILE_OPTION=,-Tp24EP128GP202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/FrameFunction.o: FrameFunction.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FrameFunction.o.d 
	@${RM} ${OBJECTDIR}/FrameFunction.o.ok ${OBJECTDIR}/FrameFunction.o.err 
	@${RM} ${OBJECTDIR}/FrameFunction.o 
	@${FIXDEPS} "${OBJECTDIR}/FrameFunction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FrameFunction.o.d" -o ${OBJECTDIR}/FrameFunction.o FrameFunction.c    
	
${OBJECTDIR}/HoldingReg.o: HoldingReg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HoldingReg.o.d 
	@${RM} ${OBJECTDIR}/HoldingReg.o.ok ${OBJECTDIR}/HoldingReg.o.err 
	@${RM} ${OBJECTDIR}/HoldingReg.o 
	@${FIXDEPS} "${OBJECTDIR}/HoldingReg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/HoldingReg.o.d" -o ${OBJECTDIR}/HoldingReg.o HoldingReg.c    
	
${OBJECTDIR}/packet_parser.o: packet_parser.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/packet_parser.o.d 
	@${RM} ${OBJECTDIR}/packet_parser.o.ok ${OBJECTDIR}/packet_parser.o.err 
	@${RM} ${OBJECTDIR}/packet_parser.o 
	@${FIXDEPS} "${OBJECTDIR}/packet_parser.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/packet_parser.o.d" -o ${OBJECTDIR}/packet_parser.o packet_parser.c    
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o.ok ${OBJECTDIR}/main.o.err 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    
	
${OBJECTDIR}/forcemultiplecoils.o: forcemultiplecoils.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/forcemultiplecoils.o.d 
	@${RM} ${OBJECTDIR}/forcemultiplecoils.o.ok ${OBJECTDIR}/forcemultiplecoils.o.err 
	@${RM} ${OBJECTDIR}/forcemultiplecoils.o 
	@${FIXDEPS} "${OBJECTDIR}/forcemultiplecoils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/forcemultiplecoils.o.d" -o ${OBJECTDIR}/forcemultiplecoils.o forcemultiplecoils.c    
	
${OBJECTDIR}/forcesinglecoil.o: forcesinglecoil.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/forcesinglecoil.o.d 
	@${RM} ${OBJECTDIR}/forcesinglecoil.o.ok ${OBJECTDIR}/forcesinglecoil.o.err 
	@${RM} ${OBJECTDIR}/forcesinglecoil.o 
	@${FIXDEPS} "${OBJECTDIR}/forcesinglecoil.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/forcesinglecoil.o.d" -o ${OBJECTDIR}/forcesinglecoil.o forcesinglecoil.c    
	
${OBJECTDIR}/ReadInputRegisters.o: ReadInputRegisters.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ReadInputRegisters.o.d 
	@${RM} ${OBJECTDIR}/ReadInputRegisters.o.ok ${OBJECTDIR}/ReadInputRegisters.o.err 
	@${RM} ${OBJECTDIR}/ReadInputRegisters.o 
	@${FIXDEPS} "${OBJECTDIR}/ReadInputRegisters.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ReadInputRegisters.o.d" -o ${OBJECTDIR}/ReadInputRegisters.o ReadInputRegisters.c    
	
${OBJECTDIR}/TestingFunction.o: TestingFunction.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TestingFunction.o.d 
	@${RM} ${OBJECTDIR}/TestingFunction.o.ok ${OBJECTDIR}/TestingFunction.o.err 
	@${RM} ${OBJECTDIR}/TestingFunction.o 
	@${FIXDEPS} "${OBJECTDIR}/TestingFunction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TestingFunction.o.d" -o ${OBJECTDIR}/TestingFunction.o TestingFunction.c    
	
${OBJECTDIR}/modbuserror.o: modbuserror.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/modbuserror.o.d 
	@${RM} ${OBJECTDIR}/modbuserror.o.ok ${OBJECTDIR}/modbuserror.o.err 
	@${RM} ${OBJECTDIR}/modbuserror.o 
	@${FIXDEPS} "${OBJECTDIR}/modbuserror.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/modbuserror.o.d" -o ${OBJECTDIR}/modbuserror.o modbuserror.c    
	
${OBJECTDIR}/presetmultipleregisters.o: presetmultipleregisters.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/presetmultipleregisters.o.d 
	@${RM} ${OBJECTDIR}/presetmultipleregisters.o.ok ${OBJECTDIR}/presetmultipleregisters.o.err 
	@${RM} ${OBJECTDIR}/presetmultipleregisters.o 
	@${FIXDEPS} "${OBJECTDIR}/presetmultipleregisters.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/presetmultipleregisters.o.d" -o ${OBJECTDIR}/presetmultipleregisters.o presetmultipleregisters.c    
	
${OBJECTDIR}/presetsingleregister.o: presetsingleregister.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/presetsingleregister.o.d 
	@${RM} ${OBJECTDIR}/presetsingleregister.o.ok ${OBJECTDIR}/presetsingleregister.o.err 
	@${RM} ${OBJECTDIR}/presetsingleregister.o 
	@${FIXDEPS} "${OBJECTDIR}/presetsingleregister.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/presetsingleregister.o.d" -o ${OBJECTDIR}/presetsingleregister.o presetsingleregister.c    
	
${OBJECTDIR}/readcoilstatus.o: readcoilstatus.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/readcoilstatus.o.d 
	@${RM} ${OBJECTDIR}/readcoilstatus.o.ok ${OBJECTDIR}/readcoilstatus.o.err 
	@${RM} ${OBJECTDIR}/readcoilstatus.o 
	@${FIXDEPS} "${OBJECTDIR}/readcoilstatus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/readcoilstatus.o.d" -o ${OBJECTDIR}/readcoilstatus.o readcoilstatus.c    
	
${OBJECTDIR}/readinputstatus.o: readinputstatus.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/readinputstatus.o.d 
	@${RM} ${OBJECTDIR}/readinputstatus.o.ok ${OBJECTDIR}/readinputstatus.o.err 
	@${RM} ${OBJECTDIR}/readinputstatus.o 
	@${FIXDEPS} "${OBJECTDIR}/readinputstatus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/readinputstatus.o.d" -o ${OBJECTDIR}/readinputstatus.o readinputstatus.c    
	
else
${OBJECTDIR}/FrameFunction.o: FrameFunction.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FrameFunction.o.d 
	@${RM} ${OBJECTDIR}/FrameFunction.o.ok ${OBJECTDIR}/FrameFunction.o.err 
	@${RM} ${OBJECTDIR}/FrameFunction.o 
	@${FIXDEPS} "${OBJECTDIR}/FrameFunction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FrameFunction.o.d" -o ${OBJECTDIR}/FrameFunction.o FrameFunction.c    
	
${OBJECTDIR}/HoldingReg.o: HoldingReg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HoldingReg.o.d 
	@${RM} ${OBJECTDIR}/HoldingReg.o.ok ${OBJECTDIR}/HoldingReg.o.err 
	@${RM} ${OBJECTDIR}/HoldingReg.o 
	@${FIXDEPS} "${OBJECTDIR}/HoldingReg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/HoldingReg.o.d" -o ${OBJECTDIR}/HoldingReg.o HoldingReg.c    
	
${OBJECTDIR}/packet_parser.o: packet_parser.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/packet_parser.o.d 
	@${RM} ${OBJECTDIR}/packet_parser.o.ok ${OBJECTDIR}/packet_parser.o.err 
	@${RM} ${OBJECTDIR}/packet_parser.o 
	@${FIXDEPS} "${OBJECTDIR}/packet_parser.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/packet_parser.o.d" -o ${OBJECTDIR}/packet_parser.o packet_parser.c    
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o.ok ${OBJECTDIR}/main.o.err 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    
	
${OBJECTDIR}/forcemultiplecoils.o: forcemultiplecoils.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/forcemultiplecoils.o.d 
	@${RM} ${OBJECTDIR}/forcemultiplecoils.o.ok ${OBJECTDIR}/forcemultiplecoils.o.err 
	@${RM} ${OBJECTDIR}/forcemultiplecoils.o 
	@${FIXDEPS} "${OBJECTDIR}/forcemultiplecoils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/forcemultiplecoils.o.d" -o ${OBJECTDIR}/forcemultiplecoils.o forcemultiplecoils.c    
	
${OBJECTDIR}/forcesinglecoil.o: forcesinglecoil.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/forcesinglecoil.o.d 
	@${RM} ${OBJECTDIR}/forcesinglecoil.o.ok ${OBJECTDIR}/forcesinglecoil.o.err 
	@${RM} ${OBJECTDIR}/forcesinglecoil.o 
	@${FIXDEPS} "${OBJECTDIR}/forcesinglecoil.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/forcesinglecoil.o.d" -o ${OBJECTDIR}/forcesinglecoil.o forcesinglecoil.c    
	
${OBJECTDIR}/ReadInputRegisters.o: ReadInputRegisters.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ReadInputRegisters.o.d 
	@${RM} ${OBJECTDIR}/ReadInputRegisters.o.ok ${OBJECTDIR}/ReadInputRegisters.o.err 
	@${RM} ${OBJECTDIR}/ReadInputRegisters.o 
	@${FIXDEPS} "${OBJECTDIR}/ReadInputRegisters.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ReadInputRegisters.o.d" -o ${OBJECTDIR}/ReadInputRegisters.o ReadInputRegisters.c    
	
${OBJECTDIR}/TestingFunction.o: TestingFunction.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TestingFunction.o.d 
	@${RM} ${OBJECTDIR}/TestingFunction.o.ok ${OBJECTDIR}/TestingFunction.o.err 
	@${RM} ${OBJECTDIR}/TestingFunction.o 
	@${FIXDEPS} "${OBJECTDIR}/TestingFunction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TestingFunction.o.d" -o ${OBJECTDIR}/TestingFunction.o TestingFunction.c    
	
${OBJECTDIR}/modbuserror.o: modbuserror.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/modbuserror.o.d 
	@${RM} ${OBJECTDIR}/modbuserror.o.ok ${OBJECTDIR}/modbuserror.o.err 
	@${RM} ${OBJECTDIR}/modbuserror.o 
	@${FIXDEPS} "${OBJECTDIR}/modbuserror.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/modbuserror.o.d" -o ${OBJECTDIR}/modbuserror.o modbuserror.c    
	
${OBJECTDIR}/presetmultipleregisters.o: presetmultipleregisters.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/presetmultipleregisters.o.d 
	@${RM} ${OBJECTDIR}/presetmultipleregisters.o.ok ${OBJECTDIR}/presetmultipleregisters.o.err 
	@${RM} ${OBJECTDIR}/presetmultipleregisters.o 
	@${FIXDEPS} "${OBJECTDIR}/presetmultipleregisters.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/presetmultipleregisters.o.d" -o ${OBJECTDIR}/presetmultipleregisters.o presetmultipleregisters.c    
	
${OBJECTDIR}/presetsingleregister.o: presetsingleregister.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/presetsingleregister.o.d 
	@${RM} ${OBJECTDIR}/presetsingleregister.o.ok ${OBJECTDIR}/presetsingleregister.o.err 
	@${RM} ${OBJECTDIR}/presetsingleregister.o 
	@${FIXDEPS} "${OBJECTDIR}/presetsingleregister.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/presetsingleregister.o.d" -o ${OBJECTDIR}/presetsingleregister.o presetsingleregister.c    
	
${OBJECTDIR}/readcoilstatus.o: readcoilstatus.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/readcoilstatus.o.d 
	@${RM} ${OBJECTDIR}/readcoilstatus.o.ok ${OBJECTDIR}/readcoilstatus.o.err 
	@${RM} ${OBJECTDIR}/readcoilstatus.o 
	@${FIXDEPS} "${OBJECTDIR}/readcoilstatus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/readcoilstatus.o.d" -o ${OBJECTDIR}/readcoilstatus.o readcoilstatus.c    
	
${OBJECTDIR}/readinputstatus.o: readinputstatus.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/readinputstatus.o.d 
	@${RM} ${OBJECTDIR}/readinputstatus.o.ok ${OBJECTDIR}/readinputstatus.o.err 
	@${RM} ${OBJECTDIR}/readinputstatus.o 
	@${FIXDEPS} "${OBJECTDIR}/readinputstatus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/readinputstatus.o.d" -o ${OBJECTDIR}/readinputstatus.o readinputstatus.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Version5.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -o ${DISTDIR}/Version5.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1
else
${DISTDIR}/Version5.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Version5.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex ${DISTDIR}/Version5.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
