//liehu.c 猎户
//Made By:pingpang
#include <ansi.h>

inherit NPC;
void create()
{
	set_name(HIC"猎户"NOR,({"lie hu","lie","hu"}));
	set("nickname",RED"神射手"NOR);
	set("age",41);
	set("gender","男性");
	set("long",@LONG
他是个中年人，皮肤黝黑，一定是经常在太阳下晒的。\n
他身背弓箭，是方圆十里的有名的猎户。
LONG);
	set("attitude","friendly");
	set("str",28);
	set("int",24);
	set("con",24);
	set("dex",21);
	set("combat_exp",15000+random(2000));
	set("max_qi",600);
	set("max_neili",300);
	set("neili",300);
	set("max_jing",400);
	set("jiali",10);
	set_skill("force",35);
	set_skill("dodge",35);
	set_skill("unarmed",40);
	set_skill("parry",40);
	set("chat_chance_combat",100);
	set("shen_type",1);set("score",200);setup();
	set("chat_chance",5);
	set("chat_msg",({"我刚从树林里打猎回来，今天收获还算颇丰啊.\n",
	"我在树林深处遇到了一位[隐者]，他说他有一件稀世之宝---[金轮铠甲].\n",
	}));
	carry_object("/d/city/obj/cloth")->wear();
	add_money("silver",15);
}
