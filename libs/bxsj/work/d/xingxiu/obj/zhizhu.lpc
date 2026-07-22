inherit ITEM;

#include <ansi.h>

void create() 
  {
   set_name("蜘蛛",({"zhizhu"}));
   set_weight(10);
   set("unit","只");
   set("value",0);
   set("cook/allow",1);
   set("cook/value",1);
   set("cook/type","zhizhu");
   setup();
   call_out("dest", 180);
  }

void dest()
{
	object owner,me=this_object();
	string a="";
	if(owner=environment(me)){
	if(!living(owner)){
		if(owner=environment(owner))
		a="从坛子里钻了出来，";
	}
	else a="从你身上";
	if(!random(4)){
	if(owner)message("vision", me->name()+a+"爬到地上，你想抓的时候已经不见了。\n", owner );
        destruct(this_object());
}
else call_out("dest", 180);
return;
}
return;
}
