 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "地洞");
        set("long", @LONG
这条小小的地道大约有七八尺，然后，里面就是个小小的洞，
最多也不过只有七八尺见方。但这洞里，却早巳铺好了四五床
棉被，还有两缸水，一坛酒，和一大堆咸肉、香肠、糯米糕，
此刻居然还有十几本书。
LONG
        );
        set("exits", ([ 
                                ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_dig", "dig");
} 
int do_dig(string arg)
{
        object room;
        object me;
        me = this_player();
        room = load_object(__DIR__"center");
        message_vision("$N捡起一块碎坛子，在地上拼命的挖了起来！\n",me);
        tell_object(me,"突然，砰的一响，像是木板碎裂的声音。。\n");
        me->move(room);
        return 1;
}     
