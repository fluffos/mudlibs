// D:\xkx\d\liuxiu-shanzhuang\xingzilin.c杏子林
// labaz  2012/10/21.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

int do_chat(string);
void create()
{
    set("short", "杏子林");
    set("long", @LONG
一阵风来，正是“风过吹斜阳”的景。杏叶已成片泛黄，整个杏子
林，像是泼洒上一片橙橙的黄墨。你不难想到，如果时逢春风小
渡，杏花醉红，成片成片的杏花海，是怎样的景象，夏日又会是
怎样绿树成荫的繁茂。此时的枯黄，大概正是英雄迟暮的景了。
若是你细心看去，一些杏树下有一些零散的脚印。
杏林中有一条因马车常年驶过而留下的车辙痕迹，向西延伸通向
扬州。而这些车辙印记则来自于杏子林南边的车马行。
LONG);

    set("outdoors","liuxiu-shanzhuang");

    set("exits", ([
        "east" : __DIR__"jizhen-xiaodao1",
        "south" : __DIR__"chemahang",
        ])
     );

	set("objects", ([
		__DIR__"npc/youkunyi_fb" : 1,
	]));

    setup();
}

void init()
{
	add_action("show_quest","quest");
    add_action("do_chat","chat*");
}

int do_chat(string arg)
{
    object who,money,book;
    who=this_player();
    
    if ((arg=="bye you" || arg=="bye you kunyi") && 1==check_questindex(who,"去杏子林和游鲲翼道别"))
    {
        set_nextquest(who,"去杏子林和游鲲翼道别","去车马行坐车到扬州开始你的江湖路吧！", 50, 250);
        tell_object(who,"游鲲翼双手奉上一本《江湖宝典》，你收了下来。\n");

        book=new(__DIR__"obj/jianghubaodian");
        book->move(who);
    }
    return 0;
}

int valid_leave(object who,string dir)
{
    if ("east"==dir)
    {
        return notify_fail("你去意已决，就不必再回去了吧。\n");
    }
    if ("south"==dir && 1==check_questindex(who,"去杏子林和游鲲翼道别"))
    {
        return notify_fail("这几日，游鲲翼待你甚好，今日一别，不知何时再见，跟人打个招呼就走吧，免得红着眼圈，怪不像样的。\n"+HIC"请输入chat* bye you\n"NOR);
    }
    return ::valid_leave(who,dir);
}



