// Room: /d/tianshui/chaguan.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "碧螺茶馆");
	set("long", @LONG
虽说这里桌椅简陋，但一阵阵沁人心脾的茶香扑鼻而来，使
人精神为之一爽。里面坐满了客人，有的高谈阔论，有的交头接
耳。要想打听什么事情，看来这里最合适。
LONG
	);
        set("night_long", @LONG
这里已经打烊了。茶堂上空空的，只有桌椅呆在那。茶师正
伏在角落的一张桌子上睡着，听到有人进来，赶紧站了起来。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"sroad1",
]));

	
        set("no_sleep_room",1);

        set("objects",([
        __DIR__"npc/teaboss" : 1,
]));

	setup();
}

void open_close_door(string msg,object user)
{
        object ob = present("tea boss",this_object());
 
        if(!msg || !user)
                return;
        if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,CYN"茶师笑盈盈的对你说道：客官请进坐，现在营业了！！"+
                        RANK_D->query_respect(user)+"请随意。\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
                return;
        }

        else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,CYN"茶师点头哈腰地说道：这位"+
                        RANK_D->query_respect(user)+"对不起，小号打烊了，请您明儿个再来吧。\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"打烊了。\n"NOR);
                return;
        }
}
