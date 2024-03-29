/*
    DIPSFA -- Distributed Image Processing Server for Forensics Analysis
    Copyright (C) 2011 - Juan Gabriel Calderon-Perez
    Website: http://code.google.com/p/dipsfa
    Written by Juan Gabriel Calderon-Perez

    This file is part of DIPSFA.
    
    DIPSFA is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DIPSFA is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with DIPSFA.  If not, see http://www.gnu.org/licenses/.
 */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#define AUTHOR  "Juan Gabriel Calderon-Perez"

#define COPYRIGHT "\nDIPSFA -- Distributed Image Processing Server for Forensics Analysis\n"\
    "Copyright (C) 2011 - Juan Gabriel Calderon-Perez\n"\
    "Website: http://code.google.com/p/dipsfa\n"\
    "Written by Juan Gabriel Calderon-Perez\n\n"\
    "This program is free software: you can redistribute it and/or modify\n"\
    "it under the terms of the GNU General Public License as published by\n"\
    "the Free Software Foundation, either version 3 of the License, or\n"\
    "(at your option) any later version.\n\n"\
    "This program is distributed in the hope that it will be useful,\n"\
    "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"\
    "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"\
    "GNU General Public License for more details.\n\n"\
    "You should have received a copy of the GNU General Public License\n"\
    "along with this program.  If not, see http://www.gnu.org/licenses/.\n\n"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <stdarg.h>
#include <pthread.h>
#include "c_security.h"  /*Basic Security Library for DIPSFA*/

#define TRUE   1
#define FALSE  0
#define PROGRAM_NAME             "DIPSFA"
#define VERSION                  "0.1-alpha"
#define UPDATE                   "March 4, 2011"
#define DIPSFA_CONFIG_FILE       "config.conf"
#define SERVER_CONFIG_FILE       "server.conf"
#define CLIENT_CONFIG_FILE       "client.conf"
#define DIVIDER "-------------------------------------------------------------"
#define LINE_LENGTH 74

#define KILOBYTE                  1024
#define MEGABYTE                  1024 * KILOBYTE
#define GIGABYTE                  1024 * MEGABYTE
#define TERABYTE                  1024 * GIGABYTE
#define PETABYTE                  1024 * TERABYTE
#define EXABYTE                   1024 * PETABYTE

    /* -----------------------------------------------------------------
        State and Global Variables
    ----------------------------------------------------------------- */
    enum mode_t {
        NONE_MODE = 0,
        SERVER_MODE = 1 << 1,
        CLIENT_MODE = 1 << 2
    };

    enum ptool_e {
        NONE = 0,
        FOREMOST = 1 << 1,
        SCALPEL = 1 << 2,
        ENT = 1 << 3
    };

    typedef struct ptool_s {
        char * directory; /* Tool directory */
        char * input_file; /* Input file for processing */
        char * output_directory; /* Tool output directory */
        char * audit_file_name; /* Audit file name */
        char * arguments; /* Arguments to run tool */
        enum ptool_e ptool; /* Selected Tool */
        FILE * audit_file; /* File pointer to audit file */
    } ptool_s;

    typedef struct dipsfa_state {
        char * input_file;
        char * tool_arguments;
        struct ptool_s mytool;
        enum mode_t mode;
        enum ptool_e ptool;
    } dipsfa_state;

    /* -----------------------------------------------------------------
        Function definitions
     * ----------------------------------------------------------------- */

    /* Processing Tool functions */
    void initialize_tool ( ptool_s * t );
    void start_tool ( ptool_s * t );
    void free_tool ( ptool_s * t );
    void set_tool_input_file ( ptool_s * t, char * filename );
    void set_tool_name ( ptool_s * t, char * toolname );
    void set_tool_directory ( ptool_s * t, char * dirname );
    void set_tool_output_directory ( ptool_s * t, char * dirname );
    FILE * get_tool_audit_file ( ptool_s * t );
    void query_back_results ( ptool_s * t );
    void fetch_results ( ptool_s * t );

    /* Engine functions */
    void initialize_dipsfa ( dipsfa_state * s );
    void free_dipsfa ( dipsfa_state * s );
    void set_operation_mode ( dipsfa_state * s, char * filename );
    void set_input_file ( dipsfa_state * s, char * filename );
    void set_processing_tool ( dipsfa_state * s, char * toolname );
    void set_tool_arguments ( dipsfa_state * s, char * arguments );
    char * get_ptool_name ( dipsfa_state * s );
    char * get_input_file ( dipsfa_state * s );
    char * get_tool_arguments ( dipsfa_state * s );
    struct ptool_s get_ptool_s ( dipsfa_state * s );
    enum ptool_e get_ptool_e ( dipsfa_state * s );

    /* Client functions */

    /* Server functions */

    /* Database functions */

    /* Networks functions */

    /* Extra functions */
#ifdef __WIN32
    int getopt ( int argc, char *const argv[], const char *optstring );
#endif    
    void process_command_line ( int argc, char **argv, dipsfa_state * s );
    void try_msg ( void );
    void dipsfa_help ( void );

#ifdef	__cplusplus
}
#endif

#endif	/* __MAIN_H */