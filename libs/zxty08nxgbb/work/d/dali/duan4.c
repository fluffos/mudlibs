// Room: /d/dali/duan4.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：20时44分7秒。

inherit ROOM;

void create()
{
	set("short", "花厅");
	set("long", @LONG
穿过大厅一旁的走廊，来到了一侧的花厅。厅内陈设华美，雕梁
画栋，极穷巧思，比诸雄伟豪华的殿堂又别有一番气象。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"duan5",
  "north" : __DIR__"duan3",
]));

set("objects", ([
__DIR__"npc/yahuan" : 2,
]));
	setup();
}

