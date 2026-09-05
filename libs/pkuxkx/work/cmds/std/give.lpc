// give.c
// Modified by iszt@pkuxkx, 2007-04-08, avoid call accept_object() twice

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("指令格式:give <物品> to <某人> 或 give <某人> <物品> 或 give <某人> all\n"); 

	if( sscanf(arg, "%s to %s", item, target)==2 || sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你指令格式:give <物品> to <某人> 或 give <某人> <物品> 或 give <某人> all\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有 "+target+" 。\n");
	if(who->is_busy()) return notify_fail(who->query("name") +"忙着呢，等会吧。\n");
	if(who==me) return notify_fail("把东西给自己？你可真幽默。\n");
	if( who->query("env/no_accept") )
		return notify_fail("对方不接受你的贿赂，你还是自己留着吧。\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) ) 
			return notify_fail("你身上没有 "+item+" 这样东西。\n");
		if( obj->query("no_drop") && !wizardp(me))
			return notify_fail("这样东西不能随便给人。\n");
		if( who->query("env/no_accept") )
			return notify_fail(who->name()+"不想要"+obj->name()+"，你就自个留着吧。\n");
		if( !obj->query_amount() )  
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		//icer added，添加give别人时自己的busy，防止给npc东西后立刻dang,pawn,store等引起的bug
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
		{
		  obj2=new(base_name(obj));
		  obj2->set_amount(amount);
		  destruct(obj);
		  if ( do_give(me, obj2, who) )
		    return 1;
		  else
		  {
		    obj2->move(me);
		    return 0;
		  }
		}
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else {
				obj->set_amount((int)obj->query_amount() + amount);
				return 0;
			}

		}
	}

	if(item=="all") 
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if( !inv[i]->query("equipped"))
			do_give(me, inv[i], who);
		}
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有 "+item+" 这样东西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	if( obj->query("no_drop") && !wizardp(me))
		return notify_fail("这样东西不能随便给人。\n");
	if( obj->query("no_give_user") && userp(who) )
		return notify_fail("这样东西不能给玩家。\n");
	if(!interactive(who))
	{
		if(TASK_D->task_give(me,who,obj))
			return 1;
		if(obj->give_mail(who,me))
			return 1;
		if(obj->give_chengyao(who,me))
			return 1;
		if (F_NEWQUEST->quest_give (me, who, obj)) {
			message_vision("$N给$n一"+obj->query("unit")+obj->name()+"。\n",me,who);
			message_vision("$N由衷地向$n道谢。\n",who,me);
			destruct(obj);
			return 1;
		} 
	}
	if( who->query_encumbrance() >= who->query_max_encumbrance())
		return notify_fail("他身上的物品似乎已经满了。\n");
	if (sizeof(all_inventory(who))>380)
		return notify_fail("他身上东西已经够多了，拿不了了。\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if( !interactive(who) && !who->accept_object(me, obj) )
	{
		write(who->name()+"不想要"+obj->name()+"，你就自个留着吧。\n");
		return 0;
		//iszt changed to write & return 1, or the function accept_object would be called twice
	}
	if( userp(me) && userp(who) && wizardp(me) && (!wizardp(who))) {
		log_file( "wiz/wiz_give_log", sprintf("%s %s（%s）在%s给%s（%s）一%s（%d）%s。\n", 
			ctime(time()), me->query("name"), me->query("id"), 
			( stringp(environment(me)->query("short")) ) ?
			environment(me)->query("short") : environment(me)->query("name"), 
			who->query("name"), who->query("id"), 
			obj->query("unit"), obj->query_amount(), obj->name()));}
                if (!wizardp(me)) me->start_busy(1);
  
  if ( !objectp(obj) )
  	return 1;

	if( !userp(who) && obj->value() ) {
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
		destruct(obj);
		return 1;
	} else if( obj->move(who) ) {
		printf("你给%s一%s%s。\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s给你一%s%s。\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		//icer added in case clone money when mud shutdown
		me->save();
		who->save();
		return 1;
	}
	else return 0;
}
int help(object me)
{
	write(@HELP
指令格式 : give <物品名称> to <某人>
或 : give <某人> <物品名称>
或 ：give <某人> all
这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品
HELP);
	return 1;
}
