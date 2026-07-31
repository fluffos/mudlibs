// Room: /d/linzhi/lin64.c

inherit ROOM;

void create()
{
	set("short", "高原缓坡");
	set("long", @LONG
这里是高原缓坡，海拔虽然很高，但地势已不是很陡。你已
经很久没走过这种舒服的路了，不禁放缓了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin65",
  "southeast" : __DIR__"lin55",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
