// /d/kunming/jinrilou
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "钟楼" );
        set("long", @LONG
这是一座钟楼，中间悬有有一巨钟，上面刻的有铭文：永乐大钟
钟身足有两人那么高，看起来足有上千斤，不知道当初是怎么挂上去
的，钟的两侧悬有一巨木，看来是用来敲钟(hit)用的。 
LONG
        );
        
        set("exits", ([
                "down"    :__DIR__"jinrilou",
                
                
        ]));

             
        setup();
       
}

int init()
{add_action("do_hit","hit");
}

int do_hit(string arg)
{
	object me=this_player();
	if (arg=="" || !arg ) return 0;
	if (arg=="钟")
	if ( (int)me->query_int() < 25 )
	{
	    if ( !(int)me->query_temp("temp") )
		{
		if ((int)me->query_str()< 25 ) return notify_fail("你敲不动这个大钟\n");
		message_vision("$N敲了一下钟“铛～～～”，钟声远远传了出去。\n",me);
		tell_object(me,"钟声在四周不停的回荡，震得你觉的头昏欲倒。\n");
		me->add("qi", -10);
		me->set_temp("temp",1);
		return 1;
		}
		message_vision("$N又敲了一下钟“铛～～～”，钟声远远传了出去。\n",me);
		tell_object(me,"钟声悠远的传了出去，许久又回声回来，你只觉得这钟声里似乎\n"+
			"包含有无穷的玄妙，无穷的佛意。\n");
		me->add("qi", -10);
		if (!random(10))
		{ 
		tell_object(me,"你静心倾听，觉的着声音似流水，似风吹，似鸟叫...你恍然大悟\n"+
					"这原来便是天籁之音，是大自然的声音。\n"+
					HIC "你的悟性提高了！\n" NOR);

if ( !me->query("kmint") && (int)me->query_int() < 18  )
{
			me->add("int",1);
me->set("kmint",1);
}
		}
		else tell_object(me,"你穷思奇妙，可怎么也不能明其理，只有作罢。\n");
		me->delete_temp("temp");
	}
	else tell_object(me,"你咚咚咚的敲了几下钟，真是无聊。\n");
	return 1;
}
	  		