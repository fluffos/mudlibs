// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
int desc(object me);
void create()
{
        set("short", HIG"中心广场"NOR);
        set("long", "这里是昆明城的城中心，鲜花遍地。\n");
        set("exits", ([
               "west" : __DIR__"weststreet",
               "south" : __DIR__"southstreet",
               "north" : __DIR__"northstreet",
               "east" : __DIR__"eaststreet",
               
                
        ]));
        
        set("outdoors", "kunming");
        setup();
   
}
int open(object me)
{
	set("owner",me);
	desc(me);
}
int desc(object me)
{
	set("long","这里是昆明城的城中心，已不似往日景象，帅府高高挂起了"+HIR+COLOR_D->uncolor(me->query("name"))[0..1]+NOR+"字帅旗。\n");
	delete_temp("mixed_long");
	set("exits/enter","/d/song/shuaifu");
	call_out("close",180);
}
int close()
{
	object pl;
	if (!pl=query("owner")||!pl->query_temp("songtasks/nanzheng/general_sign"))
	{
		if (pl&&objectp(pl))
		tell_object(pl,"因为迟迟不赴任，你被取消了南征主帅资格。\n");
		delete("owner");
	}
}
int redesc()
{
	set("long", "这里是昆明城的城中心，鲜花遍地。\n");
	delete_temp("mixed_long");
}

int valid_leave(object me,string dir)
{
	if (!me->query("song/pro")&&dir=="enter") return notify_fail(RED+"未得准许，不得擅闯帅府。\n"+NOR);
	return ::valid_leave(me,dir);
}