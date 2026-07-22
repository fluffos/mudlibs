#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_decide(string arg);
void create()
{
	set("short", HIB "房间" NOR);
	set("long","这是一间小房间，平时没什么人来。\n");

	setup();  
}

void init()
{
	object me = this_player();

	if (!userp(me)) return;
	me->set_temp("caught",1);
	if (!me->query_temp("convinced")) {
	 message_vision("门外一个阴冷的声音道：$N，你决定要断指(duanzhi)或是出来练招(lianzhao)吧。\n",me);
	 message_vision("决定(decide)好了，就告诉我。嘿嘿嘿。\n",me);
	 me->set("eff_qi",me->query("max_qi"));
	 me->set("qi",me->query("max_qi"));
	 me->set("jingli",me->query("eff_jingli"));
	 add_action("do_decide","decide");
	} else {
	 message_vision("士兵告诉$N：$N既然已经降服，就不可再做些有助于汉人的工作了。\n",me);
	 me->move("/d/city/kedian");
	 }
}

int do_decide(string arg)
{
	object me = this_player();
	object ob;
	if (!arg || (arg != "duanzhi" && arg != "lianzhao"))
	   return notify_fail("你的决定是什么？\n");
	if (arg == "duanzhi") {
	   me->add("duanzhi",1);
	   message_vision("$N惨叫一声，晕了过去。\n",me);
	   message_vision("$N被扔了出去，迷糊中听人骂了一句“真没用！”。\n",me);
	   me->unconcious();
	   me->move("/d/city/kedian");
	} else {
	   ob = new(__DIR__"wushi");
	   ob->move(this_object());
	   ob->force_me("hehe");
	   ob->kill_ob(me);
	   ob->set("combat_exp",me->query("combat_exp")*9/10);
	   call_out("leave",70,me);
		remove_action("do_decide", "decide");
	}
	return 1;
}

void leave(object me)
{
	if(!me || !living(me) || me->is_ghost()) return;
	me->move("/d/city/kedian");
	me->clear_condition("ruanjin_poison");
	me->delete_temp("caught");
	message_vision("$N被一个士兵扔了出来。\n",me);
	message_vision("士兵对$N道：“这次就放了你！下次就没那么简单了。\n",me);
}
