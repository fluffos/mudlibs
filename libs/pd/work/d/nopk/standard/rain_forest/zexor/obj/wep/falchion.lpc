#include <std.h>
#include <zexor.h>
inherit WEAPON;
int weapon_hit(object atk);

create() {
    ::create();
    set_name("falchion");
    set_short("a wide-bladed falchion");
    set_long("This is a monstrous sword. It is a full 4 feet "
      "of razor sharp metal. It has a deep blood channel all "
      "the way to the embroidered hilt, which a runed pommel "
      "stone is attached too. The sword looks very deadly in "
      "the right hands.");
    set_id(({"wide-bladed falchion", "falchion", "blade"}));
    set_wc(12);
    set_type("blade");
    set_weight(30);
    set_value(600);
    set_hit((:weapon_hit:));
}
int query_auto_load() {
    if(this_player()->query_level() < 37) return 0;
    return 1;
}

int weapon_hit(object atk) {
    int result;
    if(random(100) > 90) {
	write("You slash "+ atk->query_cap_name() +" deeply");
	say(""+ this_player()->query_cap_name() +" slices "+ atk->query_cap_name() +" deeply.");
	result = (random(80))+((this_player()->query_level()));
	return result;
    }
}
