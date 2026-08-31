/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Tsath, 2020
*/

inherit ADVERSARY;
inherit M_GUILD_MEMBER;
inherit M_ASSISTANCE;
inherit M_ASSISTANCE;

void setup()
{
   string length = choice(({"long", "short", "very long", "very short"}));
   string color = choice(({"black", "dark brown", "white", "grey", "brown"}));

   set_name("Yakitory Delivery boy");
   set_in_room_desc("A delivery boy in a Yakitori uniform with " + length + " " + color + " hair.");
   add_id("boy", "delivery boy", "yakitori delivery boy", "yakitory_member");
   set_gender(1);
   set_special_chance(20); // 20% chance to fire off specials per swing
   set_level(10);
   set_long("A young mang with " + length + " " + color + " hair in a white and red Yakitori " +
            "uniform, although a bit smudged. He's got an intense stare and a " + "combat ready stance.");
   set_which_guild("yakitori");
   set_wearing("../armor/uniform");
   add_helper("yakitory_member");
   set_objects((["^nuke/consumable/sake":1]));
}

void under_attack_by(object who)
{
   targetted_action("$N $vpoint to $t, \"Get him!\"", who);
   get_help();
}
