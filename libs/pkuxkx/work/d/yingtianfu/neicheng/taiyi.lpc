//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include <skill.h>
void create()
{
        set("short", HIW"太医院"NOR);
        set("long", 
"这里太医院的衙门。墙上一张经络图(tu)是明朝历代太医研究的心得，完全\n颠覆了之前的理论。\n"

        );
        set("item_desc", ([
		"tu" : "这是一张经络图，和中原固有内功运行方式完全不一致，你可以参照修炼内功。\n", 
	    ]));
        set("exits", ([
                
              
                
                
                "north" : __DIR__"datong1",
               
                
                
                
        ]));
         set("objects", ([
		__DIR__"npc/taiyi-yuanpan" : 1,
        __DIR__"npc/taiyiyuanshi" : 1,
	    ]));
        
        setup();
   
}

int get_xiulian_bonus(object me)
{
    if (me->query("ming/tj/pin")&&me->query("ming/tj/pin")<=4)
    return 105;
    if (me->query("ming/tj/pin")==5)
    return 103;
	if (me->query("ming/tj/pin")==6||me->query("ming/tj/pin")==7)
    return 102;
    if (me->query("mingpin")==1)
    return 110;
	if (me->query("mingpin")==2)
    return 108;
	if (me->query("mingpin")==3)
    return 105;
	if (me->query("mingpin")==4)
	return 103;
	if (me->query("mingpin")==5)
	return 102;
	else
	return 100;
}
string get_xiulian_bonus_desc(object me)
{
	if (get_xiulian_bonus(me)>100)
	{
		return "$N对照着墙上的经络图修炼内功，事半功倍。\n";
	}
}