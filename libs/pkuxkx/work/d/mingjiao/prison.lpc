#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", WHT"明教水牢"NOR);
        set("long", @LONG 
这里是明教的水牢，专门用来囚禁犯了重罪的明教弟子。
LONG );
        set("no_task",1);
        set("real_dark",1);
        set("exits", ([
                "out" : __DIR__"dadian",
               
 ]));
       /* set("objects", ([
                CLASS_D("mingjiao") + "/zhang" : 1,
 ]));*/
        setup();

}

void init()
{
    add_action("do_none","quit");
    add_action("do_none","chat");
    add_action("do_none","tell");
    add_action("do_none","rumor");
    add_action("do_none","baowei");
    add_action("do_none","mp");
    add_action("do_none","say");
    add_action("do_none","dazuo");
    add_action("do_none","tuna");
    add_action("do_none","lian");
    add_action("do_none","practice");
    add_action("do_none","xiulian");
    add_action("do_none","dz");
}

int do_none()
{
    object me=this_player();
    tell_object(me,"监禁期还没有结束，什么事也不许做！\n");
    return 1;
}


int valid_leave(object me,string dir)
{  
	
    if (dir=="out"&& me->query_temp("mj_canleave"))
    {
        me->delete_temp("mj_canleave");
        return ::valid_leave(me, dir);
    }
    else
    
	return notify_fail("监禁期还没有结束，不准离开！\n");
}