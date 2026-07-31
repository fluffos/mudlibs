// Room: /d/snow/school1.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "淳风武馆大门");
        set("long", @LONG
你现在正站在一间大宅院的入口，两只巨大的石狮镇守在大门
的两侧，一阵阵吆喝与刀剑碰撞的声音从院子中传来，通过大门往
东可以望见许多身穿灰衣的汉子正在操练。
LONG
        );
       set("no_beg",1);
       set("no_sleep_room",1);
       //set(SAFE_ENV, 1);
       set("exits", ([ /* sizeof() == 2 */
       "west" : __DIR__"guangchang_n",
       "east" : __DIR__"school2",
]));
        set("outdoors", "xueting");
        
        set("objects", ([
        	__DIR__"npc/cleaner":1,
                __DIR__"npc/liuanlu": 1 ,
                ]) );
        create_door("east", "红漆大门", "west", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}
