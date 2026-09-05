//大境门 /d/jinyang/dajingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_dan();
void create()
{
        set("short", "酒家");
        set("long", 
"这里是张家口最大的一家酒家，各色菜式齐全。墙上贴着菜单(dan)。\n"

        );
        
        set("exits", ([
                "east" : __DIR__"northstreet",
                //"north" : __DIR__"dajingmen",
                //"southwest" : __DIR__"citywall2",
                //"south" : __DIR__"guangchang",
                
        ]));
		set("item_desc",
        ([
        "dan":(:look_dan:),
        ]));
        set("objects", ([
		__DIR__"npc/xiaoer" : 1,
        ]));
        set("zjk_jiujia",1);
        setup();
   
}

string look_dan()
{
	string msg="本店提供：\n";
	msg+="1.熟牛肉 10两\n";
	msg+="2.面饼 2两\n";
	msg+="3.羊汤 5两\n";
	msg+="任君挑选，请点(order)菜号。\n";
	return msg;
}

void init()
{
	add_action("do_order","order");
	add_action("do_eat","eat");
}
int check_huang(object huang)
{
	if (!huang)
	{
		this_object()->delete("using");
		return 1;
	}
	if (!present(huang,this_object()))
	{
		this_object()->delete("using");
		return 1;
	}
	remove_call_out("check_huang");
	call_out("check_huang",1,huang);
	return 1;
}
int huang_appear(object me)
{
	object huang;
	if (!me->query("shediaoquest/zjk")) return 0;
	if (me->query("shediaoquest/zjk")==3) return 0;
	if (this_object()->query("using")) return 0;
	this_object()->set("using",1);
	remove_call_out("check_huang");
	call_out("check_huang",1,huang);
	me->set_temp("shediaoquest/zjk/meethuang",1);
	message_vision("$N你正吃得痛快，忽听店门口吵嚷起来。\n",me);
	huang=new(__DIR__"npc/huang");
	huang->move(this_object());
	huang->appear(me);
	return 1;
}
int do_eat(string arg)
{
	object food,me=this_player();
	if (!arg)
	{
		return 0;
	}
	if (!food=present(arg,me))
	{
		return 0;
	}
	if (me->query("shediaoquest/zjk")==3)
	{
		return 0;
	}
	if (food->query("zjk_food")==1&&(me->query("shediaoquest/zjk")==1||me->query("shediaoquest/zjk")==2))
	{
		me->set_temp("shediaoquest/zjk/food1",1);
		if (me->query_temp("shediaoquest/zjk/food2")&&!me->query_temp("shediaoquest/zjk/meethuang"))
		{
			huang_appear(me);
			return 0;
		}
		me->set("food",me->max_food_capacity()/2);
		tell_object(me,"你觉得自己却不甚饱，再吃点面饼吧。\n");
		return 0;
	}
	if (food->query("zjk_food")==2&&(me->query("shediaoquest/zjk")==1||me->query("shediaoquest/zjk")==2))
	{
		me->set_temp("shediaoquest/zjk/food2",1);
		if (me->query_temp("shediaoquest/zjk/food1")&&!me->query_temp("shediaoquest/zjk/meethuang"))
		{
			huang_appear(me);
			return 0;
		}
		me->set("food",me->max_food_capacity()/2);
		tell_object(me,"你觉得自己口中无味，再吃点熟牛肉吧。\n");
		return 0;
	}
	return 0;
}
int do_order(string arg)
{
	object food,me=this_player();
	int no;
	if(!arg || (sscanf(arg, "%d",no)< 1 ))
	{
		tell_object(me,"店小二道：客官，你要点哪道菜啊？\n");
		return 1;
	}
	if (no<=0||no>3)
	{
		tell_object(me,"店小二道：没这道菜啊！\n");
		return 1;
	}
	message_vision("$N提高音量，喊了一声：上菜！\n",me);
	if (no==1&&MONEY_D->player_pay(me,1000))
	{
		food=new(__DIR__"obj/food1");
		message_vision("店小二为$N端上了一份"+food->query("name")+"。\n",me);
		food->move(me);
		return 1;
	}
	if (no==2&&MONEY_D->player_pay(me,200))
	{
		food=new(__DIR__"obj/food2");
		message_vision("店小二为$N端上了一份"+food->query("name")+"。\n",me);
		food->move(me);
		return 1;
	}
	if (no==3&&MONEY_D->player_pay(me,500))
	{
		food=new(__DIR__"obj/food3");
		message_vision("店小二为$N端上了一份"+food->query("name")+"。\n",me);
		food->move(me);
		return 1;
	}
	
	else
	{
		message_vision("店小二对$N道：本店吃饭，概不赊账！\n",me);
		return 1;
	}
}