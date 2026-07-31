#pragma save_binary
// ROOM:__DIR__"camp8"

inherit ROOM;
void create()
{
        set("coor",({-220,4250,0}));
	set("short","将军营帐");
	set("long",
"虎头挂于营顶，虎皮披于帐上，威武无比，帐中龙柱顶天，双龙吐珠图挂于前，严然有天子\n"
"之势，金椅银桌，里、簋、爵、角、鉴，样样俱全，一磬、一鼓、一笙、一笛、一萧，文墨\n"
"章笔擎于旁，将军在上，参谋在右，由不得令人生畏。\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
        	"west" : __DIR__"camp7",
        	"east" : __DIR__"blackmarket",	
	"north" : "/d/tieflag/dreamland/shanpo",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/general" : 1,
		__DIR__"npc/adviser" : 1,
	]) );
	
	setup();
	
} //EOF
int valid_leave(object me, string dir)
{


	if ( objectp(present("master general", environment(me))) && 
		dir == "east")
		return notify_fail("严廷殷拦住了你的去路。\n");


	return ::valid_leave(me, dir);
}
       