#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"金屋"NOR);
        set("long", @LONG
黄金的墙壁果然随之移动，现出了道门户，人还未进去，已有一片辉
煌的光洒了出来。这金色的墙壁后，竞赫然全都是珠宝，数不清的珠宝，
任何人做梦都想不到会有这么多的珠宝！
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
                __DIR__"obj/treasure" : 3,
                __DIR__"npc/maskman_g" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_pick", "get");
}  
int do_pick(string arg) {
        object me, guard;
        int num;
        
        if(!arg) return 0;
        if (arg=="all" || arg == "treasure stone"
                || sscanf(arg,"treasure stone %d",num)) {
                if (guard=present("maskman",this_object())) {
                        message_vision("$N不言不语，伸手挡住了你。\n",guard);
                        return 1;
                }
                return 0;
   }
        return 0;
}   
