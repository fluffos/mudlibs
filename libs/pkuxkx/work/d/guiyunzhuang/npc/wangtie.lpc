#include "/quest/quest.h"
#include <ansi.h>
string ask_me();
inherit NPC;
void create()
{
set("title",GRN"桃花岛"NOR+RED"第三代弟子"NOR);
set_name("王铁",({"wang tie","wang"}));
set("long","他英俊潇洒，是陆乘风门下的一位出众的弟子了."
"然而如今由于偷吃了后花园的"GRN"含羞草"NOR"而被陆乘风逐出师门.\n");
set("gender","男性");
set("age",30);
set("attitude","friendly");
set("str",25);
set("int",28);
set("con",23);
set("dex",24);
set("max_qi",800);
set("max_jing",600);
set("neili",800);
set("max_neili",800);
set("combat_exp",100000+random(2000));
set("score",1000);
set_skill("force",90);
set_skill("dodge",90);
set_skill("parry",90);
set_skill("bihai-shengong",90);
set_skill("fuxue-shou",90);
set_skill("hand",90);
set_skill("finger",90);
set_skill("sword",90);
set_skill("yuxiao-jian",90);
set_skill("tanzhi-shengong",90);
set_skill("luoying-shenfa",90);
map_skill("force","bihai-shengong");
map_skill("dodge","luoying-shenfa");
map_skill("sword","yuxiao-jian");
map_skill("finger","tanzhi-shengong");
prepare_skill("finger","tanzhi-shengong");
create_family("桃花岛",3,"弟子");
set("inquiry",(["含羞草":(:ask_me:),
		"陆乘风":"他是我师傅啊，虽然我被他老人家逐出师门，可我并不恨他，是悔当初不该!\n",]));
set_temp("apply/attack",5);
set_temp("apply/defense",10);
set_temp("apply/damage",10);
set("chat_chance_combat",100);
set("shen_type",1);set("score",200);setup();
set("chat_chance",8);
set("chat_msg",({"师傅,我何时才能乞得您的原谅啊?\n",
"我当年一时贪心，才遭到如今的境地.\n",
	}));
carry_object("/d/city/obj/cloth")->wear();
carry_object("/clone/weapon/changjian")->wield();
}
string ask_me()
{	
	this_player()->set_temp("marks/草",1);
	return("它就长在归云庄的后花园里呀!\n");
}	

	
