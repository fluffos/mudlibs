inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "后偏厅");
        set("long", @LONG
后偏厅的楼上就是马空群的卧室，所以这儿一年三百六十五天，一天二十四小
时有人当值。能在这儿守卫的，不是马空群的嫡传弟子，就是跟随他出生入死多年
的侍卫，除了总管公孙断，就连副堂主花满天也要通报了才能上楼。
LONG
        );
        set("exits", ([ 
                "up": __DIR__"corridor3",
                "east": __DIR__"hall4",
        ]));
        set("objects", ([
                __DIR__"npc/vguard2":   1,
                __DIR__"npc/vguard3":   1,
        ]) );
        set("coor/x",-1120);
        set("coor/y",320);
        set("coor/z",0);
        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string arg) {
        object ob;
        
        ob=present("ma shier",this_object());
        
        if (!ob || me->query("wanma/上楼")) 
                return 1;
        
        if (userp(me))
        if (arg== "up" ) {
                message_vision("$N说：“没有叁堂主的邀请，谁都不准入内。”\n",ob);
                return notify_fail("");
        }
        
        return 1;
}
