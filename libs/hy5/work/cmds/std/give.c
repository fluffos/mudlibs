// give.c
// 星星2000/6/14修正bug

#include <ansi.h>

inherit F_CLEAN_UP;
#include "/quest/givehdgift.c"
int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
string wiz_status;
	object obj, who, *inv, obj2;
	int i, amount;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("由于你没有心跳，请重新登陆!!\n");
        }

	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if( who->query("env/no_accept")&&!wizardp(me) )
		return notify_fail("人家现在不想要什么东西。\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "正被你骑着，不能给人。\n");
if (userp(me) && !userp(who) && obj->is_character())
	return notify_fail("你想把活人送人??\n");

if (who->query("id")!="zhou botong" &&
who->query("id")!="shangguanjiannan")
{
	if( obj->query("no_give")&& obj->query("no_get")&&!wizardp(me))
			return notify_fail("这样东西不能随便给人。\n");

	if( obj->query("no_drop")&&!wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");
	if( obj->query("no_drop")&& obj->query("no_get")&&!wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");
	if( obj->query("no_get")&&!wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");

}
                if( obj->query("weapon_prop") && me->is_exert() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("你正在使用"+me->query_exert()+"，无法给出"+obj->name()+"。\n");
                if( obj->query("weapon_prop") && me->is_perform() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("你正在使用"+me->query_perform()+"，无法给出"+obj->name()+"。\n");
	if( obj->query("ownmake") && !wizardp(me) )
		return notify_fail("这样东西不能随便给人。\n");
	if( obj->query("jobfeng") )
		return notify_fail("这样东西不能随便给人。\n");

        if(obj->query("dynamic_quest") && !userp(me))
		return notify_fail("这样东西不能随便给人。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");

                // add by hello 1996.12.05
                // 检查玩家身上是不是已有太东西
                inv = all_inventory(who);
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"【玩家监督】"+me->name() + "给" + 
                  who->query("name") + "个"+obj->query("name")+HIC"!"NOR"。\n", users());

                if (inv && sizeof(inv)>49 && userp(who))
                {
                        write(who->name()+"身上都那么多东西了，你还想给他啊！\n");
                        return 1;
                }
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
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

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
int exp,pot;
string wiz_status;
 object maxpot,badguy,fang,killern;
 int i,j,maxskill,fskill,rw;

if (who->query("id")!="zhou botong")
{
	if( obj->query("no_give")&& obj->query("no_get")&&!wizardp(me))
			return notify_fail("这样东西不能随便给人。\n");

	if( obj->query("no_drop")&&!wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");
	if( obj->query("no_get")&& obj->query("no_drop") && !wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");
}
	if( obj->query("jobfeng") )
		return notify_fail("这样东西不能随便给人。\n");
        if (userp(who) &&
            sizeof(filter_array(all_inventory(who), (: ! $1->query("equipped") :))) >= 40 &&
            ! obj->can_combine_to(who))
        {
		tell_object(me, "人家身上的东西实在是太多了，没法再拿东西了。\n");
                return 0;
        }

	switch ((string)obj->query("equipped"))
	{
	case "worn":
		tell_object(me, obj->name() + "必须脱下来才能给别人。\n");
                return 0;

	case "wielded":
                tell_object(me, obj->name() + "必须解除装备才能给别人。\n");
                return 0;
	}

// Add by Java 
	if( userp(obj) )
		return notify_fail("你只能卖玩家。\n");
// on June 3.1998

	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "不是正被你骑着。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
		// check for dynamic_quests
        if(obj->query("dynamic_quest"))
        if(TASK_D->quest_reward(me,who,obj))
        return 1;





if(me->query_temp("nhdjob2lb")=="武林送货" && !userp(who)
 && obj->query("nhwtg")==who->query("name")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("nhdjobsl",1)>=1) exp=exp+((int)me->query_temp("nhdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"你成功的完成了一项江湖互动任务!\n"+
NOR);
destruct(obj);
me->delete_temp("nhdjob2lb");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2sc");
me->delete_temp("nhdjob2en");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
me->add_temp("nhdjobsl",1);
me->add("max_neili",1);
if (me->query("shen")>=0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"你增加了一点内力上限和二百点神!\n");
if (random(9)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(5,who,me);
else
"/adm/daemons/taskd"->give_gift3(7,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$n说道,还有个事你去办 你得到任务信息如下:\n" + me->query_temp("nhdjob2sc") + "。\n", me, who);
}

me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");
return 1;
}

if(me->query_temp("nhdjob2lb")=="寻找物品" && !userp(who)
 && obj->query("name")==who->query_temp("nhdjobxh")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("nhdjobsl",1)>=1) exp=exp+((int)me->query_temp("nhdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"你成功的完成了一项江湖互动任务!\n"+
NOR);
destruct(obj);
who->delete_temp("nhdjobxh");
me->delete_temp("nhdjob2lb");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2sc");
me->delete_temp("nhdjob2en");
me->clear_condition("taskjob_busy");
me->add_temp("nhdjobsl",1);
addnl(me,"exp",exp);
me->add("max_neili",1);
if (me->query("shen")>=0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"你增加了一点内力上限和二百点神!\n");
if (random(9)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(4,who,me);
else
"/adm/daemons/taskd"->give_gift3(8,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$n说道,还有个事你去办 你得到任务信息如下:\n" + me->query_temp("nhdjob2sc") + "。\n", me, who);
}

me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");
return 1;
}
//tell_object(me,obj->query("killbyn")+":"+me->query_temp("nhdjob2lb"));
if(me->query_temp("nhdjob2lb")=="宝物争夺" && !userp(who)
 && obj->query("killbyn")==who->query("id")
 && !userp(obj))
{
exp=1350+random(188);
if ((int)me->query_temp("nhdjobsl",1)>=1) exp=exp+((int)me->query_temp("nhdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"你成功的完成了一项江湖互动任务!\n"+
NOR);
destruct(obj);
//who->delete_temp("nhdjobxh");
me->delete_temp("nhdjob2lb");
me->delete_temp("nhdjob2tg");
me->delete_temp("nhdjob2sc");
me->delete_temp("nhdjob2en");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
me->add("max_neili",1);
me->add_temp("nhdjobsl",1);
if (me->query("shen")>=0) me->add("shen",200);
if (me->query("shen")<0) me->add("shen",-200);
tell_object(me,"你增加了一点内力上限和二百点神!\n");
if (random(9)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(4,who,me);
else
"/adm/daemons/taskd"->give_gift3(6,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$n说道,还有个事你去办 你得到任务信息如下:\n" + me->query_temp("nhdjob2sc") + "。\n", me, who);
}

me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");

return 1;
}


if(me->query_temp("hdjob2lb")=="送货" && !userp(who)
 && obj->query("hwtg")==who->query("name")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("hdjobsl",1)>=1) exp=exp+((int)me->query_temp("hdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"你成功的完成了一项玩家互动任务!\n"+
NOR);
destruct(obj);
me->delete_temp("hdjob2lb");
me->delete_temp("hdjob2tg");
me->delete_temp("hdjob2sc");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
me->add_temp("hdjobsl",1);
me->add("max_neili",2);
if (me->query("shen")>=0) me->add("shen",500);
if (me->query("shen")<0) me->add("shen",-500);
tell_object(me,"你增加了二点内力上限和五百点神!\n");
if (random(5)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");

//return notify_fail(HIR"你成功的完成了一个任务!。\n"NOR);
return 1;
}

if(me->query_temp("hdjob2lb")=="互动" && userp(who)
 && obj->query("hwtg")==who->query("id")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("hdjobsl",1)>=1) exp=exp+((int)me->query_temp("hdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;
tell_object(me,HIR"你成功的完成了一项玩家互动任务!\n"+
NOR);
destruct(obj);
me->delete_temp("hdjob2lb");
me->delete_temp("hdjob2tg");
me->delete_temp("hdjob2sc");
me->clear_condition("taskjob_busy");
addnl(me,"exp",exp);
addnl(who,"exp",exp);
me->add("max_neili",2);
me->add_temp("hdjobsl",1);
who->add("max_neili",2);
if (me->query("shen")>=0) me->add("shen",500);
if (me->query("shen")<0) me->add("shen",-500);
if (who->query("shen")>=0) who->add("shen",500);
if (who->query("shen")<0) who->add("shen",-500);
tell_object(who,"你增加了二点内力上限和五百点神!\n");
tell_object(me,"你增加了二点内力上限和五百点神!\n");
if (random(5)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
//return notify_fail(HIR"你成功的完成了一个任务!。\n"NOR);
return 1;
}

if(me->query_temp("hdjob2lb")=="寻物" && userp(who)
 && obj->query("name")==who->query_temp("hdjobxh")
 && !userp(obj))
{
exp=1300+random(188);
if ((int)me->query_temp("hdjobsl",1)>=1) exp=exp+((int)me->query_temp("hdjobsl",1)*30);
if (me->query("hyvip",1)==4) 
exp=exp/2+300;
else
exp=exp/2;

tell_object(me,HIR"你成功的完成了一项玩家互动任务!\n"+
NOR);
destruct(obj);
who->delete_temp("hdjobxh");
me->delete_temp("hdjob2lb");
me->delete_temp("hdjob2tg");
me->delete_temp("hdjob2sc");
me->clear_condition("taskjob_busy");
me->add_temp("hdjobsl",1);
addnl(me,"exp",exp);
me->add("max_neili",2);
if (me->query("shen")>=0) me->add("shen",500);
if (me->query("shen")<0) me->add("shen",-500);
tell_object(me,"你增加了二点内力上限和五百点神!\n");
if (random(5)==0)
	 {
tell_object(me,"你的门派贡献增加了!\n");
	 me->add("mpgx",1);
}
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
//return notify_fail(HIR"你成功的完成了一个任务!。\n"NOR);
return 1;
}


        if(!userp(who)
 && obj->query("name")==me->query_temp("jobitem")
 && who->query("name")==me->query_temp("jobnpc")
 && !userp(obj))
{
exp=random(320)+390;
pot=exp*2/3+random(280);
exp=exp/2;
  if (exp < 90) exp=88+random(22);
if (!me->query("zhuanshen") && me->query("combat_exp",1)<=8000000 ) exp=exp*5;
addnl(me,"exp",exp);

fskill=me->query_skill("force",1);
if (fskill >=100)
{
	me->start_busy(2);
rw=random(199);
fskill=fskill/2+1;
killern=new("/quest/menpai/man");
killern->move(environment(me));
killern->initlvl(fskill);
killern->setn(rw);
//killern->kill_ob(me);

tell_object(me, me->query("name")+"发现附近有个" + killern->query("name") + "很可疑。\n" NOR);

}
tell_object(me,HIR"你成功的完成了一项任务!\n"+
NOR);
		if ((int)me->query_temp("menpaikill")==1)
		{
me->add_temp("menpaijob",1);
		me->delete_temp("menpaikill");	
		}
destruct(obj);
me->apply_condition("nonamejob",0);
me->delete_condition("nonamejob");
me->set("quest", 0);
me->delete_temp("jobnpc");
me->delete_temp("jobitem");
//return notify_fail(HIR"你成功的完成了一个任务!。\n"NOR);
return 1;
}

	if( !interactive(who) && !who->accept_object(me, obj) )
//		return notify_fail("你想给，可是人家还不想要你的这样东西。\n");
		return notify_fail("对方不接受这样东西。\n");
/* 
       //给东西记录到/log/cmds/give   星星(lywin)

	log_file("cmds/give",
	sprintf("%s(%s) 在%s把一个(%s) 给了%s（%s）on %s\n",
	me->name(),  //记录使用命令的人名
	geteuid(me), //记录使用命令的ID
	(string)environment(me)->query("short"), //记录复制物品所在的房间
	obj->name(1), //记录给的物品的名称
	who->name(),  //记录使用对象的人名
	geteuid(who), //记录使用对象的ID
	ctime(time()) ) ); //记录使用命令的时间
*/

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"【玩家监督】"+me->name() + "给" + 
                  who->query("name") + "个"+obj->query("name")+HIC"!"NOR"。\n", users());

	if( !userp(who) && obj->value() ) {
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
if (!obj->query("money_id") || !who->query("pubmaster") || !who->query_temp("no_kill")  || obj->query("base_value") < 100 )
{
		destruct(obj);
}
else
{
//if (!userp(who) && (int)who->query("combat_exp")==50000000)
//{
//		destruct(obj);
//}

	obj->move(who);

}

//if (!userp(who) && (int)who->query("combat_exp")==50000000)
//{
//		destruct(obj);
//}

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
	if( !userp(who) && !obj->is_character()
	&& !userp(obj)) 
{
obj->set("no_beg",1);	
obj->set("no_steal",1);
}


		if (userp(who)) who->save();
		if (userp(obj)) obj->save();
if (userp(me) &&me->query_temp("xmud")) 
{
	seteuid(getuid());
	me->force_me("xnventory");
}

if (userp(who) && who->query_temp("xmud")) 
{
	seteuid(getuid());
	who->force_me("xnventory");
}
if (userp(obj) && obj->query_temp("xmud")) 
{
	seteuid(getuid());
	obj->force_me("xnventory");
}

		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
 
这个指令可以让你将某样物品给别人，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
