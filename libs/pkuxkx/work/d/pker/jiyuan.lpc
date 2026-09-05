
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "妓院");
        set("long", @LONG
这是杀手帮最红的一家妓院，每天都是顾客盈门，甚至不乏武林高手。据说杀手帮开设这
妓院的目的一是笼络人心，二是探听消息
LONG
        );
        
        set("exits", ([
                
                "south":__DIR__"dadao22",
                ]));
          set("objects", ([
__DIR__"npc/xiaocui":1,
__DIR__"npc/xiaohong":1,
__DIR__"npc/pozi":1,
         
           ]));
        setup();
      
}


void init()
{
   object me=this_player();
   remove_call_out("greeting");
   call_out("greeting",0,me); 
   
}

void greeting(object me)
{
	if (!me) return;
   message("vision",HIR"客官来了？只要来到本院，不论老幼都可以在这里得到满足
您来这里真是太对了!\n"NOR,me);
}