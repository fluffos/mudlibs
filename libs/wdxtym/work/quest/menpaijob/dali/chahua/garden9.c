//Cracked by Kafei
// Room: /d/dali/garden9.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);

	set("item_desc", ([
		"flower" : RED"抓破美人脸
白瓣而洒红斑的，叫作“红妆素裹”，百瓣而有一抹绿晕，一
丝红条的叫作“抓破美人脸”。但红丝多了，便是“倚榄娇”了。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("objects", ([
		__DIR__"npc/chahua" : random(2),
		]));

	set("exits", ([
		"south" : __DIR__"garden8",
		]));

	set("valid_startroom", 1);

    setup();
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
