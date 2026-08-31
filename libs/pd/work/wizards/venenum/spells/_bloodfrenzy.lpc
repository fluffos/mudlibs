// Venenum, based off code provided by Seeker.

#include <std.h>
inherit OLD_SPELL;
int spell();
mapping casted;
void create()
{
    ::create();
    set_min_mp(40); 
    set_min_level(15);
    set_class( ({ "vampire" }) );
    set_subclass( ({ "vampire" }) );
    set_skills( ([ "death" : 135 ]) );
    set_target_properties( ({ "undead" }) );
    set_no_combat(1);
}
mapping query_cast()
{
    return casted;
}
int cmd_bloodfrenzy(string str)
{
    string us;
    object ob;
    int i, strength;
    if (!spell()) return notify_fail("What?\n");
    if (!str || str=="") return notify_fail("Summon the Blessing of Blood upon whom?\n");
    if (!ob = present(str, environment(this_player())))
	return notify_fail("That undead is not there...\n");
    if (!ok_to_cast(ob)) return 0;
    if (!target_ok(ob)) return 0;
    if (!casted) casted = ([]);
    us = ob->query_name();
    if (casted[us])
	return notify_fail(ob->query_cap_name()+" suffers the Blessing of Blood already.\n");
    strength = (this_player()->query_level()/10)+random(4)+this_player()->query_skill("death")/30; 
    casted[us] = (string)strength;
    i = this_player()->query_skill("death")*3;
    this_player()->add_bp(-150);
    ob->add_stat_bonus("strength", strength, i);
    ob->add_skill_bonus("melee", strength*5, i);
    call_out("rem_ds", i+1, us);
    if (ob->query_name() == this_player()->query_name())
    {
	write("%^BOLD%^%^BLACK%^You bite down on your own lip, letting the %^RED%^blood%^BLACK%^ run freely down your own chin. You feel stronger.");
    }
    else
    {
	write("%^BOLD%^%^BLACK%^You bite down on your own lip, then touch the %^RED%^blood%^BLACK%^ with your finger and flick the %^RED%^blood%^BLACK%^ at "+ob->query_cap_name()+".%^RESET%^");
    }
    message("info", "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" flicks some %^RED%^blood%^BLACK%^ at you, leaving you splattered with drops of crimson liquid. You feel stronger.%^RESET%^", ob, this_player());
    message("info", "%^BOLD%^%^BLACK%^"+ob->query_cap_name()+" is splashed with the blood of the nosferatu, leaving "+ob->query_objective()+" splattered in drops of burning %^RED%^blood%^BLACK%^.%^RESET%^", environment(this_player()), ({ this_player(), ob }) );
    ob->fix_vital_bonus();
    return 1;
}
int rem_ds(string us)
{ 
    object ob;
    if(!(ob = find_player(us))) {
	map_delete(casted, us );
	return;
    }
    message("info", "%^BOLD%^%^BLACK%^The %^RED%^blood%^BLACK%^ evaporates from your body.", ob);
    map_delete(casted, ob->query_name() );
    ob->fix_vital_bonus();
}
int spell()
{
    if (this_player()->query_subclass()!="vampire") return 0;
    if (this_player()->query_level() < 25) return 0;
    return 1;
}
void help() {
    write("Syntax: <bloodfrenzy [undead]>\n\n Vampires may use this spell to splatter some of their own blood onto another undead, granting them unholy power.");
}
