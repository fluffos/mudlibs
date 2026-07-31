// Room: /d/yandang/jiedao1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
远远的,前面出现了一个小镇,在早晨的蒙蒙清光中,有几缕炊烟袅
袅的升起来,在路边的一块石碑上,刻着地名'芙蓉镇',这里就是雁荡山
下的唯一小镇了.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/hangzhou/dalu1",
  "north" : __DIR__"jiedao",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
