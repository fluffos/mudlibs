// Room: /d/dali/duan6.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：20时44分10秒。

inherit ROOM;

void create()
{
	set("short", "小亭");
	set("long", @LONG
这里是王府一角的一个小亭，从这里可以看到远处的群山，
放眼但见山青水绿，天蓝云苍，夕阳橙黄，晚霞桃红，真是一个
纳凉赏景的好地方。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"duan8",
  "northwest" : __DIR__"duan5",
  "east" : __DIR__"duan7",
]));

        set("objects", ([
        __DIR__"npc/jiading" : 2,
]));

	setup();
}

