#include <std.h>

inherit OBJECT;

void create()
{
    ::create();
    set_name("ointment");
    set_short("A vial of ointment");
    set_long("This is a clearish pink vial of ointment. You can <apply "
            "ointment (limb)> and it will heal your specific wounds or <apply "
            "ointment all> to do a general healing of all body damage.");
    set_id( ({ "ointment", "vial" }) );
    set_mass(2);
    set_value(10);
    set_your_mess_limb("You feel the ointment healing your $L.");
    set_your_mess_all("You feel the ointment healing you.");
    set_their_mess_limb("$N applies ointment to $P $L.");
    set_their_mess_all("$N rubs ointment upon $P body.");
    set_action("apply $I");
}

