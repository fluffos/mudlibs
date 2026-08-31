#include <std.h>
#include <sakura.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("prisoner");
    set_short("A prisoner, tied to the chair");
    set_id(({"prisoner"}));
    set_level(1);
    set_race("Human");
    set_body_type("human");
    set_gender("male");
    set_long("This male human is tied to the heavy oaken chair on the far east side of the room, with a wooden gag placed in his mouth. He is covered in blood from several locations and looks extremely frightened. You could probably %^BOLD%^%^CYAN%^rescue%^RESET%^ him if it was clear.");
    set_die( (: call_other, this_object(), "death_func":) );

    this_object()->set_hp(this_object()->query_max_hp() / 2);

}

int death_func() {

    message("say", "The bound human is no match for you and you defeat him easily.", environment(this_object()));
    return 1;
}
