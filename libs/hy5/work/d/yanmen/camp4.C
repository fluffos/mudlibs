#pragma save_binary
// ROOM:__DIR__"camp4"

inherit ROOM;
void create()
{
        set("coor",({-250,4240,0}));
	set("short","小兵营帐");
	set("long",
"这里有一大群的小兵，不知道是在做什么，营帐中央有一张桌子，上面堆满了各式各样的赌\n"
"具，小板凳，和茶水。\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/guard1" : 2,
		__DIR__"npc/guard2" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
