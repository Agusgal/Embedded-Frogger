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
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Audio.o \
	${OBJECTDIR}/Check_Frog.o \
	${OBJECTDIR}/Draw\ Vehicules.o \
	${OBJECTDIR}/Draw_Frog.o \
	${OBJECTDIR}/Game\ Threads.o \
	${OBJECTDIR}/Scoring\ System.o \
	${OBJECTDIR}/Screens.o \
	${OBJECTDIR}/gameboard.o \
	${OBJECTDIR}/main_frogger.o


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
LDLIBSOPTIONS=-lallegro.5.2.4 -lallegro.5.2 -lallegro -lallegro_acodec.5.2.4 -lallegro_acodec.5.2 -lallegro_acodec -lallegro_audio.5.2.4 -lallegro_audio.5.2 -lallegro_audio -lallegro_color.5.2.4 -lallegro_color.5.2 -lallegro_color -lallegro_dialog.5.2.4 -lallegro_dialog.5.2 -lallegro_dialog -lallegro_font.5.2.4 -lallegro_font.5.2 -lallegro_font -lallegro_image.5.2.4 -lallegro_image.5.2 -lallegro_image -lallegro_main.5.2.4 -lallegro_main.5.2 -lallegro_main -lallegro_memfile.5.2.4 -lallegro_memfile.5.2 -lallegro_memfile -lallegro_physfs.5.2.4 -lallegro_physfs.5.2 -lallegro_physfs -lallegro_primitives.5.2.4 -lallegro_primitives.5.2 -lallegro_primitives -lallegro_ttf.5.2.4 -lallegro_ttf.5.2 -lallegro_ttf -lallegro_video.5.2.4 -lallegro_video.5.2 -lallegro_video

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tpf_con_menu_nuevo

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tpf_con_menu_nuevo: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tpf_con_menu_nuevo ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Audio.o: Audio.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Audio.o Audio.c

${OBJECTDIR}/Check_Frog.o: Check_Frog.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Check_Frog.o Check_Frog.c

.NO_PARALLEL:${OBJECTDIR}/Draw\ Vehicules.o
${OBJECTDIR}/Draw\ Vehicules.o: Draw\ Vehicules.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Draw\ Vehicules.o Draw\ Vehicules.c

${OBJECTDIR}/Draw_Frog.o: Draw_Frog.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Draw_Frog.o Draw_Frog.c

.NO_PARALLEL:${OBJECTDIR}/Game\ Threads.o
${OBJECTDIR}/Game\ Threads.o: Game\ Threads.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game\ Threads.o Game\ Threads.c

.NO_PARALLEL:${OBJECTDIR}/Scoring\ System.o
${OBJECTDIR}/Scoring\ System.o: Scoring\ System.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Scoring\ System.o Scoring\ System.c

${OBJECTDIR}/Screens.o: Screens.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Screens.o Screens.c

${OBJECTDIR}/gameboard.o: gameboard.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gameboard.o gameboard.c

${OBJECTDIR}/main_frogger.o: main_frogger.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_frogger.o main_frogger.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
