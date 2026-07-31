// zuoqh.c 
//by dwolf

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
	set_name(YEL"左轻候"NOR, ({ "zuo qinghou", "zuo" }));
	set("gender", "男性");
	set("age", 50);
	set("long",
        	"他看上去鹤发童颜，和蔼可亲，一副淡泊名利，逍遥世外
的模样。\n");

	set("attitude", "peaceful");

	set("str", 200);
	set("int", 200);

	set("combat_exp", 500000);

	set("inquiry", ([
		"糖醋鱼" : (: ask_me :),
	]) );  
	set("count", 1);
	
	set("chat_chance", 5);
	set("chat_msg", ({
		"小兄弟，你可知道老夫做的糖醋鱼天下无双？ \n",
	}) );
	
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 5);

	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	
	setup();
}      

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("count") < 1)
		return "抱歉，你来晚了，糖醋鱼已经给别人了。";

	ob = new(__DIR__"/npc/obj/yu");
	ob->move(this_player());

	add("count", -1);

	message_vision("\n左轻候长笑一声，点点头，很快做好一条糖醋鱼，然后交
			交给$N。\n\n", this_player());

	return "我一天只做一条糖醋鱼，你既然来得恰到时候，这鱼就送给你了。";
}


