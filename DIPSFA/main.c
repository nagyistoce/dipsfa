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

void try_msg ( void )
{
    fprintf ( stderr, "Try `%s -h` for more information.\n", PROGRAM_NAME );
}

void dipsfa_help ( void )
{
    fprintf ( stderr, "\nDIPSFA - Distributed Image Processing Server for Forensics Analysis\n\n" );
    fprintf ( stderr, "$ %s [-V|-h [-i <file] [-m <mode] [-t <tool_name] [-a tool_args]\n\n", PROGRAM_NAME );
    fprintf ( stderr, "\t -V  display copyright information and exit.\n" );
    fprintf ( stderr, "\t -i  specify input file.\n" );
    fprintf ( stderr, "\t -m  specify the operating mode (ej. SERVER or CLIENT).\n" );
    fprintf ( stderr, "\t -t  specify the processing tool.\n" );
    fprintf ( stderr, "\t -a  specify tool arguments(ej. vCih).\n\n" );
    fprintf ( stderr, "%s version %s by %s.\n", PROGRAM_NAME, VERSION, AUTHOR );
    fprintf ( stderr, "http://code.google.com/p/dipsfa/ \n" );
    fprintf ( stderr, "%s\n\n", UPDATE );
}

void process_command_line ( int argc, char **argv, dipsfa_state * s )
{
    int32_t i;

    while ( ( i = getopt ( argc, argv, "m:t:i:a:hvV" ) ) != -1 )
    {
        switch ( i )
        {
            case 'i':
                set_input_file ( s, optarg );
                free_s ( s->input_file );
                break;

            case 'm':
                set_operation_mode ( s, optarg );
                break;

            case 't':
                set_processing_tool ( s, optarg );
                break;

            case 'a':
                set_tool_arguments ( s, optarg );
                free_s ( s->tool_arguments );
                break;

            case 'h':
                dipsfa_help ( );
                exit ( EXIT_SUCCESS );

            case 'V':
                printf ( "%s", COPYRIGHT );
                exit ( EXIT_SUCCESS );

            default:
                try_msg ( ); /* FIX not working... */
                exit ( EXIT_FAILURE );
        }
    }
}

int main ( int argc, char** argv )
{
    dipsfa_state * t = malloc ( sizeof (dipsfa_state ) );
    /*init dipsfa_state*/
    process_command_line ( argc, argv, t );
    /*free dipsfa_state...*/
    return (EXIT_SUCCESS );
} /* end main */