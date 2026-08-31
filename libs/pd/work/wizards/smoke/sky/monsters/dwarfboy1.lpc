#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven child");
         set_id(({ "dwarf", "child", "dwarven child" }));
         set_short("dwarven child");
         set_long("This young dwarf wants to play. He's looking "
                 "for more children to hang out with.");
         set_race("dwarf");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("dwarf");
         set("aggressive", 70);
         set_gender("male");
         set_level(69);
set_emotes(10, ({"%^CYAN%^The child asks:%^RESET%^ What's that?",
	"%^CYAN%^The child asks:%^RESET%^ ..why?",
	"%^CYAN%^The child asks:%^RESET%^ What's your name?",
        "%^CYAN%^The child asks:%^RESET%^ What did you say?"}), 0);
}
