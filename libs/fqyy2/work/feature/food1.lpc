// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	if (!query("decay")) {
		set("decay", 1);
		call_out("decay", 280);
	}
}



void decay()
{
	object me = this_object(), ob = environment();
        if (!me || !ob) return;
	switch(add("decay", 1)) {
		case 2:
			set_temp("apply/long", ({ query("long") + "可是看起来不是很新鲜。\n" }));
			tell_object(ob, me->name()+"的颜色有些不对了。\n");
			break;
		case 3:
			set_temp("apply/long", ({ query("long") + "可是正在散发出一股难闻的味道。\n" }));
			tell_object(ob, me->name()+"散发出一股难闻的味道。\n");
			break;
		case 4:
			set_temp("apply/long", ({ query("long") + "可是有些腐烂了。\n" }));
			tell_object(ob, me->name()+"有些腐烂了，发出刺鼻的味道。\n");
			break;
		default:
			tell_object(ob, me->name()+"整个腐烂掉了。\n");
			destruct(this_object());
			return;
	}
	call_out("decay", 150);
}
