#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "原始丛林");
        set("long", @LONG
丛林中一片黑暗，黑暗中充满了各式各样的危险，每一种都可以
致命。若是在丛林中迷失了方向，饥渴就足以致命。
LONG
        );
        set("exits", ([
                "north" : __DIR__"forest7",
                "south" : __DIR__"forest1",
                "east" : __DIR__"forest5",
                "west" : __DIR__"forest6",
        ]));
        set("objects", ([
                __DIR__"npc/ye": 1,
                __DIR__"obj/tree": 1,
        ]));
        set("outdoors", "ghost");
        set("coor/x",-1180);
        set("coor/y",-60);
        set("coor/z",-10);
        setup();
} 
void reset()
{
        object          *inv;
        object          con, item;
        object          room, fen;
        int             i; 
        ::reset();
        set("exits", ([
                "north" : __DIR__"forest7",
                "south" : __DIR__"forest1",
                "east" : __DIR__"forest5",
                "west" : __DIR__"forest6",
        ]));    
        room = this_object();
        if(objectp(fen = present("fen yan zi", room)))
                destruct(fen);
        con = present("big tree", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"npc/fen");
                item->move(con);
        }
} 
int valid_leave(object me, string dir)
{
        object env, ye, gudu; 
        env = this_object();
        ye = present("ye gu hong", env);
        gudu = present("gu du mei", env); 
        if(objectp(gudu) && gudu->query_leader() == me) {
                if(objectp(ye) && !(me->query_temp("marks/okleave"))) 
                        return notify_fail( HIY "\n叶孤鸿冷冷的说道：这位朋友留下孤独美再走。\n"NOR);
        }
        return 1; 
}   
