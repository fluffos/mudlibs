// /d/xiangyang/hunanroad1.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在湘鄂交界的土路上，偶尔会有人骑着马匆匆而过。这里已经是湖南
地界，往北进入湖北境内。
LONG
	);
        set("outdoors", "tiezhang");

	set("exits", ([
	"northup" : "d/xiangyang/caodi6",
      "southwest" : __DIR__"hunanroad2",
	]));

	setup();
	replace_program(ROOM);
}

