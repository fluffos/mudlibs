// Room: /d/snow/chatroom.c
// This is a room made by roommaker. write by Zhm. :)
inherit ROOM;
void create()
{
       set("short", "大杉树顶");  
        set("long", @LONG
这棵大杉树真不愧为千年神木，绿叶繁茂,上到树顶更觉视野开阔，据说这
里的时间是冻结的，因此便成为许多玩家消遣下棋的地方。这里摆着几张用杉树
根做的椅子，中间用几根杉树枝搭在一起，算是一个茶几了，茶几上摆放着一张
用来下象棋的中国象棋盘（ccb)。不过，想下棋还室到专用的棋室去吧。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "down": __DIR__"chatroom1",
        "east": __DIR__"chessroom5",
        "west": __DIR__"chessroom2",
        "north": __DIR__"chessroom3",
        "south": __DIR__"chessroom4",
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("freeze",1);
//        set("objects", ([
//                "/d/city3/obj/cch" : 1,
//        ]));
        setup();
}
void init()
{
    if (wizardp(this_player())) return;
    add_action("do_swing","swing");
    add_action("discmds",({"respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}
int discmds()
{
        tell_object(this_player(),"现在你还是专心下棋吧！\n");
        return 1;
}
int do_swing(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("你要往哪荡？\n");
      if (me->is_fighting() || me->is_busy() )  return notify_fail("你正忙着呢！\n");
        message("vision",
                me->name() + "鼓起勇气，抓着杉树枝荡了下去。\n“嘘”的一声，似乎听到"+me->name()+"着地的声音!\n",
                environment(me), ({me}) );
                me->move(__DIR__"chatroom1");
        message("vision",
                me->name() + "抓着杉树枝，姿势优雅地从树顶上荡了下来。\n",
                environment(me), ({me}) );
        return 1;
}
int valid_leave(object me, string dir)
{
        if ( dir=="down" && !wizardp(me))
        return notify_fail("树干不知道给哪个坏家伙砍得快要断了，看来只能荡(swing)下去了！\n");
        else return 1;
}
