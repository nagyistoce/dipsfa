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

void initialize_tool ( ptool_s * t )
{
    t->directory = NULL;
    t->input_file = NULL;
    t->output_directory = NULL;
    t->audit_file = NULL;
    t->arguments = NULL;
    t->audit_file = NULL;
    t->ptool = NONE;
}

void free_tool ( ptool_s * t )
{
    free_s ( t->directory );
    free_s ( t->input_file );
    free_s ( t->output_directory );
    free_s ( t->audit_file );
    free_s ( t->arguments );
    free_s ( t->audit_file_name );
}

void start_tool ( ptool_s * t )
{
    /*strcat ./name arguments */
    /*popen command...*/
}