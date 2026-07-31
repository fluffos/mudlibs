#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", BLK"铁屋"NOR);
        set("long", @LONG
这铁屋特别大，特别高，四壁空空，什么也没有，一个人站在里
面，就好像站在旷野中似的。就在这空旷而阴森的屋子中央，孤零零
地站着两具骷髅，两具惨白色的骷髅，紧紧拥抱在一起。死人的血肉
已化，但骷髅至今犹屹立不倒。五张矮几，几上居然还放着些笔墨、
书册。
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
                __DIR__"npc/maskman_i" : 1,
                __DIR__"obj/table" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}    
