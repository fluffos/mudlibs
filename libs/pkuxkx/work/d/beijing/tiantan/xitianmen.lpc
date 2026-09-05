// Room: /d/beijing/xitianmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"西天门"NOR);
        set("long",
HIC"迎面是一座巨大的汉白玉牌楼，整个牌楼雕刻着许多的鸟兽鱼虫，手工
极之精细，上面题着“天坛”二字，笔走龙蛇，气势不凡，站立其下，不由
然有一种神圣庄严的感觉。这里是天坛的西大门，天坛有内外两重坛墙，
坛墙南方北圆，象征“天圆地方”。是皇帝祈祷五谷丰登的场所。\n"NOR
        );
        set("outdoors", "beijing");

        set("exits", ([
                "east" : __DIR__"shibanlu1",
                "west" : "/d/beijing/picai",
        ]));

        set("objects", ([
         "/d/beijing/npc/jinyiwei" : 4,
        ]));
        setup();
}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/xitianmen",1);
      }

}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if(dir=="east")
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
