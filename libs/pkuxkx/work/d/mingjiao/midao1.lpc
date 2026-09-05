//sheng men

#include <ansi.h>
#include "/doc/help.h"

inherit ROOM;

void create()
{
        string *mkey=({
                "midao0","midao1","midao2","midao3","midao4","midao5","midao6","midao7",
                });
        mapping midao=([
                                mkey[0] : __DIR__"midao0",
                                mkey[1] : __DIR__"midao1",
                                mkey[2] : __DIR__"midao2",
                                mkey[3] : __DIR__"midao3",
                                mkey[4] : __DIR__"midao4",
                                mkey[5] : __DIR__"midao5",
                                mkey[6] : __DIR__"midao6",
                                mkey[7] : __DIR__"midao7",                      
                        ]);
        int i;

        i=random(257);
        
        set("short", "秘道");
        set("long",@LONG
    这里黑凄凄的，墙壁上挂着一盏油灯，发着昏黄的微光，周围有八个洞，
能感到隐隐杀气从中传出，你不由得打了个冷战。
LONG
                );
        set("no_task",1);
        set("exits", ([    
              "east" : midao[mkey[(i+0)%8]],
         "southeast" : midao[mkey[(i+1)%8]],
             "south" : midao[mkey[(i+2)%8]],
         "southwest" : midao[mkey[(i+3)%8]],
              "west" : midao[mkey[(i+4)%8]],
         "northwest" : midao[mkey[(i+5)%8]],
             "north" : midao[mkey[(i+6)%8]],
         "northeast" : midao[mkey[(i+7)%8]],
        ]));

        setup();

        
}

int valid_leave(object me, string dir)
{
        int i;

        create();

        me=this_player();
        i=me->query_temp("sheng");
        i++;
        me->set_temp("sheng",i);

        if (i>22)
        {
		message_vision(HIY "$N突然触发机关! $N被一股大力抛了出去。\n" NOR,me);
		me->move(__DIR__"midao");
		return 0;
        }

        return 1;
}
