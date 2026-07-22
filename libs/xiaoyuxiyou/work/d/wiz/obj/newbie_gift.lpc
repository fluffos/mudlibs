#include <ansi.h>
#include <mudlib.h>
inherit ITEM;

void create()
{
	set_name(HIG"新手锦囊"NOR,({"xinshou bag","bag","nang"}));
	set_weight(1);
	if( clonep() )
        	set_default_object(__FILE__);
	else    
	{
        	set("long", MUDLIB_NAME+"新手礼物，当你满足要求时，它会有提示的。\n");
        	set("unit", "个");
        	set("no_get",1);
        	set("no_give",1);
        	set("no_put",1);
        	set("no_drop",1);
        	set("no_sell",1);
        	set("level",1);
        }
        setup();
}       

int query_autoload(){return 1;}

string name(int raw)
{
	int lvl;
	string name = ::name(raw);
	lvl = this_object()->query("level");
	if( lvl<=0 )
		return name;
	name+= "("HIR+lvl+"级"NOR")";	
	return name;
}

void check_gift1(object who)
{
	remove_call_out("check_gift1");
	if( who->query("giftmark/level_1")>0 )
		return;	
	if( who!=environment() )
		return;
	if( who->query("eff_kee")>=who->query_maxkee() 
	 && who->query("eff_sen")>=who->query_maxsen() )
	{
		who->set("giftmark/level_1",1);
		tell_object(who,HIY"【系统】当你气血精神状态值不满的情况，需要使用疗伤的丹药。("HIR"help statue"HIY")\n"NOR);
		who->add("combat_exp",9000);
		who->add("potential",3000);
		who->money_add(10000);
		tell_object(who,HIY"【系统】你得到了"HIR"9000"HIY"点武学经验和"HIR"3000"HIY"点潜能。\n"NOR);
		tell_object(who,HIY"【系统】你得到了"HIR"1"HIY"两黄金。\n"NOR);
		tell_object(who,HIY"【系统】你可以去东方武馆和弟子切磋"HIR"(fight)"HIY"来快速增加武学经验。\n"NOR);
		who->save();
		this_object()->set("level",2);
	}
	else	call_out("check_gift1",1+random(3),who);	
}

void check_gift3(object who)
{
	remove_call_out("check_gift3");
	if( who->query("giftmark/level_3")>0 )
		return;	
	if( who!=environment() )
		return;
	if( who->query("food")>=who->max_food_capacity()
	 && who->query("water")>=who->max_water_capacity() )
	{
		who->set("giftmark/level_3",1);
		tell_object(who,HIY"【系统】当你饮食状态不满的情况下，需要食物和饮水了。\n"NOR);
		who->add("combat_exp",15000);
		who->money_add(30000);
		tell_object(who,HIY"【系统】你得到了"HIR"9000"HIY"点武学经验。\n"NOR);
		tell_object(who,HIY"【系统】你得到了"HIR"3"HIY"两黄金。\n"NOR);
		who->save();
	}
	else	call_out("check_gift3",1+random(3),who);	
}

void init()
{
	add_action("do_ask","ask");
}

int do_ask(string arg)
{
	object who,where,ob,me = this_player();
	string type,*types,id,sth;
	int i;
	if( !arg || sscanf(arg,"%s about %s",id,sth)!=2 )
		return 0;
	where = environment(me);
	
	if( me->query_level()==2 )
	{
		if( !where || base_name(where)!="/d/aolai/bingqi" 
	 	 || ( sth!="weapon" && sth!="武器" ) )
			return 0;
		if( me->query("giftmark/level_2") )
			return 0;
		who = present(id,where);
		if( !who || userp(who)
	 	|| base_name(who)!="/d/aolai/npc/wuqi" )
			return 0;
		message_vision("$N向$n打听有关『"+sth+"』的消息。\n",me,who);
		EMOTE_D->do_emote(who, "wow",geteuid(me),CYN,0,0,0);
		tell_object(me,CYN+who->name()+CYN"说道：这几日多有异象，看"+RANK_D->query_respect(me)+"仪表堂堂，看来终非池中之物。\n"NOR);
		tell_object(me,CYN+who->name()+CYN"说道：来来来，我这里有把家传多年的兵刃，放在我这也是暴殄天物。\n"NOR);
		types = ({
			"axe","blade","fork","hammer","mace","spear","staff","stick","sword","unarmed","whip",
		});
		type = 0;
		for(i=0;i<sizeof(types);i++)
		{
			if( me->query_skill(types[i],2)>1 )
			{
				type = types[i];
				break;
			}
		}
		if( !type )
			type = types[random(sizeof(types))];
		who->set_temp("weapon_level",1);
		who->set("env/test","HIB");	
		ob = new("/d/obj/nweapon/"+type);
		ob->init_weapon(who);
		if( ob->move(me) )
		{
			me->set("giftmark/level_2",1);
			message_vision("$N递给$n一"+ob->query("unit")+ob->short()+"。\n",who,me);
			me->add("combat_exp",10000);
			me->add("daoxing",5000);
			me->money_add(20000);
			tell_object(me,HIY"【系统】你得到了"HIR"10000"HIY"点武学经验和"HIR"5"HIY"年道行。\n"NOR);
			tell_object(me,HIY"【系统】你得到了"HIR"2"HIY"两黄金。\n"NOR);
			me->save();
		}
		else
		{
			if( ob ) destruct(ob);
			EMOTE_D->do_emote(who, "sigh",geteuid(me),CYN,0,0,0);
			tell_object(me,CYN+who->name()+CYN"说道："+RANK_D->query_respect(me)+"你背包满了吧。\n"NOR);
		}
		return 1;
	}
	else if( me->query_level()==4 )
	{
		if( !where || base_name(where)!="/d/aolai/yimao" 
	 	 || ( sth!="armor" && sth!="盔甲" ) )
			return 0;
		if( me->query("giftmark/level_4") )
			return 0;
		who = present(id,where);
		if( !who || userp(who)
	 	|| base_name(who)!="/d/aolai/npc/yimao" )
			return 0;
		message_vision("$N向$n打听有关『"+sth+"』的消息。\n",me,who);
		EMOTE_D->do_emote(who, "xixi",geteuid(me),CYN,0,0,0);
		tell_object(me,CYN+who->name()+CYN"说道：我看"+RANK_D->query_respect(me)+"长得一表人才，整天光着身子也不是个法子。\n"NOR);
		who->set_temp("armor_level",4);
		who->set("env/test","HIB");	
		ob = new("/d/obj/narmor/armor");
		ob->init_armor(who);
		if( ob->move(me) )
		{
			me->set("giftmark/level_4",1);
			message_vision("$N递给$n一"+ob->query("unit")+ob->short()+"。\n",who,me);
			me->add("combat_exp",20000);
			me->money_add(40000);
			tell_object(me,HIY"【系统】你得到了"HIR"20000"HIY"点武学经验。\n"NOR);
			tell_object(me,HIY"【系统】你得到了"HIR"4"HIY"两黄金。\n"NOR);
			me->save();
		}
		else
		{
			if( ob ) destruct(ob);
			EMOTE_D->do_emote(who, "sigh",geteuid(me),CYN,0,0,0);
			tell_object(me,CYN+who->name()+CYN"说道："+RANK_D->query_respect(me)+"你背包满了吧。\n"NOR);
		}
		return 1;
	}
	else if( me->query_level()==5 )
	{
		if( !where || base_name(where)!="/d/aolai/bingqi" 
	 	 || ( sth!="weapon" && sth!="武器" ) )
			return 0;
		if( me->query("giftmark/level_5") )
			return 0;
		who = present(id,where);
		if( !who || userp(who)
	 	|| base_name(who)!="/d/aolai/npc/wuqi" )
			return 0;
		message_vision("$N向$n打听有关『"+sth+"』的消息。\n",me,who);
		EMOTE_D->do_emote(who, "wow",geteuid(me),CYN,0,0,0);
		tell_object(me,CYN+who->name()+CYN"说道：这几日多有异象，看"+RANK_D->query_respect(me)+"仪表堂堂，看来终非池中之物。\n"NOR);
		tell_object(me,CYN+who->name()+CYN"说道：来来来，我这里有把家传多年的兵刃，放在我这也是暴殄天物。\n"NOR);
		types = ({
			"axe","blade","fork","hammer","mace","spear","staff","stick","sword","unarmed","whip",
		});
		type = 0;
		for(i=0;i<sizeof(types);i++)
		{
			if( me->query_skill(types[i],2)>1 )
			{
				type = types[i];
				break;
			}
		}
		if( !type )
			type = types[random(sizeof(types))];
		who->set_temp("weapon_level",5);
		who->set("env/test","HIB");	
		ob = new("/d/obj/nweapon/"+type);
		ob->init_weapon(who);
		if( ob->move(me) )
		{
			me->set("giftmark/level_5",1);
			message_vision("$N递给$n一"+ob->query("unit")+ob->short()+"。\n",who,me);
			me->add("combat_exp",20000);
			me->add("daoxing",5000);
			me->money_add(50000);
			tell_object(me,HIY"【系统】你得到了"HIR"20000"HIY"点武学经验和"HIR"5"HIY"年道行。\n"NOR);
			tell_object(me,HIY"【系统】你得到了"HIR"5"HIY"两黄金。\n"NOR);
			tell_object(me,HIY"【系统】你现在已经 "HIR"5"HIY" 级了，可以离开傲来国去东土神州闯荡了。\n"NOR);
			tell_object(me,HIY"【系统】你可以通过 "HIR"help menpai"HIY"命令来了解游戏中门派系统。\n"NOR);
			me->save();
		}
		else
		{
			if( ob ) destruct(ob);
			EMOTE_D->do_emote(who, "sigh",geteuid(me),CYN,0,0,0);
			tell_object(me,CYN+who->name()+CYN"说道："+RANK_D->query_respect(me)+"你背包满了吧。\n"NOR);
		}
		return 1;
	}			
	return 0;
}

void show_gift(object who,int level)
{
	object gift;
	string msg;
	if( !who || !living(who)
	 || !present(this_object(),who) )
		return;
	if( level>10 )
		return;	
	if( who->query("giftmark/level_"+level) )
		return;	
	switch(level)
	{
		case 1 :
			tell_object(who,HIY"\n\n【系统】欢迎来到"HIG+MUDLIB_NAME+HIY"，现在正式开站了。\n"NOR);
			tell_object(who,HIY"【系统】本站的武学经验类似于RPG中的EXP。\n"NOR);
			tell_object(who,HIY"【系统】如果支持这样的泥巴游戏，请在群里给好的建议吧。\n"NOR);
			tell_object(who,HIY"【系统】年关将近，赶在2013年的最后一天开，临时仓促，可能好多地方会有问题，请\n"NOR);
			tell_object(who,HIY"【系统】在群里提出你的建议以及你发现的bug。\n\n"NOR);
			gift = new("/d/city/obj/danping");
			gift->set("num",200);
			gift->set("value",0);
			gift->set("no_give",1);
			gift->set("no_drop",1);
			gift->set("changed",1);
			gift->set("no_get",1);
			if( !gift->move(who) )
			{
				if( gift )  destruct(gift);
				return;
			}
			tell_object(who,HIY"\n【系统】游戏快乐，你得到了"+gift->query("name")+HIY"。\n"NOR);
			gift = new("/d/city/obj/yaoping");
			gift->set("num",200);
			gift->set("value",0);
			gift->set("no_give",1);
			gift->set("no_drop",1);
			gift->set("changed",1);
			gift->set("no_get",1);
			if( !gift->move(who) )
			{
				if( gift )  destruct(gift);
				return;
			}
			tell_object(who,HIY"【系统】游戏快乐，你得到了"+gift->query("name")+HIY"。\n"NOR);
			who->receive_wound("kee",30);
			who->receive_wound("sen",30);
			tell_object(who,HIY"【系统】下面你用"HIR" eat "HIY"命令，来吃治疗下你自己试试（"HIR"hp "HIY"查看你的状态）。\n"NOR);
			remove_call_out("check_gift1");
			call_out("check_gift1",1,who);
			break;
		case 2 :
			tell_object(who,HIY"\n\n【系统】恭喜！你现在算是「新手上路」了。\n"NOR);
			tell_object(who,HIY"【系统】所谓「工欲善其事，必先利其器」，你可以输入 "HIR"help weapon"HIY" 命令，来查看武器相关的说明。\n"NOR);
			tell_object(who,HIY"【系统】现在去武器店向老板打听打听「武器」的事吧。\n"NOR);
			break;		
		case 3 :
			tell_object(who,HIY"\n\n【系统】很好很好，继续努力！\n"NOR);
			tell_object(who,HIY"【系统】在没有学习「辟谷术」之前，游戏中人物的饮食掉的是很快的。\n"NOR);
			tell_object(who,HIY"【系统】虽然没有饥渴得昏迷的设定，但是当饮食很低的情况下，你的内力和法力会不掉的自动消耗的。\n"NOR);
			tell_object(who,HIY"【系统】现在去客栈中买点食物与饮料补充下你自己吧，相关命令 "HIR" list"HIY"、"HIR"buy"HIY"、"HIR"eat"HIY"、"HIR"drink"HIY" 。\n"NOR);
			tell_object(who,HIR"【系统】注意，喝酒会导致醉酒！安全第一，买了酒袋后，你可以在客栈使用 "HIY"fill jiudai"HIR" 命令来将里面的酒换成清水。\n"NOR);
			remove_call_out("check_gift3");
			call_out("check_gift3",5,who);
			break;		
		case 4 :
			tell_object(who,HIY"\n\n【系统】很好很好，继续努力！\n"NOR);
			tell_object(who,HIY"【系统】接下来我们了解下游戏的防具设定，毕竟保护好自己才是开心游戏的前提。\n"NOR);
			tell_object(who,HIY"【系统】你可以输入 "HIR"help armor"HIY" 命令，来查看防具相关的说明。\n"NOR);
			tell_object(who,HIY"【系统】现在去衣帽店向老板打听打听「盔甲」的事吧。\n"NOR);
			break;		
		case 5 :
			tell_object(who,HIY"\n\n【系统】不错不错，你现在已经 "HIR"5 "HIY"级了。\n"NOR);
			tell_object(who,HIY"【系统】接下来我们换把级别高的武器吧。\n"NOR);
			tell_object(who,HIY"【系统】现在再去武器店向老板打听打听「武器」的事吧。\n"NOR);
			break;		
		case 6 :
			break;		
		case 7 :
			break;		
		case 8 :
			break;		
		case 9 :
			break;		
		case 10:
			break;		
		default: return; 
	}	
}			 

void update_bag()
{
	int lvl;
	object who;
	who = environment();
	if( !who || !userp(who) )
	{
		destruct(this_object());
		return;
	}
	lvl = who->query_level();
	if( who->query("giftmark/level_"+lvl) )
		return;
	show_gift(who,lvl);
	return;
}
		
	