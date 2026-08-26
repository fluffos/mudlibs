/*
// File:       memopad.c
// Purpose:    An object to store memorandi in.  An example of hypertext.
// 93-07-25    Written by Douglas Reay (Pallando @ TMI-2)
// 93-09-19    move() added by Pallando on request from Mobydick
*/
#include <move.h>

inherit "/std/hypertext";

string datafile()
{
    return user_path( geteuid( this_object() ) ) + ".memo";
}

void memo_pad_set_up()
{
    data["start"] = ([
        "author" : "Pallando",
        "time"   : 745550000,
        "links"  : ([ "hypertext" : "help.hypertext",
                      "memopad"   : "help.memopad"    ]),
        "type"   : "text",
        "data"   : @EndText
HOME PAGE                     (start)                       HOME PAGE

Welcome to Pallando's hypertext memo pad.

You will always start at this item on entering the memo pad, however
you may use the "e" option to customise it.  For help on the options
just type "h".  For help on {hypertext} or the {memopad} just type
"hypertext" or "memopad".  The curly brackets around the words on
the above line indicate that there are links from this item to other
items which you can go to by typing the bracketed word.

EndText
    ]);
    data["help.hypertext"] = ([
        "author" : "Pallando",
        "time"   : 745550000,
        "links"  : ([ "memopad" : "help.memopad" ]),
        "sknil"  : ([ "help.memopad" : "hypertext",
                      "start"        : "hypertext"  ]),
        "type"   : "text",
        "data"   : @EndText
HELP PAGE                  (help.hypertext)                 HELP PAGE

Hypertext is a way of organising text in a non-linear way. 

This means that instead of a book being divided into items that
are arranged one after another in a fixed order, the items can
chose several other items that are of linked subjects any of
which the user can then chose to go to.

It is up to you how structured to make your links, but done properly
hypertext is a powerful tool for thought organisation and lateral thinking.

See also: {memopad}
EndText
    ]);
    data["help.memopad"] = ([
        "author" : "Pallando",
        "time"   : 745550000,
        "links"  : ([ "hypertext" : "help.hypertext",
                      "man"       : "man.save_object" ]),
        "sknil"  : ([ "help.hypertext" : "memopad",
                      "start"          : "memopad", ]),
        "type"   : "text",
        "data"   : @EndText
HELP PAGE                   (help.memopad)                  HELP PAGE

This object is an example of {hypertext}.  It may eventually become a
full filofax, with a diary linked to the event daemon, but in the
mean time, you can use it for storing miscelaneous text that you 
want to cross reference, such as memorandi.

For example, if you had several bugs you wished to remind yourself
to fix, you could give each bug an item, cross reference the ones
with similarities and link in the relevant {man} pages.

EndText
    ]);
    data["man.save_object"] = ([
        "author" : "Pallando",
        "time"   : 745550000,
        "sknil"  : ([ "help.memopad" : "man" ]),
        "type"   : "file",
        "data"   : "/doc/functions/efuns/save_object.3",
    ]);
}

void create()
{
    if( !directory_exists( user_path( geteuid( this_player() ) ) ) )
    {
        write( "Sorry, you need a user directory.\n" );
        destruct( this_object() );
        return;
    }
    seteuid( geteuid( previous_object() ) );
    ::create();
    if( !data["start"] || ( data["start"]["time"] < 745550000 ) )
        memo_pad_set_up();
    set( "id", ({ "memopad", "memo", "memo pad", "pad" }) );
    set( "name", "memopad" );
    set( "start", "memo" );
    set( "short", this_player()-> query( "cap_name" ) + "'s memo pad" );
    set( "long", @EndText
A large loose-leaf book, bound in soft red leather.
Type "memo" to use.
EndText
    );
}

mixed query_auto_load() { return 1; }

int move( mixed dest )
{
    if( environment( this_object() ) ) return MOVE_NOT_ALLOWED;
    if( stringp( dest ) ) dest = find_object_or_load( dest );
    if( !objectp( dest ) ) return MOVE_NOT_ALLOWED;
    if( !wizardp( dest ) ) return MOVE_NOT_ALLOWED;
    if( present( "memopad", dest ) )
    {
        write( "\nYou already have a memopad.\n" );
        destruct( this_object() );
        return MOVE_NOT_ALLOWED;
    }
    return ::move( dest );
}
