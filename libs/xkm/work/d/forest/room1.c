inherit ROOM;

#include <ansi.h>


void create()
{
    set("short", HIM"后院"NOR);
    set("long",
"这里是长乐帮的后山，供帮主和几位香主休闲的好地方，风影宜人种满
了各种花草，假山旁边有一汪热烘烘的温泉，周围有几位使女打理着。\n");
	   set("objects", ([
 	 __DIR__"npc/shiji": 1,
  	  ]) );
       set("exits", ([
		"out": __DIR__"clhuayuan",
	]));
	
        set("outdoors","forest");
        
        set("cost",0);
        
        setup();
 
}

void init()
{
   add_action("do_xizao", "xizao");
   add_action("do_xizao", "paozao");
   add_action("do_hui", "hui");
}
int do_xizao()
{
	object me = this_player();
		
	if (!stringp(me->query_temp("bangs/pos")) )
	{	
		write("你不是长乐帮香主，不能享受这里的温泉浴。\n");
		return 1;
	}
	
	if (me->query_temp("is_swim") == 1)
		return notify_fail("你正在温泉里泡着呢！\n");
		
	
	if (me->is_busy())
		 return notify_fail("你现在正忙着呢。\n");
		 
	
	if ( intp (me->query("bangs/bathtime")) )
		if (uptime() < me->query("bangs/bathtime") + 10 )
			return notify_fail("你才洗过不久，泡多了可不太好。\n");
			
	message_vision(HIG"$N兴奋地往温柔乡跳下去，一名小妾过来替你脱靴解带，服侍得十分周到。\n"NOR,me);
        message_vision(HIG"小妾替$N洗刷着全身，不一会儿，你就哼起了小调。\n"NOR,me);
 	me->set_temp("is_swim",1);
	me->start_busy(3);
	//me->add("clbscore",-1);
	call_out("bathtwo",3,me);
	return 1;
}

void bathtwo(object me)
{
	write(HIG"你浸在温泉之中，全身放松，让泉水渗透你着你的每寸肌肤和毛发。\n"NOR);
	me->start_busy(4);
	call_out("baththree",4,me);
}

void baththree(object me)
{
	write(HIG"你享受着泉水的滋润，感觉自己全身的精力都在迅速的恢复中。\n"NOR);
	me->start_busy(4);
	call_out("bathfour",4,me);
}

void bathfour(object me)
{
	if (!random(10))
	{
		write(HIW"你稍一运功，发现自己不但劲气全复，精力修为似乎还更有进境。\n"NOR);
                me->add("max_jingli",1);
                me->add("eff_jingli",1);
	}
	me->start_busy(4);
	call_out("bathfive",4,me);
}

void bathfive(object me)
{
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") 
   	|| (int)me->query("eff_jing") < (int)me->query("max_jing")) {
	 
	  if ( (int)me->query("eff_qi") < (int)me->query("max_qi") ) {
		me->receive_curing("qi", 150);
	}
	
	if ( (int)me->query("eff_jing") < (int)me->query("max_jing") ) {
		me->receive_curing("jing", 150);
	}message_vision(HIY "$N泡了一会只觉伤势大为好转，可见此泉还有疗伤的作用。\n\n" NOR, me);
	}
        me->set("qi", me->query("eff_qi"));
        
        me->set("jing", me->query("eff_jing"));
        
        me->set("neili", me->query("max_neili"));

        me->set("jingli", me->query("max_jingli"));

	me->delete_temp("is_swim");
	me->set("bangs/bathtime",uptime() );
        message_vision(HIG"$N终于洗完啦，由小妾服侍着穿好衣物，精力充沛地活动了一下筋骨。。\n"HIG,me);
        message_vision(HIG"$N洗完澡，小妾服侍着$N穿戴整齐，只觉精力充沛，该活动一下了。\n"HIG,me);
 
}

int do_hui()
{
  object me;
  me=this_player();
   		
   		if (!stringp(me->query_temp("bangs/pos")) )
	{	
		write("你不是长乐帮香主,想回那里，还是出去吧!\n");
		return 1;
	}
	    
	      	if (me->query_temp("bangs/pos") == "凤翼堂") 
        	{
   		me->move(__DIR__"fang6");
                write(HIY"你回到自己的房间。\n"NOR);
                 }
        
        	if (me->query_temp("bangs/pos") == "龙灵堂") 
            	{
   		me->move(__DIR__"fang2");
   		write(HIY"你回到自己的房间。\n"NOR);
   		}
        
        	if (me->query_temp("bangs/pos") == "狮敏堂") 
            	{
   		me->move(__DIR__"fang3");
   		write(HIY"你回到自己的房间。\n"NOR);
   		}
        
            	if (me->query_temp("bangs/pos") == "熊威堂") 
            	{
   		me->move(__DIR__"fang4");
   		write(HIY"你回到自己的房间。\n"NOR);
   		
   		}
         
         	if (me->query_temp("bangs/pos") == "豹捷堂") 
            	{
   		me->move(__DIR__"fang5");
   		write(HIY"你回到自己的房间。\n"NOR);
   			
   		}
         
         	if (me->query_temp("bangs/pos") == "虎啸堂") 
            	{
   		me->move(__DIR__"fang");
   		write(HIY"你回到自己的房间。\n"NOR);
   		}
   	return 1;
}	

		


