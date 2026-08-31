#include <std.h>

inherit OINTMENT;

void create()
{
    ::create();
    set_property("no store", 1);
    set_name("ointment");
    set_short("A vial of ointment");
    set_long("This is a clearish pink vial of ointment. You can <apply "
      "ointment (limb)> and it will heal your specific wounds or <apply "
      "ointment all> to do a general healing of all body damage.");
    set_id( ({ "ointment", "vial" }) );
    set_mass(2);
    set_value(10);
    // $L is replaced with the specific limb.
    set_your_mess_limb("You feel the ointment healing your $L.");
    set_your_mess_all("You feel the ointment healing you.");
    // $O - objective (him, her), $S - subjective (he, she),
    // $P - possessive (his, her), $N - capitalized name of user.
    set_their_mess_limb("$N applies ointment to $P $L.");
    set_their_mess_all("$N rubs ointment upon $P body.");
    // Set the command used to use it.
    // Use $I if one of the ID's must be mentioned.
    set_action("apply $I");
    /*
      Example without the $I:
	set_action("salve");
	This would work if the player used "salve all" or "salve left leg"
      Another example with the $I:
	set_action("squirt $I on");
	This would work for "squirt lotion on left leg" or "squirt lotion on
	all", assuming, of course, that "lotion" is one of the ID's
      More than one $I won't work. Also, this will only work for one word ID's.
      The ID that you want used in the command should be the first one in
      set_id(), as that is the one that will (well, should) be used in "Correct
      syntax:" error messages.
    */
}
