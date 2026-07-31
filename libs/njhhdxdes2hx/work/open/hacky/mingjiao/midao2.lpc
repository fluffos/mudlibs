//shang men

#include <ansi.h>

inherit ROOM;

void create()
{
        string *midao=({
                                 __DIR__"midao0",
                                 __DIR__"midao1",
                                 __DIR__"midao2",
                                 __DIR__"midao3",
                                 __DIR__"midao4",
                                 __DIR__"midao5",
                                 __DIR__"midao6",
                                 __DIR__"midao7",
                        });
        int i;

        i=random(257);
        
        set("short", "秘道");
        set("long",@LONG
    这里黑凄凄的，墙壁上挂着一盏油灯，发着昏黄的微光，周围有八个洞，
能感到隐隐杀气从中传出，你不由得打了个冷战。
LONG
                );
        set("exits", ([    
              "east" : midao[(i+0)%8],
         "southeast" : midao[(i+1)%8],
             "south" : midao[(i+2)%8],
         "southwest" : midao[(i+3)%8],
              "west" : midao[(i+4)%8],
         "northwest" : midao[(i+5)%8],
             "north" : midao[(i+6)%8],
         "northeast" : midao[(i+7)%8],
	]));

        setup();

        
}

int valid_leave(object me, string dir)
{
        int i;

        create();

        i=me->query_temp("bagua/shang");
        i++;
        me->set_temp("bagua/shang",i);

        if (i>10)
        {
		message_vision(HIY "$N突然触发机关! $N一下失去了知觉。\n" NOR,me);
		me->set_temp("bagua/shang",random(10));
		me->unconcious();
		return 0;
        }

        return ::valid_leave(me,dir);
}
