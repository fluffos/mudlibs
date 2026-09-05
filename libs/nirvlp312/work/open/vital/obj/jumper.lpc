/******************************************************************************
 *  File:           jumper.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2003 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:			11/7/03
 *  Notes:			Used to add/remove an action to a room
 *  Change History: 
 *****************************************************************************/

#include "/players/vital/closed/headers/vital.h"

inherit "/players/vital/closed/std/obj";

string *ids;

reset(arg) {
    if(arg) return;
    set_name("");
    set_alias("jumper");
    set_alt_name("");
    set_id( ({
        name, alias, alt_name, 
    }) );
    set_short("");
    set_long("");
}

void set_id(string *new_ids) { 
    ids = new_ids;
}

init()
{
    ::init();
    add_action("jump_one","jump");
}

jump_one()
{
    environment()->jump_exit();
    return 1;
}
