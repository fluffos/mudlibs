// Room: /d/linzhi/lin28.c

inherit ROOM;

void create()
{
	set("short", "则玛拉山南平坡");
	set("long", @LONG
你来到则玛拉山的南侧平坡，这里海拔在4200米左右，地势
相对平坦。一个喇嘛迎面走来，头也不抬地与你擦肩而过。你抬
头看去，只见南面有家寺庙。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin27",
  "south" : __DIR__"rqb_temple",
]));

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/man" : 2,
  __DIR__"npc/lama" : 1,
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
