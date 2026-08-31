#include <std.h>
inherit MONSTER;

create() {
         ::create();
         set_name("wooly mammoth");
         set_id(({ "mammoth", "wooly mammoth" }));
         set_short("giant wooly mammoth");
         set_long("This enormous beast is like an extra large elephant. "
                 "It is covered in a %^ORANGE%^brown fur%^RESET%^ that "
                 "appears very bristly. It bears two enormous, ivory tusks.");
         set_race("wooly mammoth");
         set_body_type("elephant");
         set_gender("male");
         set("aggressive", 74);
         set_level(100);
	 set_emotes(1,({ "The mammoth lifts it's enormous trunk and belts"
		" out a wail."}),0);
    new("/wizards/smoke/mountain/items/other/tusk")->move(this_object());
    new("/wizards/smoke/mountain/items/other/tusk")->move(this_object());
}
