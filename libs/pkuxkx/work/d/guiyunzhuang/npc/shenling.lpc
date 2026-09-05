// shenling.c
//Made By:pingpang
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("神灵", ({ "shen ling", "shen","ling" }) );
	set("nickname",GRN"天神"NOR+YEL"下凡"NOR);

	set("gender", "男性" );
	set("age", 63);
	set("long", 
"他身影轻巧,灵气逼人,凡人难以接近.\n"
"他是[玉皇大帝]派来的守护神。\n");
	set("combat_exp", 500000);

        set("str", 35);
        set("dex", 30);
        set("con", 39);
        set("int", 34);
	set("shen_type", 1);

        set("attitude", "friendly");
        set_skill("dodge", 170);
	set_skill("unarmed",300);
	set_skill("parry", 160);
        set_skill("force", 140);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
	set("chat_chance_combat",100);
	setup();
	set("chat_chance",4);
	set("chat_msg",({HIG"我受[玉皇大帝]之托，前来人间看守宝库。\n"NOR,}));
        carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
	object ob;
	ob=this_player();
}
int accept_fight(object ob)
{
	command("say 竟敢袭击本神，去死吧.\n");
	ob->unconcious();
	return 1;
}

int accept_object(object who, object ob)
{	
	object room;

if ((string)ob->query("id")=="shouyin"){
			write(
RED"神灵说道：壮士，真是有缘人啊!你可以进去了。\n"NOR
RED"神灵凌空一指，变出了一个出口。\n"NOR);
			if(!(room=find_object("/d/guiyunzhuang/rukou")))
				room=load_object("/d/guiyunzhuang/rukou");
			room->set("exits/south","/d/guiyunzhuang/mihun");
			remove_call_out("close_door");
			call_out("close_door",8,room);
			call_out("dest",1,ob);		
			return 1;}
		return 0;
}
void close_door(object room)
{
	message("vision",YEL"\n神灵凌空一指，刚出现的出口消失了。\n"NOR,room);
	room->delete("exits/south");
}
void dest(object ob)
{
	destruct(ob);
	return;
}
void unconcious()
{
}
