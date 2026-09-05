// 5lun_npc.c
// Created by snowman@SJ
// Modified by snowman@SJ 28/11/2000

#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
    set_name("五轮大转之Perform NPC", ({ "wulun npc", "npc"}));
    set("gender", "男性");
    set("age", 20);
    set("attitude", "peaceful");
    set("str", 40);
    set("int", 40);
    set("con", 30);
    set("dex", 20);
    set("location", 1);
    set("no_quest", 1);
    set("env/invisibility", 1);
    set("max_qi", 500);
    set("max_jing", 500);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 20);
    set("combat_exp", 1000);
    set_temp("hit_ob_hit", 1);
    set_skill("force", 50);
    set_skill("xiangfu-lun", 50);
    set_skill("longxiang-boruo", 50);
    set_skill("strike", 50);
    set_skill("hammer", 50);
    map_skill("force", "longxiang-boruo");
    map_skill("hammer", "xiangfu-lun");
    set_temp("apply/damage", 60);
    setup();
}

void die()
{
    object me, weapon;
    me = query("master_user/user");
    weapon = query("master_user/weapon");

    if( objectp(me) ) 
    {
        me->delete_temp("dazhuan_npc");
        me->add_temp("apply/parry", -100);
        me->add_temp("apply/armor_vs_force", -200);
    }

    if( !objectp(me) || !living(me) || environment(me) != environment(this_object()) )
    {
        if( objectp(weapon) && environment(weapon) == this_object() )
        {
            message_vision(HIW"\n$N"HIW"在空中旋转飞行之势已弱，当当当几声，都落到了地上。\n"NOR, weapon);
            weapon->move(environment(this_object()));
        }
    }
    else if( objectp(me) && objectp(weapon) && environment(weapon) == this_object() )
    {
        if( query("dazhuan_finish") )
        {
            message_vision(HIW"\n$N"HIW"在空中旋转飞行之势已弱，当当当几声，都落到了地上。\n"NOR, weapon);
            weapon->move(environment(this_object()));
        }
        else 
        {
            message_vision(HIY "\n$n"HIY"在$N身旁绕了个圈子，$P伸手一招，那飞行中的$n"HIY"便重新飞回$P的手中！\n\n"NOR, me, weapon);
            weapon->move(me);
            if( !me->query_temp("weapon") )
            weapon->wield();
        }
    }

    destruct(this_object());
}

void unconcious(){ die(); }

void set_master_player(object me, object weapon)
{
    set("name", me->name());
    set_skill("longxiang-boruo", me->query_skill("longxiang-boruo", 1));
    set_skill("force", me->query_skill("force", 1));
    set_skill("xiangfu-lun", me->query_skill("xiangfu-lun", 1));
    set_skill("hammer", me->query_skill("hammer", 1));
    set_skill("strike", me->query_skill("strike", 1));
    set("combat_exp", me->query("combat_exp"));
    set("max_neili", me->query("max_neili"));
    add_temp("apply/attack", me->query_skill("xiangfu-lun", 1)/2);
    add_temp("apply/attack", me->query_skill("longxiang-boruo", 1)/2);
    set("master_user/user", me);
    set("master_user/weapon", weapon);
    weapon->wield();       
}

void heart_beat()
{
    int i;
    object *enemy, target, me, weapon;

    me = query("master_user/user");

    if( !objectp(me) 
    || !me->is_fighting()
    || !living(me) 
    || environment(me) != environment(this_object()) 
    || !objectp(weapon = query_temp("weapon"))
    || weapon != query("master_user/weapon") ){
    die();
    return;
    }
    enemy = me->query_enemy();
    i = sizeof(enemy);
    if( i < 1 || me->query_temp("weapon") ){
    set("dazhuan_finish", 1);
    die();
    return;
    }
/*    if( me->query_skill_mapped("hammer") != "xiangfu-lun" ){
                message_vision(HIY"$N变换了轮法招数，飞行中的$n"HIY"顿时无法控制了！\n"NOR,me, weapon);
                die();
                return;
            }
      else */
    if( me->query_skill_mapped("force") != "longxiang-boruo")
    {
        message_vision(HIY"$N变换了内功招数，飞行中的$n"HIY"顿时无法控制了！\n"NOR,me, weapon);
        die();
        return;
    }
    else if( me->query("neili") < 300 )
    {
        message_vision(HIY"$N内力消耗甚巨，再也控制不了飞行中的$n"HIY"了！\n"NOR,me, weapon);
        die();
        return;
    }
            
    set("neili", me->query("neili"));
    set("jiali", me->query("jiali"));
    target = enemy[random(i)]; 
    if( environment(target) == environment(me) )
    {
        COMBAT_D->do_attack(this_object(), target, query_temp("weapon"), TYPE_SPECIAL);

        if( me->is_fighting(target) && random(10) == 5 )
        {
            if ( !objectp(query_temp("weapon")) )
            {
                set("dazhuan_finish", 1);
                die();
                return;
            }
            COMBAT_D->do_attack(this_object(), target, query_temp("weapon"), TYPE_SPECIAL);
        }
        me->add("neili", -(30+random(50)));
    }
    ::heart_beat();
}

