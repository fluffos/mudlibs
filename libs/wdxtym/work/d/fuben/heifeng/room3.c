// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
这里是黑风寨卧室，土匪头领便居于此处。
LONG
	);
	set("exits", ([
		"south" : __DIR__"room2",
		"down" : __DIR__"room4",
	]));
	set("item_desc", ([
		"字画" : "这是一幅土匪们收藏的字画，你好像看到画像背后有一个按钮。\n"
		ZJOBACTS2"按钮:anniu picture\n",
	]));
	set("objects", ([
		"/d/fuben/npc/tufei": 2,
		"/d/fuben/npc/tufeitou": 1,
		"/d/fuben/obj/baoxiang": 1,
	]));
	set("anniu_hide", 1);
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
	
	oba = present("tu fei", environment(me));
	obb = present("tufei tou", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				tell_object(player, oba->name()+"对你大吼道：活得不耐烦了？敢在大爷面前乱来！\n");
				ok = 1;
			}
			if (obb) {
				obb->kill_ob(player);
				player->kill_ob(obb);
				tell_object(player, obb->name()+"对你大吼道：想在我这里乱按？我看你是找死！\n");
				ok = 1;
			}
		}
	}
	if (ok > 0)
		return 1;
	
	if (!arg || arg != "picture") {
		write("乱按什么？！\n");
		return 1;
	}
	if (me->is_busy())
		return notify_fail("你正忙着！\n");
	
	if (query("do_down")) 
		return notify_fail("乱按什么？按钮已经被人按坏了！\n");
	
	if (!query("do_down") && random(50) > 3) {
		room = this_object()->query("bei_path");
		ob  = find_object(room);
		message_vision("$N用力把字画背后的按钮按下，却听得地板一阵"
							+"“咔嚓~咔嚓~响动，$N回头一看，墙角露出一个向下的通道……。\n"
										+"$N惊讶之下用力过猛，只听“咔嚓”一声，按钮居然被$N按坏了！”\n", me);
		this_object()->set("exits/down", file_name(ob));
		call_out("do_closed", 600, ob);//10分钟后关闭
	} else {
		message_vision("$N用力把字画背后的按钮按下，却听得按钮一阵"
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
