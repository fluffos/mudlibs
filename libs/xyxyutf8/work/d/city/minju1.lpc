#include <ansi.h> 
inherit ROOM;

void create ()
{
        set ("short", "民居");
        set ("long", @LONG

这是一户长安城里普普通通的民宅，小夫妇俩朴实勤劳，因此，家境
虽然说不上富裕，但也丰衣足食。屋中并没有什么好的摆设，木桌上
的玻璃瓶中插了几朵野花。
LONG);

        set("exits", ([
		"west" : __DIR__"beiyin1",
        ]));
        set("objects", ([
                __DIR__"npc/dog" : 1,
		__DIR__"npc/girl" : 1,
		__DIR__"npc/liyu" : 1,
		"/d/eastway/npc/man" : 1,
        ]));
	set("no_clean_up", 0);
        setup();
}

int valid_leave(object who,string dir)
{
	if( !wizardp(who) )
	{
		if( who->query_level()<10 
		 || who->query_level()>25 )
		 	return ::valid_leave(who,dir);
	}	 	
	if( dir!="west" )
		return ::valid_leave(who,dir);
	if( !who->query_temp("pending/beiyin_ok") )
		return ::valid_leave(who,dir);
	if( time()<who->query("maze/beiyin")+1800 )	
	 	return ::valid_leave(who,dir);
	who->delete_temp("maze");
	if( MAZE_D->enter_maze(who, "beiyin") )	
	{
		who->set_temp("maze/beiyin",1);
        	who->set("maze/beiyin",time());
        	who->delete_temp("pending");
        	message_vision("李玉娘跟随你一起出来。\n",who);
        	message_vision(CYN"李玉娘说道：奴家带了些丹药过来，不过你得向我购买(buy)。\n"NOR,who);
        	return 2;
	}
	return ::valid_leave(who,dir);
}