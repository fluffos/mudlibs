// xuedao-miji.c 

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"血刀秘籍"NOR, ({ "xuedao-miji","miji","shu", "book" }));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是本略微发黄的手抄小册子，看来年代久远，里面绘制了些裸体男子画像。\n");
		set("value", 500);
                set("treasure",1);
		set("material", "paper");
		set("skill", ([
			"name":	"xuedao-jing",	
			"exp_required":	0,	
			"jing_cost":	30,	
			"difficulty":	15,	
             		"max_skill":	101	
		]) );
	}
}
