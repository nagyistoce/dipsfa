/*
    DIPSFA -- Distributed Image Processing Server for Forensics Analysis
    Copyright (C) 2011 - Juan Gabriel Calderon-Perez
    Website: http://code.google.com/p/dipsfa
    Written by Juan Gabriel Calderon-Perez

    c_security.h is a C Security Library written for the DIPSFA project.

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

#pragma once

#ifndef C_SECURITY_H
#define	C_SECURITY_H

#ifdef	__cplusplus
extern "C" {
#endif

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

#define TRUE   1
#define FALSE  0

    /* -----------------------------------------------------------------
            Dynamic Memory Management
     * ----------------------------------------------------------------- */
    void fatal_error ( void );
    void * malloc_s ( size_t size );
    void * realloc_s ( void * myptr, size_t size );
    void * calloc_s ( size_t num, size_t size );
    void free_s ( void * ptr );

    /* -----------------------------------------------------------------
            File I/O Management
     * ----------------------------------------------------------------- */
    FILE * fopen_s ( const char * filename, const char * mode );
    void fclose_s ( FILE * stream );
    size_t fread_s ( void * ptr, size_t size, size_t count, FILE * stream );
    size_t fwrite_s ( const void * ptr, size_t size, size_t count, FILE * stream );
    void fseek_s ( FILE * stream, long int offset, int origin );
    long int ftell_s ( FILE * stream );
    FILE * popen_s ( const char * command, const char * type );
    int pclose_s ( FILE * stream );

#ifdef	__cplusplus
}
#endif

#endif	/* C_SECURITY_H */