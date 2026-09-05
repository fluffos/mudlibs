// jiuyin-zhenjing1.c
#include <ansi.h>
inherit ITEM;
int do_study(string arg);

void create()
{
     set_name("铁板床" , ({ "bed", "iron bed" }));
        set_weight(2000);
        set("unit", "块");
        set("long", "这是一块用来铺床的铁板，上面刻满了字迹，看来是一篇有关内功的心法。\n");
        set("value", 500);
	set("no_drop",1);
	set("no_give",1);
	set("no_steal",1);
    set("no_get",1);
	set("mingjiao",1);
        set("material", "iron");
	setup();
}

void init()
{
	add_action("do_study","study");
	add_action("do_study","du");
	add_action("do_get","get");
	add_action("do_move","move");

}

int do_move()
{
	object me = this_player();
	
	if (me->query_temp("riyue/movexizi"))
		return notify_fail("你已经移开了席子，还要把它放哪儿？\n");
	message_vision("$N把席子胡乱一卷，扔在了墙角。\n",me);
	me->set_temp("riyue/movexizi",1);
	return 1;
}


int do_get(string arg)
{
	if ( arg == "bed" )
	{ 
		tell_object(this_player(),"把床背在身上走，到哪儿睡哪儿？你可真懒！\n");
		return 1;
	}
	else 
	return 0;
}

int do_study(string arg)
{
	object me;
	me = this_player();
	if(arg == "bed")
	{
		if (!me->query_temp("riyue/movexizi"))
		{
			tell_object(me,"床上的席子当住了许多字，你根本看不懂。\n");
			return 1;
		}			
	        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		{
                	tell_object(me,"你练了秃驴牛鼻子们的心法，还学吸星大法做什麽！\n");
			return 1;
		}
	        if ( me->query_skill("hunyuan-yiqi",1)
	        || me->query_skill("huntian-qigong",1)
	        || me->query_skill("jiuyang-shengong",1)
	        || me->query_skill("taiji-shengong",1) 
		|| me->query_skill("huagong-dafa",1)
		|| me->query_skill("beiming-shengong",1)
		|| me->query_skill("bihai-shengong",1)
		|| me->query_skill("linji-zhuang",1)
		|| me->query_skill("huashan-neigong",1)
		|| me->query_skill("jiuyin-shengong",1)
		|| me->query_skill("xiantian-gong",1)
		|| me->query_skill("zixia-shengong",1)
//                || me->query_skill("kuihua-shengong",1)
		|| me->query_skill("kurong-shengong",1)
		|| me->query_skill("yunu-xinfa",1))
                {
			tell_object(me,"你不先散了别派内功，怎能学吸星大法？！\n");
			return 1;
		}			
        	
		if ( (int)me->query_skill("literate", 1) < 100)
     	   	{
                	write("你看了半天，还是看不出头绪，只隐隐觉的好象自己读书写字水平不够。\n");
	                return 1;
        	}
		if ( (int)me->query_skill("force", 1) < 150)
       		{
                	write("你看了半天，觉的上面写的很有道理，但由于你内功不深，不能完全领悟。\n");
	                return 1;
        	}

		if((int)me->query("jing")>100)
		{
			me->add("jing",-50);
			if ( (int)me->query_skill("xixing-dafa", 1) < 180)
			{
				 message_vision("$N正专心研读铁板上的文字. \n", me);
				 me->improve_skill("xixing-dafa", (int)(me->query("int")+me->query_skill("literate",1)/10));
	      		  	 write("你对铁板上的文字研读了一会,似乎对吸星大法有些心得, \n");
			}
			else
			{
				write("你对铁板上的文字琢磨了一会，发现上面的太过浅薄，对你来说已毫无意义了.  \n");
			}
		}
		else 
		{
		  write("你现在有些疲倦，无法专心下来研读新知. \n");
		}
	}
	else {return notify_fail("你要读什么？\n");}
 return 1;
}
