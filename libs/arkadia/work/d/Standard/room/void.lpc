/*
  /room/void.c

  This object should always load and work.
  We must inherit /std/object to be allowed to enter it.

*/

#pragma no_inherit
#pragma save_binary
#pragma strict_types

inherit "/std/room";

#include <macros.h>
#include <stdproperties.h>
#include <std.h>

void
create_room()
{
    set_short("Pustka");
    set_long("Znalazles sie w Pustce. Nie ma dla ciebie zadnej nadziei. "
           + "Chcialoby sie krzyknac: Czarodzieje, na pomoc !\n");

    add_prop(ROOM_I_TYPE, ROOM_IN_AIR);
}

void
enter_inv(object ob, object from)
{
    ::enter_inv(ob, from);

    if (interactive(ob))
        set_alarm(0.1, 0.0, "kick_out", ob,
                  SECURITY->wiz_home(ob->query_real_name()));
}

void
kick_out(object tp, object room)
{
    if (environment(tp) != this_object())
        return;

    tp->catch_msg("Zostajesz wyrzucon" + tp->koncowka("y", "a", "e") + " z "
                + "Pustki do miejsca zwanego: " + room->short() + ".\n");

    if (tp->move_living("X",room))
        tp->move_living("X",DEFAULT_START);
}