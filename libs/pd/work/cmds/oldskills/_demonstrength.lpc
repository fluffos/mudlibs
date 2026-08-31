//seeker!
#include <std.h>
inherit OLD_SPELL;
int spell();
mapping casted;
void create()
{
    ::create();
    set_min_mp(40); 
    set_min_level(15);
    set_class( ({ "fighter" }) );
    set_subclass( ({ "antipaladin" }) );
    set_skills( ([ "faith" : 20 ]) );
    set_target_properties( ({ "living" }) );
    set_no_combat(1);
}
mapping query_cast()
{
    return casted;
}
int cmd_demonstrength(string str)
{
    string us;
    object ob;
    int i, strength;
    if (!spell()) return notify_fail("What?\n");
    if (!str || str=="") return notify_fail("Demonstrength who?\n");
    if (!ob = present(str, environment(this_player())))
        return notify_fail("Demonstrength who?\n");
    if (!ok_to_cast(ob)) return 0;
    if (!target_ok(ob)) return 0;
    if (!casted) casted = ([]);
    us = ob->query_name();
    if (casted[us])
        return notify_fail("The demons have answered your prayers for "+ob->query_cap_name()+"\n");
    strength = 6+random(4)+this_player()->query_faith()/50; 
    casted[us] = (string)strength;
    i = this_player()->query_skill("faith")*2;
    this_player()->add_mp(-i*3/2);
    ob->add_stat_bonus("strength", strength, i);
    call_out("rem_ds", i, us);
    write("%^BOLD%^%^RED%^The demons answer your prayer and suddenly "+ob->query_cap_name()+"'s muscles ripple.%^RESET%^");
    message("info", "%^RED%^%^BOLD%^The demons look you over and you feel your muscles ripple.%^RESET%^", ob);
    message("info", "%^RED%^%^BOLD%^"+ob->query_cap_name()+"'s muscles start to glow with evil.%^RESET%^", environment(this_player()), ({ this_player(), ob }) );
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
    message("info", "%^BOLD%^%^BLACK%^You feel the evil from the demons leave your body making you feel weaker.%^RESET%^", ob);
    map_delete(casted, ob->query_name() );
    ob->fix_vital_bonus();
}
int spell()
{
    if (this_player()->query_subclass()!="antipaladin") return 0;
   if (this_player()->query_level() < 5) return 0;
    return 1;
}
void help() {
    write("Syntax: <demonstrength [living]>\n\nAntipaladins are able to "
      "call upon the demons for enhanced strength in themselves or their allies.");
}
