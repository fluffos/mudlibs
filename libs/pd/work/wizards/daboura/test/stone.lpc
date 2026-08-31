#include <std.h>
#include <daboura.h>

inherit NEWSTONE;

void create()
{
    ::create();
    set_name("magic stone");
    set_short("a magical stone");
    set_long("The stone is a really smooth and shiny stone that emits a "
      "green light. There is a small message engraved on the back "
      "of the stone that reads: <rub stone> "
      "to release the magical powers of this stone.");
    set_id( ({ "stone", "magic stone" }) );
    set_action("rub");
    set_remove_mess("The magical stone turns into dust and blows away.");
    set_levels(({"barely glowing", "glowing dimly", "glowing", "glowing lightly", "glowing brightly" }));
    set_use_mess("You rub the stone and feel the rush of mana enter your body.");
    set_mass(1);
    set_value(0);
}
