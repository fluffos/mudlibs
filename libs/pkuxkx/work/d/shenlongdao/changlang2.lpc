// Room: /shenlongjiao/changlang2.c
// kiden 06/08/25
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", YEL"长廊"NOR);
        set("long", @LONG
        越往前走，你就感觉气氛更加凝重，似乎到了紫禁城一般。
抬头看去，一个大铁门紧闭着，门的上房有一块大匾（bian）。
铁门的门口站着几个女弟子，也许你进去要征求她们的同意吧。

LONG
        );


        set("item_desc", ([
                "bian" : 
        "\n"
        "    ※※※※※※※※※※※※※※※※※※※\n"
        "    ※※※※　　　　　　　　　　　※※※※\n"
        "    ※※※※　  "+HIR"议  事  大  厅"NOR+"    ※※※※\n"
        "    ※※※※　　　　　　　　　　　※※※※\n"
        "    ※※※※※※※※※※※※※※※※※※※\n"
        ]));

        set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"changlang1",  
                "enter" : __DIR__"yishidating",                     

]));
        set("objects", ([
              __DIR__"npc/nvdizi" : 2,
       ]));

        setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
        if ((!myfam || myfam["family_name"] != "神龙教") && dir == "enter"
            && objectp(present("shenlong dizi", environment(me)))
            && living(present("shenlong dizi", environment(me))))
           return notify_fail("神龙教弟子大声喝道：本教重地，外人不得入内！\n");
        return ::valid_leave(me, dir);
}

