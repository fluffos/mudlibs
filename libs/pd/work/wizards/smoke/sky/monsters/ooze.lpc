#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("puddle of ooze");
         set_id(({ "ooze", "puddle", "puddle of ooze"}));
         set_short("%^GREEN%^puddle of ooze");
         set_long("%^BOLD%^%^GREEN%^This is a nasty puddle of "
                 "green ooze. It sits in the middle of the room "
                 "and growls.");
         set_race("puddle");
         set_class("fighter");
         set_subclass("warrior");
add_limb("center", "edge", 1500, 0 ,
50);
add_limb("edge", "center", 1500, 0 ,
50);
         set("aggressive", 75);
         set_gender("neuter");
         set_level(80);
}
