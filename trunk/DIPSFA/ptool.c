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

void initialize_tool ( p_tool * t )
{
    t->directory = NULL;
    t->name = NULL;
    t->input_file = NULL;
    t->output_directory = NULL;
    t->audit_file = NULL;
    t->arguments = NULL;
    t->audit_file = NULL;
}

void free_tool ( p_tool * t )
{
    free ( t->directory );
    free ( t->name );
    free ( t->input_file );
    free ( t->output_directory );
    free ( t->audit_file );
    free ( t->arguments );
    free ( t->audit_file_name );
}

void start_tool ( p_tool * t )
{
    /*strcat ./name arguments */
    /*popen command...*/
}

/*
void start_tool ( p_tool * t )
void set_tool_input_file ( p_tool * t );
void set_tool_name ( p_tool * t );
void set_tool_directory ( p_tool * t );
void set_tool_arguments ( dipsfa_state * s, char * filename );
void set_processing_tool ( dipsfa_state * s, char * filename );
FILE * get_tool_audit_file ( p_tool * t );
 */