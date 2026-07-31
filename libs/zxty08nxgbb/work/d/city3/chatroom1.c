// Room: /d/snow/chatroom.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
       set("short", "大杉树上");
        set("long", @LONG
人说大树底下好乘凉，没想到大树上更凉快。这棵大杉树真不愧为千年神木，
至今仍绿叶繁茂。据说这里的时间是冻结的，因此便成为许多玩家聊天的地方。
这里摆着几张用杉树根做的椅子，中间用几根杉树枝搭在一起，算是一个茶几了。
当你抬头往上看的时候似乎有个影在树梢之间移动，不过也许是风吹动所造成的
错觉。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "down": __DIR__"guangchang",
        "up": __DIR__"chessroom",
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("freeze",1);
      set("valid_startroom","1");
        set("objects", ([
//                "/d/wizard/npc/chaiyao" : 1,
        ]));
        setup();
}
void init()
{
    if (wizardp(this_player())) return;
    add_action("do_jump","tiao");
//    add_action("do_climb", "climb");
    add_action("discmds",({"respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}
int discmds()
{
        tell_object(this_player(),"现在你还是专心聊天吧！\n");
        return 1;
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("你要往哪跳？\n");
      if (me->is_fighting() || me->is_busy() )  return notify_fail("你正忙着呢！\n");
        message("vision",
                me->name() + "犹豫了一下，鼓起勇气，跳了下去。\n“嘭”的一巨响，似乎听到"+me->name()+"惨嚎了一声!\n",
                environment(me), ({me}) );
                me->move(__DIR__"guangchang");
        message("vision",
                me->name() + "惨嚎一声，从树上掉了下来。\n",
                environment(me), ({me}) );
        return 1;
}
int valid_leave(object me, string dir)
{
        if ( dir=="down" && !wizardp(me))
        return notify_fail("盘根不知道给哪个坏家伙砍断了，看来只能跳(tiao)下去！\n");
        else return 1;
}
int do_climb(string arg)
{
    object me;
    mixed *local;
    local=localtime(time());
    me = this_player();
        if( !arg || arg!="up") return notify_fail("你要往哪个方向爬？\n");
    message("vision",
       me->name() + "姿势优雅地抓着大杉树的树枝，“嘘”的一声，向上爬去。\n",
        environment(me), ({me}) );
        me->move("/d/city3/chessroom.c");
        message("vision",
       me->name() + "抓着大杉树的树枝，爬了上来。\n",
                environment(me), ({me}) );
    return 1;
}
