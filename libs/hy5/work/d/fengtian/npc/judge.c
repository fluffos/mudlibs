// judge.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("宝官", ({ "judge" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long", "他脸上的表情仿佛是看到了你口袋里的钱一般。\n");
	set("per", 25);
	set("combat_exp", 11500);
	set("attitude", "friendly");
	set_skill("unarmed", 150);
	set_skill("parry", 170);

	set("inquiry", ([
		"赌" : "客官您把钱给我就行了。\n",
]) );
 
	setup();

	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

void init()
{
	object ob;

	::init();
	if( living(ob = previous_object()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom") )
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N冲着$n喊道：这不是穷光蛋来的地方，赶紧滚！\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	switch( random(3) )
	{
		case 0:
			say( CYN"宝官喊道：“快来赌吧，赌全色可是一赔八！”\n"NOR);
			break;
		case 1:
			say( CYN"宝官喊道：“赌场门，两边开，有钱没福别进来！”\n"NOR);
			break;
		case 2:
			say(CYN"宝官喊道：客官里面请，咱们这信誉卓著，全天营业。\n"NOR);
        }
}
