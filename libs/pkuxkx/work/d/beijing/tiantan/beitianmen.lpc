
// Room: /d/beijing/west/beitianmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"北天门"NOR);
	set("long",
HIC"这里是天坛的北大门，天坛有内外两重坛墙，坛墙南方
北圆，象征“天圆地方”。是皇帝祈祷五谷丰登的场所。这里
守卫不严，很容易溜进去。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"northeast" : __DIR__"xiaohutong1",
  	"south" : __DIR__"shibanlu4",
]));
        set("objects", ([
         "/d/beijing/npc/jinyiwei" : 4,
        ]));
        set("outdoors", "beijing");
	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/beitianmen",1);
      }

}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if(dir=="south")
    {
        if (me->query("class") == "officer" && (me->query("pin") < 8 || me->query_temp("chaoting/xuncheng")))
        {
            message_vision(HIY"锦衣卫恭恭敬敬地对你说道：“大人请!”\n"NOR, me);
            return ::valid_leave(me, dir);
        }
        ob = all_inventory( environment( me ));
        for(i=0; i<sizeof(ob); i++) 
        {
            if( living(ob[i]) && ob[i]->query("id") == "jin yiwei" )
                return notify_fail("锦衣卫上前挡住你说道：里面没什么好看的，马上离开这里....！\n");
        }
        return ::valid_leave(me, dir);
    }
    return ::valid_leave(me, dir);
}
