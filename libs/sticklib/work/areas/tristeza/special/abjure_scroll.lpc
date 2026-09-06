#include <conditions.h>
#include <treasure.h>

#define TP this_player()

void create_treasure() {
    set_name("scroll of abjuration");
    set_short("Scroll of abjuration");
    set_long(
      "This is a crinkled, yellowed scroll with flaring red runes inscribed \
upon it. With this scroll, you can banish summoned creatures by reading it."
    );
    set_id(({ "scroll", "abjuration scroll", "scroll of abjuration" }));
    set_value(800);
    set_weight(1);
}

status read_cmd(string str) {
    string *summoned;
    object *inv;
    int i, j;

    if(!id(str)) return 0;
    if(!present(this_object(), TP))
	return notify_fail("First, you must have the scroll. \n"), 0;

    if(TP->query_condition(C_STUNNED) ||
      TP->query_condition(C_UNCONSCIOUS)) {
	return notify_fail("You can't read it now.\n"), 0;
    }
    summoned = ({
      "/guilds/necromancer/cast/lycanthrope",
      "/guilds/necromancer/cast/undead",
      "/guilds/priests/monsies/angel",
    });

    inv = all_inventory(environment(TP));
    environment(TP)->tell_here(":You hear a sound of bell tolling as \
%<me.name>% reads a scroll of abjuration.",0,0,TP,TP,0,0);
    TP->tell_me("You hear the sound of a bell toll as you read the scroll.");

    for(i=0;i<sizeof(inv);i++) {
	if(inv[i])
	    for(j=0;j<sizeof(summoned);j++) {
		if(strstr("/"+object_name(inv[i]), summoned[j]) != -1) {
		    if(random(100) < 75) inv[i]->vanish();
		    break;
		}
	    }
    }
    TP->tell_me("The scroll vanishes.");
    destruct(this_object());
    return 1;
}
