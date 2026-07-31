// /u/beyond/mr/xiaoshe.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short", HIY"小舍"NOR);
         set("long",
"这间房舍小巧玲珑, 颇为精雅。小舍匾额上写着「"HIY"琴韵"NOR"」两字笔致,\n"
"致颇为潇洒。远处的小屋露出一檐屋角。东西两边各有一条小径不知通向哪里。\n"
);
         set("exits", ([
             "east" : __DIR__"xiaojing3",
"north" : __DIR__"xiaodao",
             "west" : __DIR__"xiaojing1",
]));
         set("objects",([
             __DIR__"npc/bao" : 1,          
]));
             setup();
          // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    object *inv;
       mapping myfam;
    int i;
               
    myfam = (mapping)me->query("family");

    if ((!myfam || myfam["family_name"] != "姑苏慕容" ) && dir == "west") {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("bao butong", environment(me))))
                    return notify_fail("包不同拦住你说道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。为了表示"
                        "对姑俗慕容的景仰，请放下兵仞进入姑俗慕容。\n");
                
    }
    return ::valid_leave(me, dir);
}
