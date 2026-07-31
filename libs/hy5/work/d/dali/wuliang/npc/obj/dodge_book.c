// by cool 980719
// Modify By River 98/12
#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_du", "read");
     	add_action("do_fan", "fan");	
     	add_action("do_fan", "find");
	add_action("do_lingwu", "study");
        add_action("do_lingwu", "lingwu");
}

void create()
{
        set_name(HIW"帛卷"NOR, ({ "bo juan", "bojuan", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "一本烂的不成样子的帛制长卷。\n"); 
                set("unique", 1);
                set("treasure", 1);
                set("material", "silk");
		set("book_fan",4);
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
        }
}

int do_du(string arg)
{
        object me = this_player();
        mapping skill;      
        if (!(arg=="bo juan" || arg == "bojuan" || arg == "book"))
        return 0;
        if( me->is_busy()) 
            return notify_fail("你现在正忙着呢。\n");
        if( me->is_fighting() ) 
            return notify_fail("你无法在战斗中专心下来研读新知！\n");
        if(!id(arg))
             return notify_fail("你要读什么？\n");
        if(!me->query("dali/meet_dy1") || !me->query("dali/pass"))
             return notify_fail("帛卷撕的乱七八糟，什么都看不清，你无法从里面学到东西。\n");
        if(!me->query_temp("book", 1))
             return notify_fail("帛卷撕的乱七八糟，什么都看不清，你无法从里面学到东西。\n");
	if((int)me->query("jing") < 25 )
             return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");        
	if((int)me->query("neili") < 35 )
             return notify_fail("你内力不够，无法专心下来研读新知。\n");        
        if((int)me->query_int() < 34)
             return notify_fail("你的悟性不足钻研这么高深的武功。\n");
        if((int)me->query_skill("literate", 1) < 100)
             return notify_fail("你看不懂这上面所写的文字。\n"); 
        if((int)me->query("max_neili") < 1200 )
             return notify_fail("你内力修为不够，无法钻研这么高深的武功。\n");
        if((int)me->query("combat_exp")< 200000)
             return notify_fail("你的实战经验不够，无法钻研这么高深的武功。\n"); 
        if( me->query_skill("lingboweibu", 1) > 60)
	     return notify_fail("你研读了一会儿，觉得书上讲的步法，如果不身体力行的练习是无法领会的。\n");
          me->receive_damage("jing", 15);
          me->add("neili",-(int)me->query_skill("lingboweibu", 1)/2);  
          me->improve_skill("lingboweibu", (int)me->query_skill("literate", 1)/3+1);
          write("你仔细研读着帛卷上的步法。\n");
         return 1;
}

int do_fan(string arg)
{
       object me = this_player();        		       
       if (!(arg=="bo juan" || arg == "bojuan" || arg == "book"))
           return 0;
       if ( me->is_busy()) 
           return notify_fail("你现在正忙着呢。\n");
       if( me->is_fighting() ) 
           return notify_fail("你无法在战斗中做这个事情。\n");
       if (!id(arg))
           return notify_fail("你要翻什么？\n");
       if( me->query_temp("book"))
           return notify_fail("你已经找到你想要的了。\n");
       if (me->query_temp("find") < 3 ){
         write("你仔细翻看着被撕的破烂的帛卷，希望能从中找出点什么。\n");
         me->add_temp("find", 1);         
         return 1;
         }
         write("你翻到最后，不由得大为狂喜，这部分并没有被撕烂，题着“凌波微步”四字，\n"+
               "其后绘的是无数足印，注明“妇妹”、“无妄”等等字样，尽是易经中的方位。\n"+
	       "只见足印密密麻麻，不知有几千百个，自一个足印至另一个足印均有绿线贯串，\n"+
	       "线上绘有箭头，料是一套繁复的步法。最后写着一行字道：“猝遇强敌，以此 \n"+
	       "保身，更积内力，再取敌命。”\n");
	 me->set_temp("book", 1);
         me->delete_temp("find");
         return 1;	    
}

int do_lingwu(string arg)
{
	object me = this_player();
	int level, jingcost;
        if ( !arg ) return 0;
        if (!(arg == "bo juan" || arg == "bojuan" || arg=="book"))
	   return notify_fail("你要学什么？\n");
	  level = me->query_skill("lingboweibu", 1);
	if (level > me->query_skill("dodge", 1))  
           return notify_fail("你先打好轻功的根基吧！\n");
	if ( !me->is_fighting())
           return notify_fail("你觉得必须在战斗中领悟。\n");
        if ( level <= 100 ) {
	  jingcost = level / 3 + random(level / 3);
	if (me->query("jing") <= jingcost)
           return notify_fail("你太疲倦了，先歇歇吧！\n");
        if (me->query("neili") < 20)
           return notify_fail("你的内力不够，先歇歇吧！\n");
          me->receive_damage("jing", jingcost);
          me->add("neili",-random(20));
	  me->improve_skill("lingboweibu", (int)me->query_skill("literate", 1)/3+1);
	  message_vision("$N战斗中闭上双眼，回想着帛卷上的步法。\n", me);
	  return 1;
	  }
      return notify_fail("你已经把书中的精髓都领悟到了。\n");
}
