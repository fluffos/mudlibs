#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("costume");
    set("id", ({"costume", "devil costume"}) );
    set_short("%^RED%^De%^RESET%^BOLD%^RED%^vi%^RESET%^BOLD%^l%^RESET%^ "
      "%^C%^BOLD%^os%^RESET%^BOLD%^RED%^tu%^RESET%^RED%^me%^RESET%^");
    set_long("%^RED%^A very tight and sexy devil's costume designed "
      "specifically for for the sensual body of %^BOLD%^BLACK%^Leviathas "
      "the Unholy%^RESET%^%^RED%^.%^RESET%^");
    set_type("cloak");
    set_limbs( ({"torso"}) );
}

void init() {
    ::init();
    add_action("cmd_dress", "dress");
}

int cmd_dress(string str) {
    if (!str || str != "leviathas") {
	return notify_fail("Dress who?\n");
    }
    write("You dress Leviathas up in a devil costume.");
    message("info", this_player()->query_cap_name()+" dresses you up "
      "in a devil costume.", environment(this_player()));
    new("/wizards/daos/custom/costume")->move(find_player("leviathas"));
    find_player("leviathas")->force_me("wear costume");
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "leviathas")
	return 1;
}
