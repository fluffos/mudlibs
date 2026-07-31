// bao.c 包打听
inherit F_CLEAN_UP;
#include <ansi.h>


inherit NPC;
int ask_baowu();
int ask_gushi();



void create()
{
	object book;

	set_name(HIR"涂山苏苏"NOR, ({"tu shan", "susu"}));
	set("gender", "女性");
	set("age", 12);
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 50000001);
	set("int", 30000006);
	set("con", 50000002);
	set("dex", 200000009);

	set("qi", 100000000);
	set("max_qi", 1000000);
	set("jing", 310000);
	set("max_jing", 310000);
	set("neili", 650000);
	set("max_neili", 650000);
	set("jiali", 50000);

	set("combat_exp", 20);

	set_skill("force", 1);
	set_skill("dodge", 100);
	set_skill("parry", 1);
	set_skill("unarmed", 1000);
	set_skill("literate", 1000);

	set("title", "红线仙");

	set("inquiry", ([
		"问情" : (: ask_baowu :),		
	]));

	set_temp("apply/attack", 900000);
	set_temp("apply/dodge", 8000000);
	set_temp("apply/parry", 8000000);
	set_temp("apply/unarmed_damage", 900000);
	set_temp("apply/damage", 300000);
set("chat_msg", ({
	HIR"苏苏大声喊到：红尘仙免费算姻缘了!”\n",NOR
	HIR"苏苏委屈巴巴的说：月初哥哥不知道去哪了?”\n",NOR
    }));
	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("show_baowu","chabw");
}



int ask_baowu()
{
	string str,*items,wen,arg;
	object me,liwu;
	me = this_player();
     liwu = new("/clone/gift/meigui");
	if(me->query("wenqin")==1)
	{
		 write(HIR"苏苏恶狠狠的说；变心是不好的哦！\n"NOR);
	return notify_fail(HIR"变心是不好的哦。\n"NOR);
	}
	
	write(INPUTTXT(HIR"你喜欢谁呢"NOR, "call me->set(love,$txt#)") + "\n");
  
  
   me->set("wenqin",1);
   write(HIR"苏苏大声喊道；祝你有情人终成眷属，这个小礼物就送给你啦\n"NOR);
   write(HIR"苏苏点点头；这个小礼物就送给你啦\n"NOR);
	liwu->move(me);
	return 0;
}



