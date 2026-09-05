#include <ansi.h>
#include <skill.h>
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
{ object me, where;
	string book;
	int times,forceskill,parryskill;
	me = this_player();
    where = environment(me);
	if(!arg || (sscanf(arg, "%s %d",book,times) < 1 ))
	{
		return notify_fail("指令格式：read shediao/zhuan [次数]\n");
	}
	if (  ( book != "shediao" && arg!= "zhuan") )
		return notify_fail("什么？\n");
 	if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
	if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if(times>50)
                return notify_fail("你也太贪了，最多做50次！\n");
	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");
	forceskill = me->query_skill("force",1);
	parryskill = me->query_skill("parry",1);
	if( forceskill * forceskill * forceskill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是缺乏实战经验，你对射雕上面所说的东西总是无法领会。\n");
			me->receive_damage("jing",30 );
			return 1;

      }
for ( int i=0; i < times; i++ )
{
	
        if ((int)me->query("jing")< 32)
        {
                  write("你已经很累了，歇歇在读吧,身体要紧.\n");
                  return 1;
        }
	me->add("jing",-30);
       	message_vision("$N正专心看着一本厚厚的小说。\n", me);
       	switch( random(2) ) 
	{
	    case 1:
		if( parryskill * parryskill * parryskill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是缺乏实战经验，你对射雕上面所说的东西总是无法领会。\n");
			me->receive_damage("jing",30 );
             return 1;
		}
		if ( (int)me->query_skill("parry", 1) < 180)
		{
			me->improve_skill("parry", me->query("int"));
			write("你思索着小说中关于防御的情节，对基本招架有一些新的理解.\n");
			me->set_temp("book_learned",1);
		}
              else{
                	write("你看着看着觉得郭靖的攻防技巧也不过如此。\n");
                        me->set_temp("book_learned",1);}

		break;
	    case 0:
		if( forceskill * forceskill * forceskill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是缺乏实战经验，你对射雕上面所说的东西总是无法领会。\n");
			me->receive_damage("jing",30 );
        return 1;
		}
		if ( (int)me->query_skill("force", 1) < 180)
		{
			me->improve_skill("force", me->query("int"));
			write("你思索着小说中关于内功的情节，对基本内功有一些新的理解.\n");
			me->set_temp("book_learned",1);
		}
           else{
                	write("你看着看着觉得郭靖的内功也不过如此。\n");
                        me->set_temp("book_learned",1);}

		break;
            
	}       

	if ( !me->query_temp("book_learned") )
	{
		write("你拿起小说翻了一回儿，觉得那上面的内容太平淡了。\n");
		return 1;
	}
	

}

	return 1;
}
