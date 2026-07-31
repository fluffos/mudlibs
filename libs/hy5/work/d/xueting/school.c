// Room: /d/snow/school.c

inherit ROOM;

void create()
{
	set("short", "无极书院");
	set("long", @LONG
这里是一间宽敞的书院，虽然房子看起来很老旧了，但是打扫
得很整洁，墙壁上挂著一幅山水画，意境颇为不俗，书院的大门开
在北边，西边有一扇木门通往边厢。
LONG
	);
	
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"wstreet1",
	]));
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/teacher" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
