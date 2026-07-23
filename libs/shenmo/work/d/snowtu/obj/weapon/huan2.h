#include <ansi.h> 

void check_owner()
{
object ob = this_object();  
object me = environment(ob);
if ( !userp(me) )
	destruct(ob);
return;
}

void init()
{
check_owner();
add_action("do_huanyuan","huanyuan");   
return; 
}  
      
int do_huanyuan( )  
{ 
string str;
object ob = this_object();  
object me = environment(ob);
object wuqi; 
if ( !present(ob,me) )  return 1;
wuqi=new("/d/snowtu/obj/weapon/wuxian3");
wuqi->move(me);
if ( present(wuqi,me) )
	{
	str = "$N小心翼翼的将$n脱将下来，飞快的将它拆卸为$m。\n";
	str = replace_string(str,"$n",ob->name());
	str = replace_string(str,"$m",wuqi->name());
	message_vision(str, me);  
	destruct(ob);  
	}
return 1;           
}

