// File         : master.c
// Modified by  : kiden@pkuxkx

#include <ansi.h>
#include "wield.h"
#include "full.h"
inherit FAMILY_NPC;
void die();

void create()
{
        set_name("武学大宗师", ({ "zong shi", "grand master"}) );
        set("gender", "男性" );
        set("age", 22+random(22));
        set("long", "他是镇守关卡的武学大宗师，想要出师得过了他这一关。\n");
        set("per",30);
        set("kar",30);
        set("str",30);
        set("con",30);
        set("dex",30);
        set("int",30);
        set("attitude", "peaceful");
        set("rank_info/respect", "老前辈");
        set("chat_chance_combat", 100);
        family_skill(this_object(), "random", 800+random(100), 1);
        set("max_qi",  15000);
        set("eff_qi",  15000);
        set("qi",      15000);
        set("max_jing",15000);
        set("eff_jing",15000);
        set("jing",    15000);
        set("max_jingli",15000);
        set("jingli",    15000);
        set("max_neili", 15000);
        set("neili",     15000);
        set_temp("apply/damage", 500);
        set_temp("apply/defense",800);
        set("jiali",500);
        set("combat_exp",70000000+random(30000000));
        setup();
        carry_object("/clone/armor/bianfuxuejia")->wear();
        wield_weapon();
}

void init()
{
        add_action("full_me","hit");
        add_action("full_me","fight");
        add_action("full_me","kill");
        add_action("full_me","hitall");
        add_action("full_me","killall");        
}


void unconcious()
{
        die();
}

void die()
{
        object me = get_damage_origin_object();
        if(!objectp(me) || !present(me, environment()))
        {
                ::die();
                return;
        }
        message_vision("$N闯过了第一关。\n", me);
        message("chat",HIY+"【闲聊】金庸(Jin yong):"+me->name()+"闯过了第一关。\n"NOR,users());
        me->add("combat_exp",100000);
        me->add("potential",10000);
        me->add("repute",1000);
        me->set("reborn/stage1",1);
        ::die();
}

int accept_fight(object ob)
{
    return 0;
}

void start_busy(mixed new_busy, mixed new_interrupt)
{
        if(intp(new_busy) && new_busy > 15)

                ::start_busy(14+random(3));
}
