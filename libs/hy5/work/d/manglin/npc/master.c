 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("裴冥通天", ({ "master peiming", "master", "peiming" }) );
    set("nickname", HIG"五毒童子"NOR);
    set("gender", "男性" );
    set("age", 44);
    set("str", 30);
    set("cor", 30);
    set("cps", 30);
    set("int", 30);
    set("per", 30);
    set("attitude","aggresive");
    set("max_neili", 15000);
    set("force", 15000);
    set("force_factor", 3);
    set("long", "裴冥通天学艺于自然，以最毒之物为师，一身毒气杀人于无形．"
        "更精于通天降．．\n");
    set("rank_nogen",1);
    create_family("通天门", 1, "门主");
    set("ranks",({"门众","副堂主","堂主","副坛主","坛主",
                      "副舵主","舵主","护法","大护法",
                      "长老","大长老","副帮主"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("combat_exp", 10000000);
    set("score", 200000);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :)
            }) ); 
	set("max_qi", 25000);
	set("max_jing", 23000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 100);
	set("combat_exp", 8000000);
	set("score", 600000);

		set_skill("zhuihun-biao", 380);
		set_skill("liuxing-biao", 380);
	set_skill("pili-biao",380);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 380);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 380);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 380);
	set_skill("parry", 280);
	set_skill("throwing", 380);
	set_skill("zimu-zhen", 380);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	

	set("chat_chance_combat", 98);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
                (: perform_action, "throwing.qizigangbiao" :),
                (: perform_action, "throwing.tanghua" :),
		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );

    setup();
	carry_object("/d/tangmen/obj/zimuzhen")->wield();
    carry_object(__DIR__"obj/ducloth")->wear();
} 
