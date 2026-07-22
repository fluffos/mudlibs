// houshanxl3.c
// 后山小路
inherit ROOM;
#include <ansi.h>

int do_kan(string arg);

void create()
{
        set("short", HIG "后山小路" NOR);
        set("long", @long
这里虽说是小路，但周围除了不高的小树，就是绊脚的灌木，很难再找到
下山的路了。
long);
	set("outdoors", "峨眉山");
	set("exits",([
		"southup":__DIR__"houshansl",
		"northdown":__DIR__"houshanxl4",
	]));
	set("objects",([
		__DIR__"obj/axe" : 1,
	]));
        setup();
}

void init()
{
	add_action("do_kan", ({"kan", "cut"}));
}

int do_kan(string arg)
{
	object weapon, me=this_player();
	if (!arg && arg != "灌木丛" && arg != "灌木" && arg != "guanmu" && arg != "cong")
		return notify_fail("你要砍什么？\n");
	if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("flag") != 4 )
		return notify_fail("你拿什么砍？\n");
	message_vision("$N拿起"+weapon->name()+"对着灌木丛砍了起来，一转眼就钻了进去。\n", me);
	me->receive_damage("jingli", random(200) );
	me->set_temp("last_damage_from", "在灌木丛里筋疲力尽累");
	me->move(__DIR__"houshangm");
	return 1;
}
