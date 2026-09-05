#include <ansi.h>
inherit ITEM;
void init();
int to_read(string);
void create()
{       
        set_name(YEL"射雕英雄传"NOR, ({ "shediao", "zhuan" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", YEL"这是一册记录郭靖毕生丰功伟绩的小说，乃武侠小说中难能可贵之精品。\n比较适合那些高手们阅读."NOR);
		set("value", 5000);
		set("material", "paper");
                		
	}
}
void init()
{
 add_action("to_read","read");
}                           

int to_read(string arg)
{ 	object me;
	me = this_player();
	if ( !arg || ( arg != "shediao" && arg!= "zhuan") )
		return notify_fail("什么？\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

        if ((int)me->query("jing")< 52)
                  return notify_fail("你已经很累了，歇歇在读吧,身体要紧.\n");
	me->add("jing",-50);
       	message_vision("$N正专心看着一本厚厚的小说。\n", me);
       	switch( random(3) ) 
	{
	    case 1:
		if ( (int)me->query_skill("parry", 1) < 150)
		{
			me->improve_skill("parry", me->query("int"));
			write("你思索着小说中关于防御的情节，对基本招架有一些新的理解.\n");
			me->set_temp("book_learned",1);
		}          
                else
                {write("你看着看着觉得郭靖的攻防技巧也不过如此。\n");
			me->set_temp("book_learned",1);}
		break;
	    case 0:
            
		if ( (int)me->query_skill("force", 1) < 150)
		{
			me->improve_skill("force", me->query("int"));
			write("你思索着小说中关于内功的情节，对基本内功有一些新的理解.\n");
			me->set_temp("book_learned",1);
		}      
                else
                {write("你看着看着觉得郭靖的内功也不过如此。\n");
			me->set_temp("book_learned",1);}
		break;


	}       

	if ( !me->query_temp("book_learned") )
	{
		write("你拿起小说翻了一回儿，似乎没太懂，又接着看了下去。\n");
	}        
        me->delete_temp("book_learned");
	return 1;
}
