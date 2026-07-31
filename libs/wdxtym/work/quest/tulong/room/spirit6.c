inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "龙潭入口");
        set("long", HIG @LONG  
前方就是龙潭，进去前请三思。如果到此止步，还来得及。如要
回头，请键入back。在西面，有一个向下的通道，看来似乎相当深。
LONG);

        set("exits", ([ 
              "north" : "/quest/tulong/room/dragoncave", 
              "westdown" : "/quest/tulong/room/spirit7", 
           ]));

        setup();
}

void init()
{
        add_action("do_back", "back");
}

int do_back(object me)
{
        me=this_player();
        message_vision(HIC"$N的身影消失在一阵光芒中。\n"NOR,me); 
        me->set_temp("mark/diary", 0);
        me->set_temp("m_success/初级",0);  
        me->set_temp("m_success/幻影",0);  
        me->set_temp("m_success/孽龙",0);  
        me->move("/d/city/wumiao");
        return 1;
}

