#include <ansi.h>

int armor_ob(object ob, object me, int damage)
{
		if (this_object()->query("material2") == "shen tie" )
		tell_object(me, MAG"效果一！\n"NOR);   
		
		if (this_object()->query("material2") == "xuanbing tie" )
		tell_object(me, HIG"效果二！\n"NOR);  
		
		if (this_object()->query("material2") == "yun shi" )
		tell_object(me, HIY"效果三！\n"NOR);  
		
		if (this_object()->query("material2") == "linglong yu" )
		tell_object(me, HIR"效果四！\n"NOR);     



}