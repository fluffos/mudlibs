// YangXiao.c
// pal 1997.05.09



inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();
string ask_ling();

void create()
{
	set_name("杨霄", ({"yang xiao","yang","xiao",}));
	set("long",
	"他是一位中年书生，身穿白布长袍。\n"
	"他相貌俊雅，只是双眉略向下垂，嘴边露出几条深深的皱纹，不免略带衰老凄苦\n"
	"之相。他不言不动，神色漠然，似乎心驰远方，正在想什么事情。\n"
	);

	set("title",HIG "明教" HIR "光明左使" NOR);
	set("level",11);
	set("gender", "男性");
	set("attitude", "peaceful");
	
	set("age", 42);
	set("shen_type", 1);
	set("per", 29);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

        set("max_qi", 3500);
        set("max_jing", 150000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 1500);
        set("combat_exp", 1000000);
        set("score", 800000);

        set_skill("force", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("sword", 220);
        set_skill("cuff", 220);
        set_skill("strike", 220);
        set_skill("literate", 220);

        set_skill("shenghuo-xinfa", 220);
        set_skill("lingxu-bu", 220);
        set_skill("shenghuo-bu", 220);
        set_skill("pili-quan", 220);
        set_skill("shenghuo-quan", 220);
        set_skill("guangming-zhang", 220);
        set_skill("liehuo-jian", 220);
        set_skill("xiaoyao-jian", 220);
        set_skill("martial-cognize", 220);

        map_skill("force", "shenghuo-xinfa");
        map_skill("dodge", "lingxu-bu");
        map_skill("strike", "guangming-zhang");
        map_skill("cuff", "shenghuo-quan");
        map_skill("parry", "xiaoyao-jian");
        map_skill("sword", "xiaoyao-jian");

        prepare_skill("cuff", "shenghuo-quan");
        prepare_skill("strike", "guangming-zhang");

	set("inquiry", 
	([
		"光明圣火阵"  : (: ask_me :),
		"明教圣火阵"  : (: ask_me :),
		"圣火阵"      : (: ask_me :),
	]));

	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: command("perform sword.kuai") :),
                (: command("perform sword.qi") :),
                (: command("perform sword.fei") :),
                (: command("perform cuff.jin") :),
        }) );
        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);
	create_family("明教", 34, "光明左使");
	setup();
	   
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object ();
	ob = this_player ();

	::init();

	if (interactive(ob) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}


#include "yangxiao.h"
