//edit by feng
//2008.12.8
//宠物系统

/*
1.吸收伤害  xishou
2.加速生命内力恢复速度 huifu
3.增加角色物力攻击 gongji
4.增加角色物力防御 fangyu
5.增加角色百分比反射伤害 fanshang
6.让角色可开传送门 chuansong
7.给主人增加气血  qixue
9.给主人增加精力  jinli
9.给主人增加精气 jinqi
10.给主人增加内力 neil

宠物可接受物品(吃的喝的)
宠物消失，去掉所有加成。
*/
#include <ansi.h>
#include <localtime.h>

inherit NPC;
inherit F_SAVE;

#define USER_ENERGY_D "/adm/daemons/energy.c" //属性重算

//宠物标志
int is_pet() { return 1; }

void jiacheng(object me,object pet);
int index_pet(int index,object pet);
void pet_heart();

//函数：查询存盘路径
string query_save_file()
{
	object pet = this_object();
	string dir;

	if(!dir = pet->query("owner_id")) return "";
	return sprintf("/data/pet/%c/%c/%s_%s.pet",dir[0],dir[1],dir,pet->query("id"));
}

//取消所有加成
void remove_prop(object me)
{
	USER_ENERGY_D->count_hp(me);        //气血
	USER_ENERGY_D->count_jingli(me);    //精力
	USER_ENERGY_D->count_jing(me);      //精气
	USER_ENERGY_D->count_ap(me);        //魔法攻击
	USER_ENERGY_D->count_dp(me);        //物理防御
	USER_ENERGY_D->count_pp(me);        //魔法防御
	USER_ENERGY_D->count_cp(me);        //物理攻击
	USER_ENERGY_D->count_neili(me);     //内力
}

// 函数：构造处理
void create()
{
	object owner;
	string dir;

	set_name("宠物", ({ "pet" }) );
	set("long","一只可爱的小宠物。\n");
	set("race", "野兽");
	
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) ); 
	set("verbs", ({ "bite", "claw" }) ); 

	setup();

	//删除前任主人的存盘
	dir = query("old_owner_id");
	if(dir != query("owner_id"))
	{
		if(dir != 0) rm(sprintf("/data/pet/%c/%c/%s_%s.pet",dir[0],dir[1],dir,query("id")));
		set("old_owner_id",query("owner_id"));
	}
	//设置使用者
	if(query("owner_id") && (owner = find_player(query("owner_id")))) set("owner",owner);
//        pet_heart();
}

//函数：给主人添加命令
void init()
{
	object me = this_player();
	if(me->query("id") == this_object()->query("owner_id"))
	{
		//宠物属性查询
		add_action("do_hp",  "hp");
		//让角色可开传送门
		if(this_object()->query("chuansong"))
		{
			add_action("do_jilu", "jilu");
			add_action("do_trans", "trans");
		}
	}
}

//宠物属性查询
int do_hp(string arg)
{
	object me,pet;
	string str;
	me = this_player();
	pet = this_object();
	
	if(arg != "pet" ) return 0;
	
	if(pet->query("chuansong")) str = "是";
	else str = "否";
	
	tell_object(me,HIC"≡"HIY"───────────────────────────────"HIC"≡\n"NOR);
	tell_object(me,sprintf("【伤害吸收】 百分之%d      【恢复气血】 %d点\n",index_pet(pet->query("xishou"),pet),index_pet(pet->query("huifu"),pet) ));
	tell_object(me,sprintf("【攻击增强】 %d点          【防御增强】 %d点\n",index_pet(pet->query("gongji"),pet),index_pet(pet->query("fangyu"),pet) ));
	tell_object(me,sprintf("【伤害反射】 百分之%d      【可开传送】 %s\n",index_pet(pet->query("fanshang"),pet),str ));
	tell_object(me,sprintf("【气血增强】 %d点          【精力增强】 %d点\n",index_pet(pet->query("qixue"),pet),index_pet(pet->query("jinli"),pet) ));
	tell_object(me,sprintf("【精气增强】 %d点          【内力增强】 %d点\n",index_pet(pet->query("jinqi"),pet),index_pet(pet->query("neil"),pet) ));
	tell_object(me,sprintf("【 食  物 】 %d点          【 饮  水 】 %d点\n",pet->query("food"),pet->query("water")));
	tell_object(me,HIC"≡"HIY"─────────────────────────号令天下──"HIC"≡\n"NOR);
	return 1;
}

int do_jilu(string arg)
{
	object pet,me,room;
	int size;
	
	pet = this_object();
	me = this_player();
	
	if(!room = environment(pet))
	{
		tell_object(me,"你的宠物，无法为你打开传送门。\n");
		return 1;
	}
	
	if(!arg)
	{
		tell_object(me,"请输入你要记录这个房间的名称。\n");
		return 1;
	}
	size = sizeof(me->query_temp("congwu/map"));
	/*
	if(!me->query("jym_level/vip") && size > 1)
	{
		tell_object(me,"抱歉您不是贵宾，无法记录那么多点。\n");
		return 1;
	}
	*/
	if(size >= 20)
	{
		tell_object(me,"您记录的传送点太多了。\n");
		return 1;
	}
	
	me->set_temp(sprintf("congwu/map/%s",arg),room);
	tell_object(me,sprintf(HIY"传送记录成功，您输入：trans %s 即可回来。\n"NOR,arg));
	return 1;
}

//角色可开传送
int do_trans(string arg)
{
	object pet,me,room,path;

	pet = this_object();
	me = this_player();
	
	if(!room = environment(pet) || !arg) return 0;

	if(path = me->query_temp(sprintf("congwu/map/%s",arg)))
	{
		tell_object(me,"你的宠物纵身往空中一划，一道弧形的门出现了，你往门里走了进去。\n");
		me->move(path);
		return 1;
	}
	else
	{
		tell_object(me,"你在那里没有开传送门。\n");
		return 1;
	}
	return 0;
}

//函数：心跳循环
void pet_heart()
{
	object here,pet,owner,room;
	int fanying;
	mixed loctime;

	pet = this_object();
	here = environment(pet);
	
	//寿命不足
	if(pet->query("shouming") < 1) return;
	//寿命计算
	loctime = localtime(time());
	if(loctime[LT_MDAY] != pet->query("day_time"))
	{
		pet->add("shouming",-1);
		pet->set("day_time",loctime[LT_MDAY]);
	}

	if((!owner = pet->query("owner")) || (!room = environment(owner)))
	{
		if(owner) remove_prop(owner);
		pet->save();
		destruct(pet);
		return;
	}

	if(here != room)
	{
		pet->move(room);
		tell_object(owner,sprintf("%s蹦蹦跳跳的跑了过来。\n",pet->query("name")));
	}

	pet->set_leader(owner);
	owner->set_temp("pet",pet);
	
	//宠物加成
	jiacheng(owner,pet);
	
	if(!fanying = pet->query("fanying")) fanying = 100;

	call_out("pet_heart",fanying);
}

//函数：宠物死亡处理
void die()
{
	object pet,owner;
	int rand;

	pet = this_object();
	pet->add("shouming",-(1+random(5))); //减寿命

	rand = random(100);
	if(rand < 10) command("say 我靠，XP不发威，你当是DOS啊。十八年后又是一条好汉。\n");
	else if(rand < 20) command("say 哎呀！吃亏啦。\n");
	else if(rand < 30) command("say 头好痛，头好痛。\n");
	else if(rand < 40) command("say 主人替我报仇啊，我去了。\n");
	else if(rand < 50) command("say 我顶你个肺。\n");
	else if(rand < 60) command("say 珍惜生命，远离《江湖》！\n");
	else if(rand < 70) command("say 不是我不小心，而是我故意的！\n");
	else if(rand < 80) command("say 一觉醒来，天都黑了。\n");
	else if(rand < 90) command("say 秃驴，敢跟我抢师太?\n");
	else if(rand < 100) command("say 不要眼睁睁看着我死，请闭上眼。\n");
	if(owner = pet->query("owner")) remove_prop(owner);
	::die();
}

void jiacheng(object me,object pet)
{
	int index;

	//伤害吸收
	if(index = index_pet(pet->query("xishou"),pet))
	{
		if(me->query_temp("congwu/xishou") != index) me->set_temp("congwu/xishou",index);
	}
	//生命加速恢复
	if((index = index_pet(pet->query("huifu"),pet)) && !me->is_fighting())
	{
		//精力
		if(me->query("jingli") < me->query_max_jingli())
		{
			me->add("jingli",index);
			if(me->query("jingli") > me->query_max_jingli()) me->set("jingli",me->query_max_jingli());
		}
		//精神
		if(me->query("eff_jing") < me->query_max_jing())
		{
			me->add("eff_jing",index);
			if(me->query("eff_jing") > me->query_max_jing()) me->set("eff_jing",me->query_max_jing());
		}
		if(me->query("jing") < me->query_max_jing())
		{
			me->add("jing",index);
			if(me->query("jing") > me->query_max_jing()) me->set("jing",me->query_max_jing());
		}
		//内力
		if(me->query("neili") < me->query_max_neili())
		{
			me->add("neili",index);
			if(me->query("neili") > me->query_max_neili()) me->set("neili",me->query_max_neili());
		}
		//气血
		if(me->query("eff_qi") < me->query_max_hp())
		{
			me->add("eff_qi",index);
			if(me->query("eff_qi") > me->query_max_hp()) me->set("eff_qi",me->query_max_hp());
		}
		if(me->query("qi") < me->query_max_hp())
		{
			me->add("qi",index);
			if(me->query("qi") > me->query_max_hp()) me->set("qi",me->query_max_hp());
		}
	}
	//增加角色物力攻击
	if(index = index_pet(pet->query("gongji"),pet))
	{
		if(pet->query_temp("owner_add_ap") != index)
		{
			pet->set_temp("owner_add_ap",index);
			USER_ENERGY_D->count_ap(me);//重算攻击力
			me->set_temp_ap("equip",me->query_equip_ap()+index);
		}
	}
	//增加角色防御力
	if(index = index_pet(pet->query("fangyu"),pet))
	{
		if(pet->query_temp("owner_add_pp") != index)
		{
			pet->set_temp("owner_add_pp",index);
			USER_ENERGY_D->count_pp(me);//重算防御力
			me->set_temp_pp("equip",me->query_equip_pp()+index);
		}
	}
	//给主人增加气血
	if(index = index_pet(pet->query("qixue"),pet))
	{
		if(pet->query_temp("owner_add_hp") != index)
		{
			pet->set_temp("owner_add_hp",index);
			USER_ENERGY_D->count_hp(me);//重算气血
			me->set_temp_hp("equip",me->query_temp_hp()+index);
		}
	}
	//给主人增加精力
	if(index = index_pet(pet->query("jinli"),pet))
	{
		if(pet->query_temp("owner_add_jingli") != index)
		{
			pet->set_temp("owner_add_jingli",index);
			USER_ENERGY_D->count_jingli(me);//重算精力
			me->set_temp_jl("equip",me->query_temp_jl()+index);
		}
	}
	//给主人增加精气
	if(index = index_pet(pet->query("jinqi"),pet))
	{
		if(pet->query_temp("owner_add_jingqi") != index)
		{
			pet->set_temp("owner_add_jingqi",index);
			USER_ENERGY_D->count_jing(me);//重算精力
			me->set_temp_j("equip",me->query_temp_j()+index);
		}
	}
	//给主人增加内力
	if(index = index_pet(pet->query("neil"),pet))
	{
		if(pet->query_temp("owner_add_neili") != index)
		{
			pet->set_temp("owner_add_neili",index);
			USER_ENERGY_D->count_neili(me);//重算精力
			me->set_temp_nl("equip",me->query_temp_nl()+index);
		}
	}
	//增加角色百分比反射伤害
	if(index = index_pet(pet->query("fanshang"),pet))
	{
		if(me->query_temp("congwu/fanshang") != index) me->set_temp("congwu/fanshang",index);
	}
}

//食物饮水比例
int index_pet(int index,object pet)
{
	int food,water;

	food = pet->query("food");
	water = pet->query("water");
	
	if(food <= 0 || water <= 0) return 0;
	
	if(food > 100) food = 100;
	if(water > 100) water = 100;
	
	index =  (index*(food/2))/50;
	index += (index*(water/2))/50;

	if(index > 0) return index;
	return 0;
}

//接受吃的东西
int accept_object(object who, object ob) 
{
	object pet;
	int food,water;
	
	pet = this_object();
	
	if(who != pet->query("owner"))
	{
		tell_object(who,sprintf("%s抬起头来，看了看你。\n",pet->query("name")));
		return 0;
	}
	
	if((!food = ob->query("food_supply")) && (!water = ob->query("liquid/remaining")))
	{
		tell_object(who,sprintf("%s瞪大眼睛，把玩了一下%s，然后还给了你。\n",pet->query("name"),ob->query("name")));
		return 0;
	}
	pet->add("food",food);
	pet->add("water",water);
	command("thank");
	destruct(ob);
	return 1;
}