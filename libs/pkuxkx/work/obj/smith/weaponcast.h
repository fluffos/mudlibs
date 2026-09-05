#include <ansi.h>
#include <dbase.h>
#define CHECK_DOOR_TIME 10
#define Mark "weapon_cast"
//兵器铸造系统 Zine@pkuxkx 2014
//火焰CYN时需要玩家defend,MAG需要blow,HIW需要turndown,HIR需要turnup
int Interval(object me)
{
	int interval=5+random(3);
	return interval;
}
string inside_detail();

void init()
{
	if (this_object()->query("LongTerm")&&time()>=this_object()->query("LongTerm"))
	{
		tell_object(this_player(),"你的租期到了，要再使用"+this_object()->query("name")+"，就要续租了。\n");
		return;
	}
	add_action("do_lookin","lookin");
	add_action("do_look","look");
	add_action("do_process","process");
	add_action("do_put","put");
	if (this_player()->is_busy())
	{
		tell_object(this_player(),"你正忙着呢。\n");
		return;
	}
	add_action("do_hammer","hammer");
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
void refresh(int flag)
{
	if (flag)
	{
		delete("operating");
		remove_call_out("check_temperature");
	}
	remove_call_out("check_material");
	delete("product");
	delete("act");
	delete("theMaterial");
	set("door",5);//半开半闭
	delete_temp("phase_color");
}
void check_availability()
{
	object ob=this_object();
	if (!ob->query("product")||!mapp(ob->query("product")))
	refresh(1);
}
string phase_color()
{
	string color,*colors=({MAG,HIW,HIR,CYN});
	color=colors[random(sizeof(colors))];
	set_temp("phase_color",color);
	return color;
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
	if (ob->query("temperature")<0)
	{
		refresh(1);
		tell_object(me,this_object()->query("name")+"的炉火彻底熄灭了。\n");
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
	tell_object(me,this_object()->query("name")+"现在炉内火焰的状况：\n");
	tell_object(me,fire);
	return;
}
int do_process()
{
	object ob=this_object(),me=this_player(),obj;
	float percent;
	string msg="『锻造进度』\n"+"--------------------------------------------------------------\n";
	if (!ob->query("product")||!mapp(ob->query("product"))||!obj=query("theMaterial"))
	{
		msg="『打铁炉信息』\n"+"--------------------------------------------------------------\n";
		msg+="【炉温】";
		if (ob->query("temperature")>0)
		msg+=ob->query("temperature");
		else
		msg+="尚未点燃";
		return notify_fail(msg+"\n");
	}
	msg+="【目标】"+HBCYN+HIW+query("product")["name"]+NOR;
	msg+="|【炉温】"+HIW+query("temperature")+NOR;
	if (obj->query("total_heat")>=ob->query("product")["heat_require"])
	percent=1.0;
	else
	percent=to_float(obj->query("total_heat"))/to_float(ob->query("product")["heat_require"]);
	percent*=100.0;
	msg+="|【热力】"+HIR+sprintf("%.2f%s",percent,"%")+NOR;
	if (obj->query("hammered")>=ob->query("product")["hammer_require"])
	percent=1.0;
	else
	percent=to_float(obj->query("hammered"))/to_float(ob->query("product")["hammer_require"]);
	percent*=100.0;
	msg+="|【锤击】"+RED+sprintf("%.2f%s",percent,"%")+NOR;
	msg+="|【失误】"+WHT+chinese_number(obj->query("error"))+NOR+"次\n";
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
mapping check_will(object me)//返回要打造的武器或铠甲([])失败
{
	mapping *products="/obj/smith/smithing"->smith(me);
	if (!me->query("env/smithing"))
	return ([]);
	for (int i=0;i<sizeof(products);i++)
	{
		if (products[i]["name"]==me->query("env/smithing"))
		return products[i];
	}
	return ([]);
}
void FailureProduct(object *inv,object ob,string msg)
{
	object obj=new("/obj/remedy/slag");
	for (int i=0;i<sizeof(inv);i++)
	destruct(inv[i]);
	message_vision(msg,ob);
	obj->move(ob);
	refresh(1);
	return;
}
int automatic_drop(int flag)//return 炉子一周期自动降低的热力。1/10即为自动降低的温度
{
	int res=-60;
	if (query("auto_drop")&&intp(query("auto_drop")))
	res=query("auto_drop");
	if (flag==1)//燃烧时候门才有影响
	res-=(5-query("door"))*10;//query("door")是炉门1-9，1最小，空气少，火小温度降最快。
	return res;
}
int calc_temperature(object me,object *inv)//合适的temperature在1-100之间。
{
	int remain=0,total_temp=0,count=0,peak=0,res;
	for (int i=0;i<sizeof(inv);i++)
	{
		if (inv[i]->is_castfuel())
		{
			if (inv[i]->query("thermalpower")>0)
			{
				inv[i]->add("thermalpower",-1);
				count+=1;
				if (inv[i]->query("thermalpower")>remain)
				remain=inv[i]->query("thermalpower");//可再燃烧多久
				if (inv[i]->query("peakTemperature")>peak)
				peak=inv[i]->query("peakTemperature");
				total_temp+=inv[i]->query("thermalrate");//总最高温度
			}
			else
			{
				destruct(inv[i]);
			}
		}//thermalpower是单个燃料剩余火力，peakTemperature是单个燃料最高可达到温度
	}
	add("total_heat",total_temp);//总火力用燃料火力-自然降温
	if (!count)
	{
		tell_object(me,"因为燃料燃尽，炉温正在急剧下降。\n");
		res=query("temperature")+automatic_drop(-1)/10;
	}
	else
	{
		tell_object(me,"这"+this_object()->query("name")+"里的燃料还可以再燃烧"+CHINESE_D->chinese_period(remain*Interval(me))+"。\n");
		res=query("temperature")+automatic_drop(1)/10+total_temp/count;//平均温度
	}
	if (res>peak)
	res=peak;
	return res;
}
void check_temperature(object me)//检查炉温
{
	object ob=this_object(),*inv;
	int temperature;
	if (!me)
		return FailureProduct(inv,ob,"$N中的只剩下了炉渣。\n");
	if (!living(me)||environment(me)!=environment(ob))
		return FailureProduct(inv,ob,"$N中的只剩下了炉渣。\n");
	inv=all_inventory(ob);
	me->set_temp(Mark+"/ongoing",time()+Interval(me));
	temperature=calc_temperature(me,inv);
	if (temperature<0)
	{
		refresh(1);
		message_vision("$N彻底熄灭了。\n",ob);
		return;
	}
	if (temperature>(query("HeatLimit")>100?query("HeatLimit"):100))//炉子能承受的炉温上限
	{
		message_vision("$N承受不了内力的高温，炸裂开来。\n",ob);
		destruct(ob);
		return;
	}
	call_out("check_temperature",Interval(me),me);
	set("temperature",temperature);
	return;
}
int check_material(object me,object material)
{
	object ob=this_object(),*inv;
	int tolerance=10;
	if (!material||environment(material)!=ob)
	{
		tell_object(me,"材料都没了，还打造什么？\n");
		return 0;
	}
	if (!ob->query("product")||!mapp(ob->query("product")))
	{
		tell_object(me,"你要打造什么？必须提前设置好。\n");
		return 0;
	}
	if (material->query("type")!=ob->query("product")["type"])
	{
		tell_object(me,material->query("name")+"的形状不适合打造"+ob->query("product")["name"]+"。\n");
		return 0;
	}
	if (ob->query("temperature")<ob->query("product")["temperature"]*9/10||ob->query("temperature")>ob->query("product")["temperature"]*11/10)
	{
		material->add("inappropriate_temp",1);
	}
	if (material->query("tolerance")>tolerance)
	tolerance=material->query("tolerance");
	if (material->qeury("inappropriate_temp")>tolerance)
	{
		if (material->query("level")>0)
		{
			material->add("level",-1);
			tell_object(me,"长期在不合适的温度下加工，"+material->query("name")+"的品质下降了。\n");
		}
		else
		{
			tell_object(me,"长期在不合适的温度下加工，"+material->query("name")+"彻底损坏了。\n");
			destruct(material);
			return 0;
		}
	}
	inv=all_inventory(ob);
	for (int i=0;i<sizeof(inv);i++)
	{
		if (!inv[i]->is_castfuel()&&inv[i]!=material)
		{
			tell_object(me,"炉中的"+inv[i]->query("name")+"立刻给融化了。\n");
			destruct(inv[i]);
		}
	}
	if (material->query("total_heat")>ob->query("product")["heat_require"])
	material->set("heat_finish",1);
	else
	material->add("total_heat",ob->query("total_heat"));
	if (ob->query_temp("abnormal"))
	{
		material->add("error",1);
		ob->delete_temp("abnormal");
	}
	if (!random(12))
	{
		tell_object(me,BLINK+"炉火似乎有些异常。\n"+NOR);
		ob->set_temp("abnormal",1);
		ob->set("act",0);
	}
	if (ob->query("temperature")<0)
	{
		message_vision(HIR+BLINK+"$N彻底熄灭了。\n"+NOR,ob);
	}
	call_out("check_material",Interval(me),me,material);
	return 1;
}//material有query("is_castmaterial")标记
int improve_smithing(object me,int material_lv,int adv,int suc,int smith)
{
	int res,lv,smith_lv=1+me->query_skill("smithing",1)/15,*sk_points=({12,16,20,24,30,32,36,40});
	material_lv=material_lv>0?material_lv:1,
	lv=material_lv>smith_lv?smith_lv:material_lv;
	if (lv>8) lv=8;
	if (lv<1) lv=1;
	res=sk_points[lv-1];
	if (smith_lv-1>material_lv)
	{
		tell_object(me,RED+"你用来锻造的材料相对于你的能力太低了，技能提升受到影响。\n"+NOR);
		if (smith_lv-3>material_lv)
		res=1;
		else
		res/=2;
	}
	if (smith)
	res=res*3/2;
	if (me->query_skill("smithing",1)%10==0&&me->query_skill("smithing",1)!=0)
	{
		res*=2;
		write(HIC+"这一阶段，你觉得自己体会铸造术特别顺利。\n"+NOR);
	}
	if (suc)
	{
		res=res/2+random(res/2);
		if (adv)
		res=res*4/3;
	}
	else
	res=1+random(res/2);
	if (time()<me->query("pro_double_reward"))
	res*=2;
	if (me->query_skill("smithing",1)<100||smith)
	me->improve_skill("smithing",res);
	return res;
}
int CalcMaterial(object me,object ob,int lv)
{
	if (lv>4&&!me->query(Mark+"/treating"+lv))
	{
		tell_object(me,HBWHT+RED+"可惜你没有掌握"+ob->query("name")+HBWHT+RED+"的加工方式，"+ob->query("name")+HBWHT+RED+"只能被当作第四级材料巽風之材来加工！\n"+NOR);
		return 4;
	}
	return lv;
}
int finish(object me,object material,mapping product)
{
	int bonus=random(100),extra_sk,smith=0,error=material->query("error"),err=material->qeury("inappropriate_temp"),suc=0,obstacle=5;
	int lv,material_lv=material->query("level")>0?material->query("level"):1,smith_lv=1+me->query_skill("smithing",1)/15;
	object obj;
	if (F_PRO->pro_class(me)=="smith")
	{
		smith=1;
		bonus+=random(5);
		obstacle-=2;
	}
	//以下为提升级别
	if (me->query_skill("smithing",1)>product["maker_level"]*3/2&&smith)
	bonus+=10;
	if (me->query_skill("smithing",1)>product["maker_level"]*2)
	bonus+=10;
	bonus-=5*(error>4)?4:error;
	extra_sk=random(10)+random(5)*smith+me->query_skill("smithing",1);
	material_lv=CalcMaterial(me,material,material_lv);
	if (wizardp(me))
	tell_object(me,"铸造："+bonus+"，铸造难度："+product["fail_possibility"]+"|技能指数："+extra_sk+"，需要："+product["maker_level"]+"|材料:"+material_lv+"级。\n");
	if (bonus>(product["fail_possibility"]+material->query("level")*obstacle)&&extra_sk>product["maker_level"])//suc
	suc=1;
	improve_smithing(me,material->query("level"),material->query("advanced"),suc,smith);
	me->add("myWeaponCast/stat/TotalWorks",1);
	me->add("myWeaponCast/stat/"+product["name"],1);
	destruct(material);
	//以下为生成物品
	obj=new(product["product"]);
	lv=material_lv>smith_lv?smith_lv:material_lv;
	obj->set_temp("gen_grade",lv);
	obj->set("PlayerMade",me->query("id"));
	obj->generate(me,product["name"],suc,smith,err,lv);
	obj->move(this_object());
	refresh(0);
	message_vision(CYN"$N"+CYN+"里锻打的"+obj->query("name")+CYN+"似乎成型了，拿出来(takeout <装备名>)看看吧。\n"+NOR,this_object());
	me->delete_temp(Mark+"/ongoing");
	return 1;
}
int do_hammer(string arg)
{
	object *inv,obj,me=this_player(),ob=this_object(),tool;
	int allow,sk=1;
	if (!arg)
	return notify_fail("你要锻打什么东西？\n");
	inv=all_inventory(this_object());
	if (sizeof(inv)<1)
	return notify_fail("炉子里没有东西，你要锻打什么？\n");
	if (!ob->query("product")||!mapp(ob->query("product")))
	return notify_fail("你要打造什么？必须提前设置好。\n");
	if (me->query_temp("weapon")&&objectp(tool=me->query_temp("weapon"))&&tool->is_SmithHammer()) allow=1;
	else if (me->query_temp("secondary_weapon")&&objectp(tool=me->query_temp("secondary_weapon"))&&tool->is_SmithHammer()) allow=1;
	if (!allow)
	{
		tell_object(me,RED"你要打铁，总不能用手打吧？至少找个铁锤来。\n"NOR);
		return 1;
	}
	for (int i=0;i<sizeof(inv);i++)
	{
		if (member_array(arg,inv[i]->parse_command_id_list())!=-1&&inv[i]->query("is_castmaterial"))
		{obj=inv[i];break;}
	}
	if (!obj)
	return notify_fail("炉子里没有你要锻打的"+arg+"。\n");
	if (time()<me->query_temp(Mark+"/hammer"))
	return notify_fail("你的体力还没有完全恢复。\n");
	message_vision(HIR+"$N"+HIR+"举起了"+tool->query("name")+HIR+"，一下一下地向"+obj->query("name")+HIR+"上锻击。\n"NOR,me);
	tool->worn(1+random(2));
	obj->add("hammered",1);
	me->add_temp(Mark+"/hammer_times",1);
	if (time()<me->query("pro_double_reward"))
	sk*=2;
	if (me->query_temp(Mark+"/hammer_times")%5==0&&me->query_temp(Mark+"/hammer_times")!=0&&(me->query_skill("smithing",1)<100||F_PRO->pro_class(me)=="smith"))
	me->improve_skill("smithing",sk);
	me->set_temp(Mark+"/hammer",time()+(obj->query("hammer_time")>2?obj->query("hammer_time"):2));
	if (obj->query("heat_finish")&&obj->query("hammered")>ob->query("product")["hammer_require"])
	finish(me,obj,ob->query("product"));
	return 1;
}
int do_defend()
{
	object me=this_player(),ob=this_object();
	int neili=50+random(200);
	message_vision("$N对着炉内灌注内力，以使炉火保证正常。\n",me);
	if (query_temp("phase_color")==CYN&&!ob->query("act"))
	{
		if (me->query("neili")>neili)
		{
			ob->delete_temp("abnormal");
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
	if (query_temp("phase_color")==MAG&&!ob->query("act"))
	ob->delete_temp("abnormal");
	ob->set("act",1);
	return 1;
}

int do_turnup()
{
	object me=this_player(),ob=this_object();
	message_vision("$N试着想把炉门开大了一些。\n",me);
	if (query_temp("phase_color")==HIR&&!ob->query("act"))
	ob->delete_temp("abnormal");
	ob->set("act",1);
	if (ob->query("door")>=9)
	return notify_fail("炉门已经被开到了最大。\n");
	ob->add("door",1);
	return 1;
}
int do_turndown()
{
	object me=this_player(),ob=this_object();
	message_vision("$N试着想把炉门关小了一些。\n",me);
	if (query_temp("phase_color")==HIW&&!ob->query("act"))
	ob->delete_temp("abnormal");
	ob->set("act",1);
	if (ob->query("door")<=1)
	return notify_fail("炉门已经被关到了最小。\n");
	ob->add("door",-1);
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
int do_place(string arg)//加药材进炉子
{
	object *inv,me=this_player(),ob=this_object(),obj;
	int i;
	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (!arg)
		return notify_fail("你要把什么放进"+ob->query("name")+"。\n");
	if (!obj=present(arg,me))
		return notify_fail("你身上并无"+arg+"这样东西。\n");
	if (!obj->is_castfuel())
	{
		if (!ob->query("operating"))
		{
			check_availability();
			return notify_fail("这具"+ob->query("name")+"没有被点着，没有火力让你锻造武器铠甲。\n");
		}
		if (ob->query("theMaterial")&&environment(ob->query("theMaterial"))==ob)
			return notify_fail(ob->query("name")+"已经放入锻造的材料了。\n");
		if (!obj->query("is_castmaterial"))
			return notify_fail(obj->query("name")+"不是锻造的材料。\n");
		if (sizeof(check_will(me))<1)
			return notify_fail("在开始锻造之前，你必须先设定锻造的目标(set smithing <目标>)。\n");
		if (obj->query("is_castmaterial")&&obj->query("type")!=check_will(me)["type"])
			return notify_fail(obj->query("name")+"和你锻造目标——"+HIW+me->query("env/smithing")+NOR+"的目标并不一致，你可以重新set或者换一块材料锻打。\n");
	}
	obj->move(ob);
	if (obj->query("is_castmaterial"))
	{
		ob->set("theMaterial",obj);
		ob->set("product",check_will(me));
		me->delete_temp(Mark);
		me->set_temp(Mark+"/ongoing",time()+Interval(me));
		call_out("check_material",Interval(me),me,obj);
	}
	message_vision(HIW"$N"+HIW+"将$n"+HIW+"小心地放入"+ob->query("name")+HIW+"里面。\n"NOR,me,obj);
	return 1;
}
int check_fuel(object ob)
{
	object *inv;
	int i;
	inv=all_inventory(ob);
	for (i=0;i<sizeof(inv);i++)
	if (inv[i]->is_castfuel())
	return 1;
	return 0;
}
int do_fire()
{
	object me=this_player(),ob=this_object(),obj;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (ob->query("operating"))
	{
		check_availability();
		tell_object(me,"这具"+ob->query("name")+"已经点着了。\n");
		return 1;
	}
	if (!check_fuel(ob))
	{
		tell_object(me,"这具"+ob->query("name")+"里没有什么燃料可以点着。\n");
		return 1;
	}
	if (!obj=present("huo zhezi",me))
	{
		tell_object(me,"你需要一个火折子(Huo zhezi)引燃炉火。\n");
		return 1;
	}
	destruct(obj);
	message_vision(HIR"$N"+HIR+"引燃了$n"+HIR+"中的炉火，炉温正不断升高……\n"NOR,me,ob);
	set("door",5);
	set("temperature",1);
	set("act",1);
	write("你把炉门打开到半开半闭的位置。\n");
	call_out("check_temperature",Interval(me),me);
	set("operating",1);
	tell_object(me,"炉火越来越旺了，你要检查炉温(process)，保持在一个合适的温度。\n");
	return 1;
}
int do_putout()
{
	object me=this_player(),ob=this_object();
	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (!ob->query("operating"))
		return notify_fail("你弄错了吧？"+ob->query("name")+"是熄灭的。\n");
	ob->delete("operating");
	remove_call_out("check_temperature");
	message_vision(WHT+"$N"+WHT+"认真地熄灭了$n"+WHT+"内的炉火。\n"NOR,me,ob);
	return 1;
}
int do_takeout(string arg)
{
	object me=this_player(),ob=this_object(),*inv,obj;
	string msg="";
	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
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
		{
			if (ob->query("operating"))
			message_vision("$N从$n中小心翼翼地取出了"+msg+"\n",me,ob);
			else
			message_vision("$N从$n取出了"+msg+"\n",me,ob);
		}
		else
		return notify_fail(ob->query("name")+"里什么也没有。\n");
	}
	else
	{
		if (ob->query("operating"))
		message_vision("$N从$n中小心翼翼地取出了"+obj->query("name")+"。\n",me,ob);
		else
		message_vision("$N从$n取出了"+obj->query("name")+"。\n",me,ob);
		obj->move(me);
	}
	return 1;
}

int do_put(string arg)
{
	string target, item;
	object obj, dest;
	object me = this_player();
	if(!arg) 
	return notify_fail("你要将什么东西放进哪里？\n");
	if( sscanf(arg, "%s in %s", item, target)!=2 )
	return notify_fail("你要给谁什么东西？\n");
	dest = present(target, me);
	if( !dest || living(dest) ) 
	dest = present(target, environment(me));
	if( !dest || living(dest) )
	return notify_fail("这里没有这样东西。\n");
	if(dest->is_SmithFurnace())
	{
		write(WHT"请用putin 命令将燃料或材料放入打铁炉。\n"NOR);
		return 1;
	}
}       