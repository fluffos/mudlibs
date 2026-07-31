// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
这里是一处豪华的卧室，堡内头领居于此处。
LONG
	);
	set("exits", ([
		"south" : __DIR__"room2",
	]));
	if (random(2) == 0) {
		set("jiguan", 1);
		set("item_desc", ([
			"机关" : "一个按钮机关，不知道有什么作用。\n"
			ZJOBACTS2"按钮:anniu jiguan\n",
		]));
	}
	set("objects", ([
		"/d/fuben/npc/hanfei": 2,
		"/d/fuben/npc/hanfeitou": 1,
	]));

	setup();
}

int do_anniu(string arg)
{
	string room;
	object ob;
	object me = this_player();
	object oba, obb;
	object player;
	int ok = 0;
	object *obs = all_inventory();
	
	oba = present("hanfei", environment(me));
	obb = present("hanfei tou", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				tell_object(player, oba->name()+"对你吼道：想干嘛？先过我这关！\n");
				ok = 1;
			}
			if (obb) {
				obb->kill_ob(player);
				player->kill_ob(obb);
				tell_object(player, obb->name()+"对你“嘿嘿”笑道：当我死了么？你乱按什么？\n");
				ok = 1;
			}
		}
	}
	if (ok > 0)
		return 1;
	
	if (!arg || arg != "jiguan") {
		write("乱按什么？！\n");
		return 1;
	}
	if (me->is_busy())
		return notify_fail("你正忙着！\n");
	
	if (query("do_down")) 
		return notify_fail("乱按什么？按钮已经被人按坏了！\n");
	
	if (!query("do_down") && random(5) < 3) {
		room = __DIR__"room4";
		ob  = new(room);
		message_vision("$N用力把机关按钮按下，却听得地板一阵"
							+"“咔嚓~咔嚓~响动，$N回头一看，墙角露出一个向下的通道……。\n"
										+"$N惊讶之下用力过猛，只听“咔嚓”一声，按钮居然被$N按坏了！”\n", me);
		this_object()->set("exits/down", file_name(ob));
		ob->set("exits/up", file_name(this_object()));
		call_out("do_closed", 600, ob);//10分钟后关闭
	} else {
		message_vision("$N用力机关的按钮按下，却听得按钮一阵"
							+"“咔嚓~咔嚓~响动，按钮居然被$N按坏了！”\n", me);
	}
	
	this_object()->set("do_down", 1);
	return 1;
}
void do_closed(object ob)
{	
	if (this_object()) {
		message("vision", "只听地板一阵响动，地面的通道居然自动关闭了！\n", this_object());
		this_object()->delete("exits/down");
	}
	if (ob)
		destruct(ob);
	remove_call_out("do_closed");
}
#include "/d/fuben/room_fb.h"
