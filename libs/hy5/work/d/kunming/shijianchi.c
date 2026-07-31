// /d/kunming/shilin
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "试剑池" NOR);
        set("long", @LONG
这是一个小池塘，大小不过两三丈，中间有一块大石(stone)，看上去
有些古怪。南边有个小洞(dong)，似乎可以钻过去。
LONG
        );
        set("outdoors", "kunming");
           
        setup();
        
}

void init()
{
	add_action("do_jump", "jump");
        add_action("do_zuan", "zuan");
        add_action("do_poke",  "poke");
}

int do_jump(string arg)
{  
	object me;
        int i_dodge;
        
        me=this_player();
        i_dodge=(int)me->query_skill("dodge");
        if (!arg || arg != "up") return 0;
        if (i_dodge < 100 ) return notify_fail("莲花峰对于你来说太高了\n");
        else {   message("vision",
			"只见人影一晃"+me->name() + "奋不顾身向下跳去。\n",
			environment(me), ({me}) );
		 me->move(__DIR__"lianhua");
		 message("vision",
			"只见人影一闪"+me->name() + "从下面跳了上来。\n",
			environment(me), ({me}) );
               message("vinson","你纵身向上一跃，在空中转了两个圈，落在莲峰顶上。\n",me);
             }
	return 1;
}

int do_zuan( string arg)
{
	object me;
        me=this_player();
        if (!arg || arg !="dong") return 0;
        
        if ( me->query("gender") == "男性" )
            return notify_fail("你一个大男人，能钻进那么小的洞吗？\n");
        if ( me->query("gender") == "无性" )
            return notify_fail("你刚想往洞里面钻，忽然想起来，这种地方一般都是男\n"+
                                "女幽会的地方，象我这种人，还是别去的好。\n");
        if ( me->query("gender") == "女性" && (int)me->query("age")<25 )
            {	message("vision",
			me->name() + "一弯腰，钻进了小洞。\n",
			environment(me), ({me}) );
		me->move(__DIR__"xiaodong");
		message("vision",
			me->name() + "从从外面钻了进来。\n",
			environment(me), ({me}) );
            message("vinson","你一弯腰，向洞里面钻去，洞口很小，幸好你是女孩子，\n"+
                              "身子小，不费什么力就钻进去了。\n",me);
            }else return notify_fail("你那么大个人，怎么能钻进这么小的洞\n");
        return 1;
}

int do_poke( string arg)
{       
	object me,weapon;
        int i_sword, i_qi;
        me=this_player();
        i_sword=(int)me->query_skill("sword",1);
	i_qi=600/(int)me->query("int");
        if (!arg || arg=="") return 0;
	if (arg == "stone")
		{ 
		if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("没有剑可以吗？\n");
	        if( (int)me->query("qi") < i_qi) return notify_fail("你太累了，先休息一会吧。\n");
                if (i_sword < 20) 
			{message("vinson","你挺剑向大石刺去，忽然水花溅起，你刺了一个空。\n",me);
			 message("vision",
			 me->name() + "挥舞着长剑，拼命向大石头刺去。\n",
			 environment(me), ({me}) );}
	        if ( 20 <= i_sword && i_sword < 40) {
			message("vinson","你挺剑向大石刺去，忽然水花四溅，你只刺到了点边。\n", me);
			message("vision",
			me->name() + "挥舞着长剑，用力的向大石头刺去。\n",
			environment(me), ({me}) );}
		if ( 40 <= i_sword && i_sword < 60) {
                        message("vinson","你挺剑刺向大石，只听当的一声，你的剑差点脱手。\n", me);
			message("vision",
			me->name() + "挥舞着长剑，飞快的向大石头刺去。\n",
			environment(me), ({me}) );}
		if ( 60 < i_sword) {message("vision",
			me->name() + "挺剑刺向大石，只听得当的一声，长剑没入石头尺许！\n",
			environment(me), ({me}) );
			return notify_fail( HIW "你挺剑刺向大石，只听得当的一声，长剑没入石头尺许！\n" NOR);}
		me->improve_skill("sword", 2*i_sword);
                me->receive_damage("qi", i_qi );
		}
        else return notify_fail("你要刺什么？\n");
	return 1;	
}