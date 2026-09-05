#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "城东小路");
set("outdoors","xiangyang");
set("occupied",1);
	set("long",
	CYN"这里是襄阳的东门外,襄阳城西群山耸立，交通不便，所以很少有人来此,
  出城不久路就越走越窄，蜿蜒通向山岭之上,东面还有一条岔路,似乎常有人走动。\n"NOR
	);

	set("exits", ([
		"eastup" : __DIR__"eroad2",
		"west" : __DIR__"egate",          
                "east" : __DIR__"caiyuan",
        "southeast" : "/d/xinyang/guandaow1",
	]));
    	set("objects", ([
		__DIR__"npc/qiaofu" : 1,
        ]));
	setup();
}



int valid_leave(object me, string dir)
{        
         if (dir=="eastup" && !me->query_temp("东门"))
           {   me->set_temp("东门",1);
              return notify_fail("此去往东是荒郊野岭，盗贼猛兽出没之地，我劝" + RANK_D->query_respect(me) +"\n还是不要去了,如果" + RANK_D->query_respect(me) + "一心想去，千万多加小心！\n");
           }
          return ::valid_leave(me, dir);
}