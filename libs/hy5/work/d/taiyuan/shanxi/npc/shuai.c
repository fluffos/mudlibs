 //TIE@FY3
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;
void create()
{
        set_name("帅一凡", ({ "shuai yifan","shuai" }) );
        set("gender", "男性" );
    	set("title","摘星羽士");
    	set("nickname",HIG"一剑动三山 谈笑斩天星"NOR);
    	set("class","huangshan");
    	set("npc_difficulty",12);
    	set("organization/性质","邪");
        set("age", 55);
        set("int", 30);
        set("per", 30);
        set("fle",40);
        set("cps",35);
        set("dur",40);
        set("resistance/kee",80);
        set("resistance/gin",80);
        set("resistance/sen",80);
        set("long",
"这个羽衣高冠的白发老者便是当年一剑动三山，力斩过天星的名侠。\n"
                );
        set("force_factor", 110);
set("qi", 18000);
	set("max_qi", 18000);
	set("jing", 18000);
	set("max_jing", 18000);
	set("neili", 39000);
	set("max_neili", 39000);
	set("jiali", 100);

	set("combat_exp", 8500000);
	set("score", 200000);
	        set_skill("claw", 220);
        set_skill("throwing", 220);
        set_skill("goplaying", 100);
        set_skill("luteplaying", 100);
        
        set_skill("painting", 100);
        set_skill("medicine", 100);
        set_skill("construction", 100);
        set_skill("horticulture", 100);
        set_skill("dramaturgy", 100);

	set_skill("yangyanshu", 380);
	set_skill("force", 200);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",350);
	set_skill("strike", 250);
        set_skill("sword",250);
	set_skill("sword",200);
	set_skill("strike", 260);
	set_skill("sword", 260);
	set_skill("hand", 360);
	set_skill("qingyun-shou", 380);
	set_skill("panyang-zhang", 380);
	set_skill("liuyue-jian", 380);

	set_skill("wuzhan-mei",380);
	set_skill("zhemei-shou",380);
	set_skill("liuyang-zhang",380);
        set_skill("tianyu-qijian",380);
	set_skill("yueying-wubu",380);
	set_skill("bahuang-gong", 380);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                	(: exert_function, "shield" :),
                	(: exert_function, "dunzun" :),	
                (: perform_action, "sword.kuangwu" :),
                	(: perform_action, "sword.qing" :),
                		(: perform_action, "sword.ju" :),
               
                (: perform_action, "sword.san" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));
        set("chat_chance",1);
        set("chat_msg",({
"帅一凡长长叹息了一声：“可惜故人们多已仙去，只剩下老朽百病之身，
还在人间流浪，再想找一个能伴我烹茶试剑的人，亦不可得了。”\n",
        })      );

        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/qiushui")->wield();
}   
