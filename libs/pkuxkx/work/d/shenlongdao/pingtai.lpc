// Room: /shenlongjiao/pingtai1.c
// kiden 06/08/26
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
        set("short", HIC"平台"NOR);
        set("long", @LONG
好一片风光秀丽的平台。远远望去，可以看到那海天一线。东边的台阶下是一片茂密的竹林。
台上建着几间大屋，十余名分穿五色衣衫的少年男女持剑前后把守。
LONG
        );
        set("outdoors", "shenlongdao");
        
        set("exits", ([
                "eastdown" : __DIR__"zhulin4",        
                "north" : __DIR__"xianfuju",
                "west" : __DIR__"zhusuo1",
                "south" : __DIR__"zhusuo2",                
        ]));
          set("objects", ([
              __DIR__"npc/nvdizi" : 2,
              __DIR__"npc/dizi1" : 2,
              __DIR__"npc/dizi2" : 2,
              __DIR__"npc/dizi3" : 2,
              __DIR__"npc/dizi4" : 2,
         
           ]));
        setup();
       //replace_program(ROOM);
}



int valid_leave(object me, string dir)
{        

        mapping myfam;
        myfam = (mapping)me->query("family");
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
        if ((!myfam || myfam["family_name"] != "神龙教") && dir == "north"
            && objectp(present("shenlong dizi", environment(me)))
            && living(present("shenlong dizi", environment(me))))
           return notify_fail("神龙教弟子大喝一声：里面是教主和夫人休息之低，外人不得入内。\n");

        if (me->query("gender")=="男性" && dir == "south")
        return notify_fail(HIC"你被女弟子轰了出来，感觉非常尴尬。\n"NOR);

        if ( me->query("gender")=="女性"&& dir == "west")
        return notify_fail(MAG"你贸贸然闯了进去，羞得满脸通红，赶紧飞也似的逃了出来！\n"NOR);


        return ::valid_leave(me, dir);
}
