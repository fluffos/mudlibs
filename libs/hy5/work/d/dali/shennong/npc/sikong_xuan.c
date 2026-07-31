// 司空玄    /d/menpai/shennong/npc/sikong_xuan.c
// by lala, 1998-01-21

#include <ansi.h>
inherit __DIR__"ShennongNpc.c";
inherit F_MASTER;



void create()
{
    set_name("司空玄", ({ "sikong xuan", "sikong", "sikongxuan", "bangzhu", }) );
    set("class_score/神农帮",       400);
    set("title", BLU"神农帮帮主"NOR);
    create_family("神农帮", 1, "帮主");
    set("combat_exp",   1500000);
    set("social_exp",   240000);
    set("negative_score", 1200);
    set("max_force",       900);
    set("force",           900);
    set("force_factor",     50);
    set("max_kee",         425);
    set("max_sen",         425);
    set("kee",             425);
    set("sen",             425);
    set("age",              55);
    set("int",              30);
    set("long", @LONG
　　神农帮主司空玄是一个瘦小的老者，颏下一把山羊胡子，神态甚是倨傲。
LONG
    ); 
    
	set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 14000);
	set("max_neili", 14000);
	set("max_neili", 14000);
	set("jiali", 100);
	set("combat_exp", 5500000);
	set("score", 400000);

	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("huagong-dafa", 280);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 280);
	set_skill("dodge", 250);
	set_skill("zhaixinggong", 280);
	set_skill("strike", 250);
	set_skill("chousui-zhang", 280);
	set_skill("claw", 350);
	set_skill("sanyin-wugongzhao", 280);
	set_skill("parry", 200);
	set_skill("staff", 300);
	set_skill("poison", 280);
	set_skill("tianshan-zhang", 280);
	set_skill("chanhun-suo", 280);
	set_skill("whip", 280);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 280);
set_skill("bingpo-blade", 280);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "whip.duo" :),
(: perform_action, "whip.huixuan" :),
(: perform_action, "whip.suo" :),
         }) );

    setup();

    carry_object("/clone/misc/cloth" )->wear();
    add_money( "gold", 1 + random(3) );
}


        
