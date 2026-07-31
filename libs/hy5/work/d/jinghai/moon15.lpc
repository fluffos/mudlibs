// Room: /d/jinghai/moon15.c

inherit ROOM;

void create()
{
	set("short", "兵器仓库");
	set("long", @LONG
这是一间很大的木屋，是水寨的兵器仓库的所在。里面存放
着许多武器只有看守同意的情况下你才可以领取你所需要的武器
。你可不要太贪心啊。多拿了兵器的后果可不是好玩的！
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"moon11",
]));
        set("objects", ([
            __DIR__"obj/changmao"       : 2,
            __DIR__"obj/blade"       : 2,
            __DIR__"obj/sword"       : 2,
        ]));


	setup();
	replace_program(ROOM);
}
