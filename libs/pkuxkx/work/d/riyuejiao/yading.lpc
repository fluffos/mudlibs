//yading.c	黑木崖顶
//by bing
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","黑木崖");
	set("long",@LONG 
迎面一座汉白玉的巨大牌楼，牌楼上四个金色大字「泽被苍生」，在阳光下发出闪闪金光，
不由得令人肃然起敬。前方是一座巍峨的大殿，气势十分宏伟。这副排场，武林中确是无人能
及。这里地势很高，寒风阵阵，凛冽刺骨。悬崖边上吊着一个大竹篓(zhu lou)。
LONG
	);
	set("exits", ([
		"east"	: __DIR__"wanghaishi",
		"west"	: __DIR__"xiuxishi",
		"north"	: __DIR__"chengde",
        "south" : __DIR__"prison_entry",
	]));
    set("valid_startroom", 1);
	set("objects", ([
               CLASS_D("riyuejiao") + "/jiabu" : 1,
                __DIR__"npc/jiaozhong4": 3,
        ]));
	set("item_desc",([
  	"zhu lou" : "这是一个竹子编成的大篓，大概可以装得下一个人，上面连着一根粗绳子。",
  	"lou" : "这是一个竹子编成的大篓，大概可以装得下一个人，上面连着一根粗绳子。", 	   ]));

	set("outdoors", "riyuejiao");
	setup();
}

void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me = this_player();
	object room;
	if(!( room = find_object(__DIR__"lounei2")) )
        room = load_object(__DIR__"lounei2");
	
	if (!arg || (arg != "zhu lou" && arg != "lou"))
		return notify_fail("你要进哪里？\n");
	if (((int)room->query_temp("无人"))==1)
                return notify_fail("竹篓里已经有人了，盛不下你。\n");
	message_vision("$N走进竹篓内，旁边的日月教众摇动轱辘，竹篓慢慢的降了下去。\n",me);
	me->move(__DIR__"lounei2");
	room->set_temp("无人",1);
	call_out("lou2",1);
	call_out("godown",4,me);
	return 1;
}

int me_in(object me)
{
    if (!me)
    {
        return 0;
    }
    if (!environment(me))
    {
        return 0;
    }
    if (!environment(me)->query("ry_lou_2"))
    {
        return 0;
    }
    return 1;
}
int godown(object me)
{
	object room;
	if(!( room = find_object(__DIR__"lounei2")) )
        room = load_object(__DIR__"lounei2");
	add("number",1);
	if (query("number") < 4)
	{
        if (me_in(me))
        {
            message_vision("竹篓慢慢下降，片片白云从你身旁飘过。\n",me);
            call_out("godown",4,me);
            return 1;
        }
		else
        {
            room->set_temp("无人",0);
	        set("number",0);
	        return 1;
        }
	}

	
    if (me_in(me))
    {
        message_vision("只觉得竹篓一震，原来已经到了崖下。\n",me);
	    tell_room(__DIR__"yaxia","只一个竹篓慢慢降下来，里面站着" + me->query("name") + "。\n");
        me->move(__DIR__"yaxia");
        message_vision("$N定了定神，走了出来。\n",me);
	    message_vision("竹篓又慢慢地升上去了。\n",me);	
    }	
	room->set_temp("无人",0);
	set("number",0);
	return 1;
}



void lou2()
{
	tell_room(__DIR__"yading","过了不久，又一个竹篓由下面缓缓吊上来。\n");
}

int valid_leave(object me,string dir)
{
    if (dir=="south"&&me->query("family/family_name")!="日月神教")
    {
        return notify_fail("神教的监狱，岂是可以擅闯的？\n");
    }
    return ::valid_leave(me,dir);
}