#include <room.h>
inherit ROOM;
void create()
{
        set("short", "广场南");
        set("long", @LONG
北面就是风云的中心广场。这里是风云城中大富人家去集市的必经之路。豪富
的行人导致了这里的崎形繁荣。大街西侧的玉龙珠宝店人进人出，拥挤不堪。东侧
则是专门为有钱人的远方朋友到风云城来玩时所准备的凤求凰客栈。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind2",
  "north" : __DIR__"fysquare",
  "east" : __DIR__"fqkhotel",
  "west" : __DIR__"yuljade",
]));
        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/mei": 1,
                        ]) ); 
        set("coor/x",0);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
//      replace_program(ROOM);
}  
/*
void init() {
          add_action("do_dazuo","dazuo");
        }
        
int do_dazuo(string arg) {
        object me;
        me=this_player();
        tell_object(me,"此地不能打坐。\n");
        return 1;
}*/   
