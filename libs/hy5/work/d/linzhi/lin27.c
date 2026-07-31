// Room: /d/linzhi/lin27.c

inherit ROOM;

void create()
{
	set("short", "则玛拉山南平坡");
	set("long", @LONG
你来到则玛拉山的南侧平坡，这里海拔在4200米左右，地势
相对平坦。一个喇嘛迎面走来，头也不抬地与你擦肩而过。好像
前面有家寺庙。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lin26",
  "west" : __DIR__"lin28",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
