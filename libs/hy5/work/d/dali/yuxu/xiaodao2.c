// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "道旁田野");
	set("long", @LONG
你走在田间野地上，不时的传来鸟鸣声，脚边也跳出许多青蛙之类的小动
物。走在路上，你觉得心况神怡。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([ 
	    "west" : __DIR__"shangang",
	    "east" : __DIR__"xiaodao1",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
