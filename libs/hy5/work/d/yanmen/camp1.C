// ROOM:__DIR__"camp1"

inherit ROOM;
void create()
{
        set("coor",({-250,4250,0}));
	set("short","军营入口");
	set("long",
"此处为黄石隘口驻军的入口，东方为军队饮食的地方，在门口的两侧有两位小兵正在值勤。\n"
"南、北两侧为小兵的营帐。\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==4 */
		"west" : __DIR__"canyon4",
        	"north" : __DIR__"camp3",
        	"south" : __DIR__"camp4",
        	"east" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/door_guard" : 5,
	]) );
	
        set("outdoors","yanmen");
	setup();
	
	replace_program(ROOM);
} //EOF
