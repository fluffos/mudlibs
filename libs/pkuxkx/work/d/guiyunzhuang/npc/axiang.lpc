#include <ansi.h>
string ask_me();
inherit NPC;
void create()
{
set("title",RED"花侍"NOR);
set_name("阿香",({"a xiang","xiang"}));
set("nickname",GRN"花神"NOR+RED"仙子"NOR);
set("long","她有沉鱼落雁，闭月羞花之貌，堪称人间仙子。\n");
set("gender","女性");
set("age",20);
set("attitude","friendly");
set("str",21);
set("int",20);
set("con",20);
set("dex",17);
set("max_qi",200);
set("max_jing",200);
set("neili",200);
set("max_neili",200);
set("combat_exp",3000);
set("score",1000);
set_skill("force",30);
set_skill("dodge",20);
set_skill("unarmed",20);
set_skill("parry",10);
set_temp("apply/attack",5);
set_temp("apply/defense",10);
set_temp("apply/damage",10);
set("chat_chance_combat",100);
set("inquiry",(["烟斗":(:ask_me:),]));
set("shen_type",1);set("score",200);setup();
set("chat_chance",8);
set("chat_msg",({"来赏花呀,我们这儿的花可是武林中最最有名的啊.\n",
	"昨晚上总管去我的厢房，把烟斗忘在了那儿.\n",		
}));
carry_object("/d/city/obj/cloth")->wear();
}
string ask_me()
{	
	object ob;
	ob=new(__DIR__"obj/yandou");
	if(this_player()->query_temp("been_get"))
		return("你不是已经拿走了吗?\n");
	else
		{
			ob->move(this_player());
			this_player()->set_temp("been_get",1);
			return("你帮我把烟斗还给他吧，他就在南面的走廊里。\n");	
		}
}
