 inherit ROOM;
void create()
{
        set("short", "原始丛林");
        set("long", @LONG
丛林中一片黑暗，黑暗中充满了各式各样的危险，每一种都可以
致命。若是在丛林中迷失了方向，饥渴就足以致命。落叶是湿的，泥
土也是湿的。一个人倒在落叶湿泥中，全身都已因痛苦而扭曲。
LONG
        );
        set("exits", ([
                "north" : __DIR__"forest6",
                "south" : __DIR__"forest2",
                "east" : __DIR__"forest3",
                "west" : __DIR__"forest1",
        ]));
        set("objects", ([
                __DIR__"npc/gudumei" : 1,
        ]));
        set("outdoors", "ghost");
        set("coor/x",-1150);
        set("coor/y",-50);
        set("coor/z",-10);
        setup();
} 
void reset()
{
        object room, gudu; 
        ::reset();
        set("exits", ([
                "north" : __DIR__"forest6",
                "south" : __DIR__"forest2",
                "east" : __DIR__"forest3",
                "west" : __DIR__"forest1",
        ]));    
        room = this_object();
        if(!objectp(present("gu du mei", room))){
                gudu = new(__DIR__"npc/gudumei");
                gudu->move(room);
        }
}  
