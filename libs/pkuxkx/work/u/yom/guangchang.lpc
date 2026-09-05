// Room: /city/guangchang.c
// HSR 1997/9/16

inherit ROOM;
#include <ansi.h>
int newyear(object);

void create()
{
         set("short", "中央广场");
        set("long", @LONG
    这里是城市的正中心，一个很宽阔的广场，铺着青石地面。一些游手好闲
的人在这里溜溜达达，经常有艺人在这里表演。中央有一棵大榕树，盘根错节，据
传已有千年的树龄，是这座城市的历史见证。树干底部有一个很大的洞(shudong)。
你可以看到北边有来自各地的行人来来往往，南面人声鼎沸，一派繁华景象，东边
不时地传来朗朗的读书声，西边则见不到几个行人，一片肃静。
LONG
        );
        set("no_sleep_room",1);
//      set("no_fight", 1);     现在广场下面有发呆室，这里不需要no_fight了。
        set("outdoors", "city");

        set("item_desc", ([
                "shudong" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n"
,
                "baoku" : "你觉得一阵头晕，有一种想呕吐的感觉。\n",
        ]));
        
        set("exits", ([
                "east" : __DIR__"dongdajie1",
                "south" : __DIR__"nandajie1",
                "west" : __DIR__"xidajie1",
                "north" : __DIR__"beidajie1",
                "up" : __DIR__"shangyuetai",
                "down" : __DIR__"idleroom",
        ]));
        set("objects",([
        	"/clone/npc/camel1":1,
 //                "/u/male/fengdaoren":1,
//                "/u/male/bigexp":2,
          //     "/d/city/npc/dum":1,
//                "/clone/gift/gifttree":1,
                "/u/yom/gifttree":1,
        ]));

        setup();
  "/clone/board/ct_b"->foo();
}

void init()
{
        add_action("do_enter", "enter");
          add_action("do_none","dz");
          add_action("do_none","dazuo");
}
int do_none()
{
        write("你怎么能在中央广场随便打坐呢？\n");
        return 1;
}
int newyear(object ppl)
{
    ppl->delete("newyear");
    ppl->save();
    return 1;
}

int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="shudong" )
        {
                message("vision",
                        me->name() + "一弯腰往洞里走了进去。\n",
                        environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );
                return 1;
        }

        if( arg=="baoku" )
        {
                message("vision",
                        me->name() + "本来好端端在这里的，忽然消失了，好象人间蒸
发了一样。\n",
                        environment(me), ({me}) );
                me->move("/d/city/baoku");
                message("vision",
                        me->name() + "不知道从哪里冒出来的，吓了你一跳。\n",
                        environment(me), ({me}) );
                return 1;
        }
}
int valid_leave(object me, string dir)
{
        write(HIR"主页地址：http://www.pkuxkx.net\n"NOR);
        if (dir == "up")
        {
        if(me->query("age")>16 && !wizardp(me))

                {
                  return notify_fail("绿萼白了你一眼道：“都那么大了还来白吃，不害羞。”\n");
                }
        }
        return ::valid_leave(me, dir);
}

