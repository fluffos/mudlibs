// Room: /d/snow/chatroom.c
// This is a room made by roommaker. write by Zhm. :)
inherit ROOM;
void create()
{
       set("short", "棋室");  
        set("long", @LONG
这里不知什么时候开始，给长来这做客的人做了一张棋盘，大家
都会到这里下棋。这里的时间是冻结的，但树干上挂了个牌子，上面
写着几个大大的字，“不要在这里发呆哦，会被踢出去的喔”。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "west": __DIR__"chessroom",
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("freeze",1);
        set("objects", ([
                "/d/city3/obj/cch" : 1,
        ]));
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
