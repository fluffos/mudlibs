// monkey1.c 
//Made by:pingpang
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIC"老猴子"NOR, ({ "lao monkey","monkey" }) );
	set("gender", "男性");
	set("age", 55);
//	set("race","野兽");似乎出bug，可能是没加limb，屏蔽,by icer
	set("long",
		"这只猴子好可爱啊。\n");
	set("combat_exp", 10000);
        set("shen_type", 0);
	set("attitude", "peaceful");
	
	set("water", 200);
	set("food", 200);

	set("apply/attack", 20);
	set("apply/defense", 20);

//	set("chat_chance", 30);
//	set("chat_msg", ({}));

	set_skill("unarmed", 35);
	set_skill("parry", 35);
	set_skill("dodge", 35);

	setup();

}
int accept_object(object who,object ob)
{
	if((string)ob->query("name")=="蜜桃"||(string)ob->query("id")=="mitao")
		{
			command("say 这桃子好大啊，我得好好吃一顿。\n");
			call_out("dest",1,ob);
			message_vision("猴子很快地闪到一边去了。\n",this_player());
			this_object()->move("/d/guiyunzhuang/taolin2");
			return 1;
		}
	else return 0;
}
void dest(object ob)
{
	destruct(ob);
	return;
}
