// created 4/5/1997 by snowcat
#include <ansi.h>
inherit ITEM;
#include "message.h"

nosave int t = 0;

void create()
{
	set_name("花籽", ({ "seed"}));
  	set_weight(100);
	if( clonep() )
    		set_default_object(__FILE__);
  	else
  	{
    		set("long","一颗小小的花籽。\n");
    		set("unit", "颗");
  	}
  	setup();
  	set_heart_beat(30+random(30));
}

void init()
{
	set("water",0);
	add_action ("do_water", "water");
}

void grow (object who)
{
	object me = this_object();
  	string name = me->query("name");
  	string msg;

	t = t-1;
	if( t>0 )
		return;
	if( !environment() )
		return;
  	if( !who || !living(who) || !present(this_object(),who) 
  	 || query("dried") )
		return;
	if( query("id") == "seed")
  	{
    		if( random(6) == 0)
    		{
      			message_vision ("花籽绽裂开，露出了一颗绿芽。\n",who);
      			set_name("绿芽", ({ "germ"}));
			set("long","一株正在长大的小绿芽。\n");
      			set("unit", "株");
    		}
    		else	message_vision ("花籽动了一下，胀大了一点点。\n",who);
  	}
	else if(query("id") == "germ")
  	{
    		if( random(9) == 0)
    		{
      			message_vision ("绿芽终于长高了，在风中欢快地摇弋。\n",who);
      			me->set_name("绿草", ({ "plant"}));
      			me->set("long","一棵茁壮的绿草，上面有花苞。\n");
      			me->set("unit", "棵");
    		}
    		else	message_vision ("绿芽咔嚓一声长高了一截。\n",who);
  	}
	else if( me->query("id") == "plant")
  	{
    		if( random(12) == 0)
    		{
      			object flower;
      			message_vision ("绿草上的花苞绽开了！春天来了！\n",who);
      			flower = new (__DIR__"flower");
      			if( query("owner_id") )
      				flower->set("owner_id",query("owner_id"));
      			flower->move(who);
      			destruct(me);
      			return;
    		}
    		else
    		{
      			switch (random(3))
      			{
        			case 0: message_vision ("绿草在风中跳起了舞。\n",who); break;
        			case 1: message_vision ("绿草要开花了。\n",who); break;
        			case 2: message_vision ("绿草微笑着。\n",who); break;
        		}	
    		}
  	}
}

void heart_beat()
{
  	object me;
  	string msg;

	if( !environment() )
		return;
  	me = environment();
  	if( !userp(me) || !living(me) )
    		return;
	if( query("dried")) 
		return;
	if( me->query("id")!= "seed")
	{
  		switch(query("water"))
  		{
    			case 0: msg = name()+"长高了一点。\n"; break;
    			case 1: msg = name()+"有点蔫了，快淋一点水吧。\n"; break;
    			case 2: msg = name()+"开始发黄了。\n"; break;
    			case 3: msg = name()+"已经失去了绿色的光泽。\n"; break;
    			case 4: msg = name()+"看上去严重缺水，奄奄一息了。\n"; break;
    			default:
      				msg = name()+"干枯了。\n";
        			set("name","干枯的"+name(1));
        			set("dried",1);
        			break;
		}
  		message_vision(msg,me);
  		add("water",1);
  	}
  	grow(me);
}

int do_water (string arg)
{
  	object me = this_object();
  	object who = this_player();
  	string name = me->query("name");
  	string msg,*strs;
	
	if( !arg || !id(arg) || query("dried") )
		return 0;
	if( who->query("kee")<20 )
		return err_msg("你现在精疲力尽。\n");	
	if( me->query("water") >= 5)
  	{
    		message_vision ("$N的泪水一滴滴流在"+name+"上。\n",who);
    		return 1;
  	}
  	strs = ({
		"$N口含清水，喷在$n上。\n",
		"$N将一点清水洒在$n上。\n",
		"$N伸出手抓住细细的小雨，淋在$n上。\n",
		"$N小心地捧起一点点露水，滴在$n上。\n",
		"$N一阵心痛，泪水流在$n上。\n",
		"$N双手捧着$n，伸到窗外的小雨中……\n",
		"$N仔细地拿起一只小杯子，将水滴在$n上。\n",
		"$N捧起从野外采来的晨露，洒在$n上。\n",
		"$N用手指蘸着清水，一点点滴在$n上。\n",
	});	
	who->receive_damage("kee",10);
	msg = strs[random(sizeof(strs))];
	message_vision (msg,who,this_object());
  	me->set("water",0);
  	if( t<=0 )
  		t = 5+random(5);
  	grow(who);
  	return 1;
}
