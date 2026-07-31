//Cracked by Kafei
// Room: /d/dali/garden8.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : HIR"眼儿媚
一本白花，花瓣儿上有两个橄榄核儿状黑斑的，叫作“眼儿
媚”，那两个黑斑，便好似美人儿的媚眼。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"garden9",
  "east" : __DIR__"garden6",
]));
	set("no_clean_up", 0);
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
