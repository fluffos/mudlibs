/*
// File:       hypertext.c
// Purpose:    a generic hypertext information storage device
// 93-07-25    Written by Douglas Reay (Pallando @ TMI-2)
//             The name "hypertext" is used in the sense of non-linear text,
//             a usage originating with Ted Nelson c1965.
//             See /obj/tools/memopad.c for an example of use.
// 93-08-28    Default option added by Pallando on idea by Grendel
// 93-09-17    Pallando changed option r to use more()
// 93-09-18    Pallando added version control and settable name of default item
// 93-09-19    Pallando made adding new item types easier
*/
#define HYPERTEXT_VERSION 930919

#include <uid.h>
#include <config.h>
#include <mudlib.h>

#define TEMP_FILE temp_file( query( "name" ) )

inherit OBJECT;

mapping data;
mapping options;
int hypertext_version;
nosave string index;
nosave string *history;

varargs int get_option( string option );

// Security.
int query_prevent_shadow() { return 1; }

// The previous object (the user) may read item <index>
varargs int valid_read( string arg )
{
    return 1;
}

// The previous object (the user) may alter item <index>
varargs int valid_write( string arg )
{
    return ( geteuid( this_object() ) != ROOT_UID ) &&
           ( geteuid( this_object() ) != "NONAME" );
}

// The file a particular user's copy of this object should save to.
string datafile()
{
    if( !previous_object() ) return TMP_DIR + query( "name" ) + "_noname";
    return TMP_DIR + query( "name" ) + "_" + geteuid( previous_object() );
}

int do_save()
{
    if( !valid_write() ) return 0;
    save_object( datafile() );
    return 1;
}

int remove()
{
    do_save();
    return ::remove();
}

void write_prompt()
{
    printf( "(%s) [%s] ", index, implode( keys( options ), "," ) );
}

void increment_history()
{
    if( query( "history" ) && ( index != history[0] ) )
        history = ( ({ index }) + history )[0..( query( "history" ) )];
}

// **************** START OF OPTIONS ******************* //

// Option: delete
// Effect: deletes item (arg)
varargs int option_d( string arg )
{
    // "sknil", you may notice, is "links" spelt backwards.
    mapping item, sknil, links;
    string *indexes, *names;
    int loop;

    if( !arg ) arg = index;
    if( arg == query( "home" ) )
    {
        write( "You may not delete the home item.\n" );
        return get_option();
    }
    if( !valid_write( arg ) )
    {
        write( "You may not alter item (" + arg + ")\n" );
        return get_option();
    }
    if( !mapp( item = data[arg] ) )
    {
        write( "There is no item (" + arg + ")\n" );
        return get_option();
    }
    if( arg == index ) index = query( "home" );
    increment_history();
    // Delete all links from this item.
    if( mapp( links = item["links"] ) &&
      ( loop = sizeof( names = keys( links ) ) ) )
        while( loop-- )
            if( mapp( data[links[names[loop]]] ) &&
              mapp( data[links[names[loop]]]["sknil"] ) )
                map_delete( data[links[names[loop]]]["sknil"], arg );
    // If other items have links to this item (the one to be deleted) then
    // delete this item from their links.
    if( mapp( sknil = item["sknil"] ) &&
      ( loop = sizeof( indexes = keys( sknil ) ) ) )
        while( loop-- )
            if( mapp( data[indexes[loop]] ) && 
              mapp( data[indexes[loop]]["links"] ) )
                map_delete( data[indexes[loop]]["links"],
                  sknil[indexes[loop]] );
    map_delete( data, arg );
    do_save();
    write( "Ok.\n" );
    return get_option();
}

// Option: edit
// Effect: create or alter an item
varargs int option_e( string arg )
{
    string filename, tmp;

    if( arg && ( sscanf( arg, "%s %s", tmp, filename ) == 2 ) )
    {
        if( !valid_write( tmp ) ) return get_option();
        filename = resolv_path( "cwd", filename );
        if( !file_exists( filename ) )
        {
            write( "There is no file called " + filename + "\n" );
            return get_option();
        }
        index = tmp;
        increment_history();
        if( !mapp( data[index] ) ) data[index] = ([ ]);
        data[index]["type"] = "file";
        data[index]["data"] = filename;
        data[index]["author"] = capitalize( geteuid( this_player() ) );
        data[index]["time"] = time();
        do_save();
        write( "Ok, item (" + index + ") is " + filename + "\n" );
        return get_option();
    }
    if( arg ) index = arg;
    if( !valid_write( index ) ) return get_option();
    increment_history();
    write( "Edit item (" + index + ")\n" );
    if( mapp( data[index] ) && 
        stringp( data[index]["data"] ) &&
        ( data[index]["type"] == "text" ) )
        write_file( TEMP_FILE, data[index]["data"] );
    this_player()-> edit( TEMP_FILE, "finish", this_object() );
    return 1;
}

// called by option_e if the body's edit() function is finished normally
void finish()
{
    mapping item;
    string text;

    text = read_file( TEMP_FILE );
    rm( TEMP_FILE );

    if( text )
    {
        if( !mapp( data[index] ) ) data[index] = ([ ]);
        data[index]["author"] = capitalize( geteuid( this_player() ) );
        data[index]["time"] = time();
        data[index]["data"] = text;
        data[index]["type"] = "text";
        write( "(" + index + ") changes saved.\n" );
    } else {
        write( "Changes not saved.  Use \"d\" if wish to delete item.\n" );
    }
    do_save();
    get_option();
}

// called by option_e if the body's edit() function is aborted
void abort()
{
    rm( TEMP_FILE );
    write( "Ok, edit abandoned.\n" );
    get_option();
}

// Option: help
// Effect: provides help on the hyper object and its functions.
varargs int option_h( string arg )
{
    if( arg )
    {
        if( query( "help/" + arg ) )
            write( query( "help/" + arg ) );
        else
            write( wrap( "Help is available on: " +
                implode( keys( query( "help" ) ), " " ) ) );
    } else {
        write( query( "help/options" ) );
    }
    return get_option();
}

// Option: index
// Effect: lists the indexes of all known items.
varargs int option_i( string arg )
{
    string *indexes;

    indexes = keys( data );
    if( arg )
    {
        indexes = regexp( indexes, arg );
        if( !sizeof( indexes ) )
        {
            write( "There are no indices matching the pattern " + arg + "\n" );
            return get_option();
        }
    }
    write( wrap( implode( indexes, "   " ) ) );
    return get_option();
}

// Option: unlink
// Effect: tries to remove a link {arg} from item (index)
//         If arg2 is passed (as when called by option_l) it is silent
varargs int option_u( string arg, int arg2 )
{
    mapping item, links;
    string indx;

    if( !arg )
    {
        write( "Syntax: u {name}\nEffect: unlinks the link {name}\n" );
        return get_option();
    }
    if( !mapp( item = data[index] ) || !mapp( links = item["links"] ) )
    {
        write( "(" + index + ") has no links.\n" );
        return get_option();
    }
    if( !( indx = links[arg] ) )
    {
        printf( "(%s) does not have a link {%s}\n", index, arg );
        return get_option();
    }
   if( mapp( data[indx] ) && mapp( data[indx]["sknil"] ) )
        map_delete( data[indx]["sknil"], index );
    map_delete( data[index]["links"], arg );
    if( arg2 ) return 1;
    printf( "Link {%s} to Item (%s) removed.\n", arg, indx );
    do_save();
    return get_option();
}

// Option: link
// Effect: makes a link from item <index>
varargs int option_l( string arg )
{
    int loop;
    mapping item, links;
    string indx, name, *names;

    if( arg )
    {
        if( !valid_write( index ) ) return get_option();
        if( sscanf( arg, "%s %s", name, indx ) != 2 )
        {
            write( "Syntax: l {name} (index)\n" );
            return get_option();
        }
        if( !mapp( data[indx] ) )
        {
            write( "You need to create item (" + indx + ") first.\n" );
            return get_option();
        }
        if( !mapp( data[index] ) ) data[index] = ([ ]);
        if( mapp( data[index]["links"] ) )
        {
            if( data[index]["links"][name] )
                option_u( name );
            data[index]["links"][name] = indx;
        } else {
            data[index]["links"] = ([ name : indx ]);
        }
        if( mapp( data[indx]["sknil"] ) )
            data[indx]["sknil"][index] = name;
        else
            data[indx]["sknil"] = ([ index : name]);
        write( "Ok.\n" );
        do_save();
        return get_option();
    }
    if( !mapp( item = data[index] ) || !mapp( links = item["links"] ) ||
      !( loop = sizeof( names = keys( links ) ) ) )
    {
        write( "Item " + index + " is not linked to any other items.\n" );
        return get_option();
    }
    write( "Item (" + index + ") has the links:\n" );
    printf( "%-15s\t%s\n", "{name}", "(index)" );
    while( loop-- ) printf( "%-15s\t%s\n", names[loop], links[names[loop]] );
    return get_option();
}

// Option: read
// Effect: displays item (arg)
varargs int option_r( string arg )
{
    string indx;
    mapping item;
    mixed more_data;

    if( !arg ) arg = index;
    item = data[arg];
    if( undefinedp( item ) )
    {
        write( "There is no item (" + arg + ")\n" );
        return get_option();
    }
    if( !valid_read( arg ) )
    {
        write( "Yoy may not read (" + arg + ")\n" );
        return get_option();
    }
    switch( item["type"] )
    {
        case "file":
        {
            write( "(" + arg + ") " + item["data"] + "\n" );
            more_data = item["data"];
            break;
        }
        case "text":
        {
            write( "(" + arg + ") by " + item["author"] +
                " at " + ctime( item["time"] ) + "\n" );
            more_data = explode( item["data"], "\n" );
            break;
        }
        default:
        {
            if( !stringp( item["type"] ) )
                write( "Error in item: no type.\n" );
            else
            if( !call_other( this_object(), "read_" + item["type"], arg ) )
                write( "Unknown data type: " + item["type"] + "\n" );
            return get_option();
        }
    }
    indx = index;
    index = arg;
    if( (int)this_player()-> more( more_data ) )
    {
        return 1;
    } else {
        index = indx;
        this_object()-> done_more();
        return 0;
    }
}

void done_more()
{
    mapping item, links;
    string *names;

    item = data[index];
    if( query( "show_links" ) && mapp( links = item["links"] ) &&
      sizeof( names = keys( links ) ) )
    {
        write( wrap( "Links: " + implode( names, "," ) ) );
    }
    increment_history();
    get_option();
}

// Option: previous
// Effect: lists previous items visited (ie a history function)
//         if integer <arg> is specified, if goes back to that item
varargs int option_p( string arg )
{
    int loop;

    if( arg )
    {
        if( sscanf( arg, "%d", loop ) )
        {
            if( ( loop < sizeof( history ) ) && history[loop] )
                return option_r( history[loop] );
            else
                write( "Your history doesn't go back that far.\n" );
        } else write( arg + " is not a number.\n" );
    } else write( "Item index history:\n" );
    for( loop = 0 ; history[loop] ; loop++ )
        printf( "%3d  %s\n", loop, history[loop] );
    return get_option();
}

// Option: quit
// Effect: only option not to do a return get_option()
varargs int option_q( string arg )
{
    write( "Ok.\n" );
    return 1;
}

// ****************** END OF OPTIONS ********************** //

varargs int get_option( string option )
{
    string tmp, arg;

    if( option == "" )
    {
        if( mapp( data[index] ) && mapp( data[index]["links"] ) &&
          stringp( data[index]["links"]["default"] ) )
        {
            if( data[index]["links"]["default"] != index )
                return option_r( data[index]["links"]["default"] );
        } else if( ( index != query( "default" ) ) &&
          mapp( data[query( "default" )] )     )
            return option_r( query( "default" ) );
    }
    if( !option || option == "" )
    {
        write_prompt();
        input_to( "get_option" );
        return 1;
    }

    if( sscanf( option, "%s %s", tmp, arg ) ) option = tmp;
    if( options[option] )
        return (int)call_other( this_object(), options[option], arg );
    if( arg )
    {
        write( "You may not specify \"" + option + "\" with an argument.\n" );
        return get_option();
    }
    if( mapp( data[index] ) && mapp( data[index]["links"] ) &&
      data[index]["links"][option] )
        return option_r( data[index]["links"][option] );
    return option_r( option );
}
        
int cmd_start( string arg )
{
    if( stringp( arg ) && data[arg] )
        return option_r( arg );
    return option_r( query( "home" ) );
}

void init()
{
    add_action( "cmd_start", query( "start" ) );
}

void set_up()
{
    options = ([
        "d" : "option_d",
        "e" : "option_e",
        "h" : "option_h",
        "i" : "option_i",
        "l" : "option_l",
        "p" : "option_p",
        "q" : "option_q",
        "r" : "option_r",
        "u" : "option_u",
    ]);
    set( "help/options", @EndText
HELP PAGE                                                   HELP PAGE
              Help on interactive hypertext options
This object contains a collection of text items, either as variables
in the object or as references to files in the mudlib.
Each item has an index - shown in () - a string with no spaces
such as "longsword", "12.4", "item1", "driver/bugs" or whatever
naming scheme you chose.
Items may have links - shown in {} - to other items.
Option:
EndText
+ @EndText
 l         - list the links from the current item.
 l {name} (index) - links the current item to item (index)
             typing "{name}" at the prompt will take you to the linked item.
 (index)   - displays item (index).
 r (index) - displays item (index).  Typing "r" will display the current item.
 e (index) - edit item (index).  Typing "e" will edit the current item.
 e (index) <filename> - set item (index) to refer to the file <filename>
 h         - help (this message)
 q         - quit
 i <pattern> - show all items who indexes match <pattern>
 p         - a history command.  display the indexes of your previous items.
 p <n>     - go to the <n>'th item in the history list.
 d (index) - deletes item (index)
 u {name}  - deletes the link {name}
EndText
    );
    set( "id", ({ "hypertext", "hypereader" }) );
    set( "name", "hypereader" );
    set( "home", "start" );
    set( "start", "hyper" );
    set( "default", "default" );
    set( "history", 20 );
    hypertext_version = HYPERTEXT_VERSION;
}

void check_version()
{
    string *indexes;
    int loop;

    if( hypertext_version == HYPERTEXT_VERSION ) return;
    if( stringp( hypertext_version ) )
        sscanf( hypertext_version, "%d", hypertext_version );
    if( hypertext_version < 930918 )
    {
        set( "default", "default" );
    }
    if( hypertext_version < 930919 )
    {
        loop = sizeof( indexes = keys( data ) );
        while( loop-- )
        {
            if( undefinedp( data[indexes[loop]]["filename"] ) )
            {
                data[indexes[loop]]["type"] = "text";
                data[indexes[loop]]["data"] = data[indexes[loop]]["text"];
                map_delete( data[indexes[loop]], "text" );
            } else {
                data[indexes[loop]]["type"] = "file";
                data[indexes[loop]]["data"] = data[indexes[loop]]["filename"];
                map_delete( data[indexes[loop]], "filename" );
            }
        }
    }
    hypertext_version = HYPERTEXT_VERSION;
    do_save();
}

// It is up to the inheriting object to ensure that a wizard can't clone this
// if they shouldn't have write access to the datafile
void create()
{
    data = ([ ]);
    set_up();
    if( !geteuid( this_object() ) )
        seteuid( ROOT_UID );
    if( !geteuid( this_object() ) )
        seteuid( getuid() );
    restore_object( datafile() );
    if( query( "history" ) )
        history = allocate( query( "history" ) + 2 );
    check_version();
}
