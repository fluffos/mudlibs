// guiyunzhuang/zoulang4走廊
// Made By:pingpang
#include <ansi.h>    
inherit ROOM;

void create()
{
         set("short", "走廊");
        set("long", @LONG
这里是归云庄的长廊，里面不时地穿梭着庄里的仆人。
LONG);
         set("exits", ([ /* sizeof() == 3*/
         "north" : __DIR__"dating",
         "south" : __DIR__"shufang",
	"west" : __DIR__"danfang",
	 "east"  : __DIR__"mafang",
                  ]));
	set("objects",([__DIR__"npc/zongguan":1,]));
	setup();
}
int valid_leave(object me,string dir)
{
        object room;
    if (dir=="south"&&me->query("thnewbiejob/jianding/start")
        &&objectp(present("zong guan",environment(me)))
	    &&living(present("zong guan",environment(me))))
    {
        
        tell_object(me,"总管看了看你，侧身让开了路，你进到了庄主书房。\n");
        me->move(__DIR__"shufang");
        return notify_fail("");
    }
    if (dir=="south"&&me->query("combat_exp")<10000
        &&me->query("family/family_name") == "桃花岛"
        &&objectp(present("zong guan",environment(me)))
	    &&living(present("zong guan",environment(me))))
    {
        
        tell_object(me,"总管看了看你，道：“新来的啊，还是多去读读奇门八卦的书吧，在书房找(zhao)一找吧。”\n");
        me->move(__DIR__"shufang");
        return notify_fail("");
    }
	if(dir=="south"&&objectp(present("zong guan",environment(me)))
	    &&living(present("zong guan",environment(me))))
	return notify_fail("总管大喝:那边是我家老爷的私人书房，请留步.\n");
        if ( dir != "east" ) return 1;
        if( objectp(room = find_object("/d/guiyunzhuang/mafang")))
        if ( me->query("family/family_name") == "桃花岛" ) {
                if ( me->query_skill("dodge", 1) < 150 )
                        return 1;
                tell_object(me, HIC "御马翁对你说道：“你的轻功已经这么高了，还来这里做什么？”" NOR);
                return notify_fail("");
        }
        tell_object(me, HIC "你被御马翁赶了出来，好尴尬的样子。\n" NOR);
        return notify_fail("");

}
