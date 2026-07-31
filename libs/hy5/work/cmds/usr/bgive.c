// give.c
// 星星2000/6/14修正bug

#include <ansi.h>

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int amount;
       	string info,name,id,filen,infoa,infob;
         object weapon,newob,oldob;
        int i,j, flag = 0,arg2;
        object ob;
        string mission, wname, wmin, file,mission2;
        string *wmission;
     me=this_player();   
	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

  //if (!wizardp(me))
  //	return notify_fail("测试中 没有对玩家开放！\n"); 

  if ((int)me->query("balance",1)<= 1000000)
  	return notify_fail("特殊装备转移需要收一百两黄金收续费 请把相应钱款存入你的银行！\n"); 
//	if( who->query("env/no_accept") )
//		return notify_fail("人家现在不想要什么东西。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "正被你骑着，不能给人。\n");

	if( !obj->query("systemmake") )
		return notify_fail("特殊可以绑定的装备才可以用这个指令。\n");

	if( obj->query("id")=="newbie armor" || obj->query("id")=="newbie sword")
		return notify_fail("新手披风不充许交换。\n");                



		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
	
			if( amount != obj->query_amount() ) 
			return notify_fail("必须完整的给别人!\n");
	
	
	}



	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
string target, item;
	object  *inv, obj2;
	int amount;
       	string info,name,id,filen,infoa,infob;
         object weapon,newob,oldob;
        int i,j, flag = 0,arg2;
        object ob;
        string mission, wname, wmin, file,mission2;
        string *wmission;
//       if( obj->query("no_drop") )
//		return notify_fail("这样东西不能随便给人。\n");
// Add by Java 
	if( userp(obj) )
		return notify_fail("你只能卖玩家。\n");

	if( !obj->query("systemmake") )
		return notify_fail("特殊可以绑定的装备才可以用这个指令。\n");

 seteuid(getuid());
 filen = "/p/residence/banding/"+me->query("id");
        if (!read_file(filen))  write_file(filen, "", 1);
        wmission = explode(read_file(filen), "\n");

//printf(base_name(obj));
	        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", wname, wmin)!=2 ) continue;
//printf(wmin);
//printf(base_name(obj));
if (base_name(obj)==wmin)
{
return notify_fail("此物品已被绑定，无法给别人使用。 \n");
      }
       
        }

// on June 3.1998



	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
		// check for dynamic_quests
        if(obj->query("dynamic_quest"))
        if(TASK_D->quest_reward(me,who,obj))
        return 1;
	if( !interactive(who) && !who->accept_object(me, obj) )
		return notify_fail("对方不接受这样东西。\n");

me->add("balance",-1000000);

	if( !userp(who) && obj->value() ) {
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
		destruct(obj);
        me->save();
        if (userp(who)) who->save();
		return 1;
	} else if( obj->move(who) ) {
		printf("你给%s一%s%s。\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s给你一%s%s。\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
		if (userp(who)) who->save();
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
指令格式 : bgive <物品名称> to <某人>
      或 : bgive <某人> <物品名称>
 
这个指令可以让你将某样特殊可以绑定的物品给别人，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
