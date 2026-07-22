// Room: /d/emei/shandong8.c 山洞8
// create by host dec,20 1997

inherit ROOM;

void init();

void create()
{
        set("short", "山洞");
	set("long", @LONG
你走在一条漆黑山洞里。摸着洞内岩壁缓慢前行，从墙壁上散发出的阴冷
潮湿气息，使你不由自主的打了寒噤，浑身有说不出的难受。朦胧中，向四周
望过去，隐约可以看到一股光线从右侧洞口投射进来。
LONG
	);
        set("exits", ([
           "west":  __DIR__"shandong"+(random(6)+5),
           "south": __DIR__"shandong"+(random(6)+5),
           "north": __DIR__"shandong"+(random(6)+5), 
	]));
	setup();
}
void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{

    object me = this_player();
    object room;
    if ( !arg || (arg != "out") )
        return notify_fail("你想做什么，发痴吗？\n");
    if (me->is_busy())
	return notify_fail("你现在正忙着呢。\n");
    room= load_object(__DIR__"yunvfeng");
    if(objectp(room))
        {

                message_vision("$N从山洞中跳了出去。\n", me);
                message("vision", me->query("name")+"从山洞中跳了出来。\n", room);
        }
    
    if( (int)me->query_kar() < 25 )
      {
         me->move(__DIR__"shanpo");
         write("你只觉得脚下一阵松软，已轻飘飘的落在了地上。\n");
	 return 1;
       }
         me->move(__DIR__"yunvfeng");
         write("你只觉得脚下一阵松软，已轻飘飘的落在了草地上。\n");
     return 1;
}