// Room: /d/jinghai/jhd17.c

inherit ROOM;

void create()
{
	set("short", "阅兵场");
	set("long", @LONG
这里是靖海公府的阅兵场，大部份各地的靖海兵丁都要在这
里接受军队的训练。现在正有一批新兵在接受陆上攻防训练。这
里也是靖海公一年一度大阅兵的地方，青石铺就的操场被新兵们
踏得光滑无比，南面是一个大厅，再往西走就是公府的书房。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jhd11",
  "west" : __DIR__"jhd19",
  "south" : __DIR__"jhd16",
]));
        set("objects",([
        __DIR__"npc/shuishou" : 4,
        __DIR__"npc/jiading" : 4,
]));

        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
