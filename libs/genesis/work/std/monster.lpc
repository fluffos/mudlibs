/* 
   /std/monster.c

   This is the standard humanoid monster object. This object is intended
   to be used either by cloning or inheriting.

   This is more or less still here for compatibility reasons.

*/
#pragma save_binary
#pragma strict_types

#include "/sys/formulas.h"
#include "/sys/stdproperties.h"

inherit "/std/npc";
inherit "/std/combat/humunarmed";

inherit "/std/act/domove";
inherit "/std/act/chat";
inherit "/std/act/action";
inherit "/std/act/ranpick";
inherit "/std/act/attack";
inherit "/std/act/add_things";
inherit "/std/act/asking";

/*
 * Function name: create_monster
 * Description:   Create the monster. (standard)
 */
void
create_monster()
{
    ::create_npc();
    set_name("monster");
}

/*
 * Function name: create_npc
 * Description:   Create the inherited npc object. (constructor)
 */
nomask void
create_npc() { create_monster(); }

/*
 * Function name: reset_monster
 * Description:   Reset the monster. (standard)
 */
void
reset_monster() { ::reset_npc(); }

/*
 * Function name: reset_npc
 * Description:   Reset the inherited npc object.
 */
nomask void
reset_npc() { reset_monster(); }

/*
 * Description:  Use the humanoid combat file
 */
public string
query_combat_file() 
{
    return "/std/combat/chumanoid"; 
}

/*
 * Function name: query_humanoid
 * Description  : Since this is a humanoid, we mask this function so
 *                that it returns 1.
 * Returns      : int - 1;
 */
public int
query_humanoid()
{
    return 1;
}
