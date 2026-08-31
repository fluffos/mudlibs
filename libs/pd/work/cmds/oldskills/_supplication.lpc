#include <std.h>
inherit OLD_SPELL;

int spell();

mapping casted;

void create()
{
    ::create();

    set_min_mp(10);
    set_min_level(12);
    set_class( ({ "clergy" }) );
    set_subclass( ({ "monk" }) );
    set_skills( ([ "faith" : 70, ]) );
    set_target_properties( ({ "living" }) );
    set_no_combat(1);
}
mapping query_cast()
{
    return casted;
}
int cmd_supplication(string str)
{
    string us;
    object ob;
    int i, attack, defense, strength, dexterity, constitution;

    if (!spell()) return notify_fail("What?\n");
    if (!str || str=="") return notify_fail("Perform supplication for whom?\n");
    if (!ob = present(str, environment(this_player())))
        return notify_fail("Thats asking a bit much dont you think?\n");
    if (!ok_to_cast(ob)) return 0;
    if (!target_ok(ob)) return 0;
    if (!casted) casted = ([]);
    us = ob->query_name();
    if (casted[us])
        return notify_fail("You have already asked your deity to assist "+ob->query_cap_name()+".\n");
    attack = ob->query_skill("attack")/7;
    defense = ob->query_skill("defense")/7;
    strength = ob->query_stats("strength")/18;
    dexterity = ob->query_stats("dexterity")/18;
    constitution = ob->query_stats("constitution")/18;
    casted[us] = (string)attack, defense, strength, constitution, dexterity;
    i = this_player()->query_skill("faith")/2+(this_player()->query_level());
    this_player()->add_mp(-(this_player()->query_skill("faith")*2)+(this_player()->query_level())+random(50));
    ob->add_skill_bonus("attack", attack, i);
    ob->add_skill_bonus("defense", defense, i);
    ob->add_stat_bonus("strength", strength, i);
    ob->add_stat_bonus("dexterity", dexterity, i);
    ob->add_stat_bonus("constitution", constitution, i);
    call_out("rem_sl", i/2, ob);
    write("%^BOLD%^CYAN%^You ask your god for divine aid.%^RESET%^");
    message("info", "%^CYAN%^You feel an incredible boost in your strength and stamina.%^RESET%^", ob);
    message("info", "%^CYAN%^"+ob->query_cap_name()+" suddenly looks more imposing.%^RESET%^", environment(this_player()), ({ this_player(), ob }) );
    return 1;
}
void help() {
    write(" Syntax: <supplication [living]>"
      "\n\nMonks use the spell of supplication to pray for divine aid from their chosen diety.  If the diety chooses to answer, the target is blessed with greater battle prowess.  This spell is used by both light and dark monks.\n"
    );
}
int rem_sl(object ob)
{ 
/*
    str = -(ob->query_stats_bonus("strength"));
    dex = -(ob->query_stats_bonus("dexterity"));
    con = -(ob->query_stats_bonus("constitution"));
    ob->add_skill_bonus("attack", -to_int(casted[ob->query_name()]));
    ob->add_skill_bonus("defense", -to_int(casted[ob->query_name()]));
    ob->add_stat_bonus(str, "strength" );
    ob->add_stat_bonus(dex, "dexterity" );
    ob->add_stat_bonus(con, "constitution" );*/
    message("info", "%^CYAN%^You are no longer under the benefit of supplication.%^RESET%^", ob);
    map_delete(casted, ob->query_name() );
    return 1;
}

int spell()
{
    if (this_player()->query_subclass()!="monk") return 0;
    if (this_player()->query_skill("faith") < 70) return 0;
    if (this_player()->query_level() < 12) return 0;
    return 1;
}
