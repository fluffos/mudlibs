#pragma save_binary
// ROOM:__DIR__"camp5"

inherit ROOM;
void create()
{
        set("coor",({-240,4260,0}));
	set("short","小队长营帐");
	set("long",
"这里是小队长的营帐，四周仍旧和小兵营帐一样的空旷，但营帐的布料倒是比小兵营帐好多\n"
"了，北侧有两把凉椅，看来定是小队长偷懒时休息的地方。\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"south" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/leader1" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
