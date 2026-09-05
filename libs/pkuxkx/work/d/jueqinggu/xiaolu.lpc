//绝情谷
// By Zine 

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "小路");
        set("long", 
"这是一条弯弯曲曲的小路，不知通向何方，前方有个山洞。\n"

        );
        
        set("exits", ([
                "northwest" : "/d/saiwai/dajingmen",
                "enter" : __DIR__"xiaolu2",
                
        ]));
        
        set("outdoors", "jueqinggu");
        setup();
   
}
void init()
{
	object me=this_player();
	add_action("do_querypath","querypath");
	if (me->query("jueqinggu/maze")&&!me->query("jueqinggu/recordmaze"))
	{
		me->set("jueqinggu/recordmaze",1);
		message_vision("$N将入谷路线刻在了石壁上。\n",me);
	}
}
int do_querypath()
{
	object me=this_player();
	mapping legal_dir=(["qian":"前","hou":"后","zuo":"左","you":"右"]);
	if (!me->query("jueqinggu/maze")||!arrayp(me->query("jueqinggu/maze"))) return 0;
	tell_object(me,"你刻上的路线是：\n");
	for (int i=0;i<sizeof(me->query("jueqinggu/maze"));i++)
		tell_object(me,legal_dir[me->query("jueqinggu/maze")[i]]+" ");
	tell_object(me,"\n");
	return 1;
}