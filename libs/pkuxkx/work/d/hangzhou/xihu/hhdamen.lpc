// Room: /hangzhou/hhdamen.c
// hubo 2008/4/19

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
void create()
{
        set("short", "杭州分舵大门");
        set("long", @LONG
    富丽堂皇的大门，看似是个当地地主的庭院，但熟悉的人都清楚，这里
其实是红花会杭州分舵，门口有两个会众负责接待来客。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([     
                "west" : __DIR__"hhxiaoyuan",   
                "east" : __DIR__"zhulin5",     
]));
     
     set("objects", ([
                "/d/hangzhou/npc/honghua1" : 2,
        ]));     
   setup();
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
                
    if (me->query_temp("hhh_wt1") == 2)
          return ::valid_leave(me, dir); 
                
    if ((!myfam || myfam["family_name"] != "红花会") && dir == "west"
    && objectp(present("honghua huizhong", environment(me)))
    && living(present("honghua huizhong", environment(me))))
        return notify_fail("红花会众说道：“阁下不是红花会弟子，最好不要进去。”\n");
    return ::valid_leave(me, dir);
}

