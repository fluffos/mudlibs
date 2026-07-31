#include <ansi.h>
inherit ITEM;
string *w_object=({
"/clone/box/new/ar1",
"/clone/box/new/ar10",
"/clone/box/new/ar11",
"/clone/box/new/ar12",
"/clone/box/new/ar13",
"/clone/box/new/ar14",
"/clone/box/new/ar15",
"/clone/box/new/ar16",
"/clone/box/new/ar17",
"/clone/box/new/ar18",
"/clone/box/new/ar2",
"/clone/box/new/ar3",
"/clone/box/new/ar4",
"/clone/box/new/ar5",
"/clone/box/new/ar6",
"/clone/box/new/ar7",
"/clone/box/new/ar8",
"/clone/box/new/ar9",
"/clone/box/new/ar2",
"/clone/box/new/ar3",
"/clone/box/new/ar4",
"/clone/box/new/ar5",
"/clone/box/new/ar6",
"/clone/box/new/ar7",
"/clone/box/new/ar8",
"/clone/box/new/ar9",
"/clone/box/new/bt1",
"/clone/box/new/bt10",
"/clone/box/new/bt11",
"/clone/box/new/bt12",
"/clone/box/new/bt13",
"/clone/box/new/bt14",
"/clone/box/new/bt15",
"/clone/box/new/bt16",
"/clone/box/new/bt17",
"/clone/box/new/bt18",
"/clone/box/new/bt2",
"/clone/box/new/bt3",
"/clone/box/new/bt4",
"/clone/box/new/bt5",
"/clone/box/new/bt6",
"/clone/box/new/bt7",
"/clone/box/new/bt8",
"/clone/box/new/bt9",
"/clone/box/new/bt2",
"/clone/box/new/bt3",
"/clone/box/new/bt4",
"/clone/box/new/bt5",
"/clone/box/new/bt6",
"/clone/box/new/bt7",
"/clone/box/new/bt8",
"/clone/box/new/bt9",
"/clone/box/new/h1",
"/clone/box/new/h10",
"/clone/box/new/h11",
"/clone/box/new/h12",
"/clone/box/new/h13",
"/clone/box/new/h14",
"/clone/box/new/h15",
"/clone/box/new/h16",
"/clone/box/new/h2",
"/clone/box/new/h3",
"/clone/box/new/h4",
"/clone/box/new/h5",
"/clone/box/new/h6",
"/clone/box/new/h7",
"/clone/box/new/h8",
"/clone/box/new/h9",
"/clone/box/new/h2",
"/clone/box/new/h3",
"/clone/box/new/h4",
"/clone/box/new/h5",
"/clone/box/new/h6",
"/clone/box/new/h7",
"/clone/box/new/h8",
"/clone/box/new/h9",
"/clone/box/new/hd1",
"/clone/box/new/hd10",
"/clone/box/new/hd11",
"/clone/box/new/hd12",
"/clone/box/new/hd13",
"/clone/box/new/hd14",
"/clone/box/new/hd15",
"/clone/box/new/hd16",
"/clone/box/new/hd17",
"/clone/box/new/hd18",
"/clone/box/new/hd2",
"/clone/box/new/hd3",
"/clone/box/new/hd4",
"/clone/box/new/hd5",
"/clone/box/new/hd6",
"/clone/box/new/hd7",
"/clone/box/new/hd8",
"/clone/box/new/hd9",
"/clone/box/new/hd2",
"/clone/box/new/hd3",
"/clone/box/new/hd4",
"/clone/box/new/hd5",
"/clone/box/new/hd6",
"/clone/box/new/hd7",
"/clone/box/new/hd8",
"/clone/box/new/hd9",
"/clone/box/new/nk1",
"/clone/box/new/nk10",
"/clone/box/new/nk11",
"/clone/box/new/nk12",
"/clone/box/new/nk13",
"/clone/box/new/nk14",
"/clone/box/new/nk15",
"/clone/box/new/nk16",
"/clone/box/new/nk17",
"/clone/box/new/nk18",
"/clone/box/new/nk2",
"/clone/box/new/nk3",
"/clone/box/new/nk4",
"/clone/box/new/nk5",
"/clone/box/new/nk6",
"/clone/box/new/nk7",
"/clone/box/new/nk8",
"/clone/box/new/nk9",
"/clone/box/new/sc1",
"/clone/box/new/sc10",
"/clone/box/new/sc11",
"/clone/box/new/sc12",
"/clone/box/new/sc13",
"/clone/box/new/sc14",
"/clone/box/new/sc15",
"/clone/box/new/sc16",
"/clone/box/new/sc17",
"/clone/box/new/sc18",
"/clone/box/new/sc2",
"/clone/box/new/sc3",
"/clone/box/new/sc4",
"/clone/box/new/sc5",
"/clone/box/new/sc6",
"/clone/box/new/sc7",
"/clone/box/new/sc8",
"/clone/box/new/sc9",
"/clone/box/new/sd1",
"/clone/box/new/sd10",
"/clone/box/new/sd11",
"/clone/box/new/sd12",
"/clone/box/new/sd13",
"/clone/box/new/sd14",
"/clone/box/new/sd15",
"/clone/box/new/sd16",
"/clone/box/new/sd17",
"/clone/box/new/sd18",
"/clone/box/new/sd2",
"/clone/box/new/sd3",
"/clone/box/new/sd4",
"/clone/box/new/sd5",
"/clone/box/new/sd6",
"/clone/box/new/sd7",
"/clone/box/new/sd8",
"/clone/box/new/sd9",
"/clone/box/new/sd2",
"/clone/box/new/sd3",
"/clone/box/new/sd4",
"/clone/box/new/sd5",
"/clone/box/new/sd6",
"/clone/box/new/sd7",
"/clone/box/new/sd8",
"/clone/box/new/sd9",
"/clone/box/new/wi1",
"/clone/box/new/wi10",
"/clone/box/new/wi11",
"/clone/box/new/wi12",
"/clone/box/new/wi13",
"/clone/box/new/wi14",
"/clone/box/new/wi15",
"/clone/box/new/wi16",
"/clone/box/new/wi17",
"/clone/box/new/wi18",
"/clone/box/new/wi2",
"/clone/box/new/wi3",
"/clone/box/new/wi4",
"/clone/box/new/wi5",
"/clone/box/new/wi6",
"/clone/box/new/wi7",
"/clone/box/new/wi8",
"/clone/box/new/wi9",
"/clone/box/new/wi2",
"/clone/box/new/wi3",
"/clone/box/new/wi4",
"/clone/box/new/wi5",
"/clone/box/new/wi6",
"/clone/box/new/wi7",
"/clone/box/new/wi8",
"/clone/box/new/wi9",
"/clone/box/new/wt1",
"/clone/box/new/wt10",
"/clone/box/new/wt11",
"/clone/box/new/wt12",
"/clone/box/new/wt13",
"/clone/box/new/wt14",
"/clone/box/new/wt15",
"/clone/box/new/wt16",
"/clone/box/new/wt17",
"/clone/box/new/wt18",
"/clone/box/new/wt2",
"/clone/box/new/wt3",
"/clone/box/new/wt4",
"/clone/box/new/wt5",
"/clone/box/new/wt6",
"/clone/box/new/wt7",
"/clone/box/new/wt8",
"/clone/box/new/wt9",
"/clone/box/new/wt2",
"/clone/box/new/wt3",
"/clone/box/new/wt4",
"/clone/box/new/wt5",
"/clone/box/new/wt6",
"/clone/box/new/wt7",
"/clone/box/new/wt8",
"/clone/box/new/wt9",
});

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"九转金丹"NOR, ({"jin dan", "jindan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗九转金丹。\n");
		set("value", 50000);
set("no_pawn",1);
	}
	setup();
}

int do_eat(string arg)
{
	int exp,pot,score;
	object corpse;
        object me = this_player();
 	if (!id(arg))
		return notify_fail("你要吃什么？\n");

    if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N吃下一颗九转金丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
		exp = 4500+random(3000);
	    pot = exp*2/3;
        score = random(300)+100;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",score);
		me->add("yuanshen/exp",pot/2);
		tell_object(me,HIY"你被奖励了：100点内力上限\n" +
        chinese_number(exp) + "点实战修为\n"+
             chinese_number(pot) + "点潜能\n" +chinese_number(pot/2) + "点元神修为\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);
		me->add("max_neili", 100);
		message_vision(HIY "$N吃下一颗九转金丹，只觉得体内真力源源滋生，你好像变了一个人似的!\n" NOR, me);
		if (me->query("4zhuan") || me->query("5zhuan"))
		{
			if (random(3)==1)
			{

				me->add("expmax",1);

				tell_object(me,HIR"你成长资历获得成功!\n"+NOR);
			}
		}

		if (random(3)==0)
		{
			int rand;
			object ob;
			rand=random(sizeof(w_object));
			ob=new(w_object[rand]);

			if(ob)
			{
				ob->move(me);
				message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "通过神书任务找到了"+ob->query("name")+HIM"!"NOR"。\n", users());
				environment(this_object())->set("alrd",1);
			}
			else
				tell_object(me,"结果什么也没有!"NOR+"。\n"NOR);
		}
	}


        me->apply_condition("medicine", 100);

	destruct(this_object());
	return 1;
}