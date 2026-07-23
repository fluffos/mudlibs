//Room:/d/lingshedao/shanyao.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "山腰");
        set("long", @LONG
你气喘吁吁的爬到了山腰,隐隐的看到山顶上似乎有户人家,可是
又不清晰.远处峰回路转,忽明忽灭,尽在云雾之中.东面似乎有条
下山的路.
LONG );        
        set("exits", ([
                "eastdown"    : __DIR__"lsroad4",
                "northup"  : __DIR__"migong1",
                "southdown" : __DIR__"lsroad3",
        ]));
        
        set("no_clean_up",0);
        set("outdoors","lingshedao");           
        setup();
}

void init()
{
        object ob;
        ob=this_player();       if(environment(ob)!=environment())
        message_vision(HIB"\n突然你猛听得山顶上传来一声大叫，中气充沛,
\n极是威猛,你心中不由一震:是谁有如此深厚之内力?\n"NOR,ob);
        else
        return;
}
