/* This is a magic lighter, that lights up the room. It's cloned by the
 * light spell, and should never be seen by players.
 */

inherit "/std/object";
#include <stdproperties.h>

void
create_object()
{
    set_name("lighter");
    set_adj("magic");
    set_no_show();
    add_prop(OBJ_I_LIGHT, 1);
    add_prop(OBJ_I_NO_GET, 1);
    add_prop(OBJ_S_WIZINFO, "A magical light arrived here by a spell. Will " +
        "out before to long\n");
    add_prop(MAGIC_AM_MAGIC, ({ 20, "conjured" }) );
}

void set_duration(int dur) { call_out("remove_object", dur); }

void
enter_env(object dest, object old)
{
    if (dest && dest->query_prop(ROOM_I_IS))
        tell_room(dest, "Suddenly it gets a little brighter.\n");
}

void
leave_env(object old, object dest)
{
    if (old && old->query_prop(ROOM_I_IS))
        tell_room(old, "The shadows seem to creep closer.\n");
}

int
dispel_magic(int magic)
{
    if (magic > 20)
    {
        call_out("remove_object", 1);
        return 1;
    }
    return 0;
}

