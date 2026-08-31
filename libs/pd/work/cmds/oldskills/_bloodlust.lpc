//Asmodeus
#include <std.h>
inherit OLD_SPELL;
int spell();
mapping casted;
void create()
{
    ::create();
    set_min_mp(100);
    set_min_level(25);
    set_class( ({ "fighter" }) );
    set_subclass( ({ "antipaladin" }) );
    set_skills( ([ "faith" : 50, "attack" : 115 ]) );
    set_target_properties( ({ "living" }) );
    set_no_combat(1);
}
mapping query_cast()
{
    return casted;
}
int cmd_bloodlust(string str)
{
    string us;
    object ob;
    int i, attack, defense;
    if (!spell()) return notify_fail("What?\n");
    if (!str || str=="") return notify_fail("Bloodlust who?\n");
    if (!ob = present(str, environment(this_player())))
        return notify_fail("Bloodlust who?\n");
    if (ob == this_player()->query_current_attacker())
        return notify_fail("You have not the time for this now.\n");
    if(ob->is_monster())
     return notify_fail("The demons howl at your pitiful attempt of trechery.\n");
    if (!ok_to_cast(ob)) return 0;
    if (!target_ok(ob)) return 0;
    if (!casted) casted = ([]);
    us = ob->query_name();
    if (casted[us])
        return notify_fail("The demons have already granted bloodlust upon "+ob->query_cap_name()+".\n");
    attack = ob->query_skill("attack")/5;
    defense = ob->query_skill("defense")/-5;
    casted[us] = (string)attack, defense;
    i = this_player()->query_skill("faith")*2;
   
    this_player()->add_mp(-(this_player()->query_skill("attack")*2)+(this_player()->query_level())+random(50));
    ob->add_skill_bonus("attack", attack);
    ob->add_skill_bonus("defense", defense);
    call_out("rem_bl", i, us);
    write("%^RESET%^%^RED%^The demons answer your prayer and suddenly "+ob->query_cap_name()+" is filled with %^BOLD%^%^RED%^Bloodlust%^RESET%^%^RED%^!%^RESET%^");
    message("info", "%^RESET%^%^%^RED%^Demonic energy fills your body as you are overwhelmed with %^BOLD%^%^RED%^Bloodlust%^RESET%^%^RED%^!%^RESET%^ ", ob);
    message("info", "%^RESET%^%^RED%^"+ob->query_cap_name()+" eminates an evil aura and is overwhelmed with %^BOLD%^%^RED%^Bloodlust%^RESET%^%^RED%^!%^RESET%^ ", environment(this_player()), ({ this_player(), ob }) );
    ob->fix_vital_bonus();
    return 1;
}
void help() {
    write(" Syntax: <bloodlust [living]>"
      "Bloodlust summons forth the darkest energy from within the antipaladin "
"and uses it to increase the battle prowess of the target.  The drawback is that "
"the recipient often becomes careless in battle resulting in lower defense."
    );
}
int rem_bl(string us)
{ 
    object ob;
    if(!(ob = find_player(us))) {
      map_delete(casted, us );
      return 1;
    }
    ob->add_skill_bonus("attack", -to_int(casted[ob->query_name()]));
    ob->add_skill_bonus("defense", to_int(casted[ob->query_name()]));
    message("info", "%^RESET%^%^RED%^Your mind and body find peace once again as the %^BOLD%^%^RED%^Bloodlust%^RESET%^%^RED%^ subsides.%^RESET%^ ", ob);
    map_delete(casted, ob->query_name() );
    ob->fix_vital_bonus();
}
int spell()
{
    if (this_player()->query_subclass()!="antipaladin") return 0;
    if (this_player()->query_skill("faith") < 50) return 0;
    if (this_player()->query_level() < 25) return 0;
    return 1;
}
