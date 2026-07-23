// baling/edao1
// Room in 巴陵
inherit ROOM;

void create()
{
	set("short", "岔路口");
	set("long", @LONG
你走到一个三岔路口，向北是通向巴陵的大路，向西
你就要进入山西的地界了。
LONG
	);

	set("exits", ([
                "southwest" : __DIR__"edao13",
                "northeast" : __DIR__"edao7",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


