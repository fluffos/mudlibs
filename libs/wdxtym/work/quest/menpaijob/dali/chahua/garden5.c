//Cracked by Kafei
// Room: /d/dali/garden5.c

inherit ROOM;
int do_get(string arg);
#include <ansi.h>

void create()
{
	set("short", MAG"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : MAG"风尘三侠
风尘三侠，有正品和副品之分，凡是正品，三朵花中必须紫色
者最大，那是虬髯可，白色者次之，那是李靖，红色者最小且最娇
艳，那是红拂女。如果红花大过了紫花白花，那便是副品了，身份
就差得多了。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"garden3",
  "north" : __DIR__"garden6",
  "southwest" : __DIR__"garden4",
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