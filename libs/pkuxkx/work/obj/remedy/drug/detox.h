#include <ansi.h>
#include "eat.h"
int do_eat(string arg)
{
	object me=this_player(),ob=this_object();
	if (!can_eat(ob,arg)) return 0;
	message_vision("$N服下了一"+ob->query("unit")+"$n。\n",me,ob);
	if(query_amount()<=1)
	write("你把剩下的"+ob->name()+"都服下了。\n");
	F_POISON->relief(me,ob->query("poison"),ob->query("dur"));
	add_amount(-1);
	return 1;
}