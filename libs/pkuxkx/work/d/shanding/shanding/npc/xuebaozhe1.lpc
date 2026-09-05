// File         : xunbaozhe.c
// Modified by zhx

#include <ansi.h>
#include "wield.h"
inherit FAMILY_NPC;


string* family_list = ({  //门派列表
        "shaolin", "wudang", "emei", "gaibang", "tianlong", 
        "tiandihui", "huashan1", "quanzhen", "xingxiu", "baituo", 
        "shenlongjiao", "riyuejiao","dalunsi", "taohua", "gumu", 
        "lingjiu", "murong", "mingjiao" , "chaoting","xiake",
});
int stage = 1+random(19); //关卡

void create()
{
        set_name("寻宝者", ({ "xuebao ren","ren"}) );
        set("gender", "男性" );
        set("age", 52+random(22));
        set("long", "他是一个寻宝人，见人就抢。\n");
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
        setup();
        carry_object("/clone/armor/bianfuxuejia")->wear();
        wield_weapon();
}


