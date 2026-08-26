/*
// File:       /cmds/refs/_fref.c
// Purpose:    frontend to profile_function efun
// Mudlib:     TMI-2
// 93-07-24    Written by Douglas Reay (Pallando @ most muds)
//             Only works for MudOS Driver Version 0.9.17.3 +
//             and only if function profiling is set in options.h
// 94-11-11    Leto@Earth added #ifdef
*/

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;
inherit REF_D;

#define SYNTAX "Syntax: fref <object>\n"

string *unused;
int total_cpu;

int filter( mapping a )
{
    if( !a["calls"] )
    {
        unused += ({ a["name"] });
        return 0;
    }
    a["sort"] = a["self"];
    total_cpu += a["self"] - a["children"];
    return 1;
}

int compare( mapping a, mapping b )
{
    if( b["sort"] == a["sort"] ) return b["calls"] - a["calls"];
    return b["sort"] - a["sort"];
}

void display( mapping a )
{
    printf( "%12d   %-25s %8d %12d\n",
        a["sort"], a["name"], a["calls"], ( a["sort"] / a["calls"] ),
    );
}

int cmd_fref( mixed a )
{
    int childs;
    object ob;
    mixed *funcs;

#ifndef PROFILE_FUNCTIONS
  write("Driver not compiled with PROFILE_FUNCTIONS!\n");
  return 1;
#else
    notify_fail( SYNTAX );
    if( !a ) return 0;

    ob = ref_ob( a );
    if( !objectp( ob ) )
    {
        notify_fail( wrap( "Could not identify " + identify( (ob?ob:a) ) +
            " as an object." ) );
        return 0;
    }

    total_cpu = 0;
    unused = ({ });
    childs = sizeof( children( base_name( ob ) ) );
    write( "Profile of functions in " + base_name( ob ) );
    write( " (copies = " + childs + ")\n" );

    funcs = function_profile( ob );
    funcs = filter_array( funcs, "filter",  this_object() );
    funcs = sort_array(   funcs, "compare", this_object() );
    if( sizeof( funcs ) ) write( "\
    Cpu Time   Function Name         Number Calls    Time/Call\n" );
    funcs = map_array(    funcs, "display", this_object() );

    if( sizeof( unused ) )
        write( wrap( "Uncalled functions = " + implode( unused, " " ) ) );
    // NB this doesn't work well for objects which spend an apreciable
    // proportion of their time calling other objects (such as user.c)
    write( "Total cpu time = " + total_cpu + "\n" );

    return 1;
}

int help()
{
    write( SYNTAX + @HelpText
Effect: Breaks down cpu usage of <object> by function.
  Uses the function_profile() efun (if you define function profiling
  in the options.h file of the driver)
  This returns information on each function used, not by an individual
  object but by a group of objects (see "help function_profile").
  The groups consists of the base object (if still loaded) and any clones
  of that object that are still loaded.  If the base object is updated
  you get two groups - the new base object and any clones of it, and any
  surviving clones of the old base object (the previous generation).
  The efun provies the following information on each function:
  "calls" - how many time the function has been called.
  "self" - total cpu time spent executing the function.
  "children" - cpu time spent executing functions called by the function.

  Times are given in microseconds.
HelpText
    );
    return 1;
#endif
}

/* EOF */
