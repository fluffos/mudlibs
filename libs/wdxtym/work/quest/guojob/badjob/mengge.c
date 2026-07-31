// guojing.c 蒙哥
inherit NPC;
#include <ansi.h>
#include "menggujob.c"
//#include "teamjob.c"
string ask_newjob();
string ask_newover();
int job_over(string arg);

void create()
{
	set_name("蒙哥", ({"meng ge", "mengge", "ge"}));
	set("nickname", HIR"蒙古大汉"NOR);
	set("gender", "男性");
	set("age", 31);
	set("long", 
		"他是亲自来攻城的蒙古大汉，面目中透出一股杀气。此次带兵南来，势如破竹，兵锋毕露。\n");
	set("attitude", "friendly");
	set_max_encumbrance(100000000);
	set("per", 40);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
        set_temp("no_kill",1);
	set("chat_chance", 1);
	set("chat_msg", ({
		"蒙哥叹了口气道：“蒙古大军久攻襄阳不下,看来要靠武林人士为我们效力了!!\n",
	}));

	set("inquiry", ([
		 "job"   : (: ask_job :),
                 "fangqi": (: ask_fangqi :),
                "放弃"  : (: ask_fangqi :),
		]));

	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali", 500);
	
	set("combat_exp", 250000);
	set("score", 200000);
	 
        set("combat_exp", 400000+random(900000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

        set_skill("unarmed", 280+random(180));
        set_skill("blade", 280+random(180));
        set_skill("parry", 280+random(180));
        set_skill("dodge", 280+random(180));
        set_skill("kuang-blade", 280+random(180));
        
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set_temp("apply/attack", 320);
        set_temp("apply/defense",350);
        set_temp("apply/armor", 350);
        set_temp("apply/damage", 320);

        setup();

        carry_object("quest/weiguo/menggu/obj/japancloth")->wear();
        carry_object("quest/weiguo/menggu/obj/japanblade")->wield();
}

