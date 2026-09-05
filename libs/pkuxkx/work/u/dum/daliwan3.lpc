//tianyuebing  中秋月饼(加100000正神)
//Made By jason@mudnow.com
//2000-5.-6
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("大力丸",({"dali wan","wan"}));
        set("long","这是度每老先生亲自制作的大力丸(eat)?\n");
        set("unit","块");
        set("no_drop",1);
        set("no_get",1);
        set("value",0);
        set("no_store",1);
       setup();
}

void init()
{
    add_action("do_eat","eat");
}

int do_eat(string arg)
{
object me=this_player();
/*	object user=this_player();
	string *sname;//sname加来返老还童用的
	int *svalue;
        mapping skill_status;    //灵鹫宫返老还童用

		skill_status = user->query_skills();
        		sname  =keys(skill_status);  
			svalue=values(skill_status);
       			for(int i=0; i<sizeof(skill_status); i++) 
			{
				user->set_skill(sname[i],svalue[i]+1);	    
			}
*/
me->add("shen",100000);
return 1;
}
