/*
// File     :  guide.c
// Purpose  :  Hypertext LPC and general tmi-2 mud wizard guide
// 93-09-17 :  Written by Douglas Reay (Pallando @ TMI-2)
*/
#include <guide.h>

inherit "/std/hypertext";

string datafile()
{
    return GUIDE_DATA;
}

varargs int valid_write( string arg )
{
    return 0;
}

void write_prompt()
{
    if( index && mapp( data[index] ) && mapp( data[index]["links"] ) &&
      stringp( data[index]["links"]["default"] ) )
        printf( "(%s) Guide (%s): ", index, data[index]["links"]["default"] );
    else
        printf( "(%s) Guide (home): ", index );
}

void extra_create()
{
    set( "id", ({ "guide" }) );
    set( "name", "guide" );
    options = ([
        "h" : "option_h",
        "i" : "option_i",
        "items" : "option_i",
        "list" : "option_i",
        "l" : "option_l",
        "link" : "option_l",
        "links" : "option_l",
        "p" : "option_p",
        "hist" : "option_p",
        "history" : "option_p",
        "q" : "option_q",
        "quit" : "option_q",
        "r" : "option_r",
        "read" : "option_r", 
    ]);
    set( "help/options", @EndText
HELP PAGE                                                   HELP PAGE
               Help on interactive hypertext options

Item  - a piece of text
Index - the string by which an item is known, shown in ().  Eg (glossary.MUD)
Link  - the string you type when at one item to go to another,
        shown in {}.  Eg {MUD}
Option - single character commands that work at any item
  h    - help (this message)
  q    - quit
  l    - link (lists the links from the current item)
  i    - index (lists all items by their indexes)
         ( 'i <pattern>' - lists indexes matching <pattern> )
  p    - previous items (lists the indexes of previous items you have seen)
         ( 'p 1' - goes to the last item you saw )

  r (index)      - read item (index)
  (index)        - does the same as 'r (index)'
EndText
    );
}

void create()
{
    ::create();
    set( "attached", 1 );
    set( "start", "guide" );
    set( "short", 0 ); // invisible
    set( "long", "" );
    set( "default", "home" );
    extra_create();
}

varargs int option_q( string arg )
{
    call_out( "remove", 0 );
    this_player()-> set( "guide_index", index );
    return ::option_q( arg );
}

/* EOF */
