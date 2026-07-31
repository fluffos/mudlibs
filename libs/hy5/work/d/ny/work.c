
// work.c

inherit ROOM;

void create()
{
        set("coor",({1000,4700,10}));
	set("short", "晒谷场");
        set("long",
"这是一处晒谷场，将仓库里的谷子放在这摊晒的地方。米厂老板是一个一看就知道是十分精\n"
"明的干瘦的中年人，老是带着一脸奸笑。你可以看到许多人正在忙忙碌碌的工作着，门口挂\n"
"著一块牌子(sign)，往西是通往宁远城的大路。\n"
);
        set("exits", ([ /* sizeof() == 1 */
     "northwest" : __DIR__"temple",
     "south" : __DIR__"road11",
]));

        set("item_desc", ([
                "sign": @TEXT
现在正紧缺人手，急需雇佣一批短工来干活。

work     开始工作。

TEXT
        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
 set("outdoors", "ny");
        setup();
}

void init()
{
        add_action("do_work", "work");
}

int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();
   if (me->is_busy())
        return notify_fail("你现在正在干活吧！\n");

   if (me->query_temp("times")>20)
        return notify_fail("今天的活干完了，明天再来吧！\n");
        if( me->query("jing")<=29||me->query("qi")<=29)
        {  message_vision("$N的神太低了,明天再来工作吧。\n",me);
           return 1;
         }
message_vision("$N辛苦的工作终于结束了，可人也累的要死\n", me); 
me->add("jing",-30);
me->add("qi",-30);
me->add_temp("times",1);
//receive_damage("gin",30,me);
//receive_damage("sen",30, me);
ob = new("clone/money/silver");
me->start_busy(15);
ob->move(me);
message_vision("老板对$N说：这是你的工钱。\n", me);
return 1;  
}
