#include <ansi.h>
inherit ITEM;
int a,i;
int lvl,weapontype,armortype,gemlvl;
int obj_min,obj_max;
object setup_item(int success);
int do_open(string);
object obj;
string gemtype,msg;
void create()
{
        set_name("宝盒", ({"bao he", "he","box"}));
        set("long","一个外缠丝绸、包装华丽的锦盒，一看便知里面的东西价值不菲。\n");
        set("unit", "只");
        set("open_count", 1);
        set_weight( 2000);
        set("no_get", 1);
}

void init()
{
	object box = this_object();
	if (box->query("lvl"))
	{
		lvl = box->query("lvl");
	}
	add_action("do_open","open");
}

string gem_type()
{
	int i = random(20);
	if (i < 3) return "yan";
	else if (i < 6) return "mu";
	else if (i < 9) return "sui";
	else if (i < 12) return "jin";
	else if (i < 15) return "bing";
	else if (i < 16) return "gu";
	else if (i < 17) return "yu";
	else if (i < 18) return "jiao";
	return "jia";
}

int do_open(string arg)
{
	object material;
	object box, me;
	me = this_player();
	box = this_object();
	if (arg!="box" && arg!="bao he" && arg!="he") return notify_fail("你要打开什么？\n");
	if (!box->query("owner"))
		return notify_fail("你把吃奶的力气都使出来了，但就是打不开这个盒子！\n");
	if (me->query("id") != box->query("owner"))
	{
		write("你试着打开盒子，不料盒子里突然射出冷箭，你躲闪不及，中箭身亡。\n");
		me->receive_damage("qi", 0, "被宝盒里的冷箭射");
		me->die();
		destruct(box);
		return 1;
	}
	setup_item(lvl*random(500));
	weapontype=random(9)+1;
	armortype=random(9)+1;
	if (lvl<=7)
	{
		a=random(30);
		if (a<5)
		{
			obj = new("/obj/gem/weapon");
			obj->gen_weapon(weapontype,obj_min,obj_max);
			obj->set("forge/max",random(2)+1);
			obj->set("weapon/damage",2+lvl*random(35));   //最好武器为2o 240
		}
		else if (a>=5 && a<10)
		{
			obj = new("/obj/gem/armor");
			obj->gen_armor(armortype,obj_min,obj_max);
			obj->set("forge/max",random(2)+1);
		}
		else if (a==29)
		{
			obj = new("/obj/gem/armor");
			obj->gen_armor(armortype,obj_min,obj_max);
			obj->set("forge/max",2+random(2));	//可获得2o-3o装备
		}
		else if (a==28)
		{
			obj = new("/obj/gem/weapon");
			obj->gen_weapon(weapontype,obj_min,obj_max);
			obj->set("forge/max",2);
			obj->set("weapon/damage",210+random(20));
		}
		else
		{
			obj = new("/obj/gem/gem");  
			i = random(20);
			gemtype = gem_type();
			obj->set_level(obj_min,obj_max,gemtype);
		}
	}
	else if (lvl==8)
	{
		a=random(50);
		if (a<10)
		{
			obj = new("/obj/gem/weapon");
			obj->gen_weapon(weapontype,obj_min,obj_max);
			obj->set("forge/max",random(2)+1);
			obj->set("weapon/damage",4+lvl*random(33));   //最好武器为2o 260
		}
		else if (a>=10 && a<20)
		{
			obj = new("/obj/gem/armor");
			obj->gen_armor(armortype,obj_min,obj_max);
			obj->set("forge/max",random(2)+1);
		}
		else if (a==49)
		{
			obj = new("/obj/gem/armor");
			obj->gen_armor(armortype,obj_min,obj_max);
			obj->set("forge/max",3);                 //可获得3o装备
		}
		else if (a==48)
		{
			obj = new("/obj/gem/weapon");
			obj->gen_weapon(weapontype,obj_min,obj_max);
			obj->set("forge/max",2);
			obj->set("weapon/damage",230+random(20));
		}
		else
		{
			obj = new("/obj/gem/gem");
			gemtype = gem_type();
			if (a==47)
			{
				obj->set_level(9979,9979,gemtype);
			}
			else
			{
				obj->set_level(obj_min,obj_max,gemtype);
			}
		}
	}
	else if (lvl>=9)
	{
		a=random(1000);
		if (a<200)
		{
			obj = new("/obj/gem/weapon");
			obj->gen_weapon(weapontype,obj_min,obj_max);
			obj->set("forge/max",random(2)+1);
			obj->set("weapon/damage",3+lvl*random(34));   //最好武器为2o 300
		}
		else if (a>=200 && a<400)
		{
			obj = new("/obj/gem/armor");
			obj->gen_armor(armortype,obj_min,obj_max);
			obj->set("forge/max",random(2)+1);
		}
		else if (a>950 && a<999)
		{
			obj = new("/obj/gem/armor");
			obj->gen_armor(armortype,obj_min,obj_max);
			obj->set("forge/max",3+random(2));                 //可获得3o-4o装备
		}
		else if (a>800 && a<=950)
		{
			obj = new("/obj/gem/weapon");
			obj->gen_weapon(weapontype,obj_min,obj_max);
			obj->set("forge/max",2);
			obj->set("weapon/damage",270+random(20));           //获得2o 270+武器
		}
		else if (a==999)
		{
			obj = new("/obj/gem/weapon");
			obj->gen_weapon(weapontype,obj_min,obj_max);
			obj->set("forge/max",3);
			obj->set("weapon/damage",300+random(20));          //1/1000几率获得3o兵器
		}
		else
		{
			obj = new("/obj/gem/gem");
			gemtype = gem_type();
			if (a>=700 && a<800)
			{
				obj->set_level(9989,9989,gemtype);       //天级宝石
			}
			else
			{
				obj->set_level(obj_min,obj_max,gemtype);
			}
		}
	}
	write(HIM"你小心的打开宝盒，看到里面的"NOR+obj->name()+ HIM"不禁欣喜若狂！\n"NOR);
	obj->move(me);

	if (!obj->is_gem())
	{
		if (to_int(obj->query("level")) + to_int(obj->query("forge/max")) > 7)
		{
			msg = "";
			if (to_int(obj->query("forge/max")) > 1)
			{
				msg = CHINESE_D->chinese_number(to_int(obj->query("forge/max"))) + "孔";
				CHANNEL_D->do_channel(this_object(),"rumor","听说"+this_player()->query("name")+"开宝盒得到一"
         						+obj->query("unit")+msg+obj->name()+"啦。");
			}
		}
	}
	else
	{
		CHANNEL_D->do_channel(this_object(),"rumor",this_player()->query("name")+"开宝盒得到一"
       				+obj->query("unit")+obj->name()+"。");
	}
	if (!obj->is_gem())
	{
		msg = this_player()->name()+"在「绿柳山庄」中得到一"+obj->query("unit")+obj->name()
					   +"[等级："+obj->query("level")+"，孔数："+obj->query("forge/max")+"]。";
	}
	else
	{
		msg = this_player()->name()+"在「绿柳山庄」中得到一"+obj->query("unit")+obj->name()
					   +"[等级："+obj->query("level")+"]。";
	}
	MONITOR_D->report_system_msg(msg);
			
	if (lvl>=7 && random(10000)>9900)
	{
		material=new("/obj/remedy/drug/wuchang-material");
		if (objectp(material))
		{
			material->set("owner", this_player()->query("id"));
			material->move(this_player());
			tell_object(this_player(), "你翻了翻盒子底，在夹层中发现了一份珍贵的药材，真是意外之喜。\n");
		}
	}
	destruct(box);
	return 1;
}

object setup_item(int success)
{
	if(success>40+random(3000))      {obj_min=8500;obj_max=9999;} 
	else if(success>35+random(2000)) {obj_min=7300;obj_max=9700;} 
	else if(success>30+random(1000)) {obj_min=6100;obj_max=9300;} 
	else if(success>25+random(500))  {obj_min=4500;obj_max=8500;} 
	else if(success>20+random(200))  {obj_min=2500;obj_max=8500;}	
	else if(success>15+random(100))  {obj_min=0;   obj_max=8500;}	
	else                             {obj_min=0;   obj_max=6100;} 

}