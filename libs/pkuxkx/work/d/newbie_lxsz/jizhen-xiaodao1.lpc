// D:\xkx\d\liuxiu-shanzhuang\jizhen-xiaodao1.c集镇小道1
// labaz  2012/10/21.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

int do_go(string);
int do_west();

void create()
{
    set("short", "集镇小道");
    set("long", @LONG
这里是个并不繁荣，却显得极为安详的小镇，每一个人脸上都挂着没有
忧愁的笑容。路旁有垂柳，垂柳后有几间民房，风将路人的快乐透过
纸窗吹入进来又吹散开去，纸窗和门随着柳条的舞动开开阖阖。东南边
酒铺的喧闹声时时传来，而东北边的药铺则有药香传来，显得安静多了。
小道上偶尔有三三两两的江湖豪客经过。
LONG);

    set("outdoors","liuxiu-shanzhuang");



    set("exits", ([
        "southeast" : __DIR__"jiupu",
        "northeast" : __DIR__"yaopu",
        "west" : __DIR__"xingzilin",
        "south" : __DIR__"huanpo",
        "north" : __DIR__"jizhen-xiaodao2",
        ])
     );

    setup();
}

void init()
{
	add_action("show_quest","quest");
    add_action("do_go","go");
	add_action("do_west","west");
}

int do_west()
{
	return do_go("west");
}

int do_go(string arg)
{
    object who,xingzilin_fb;
    who=this_player();
    
    if (("west" == arg) && ( 1==check_questindex(who,"去杏子林和游鲲翼道别") ))
    {
        if (!objectp(xingzilin_fb=who->query_temp("newbie/xingzilin_room")))
        {
            xingzilin_fb=new(__DIR__"xingzilin_fb");
            if (xingzilin_fb) who->set_temp("newbie/xingzilin_room",xingzilin_fb);
            who->move(xingzilin_fb);
        }
        else
        {
            who->move(xingzilin_fb);
        }
        return 1;
    }
    
    return 0;
}

