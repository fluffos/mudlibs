//make by chenchen
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "官道");
set("occupied",1);
        set("long", @LONG
再往北,襄阳城就要到了.路上已经很少有行人,都是军汉打扮,
而且行色匆匆,大概是奉了军令,去执行什么任务.
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"mroad3", 
  "north" : __DIR__"sgate"
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        setup();
}


int valid_leave(object me, string dir)
{
    if ( dir == "south" && time()-me->query("华容道/last_time")>600&&me->query("combat_exp")-me->query("华容道/last_exp")>500000&&random(1000)>910)
        {
            me->set("华容道/last_exp",me->query("combat_exp"));
            me->set("华容道/last_time",time());
            me->set_temp("huarongdao/start",1);
            tell_object(me,BLINK+"村民告诉你：华容道最近被一伙山贼占据，没事最好绕道而行。\n"+NOR);
        }
        return ::valid_leave(me, dir);
}