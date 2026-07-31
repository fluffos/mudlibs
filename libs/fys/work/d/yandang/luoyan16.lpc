// Room: /d/yandang/luoyan16
inherit ROOM;
int jian=5,dao=5,fu=5,tongjia=5,gangjia=5;

void create()
{
  set ("short", "兵器库");
  set ("long", @LONG
由于庄主喜欢搜寻天下各种武器,所以落雁山庄的武库在江湖上一直
是以品种齐全而名的,在武库中,摆着一排排的架子,上面摆满了各种各样的
武器,有许多你连名都说不上来.你可以先用(list)查看一下,然后拿取(naqu).
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luoyan9",
]));
  setup();
}
void init()
{
	add_action("do_list","list");
	add_action("do_naqu","naqu");
}

int do_list()
{
	string msg;
	object me;
	me=this_player();
	if(! living(me))	return 0;
	msg="目前库房内有下列物品可以拿取(naqu)\n";
	msg +="----------------------------------\n";
	if( jian)
	msg +="  长剑(jian)             "+chinese_number(jian)+"把\n";
	if( dao)
	msg +="  单刀(dao)              "+chinese_number(dao)+"把\n";
	if(fu)
	msg +="  板斧(fu)               "+chinese_number(fu)+"把\n";
	if(tongjia)
	msg +="  铜甲(tongjia)          "+chinese_number(tongjia)+"件\n";
	if(gangjia)
	msg +="  钢甲(gangjia)          "+chinese_number(gangjia)+"件\n";
	msg +="----------------------------------\n";
	write(msg);
	return 1;
}

int do_naqu(string arg)
{
	object me,sth;
	mapping data;
	me=this_player();
	if(! living(me))	return 0;
	if(! arg)	return notify_fail("你要拿取什么？\n");
	if(me->query("family/family_name")!="雁荡派")
		return notify_fail("随便拿人家的东西不好吧。\n");
	if( me->query_temp("have_naqu"))
		return notify_fail("你已经拿过了呀,等一会再来吧。\n");
	if(arg=="jian" && jian)	{
		sth=new("/obj/weapon/sword");
		if( me->query_encumbrance() + sth->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("这把剑对你而言太重了。\n");
		jian --;
		sth->move(me);
		message_vision("$N从架子上拿了把长剑。\n",me);
	}	else if(arg=="dao" && dao)	{
		sth=new("/obj/weapon/blade");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这把刀对你而言太重了。\n");
                dao --;
		sth->move(me);
		message_vision("$N从架子上拿了把单刀。\n",me);
	}	else if(arg=="fu" && fu)	{
		sth=new("/obj/weapon/banfu");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这把斧对你而言太重了。\n");
                fu --;
		sth->move(me);
		message_vision("$N从架子上拿了把板斧。\n",me);
	}	else if(arg=="tongjia" && tongjia) {
sth=new("/obj/std/armor/tongjia");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这件铜甲对你而言太重了。\n");
                tongjia --;
		sth->move(me);
		message_vision("$N从架子上拿了件铜甲。\n",me);
	}	else if(arg=="gangjia" && gangjia) {
sth=new("/d/yeyangzai/npc/obj/gangjia");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这件钢甲对你而言太重了。\n");
                gangjia--;
		sth->move(me);
		message_vision("$N从架子上拿了件钢甲。\n",me);
	}	else	return notify_fail("这儿没有这样东西。\n");
	sth->set("no_sell",1);
	me->set_temp("have_naqu",1);
	return 1;
}
