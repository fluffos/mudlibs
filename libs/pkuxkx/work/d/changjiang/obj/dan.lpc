// Zine dec 7 2010 ,长江黄河偶然事件

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "yue");
	add_action("do_eat", "du");
	add_action("do_eat", "fan");
	add_action("do_eat", "kan");
}

void create()
{
	set_name(CYN"武功心得"NOR, ({ "wugong xinde","xinde","notebook"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本不知何人撰写的武功心得，你可以翻阅(kan)一下。\n");
			set("unit", "本");
		}
}

int do_eat(string arg)
{	
	object me = this_player();
    object ob = this_object();
    int exp,pot,rep;
	string gift,author;
	if (!id(arg)) {tell_object(me,"你想翻阅什么？\n");return 1;}
	if ( me->is_busy() || me->is_fighting()) {tell_object(me,"你正忙着呢！\n");return 1;}
	message_vision(WHT+"$N开始仔细阅读"+ob->query("author")+"$n……\n"+NOR,me,ob);
    if (me->query("riverquest")< 3 && random(100)==7)
    {
        switch (random(4))
        {
            case 0:
			gift="膂力";
            me->add("riverquest",1);
            me->add("str",1);
            me->add("xiantian/str/riverquest",1);
            break;
            case 1:
            gift="根骨";
            me->add("riverquest",1);
            me->add("con",1);
            me->add("xiantian/con/riverquest",1);
            break;
            case 2:
            gift="悟性";
            me->add("riverquest",1);
            me->add("int",1);
            me->add("xiantian/int/riverquest",1);
            break;
            case 3:
            gift="身法";
            me->add("riverquest",1);
            me->add("dex",1);
            me->add("xiantian/dex/riverquest",1);
            break;
            
        }
		write(HIW"阅读了武功心得后，你觉得融会贯通，先天"+gift+"有所提高!\n"NOR);
		CHANNEL_D->do_channel(this_object(), "jh", HIW + me->query("name") +HIB "机缘巧合，研修武功心得，先天"+gift+"获得提高！", -1);
    }
    else
    {
        exp = (me->query("kar")/2 + 40) * (14 + random(25));
	    exp = exp * 3; //随机事件暂定慕容奖励的3倍
	    pot = exp * 3/2;
        if (me->query("combat_exp") < 100000)
        {
            exp = exp / 4;
            pot = pot+random(pot/3);
        }
        else if ((me->query("combat_exp") < 500000) && (me->query("combat_exp") >= 100000))
        {
            exp = exp / 3;
            pot = pot+random(pot/3);
        }
        else if ((me->query("combat_exp") < 1000000) && (me->query("combat_exp") >= 500000))
        {
            exp = exp / 2;
            pot = pot+random(pot/3);
        }
        else if (me->query("combat_exp") < 5000000 && (me->query("combat_exp") >= 1000000))
        {
            exp = exp /3*2;
            pot = pot+random(pot/3);
        }
        else
        {
            exp = exp;
            pot = pot*11/10;
        }
        if (exp > me->query("combat_exp")/150)
        {
            exp=random(100)+me->query("combat_exp")/150;
        }
        if (pot > me->query("combat_exp")/250)
        {
            pot=random(100)+me->query("combat_exp")/250;
        }
        
        exp = REWARD_D->add_exp(me,exp);
        pot = REWARD_D->add_pot(me,pot);
        tell_object(me,HIW "阅读了武功心得后，你觉得融会贯通，武学更上一个台阶，从中你获得了：\n"
			+ chinese_number(exp) + "点实战经验，\n"
			+ chinese_number(pot) + "点潜能。\n" NOR);
			
        
    }
    destruct(ob);
	return 1;
}

