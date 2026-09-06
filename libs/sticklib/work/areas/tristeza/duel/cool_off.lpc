#include <room.h>

#include <areas.h>

void
create_room() {

    set_outdoors(WD_INDOORS);
    set_light(1);

    set_short("The Cooling-Off Room");
    set_long("Aaaah, the duel is now over and you can cool off a bit. "+
      "There are no enemies around here so it's no point "+
      "trying to waste someone here. This is your own cooling "+
      "room. You can 'leave' when you want.");

    set(PREVENT_TELEPORT);
}

void
init_room() {

    //Let's kill suffering player, he'll be saved. (object died function)
    if(this_player()->query_hp() < 0) {
	write("The Demons of the Pit scream...DIE!!!\n");
	this_player()->hit_player(1000);
    }
    this_player()->set_attacker(0);
    this_player()->set_alt_attacker(0);
    this_player()->set_hunted(0);
    add_action("leave", "leave");

}

status
leave() {

    object *obs;
    int i;

    this_player()->move_player("X",
      AREA_TRISTEZA "duel/duel_off");
    obs = all_inventory(this_object());
    i = sizeof(obs);
    while(i--) {
	move_object(obs[i], AREA_TRISTEZA "duel/duel_off");
    }
    destruct(this_object());
    return 1;
}

nomask status
object_died(object ob, object killer) {

    tell_object(ob, "A white nurse saves you at the last second.\n");
    tell_object(ob, "The nurse says: There ya go. And leaves.\n");

    if(ob->query_hp() < 0) ob->add_hp(-ob->query_hp()+10);
    return 1;
}

