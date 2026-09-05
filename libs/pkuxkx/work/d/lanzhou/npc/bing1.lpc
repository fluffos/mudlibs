inherit NPC;
#include <ansi.h>
int xunluo()
{
	string * rooms;
	object room;
	if (query("xunluo"))//左
	{
		rooms=({"cishi","north_avenue1","north_avenue2","guoshi","west_street2","west_street1"});
	}
	else
	{
		rooms=({"zuru","north_avenue1","north_avenue2","jiangjun","east_street2","east_street1"});
	}
	if (query("step")>=sizeof(rooms))
	{
		if (query("leader"))
		message_vision("$N巡逻完成，带领着属下士兵回营地休息了。\n",this_object());
		destruct(this_object());
		return 1;
	}
	room=load_object("/d/lanzhou/"+rooms[query("step")]);
	set("target",room);
	if (query("leader"))
	{
		message_vision(HBBLU+HIR+"$N带领着一队士兵向着"+room->query("short")+HBBLU+HIR+"方向巡弋。\n"NOR,this_object());
		tell_room(room,HBBLU+HIR+query("name")+"带领着一队士兵巡弋过来。\n"+NOR);
	}
	move(room);
	add("step",1);
	remove_call_out("xunluo");
	call_out("xunluo",7);
	return 1;
}
int dest()
{
	if (this_object())
	destruct(this_object());
}
void create()
{
	set_name("巡城士兵", ({ "shi bing", "bing", }));
	set("str", 20);
	set("gender", "男性");
	set("age", 20+random(10));
	set("long", "他是一名西夏的巡城士兵，威武精悍。\n");
	set("combat_exp", 250000);
	set("attitude", "friendly");
    set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 80);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	set("shen_type",-1);set("score",200);setup();
	call_out("xunluo",1);
	carry_object("/clone/armor/tiejia")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	call_out("dest",100);
}
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("xixia_killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 袭击巡城军士者死！\n");
	me->apply_condition("xixia_killer", 60);
	kill_ob(me);
	return 1;
}