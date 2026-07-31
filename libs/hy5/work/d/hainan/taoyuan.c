// Room: /d/hainan/taoyuan.c

inherit ROOM;

void create()
{
	set("short", "海南桃园");
	set("long", @LONG
这里的景色实在是太美了，到处都是野花野草，阵阵花香
飘来。你不禁想倒在地上睡一小会儿。。。那边有只仙鹤在叫
着，好象在招呼你。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"mishi",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xianhe" : 1,
]));
//set("no_fight",1);
set("no_magic",1);

	setup();
	replace_program(ROOM);
}
