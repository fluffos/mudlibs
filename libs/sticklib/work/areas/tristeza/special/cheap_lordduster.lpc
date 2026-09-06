#include <weapon.h>

void
create_weapon()
{
    set_name("lordduster");
    set_id(({ "duster","cheap lordduster", "cheap imitation of lordduster", "cheap imitation of the lordduster", "imitation of lordduster", "imitation of the lordduster" }));
    set_short("Lordduster"); //Now ninjas can use it again
    set_long("A cheap imitation of the massive lordduster with some blood-like stains on it.");
    set_wc(18);
    set_weight(4);
    set(WP_BLUNT);
    set_value(500);
    set_hit_func(this_object());
}
varargs status
wield_cmd(string str, object me) {
    if((int)this_player()->query_level()<20 && (int)this_player()->is_npc()==0) {
	this_player()->tell_me("It is too big for your hand.");
	return 1;
    }
    return ::wield_cmd(str,me);
}
weapon_hit(ob) {
    object att;
    if(!this_player()) return;
    att=this_player()->query_attack();
    if(!att) att=this_player()->query_alt_attack();
    if(!ob || !att) return;
    if(!random(3)) {
	write("You wish you would fraction "+att->query_name()+"'s bones.\n");
	say(this_player()->query_name()+" wishes that "+this_player()->Pronoun()+" would fraction "+att->query_name()+"'s bones.\n",att);
	tell_object(att,this_player()->query_name()+" wishes that "+this_player()->Pronoun()+" would fraction your bones.\n");
	return 2; /* Total wc 20 per round */
    }
}
