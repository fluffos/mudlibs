// sample master.c code
// xiake island master.c
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void consider();

void create()
{
	set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
	set("title", HIG"北丐"NOR);
	set("gender", "男性");
	set("age", 75);
set("beggarlvl",9);
	set("long", 
		"他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 130);
	set("int", 134);
	set("con", 130);
	set("dex", 134);

	set("chat_chance", 1);
	set("chat_msg", ({
		"洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
		"洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
		"洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
	}));
	set("qi", 359000);
	set("max_qi", 359000);
	set("jing", 359400);
	set("max_jing", 359400);
	set("neili", 368000);
	set("max_neili", 368000);
	set("jiali", 500);
//	        set_temp("no_kill",1);
	set("combat_exp", 15000000);
	set("score", 500000);
	set("shen", 100000);
	         set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over500", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
        set("xlz/hang", 1);
         set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
	set_skill("force", 1100);             // 基本内功
	set_skill("huntian-qigong", 1100);    // 混天气功
	set_skill("unarmed", 1100);           // 基本拳脚
	set_skill("xianglong-zhang", 1100);   // 降龙十八掌
	set_skill("dodge", 1100);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 1150);        // 逍遥游
	set_skill("parry", 1100);             // 基本招架
	set_skill("staff", 1100);             // 基本棍杖
	set_skill("dagou-bang", 1100);        // 打狗棒法
	set_skill("begging", 1100);           // 叫化绝活
	set_skill("checking", 1150);          // 道听途说
	set_skill("training", 1150);         // 驭兽术
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.zhuang" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.duo" :),
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield staff") :),
                (: command("wield staff") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
	setup();
	
    carry_object("/p/item/ritemtz3/wstaff34")->wield();
    carry_object("/p/item/ritemtz3/ahands32")->wear();
    carry_object("/kungfu/class/gaibang/obj/jiaohuaji");
}

