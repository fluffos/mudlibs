string look_zi();
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","牌坊上");
	set("long",@LONG 
    这是牌坊的顶上，上来以后，你才发现牌坊的后壁被人刻了奇怪许
多的字(zi)，其他地方却积满灰尘，显得年代久远。
LONG
	);
    set("item_desc",([
  	"zi" : (:look_zi:),
        ]));
	set("exits", ([
		"down" : __DIR__"rukou",
		
	]));
	set("no_task",1);
	set("outdoors", "riyuejiao");
	setup();

}

string look_zi()
{
    object me=this_player();
    if (me->query("family/family_name")!="日月神教")
    {
        return HIY+"我踏月色而来到此一游。\n"+NOR;
    }
    else
    {
        return "这些字符似乎和你所学武功有极深的联系，你应该仔细看(watch)一下。。\n";
    }
}

void init()
{
    add_action("do_watch",({"kan","watch"}));
}

int do_watch(string arg)
{
        object me;
        int times;
        me = this_player();
        if (me->query("family/family_name")!="日月神教")
        {
            return 0;
        }
        if(!arg)
                return notify_fail("你想看什么？\n");
        if (sscanf(arg, "牌坊 %d", times) == 1 || arg == "牌坊")
        {
        
            if(!times)
                    times = 1;
            if(times > 10)
                    return notify_fail("贪多嚼不烂，次数多过十次你记不住。\n");
            if (times <0)
                return notify_fail("你想干吗？\n");
            {
            }
            if(me->is_busy())
            {
                write("你正忙着呢。\n");
                return 1;
            } 
            if( (int)me->query("jing",) < 50 * times)
            {
                write("你精神不够集中，无法细看这段文字。\n");
                return 1;
            }

            message_vision("$N正专心观看牌坊后的文字。\n", me);
            if( (int)me->query_skill("daguangming-xinfa",1) > 200)
            {
                    write("你看了半天，发觉牌坊后的文字对你而言太浅了。\n");
                    return 1;
            }
            if( (int)me->query_skill("literate",1) < 1)
            {
                    write("你根本就是一个文盲，啥也没学会。\n");
                    return 1;
            }
            else
            {
                message_vision("$N仔细看了一段时间奇怪的文字,似乎有些心得。\n", me);
                me->add("jing", -50 * times);
                me->improve_skill("daguangming-xinfa",(int)(me->query_skill("literate",1)/2+random(me->query("int"))/3) * times);
                return 1;
            }
        }
        else
        {
            tell_object(me,"正确的格式是watch 牌坊 <次数>。\n");
            return 1;
        }

        
}



