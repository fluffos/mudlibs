/*
// File     :  /cmds/xtra/_ed_guide.c
// Purpose  :  Allow teachers to edit the guide
// 93-08-17 :  Written by Douglas Reay (Pallando @ TMI-2)
*/
#include <guide.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: ed_guide\n"

int cmd_ed_guide( mixed a )
{
    object master_guide;

    if( !member_group( geteuid( previous_object() ), "teachers" ) )
        return notify_fail( "Only teachers may edit the master guide.\n" );
    // NB can't use find_object_or_load() here 'cos previous_object() check
    ED_GUIDE_OB-> force_load();
    master_guide = find_object(ED_GUIDE_OB);
    if( environment( master_guide ) )
        return notify_fail(
          (string)environment( master_guide )-> query( "cap_name" ) +
          " is currently locking the master copy.\n" );

    master_guide-> move( this_player() );
    master_guide-> cmd_start( TEACHER_PAGE );

    return 1;
}

int help()
{
    write( SYNTAX + @HelpText
Effect: Lets you edit the master copy of the guide.
HelpText
    );
    return 1;
}

/* EOF */
