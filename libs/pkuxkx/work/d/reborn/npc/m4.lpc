// File         : master.c
// Modified by  : kiden@pkuxkx

inherit FAMILY_NPC;
#include <ansi.h>
#include "wield.h"
#include "wear.h"

void die();
void full_me();

string* family_list = ({  //门派列表
        "shaolin", "wudang", "emei", "gaibang", "tianlong", 
        "tiandihui", "huashan1", "quanzhen", "xingxiu", "baituo", 
        "shenlongjiao", "riyuejiao","dalunsi", "taohua", "gumu", 
        "lingjiu", "murong", "mingjiao" , "chaoting","xiake",
});
int stage = 4; //关卡

void create()
{
        set_name("武学大宗师", ({ "grand master", "zong shi","master"}) );
        set("gender", "男性" );
        set("age", 52+random(22));
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
        family_skill(this_object(), family_list[stage-1], 800+random(100), 1);
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
        set("stage",1);
        set("inquiry",([ 
         
        ]));
        set_temp("apply/damage", 400);
        set_temp("apply/defense",800);
        set("jiali",500);
        set("combat_exp",80000000+random(20000000));
        set("shen_type",1);set("score",0);setup();
        //carry_object("/clone/armor/bianfuxuejia")->wear();
        wield_weapon();
}

void init()
{
    object pl, ob;

    pl = this_player();
    ob = this_object();


    if ( userp(pl) && !wizardp(pl) && !pl->query("reborn/stage_"+stage) &&
         !(pl->query("eff_qi")<0 || pl->query("eff_jing")<0 || pl->query("qi")<0 || pl->query("jing")<0) )
    {
        full_me();
        if (!ob->query_temp("weapon")) wield_weapon();
        wear_armor(pl);
        ob->set_temp("time", time());
    }
    add_action("do_none","hit");
    add_action("do_none","fight");
    add_action("full_me","kill");
    add_action("do_none","hitall");
    add_action("do_none","killall"); 
    add_action("do_none","halt");
}


void unconcious()
{
        die();
}

int do_none()
{
        return 1;
}

void die()
{
        object me = get_damage_origin_object();
        if(!objectp(me) || !present(me, environment()))
        {
            full_me();
            return;
        }
        if ((int)me->query("reborn/stage_"+stage)<1)
        	{
        message_vision("$N闯过了第"+chinese_number(stage)+"关。\n", me);
        CHANNEL_D->do_channel(this_object(), "jh", "金庸(Jin yong):"+me->name()+"闯过了第"+chinese_number(stage)+"关。", -1);
        me->add("combat_exp",100000);
        me->add("potential",10000);
        me->add("repute",1000);
        me->set("reborn/stage_"+stage,1);
         }
        ::die();
}

void full_me()
{
        object me = this_object();
        me->command("sneer");
        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("neili",2*me->query("max_neili"));
        me->set("jingli",2*me->query("max_jingli"));
        me->clear_condition();
        return;
}
