inherit ITEM;

#include <ansi.h>

void create() 
{
   	set_name("蛇",({"du she"}));
   	set_weight(500);
   	set("unit","条");
   	set("value",0);
   	setup();
	if (clonep()) call_out("dest", 180);
}

void dest()
{
	object owner,me=this_object();
	string msg="";
	if(owner=environment(me)){
		if(!living(owner)){
			if(owner=environment(owner))
			msg="从你袖子里";
		}
		else msg="从你手里";
		if(!random(4)){
			if(owner){
				message("vision", me->name()+msg+"咻地蹿到地上，你想抓的时候已经不见了。\n", owner );
				destruct(this_object());
        		}
			else call_out("dest", 200);
		}
	}
}
