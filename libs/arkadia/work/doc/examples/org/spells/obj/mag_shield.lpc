/* This is a magic shield, protecting the wearer from blows.
 */

inherit "/std/armour";
#include <stdproperties.h>
#include <wa_types.h>
#include <macros.h>

void
create_armour()
{
    set_name("forcefield");
    add_name("mag_shield_prot");
    set_adj("magic");
    set_long("A magical forcefield covering your whole body.\n");
    add_prop(OBJ_I_NO_DROP, 1);
    add_prop(OBJ_I_IS_MAGIC_ARMOUR, 1);
    add_prop(OBJ_S_WIZINFO, "A magical shield to protect the wearer. Will " +
        "out before to long\n");
    add_prop(MAGIC_AM_MAGIC, ({ 20, "abjured" }) );
    add_prop(MAGIC_AM_ID_INFO, ({
	"The forcefield will protect your entire body.\n", 0}) );

    set_default_armour(6, A_MAGIC);
}

void set_duration(int dur) { call_out("remove_object", dur); }

int
remove_me()
{
    if (!worn || !wearer)
        return 0;
    worn = 0;

    wearer->remove_arm(this_object());
    tell_object(wearer, "The magic forcefield is gone, you feel " +
        "unprotected.\n");
    remove_call_out("remove_object");
    remove_object();
    return 1;
}

void
enter_env(object dest, object old)
{
    wearer = dest;
    worn = 1;
    tell_object(dest, "You become surrounded by a forcefield, you feel " +
        "protected.\n");
    tell_room(environment(dest), "Suddenly " + QTNAME(dest)  + " is " +
        "surrounded by a forcefield.\n", dest);
    wearer->wear_arm(this_object());
}

void
leave_env(object old, object dest)
{
    remove_me();
}

int *
query_shield_slots()
{
    return ({ A_HEAD, A_BODY, A_L_ARM, A_R_ARM, A_LEGS});
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


