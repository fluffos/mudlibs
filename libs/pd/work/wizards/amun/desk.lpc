#include <std.h>
#include <amun.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("Desk");
    set_short("%^RESET%^%^ORANGE%^A Desk%^RESET%^");
    set_long("This is Amun's desk. It has been custom built to her specifications.");        set_id(({"desk"}));
    set_prevent_get("Not only is it fixed to the floor,  it's twice your size and you would get your ass wooped for taking it.");
}
void init() {
    ::init();
    add_action("cmd_banish", "banish");
    add_action("cmd_release", "release");
}
int cmd_banish(string str) {
    object ob;   
    if(this_player()->query_name() != "amun"){
	return 0;
    }
    if (!str) {
	write("Banish whom?");
	return 1;
    }
    ob = find_living(str);
    if (!ob){
	write("No such player");
	return 1;
    }
    if(!present(ob)){
	write("Person must be present");
	return 1;
    }
    ob->move_player("/d/nopk/tirun/square");
    message("info", ""+ob->query_cap_name()+" plummets to "+ob->query_possessive()+" doom.", environment(this_player()), (this_player(), ob));
    return 1; 
}       
int cmd_release(string str) {
    object ob, room;   
    if (!str) {
	write("Release whom?");
	return 1;
    }
    ob = find_living(str);
    room = find_object("/d/nopk/tirun/square");
    if (!ob){
	write("No such player");
	return 1;
    }
    if(!present(ob, room)){
	write("Person must be imprisoned");
	return 1;
    }
    ob->move_player("/wizards/amun/workroom");
    return 1;
} 
