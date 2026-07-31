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
                "north" : __DIR__"forest2",
                "south" : __DIR__"forest5",
                "east" : __DIR__"forest6",
                "west" : __DIR__"forest5",
        ]));
        set("outdoors", "ghost");
        set("coor/x",-1170);
        set("coor/y",-60);
        set("coor/z",-10);
        setup();
} 
void reset()
{
        ::reset();
        set("exits", ([
                "north" : __DIR__"forest2",
                "south" : __DIR__"forest5",
                "east" : __DIR__"forest6",
                "west" : __DIR__"forest5",
        ]));
}    
