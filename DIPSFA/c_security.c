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

#include "c_security.h"

/* -----------------------------------------------------------------
        Function declarations
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

    if ( (ptr == NULL) && (size != 0) ) /* If size == 0, memory is deallocated */
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
        fatal_error ( ); /* Just as a matter of precaution */
    }
}
