 // Room: /d/oldpine/riverbank1.c
inherit ROOM; 
void create()
{
        set("short", "山涧之中");
        set("long", @LONG
你现在正站在一条山涧中的岩石上，几股泉水正从你脚边流过，水
花溅得四处飞散，南边是一个深不见底的水潭，两边的山壁看起来又高
又陡，看来要爬上岸边实在很不容易，你的北方有一座小石桥高高地跨
过两边的山壁，可是桥的高度太高，即使是轻功绝顶的高手也跃不上去。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"riverbank2",
  "south" : __DIR__"lake"
]));
        set("outdoors", "oldpine");
        set("resource/water", 1);
        set("objects", ([
        __DIR__"npc/shenyinqiang" : 1,
                        ]) );
        set("coor/x",540);
        set("coor/y",2340);
        set("coor/z",70);
        setup();
} 
void init()
{
        add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
        if( !arg || arg!="cliff" ) return 0; 
        message_vision("$N一付不信邪的表情，开始小心翼翼地攀著石壁爬了上去。\n",
                this_player() );
        this_player()->move(__DIR__"cliff1"); 
        return 1;
}     
