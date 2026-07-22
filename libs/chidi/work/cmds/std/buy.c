// buy.c

inherit F_CLEAN_UP;

/*void create() { seteuid(getuid()); }*/

int main(object me, string arg)
{
	string banghui;
	string item, targ;
	object ob, owner;
	int price, afford;
	int much;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 || sscanf(arg, "%s", item)!=2 )
	if( me->is_busy())	return notify_fail("你正忙着呢！\n");

	if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
		return notify_fail("指令格式: buy <something> from <someone>\n");
	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("你要跟谁买东西？\n");
	if(!owner->is_character())
		return notify_fail("看清楚，它不是人啊。\n");
	if(!living(owner))
		return notify_fail("先把他弄醒再说吧。\n");
	if( userp(owner) ) {
		message_vision("$N想向$n购买「" + item + "」。\n", me, owner);
		return 1;
	}

	//me->start_busy(2);
	//notify_fail("对方好像不愿意跟你交易。\n");
	if( (price = owner->buy_object(me, item)) < 1 ) return 0;
//检测是否同帮之人,若是,则price减半.change by xxy
	if(stringp(banghui=me->query("banghui/name"))&&
		banghui==(string)owner->query("banghui/name"))
		(int)price=(price*2/3);
		if(price<=0)	price=1;

	if( afford = me->can_afford(price) ) {
		if( afford==2 ) 
		return notify_fail("你没有足够的零钱，而对方也找不开...。\n");
		me->pay_money(price);
		much=(int)(price/10);
		if(much<=0)	much=1;
		"/cmds/adm/ctom.c"->save_money(owner,much);
		owner->compelete_trade(me, item);
           me->start_busy(1);
		return 1;
	} else
		return notify_fail("你的钱不够。\n");
}

int help(object me)
{
   write( @HELP
指令格式: buy <something> from <someone>

这一指令让你可以从某些人身上买到物品。
HELP
   );
   return 1;
}
