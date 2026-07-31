//Cracked by Kafei
// Room: /d/dali/garden1.c

inherit ROOM;

void create()
{
	set("short", "茶花园入口");
	set("long", @LONG
在一堵青色的石墙后面，隐隐可以看到一排排的垂柳，青
石门前站了一个老花匠，鼻中闻到随风漂来的淡淡茶花香味，
心中不禁一阵清明。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/dali/wfdating",
  "enter" : __DIR__"garden2.c",
]));
	set("no_clean_up", 0);
	set("cost", 1);
	set("objects", ([
		__DIR__"npc/chahua" : random(2),
		]));

	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	object me, ob, weapon;
	me=this_player();

	if (arg=="cha" || arg=="chahua" || arg=="all" || arg=="cha hua") {
		if (!objectp(ob=present("cha", environment(me)))) {
			tell_object(me, "这里没什么好品种的茶花值得挖走。\n");
			return 1;
		}
		if (!objectp(weapon=me->query_temp("weapon"))
			|| weapon->query("id")!="huachu") {
			tell_object(me, "你没有称手的工具来移植这株茶花！\n");
			return 1;
		}
		if (random(2)==1) {
			message_vision("$N小心翼翼地用花锄掘出茶花的根，把整株茶花移了起来。\n", me);
			ob->move(me);
		}
		else {
			message_vision("$N急急忙忙地挖茶花，一不小心把根挖断了，好好的一株茶花，完了。\n", me);
			destruct(ob);
		}
		return 1;
	}
	return 0;
}
