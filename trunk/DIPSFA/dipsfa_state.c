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
    s->tool_arguments = NULL;
    s->mode = NONE_MODE;
    s->ptool = NONE;
    s->mytool->arguments = NULL;
    s->mytool->audit_file = NULL;
    s->mytool->audit_file_name = NULL;
    s->mytool->directory = NULL;
    s->mytool->input_file = NULL;
    s->mytool->ptool = NONE;
}

void free_dipsfa ( dipsfa_state * s )
{
    free_s ( s->input_file );
    free_s ( s->tool_arguments );
}

void set_operation_mode ( dipsfa_state * s, char * mode )
{
    if ( strcmp ( "server", mode ) == 0 )
    {
        s->mode = SERVER_MODE;
    }
    else
        if ( strcmp ( "client", mode ) == 0 )
    {
        s->mode = CLIENT_MODE;
    }
}

void set_input_file ( dipsfa_state * s, char * filename )
{
    s->input_file = malloc_s ( ( strlen ( filename ) + 1 ) * sizeof (char) );
    strncpy ( s->input_file, filename, strlen ( filename ) + 1 );
}

void set_processing_tool ( dipsfa_state * s, char * toolname )
{
    if ( strcmp ( "foremost", toolname ) == 0 )
    {
        s->ptool = FOREMOST;
    }
    else
        if ( strcmp ( "scalpel", toolname ) == 0 )
    {
        s->ptool = SCALPEL;
    }
    else
        if ( strcmp ( "ent", toolname ) == 0 )
    {
        s->ptool = ENT;
    }
}

void set_tool_arguments ( dipsfa_state * s, char * arguments )
{
    register uint32_t i;
    register uint32_t argvlen = strlen ( arguments );

    s->tool_arguments = malloc_s ( ( ( 3 * argvlen ) + 1 ) * sizeof (char) );

    for ( i = 0; i < argvlen; i++ )
    {
        s->tool_arguments[( 3 * i )] = '-';
        s->tool_arguments[( 3 * i ) + 1] = arguments[i];
        s->tool_arguments[( 3 * i ) + 2] = ' ';
    }
}

char * get_ptool_name ( dipsfa_state * s )
{
    char * toolname = malloc_s ( 12 * sizeof (char) );

    if ( s->ptool == FOREMOST )
    {
        strncpy ( toolname, "foremost", 8 );
    }
    else
        if ( s->ptool == SCALPEL )
    {
        strncpy ( toolname, "scalpel", 7 );
    }
    else
        if ( s->ptool == ENT )
    {
        strncpy ( toolname, "ent", 3 );
    }
    return toolname;
}

char * get_input_file ( dipsfa_state * s )
{
    return s->input_file;
}

char * get_tool_arguments ( dipsfa_state * s )
{
    return s->tool_arguments;
}

struct ptool_s get_ptool_s ( dipsfa_state * s )
{
    return s->mytool;
}

enum ptool_e get_ptool_e ( dipsfa_state * s )
{
    return s->ptool;
}