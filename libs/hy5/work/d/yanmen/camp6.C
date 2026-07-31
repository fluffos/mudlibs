#pragma save_binary
// ROOM:__DIR__"camp6"

inherit ROOM;
void create()
{
        set("coor",({-240,4240,0}));
	set("short","小队长营帐");
	set("long",
"类似北边的营帐，空空荡荡的，看起来一点也不像是军营，一点威武的感觉也没有，在这也\n"
"有两把简易的凉椅，两位队长，平常小兵没有尢许是不能擅自进入这里的，向东北是副将营\n"
"帐，但没有经过「允许」是不得进入的。\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/captain" : 1,
		__DIR__"npc/leader2" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
