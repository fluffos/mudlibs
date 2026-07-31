#include <ansi.h>
inherit NPC;

#define MAX_PAWN 50
inherit F_VENDOR;
void create()
{
	set_name("香兰", ({ "xianglan" }) );
	set("gender", "女性" );
	set("age", 29);
	set("title", "当铺老板娘");
	set("long",
		"香兰从小被卖到千金楼，生活凄苦，但因善长得男人欢心，
终被一富豪看中，娶为第十八房小老婆。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
	set("no_arrest",1);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();

       carry_object("/d/city/obj/flower_shoe")->wear();
       carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
//	add_action("do_sell", "sell");
	add_action("do_redeem", "redeem");
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "文钱";
	else
		return chinese_number(value/100) + "两"
			+ (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

void pay_player(object who, int amount)

{
	object ob;
	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要拿什麽物品给当铺估价？\n");

	if( ob->query("money_id") )
		return notify_fail("这是「钱」，你没见过吗？\n");

        if (ob->query("ownmake"))
                return notify_fail("这样的宝物我可买不起。\n");

	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");

	if (ob->query("liquid/remaining"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");

	value = ob->query("value");
	if( !value )
        return notify_fail("这样东西并不值很多钱。\n");

	if( !value || value < 30) printf("%s一文不值。\n", ob->query("name"));
	else 
		printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
			ob->query("name"), value_string(value),
			value_string(value * 25 / 100), value_string(value * 80 / 100));

	return 1;
}

int do_pawn(string arg)
{
	object ob;
	string term, *terms;
	string data;
	int value, pawn_count, i;
	int rvalue;
	mapping pawn;
	object me;
	me = this_player();
	pawn = me->query("pawn");
	if( !arg || !(ob = present(arg, this_player())) )
	{
	write("你目前典当的物品有：\n");
	if( !mapp(pawn) ||   !sizeof(pawn) )
		write("\t没有任何典当的物品。\n");
	else {
                        terms = keys(pawn);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-3s：  %-15s  赎银：%s\n", terms[i], pawn[terms[i]],
			value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
              }
	return 1;
	}
	if( ob->query("money_id") )	return notify_fail("你要当「钱」？\n");
        if( ob->query("equipped") || ob->query("no_drop") )     return notify_fail("这样可当不了！\n");
        if( ob->query("no_pawn") )     return notify_fail("这个东西当不了！\n");
	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
	if (ob->query("liquid/remaining"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
        if (ob->query("ownmake"))
                return notify_fail("这样的宝物我可买不起。\n");


	value = ob->query("value");
	if( !value )
        return notify_fail("这样东西并不值很多钱。\n");

	if( !value || value < 30)
        return notify_fail("这样东西并不值很多钱。\n");

	if( !(value/4) ) return notify_fail("这样东西并不值很多钱。\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                        if(sizeof(terms) > MAX_PAWN)
                        return notify_fail("你已典当太多物品了。\n");
			for(i=0; i<sizeof(terms); i++)	
			{
			pawn_count = i;
                        if(!((int) me->query("vpawn/" + sprintf("%d", i))))
                         break;
                        else pawn_count = i+1;
			}
                }
	else pawn_count = 0;
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	me->set("pawn/"+ sprintf("%d",pawn_count),  term);
	me->set("vpawn/"+sprintf("%d",pawn_count), ob->query("value"));
	me->set("fpawn/"+sprintf("%d",pawn_count), data);
	me->save();
	message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
		+ value_string(value * 25 / 100) + "。\n", this_player());

	pay_player(this_player(), value * 25 / 100 );
	destruct(ob);

	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖断什麽物品？\n");

	if( ob->query("money_id") )	return notify_fail("你要卖「钱」？\n");
	value = ob->query("value");
	if( !value ) return notify_fail("这样东西不值钱。\n");
if( ob->query("no_pawn") )     return notify_fail("这个东西当不了！\n");

	message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",
		this_player());

	pay_player(this_player(), value  * 80 / 100);
	destruct(ob);

	return 1;
}
void pay_him(object who, int amount)

{
	object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
	if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);


	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;

        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return total;
}
int do_redeem(string arg)
{
        int num;
        int amount;
        string ob_file;
        object ob;
        object me;
        int afford;
        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("指令格式：redeem <物品标号>\n");
        me = this_player();
        amount = (int) me->query("vpawn/" + sprintf("%d", num));
        if( !amount )
                return notify_fail("有这个物品标号吗？\n");
        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {
                pay_him(me, afford-amount);
                ob_file = me->query("fpawn/"+sprintf("%d",num));
                ob = new(ob_file);
                ob->move(me);
                me->delete("pawn/"+sprintf("%d",num));
                me->delete("vpawn/"+sprintf("%d",num));
                me->delete("fpawn/"+sprintf("%d",num));
		me->save();
                message_vision("$N赎回了$n。\n", me, ob);
                return 1;
        } else
                return notify_fail("你的钱不够。\n");

}

