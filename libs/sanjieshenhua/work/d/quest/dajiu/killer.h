string invocation(object ob)
{
    int level;
    object weapon;
    object me = this_object();

    level = NPC_D->get_skill_level(ob);
    level = level + 40 + random(20);
    STATU_D->set_npc_skill(me, level);
    NPC_D->set_npc_hp(me, ob, 150);
    weapon = STATU_D->family_weapon(query("family/family_name"));
    weapon->move(me);
    weapon->wield();

    if (ob->query("combat_exp") < 20000000)
    {
        set_temp("apply/damage", 35);
        set_temp("apply/armor", 350);
    } else 
    {
        set_temp("apply/armor", 450);
        set_temp("apply/damage", 40);
    }  
    set("level", ob->query("level"));
    set("owner", ob);

    call_out("leave", 300);
}
