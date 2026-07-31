// tianye.c
// marry 99.8
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "田野");
        set("long",
"这是片一望无际的田野，充满了大自然的勃勃生机，远处蜿蜒连绵的大山使你\n"
"感到了远离都市嘈杂后的平静和安宁。唯一有些让你觉得不和谐的是在你身旁的一大\n"
"片玉米地。\n\n"
);
                set("outdoors", "cxwxm");
        set("exits", ([ /* sizeof() == 2 */
         "west" : "/d/city3/shandao2",
]));

        setup();
}
void init()
{
        this_player()->set("jihao",0);
        add_action("do_zuan", "zuan");
}
int do_zuan(string arg)
{
        object me = this_player();

    if(arg)  
   {
    write("你乱钻什么？\n");
         return 1;
    }

    message_vision(
    "$N头也不回的钻进了玉米地。\n", this_player());

        if ((me->query("family/family_name") == "痴心妄想门"))
        {
                me->move(__DIR__"cxwx");
         }
        else
        {      
                me->move(__DIR__"yumi4");
         }
         return 1;
}

