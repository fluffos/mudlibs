// by mudring

void do_copy(object me)
{
    int level;
    object weapon;
    object killer = this_object();
    string action, family;

    level = NPC_D->get_skill_level(me);
    if (me->query("combat_exp") < 1000000)
    {
        level = level - 50 + random(20);
        killer->set_temp("apply/damage", 25);
        killer->set_temp("apply/armor", 200);
    } else 
    if (me->query("combat_exp") < 10000000)
    {
        level = level + 50 + random(30);
        killer->set_temp("apply/armor", 450);
        killer->set_temp("apply/damage", 80);
    } else
    {
        level = level + 30 + random(50);
        killer->set_temp("apply/armor", 450);
        killer->set_temp("apply/damage", 40);
    }
    if (level < 0) level = 0;
    STATU_D->set_npc_skill(killer, level);
    NPC_D->set_npc_hp(killer, me, 100);

    family = killer->query("family/family_name");
    weapon = STATU_D->family_weapon(family);
    weapon->move(killer);
    weapon->wield();

/*
    if (me->query("combat_exp") > 10000000 ||
        me->query("office_number") > 1000)
    {
        action = STATU_D->family_action(family);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
            (: perform_action, weapon->query("type"), action :),
        }));
    }
*/

    killer->set("owner", me);
    killer->set_leader(me);
    killer->kill_ob(me);
    me->set_temp("tongchuan/kk", 1);
    call_out("leave", random(50) + 300);
}

