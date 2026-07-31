inherit ROOM;

void create()
{
	set("short", "北市");
	set("long", @LONG
贵阳城的北面是商业区，南面是官衙和军队的驻地，被称为南城北
市。街市里人来人往，热闹非凡，丝毫看不出天下大乱的样子。
LONG );

	set("exits", ([
                          "north"      : __DIR__"beimen",
                         "south"      : __DIR__"center",
                         "northwest"      : __DIR__"chaguan",
                         "northeast"      : __DIR__"dangpu",
                         "southwest"      : __DIR__"qianzhuang",
		        "southeast"      : __DIR__"tiejiangpu",
	]));


 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



