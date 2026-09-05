// milin3.c 密林
// seagate@pkuxkx 路径动态更新
#include <ansi.h>
inherit ROOM;
inherit F_VIRTUAL;

void create()
{
	set("short", "小木屋");
	set("long", 
"小树林中间不知道那位猎人建了一座小木屋，虽然有些破旧，但是好歹能够抵挡风雨！\n"
	);
	
  set("outdoors", "hydmaze");	
	setup();
}

void init()
{
	tell_object(this_player(), HIY"小木屋的盗宝人请最后杀。\n"NOR);
	if ( !query("exits/out") && 
		   userp(this_player()) &&
		   this_player()->query_temp("yidao/from") )
	{
		set("exits/out", this_player()->query_temp("yidao/from"));
		delete("realmap");
	}
}

int valid_leave(object me,string dir)
{
	object ob;
	
	ob=me->query_temp("yidao/maze");
	if ( objectp(ob) && dir=="out" )
	{
		ob->set("vtime",0);
		ob->set("dtime",time());
		call_out("clean_maze", 1, ob );
	}
	
	return ::valid_leave(me, dir);
}

void clean_maze(object ob)
{
	ob->delete("owner");
	ob->virtualRoomDestruct(ob->query("froom"));
}