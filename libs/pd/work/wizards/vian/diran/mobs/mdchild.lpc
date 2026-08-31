#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("child");
    set_short("a mountain dwarf child");
    set_long("This sturdy looking mountain dwarf is a member of the city's children.  He protects the city against the Duergar.");
    set_id(({"child", "dwarf", "mountain dwarf", "mountain dwarf child", "mdchild"}));
    set_level(22);
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
        set_faction("diran");
    set_gender("male"); 
    add_money("gold", random(75));
        new(ARM"mdwcjacket")->move(this_object());
     force_me("wear jacket");
        new(ARM"mdempants")->move(this_object());
     force_me("wear pants");

}


