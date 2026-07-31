//Cracked by Kafei
// Room: /d/dali/garden2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"茶花园"NOR);
	set("long", @LONG
这花园在水边一排垂柳之后，一丛丛花树映水而红，灿若
云霞。一眼望去，都是红白缤纷的茶花，但似乎胡乱生长，并
无佳品。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"garden3.c",
  "out" : __DIR__"garden1.c",
  "northwest" : __DIR__"garden4.c",
]));
	set("objects", ([
		__DIR__"npc/chahua" : random(2),
		]));

	set("no_clean_up", 0);
	set("cost", 1);

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
