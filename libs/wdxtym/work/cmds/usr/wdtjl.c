//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int a;
	a=me->query("wudaota");
	if(a>10&&!me->query("jhxx"))
	{ 
        
	   me->add("gain/armor",100);
	   me->add("gain/max_qi",1000);
	   me->set("jhxx",1);
	   tell_object(me,HIW "你获得了"HIG"江湖新秀"HIW"称号！\n");
	  
	}
    
	if(a>30&&!me->query("wlgs"))
	{
	   me->add("gain/armor",300);
	   me->add("gain/damage",300);
	   me->add("gain/max_qi",3000);
	  // me->set("jhxx",0);
	   me->set("wlgs",1);
	   tell_object(me,HIW "你获得了"HIY"武林高手"HIW"称号！\n"); 
	   		
	}
	
	if(a>70&&!me->query("jhcs"))
	{
	   me->add("gain/armor",1000);
	   me->add("gain/damage",1000);
	   me->add("gain/max_qi",30000);
	  // me->set("wlgs",0);
	   me->set("jhcs",1);
	   me->move("/d/city/kedian");
	   tell_object(me,HIW "你获得了"HIC"江湖"HIY"传说"HIW"称号！你打通了武道塔!\n"NOR""); 
	}
	else
	   tell_object(me,HIW "你没有什么可以领取的!\n"NOR""); 	
   return 1;
}

int help (object me)
{

	return 1;
}