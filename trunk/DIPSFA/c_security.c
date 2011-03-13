/*
    DIPSFA -- Distributed Image Processing Server for Forensics Analysis
    Copyright (C) 2011 - Juan Gabriel Calderon-Perez
    Website: http://code.google.com/p/dipsfa
    Written by Juan Gabriel Calderon-Perez

    c_security.c is a C Security Library written for the DIPSFA project.

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

#include "c_security.h"

/* -----------------------------------------------------------------
        Dynamic Memory Management
 * ----------------------------------------------------------------- */

void fatal_error ( void )
{
    perror ( "[**] Fatal Error" );
    fprintf ( stderr, "errno = %d\n", errno );
    exit ( EXIT_FAILURE );
}

void * malloc_s ( size_t size )
{
    void * ptr = malloc ( size );

    if ( ptr == NULL )
    {
        fatal_error ( );
    }
    return ptr;
}

void * realloc_s ( void * myptr, size_t size )
{
    void *ptr = realloc ( myptr, size );

    if ( ( ptr == NULL ) && ( size != 0 ) )
    {
        fatal_error ( );
    }
    return ptr;
}

void * calloc_s ( size_t num, size_t size )
{
    void * ptr = calloc ( num, size );

    if ( ptr == NULL )
    {
        fatal_error ( );
    }
    return ptr;
}

void free_s ( void * ptr )
{
    if ( !ptr )
    {
        free ( ptr );
    }
    else
    {
        fatal_error ( ); /* Unallocated pointer */
    }
}

/* -----------------------------------------------------------------
        File I/O Management
 * ----------------------------------------------------------------- */

FILE * fopen_s ( const char * filename, const char * mode )
{
    FILE * stream = fopen ( filename, mode );

    if ( stream == NULL )
    {
        fatal_error ( );
    }
    return stream;
}

void fclose_s ( FILE * stream )
{
    if ( fclose ( stream ) == EOF )
    {
        fatal_error ( );
    }
}

size_t fread_s ( void * ptr, size_t size, size_t count, FILE * stream )
{
    register size_t num = fread ( ptr, size, count, stream );

    if ( ( num != count ) && ( ferror ( stream ) != 0 ) )
    {
        fatal_error ( );
    }
    return num;
}

size_t fwrite_s ( const void * ptr, size_t size, size_t count, FILE * stream )
{
    register size_t num = fwrite ( ptr, size, count, stream );

    if ( num != count )
    {
        fatal_error ( );
    }
    return num;
}

void fseek_s ( FILE * stream, long int offset, int origin )
{
    if ( fseek ( stream, offset, origin ) != 0 )
    {
        fatal_error ( );
    }
}

long int ftell_s ( FILE * stream )
{
    long int position = ftell ( stream );

    if ( position == -1L )
    {
        fatal_error ( );
    }
    return position;
}

FILE * popen_s ( const char * command, const char * type )
{
    FILE * stream = popen ( command, type );

    if ( (stream == NULL) || (stream == -1) )
    {
        fatal_error ( );
    }
    return stream;
}

int pclose_s ( FILE * stream )
{
    if ( pclose ( stream ) == -1 )
    {
        fatal_error ( );
    }
}