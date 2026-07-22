inherit ROOM;
void create()
{
        set("short", "江湖娱乐室大堂");
        set("long", @LONG
这里是江湖的娱乐室富丽堂皇的大堂，
大堂李集居者许多前来休闲的人。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "east": __DIR__"dhs_room",
        "south": __DIR__"fxq_room",
        "west": __DIR__"21_room",
        "north": __DIR__"seaf_room",
        "out": __DIR__"chatroom",
        ]));
        set("no_fight",1);
        set("no_magic",1);
      set("valid_startroom","1");
        set("freeze",1);
        set("objects", ([
      
        ]));
        setup();
       }
void init()
{
    if (wizardp(this_player())) return;
    add_action("do_jump","tiao");
    add_action("discmds",({"sleep","respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","kill","steal","conjure","fight","hit","perform","prcatice","scribe","surrender"}));
    add_action("do_climb", "climb");
}
int discmds()
{
        tell_object(this_player(),"现在你还是专心游戏吧！\n");
        return 1;
}
