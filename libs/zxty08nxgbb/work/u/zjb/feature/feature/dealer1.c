
// dealer1.c 商人
// This is a inheritable object.
// Each dealer should support buy, sell, list, value
// pawn,redeem,check 7 commands
// Write By Zman 1999.06.30
//增加了与技能（讨价还价(taojiahuanjia)）的联系
#include <dbase.h>
#include <ansi.h>
string fill_blank(string type, int num);
string remove_ansi(string str)
{
	int i;
	string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
			HIR, HIG, HIY, HIB, HIM, HIC, HIW,
			HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
			BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
			NOR, BOLD });
			
	if( !str || !stringp(str) ) return 0;
	i = sizeof(color);
	while( i-- ) {
		str = replace_string(str, color[i], "");
	}
	return str;
}
string value_string(int value)
{
	if( value < 1 ) value = 1;
	else	if( value < 100 )
		return chinese_number(value) + "文钱";
	else	if( value < 10000 )
		return chinese_number(value/100) + "两白银"
			+ (value%100? "又" + chinese_number(value%100) + "文钱": "");
	else
		return chinese_number(value/10000) + "两黄金"
			+( (value%10000)/100 ? chinese_number((value%10000)/100) + "两白银" : "")
			+( (value%10000)%100 ? "又" + chinese_number((value%10000)%100) + "文钱": "");
}

string chinese_name(string arg)
{
	switch(arg) {
		case "weapon" : return "武器";
		case "armor"  : return "防具";
		case "book"   : return "秘籍";
		case "food"   : return "食物";
		case "misc"   : return "道具";
		default       : break;
	}
	return "物品";
}

mapping filter_items(object *list, string arg)
{
	mapping goods = ([]);
	object *obj;
	int i, j;

	for(i = 0;i < sizeof(list);i++) {
		if(list[i]->query("equipped") || list[i]->query("money_id") )	continue;
		if(arg == "weapon" && !list[i]->query("weapon_prop") )		continue;
		if(arg == "armor"  && !list[i]->query("armor_type")  )		continue;
		if(arg == "book"   && !list[i]->query("skill") )		continue;
		if(arg == "food"   && !list[i]->query("food_supply")
		&& !list[i]->query("liquid/remaining") )				continue;
		if(arg == "misc" &&
		(  list[i]->query("weapon_prop")
		|| list[i]->query("armor_type")
		|| list[i]->query("skill")
		|| list[i]->query("food_supply")
		|| list[i]->query("liquid/remaining")) )				continue;

		if( mapp(goods) )	obj = keys(goods);
		for(j = 0;j < sizeof(obj);j++) {
			if( obj[j]->query("id") == list[i]->query("id")
			&&  obj[j]->query("name") == list[i]->query("name") )	break;
		}
		if( j < sizeof(obj) ) {
			if( list[i]->query("base_unit") )
				goods[obj[j]] += list[i]->query_amount();
			else	goods[obj[j]] += 1;
		}
		else {
			if( list[i]->query("base_unit") )
				goods[list[i]] = list[i]->query_amount();
			else	goods[list[i]] = 1;
		}

	}
	return goods;
}

string is_vendor_good(string arg,int once)
{
        string *goods,*all_id;
        int i,j;

        if (goods = query("vendor_goods")) 
		for (i = 0; i < sizeof(goods); i++){
			if (!all_id=goods[i]->parse_command_id_list())
				return "";
			if (goods[i]->query("name")==arg)
				return goods[i];
			for (j=0;j<sizeof(all_id);j++)
				if (all_id[j]==arg)
					if (once==1)
						return goods[i];
					else once--;
		}
        return "";
}

int pay_player(object who, int amount)
{
	object ob;

	if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new("/clone/money/100gold");
                ob->set_amount(amount/1000000);
		if (!ob->move(who)) return 0;
                amount %= 1000000;
	}
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
		if (!ob->move(who)) return 0;
                amount %= 10000;
	}
	if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
		if (!ob->move(who)) return 0;
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		if (!ob->move(who)) return 0;
	}
	return 1;
}

int vall(object me,string arg)
{
	object ob;
	ob = present(arg, me);
	if( !ob ) ob = present(arg, environment(me));
	if( !ob ) ob = find_object(resolve_path(me->query("cwd"), arg));
	if( !ob ) return notify_fail("没有这样物件或这样物件没有被载入。\n");
	return 1;

}

int do_value(string arg)
{
	object ob;
	int value;
	int amount;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要拿什麽物品给当铺估价？\n");

	if( ob->query("money_id") )
		return notify_fail("这是「钱」，你没见过吗？\n");
       if (ob->query("shaolin") || ob->query("no_sell")||ob->query("no_drop")) return notify_fail("这东西是无价之宝！\n");
	value = ob->query("value");

	if( !value ){ printf("%s一文不值。\n", ob->query("name"));return 1;}
	else 
		if (!amount=ob->query_amount())	amount=1;
		value*=amount;
        if (value<100)
        printf("\n %s%s%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
            chinese_number(amount),(ob->query("base_unit")?ob->query("base_unit"):ob->query("unit")),ob->query("name"), value_string(value),
            value_string(value *60/ 100), value_string(value *80/100));
        else
        printf("\n %s%s%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
            chinese_number(amount),(ob->query("base_unit")?ob->query("base_unit"):ob->query("unit")),ob->query("name"), value_string(value),
            value_string(value / 100 * 60), value_string(value / 100*80));
    return 1;
}


int do_pawn(string arg)
{
	object ob;
	string *pawns;
	int i,value;
	int amount;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要典当什麽物品？\n");

	if( ob->query("money_id") )	return notify_fail("你要当「钱」？你脑瓜有毛病？\n");

	value = ob->query("value");

	if( !value) return notify_fail("这样东西不值钱。\n");
	if( ob->query("value")<100) return notify_fail("你当我这是垃圾店，什么乱七八糟的东西都往这塞？\n");
       if (ob->query("no_drop") || ob->query("no_sell"))  return notify_fail("这么重要的东西你也敢拿来典当？\n");
	pawns=this_player()->query("pawns");
	if (sizeof(pawns)>100)
		return notify_fail(this_object()->query("name")+"说道：客官在本店典当的物品太多了，小店怕日后担当不起。\n");
	if (!amount=ob->query_amount())	amount=1;
	value*=amount;
    if (value<100)
        value=value*60/100;
    else
        value=value/100*60;

        if (pay_player(this_player(), value))
                message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
		+ value_string(value) + "。\n", this_player());
	else
		message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
		+ value_string(value) +",可$N拿不了。\n"
		+"$n笑嘻嘻地把$N丢下的钱拣了起来，放进钱柜，\n"
                +"地下拣到钱，问天问地拿不到，呵呵！\n", this_player(),this_object());

	if (!pawns)
		this_player()->set("pawns",({ base_name(ob) }) );
	else {
		pawns+=({ base_name(ob) });
		this_player()->set("pawns",pawns );
	}
	destruct(ob);

	return 1;
}

int do_sell(string arg)
{
	object ob,obj,*inv;
	string str;
	int value;
	int amount,i,j=1,ii;
	if( !arg )
		return notify_fail("你要卖断什麽物品？\n");
        if(sscanf(arg, "%d %s", j,str)==2 )
		arg=str;
	if( !(obj = present(arg, this_player())) )
		return notify_fail("你要卖断什麽物品？\n");
    if (obj->query("no_sell") || obj->query("no_drop")) return notify_fail("这东西是无价之宝，不能卖断！\n");

	if (j<1) return notify_fail("什么？几个？你当我是三岁小孩呀？\n");
	if( obj->query("money_id") )	return notify_fail("你要卖「钱」？\n");
	value = obj->query("value");

	if( !value) return notify_fail("这样东西不值钱。\n");
	if (!amount=obj->query_amount())	amount=1;
	value*=amount;
    if (value<10000)
        value=value*80/100;
    else
        value=value/100*80;
	if (value<1) return notify_fail("这样东西你卖一文钱也没有人要。\n");
	for (i=0;i<j;i++){
		if( !(ob = present(arg, this_player())) )
			break;
		else{
			ob->move(this_object());
		        inv = all_inventory(this_object());
		        if (sizeof(inv)>101)
				destruct(inv[sizeof(inv)-2]);
		}
	}
        if (MONEY_D->pay_player(this_player(), value*i))
		message_vision("$N把身上的" + CHINESE_D->chinese_number(i)+obj->query("unit")+obj->query("name") + "卖掉"+ value_string(value*i)+"。\n",
		this_player());
	else
		message_vision("$N把身上的" + CHINESE_D->chinese_number(i)+obj->query("unit")+obj->query("name") + "卖掉"+ value_string(value*i)+"。\n",
		this_player());
//                message_vision("$N把身上的" +  CHINESE_D->chinese_number(i)+obj->query("unit")+obj->query("name") + "卖掉"+ value_string(value*i)+"。可$N拿不起这么多钱了。\n"
//		+"$n笑嘻嘻地把$N丢下的钱拣了起来，放进钱柜，\n"
//                +"地下拣到钱，问天问地拿不到，呵呵！\n", this_player(),this_object());
//		this_player()->improve_skill("taojiahuanjia", random(3));
	return 1;
}

int do_check()
{
	string str,*ob;
	int i;

	if (!(ob = this_player()->query("pawns")))
		return notify_fail(this_object()->query("name")+"说道：客官并未在本店典当过任何物品。\n");
	str="\n你在本店典当的物品如下:\n\n";
	for(i=0;i<sizeof(ob);i++){
		str+=sprintf("%-40s :%s \n",
		ob[i]->short(),
        value_string(ob[i]->query("value")));
	}
	write(str);
	return 1;
}
int do_redeem(string arg)
{
	string *pawns,*new_pawns,ob;
	mapping all_id;
	int i,j;

	if (!(pawns = this_player()->query("pawns")))
		return notify_fail(this_object()->query("name")+"说道：客官并未在本店典当过任何物品。\n");
	for(i=0;i<sizeof(pawns);i++){
		ob=pawns[i];
		all_id=ob->parse_command_id_list();
		for (j=0;j<sizeof(all_id);j++){
			if (all_id[j]==arg)
				break;
		}	if (j!=sizeof(all_id))
			break;
	}
	if (j==sizeof(all_id))
		return notify_fail(this_object()->query("name")+"急了：你...你何时在小店典当过这东西？\n");

    if( this_player()->can_afford(ob->query("value"),1))
        this_player()->pay_money(ob->query("value"),0);
	else
		return notify_fail("你的钱不够。\n");
		new_pawns=({});
		j=1;
	for(i=0;i<sizeof(pawns);i++){
		if (j==1 && ob==pawns[i]) { j--;continue; }
		else new_pawns+=({pawns[i]});
	}

		if (sizeof(new_pawns))
			this_player()->set("pawns",new_pawns );
		else
			this_player()->delete("pawns");


	message_vision("$N从当铺里赎回一" + ob->query("unit")
		 + ob->query("name") + "。\n",
			this_player() );
        new(ob)->move(this_player());
	return 1;
}

string inventory_desc(object ob)
{
	if (ob->query("equipped")) return "";
	else return sprintf("  (一%s)%-25s:  %s",
		ob->query("unit"),		ob->short(),
value_string(ob->query("value")));
}

int do_list(string arg)
{
	object *list,ob;
	mapping goods;
	int i;
	string msg;

	ob=this_object();
	list=all_inventory(ob);

	if(!arg || 
	(  arg != "weapon" && arg != "armor" && arg != "book"
	&& arg != "food"   && arg != "misc"  && arg != "all" ) ) {
		write("你要列出哪一柜，weapon、armor、book、food、misc 还是 all？\n");
		return 1;
	}

	goods = filter_items(list, arg);
	if(!mapp(goods) || !sizeof(list = keys(goods)) ) {
		write("本店目前没有" + chinese_name(arg) + "出售。\n");
		return 1;
	}

	msg = "本店目前出售以下" + chinese_name(arg) + "：\n";

	for(i = 0;i < sizeof(list);i++) {
		msg += sprintf("%-s ： %-20s%-20s\n",
			list[i]->short()+fill_blank(remove_ansi(list[i]->short()),30),
			value_string(list[i]->query("value")),
			"(共有" + chinese_number(goods[list[i]]) + 
(list[i]->query("base_unit")?list[i]->query("base_unit"):list[i]->query("unit"))
			 + ")" );
	}

	this_player()->start_more(msg);
	return 1;
}

int do_buy(string arg)
{
	string items,targ;
	object *inv, who,ob, owner,obj;
	int price, i,amount=1;
	int once=1;
        who=this_player();

	targ="";
	if( who->query_temp("sleeping") )
		return notify_fail("你正躺着呢！\n");
	if ( !arg )
		return notify_fail("你要买什么东西？\n");
        if(sscanf(arg, "%d %s %d from %s",amount,items,once, targ)!=4 )
        	if(sscanf(arg, "%d %s from %s",amount,items, targ)!=3 )
	        if(sscanf(arg, "%s %d from %s", items,once,targ)!=3 )
		if( sscanf(arg, "%d %s %d",amount,items,once)!=3 )
		        if(sscanf(arg, "%s from %s", items, targ)!=2 )
			if( sscanf(arg, "%d %s",amount,items)!=2 )
			if( sscanf(arg, "%s %d",items,once)!=2 )
				items=arg;
	if(targ=="")
		owner=this_object();
	else	if (!objectp(owner = present(targ, environment(who))) )
		return notify_fail("你要跟谁买东西？\n");

    inv = all_inventory(who);  
    if (inv && sizeof(inv)>=50) {
        if( who==this_player() )
            return notify_fail( "你身上已经太多东西了。\n");
        else
        if (userp(who))
            return notify_fail(ob->name() + "身上已经太多东西了。\n");
    }

	if (owner->query_temp("busy"))
		return notify_fail(owner->query("name")+"说道：客倌等等，小的这就拿来！\n");
	arg=items;
	items = is_vendor_good(arg,once);
	if (items == ""){
	        if (!objectp(obj=present(arg, owner)))
                return notify_fail("你想买什么？ \n");
	}
	if(amount<1) return notify_fail("至少得买一个吧？\n");
	if(amount>30) return notify_fail("你一次不能买这么多。\n");
	if (items == ""){
		if (obj->query("equipped")||obj->query("money_id"))
			return notify_fail(owner->query("name")+"气冲冲地说：身上的东西，不卖！\n");
		price=obj->query("value");
	}else{
		price=items->query("value");
		if (amount>9)
			if (items->query("name")=="牛皮酒袋")
				message_vision("$N一边转身去装酒，嘴里一边嘀咕：买这么多酒，用来洗澡呀？\n",
				owner );
			else
				message_vision("$N用一种奇怪的眼神看盯了$n好一会，似乎怕$n用来倒卖，抢了自己的生意！\n",
				owner,who );
	}

	if( who->can_afford(price*amount) ) {
		for (i=0;i<amount;i++){
			if (items == ""){
			if (ob = present(arg, owner))
				ob->move(who);
			else break;
			} else
			new(items)->move(who);
		}
		amount=i;
		MONEY_D->player_pay(this_player(),price*amount);
		if (items == "")
		message_vision("$N向$n买下" +CHINESE_D->chinese_number(amount)+obj->query("unit") + obj->query("name") + "。\n",
				who, owner );
		else
		message_vision("$N向$n买下" +CHINESE_D->chinese_number(amount)+items->query("unit") + items->query("name") + "。\n",
				who, owner );
		owner->set_temp("busy",1);
		remove_call_out("clear_busy");
		call_out("clear_busy",1,owner);
		return 1;
	} else
		return notify_fail("你的钱不够。\n");
}

void clear_busy(object me)
{
	me->delete_temp("busy");
}
string fill_blank(string type, int num)
{
	string bak;
	int i, j;

	bak="";
	i=strlen(type);
	for (j=0; j<num-i; j++ )
		bak+=" ";
	return bak;
}
