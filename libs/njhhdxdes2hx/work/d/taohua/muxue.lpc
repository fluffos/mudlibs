// Room: /d/new_taohua/muxue.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "黄药师妻墓地");
        set("long", @LONG
你的眼前忽出现一片白色花丛，重重叠叠，宛如一座白花堆起的小湖。
白花之中有一块东西高高隆起。走近一看原来是一座石坟。坟前墓碑上刻着
“桃花岛女主冯氏埋香之冢”。周围环境肃穆，似乎蕴藏着秘密。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "out" : __DIR__"wifemu",
    "down" :__DIR__"andao",
]));
        set("item_desc", ([
                "mubei": "碑上写着'感逝者之不逝,情忽忽而失度，天盖高而无阶，'\n",
                "墓碑": "碑上写着'感逝者之不逝,情忽忽而失度，天盖高而无阶，'\n"
]));

        setup();
}
 void init()
{
	add_action("do_love","write");
}  
int do_love(string arg)
{
	object me;
	me=this_player();
        if(!arg )
                return notify_fail("write <事>\n");
        if(query("exits/enter")) return 0;
        if(arg[0..11] == "怀此恨其谁诉" && random(10)>8 && me->query_skill("qimen-bagua",1)>50) {
                        message_vision( "\n$N顺着墓碑上的字迹描了一遍，墓碑突然向边上缓缓滑开，露出一条地道。\n",this_player());
	                set("exits/enter",__DIR__"midao");
                        return 1;
                }
        return notify_fail("\n你顺着墓碑上的字迹描了一遍。\n");
}  
void reset()
{
    ::reset();
    if(query("exits/enter"))
    	delete("exits/enter");
}
