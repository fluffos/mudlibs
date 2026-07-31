// Room: /d/fengtian/jiulou.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "浮华酒楼");
	set("long", @LONG
浮华酒楼是盛京城内一家最新也是最大的酒楼，近年战乱很
少，自然商业就发达，浮华酒楼选在李林街开张也是因为这里越
来越繁华了。
LONG
	);
	set("night_long", @LONG
浮华酒楼是盛京城内一家最新也是最大的酒楼，现在已经打
烊了，跑堂的没精打采的趴在柜台上。
LONG
        );

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ll4",
  "west" : __DIR__"jiulou2",
]));

	
	set("valid_startroom", 1);

	set("objects",([
	__DIR__"npc/paotang" : 1,
]));

	setup();
	//load_board("board_fengtian");
}

void open_close_door(string msg,object user)
{
        object ob = present("pao tang",this_object());

        if(!msg || !user)
                return;
        if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,CYN"酒楼跑堂笑盈盈的对你说道：酒楼开始营业了！！"+
                        RANK_D->query_respect(user)+"请随意。\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
                return;
        }

        else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,CYN"酒楼跑堂说道：这位"+
                        RANK_D->query_respect(user)+"对不起，小号打烊了，请您明天再来吧。\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"打烊了。\n"NOR);
                return;
        }
}
