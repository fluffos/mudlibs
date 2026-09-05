//giftbox(大礼包)
//Made By pal
//2005-9.-21
#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("大礼包",({"giftbox","box"}));
        set("long","这是一个包装精美的大礼包，还不赶紧拆开看看(chai)?\n");
        set("unit","个");
        set("value",1);
        set_weight(1000000);
        set("no_store",1);
        set("no_pawn",1);
        set("no_sell",1);
        set("no_drop",1);
       setup();
}

void init()
{
	object owner;
	if(!query("owner") || query("owner")=="pal")//只能由pal发
		set("owner",this_player()->query("id"));
	owner=find_player(query("owner"));
	if (this_player()->query("id")!=query("owner") && living(environment(this_object())))
	{
		message_vision(query("name")+"突然爆炸开来。\n",this_player());
		this_player()->unconcious();
		tell_object(owner,HIR"你被大礼包爆炸的威力掀上了天。\n"NOR);
		tell_object(owner,HIR"在意识模糊之前，你隐约想到pal说过礼包不能给人，只好自认倒霉。\n"NOR);
		owner->set_temp("last_damage_from",owner);
		owner->die();
		destruct(this_object());
		return;
	}
	if(owner->query("gift/2005zhongqiu"))
	{
		message_vision(query("name")+"突然爆炸开来。\n",this_player());
		tell_object(owner,HIR"你被大礼包爆炸的威力掀上了天。\n你忽然想起你以前已经拿过一个礼包了。\n"NOR);
		owner->unconcious();
		destruct(this_object());
		return;
	}
	if(this_player()->query("id")!="pal")
	{
		owner->set("gift/2005zhongqiu",1);
	}
	if(this_player()->query("combat_exp")>=1000000)
	{
		tell_object(owner,"你的经验太高了，这种礼盒对你没有用处！\n");
		return;
	}
	add_action("do_chai","chai");
}

int do_chai(string arg)
{
	object me;
	int i,j;
	me = this_player();
	if (!arg)  return notify_fail("你要拆什么？\n");
	if((arg=="giftbox") || (arg=="box")) 
	{
		object gift;
		message_vision(HIG"\n$N手忙脚乱地把大礼包打开，从里面掏出来一个大大的盒子！\n"NOR,me);
		for(i=0;i<4;i++)
		{
			switch(random(10))
			{
				case 0:
					tell_object(me,"你摸了半天，突然发现盒子底部居然有一个洞。你懊恼自己的坏运气，礼物到手了居然也能掉了。\n");
				break;
				case 1:
				case 2:
					me->delete("kaizhan/gift_guo");
					me->delete("chris/got");
					tell_object(me,"恭喜你获得新手特别奖励：可以从开站礼品树上再摘一个果子吃。\n");
				break;
				case 3:
				case 4:
					gift=new("/d/yuewangmu/obj/jsbaojia");
					gift->set("no_give",1);
					gift->set("no_store",1);
					gift->set("no_pawn",1);
					gift->set("no_drop",1);
					gift->move(me);
					tell_object(me,"你拿出了一件漂亮的盔甲！\n");
				break;
				case 5:
				case 6:
					gift=new("/d/riyuejiao/obj/riyuejian");
					gift->set("no_give",1);
					gift->set("no_store",1);
					gift->set("no_pawn",1);
					gift->set("no_drop",1);
					gift->move(me);
					tell_object(me,"你拿出了把宝剑！\n");
				break;
				case 7:
				case 8:
					gift=new("/d/riyuejiao/obj/riyuedao");
					gift->set("no_give",1);
					gift->set("no_store",1);
					gift->set("no_pawn",1);
					gift->set("no_drop",1);
					gift->move(me);
					tell_object(me,"你拿出了一把沉甸甸的宝刀！\n");
				break;
				case 9:
					gift=new("/d/city/npc/obj/zaizaowan");
					gift->set("owner",me->query("id"));
					gift->move(me);
					tell_object(me,"你激动地摸了半天，摸出了一个小药丸。你定睛一看，居然是武林中人梦寐以求的再造丸！\n");
				break;
			}
		}
	destruct(this_object());
	}
	return 1;
}