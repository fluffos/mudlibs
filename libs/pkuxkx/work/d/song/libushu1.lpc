// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "吏部尚书值房");
	set("long", @LONG
这里是吏部尚书的值房。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","libu");
	set("exits", ([
		"east" : __DIR__+query("yamen")+"court",
	
	]));
	set("objects", ([
          __DIR__"npc/li_shangshu" : 1,
        ])); 
	setup();
}

void init()
{
    add_action("do_daying","daying");
}

int do_daying()
{
    object me=this_player();
    object officer;
    if (!me->query_temp("songtasks/libu/introducer"))
    {
        return 0;
    }
    officer=find_player(me->query_temp("songtasks/libu/introducer"));
    if (!officer||!living(officer)||base_name(environment(officer))!=base_name(environment(me)))
    {
        tell_object(me,"你的引荐人不在场，还是等等吧。\n");
        return 1;
    }
    me->delete_temp("songtasks");
    officer->add("song/credit",5);//额外奖励
    MONEY_D->pay_player(me,100000);
	tell_object(officer,"完成【任用贤能】任务，你被额外奖励了5点大宋功勋度，你现在可以向吏部尚书复命了。\n");
    message_vision("$N静静对答吏部尚书的问话，$n听得暗暗点头。\n",me,officer);
    message_vision("吏部尚书对$N道：“朝廷不能薄待贤士，特赠你黄金十两。”\n",me);
    return 1;
}