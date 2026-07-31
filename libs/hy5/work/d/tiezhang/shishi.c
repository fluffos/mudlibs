// Room: /u/zqb/tiezhang/shishi.c

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
      这是一间在山腹中凿成的小石屋，中间有一座石桌，桌上摆放着 
一盏油灯，散发出暗淡昏黄的光亮。屋内一角的地上，铺着很多干草，上面
坐着一个人。长发垂下，遮去面容，看不出多大年纪，身上穿着一件又脏又 
破的黑衣，说不出的诡异神秘。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"shijie-3",
]));
    set("objects", ([
        __DIR__"npc/sgjn" : 1,
    ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
