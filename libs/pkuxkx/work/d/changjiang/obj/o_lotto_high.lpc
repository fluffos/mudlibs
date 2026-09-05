// Zine dec 7 2010 ,长江黄河偶然事件

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_jiang", "choujiang");
}

void create()
{
	set_name(HIB+"奥"+HIY+"运"+WHT+"对"+HIG+"奖"+HIR+"券"NOR, ({ "olympic lottery","lottery","quan"}));
	set_weight(500);
	set("no_give","自己的奖券不能给别人。\n");
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一张"+query("name")+"，你可以用来抽奖(choujiang)一次。\n");
			set("unit", "张");
		}
}

int do_jiang()
{	
	object me = this_player();
    object ob = this_object(),bonus;
	string msg,*tqt_books=({"dan10_s","dan12_s","dan16_s","dan3_s","dan4_s","dan5_s","dan9_s"});
	int balance;
	if ( me->is_busy() || me->is_fighting()) {tell_object(me,"你正忙着呢！\n");return 1;}
	if (ob->query("owner")!=me->query("id"))
	{
		tell_object(me,"这张奖券不是你的，快发挥拾金不昧，还给失主吧。\n");
		return 1;
	}
	message_vision("$N用手中的$n，开始兑奖。\n",me,ob);
	tell_object(me,"这次奥运抽奖，你的奖励是：");
	switch (random(30))
	{
            case 0:
            bonus=new(__DIR__+"pass");
			bonus->move(me);
			msg="一月免费长江黄河渡船船票。\n";
            break;
            case 1:
            bonus=new(__DIR__+"fun_card");
			bonus->move(me);
			msg="获得了一张"+bonus->query("name")+"。\n";
            break;
            case 2:
            bonus=new(__DIR__+tqt_books[random(sizeof(tqt_books))]);
			bonus->move(me);
			msg="获得了一本"+bonus->query("name")+"的体验版。\n";
            break;
            case 3:
            bonus=new(__DIR__+"pass");
			bonus->move(me);
			msg="一月免费长江黄河渡船船票。\n";
            break;
            case 4:
            bonus=new(__DIR__+"pass");
			bonus->move(me);
			msg="一月免费长江黄河渡船船票。\n";
            break;
			case 5:
            bonus=new(__DIR__+tqt_books[random(sizeof(tqt_books))]);
			bonus->move(me);
			msg="获得了一本"+bonus->query("name")+"的体验版。\n";
			break;
			case 6:
            bonus=new(__DIR__+tqt_books[random(sizeof(tqt_books))]);
			bonus->move(me);
			msg="获得了一本"+bonus->query("name")+"的体验版。\n";
			break;
			case 7:
            bonus=new(__DIR__+tqt_books[random(sizeof(tqt_books))]);
			bonus->move(me);
			msg="获得了一本"+bonus->query("name")+"的体验版。\n";
			break;
			case 8:
            bonus=new(__DIR__+tqt_books[random(sizeof(tqt_books))]);
			bonus->move(me);
			msg="获得了一本"+bonus->query("name")+"的体验版。\n";
			break;
			case 9:
            bonus=new(__DIR__+"tqt_card");
			bonus->move(me);
			msg="获得了一张"+bonus->query("name")+"。\n";
			break;
			case 10:
            bonus=new(__DIR__+"tqt-ob1");
			bonus->move(me);
			msg="获得了一支"+bonus->query("name")+"。\n";
			break;
			case 11:
            bonus=new(__DIR__+"tqt-ob1");
			bonus->move(me);
			msg="获得了一支"+bonus->query("name")+"。\n";
			break;
			case 12:
			me->add("non_daming_bonus_zhuicha",5);
			msg="被大明朝廷授予了5次利用大明官方力量追查(zhuicha)npc或玩家的机会。\n";
			break;
			case 13:
			me->add("non_daming_bonus_zhuicha",5);
			msg="被大明朝廷授予了5次利用大明官方力量追查(zhuicha)npc或玩家的机会。\n";
			break;
			case 14:
			me->add("non_daming_bonus_zhuicha",5);
			msg="被大明朝廷授予了5次利用大明官方力量追查(zhuicha)npc或玩家的机会。\n";
			break;
            default :
			balance=30000+random(100000);
			me->add("balance",balance);
			msg="收到了红包"+MONEY_D->money_str(balance)+"。\n";
			break;
	}
	tell_object(me,msg);
	destruct(ob);
	return 1;
}

