#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven child");
         set_id(({ "dwarf", "child", "dwarven child" }));
         set_short("dwarven child");
         set_long("This young dwarf wants to play. She's looking "
                 "for more children to hang out with.");
         set_race("dwarf");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("dwarf");
         set("aggressive", 70);
         set_gender("female");
         set_level(68);
set_emotes(10, ({"%^CYAN%^The child asks:%^RESET%^ Where are you going?",
	"%^CYAN%^The child asks:%^RESET%^ Will you play with me?",
	"%^CYAN%^The child asks:%^RESET%^ Why do you smell so bad?",
        "%^CYAN%^The child exclaims:%^RESET%^ I'm bored!"}), 0);
}
