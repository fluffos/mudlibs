// by picewolf for wananta  2009-5-20
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
        set("long",
"这是一个古香古色的盒子，一看便知里面的东西价值不菲。\n");
        set("unit", "只");
        set("open_count", 1);
        set_weight( 2000);
        set("no_get", 1);
}

void init()
{
		if (this_player()->query_temp("wananta/lvl"))
		{
			lvl=this_player()->query_temp("wananta/lvl");
		}
        add_action("do_open","open");
}

int do_open(string arg)
{
	object material;
		if (arg!="box" && arg!="bao he" && arg!="he") return 0;
		if (!this_player()->query_temp("wananta/lvl"))
		{
			add("open_count", -1);
			write("你试着打开盒子，不料盒子里突然射出冷箭，你躲闪不及，命中身亡。\n");
            this_player()->receive_damage("qi", 0, "被宝盒里的冷箭射");
			this_player()->die();
			destruct(this_object());
			return 1;
		}
		if (arg=="box" || arg=="bao he" || arg=="he")
		{


        if (query("open_count") > 0)
        {
			this_player()->delete_temp("wananta/lvl");

			setup_item(lvl*random(500));
			add("open_count", -1);
			weapontype=random(9)+1;
			armortype=random(9)+1;
			if (lvl==4)
			{
				a=random(30);
				if (a<3)
				{
					obj = new("/obj/gem/weapon");
					obj->gen_weapon(weapontype,obj_min,obj_max);
					obj->set("forge/max",random(2)+1);
					obj->set("weapon/damage",lvl*random(45));   //第四级获得最好武器为20 180
				}

				if (a>=3 && a<=7)
				{
					obj = new("/obj/gem/armor");
					obj->set("type",armortype);
					obj->gen_armor(armortype,obj_min,obj_max);
					obj->set("forge/max",random(2)+1);
				}
				if(a>7 && a<=10)
				{
					obj = new("/obj/gem/gem");
                	//种类不太重要，直接设定
                		i = random(20);
	if (i < 3) gemtype = "yan";
	else if (i < 6) gemtype = "mu";
	else if (i < 9) gemtype = "sui";
	else if (i < 12) gemtype = "jin";
	else if (i < 15) gemtype = "bing";
	else if (i < 16) gemtype = "gu";
	else if (i < 17) gemtype = "yu";
	else if (i < 18) gemtype = "jiao";
	else gemtype = "jia";
					obj->set_level(obj_min,obj_max,gemtype);
				}
				if (a>10 && a<=20)
				{
					obj=new("/d/wananta/npc/obj/kulou");
				}
				else
				{
					obj=new("/d/wananta/npc/obj/wazi");
				}
			}
			if (lvl==5)
			{
				a=random(30);
				if (a<5)
				{
					obj = new("/obj/gem/weapon");
					obj->gen_weapon(weapontype,obj_min,obj_max);
					obj->set("forge/max",random(2)+1);
					obj->set("weapon/damage",lvl*random(45));   //第5级获得最好武器为20 225
				}

				if (a>=5 && a<10)
				{
					obj = new("/obj/gem/armor");
					obj->gen_armor(armortype,obj_min,obj_max);
					obj->set("forge/max",random(2)+1);
				}
				if (a==29)
				{
					obj = new("/obj/gem/armor");
					obj->gen_armor(armortype,obj_min,obj_max);
					obj->set("forge/max",2);
				}
				if (a==28)
				{
					obj = new("/obj/gem/weapon");
					obj->gen_weapon(weapontype,obj_min,obj_max);
					obj->set("forge/max",2);
					obj->set("weapon/damage",200+random(20));
				}
				if (a>=10 && a<=15)
				{
					obj=new("/d/wananta/npc/obj/wazi");
				}
				if (a>15 && a<=23)
				{
					obj=new("/d/wananta/npc/obj/kulou");
				}
				else
				{
					obj = new("/obj/gem/gem");     //种类不太重要，直接设定
                	i = random(20);
	if (i < 3) gemtype = "yan";
	else if (i < 6) gemtype = "mu";
	else if (i < 9) gemtype = "sui";
	else if (i < 12) gemtype = "jin";
	else if (i < 15) gemtype = "bing";
	else if (i < 16) gemtype = "gu";
	else if (i < 17) gemtype = "yu";
	else if (i < 18) gemtype = "jiao";
	else gemtype = "jia";
					obj->set_level(obj_min,obj_max,gemtype);
				}

			}
			if (lvl==6)
			{
				a=random(50);
				if (a<10)
				{
					obj = new("/obj/gem/weapon");
					obj->gen_weapon(weapontype,obj_min,obj_max);
					obj->set("forge/max",random(2)+1);
					obj->set("weapon/damage",lvl*random(40));   //第6级获得最好武器为20 240
				}

				if (a>=10 && a<20)
				{
					obj = new("/obj/gem/armor");
					obj->gen_armor(armortype,obj_min,obj_max);
					obj->set("forge/max",random(2)+1);
				}
				if (a>=20 && a<=27)
				{
					obj=new("/d/wananta/npc/obj/wazi");
				}

				if (a>27 && a<=33)
				{
					obj=new("/d/wananta/npc/obj/kulou");
				}
				if (a==49)
				{
					obj = new("/obj/gem/armor");
					obj->gen_armor(armortype,obj_min,obj_max);
					obj->set("forge/max",3);                 //6层可获得3o装备
				}
				if (a==48)
				{
					obj = new("/obj/gem/weapon");
					obj->gen_weapon(weapontype,obj_min,obj_max);
					obj->set("forge/max",2);
					obj->set("weapon/damage",240+random(20));
				}
				else
				{
					obj = new("/obj/gem/gem");
                	//种类不太重要，直接设定
                	i = random(20);
	if (i < 3) gemtype = "yan";
	else if (i < 6) gemtype = "mu";
	else if (i < 9) gemtype = "sui";
	else if (i < 12) gemtype = "jin";
	else if (i < 15) gemtype = "bing";
	else if (i < 16) gemtype = "gu";
	else if (i < 17) gemtype = "yu";
	else if (i < 18) gemtype = "jiao";
	else gemtype = "jia";
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
			if (lvl==7)
			{
				a=random(1000);
				if (a<200)
				{
					obj = new("/obj/gem/weapon");
					obj->gen_weapon(weapontype,obj_min,obj_max);
					obj->set("forge/max",random(2)+1);
					obj->set("weapon/damage",lvl*random(35));   //第6级获得最好武器为20 245
				}

				if (a>=200 && a<400)
				{
					obj = new("/obj/gem/armor");
					obj->gen_armor(armortype,obj_min,obj_max);
					obj->set("forge/max",random(2)+1);
				}
				if (a>950 && a<999)
				{
					obj = new("/obj/gem/armor");
					obj->gen_armor(armortype,obj_min,obj_max);
					obj->set("forge/max",3);                 //7层可获得3o装备
				}
				if (a>800 && a<=950)
				{
					obj = new("/obj/gem/weapon");
					obj->gen_weapon(weapontype,obj_min,obj_max);
					obj->set("forge/max",2);
					obj->set("weapon/damage",260+random(20));           //获得2o 260+武器
				}
				if (a==999)
				{
					obj = new("/obj/gem/weapon");
					obj->gen_weapon(weapontype,obj_min,obj_max);
					obj->set("forge/max",3);
					obj->set("weapon/damage",260+random(20));          //1/1000几率获得3o兵器
				}
				else
				{
					obj = new("/obj/gem/gem");
                	//种类不太重要，直接设定
                	i = random(20);
	if (i < 3) gemtype = "yan";
	else if (i < 6) gemtype = "mu";
	else if (i < 9) gemtype = "sui";
	else if (i < 12) gemtype = "jin";
	else if (i < 15) gemtype = "bing";
	else if (i < 16) gemtype = "gu";
	else if (i < 17) gemtype = "yu";
	else if (i < 18) gemtype = "jiao";
	else gemtype = "jia";
					if (a>=700 && a<800)
					{
						obj->set_level(9989,9989,gemtype);       //获得天圣级别宝石
					}
					else
					{
					obj->set_level(obj_min,obj_max,gemtype);
					}
				}
			}
			write(HIM"你小心的打开宝盒，看到里面的"NOR+obj->name()+ HIM"不禁欣喜若狂！\n"NOR);
			obj->move(this_player());


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
				msg = this_player()->name()+"在万安塔任务中得到一"+obj->query("unit")+obj->name()
  					   +"[等级："+obj->query("level")+"，孔数："+obj->query("forge/max")+"]。";
			}
			if (obj->is_gem())
			{
				msg = this_player()->name()+"在万安塔任务中得到一"+obj->query("unit")+obj->name()
  					   +"[等级："+obj->query("level")+"]。";
			}
			MONITOR_D->report_system_msg(msg);
			
			if (lvl==7 && random(10000)>9900)
			{
				material=new("/obj/remedy/drug/wuchang-material");
				if (objectp(material))
				{
					material->set("owner", this_player()->query("id"));
					material->move(this_player());
					tell_object(this_player(), "你翻了翻盒子底，在夹层中发现了一份珍贵的药材，真是意外之喜。\n");
				}
			}
			
			destruct(this_object());


		}
        else return notify_fail("宝盒已经被打开了。\n");
        return 1;
		}else return notify_fail("你要打开什么？\n");
}

object setup_item(int success)
{
/************************************************************************************************
1.drop_odds参数可以省略
  缺省情况下drop几率:80% misc, 6% weapon, 6% armor, 1.5% special, 2.5% ring, 4% gems, 0% unique(根据实际情况调整)
  //普通情况下不会出现unique物品，一般boss级别npc可以设置此参数调整drop几率
2.weapon,armor,ring的不同类别稀有度在各自的文件中定义了，如果不太好控制可以考虑采取和gems级别限制的相同方法
3.npc设置参数限制gems的最高级别,和非缺省情况下的drop几率
  set("item_drop_odds", ({500, 150, 150, 100, 50, 45, 5, }));
  总和1000。分别代表7种不同类物品的drop几率
  obj_min - obj_max
  0    - 5000  1级
	5000 - 8334  2级
	8335 - 9444  3级
	9445 - 9814  4级
	9815 - 9939  5级
	9940 - 9979  6级
	9980 - 9994  7级
	9995 - 10000 8级
  具体请看/clone/gem/gem.c  set_level()函数
4.每位npc具体能够drop多少Item, 在各自的文件中自己定义，需要drop多个item的情况，多次调用本函数即可
4.misc包括普通场景中能够得到的各种物品，也包括部分特殊药品
************************************************************************************************/

	//其实n可以直接设定为7, 这个看以后是否增加新的物品类别而定，这样写只是为了减少以后的劳动量尽量避免出错
	//如果增加新的类别，下面的if ....else if还是需要手动修改


	int judge=0;

	if(success>40+random(3000))      {obj_min=8500;obj_max=9999;judge=7;} //6-8
	else if(success>35+random(2000)) {obj_min=7300;obj_max=9700;judge=6;} //5-7
	else if(success>30+random(1000)) {obj_min=6100;obj_max=9300;judge=5;} //4-6
	else if(success>25+random(500))  {obj_min=4500;obj_max=8500;judge=4;} //3-5
	else if(success>20+random(200))  {obj_min=2500;obj_max=8500;judge=3;}	//2-5
	else if(success>15+random(100))  {obj_min=0;   obj_max=8500;judge=2;}	//1-5
  else                             {obj_min=0;   obj_max=6100;judge=1;} //1-4

}