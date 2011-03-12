/*
    DIPSFA -- Distributed Image Processing Server for Forensics Analysis
    Copyright (C) 2011 - Juan Gabriel Calderon-Perez
    Website: http://code.google.com/p/dipsfa
    Written by Juan Gabriel Calderon-Perez

    C_SECURITY.h is a Basic Security Library part of DIPSFA.

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
        Function definitions
     * ----------------------------------------------------------------- */
    void fatal_error ( void );
    void * malloc_s ( size_t size );
    void * realloc_s ( void * myptr, size_t size );
    void * calloc_s ( size_t num, size_t size );
    void free_s ( void * ptr );

#ifdef	__cplusplus
}
#endif

#endif	/* C_SECURITY_H */