 //road1.c
inherit ROOM;
void create()
{
        set("short", "山坳");
        set("long", @LONG
转过一道山坳，这里郁郁苍苍，满山树木。北面山峰环抱，
仿佛是条绝路。四周极静，除了偶尔一两声鸟鸣和时续时断的
水声，似乎什么也听不见。
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"road0",
  "northup" : __DIR__"outroom",
]));
        set("outdoors", "tieflag");
        set("coor/x",60);
        set("coor/y",2000);
        set("coor/z",20);
        setup();
}
void init()
{
        add_action("do_listen","listen");
}
int do_listen(string arg)
{
        object bird;
        if(!query("already"))
        {
        tell_object(this_player(),"你侧耳细听：＂扑楞楞楞＂，一只小山雀从树丛中飞了出来．．\n");
        bird = new(__DIR__"npc/littlebird");
        bird->move(this_object());
        set("already",1);
        return 1;       
        }
        else
        return 0;
}
void reset()
{
::reset();
delete("already");
}     
