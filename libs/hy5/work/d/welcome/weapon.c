#include <room.h>
#include <ansi.h>
string look_gaoshi();
inherit ROOM;
int jian=12,dao=5,fu=5,tongjia=5,gangjia=5;
void create ()
{
  set ("short", "兵器室");
  set ("long", @LONG
这是乃是古村的兵器室，四周是几个兵器架，上面摆满了各种各
样的兵器，（输入指令 look jia） 可以看到有什么兵器，需要的话
可以拿（输入指令 qu 兵器ID）。
LONG);
  set("exits", ([ /* sizeof() == 2 */

"south" : __DIR__"lw",


]));
  set("objects", ([ /* sizeof() == 1 */
  //__DIR__"jing" : 1,
 
]));

	set("item_desc", ([
		"jia" : (: look_gaoshi :),
	]));

set("roomif","$botten#查看|取:look jia|qu <输入>$#");	
  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  //replace_program(ROOM);
}

void init()
{
	add_action("do_list","look");
	add_action("do_naqu","qu");
}


string look_gaoshi()
{
string msg;
	object me;
	me=this_player();
	if(! living(me))	return 0;
	//if(arg!=" jia" )	return 0;
	msg="目前库房内有下列物品可以拿取(qu)\n";
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
	//write(msg);
	return msg;
	
}



int do_naqu(string arg)
{
	object me,sth;
	mapping data;
	me=this_player();
	if(! living(me))	return 0;
	if(! arg)	return notify_fail("你要拿取什么？\n");
	if(me->query("combat_exp",1) > 100000 && !wizardp(me))
		return notify_fail("你的经验太高了，没必要用这免费的武器吧。\n");
	if( me->query_temp("have_naqu"))
		return notify_fail("你已经拿过了呀,等一会再来吧。\n");
	if(arg=="jian" && jian)	{
		sth=new("/clone/weapon/changjian");
		if( me->query_encumbrance() + sth->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("这把剑对你而言太重了。\n");
		jian --;
		sth->move(me);
		message_vision("$N从架子上拿了把长剑。\n",me);
	}	else if(arg=="dao" && dao)	{
		sth=new("/clone/weapon/blade");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这把刀对你而言太重了。\n");
                dao --;
		sth->move(me);
		message_vision("$N从架子上拿了把单刀。\n",me);
	}	else if(arg=="fu" && fu)	{
		sth=new("/clone/weapon/axe");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这把斧对你而言太重了。\n");
                fu --;
		sth->move(me);
		message_vision("$N从架子上拿了把板斧。\n",me);
	}	else if(arg=="tongjia" && tongjia) {
sth=new("/clone/armor/tongjia");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("这件铜甲对你而言太重了。\n");
                tongjia --;
		sth->move(me);
		message_vision("$N从架子上拿了件铜甲。\n",me);
	}	else if(arg=="gangjia" && gangjia) {
sth=new("/clone/armor/tiejia");
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
