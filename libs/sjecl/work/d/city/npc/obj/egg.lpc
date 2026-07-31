// egg.c 猪泥圣蛋
// created by campsun 2003/12/17
#include <ansi.h>

inherit ITEM;

int do_qiao(string);
string gGetRndColor();
void create()
{
    set_name(CYN "猪泥圣蛋" NOR, ({ "piggy's egg","egg" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个圣诞猪生的蛋，外面看起来花花绿绿的，不知道里面是什么东西。或者你可以"HIW"敲敲(Qiao)"NOR"看里面藏着什么好东西。\n");
		set("treasure",1);
		set("value", 10);
		set("no_give",1);
		set("no_drop",1);
		set("qiao",1);
		set("egg",1);
		set("material", "paper");
             }
	setup();
}
void init()
{
   	add_action("do_qiao", "qiao");
}

int do_qiao(string arg)
{
	object me,ob;	
	string strString;
	me=this_player();
	ob=this_object();

	if (arg!="egg") 
	{
		message_vision(HIR"$N用力在自己的脑门上狠狠的敲了一下，疼的眼冒金星。\n"NOR,me );	
		return 1;
	}
	if (!ob->query("qiao"))
	{ 
		tell_object(me,"请稍微等一下再敲。\n");	
		return 1;
	}

	switch (ob->query("egg"))
	{
		case 1:
			strString = HIG"$N敲着「$n"HIG"」，「"+gGetRndColor()+"冬"HIG"」、「"+gGetRndColor()+"冬"HIG"」、「"+gGetRndColor()+"冬"HIG"」、心情舒畅，越发觉得快乐开心。";
			ob->set("qiao",0);
			call_out("up_level2",10);
		break;
		case 2:
			strString = HIG"$N敲着「$n"HIG"」，「"+gGetRndColor()+"冬"HIG"」、「"+gGetRndColor()+"冬"HIG"」、「"+gGetRndColor()+"冬"HIG"」、这声音忽然让你想起自己在这个江湖中的点点滴滴。";
			ob->set("qiao",0);
			call_out("give_reward",5,me);
		break;
	}
	message_vision(strString + "\n"NOR,me,ob);
	return 1;
		
}
void up_level2()
{
	this_object()->set("qiao",1);
	this_object()->set("egg",2);	
	return;
}
void give_reward(object me)
{
	object cash;
	object *list;
	int number;	
	if(!objectp(me)) return;
	message_vision(HIG"有快乐、悲伤、感动、失落、开心、怨恨、无奈、兴奋、成就、友谊……\n"NOR,me);
	message_vision(HIY"◎◎◎◎◎◎◎"+gGetRndColor()+"　　　■ˉˉ　■　■　■ˉ■　ˉ■ˉ　■ˉˉ　ˉ■ˉ　■\\　　/■　　 ∧ 　　■ˉˉ　\n"NOR,me);
	message_vision(HIY"◎"HIW"祝圣诞　　"HIY"◎"+gGetRndColor()+"　　　■　　　■＿■　■＿■　　■　　■＿＿　　■　　■ \\　/ ■　　/　\\　　■＿＿　\n"NOR,me);
	message_vision(HIY"◎　　"HIW"生蛋猪"HIY"◎"+gGetRndColor()+"　　　■　　　■　■　■　\\ 　  ■　　　　■　　■　　■　\\/　■　 /＿＿\\　　　 ■　\n"NOR,me);
	message_vision(HIY"◎◎◎◎◎◎◎"+gGetRndColor()+"　　　■＿＿　■　■　■　 \\　＿■＿　＿＿■　　■　　■　　　■　/　　　\\　＿＿■　\n"NOR,me);
	message_vision(HIG"$N获得了【"HIW"一万五千点实战经验、二百点潜能、十点最大内力、十点最大精力、十张银票"HIG"】的奖励。\n"NOR,me);
	me->add("combat_exp",15000);
	me->add("potential",200);
	me->add("max_neili",10);
	me->add("max_jingli",10);
	cash = new("/clone/money/thousand-cash");
	cash->set_amount(10);
	cash->move(me);
	log_file("quest/sdgift",sprintf("%s %s(%s)敲开猪泥圣蛋得到奖励。\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id"))));

	
	list = filter_array(children(USER_OB), (: userp($1) && environment($1) :));

	for(number=0;number<sizeof(list);number++)
	{
		if (list[number]->query_temp("havegong")<=5) continue;
		if (list[number]->query("id")==me->query("id")) continue;
		if (list[number]->query("family/family_name")!=me->query("family/family_name")) continue;
		message_vision(HIG"$N因为积极参与拱猪获得了【"HIW"二百点潜能、五点最大内力、五点最大精力"HIG"】的奖励。\n"NOR,list[number]);
		list[number]->add("potential",200);
		list[number]->add("max_neili",10);
		list[number]->add("max_jingli",10);
		//cash = new("/clone/money/thousand-cash");
		//cash->set_amount(5);
		//cash->move(list[number]);
		log_file("quest/sdgift",sprintf("%s %s(%s)积极参与拱猪得到奖励。\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id"))));
		list[number]->delete_temp("havegong");	
	}
	destruct(this_object());	
}

string gGetRndColor()
{
	string* color = ({RED,GRN,YEL,BLU,MAG,CYN,HIR,HIG,HIY,HIB,HIM,HIC,HIW});
	return color[random(sizeof(color))];
}