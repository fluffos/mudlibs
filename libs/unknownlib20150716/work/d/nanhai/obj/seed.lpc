// created 4/5/1997 by snowcat
#include <ansi.h>
inherit ITEM;

nosave int t = 0;

void create()
{
	set_name("竹米", ({ "seed"}));
  	set_weight(100);
	if( clonep() )
    		set_default_object(__FILE__);
  	else
  	{
    		set("long","一颗小小的竹米，可以种出竹子来。\n");
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
      			message_vision ("竹米绽裂开，露出了一颗绿芽。\n",who);
      			set_name("绿芽", ({ "germ"}));
			set("long","一株正在长大的小绿芽。\n");
      			set("unit", "株");
    		}
    		else	message_vision ("竹米动了一下，胀大了一点点。\n",who);
  	}
	else if(query("id") == "germ")
  	{
    		if( random(6) == 0)
    		{
      			message_vision ("绿芽终于长高了，变出了一株嫩绿嫩绿的竹笋。\n",who);
      			me->set_name("竹笋", ({ "zhu sun"}));
      			me->set("long","一棵嫩绿嫩绿的竹笋。\n");
      			me->set("unit", "棵");
    		}
    		else	message_vision ("绿芽咔嚓一声长高了一截。\n",who);
  	}
	else if( me->query("id") == "zhu sun")
  	{
    		if( random(10) == 0)
    		{
      			message_vision ("竹笋脱去了笋壳，终于长成了一株纤细的小竹子！\n",who);
      			me->set_name("竹子", ({ "zhu zi"}));
      			me->set("long","一株纤细的小竹子。\n");
      			me->set("unit", "株");
    		}
    		else	message_vision ("竹笋咔嚓一声长高了一截。\n",who);
    	}
    	else if( me->query("id")=="zhu zi" )
    	{
    		if( random(10)>0 )
    			message_vision ("竹子在风中跳起了舞。\n",who); 
    		else	
    		{
    			if( me->query("zhuzi")>=3 )
    			{
    				object zhu;
    				message_vision ("竹子上枝叶茂密，发出炫目的光芒！\n",who);
      				zhu = new (__DIR__"zhuzi");
      				if( query("owner_id") )
      					zhu->set("owner_id",query("owner_id"));
      				zhu->move(who);
      				destruct(me);
      				return;
    			}
    			if( me->query("zhuzi")>=2 )
    			{
    				me->add("zhuzi",1);
    				message_vision ("竹子上又冒出了一片竹叶。\n",who);	
    			}
    			else
    			{
    				me->add("zhuzi",1);
    				message_vision ("竹子上又长出了一支竹枝，越发碧绿。\n",who);	
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
