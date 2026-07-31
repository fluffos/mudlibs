// duanzc.c 段正淳

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_save();
string ask_duan();
string fenglu();

void create()
{
	set_name("小段正淳", ({ "duan zhengchun", "duan" }));
	set("title",  "大理镇南王" );
	set("long", "他就是大理国的镇南王，当今皇太弟，是有名的爱情圣手。\n");
	set("gender", "男性");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	
	set("max_qi", 2500);
	set("max_jing", 220);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 300000);

        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff", 140);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("staff", 150);
        set_skill("finger", 120);
        set_skill("finger", 150);
	set_skill("kurong-changong", 280);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 130);
        set_skill("wuluo-zhang", 150);
        set_skill("duanjia-sword", 280);
        set_skill("yiyang-zhi", 280);
//        set_skill("sun-finger", 100);
	set_skill("literate", 100);

	map_skill("unarmed", "yiyang-zhi");
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "yiyang-zhi");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "yiyang-zhi");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.jingtian" :),
                (: perform_action, "sword.feilong" :),                
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
        set("inquiry", ([
            "name": "你问这干嘛，我就是段正淳，难道你又是我情人生的孩子？",
            "here": "这里便是镇南王府。",
            "天龙寺" : "天龙寺是我段家武学的最高之地，不过，想拜天龙寺可不是那么容易的.",
        ]));
	setup();
        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"/obj/badan");
        carry_object(__DIR__"/obj/jinchuang");

	add_money("silver", 50);

	create_family("大理段家",18,"镇南王");
}


