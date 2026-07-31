// jiaobei.c 教碑
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "教碑");
        set("long", @LONG
这里是全真教的教碑所在地，路旁立着一块大碑(bei)。再往东
走就是天下闻名的道家玄门正宗--全真教的大门了。北面有一条石
阶，不知道通向哪里，往西是下山的路。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie6",
                "eastup" : __DIR__"damen",
                "west" : __DIR__"shijianyan",
        ]));
        set("item_desc", ([
        "bei": CYN"
        ＊＊＊＊＊
　　　　＊　　　＊
　　　　＊　全　＊
　　　　＊　　　＊
　　　　＊　真　＊
　　　　＊　　　＊
　　　　＊　古　＊
　　　　＊　　　＊
　　　　＊　教　＊
　　　　＊　　　＊
　　　　＊＊＊＊＊
\n"NOR
        ]) );
        set("objects",([
                __DIR__"npc/zhao" : 1,
                "/kungfu/class/xueshan/sd1" : 1,
                "/kungfu/class/xueshan/sd2" : 1,
                "/kungfu/class/xueshan/sd3" : 1,
                "/kungfu/class/xueshan/sd4" : 1,
        ]));

        setup();
        //replace_program(ROOM);
}
void init()
{
        add_action("do_kan","pai");
}

int do_kan(string arg)
{
        object me=this_player();
        object ob;


        if (!arg || (arg != "教碑" && arg != "bei"))
                return notify_fail("你要拍什么啊。\n");


if(me->query("jinyong/book10"))
return notify_fail("你拍了拍教碑。\n");

call_out("leavet",0);


                return notify_fail(HIR"你拍了拍教碑，突然冲出一大群道士把你围了起来，领头的道士说道:淫贼 哪里走？\n"NOR);
}

void leavet(object me)
{
me=this_player();	
me->move(__DIR__"jianzhen");
}