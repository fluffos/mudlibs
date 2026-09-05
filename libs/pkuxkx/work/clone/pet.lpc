//pet
//Made by jason@indeed for vworld
//2001.3.6

inherit NPC;
inherit F_SAVE;

#define DEBUG "jason"

#include <ansi.h>

string *skills=({"zhili","tili","fight","liyi"});
int do_train();
int do_attack(string);
int do_play(string);
int do_feed(string);
int do_refresh();
int do_action();
int do_say();
int update_age();
int get_select(string,object);
void improve(string,int);
void level_up();

string query_save_file()
{
	if(stringp(query("owner_id")))
		return "/data/pet/"+(query("owner_id"))[0..0]+"/"+query("owner_id");
	else
		return "";
}

void create()
{
	if(!restore())
	{
		set_name("快乐小精灵",({"little pet","pet"}));
		set("long",
		"这是一只可爱的小宠物。\n");
		set("weight",5000);
		set("unit","只");
		set("no_sell",1);
		set("gender","雄性");
		set("class","noneclass");
		set("pet_ob",1);
		set("owner_id",DEBUG);
		set("age",1);
		set("mud_age",86400);
		set("go_desc/out_desc","飞走了");
		set("go_desc/in_desc","飞过来");
		set("voice",HIW"呜呜呜～～～拉拉拉～～～"NOR);
		setup();
	}
	
}

//根据玩家先天属性初始化pet
void init_pet(object me)
{
	object ob=this_object();
	mapping my=me->query_entire_status();
	mapping pet=ob->query_entire_satus();
	if(query("have_init")) return;
	set_attrib("str",me->query_attrib("str")/2);
	set_attrib("per",me->query_attrib("per")/2);
	set_attrib("int",me->query_attrib("int")/2);
	set_attrib("sta",me->query_attrib("sta")/2);
	set_attrib("wil",me->query_attrib("wil")/2);
	set_attrib("tem",me->query_attrib("tem")/2);
	set_status("max_qi",query_status("str")*10);
	set_status("max_jing",query_status("int")*10);
	set_status("max_food",query_status("str")*10+query_status("sta")*10);
	set_status("max_water",query_status("str")*10+query_status("sta")*10);
	ob->set("owner_id",me->query("id"));
	ob->set("gender",random(2)>0?"雄性":"雌性");
	ob->set("have_init",1);//只能初始化一次。
	me->set("have_pet",1);
	me->save();
	save();
}

void setup_pet()//在login里调用。寻找主人。
{
	object owner;
	if(!objectp(owner=find_player(query("owner_id"))))
	{
		destruct(this_object());
		return;
	}
	set_leader(owner);
	
}

void init()
{
	object ppl=this_player();
	if(query("owner_id")==ppl->query("id"))
	{
		set_heart_beat(1);
		add_action("do_train","train");
		add_action("do_attack","attack");
		add_action("do_play","play");
		add_action("do_feed","feed");
		set_leader(ppl);
		setup();
	}
}

int do_fresh()//在心跳中调用，负责更新身体状况。
{
	object owner;
	if(!objectp(owner=find_player(query("owner_id"))))
	CHANNEL_D->do_channeld("pet",this_object(),"主人呀，你在哪里？？？");
	do_action();//作些有趣的事情
	do_say();// 说些有趣的话
	update_age();
	level_up();
	if(random(5)==3)
	{
		add_status("water",-1);
		add_status("food",-1);
		if(query_status("water")<0) 
		{
			if(!owner) command("cry");
			else CHANNEL_D->do_channel(this_object(),"pet","sigh "+
			owner->query("id"),1);
			set_status("water",0);
		}
		if(query_status("food")<0) 
		{
			if(!owner) command("cry");
			else CHANNEL_D->do_channel(this_object(),"pet","beg "+
			owner->query("id"),1);
			set_status("food",0);
		}
		if(query_status("eff_qi")<query_status("max_qi"))
		{
			add_status("eff_qi",1);
		}
		if(query_status("qi")<query_status("eff_qi"))
		{
				add_status("qi",1);
		}
	}
	continue_action();
	set_heart_beat(1);
}

int update_age()
{
	add("mud_age",1);
	if(query("mud_age")%86400==0)
	{
		message("vision",HIY+name()+"又长大一岁了，有没有人祝它生日快乐呀？\n"NOR,environment());
		//birthday();//可能的话，画个生日蛋糕，:)
		add("age",1);
		if(!random(5))
		{
			add_status("str",1);
			add_status("sta",1);
			add_status("sta",1);
			add_status("int",1);
			add_status("wil",1);
			add_status("tem",1);
			add_status("per",1);
			setup();
		}
		if(query("age")>10)//10岁以后开始衰老
		{
			add_status("str",-1);
			add_status("sta",-1);
			add_status("sta",-1);
			add_status("int",-1);
			add_status("wil",-1);
			add_status("tem",-1);
			add_status("per",-1);
			setup();
		}
		if(query("age")>20&&random(5)==2)
		{
			message("vision",name()+"觉得好累好累，它迈不动脚步了，"+
			"它只觉得两眼发花，恍恍忽忽间，它觉得自己到了天堂。。。\n",
			environment());
			CHANNEL_D->do_channel(this_object(),"pet",name()+"年老体衰，\n"+
			"于"+CHINESE_D->chinese_date(time())+"\nbccc"+"寿终正寝"+
			"永别尘世。。。\n");
			seteuid(ROOT_UID);
			rm(query_save_file()+".o");
			destruct(this_object());
		}
	}
	return 1;
}

int do_feed(string arg)
{
	object ppl=this_player();
	object ob=this_object();
	int food,water;
	int cost;
	food=query_status("food");
	water=query_status("water");
	cost=10*(max_water_capacity()-water)+20*(max_food_capacity()-food);
	if(cost<=0) return notify_fail("你的宠物不饿不渴。\n");
	if(ppl->query("money")<cost)
	{
		write("呜呜，你没有钱给"+name()+"买东西吃了～～～\n");
		return 1;
	}
	write("你买了好东东给"+name()+"吃，恩，我们动物保护协会精神上奖励你！\n");
	set_status("food",max_food_capacity());
	set_status("water",max_water_capacity());
	REWARD_D->give_reward(ppl,"money",-cost,query("class"),1);
	save();
	return 1;
}

int do_attack(string arg)
{
	int lvl,lvl2,damage;
	object ppl=this_player();
	object ob=this_object(),target;
	if(ppl->query("id")!=query("owner_id"))
		return notify_fail("搞笑，这又不是你的宠物，你指挥什么？\n");
	if(!arg||arg=="") return notify_fail("你想让你的宠物攻击谁？\n");
	if(!objectp(target=present(arg,environment())))
		return notify_fail("你想要攻击的人不在这里！\n");
	if(environment()->query("no_fight"))
		return notify_fail("这里禁止战斗!\n");
	if(ob->is_busy())
	{
		return notify_fail("你的宠物正忙着那！\n");
	}
	if(random(ob->query("qinmidu"))<5)
	{
		return notify_fail("你的宠物好像心情不是很好，不愿意为你卖命哦！\n");
	}
	message_vision(HIY"$N拍了拍$n的脑袋：乖乖，咬他！\n"+
	HIR"$n对着"+target->name()+"直扑过去！\n"NOR,ppl,ob);
	if(!lvl=query("level/fight")) lvl=0;
	lvl2=target->query("exp/crime");
	damage=(lvl-lvl2)*10;
	if(damage<0) 
	{
		ob->receive_damage("qi",damage,target);
		target->receive_damage("jing",damage,ob);
		damage=0;
	}
	
	target->receive_damage("qi",damage,ob);
	target->receive_damage("jing",damage,ob);
	target->fight_ob(ppl);
	if(damage>0)
		improve("fight",3+random(damage));
	ob->start_busy(3);
	return 1;
}

int do_action()
{
	return 1;
}

int do_say()
{
	if(random(20)==15)
		message_vision("$N "+query("voice")+"地叫了几声。\n",this_object());
	return 1;
}

int do_train()
{
	object ppl=this_player(),ob=this_object();
	if(ob->query_status("jing")<20) 
		return notify_fail("你的宠物太累了，不要再逼它了。\n");
	write(
	"你要训练你的宠物的哪个科目？\n"+
	"1)智力  2)体力   3)礼仪  4)格斗\n"
	);
	input_to("get_select",ppl);
	return 1;
}

int get_select(string arg,object ppl)
{
	if(!arg||arg=="") return 0;
	switch(arg)
	{
		case "1":write("你的宠物接受智力训练\n");
		improve("zhili",1+random(2));
		receive_damage("jing",10);break;
		case "2":write("你的宠物接受体力训练\n");
		improve("tili",1+random(2));
		receive_damage("jing",10);break;
		case "3":write("你的宠物接受礼仪训练\n");
		improve("liyi",1+random(2));
		receive_damage("jing",10);break;
		case "4":write("你的宠物接受格斗训练\n");
		improve("fight",1+random(2));
		receive_damage("jing",10);break;
		default:break;
	}
	if(!random(5))
		add("qinmidu",-1);
	save();
	return 1;
}

void improve(string arg,int point)
{
	if(member_array(arg,skills)==-1) return 0;
	add("skills/"+arg,point);
	save();
	return;
}

void level_up()
{
	for(int i=0;i<sizeof(skills);i++)
	{
		if(query("skills/"+skills[i])>=100*(1+query("level/"+skills[i])))
		{
			CHANNEL_D->do_channel(this_object(),"pet",name()+"升级了！！\n");
			add("level/"+skills[i],1);
			add("skills/"+skills[i],-100*query("level/"+skills[i]));
		}
	}
	return;
}

void unconcious()
{
	die();
}

void die()
{
	message("vision",HIW+name()+"觉得很不舒服，一头倒在地上不动了。"+
	"一个大天使飞了过来，怜惜的ｐａｔ了它一下，把它带走了。\n"NOR,environment());
	destruct(this_object());
}

int do_play(string arg)
{
	if(!arg||arg==""||arg!=query("id"))
		return 0;
	if(query_status("qi")<20||query_status("jing")<20)
	{
		write("你的宠物很累了。\n");
		return 1;
	}
	write("你的宠物玩的很开心！\n");
	add("qinmidu",1);
	receive_damage("jing",10+random(10));
	receive_damage("qi",10+random(10));
	save();
	return 1;
}









