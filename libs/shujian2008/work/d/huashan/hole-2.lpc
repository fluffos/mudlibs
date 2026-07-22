// Room: /d/huashan/hole-2.c
// Date: Look 99/03/25

inherit ROOM;

#include <ansi.h>

int init();
int do_use(string arg);
void close_out();
int do_study(string arg);

void create()
{
	set("short", "石洞");
	set("long", @LONG
这里静悄悄的，加上一片漆黑，你什么也听不见，什么也看不见。
LONG	);
	set("no_clean_up", 0);
	setup();
}
 
int init()
{
	add_action("do_use","use");
	add_action("do_study","study");
}

int do_use(string arg)
{
	object me, room, fire;
	me = this_player();
        if (!(fire=present("fire", me)))  return 0;
	if ( !arg || arg =="") return 0;
	if ( arg != "fire" ) return 0;
	write(	"  你点燃了火折，发现眼前是一个极大的洞，足可容下得千人之众。\n"
		"你举起火折往山洞四壁察看，石壁上刻着一些图形和文字，文字大意\n"
		"是五岳剑派的前辈暗算魔教长老于此，被魔教长老所杀，魔教长老被\n"
		"困于此，终于饮恨而亡。那些图形是魔教长老击破五岳剑派的前辈绝\n"
		"招的图形。\n");
	if ( !(room == find_object(__DIR__"hole-1")) )
		room = load_object(__DIR__"hole-1"); 
	{
	set("exits/east", __DIR__"hole-1");
	me->set_temp("marks/study",0);
	me->add_temp("marks/study",1);
	fire->move(environment(me));
	destruct(fire);
	fire = new(__DIR__"obj/firing");
	fire->move(me);
	remove_call_out("close_out");
    call_out("close_out",120);
	}
	return 1;
}

void close_out()
{
	object room;
	if ( !(room == find_object(__DIR__"hole-2")) )
		room = load_object(__DIR__"hole-2"); 
	room->delete("exits/east");
}

int do_study(string arg)
{
        object me, fire;
        me = this_player();
        if (!(fire=present("fire", me)))  return 0;
	if ( me->query_temp("marks/study") < 1) return 0;
        if ( !arg || ( arg != "pictures" ) )  return 0;
        if ( (int)me->query_skill("literate") < 30 )
		{
                write("你的后天学识太少，无法领悟图形上的高深的剑法。\n");
		return 1;
		};
        if ( (int)me->query("jing") < 40)
		{
                write("你已经很累的了，先休息一下吧。\n");
		return 1;
		}

	if ( (int)me->query_skill("sword",1) < 50 )
		{
                write("你的剑法火候太浅，无法领悟图形上的高深的剑法。\n");
		return 1;
		}
        me->add("jing", (-1)*random(40));
        message_vision("$N正专心研究石壁上的图形。\n", me);
	if ( (int)me->query_skill("sword", 1) < 101)
	{
	        me->improve_skill("sword", random(me->query("int")) );
	        write("你对着石壁上的图形琢磨了一回儿，似乎对剑法有点心得。\n");
        }
	else
	        write("你对着石壁上的图形琢磨了一回儿，觉得没什么意思，可能对于你来说太浅了。\n");
	return 1;
}
