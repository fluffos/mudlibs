#pragma save_binary
// ROOM:__DIR__"camp7"

inherit ROOM;
void create()
{
        set("coor",({-230,4250,0}));
	set("short","副将营帐");
	set("long",
"来到这里，看了四周的景像真会令人不敢相信，和前面的军营竟大不相同，虎皮披于军椅，\n"
"银器列于黑刚曜石桌上，爵为金缘双虎抱图，北侧挂著刀、剑、杖，地面上有羊毛软皮铺陈\n"
"著，确实有副将营帐的味道。\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
		"east" : __DIR__"camp8",
		"west" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/vice_general" : 1,
	]) );
	
	setup();
	
}

int valid_leave(object me,string dir)
{
	if ( dir=="east" && !(string)me->query("marks/军营") )
        return notify_fail("你还没被允许\进入喔。\n");
	
	return ::valid_leave(me,dir);
}
