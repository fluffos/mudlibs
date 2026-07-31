// duanzc.c 段正淳

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("段正淳", ({ "duan zhengchun", "duan" }));
	set("title",  "大理镇南王" );
	set("long", "他就是大理国的镇南王，当今皇太弟，是有名的爱情圣手。\n");
	set("gender", "男性");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 130);
	set("int", 130);
	set("con", 135);
	set("dex", 130);
	
	set("max_qi", 552500);
	set("max_jing", 551220);
	set("neili", 555000);
	set("max_neili", 555000);
	set("jiali", 100);
	set("combat_exp",15000000);
	set("score", 300000);

        set_skill("unarmed", 1150);
        set_skill("force", 1150);
        set_skill("dodge", 1150);
        set_skill("parry", 1150);
        set_skill("cuff", 1140);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("staff", 1150);
        set_skill("finger", 120);
        set_skill("finger", 150);
	set_skill("kurong-changong", 980);
        set_skill("tiannan-step", 1350);
        set_skill("jinyu-quan", 1330);
        set_skill("wuluo-zhang", 1350);
        set_skill("duanjia-sword", 980);
        set_skill("yiyang-zhi", 980);
//        set_skill("sun-finger", 100);
	set_skill("literate", 1000);

	map_skill("unarmed", "yiyang-zhi");
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "yiyang-zhi");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "yiyang-zhi");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.jian" :),
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.jingtian" :),
                (: perform_action, "sword.feilong" :),   
                	(: perform_action, "sword.ailao" :),
                		(: perform_action, "sword.xswy" :) ,            
                (: perform_action, "dodge.huadie" :),            
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );

	setup();
    carry_object("/p/item/ritemtz3/wsword18")->wield();
    carry_object("/p/item/ritemtz3/ahands19")->wear();
	carry_object("/clone/misc/cloth")->wear();
	//add_money("silver", 50);

	create_family("大理段家",18,"镇南王");
}

