// a dungeonware.net production based on demonstrength
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
    set_subclass( ({ "paladin" }) );
    set_skills( ([ "faith" : 20 ]) );
    set_target_properties( ({ "living" }) );
    set_no_combat(1);
}
mapping query_cast()
{
    return casted;
}
int cmd_godspeed(string str)
{
    string us;
    object ob;
    int i, dexterity;
    if (!spell()) return notify_fail("What?\n");
    if (!str || str=="") return notify_fail("Godspeed who?\n");
    if (!ob = present(str, environment(this_player())))
        return notify_fail("Godspeed who?\n");
    if (!ok_to_cast(ob)) return 0;
    if (!target_ok(ob)) return 0;
    if (!casted) casted = ([]);
    us = ob->query_name();
    if (casted[us])
        return notify_fail("The Gods have answered your prayers for "+ob->query_cap_name()+"\n");
    dexterity = 6+random(4)+this_player()->query_faith()/50; 
    casted[us] = (string)dexterity;
    i = this_player()->query_skill("faith")*2;
    this_player()->add_mp(-1*3/2);
    ob->add_stat_bonus("dexterity", dexterity, i);
    call_out("rem_gs", i, us);
    write("%^BOLD%^%^YELLOW%^The Gods answer your prayer and suddenly "+ob->query_cap_name()+" looks more nimble.%^RESET%^");
    message("info", "%^YELLOW%^%^BOLD%^The Gods look you over and you feel more nimble.%^RESET%^", ob);
    message("info", "%^YELLOW%^%^BOLD%^"+ob->query_cap_name()+" starts to glow.%^RESET%^", environment(this_player()), ({ this_player(), ob }) );
    ob->fix_vital_bonus();
    return 1;
}
int rem_gs(string us)
{ 
    object ob;
    if(!(ob = find_player(us))) {
      map_delete(casted, us );
      return;
    }
    message("info", "%^YELLOW%^The Gods lose interest and you feel their presence leave.", ob);
    map_delete(casted, ob->query_name() );
    ob->fix_vital_bonus();
}
int spell()
{
    if (this_player()->query_subclass()!="paladin") return 0;
    if (this_player()->query_level() < 15) return 0;
    return 1;
}
void help() {
    write("Syntax: <godspeed [whom]>\n\n"
      "Paladins can use this prayer to their god for\n"
      "added speed and dexterity.\n"
    );
}
