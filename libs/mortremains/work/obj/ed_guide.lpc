/*
// File     :  ed_guide.c
// Purpose  :  Object to edit the guide
// 93-09-17 :  Written by Douglas Reay (Pallando @ TMI-2)
*/
#include <guide.h>

inherit GUIDE_OB;

varargs int valid_write( string arg )
{
    return 1;
}

void extra_create()
{
    set( "id", ({ "master_guide" }) );
    set( "name", "master_guide" );
}

void create()
{
    if( file_name( previous_object() ) != CMD_ED_GUIDE )
    {
        destruct( this_object() );
        return;
    }
    ::create();
}
