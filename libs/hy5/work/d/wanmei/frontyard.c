 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "山庄前院");
        set("long", @LONG
十丈方园的院子两侧种着几排翠绿的蔬菜。院角有一口小井。
井口有一木桶，桶上系着麻绳，显然是用来汲水的。院子另一边
堆着的几捆刚砍下来的木柴正在太阳下慢慢晒干。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"gate",
  "east" : __DIR__"meidang",
  "north" : __DIR__"woodroom",
  "south" : __DIR__"woodhouse",
  "northeast" : __DIR__"left",
  "southeast" : __DIR__"right",
]));
        set("outdoors", "wanmei");
        set("resource/water",1);
        set("liquid/container","小井");
        set("item_desc", ([
                "蔬菜": "
                        好青好绿的蔬菜呀！你如果不怕人骂，拔（ｐｕｌｌ）一棵吧！\n",
                "木柴": "
                        快干了的木材，拿（ｐｉｃｋ）几根儿？\n",
                //"小井": "
                //        小井很滑，但你可以试着爬（ｃｌｉｍｂ）下去。\n"  
        ]) );
        set("coor/x",150);
        set("coor/y",-400);
        set("coor/z",30);
        setup();
}
void init()
{
    add_action("do_pull", "pull");
    add_action("do_pick", "pick");
    add_action("do_climb", "climb");
} 
void reset()
{
    ::reset();
    delete("pulled");
    delete("picked");
} 
int do_climb()
{
    write("你太胖了！！！\n");
    return 1;
} 
do_pull()
{
    object vege;
    if((int) query("pulled") <= 10)
    {
        vege = new(__DIR__"obj/vege");
        message_vision("$N拔了一棵"+vege->query("name")+"放在怀里。\n", this_player());
        vege->move(this_player());
        add("pulled",1);
        return 1;
    }
    else
        write("都被人拔光了！！\n");
    return 1;
} 
int do_pick()
{
    object vege;
    if((int) query("picked") <= 10)
    {
        vege = new(__DIR__"obj/wood");
        message_vision("$N拿了一根"+vege->query("name")+"放在怀里。\n", this_player()); 
        vege->move(this_player());
        add("picked",1);
        return 1;
    }
    else
        write("都被人拿光了！！\n");
    return 1;
}   
