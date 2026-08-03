// 可以戴的花
// from /d/city/yangzhou/npc/obj/hong_m.c
// create by akuma 12/15/1998

#include "ansi.h"
#include "dbase.h"
#include "armor.h"

inherit HEAD;

int do_wear (string arg)
{
  	object flower = this_object();
  	string name = flower->query("name");
  	string msg;

	switch (random(4))
  	{
    		case 0:
      			msg = YEL"$N拿起"+name+YEL"轻轻插在发际，低头婉尔一笑。\n"NOR;
      			break;
    		case 1:
      			msg = YEL"$N将"+name+YEL"轻轻别在发际，不禁满面羞红。\n"NOR; 
      			break;
    		case 2:
      			msg = YEL"$N温柔地把"+name+YEL"别在发鬏上。双眉一弯，甜甜地笑了。\n"NOR; 
      			break; 
    		case 3:
    			msg = YEL"$N将长发轻轻一甩，将"+name+YEL"别在上面。\n"NOR; 
    			break; 
  	}
	flower->set("wear_msg",msg);
	return 0;
}

int do_remove (string arg)
{
  	object flower = this_object();
  	string name = flower->query("name");
  	string msg;	
	
	msg = YEL"$N将"+name+YEL"轻轻地摘下来……\n"YEL; 
  	flower->set("unequip_msg",msg);
  	return 0;
}

int do_smell (string arg)
{
  	object me = this_player();
  	object flower = this_object();
  	string name = flower->query("name");
	string msg;

  	if ( !id(arg) )
		return 0;
	
  	if ( this_player()->query("gender") != "女性" )
    	{	
		msg = YEL"$N拿起"+name+YEL"闻了闻，一股香气扑鼻。\n"NOR;
	}
	else
	{
		switch (random(4))
  		{
    			case 0:
     				msg = YEL"$N轻轻闻着"+name+YEL"的扑鼻香气，不禁痴了……\n"NOR; 
     				break; 
	    		case 1:
				msg = YEL"$N捧着"+name+YEL"闻了一下：幸福地笑了。\n"NOR; 
				break; 
    			case 2:
      				msg = YEL"$N低头看着手中的"+name+YEL"，思绪竟仿佛这花香一样越飘越远。\n"NOR; 
      				break; 
    			case 3:
      				msg = YEL"$N低头将"+name+YEL"轻轻一嗅，不禁晕红满面。\n"NOR; 
      				break; 
  		}
  	}
	message_vision (msg,me);
    	return 1;
}

