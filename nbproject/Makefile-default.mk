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
FINAL_IMAGE=${DISTDIR}/ModbusTcpRenamed8Fn.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ModbusTcpRenamed8Fn.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=libModbus/modbuserror.c libModbus/ModbusPacketParse.c libModbus/ModbusFrame.c libModbus/presetMultipleRegisters.c libModbus/presetSingleRegister.c libModbus/holdingReg.c main.c libModbus/ReadInputRegisters.c libModbus/forcemultiplecoils.c libModbus/forcesinglecoil.c libModbus/readcoilstatus.c libModbus/readinputstatus.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/libModbus/modbuserror.o ${OBJECTDIR}/libModbus/ModbusPacketParse.o ${OBJECTDIR}/libModbus/ModbusFrame.o ${OBJECTDIR}/libModbus/presetMultipleRegisters.o ${OBJECTDIR}/libModbus/presetSingleRegister.o ${OBJECTDIR}/libModbus/holdingReg.o ${OBJECTDIR}/main.o ${OBJECTDIR}/libModbus/ReadInputRegisters.o ${OBJECTDIR}/libModbus/forcemultiplecoils.o ${OBJECTDIR}/libModbus/forcesinglecoil.o ${OBJECTDIR}/libModbus/readcoilstatus.o ${OBJECTDIR}/libModbus/readinputstatus.o
POSSIBLE_DEPFILES=${OBJECTDIR}/libModbus/modbuserror.o.d ${OBJECTDIR}/libModbus/ModbusPacketParse.o.d ${OBJECTDIR}/libModbus/ModbusFrame.o.d ${OBJECTDIR}/libModbus/presetMultipleRegisters.o.d ${OBJECTDIR}/libModbus/presetSingleRegister.o.d ${OBJECTDIR}/libModbus/holdingReg.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/libModbus/ReadInputRegisters.o.d ${OBJECTDIR}/libModbus/forcemultiplecoils.o.d ${OBJECTDIR}/libModbus/forcesinglecoil.o.d ${OBJECTDIR}/libModbus/readcoilstatus.o.d ${OBJECTDIR}/libModbus/readinputstatus.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/libModbus/modbuserror.o ${OBJECTDIR}/libModbus/ModbusPacketParse.o ${OBJECTDIR}/libModbus/ModbusFrame.o ${OBJECTDIR}/libModbus/presetMultipleRegisters.o ${OBJECTDIR}/libModbus/presetSingleRegister.o ${OBJECTDIR}/libModbus/holdingReg.o ${OBJECTDIR}/main.o ${OBJECTDIR}/libModbus/ReadInputRegisters.o ${OBJECTDIR}/libModbus/forcemultiplecoils.o ${OBJECTDIR}/libModbus/forcesinglecoil.o ${OBJECTDIR}/libModbus/readcoilstatus.o ${OBJECTDIR}/libModbus/readinputstatus.o

# Source Files
SOURCEFILES=libModbus/modbuserror.c libModbus/ModbusPacketParse.c libModbus/ModbusFrame.c libModbus/presetMultipleRegisters.c libModbus/presetSingleRegister.c libModbus/holdingReg.c main.c libModbus/ReadInputRegisters.c libModbus/forcemultiplecoils.c libModbus/forcesinglecoil.c libModbus/readcoilstatus.c libModbus/readinputstatus.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/ModbusTcpRenamed8Fn.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24EP128GP202
MP_LINKER_FILE_OPTION=,--script=p24EP128GP202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/libModbus/modbuserror.o: libModbus/modbuserror.c  .generated_files/flags/default/8f71cae5df0af4e382826e18d0d6ec41c9f16aa8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/modbuserror.o.d 
	@${RM} ${OBJECTDIR}/libModbus/modbuserror.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/modbuserror.c  -o ${OBJECTDIR}/libModbus/modbuserror.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/modbuserror.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/ModbusPacketParse.o: libModbus/ModbusPacketParse.c  .generated_files/flags/default/52b7d173bd2abb03c8f0e301393acb9966e15c4b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/ModbusPacketParse.o.d 
	@${RM} ${OBJECTDIR}/libModbus/ModbusPacketParse.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/ModbusPacketParse.c  -o ${OBJECTDIR}/libModbus/ModbusPacketParse.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/ModbusPacketParse.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/ModbusFrame.o: libModbus/ModbusFrame.c  .generated_files/flags/default/bc1f75608fd0e7a086e48011802359c860a838c3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/ModbusFrame.o.d 
	@${RM} ${OBJECTDIR}/libModbus/ModbusFrame.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/ModbusFrame.c  -o ${OBJECTDIR}/libModbus/ModbusFrame.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/ModbusFrame.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/presetMultipleRegisters.o: libModbus/presetMultipleRegisters.c  .generated_files/flags/default/451b40c1286155889b553b71bd8b17ed26ecd70c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/presetMultipleRegisters.o.d 
	@${RM} ${OBJECTDIR}/libModbus/presetMultipleRegisters.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/presetMultipleRegisters.c  -o ${OBJECTDIR}/libModbus/presetMultipleRegisters.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/presetMultipleRegisters.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/presetSingleRegister.o: libModbus/presetSingleRegister.c  .generated_files/flags/default/28a8dc4753edd5722df92614492fad16cd0b8028 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/presetSingleRegister.o.d 
	@${RM} ${OBJECTDIR}/libModbus/presetSingleRegister.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/presetSingleRegister.c  -o ${OBJECTDIR}/libModbus/presetSingleRegister.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/presetSingleRegister.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/holdingReg.o: libModbus/holdingReg.c  .generated_files/flags/default/5fbdbf53280e2298609636f9b5eb9d09dccf958e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/holdingReg.o.d 
	@${RM} ${OBJECTDIR}/libModbus/holdingReg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/holdingReg.c  -o ${OBJECTDIR}/libModbus/holdingReg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/holdingReg.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/50f3dc66fbd987e187130d9c4b8157f5ca259a1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/ReadInputRegisters.o: libModbus/ReadInputRegisters.c  .generated_files/flags/default/43a9d908b131d6e906961e43938ab23bc7ee358d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/ReadInputRegisters.o.d 
	@${RM} ${OBJECTDIR}/libModbus/ReadInputRegisters.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/ReadInputRegisters.c  -o ${OBJECTDIR}/libModbus/ReadInputRegisters.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/ReadInputRegisters.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/forcemultiplecoils.o: libModbus/forcemultiplecoils.c  .generated_files/flags/default/f90b839673aa85f526ef30ad467d47f5de67ebdd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/forcemultiplecoils.o.d 
	@${RM} ${OBJECTDIR}/libModbus/forcemultiplecoils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/forcemultiplecoils.c  -o ${OBJECTDIR}/libModbus/forcemultiplecoils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/forcemultiplecoils.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/forcesinglecoil.o: libModbus/forcesinglecoil.c  .generated_files/flags/default/129e466053105d629bca60f8c4d6df3fbb043d2e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/forcesinglecoil.o.d 
	@${RM} ${OBJECTDIR}/libModbus/forcesinglecoil.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/forcesinglecoil.c  -o ${OBJECTDIR}/libModbus/forcesinglecoil.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/forcesinglecoil.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/readcoilstatus.o: libModbus/readcoilstatus.c  .generated_files/flags/default/319fc85a76dbb68418841b43cfdd2e2bf7289f26 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/readcoilstatus.o.d 
	@${RM} ${OBJECTDIR}/libModbus/readcoilstatus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/readcoilstatus.c  -o ${OBJECTDIR}/libModbus/readcoilstatus.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/readcoilstatus.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/readinputstatus.o: libModbus/readinputstatus.c  .generated_files/flags/default/bd21d1266af0fb847041acf1e0c5add0df329072 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/readinputstatus.o.d 
	@${RM} ${OBJECTDIR}/libModbus/readinputstatus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/readinputstatus.c  -o ${OBJECTDIR}/libModbus/readinputstatus.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/readinputstatus.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/libModbus/modbuserror.o: libModbus/modbuserror.c  .generated_files/flags/default/660b1927015292fdb3b93f65c61cf8180c8e0ee6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/modbuserror.o.d 
	@${RM} ${OBJECTDIR}/libModbus/modbuserror.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/modbuserror.c  -o ${OBJECTDIR}/libModbus/modbuserror.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/modbuserror.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/ModbusPacketParse.o: libModbus/ModbusPacketParse.c  .generated_files/flags/default/1322182ef12b887564ee5574ab64a9e90aeaf300 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/ModbusPacketParse.o.d 
	@${RM} ${OBJECTDIR}/libModbus/ModbusPacketParse.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/ModbusPacketParse.c  -o ${OBJECTDIR}/libModbus/ModbusPacketParse.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/ModbusPacketParse.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/ModbusFrame.o: libModbus/ModbusFrame.c  .generated_files/flags/default/fe2a2456b778a8a15b29a8556341ad33abf7f72b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/ModbusFrame.o.d 
	@${RM} ${OBJECTDIR}/libModbus/ModbusFrame.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/ModbusFrame.c  -o ${OBJECTDIR}/libModbus/ModbusFrame.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/ModbusFrame.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/presetMultipleRegisters.o: libModbus/presetMultipleRegisters.c  .generated_files/flags/default/d7a26a0ee4248719441dff0d169db5247777bfe7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/presetMultipleRegisters.o.d 
	@${RM} ${OBJECTDIR}/libModbus/presetMultipleRegisters.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/presetMultipleRegisters.c  -o ${OBJECTDIR}/libModbus/presetMultipleRegisters.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/presetMultipleRegisters.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/presetSingleRegister.o: libModbus/presetSingleRegister.c  .generated_files/flags/default/b838ad60f7fb8e3150c384993ece85291349821d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/presetSingleRegister.o.d 
	@${RM} ${OBJECTDIR}/libModbus/presetSingleRegister.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/presetSingleRegister.c  -o ${OBJECTDIR}/libModbus/presetSingleRegister.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/presetSingleRegister.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/holdingReg.o: libModbus/holdingReg.c  .generated_files/flags/default/fb6394bca196faa0428fcc118268ca938313231d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/holdingReg.o.d 
	@${RM} ${OBJECTDIR}/libModbus/holdingReg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/holdingReg.c  -o ${OBJECTDIR}/libModbus/holdingReg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/holdingReg.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/f0643acf41738db1671460280d4713d7ae597f70 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/ReadInputRegisters.o: libModbus/ReadInputRegisters.c  .generated_files/flags/default/6ce31b3a9f9178be644c9a1acd8448a14f506e1d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/ReadInputRegisters.o.d 
	@${RM} ${OBJECTDIR}/libModbus/ReadInputRegisters.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/ReadInputRegisters.c  -o ${OBJECTDIR}/libModbus/ReadInputRegisters.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/ReadInputRegisters.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/forcemultiplecoils.o: libModbus/forcemultiplecoils.c  .generated_files/flags/default/a80dacf6e10c3c56f94cd2fa522232c6db7bf1f9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/forcemultiplecoils.o.d 
	@${RM} ${OBJECTDIR}/libModbus/forcemultiplecoils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/forcemultiplecoils.c  -o ${OBJECTDIR}/libModbus/forcemultiplecoils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/forcemultiplecoils.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/forcesinglecoil.o: libModbus/forcesinglecoil.c  .generated_files/flags/default/d3d4a8047b4f9b8bc219faab5616ffd778178769 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/forcesinglecoil.o.d 
	@${RM} ${OBJECTDIR}/libModbus/forcesinglecoil.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/forcesinglecoil.c  -o ${OBJECTDIR}/libModbus/forcesinglecoil.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/forcesinglecoil.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/readcoilstatus.o: libModbus/readcoilstatus.c  .generated_files/flags/default/d4822a4834c2be3143d7d1f7bb7044f3e7ecbae5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/readcoilstatus.o.d 
	@${RM} ${OBJECTDIR}/libModbus/readcoilstatus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/readcoilstatus.c  -o ${OBJECTDIR}/libModbus/readcoilstatus.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/readcoilstatus.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/libModbus/readinputstatus.o: libModbus/readinputstatus.c  .generated_files/flags/default/5b9be779c1059d7ee0bafa42254819d81c33788d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/libModbus" 
	@${RM} ${OBJECTDIR}/libModbus/readinputstatus.o.d 
	@${RM} ${OBJECTDIR}/libModbus/readinputstatus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  libModbus/readinputstatus.c  -o ${OBJECTDIR}/libModbus/readinputstatus.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/libModbus/readinputstatus.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -msmall-data -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/ModbusTcpRenamed8Fn.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/ModbusTcpRenamed8Fn.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/ModbusTcpRenamed8Fn.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/ModbusTcpRenamed8Fn.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/ModbusTcpRenamed8Fn.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
