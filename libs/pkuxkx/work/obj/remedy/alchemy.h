#include <ansi.h>
#include <dbase.h>
#define Interval 6
#define CHECK_DOOR_TIME 10
//炼药系统 Zine@pkuxkx 2014
//火焰CYN时需要玩家defend,MAG需要blow,HIW需要turndown,HIR需要turnup
int finish_alchemy(object me,mapping prescription,int finish);
string inside_detail();
mapping * prescriptions()
{
	return REMEDY->all_prescriptions();
}//raws是药材配方数量，product是药品目录，product_no是炼成最大产量，period是炼成时间，maker_level是玩家允许炼药最低级别，improve_level是在多少级alchemy之前可以提升，phase_color只能使用0,1,2(MAG,HIW,HIR三种颜色)，代表火焰颜色。skill_points和提升alchemy技能有关，furnace_lv是要求的药炉等级。

void init()
{
	if (this_object()->query("LongTerm")&&time()>=this_object()->query("LongTerm"))
	{
		tell_object(this_player(),"你的租期到了，要再使用"+this_object()->query("name")+"，就要续租了。\n");
		return;
	}
	add_action("do_syn","syn");
	add_action("do_lookin","lookin");
	add_action("do_look","look");
	add_action("do_process","process");
	if (this_player()->is_busy())
	{
		tell_object(this_player(),"你正忙着呢。\n");
		return;
	}
	add_action("do_unlock","unlock");//无主orOwner才能操作
	add_action("do_place","putin");//无主OrOwner操作
	add_action("do_defend","defend");
	add_action("do_blow","blow");
	add_action("do_turnup","turnup");
	add_action("do_turndown","turndown");
	add_action("do_lock","lock");
	add_action("do_fire","fire");
	add_action("do_putout","putout");
	add_action("do_takeout","takeout");
	
}
void refresh()
{
	delete("operating");
	delete("product");
	delete("RawMaterial");
	delete_temp("times");
}
void check_availability()
{
	object ob=this_object();
	if (!ob->query("product")||!mapp(ob->query("product")))
	refresh();
}
string phase_color()
{
	object ob=this_object();
	string *color=({MAG,HIW,HIR});
	if (!ob->query("product")||!mapp(ob->query("product")))
	return RED;
	if (ob->query_temp("times")<ob->query("product")["period"]/2)
	return color[ob->query("product")["phase_color"][0]];
	else if (ob->query_temp("times")<ob->query("product")["period"]*2/3)
	return color[ob->query("product")["phase_color"][1]];
	else if (ob->query_temp("times")<ob->query("product")["period"]*4/5)
	return color[ob->query("product")["phase_color"][2]];
	else
	return CYN;
}
void check_furnace(object me)
{
	object ob=this_object();
	string fire;
	if (!ob->query("operating"))
	{
		tell_object(me,this_object()->query("name")+"并未被使用。\n");
		return;
	}
	fire=phase_color()+"\n
                .               
              :|!`              
             .;|||'     .:`     
        `:.  .;|||||:  .!|'     
       '||'  :|!;!|||'.;|||:    
     `!||!:;|||;::!|||||||||' .'
 :!``;|||||||||;::::;||||;;|!!!'
.:!!!!!!;:;!!!;::::::!!;:::;!!:`
`!!!!!;;:::::::' .'::::::::;!!:`
';;;::;::::::::`    '::``::::;:`
`;;::::::'. ..          .':::;:`
 ':::::'                .':::'. \n"+NOR;
	tell_object(me,this_object()->query("name")+"现在炉内的状况：\n");
	tell_object(me,fire);
	return;
}
int do_process()
{
	object ob=this_object(),me=this_player();
	float percent;
	string msg="『炼药进度』\n"+"--------------------------------------------------------------\n";
	if (!ob->query("product")||!mapp(ob->query("product"))||!ob->query("product")["period"])
	{
		msg+="尚不明确。\n";
		return notify_fail(msg);
	}
	percent=to_float(query_temp("times"))/to_float(query("product")["period"]);
	if (percent>1.0)
	percent=1.0;
	percent*=100.0;
	msg+="【目标】"+HBCYN+HIW+query("product")["name"]+NOR+"\t\t【进度】"+HIW+sprintf("%.2f%s",percent,"%")+NOR+"\t\t【失误】"+HIR+chinese_number(me->query_temp("alchemy/error"))+"次"+NOR+"。\n";
	tell_object(me,msg);
	return 1;
}
int do_lookin(string arg)
{
	object me=this_player();
	if (member_array(arg,this_object()->parse_command_id_list())!=-1)
	check_furnace(me);
	else
	return 0;
	return 1;
}
int do_look(string arg)
{
	object me=this_player();
	if (member_array(arg,this_object()->parse_command_id_list())!=-1)
	tell_object(me,inside_detail());
	else
	return 0;
	return 1;
}
string interpret(mixed ob)//把药材翻译成药材代码
{
	int code;
	string type,*level=({"地","山","水","风","雷","火","泽","天"});
	mapping types=(["yan":HIR+"炎晶","mu":HIG+"木灵","sui":HIY+"玉髓","jin":HIW+"精金","bing":HIB+"玄冰","gu":CYN+"神龙骨","yu":WHT+"凤凰羽","jiao":RED+"麒麟角","jia":YEL+"玄武甲","ri":HIC+"日魂","yue":HIM+"月魄",]);
	mapping *list;
	if (!ob) return "other";
	if (objectp(ob))
	{
		if (ob->query("drugcode"))
		return "*"+ob->query("drugcode");
		else if (ob->is_gem())
		return "#"+ob->query("level")+"#"+ob->query("material");
		else
		return "other";
	}
	if (stringp(ob))
	{
		if (sscanf(ob, "*%d",code)== 1 )
		{
			list=REMEDY->List();
			for (int i=0;i<sizeof(list);i++)
			if (list[i]["id"]==code)
			return list[i]["name"];
		}
		if (sscanf(ob, "#%d#%s",code,type)== 2 )
		if (code>=1&&code<=8&&stringp(types[type]))
		return HBWHT+RED+level[code-1]+NOR+types[type]+NOR;
	}
	return "other";
}
mapping check_prescription(object me)//返回成品药物路径，考虑炉中药材，自身配方，公共配方，以及自身炼丹级别，([])为失败
{
	mapping raws,result,*prescriptions;
	object *inv,ob=this_object();
	string *temp_sets;
	int i,check;
	inv=all_inventory(ob);
	for (i=0;i<sizeof(inv);i++)
	{
		if (interpret(inv[i])!="other")
		{
			if (!ob->query("RawMaterial/"+interpret(inv[i])))
			ob->set("RawMaterial/"+interpret(inv[i]),1);
			else
			ob->add("RawMaterial/"+interpret(inv[i]),1);
		}
		destruct(inv[i]);
	}
	prescriptions="/cmds/usr/formula"->pres(me);
	for (i=0;i<sizeof(prescriptions);i++)
	{
		for (int j=0;j<sizeof(prescriptions[i]["raws"]);j++)
		{
			temp_sets=keys(prescriptions[i]["raws"]);
			check=sizeof(temp_sets);
			for (int k=0;k<sizeof(temp_sets);k++)
			if (ob->query("RawMaterial/"+temp_sets[k])==prescriptions[i]["raws"][temp_sets[k]])
			check-=1;
			if (check<1)
			{
				if (prescriptions[i]["temp_prescription"])
				me->delete_temp("myTempPrescription");
				return prescriptions[i];
			}
		}
	}
	return ([]);
}
void FailureProduct(object *inv,object ob,string msg)
{
	object obj=new(__DIR__"slag");
	for (int i=0;i<sizeof(inv);i++)
	destruct(inv[i]);
	message_vision(msg,ob);
	obj->move(ob);
	refresh();
	return;
}
void check_alchemy(object me)
{
	object ob=this_object(),*inv;
	if (!me)
		return FailureProduct(inv,ob,"$N中的只剩下了炉渣。\n");
	if (!living(me)||environment(me)!=environment(ob))
		return FailureProduct(inv,ob,"$N中的只剩下了炉渣。\n");
	inv=all_inventory(ob);
	if (!ob->query("product")||!mapp(ob->query("product"))||sizeof(inv)>=1)
		return FailureProduct(inv,ob,"$N中的只剩下了炉渣。\n");
	me->set_temp("alchemy/ongoing",time()+Interval);
	ob->add_temp("times",1);
	finish_alchemy(me,ob->query("product"),ob->query_temp("times")>ob->query("product")["period"]?1:0);
	return;
}
int finish_alchemy(object me,mapping prescription,int finish)
{
	mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
	int bonus=0,sk_point,extra_sk,alchemy=0;
	object obj;
	if (finish)
	{
		if (F_PRO->pro_class(me)=="alchemy")
		alchemy=1;
		if (me->query_skill("alchemy",1)>prescription["maker_level"]*3/2)
		bonus+=10;
		if (me->query_skill("alchemy",1)>prescription["maker_level"]*2)
		bonus+=10;
		bonus-=10*me->query_temp("alchemy/error");
		bonus+=random(100);
		if (alchemy)
		bonus+=random(5);
		extra_sk=random(10)+me->query_skill("alchemy",1);
		if (wizardp(me))
		tell_object(me,"炼药："+bonus+"，炼药难度："+prescription["fail_possibility"]+
		"|技能指数："+extra_sk+"，需要："+prescription["maker_level"]+"|药炉等级："+this_object()->query("furnace_lv")+"，需要："+prescription["furnace_lv"]+"。\n");
		if (!me->query("MyAlchemy/detox_expert")&&prescription["adv_detox"])
		{
			write(WHT+prescription["name"]+WHT+"属于高级解毒药，你的解毒知识不足以炼制它。\n");
			return 1;
		}
		if (REMEDY->DailyProductLimit(prescription["name"])>0&&date!=me->query("MyAlchemy/dailylimit/"+prescription["name"]+"/date"))
		{
			me->set("MyAlchemy/dailylimit/"+prescription["name"]+"/num",0);
			me->set("MyAlchemy/dailylimit/"+prescription["name"]+"/date",date);
		}
		if (REMEDY->DailyProductLimit(prescription["name"])>0&&me->query("MyAlchemy/dailylimit/"+prescription["name"]+"/num")>=REMEDY->DailyProductLimit(prescription["name"]))
		{
			write(WHT+prescription["name"]+WHT+"这种夺天造化的丹药，以你的能力心性，一天最多炼制"+chinese_number(REMEDY->DailyProductLimit(prescription["name"]))+"次。\n"NOR);
			return 1;
		}
		else if (bonus>prescription["fail_possibility"]&&extra_sk>prescription["maker_level"]
		&&this_object()->query("furnace_lv")>=prescription["furnace_lv"])//suc
		{
			for (int i=0;i<(1+random(prescription["product_no"]));i++)
			{
				obj=new(prescription["product"]);
				if (obj->query("fake_drug"))
				obj->modify(me);
				obj->move(this_object());
				if (!obj) log_file("user/drug_error",sprintf("%s",prescription["product"]+"\t"));
				sk_point=random(prescription["skill_points"]);
			}
			if (REMEDY->DailyProductLimit(prescription["name"])>0)
			me->add("MyAlchemy/dailylimit/"+prescription["name"]+"/num",1);
			if (prescription["detox_entry"]&&me->query("MyAlchemy/detox_expert"))
			tell_object(me,HIC+"作为一位解毒精通的药师，简单的解毒药物对你毫无难度。\n"+NOR);
			if (prescription["detox_entry"]&&!me->query("MyAlchemy/detox_expert"))
			me->add("MyAlchemy/detox_entry",1);
			if (me->query("MyAlchemy/detox_entry")>99)
			{
				me->delete("MyAlchemy/detox_entry");
				me->set("MyAlchemy/detox_expert",1);
			}
		}
		else
		{
			obj=new(__DIR__"slag");
			obj->move(this_object());
			if (REMEDY->DailyProductLimit(prescription["name"])>0)
			sk_point=random(5);
			else
			sk_point=random(prescription["skill_points"]/2);
		}
		if (alchemy)
		sk_point*=2;
		if (me->query_skill("alchemy",1)%10==0)
		{
			sk_point*=2;
			write(HIC+"这一阶段，你觉得自己体会炼丹术特别顺利。\n"+NOR);
		}
		if (time()<me->query("pro_double_reward"))
		sk_point*=2;
		if (me->query_skill("alchemy",1)<=prescription["improve_level"]&&
		(me->query_skill("alchemy",1)<100||alchemy))
		me->improve_skill("alchemy",1+sk_point);
		refresh();
		message_vision(CYN"$N"+CYN+"正是炉火纯青之态，可以打开看看了。\n"+NOR,this_object());
		me->delete_temp("alchemy/ongoing");
		return 1;
	}
	else
	{
		call_out("check_alchemy",Interval,me);
		if (me->query_temp("alchemy/abnormal"))
		{
			me->add_temp("alchemy/error",1);
			me->delete_temp("alchemy/abnormal");
		}
		if (!random(5))
		{
			tell_object(me,BLINK+"炉火似乎有些异常。\n"+NOR);
			me->set_temp("alchemy/abnormal",this_object()->query_temp("times"));
			this_object()->set("act",0);
		}
	}
	return 1;
}
int do_defend()
{
	object me=this_player(),ob=this_object();
	int neili=50+random(200);
	message_vision("$N对着炉内灌注内力，以使丹药更加精纯。\n",me);
	if (phase_color()==CYN&&!ob->query("act"))
	{
		if (me->query("neili")>neili)
		{
			me->delete_temp("alchemy/abnormal");
			me->add("neili",-neili);
		}
		else
		{
			tell_object(me,"你耗尽了内力，但似乎还略有欠缺。\n");
			me->set("neili",0);
		}
	}
	ob->set("act",1);
	return 1;
}
int do_blow()
{
	object me=this_player(),ob=this_object();
	message_vision("$N对着炉门内猛烈扇风。\n",me);
	if (phase_color()==MAG&&!ob->query("act"))
	me->delete_temp("alchemy/abnormal");
	ob->set("act",1);
	return 1;
}

int do_turnup()
{
	object me=this_player(),ob=this_object();
	message_vision("$N把炉门开大了一些。\n",me);
	if (phase_color()==HIR&&!ob->query("act"))
	me->delete_temp("alchemy/abnormal");
	ob->set("act",1);
	return 1;
}
int do_turndown()
{
	object me=this_player(),ob=this_object();
	message_vision("$N把炉门关小了一些。\n",me);
	if (phase_color()==HIW&&!ob->query("act"))
	me->delete_temp("alchemy/abnormal");
	ob->set("act",1);
	return 1;
}
void check_door(object me)
{
	object *inv,ob=this_object();
	inv=all_inventory(ob);
	if (!me)
		return FailureProduct(inv,ob,"$N的炉门没有关闭，火力太旺，炉中的一切都变成了炉渣。\n");
	if (!ob->query("closed")||environment(me)!=environment(ob))
		return FailureProduct(inv,ob,"$N的炉门没有关闭，火力太旺，炉中的一切都变成了炉渣。\n");
	if (!ob->query("product")||sizeof(keys(ob->query("product")))<1)
		return FailureProduct(inv,ob,"$N中的只剩下了炉渣。\n");
	me->set_temp("alchemy/ongoing",time()+Interval);
	call_out("check_alchemy",Interval,me);
	return;
}
int do_unlock()
{
	object me=this_player(),ob=this_object();
	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (!ob->query("closed"))
		return notify_fail(ob->query("name")+"的炉门已经是开着的了。\n");
	ob->delete("closed");
	message_vision("$N用力的打开了$n的炉门。\n"NOR,me,ob);
	return 1;
}
int do_lock()
{
	object me=this_player(),ob=this_object();
	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (ob->query("closed"))
		return notify_fail(ob->query("name")+"的炉门已经是关着的了。\n");
	ob->set("closed",1);
	message_vision("$N用力的关上了$n的炉门。\n"NOR,me,ob);
	return 1;
}

string inside_detail()
{
	string msg;
	object *inv,ob=this_object();
	inv=all_inventory(ob);
	if (sizeof(inv)==0) return ob->query("name")+"里面非常干净，什么东西都没有。\n";
	msg=ob->query("name")+"里面放着这些东西：\n";
	for (int i=0;i<sizeof(inv);i++)
	msg+=inv[i]->query("name")+"\n";
	return msg;
}
int do_syn(object me)
{
	if (!me)
	me=this_player();
	if (REMEDY->query_verison()<=me->query("MyAlchemy/Version"))
	return notify_fail("你现在不用同步自有药方。\n");
	else
	REMEDY->synchronize(me);
	write("你现在的自有药方已经是最新的了。\n");
	return 1;
}
int do_place(string arg)//加药材进炉子
{
	int capacity=10;
	object me=this_player(),ob=this_object(),obj;
	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (!arg)
		return notify_fail("你要把什么放进"+ob->query("name")+"。\n");
	if (!obj=present(arg,me))
		return notify_fail("你身上并无"+arg+"这样东西。\n");
	if (ob->query("operating"))
	{
		check_availability();
		return notify_fail("这具"+ob->query("name")+"正在炼制着丹药。\n");
	}
	if (ob->query("closed"))
		return notify_fail("这具"+ob->query("name")+"的炉门是关着的，你要先打开(unlock)它。\n");
	if (ob->query("capacity"))
	capacity=ob->query("capacity");
	if (sizeof(all_inventory(ob))>=capacity)
		return notify_fail(ob->query("name")+"里已经有太多的东西了，要清理一下才能继续使用。\n");
	obj->move(ob);
	message_vision(HIW"$N"+HIW+"将$n"+HIW+"小心地放入"+ob->query("name")+HIW+"里面。\n"NOR,me,obj);
	return 1;
}
int do_fire()
{
	object me=this_player(),ob=this_object(),obj;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (REMEDY->query_verison()>me->query("MyAlchemy/Version"))
	do_syn(me);
	if (ob->query("operating"))
	{
		check_availability();
		tell_object(me,"这具"+ob->query("name")+"正在炼制着丹药。\n");
		return 1;
	}
	if (ob->query("closed"))
	{
		tell_object(me,"这具"+ob->query("name")+"的炉门是关着的，你要先打开(unlock)它。\n");
		return 1;
	}
	if (!obj=present("huo zhezi",me))
	{
		tell_object(me,"你需要一个火折子(Huo zhezi)引燃炉火。\n");
		return 1;
	}
	destruct(obj);
	message_vision(HIR"$N"+HIR+"引燃了$n"+HIR+"中的炉火。\n"NOR,me,ob);
	ob->set("product",check_prescription(me));
	me->delete_temp("alchemy");
	me->set_temp("alchemy/ongoing",time()+CHECK_DOOR_TIME);
	call_out("check_door",CHECK_DOOR_TIME,me);
	set("operating",1);
	tell_object(me,"炉火越来越旺了，记得快点关上(lock)炉门，否则可能火太旺烧成炉渣哦。\n");
	return 1;
}
int do_putout()
{
	object me=this_player(),ob=this_object();
	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (!ob->query("operating"))
		return notify_fail("你弄错了吧？"+ob->query("name")+"是熄灭着的。\n");
	ob->delete("operating");
	remove_call_out("check_alchemy");
	message_vision(WHT+"$N"+WHT+"认真地熄灭了$n"+WHT+"内的炉火。\n"NOR,me,ob);
	return 1;
}
int do_takeout(string arg)
{
	object me=this_player(),ob=this_object(),*inv,obj;
	string msg="";
	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (ob->query("closed"))
		return notify_fail("这具"+ob->query("name")+"的炉门是关着的，你要先打开(unlock)它。\n");
	if (ob->query("operating"))
	{
		check_availability();
		return notify_fail("这具"+ob->query("name")+"正在炼制着丹药，要取出物品你要先熄灭(putout)它。\n");
	}
	if (!arg||!obj=present(arg,ob))
	{
		inv=all_inventory(ob);
		for (int i=0;i<sizeof(inv);i++)
		{
			inv[i]->move(me);
			msg+=inv[i]->query("name");
			if (i<sizeof(inv)-2)
			msg+="、";
			else if (i==sizeof(inv)-2)
			msg+="和";
			else if (i==sizeof(inv)-1)
			msg+="。";
		}
		if (sizeof(inv)>0)
		message_vision("$N从$n取出了"+msg+"\n",me,ob);
		else
		return notify_fail(ob->query("name")+"里什么也没有。\n");
	}
	else
	{
		message_vision("$N从$n取出了"+obj->query("name")+"。\n",me,ob);
		obj->move(me);
	}
	return 1;
}