//yijing
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("易传残本", ({"yi zhuan", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
        	set("unit", "本");
		set("long", "一本古书，篇首写道“一阴一阳之谓道”。可惜，经书不全。\n");
        	set("material", "paper");
        }
        setup();
}

void init()
{
	add_action("do_read","read");
	add_action("do_read","du");
	add_action("do_read","study");
}	

void du_book(object me,int t)
{
	string str,*msgs;
	remove_call_out("du_book");
	if( !me || !living(me) 
	 || !present(this_object(),me) )
	 	return;
	str = read_file("/doc/book/yizhuan");
	if( str )
	{
		msgs = explode(str,"\n");
		if( msgs && arrayp(msgs) && sizeof(msgs)>1 )
		{
			str = msgs[random(sizeof(msgs))];
			if( str )
				tell_object(me,"你摇头晃脑的吟道：“"+str+"”，感觉意犹未尽。。。\n");
		}		
	}		
	if( me->is_knowing("puti_yinyang")>0 )
	{
		message_vision("$N哈哈一笑：这些个偶已经会了。说完，随手将$n丢在了一边。\n",me,this_object());
		me->start_busy(1);
		destruct(this_object());
		return;
	}
	if( query("owner_id")!=me->query("id") )
	{
		message_vision("$N看得头脑发胀，不知所云，顺手就将$n丢在了一边。\n",me,this_object());
		me->start_busy(1);
		destruct(this_object());
		return;
	}
	t = t-1;
	if( t>0 )
	{
		message_vision("$N看得兴起，高兴得抓耳挠腮，连声道：好个造化，好个造化！\n",me);
		message_vision("$N沾了口唾沫，兴奋的又翻起一页看了下去。\n",me);
		me->start_busy(5);
		call_out("du_book",3+random(3),me,t);
		return;
	}
	else
	{
		tell_object(me,"你沉寂在阴阳演练中不能自己，陡然间豁然开朗，对阴阳之道有了全新的领悟！\n\n");
		if( random(6)==1 )
		{
			me->set_knowing("puti_yinyang",1);
			tell_object(me,HIY"你领悟两仪剑法「阴字诀」的奥妙！\n"NOR);
		}
		else
		{
			me->set_knowing("puti_yinyang",2);
			tell_object(me,HIY"你领悟两仪剑法「阳字诀」的奥妙！\n"NOR);
		}
		me->save();
		me->start_busy(1);
		destruct(this_object());
		return;
	}	
}		

int do_read(string arg)
{
	int t;
	object me = this_player();
	
	if( !arg || !id(arg) || !present(this_object(),me) )
		return 0;
	if( me->is_busy() )
		return notify_fail("你现在正忙着呢。\n");
	t = me->query_int();
	t = 100-t;
	t/= 6;
	if( t<2 )
		t = 2;
	if( t>5 )
		t = 5;			
	message_vision("$N拿着$n仔细研读一番。\n",me,this_object());
	me->start_busy(5);
	remove_call_out("du_book");
	call_out("du_book",3,me,t);
	return 1;
}		