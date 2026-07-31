
// girl.c

#include <ansi.h>
inherit NPC;
void create()
{
	string *name =({"张","王","赵","李","钱","孙","周","乌","冯","楚"});
        set_name(name[random(sizeof(name))]+"氏", ({ "poor girl","girl" }) );
          set("shen_type",1);
        set("gender", "女性" );
        set("age", 15);
        set("str", 16);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("attitude", "friendly");

        set("long",     "一个普通的农家女，她的背上插着个牌子( sign )。\n");

        set("combat_exp", 1000);

        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
	(:command("say 难道你不怕遭天谴！！") :),
	 }) );

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set_skill("literate", 20);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        return 0;
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "小女孩说道：这位" + RANK_D->query_respect(ob)
				+ "，可怜可怜我吧。。。\n");
	ob->set("marks/杀女",0);
}
void die()
{	int i;
	object ob,room,killer;
	if(objectp(killer= query_temp("last_damage_from")))
      {
		killer->set("marks/杀女",1);
                killer->add("shen",-1000);
                }
	else 	{::die();
		 return ;}
	room=environment(this_object());
	tell_room(room,HIC "突然，电闪雷鸣，几个神兵从天而降。。。\n");
	tell_room(room,"其中一个对着"+killer->query("name")+"喝道：\n");
	tell_room(room,HIR"大胆狂徒，连如此孝顺的柔弱女子也不放过，太过份了！！  给我杀！！\n"NOR);
	tell_object(killer,HIR"你遭天谴了！！！！！\n"NOR);
	for(i=0;i<=5;i++){
		ob=new("/obj/npc/heaven_soldier");
		ob->move(room);
		ob->kill_ob(killer);
		ob->invocation(killer);
			}
	::die();
}
