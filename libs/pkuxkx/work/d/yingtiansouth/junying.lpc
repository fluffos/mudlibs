//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "亲军营"NOR);
        set("long", 
"这里是建康府的都统制府亲军的军营。\n"

        );
        set("exits", ([
                
                "northwest" : __DIR__"dufu/jimashi",
               // "east" : __DIR__"citywall",
               // "south" : __DIR__"guandaosa",
                "south" : __DIR__"zhengyang",
                
        ]));
        set("objects", ([
		__DIR__"npc/bing" : 2,
        //"/d/city/npc/bing" : 2,
        
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}
string GiveMyArea()
{
	return "建康府南城";
}
void init()
{
	int count=0;
	object bing,*inv=all_inventory(this_object());
	for (int i=0;i<sizeof(inv);i++)
	if (inv[i]->query("is_DFQJ"))
	count+=1;
	if (count>=3)
	return;
	for (int i=0;i<3-count;i++)
	{
		bing=new(__DIR__"npc/bing");
		bing->move(this_object());
	}
}