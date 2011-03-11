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

#include "main.h"

void initialize_dipsfa ( dipsfa_state * s )
{
    s->input_file = NULL;
    s->ptool = NULL;
    s->tool_arguments = NULL;
}

void free_dipsfa ( dipsfa_state * s )
{
    free ( s->input_file );
    free ( s->ptool );
    free ( s->tool_arguments );
}

void set_input_file ( dipsfa_state * s, char * filename )
{
    s->input_file = malloc ( ( strlen ( filename ) + 1 ) * sizeof (char) );
    strncpy ( s->input_file, filename, strlen ( filename ) + 1 );
    printf ( "File: %s \n", s->input_file );
}

void set_processing_tool ( dipsfa_state * s, char * toolname )
{
    s->ptool = malloc ( ( strlen ( toolname ) + 1 ) * sizeof (char) );
    strncpy ( s->ptool, toolname, strlen ( toolname ) + 1 );
    printf ( "Tool: %s \n", s->ptool );
}

void set_tool_arguments ( dipsfa_state * s, char * arguments )
{
    register uint32_t i = 0;

    s->tool_arguments = malloc ( ( ( strlen ( arguments ) * 3 ) + 1 ) * sizeof (char) );

    for ( i = 0; i < strlen ( arguments ); i++ )
    {
        if ( i eq 0 )
        {
            s->tool_arguments[i] = '-';
            s->tool_arguments[i + 1] = arguments[i];
            s->tool_arguments[i + 2] = ' ';
        }
        else
        {
            s->tool_arguments[( 3 * i )] = '-';
            s->tool_arguments[( 3 * i ) + 1] = arguments[i];
            s->tool_arguments[( 3 * i ) + 2] = ' ';
        }
    }
}