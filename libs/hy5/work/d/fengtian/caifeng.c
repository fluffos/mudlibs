// Room: /d/fengtian/caifeng.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "裁缝铺");
	set("long", @LONG
这是坐落在盛京东城的一间裁缝铺，这里的老板李姐心灵手
巧、远近闻名，门边立着一块红木牌(sign)。
LONG
	);

	set("night_long", @LONG
这是坐落在盛京东城的一间裁缝铺，这里的老板李姐心灵手
巧、远近闻名，现在已经打烊了。
LONG
	);

	set("item_desc",([
		"sign" : "本店出售各式男女服装，也可量身定(ding)做。\n",
	]));

	set("no_sleep_room",1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ll4",
]));
	set("objects",([
		__DIR__"npc/cloth_li" : 1,
]));

	setup();
}

void open_close_door(string msg,object user)
{
	object ob = present("boss zhang",this_object());

        if(!msg || !user)
                return;
	if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,CYN"李大姐笑盈盈的对你说道：开始营业了！！"+
                        RANK_D->query_respect(user)+"请随便看看。\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
                return;
        }

	else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,CYN"李大姐说道：这位"+
                        RANK_D->query_respect(user)+"对不起，鄙店打烊了，请您明天再来吧。\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"打烊了。\n"NOR);
                return;
        }
}
