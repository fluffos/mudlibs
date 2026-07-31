 inherit ROOM;
void create()
{
        set("short", "岔路口");
        set("long", @LONG
穿过风窟，前面又是两道山窟。一条向前，一条向右。一具九子鬼母
的石像，立在两道路间。九个石塑的婴儿，爬抱在她的身上，有的手持算
盘，有的手持铃铛。石像雕塑之灵奇，当真是鬼斧神工。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"firehole",
  "west" : __DIR__"windhole",
]));
        set("objects", ([
        __DIR__"obj/stonejudge" : 1,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",180);
        set("coor/y",-40);
        set("coor/z",20);
        set("coor/x",180);
        set("coor/y",-40);
        set("coor/z",20);
        setup();
}
void init()
{
        add_action("do_east", "e");
        add_action("do_east", "east");
}
int do_east(string arg)
{
        object me;
        object room;
        me = this_player();
        message_vision("$N从东面的一处山窟钻了进去。\n", me); 
        room = load_object(__DIR__"realhole");
        if(room) me->move(room);
        
   return 1;
}   
