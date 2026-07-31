// Room: /d/yanjing/inroom.c

inherit ROOM;

void create()
{
	set("short", "小屋中");
	set("long", @LONG
举目所及,桌凳之物都是粗木所制,床帐用具无一不是如同民间农家
之物,甚是粗糙简陋,壁上挂着一根生了锈的铁枪,一张残破了的犁头,屋子
一角放着一架纺纱用的旧纺车.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/baoxiruo.c" : 1,
//  __DIR__"npc/clone/clothtieli.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"gardon",
]));

	setup();
	replace_program(ROOM);
}
