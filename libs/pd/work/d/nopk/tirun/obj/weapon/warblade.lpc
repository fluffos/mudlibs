#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);

void create() {
    ::create();
    set_name("warblade");
    set_short("Orcish Warblade");
    set_type("blade");
    set_weight(27);
    set_hands(2);
    set_long("This huge sword is known as an Orcish Warblade. With a grip far exceeding that of most men, this sword is crafted for use in both hands of an orc- heavy, sharp and very robust, it is a dependable weapon for those of above average strength. Some say that Rocko, the previous owner of this blade, even had a few minor enchantments placed upon it to make it stronger in battle.");
    set_id(({ "warblade","orcish warblade","blade" }));
    set_wc(4);
    set_curr_value("gold", 54);
    set_hit((: weapon_hit :));
}

int query_auto_load() { return 1; }

int weapon_hit(object atk) {

    int result;
    if(random(10) == 7) {
	result = this_player()->query_stat("strength");
	message("info", ""+this_player()->query_cap_name()+" cleaves into "+atk->query_cap_name()+" mightly with their Orcish Warblade!", environment(atk), ({atk, this_player()}));
	write("You cleave mightily with your Orcish Warblade!", this_player());
	message("info", ""+this_player()->query_cap_name()+" cleaves into you mightily with their Orcish Warblade!", atk);
	return result;
    }
}
