#define NONE    "n"
#define FRIEND  "f"
#define ENEMY   "e"


#include <ansi.h>
inherit ROOM;
string is_special(int i,int j);
void ini_action();
int ini_create();
int ini_create_chuan();
int ini_create_special();
int add_damage(int damage);
int get_x();
int get_y();
int is_sinking();//判断是否正在下沉
int set_sinking();//设正在下沉标志
int is_sink();//判断该船是否开始下沉
int checking_sink();//该舱开始进水
int get_damage();//得到损害数值
int fabs(int a);//不知道有没有取绝对值的函数，先写一个再说了，呵呵。
int damage_level();//得到损害程度数值
int get_damage_level();//得到应该的损害程度
string get_damage_string();//得到损害程度的文字描述．
string get_damage_color();
int renew();
int get_max_damage();
string *china_ship=({
	"/d/jwhz/jiashishi.lpc",
	"/d/jwhz/jiashishi_1.lpc",
	});
string *japan_ship=({
	"/d/jwhz/jiashishij.lpc",
	"/d/jwhz/jiashishij_1.lpc",
	"/d/jwhz/jiashishij_2.lpc",
	});
void init()
{
//	add_action("do_fly","fly");
//	add_action("do_fly","goto");
//	add_action("do_savefly","savefly");
	add_action("do_view","view");
	add_action("do_jiuhuo","jiuhuo");
	add_action("do_check","check");
	ini_action();

}


int do_check()
{
	object me;
	me=this_player();
	tell_object(me,get_damage_string());
	return 1;
}
int do_savefly()
{
	tell_object(this_player(),HIW"好好打仗吧，别东想西想了!\n"NOR);
	return 1;
}

int do_fly()
{
	tell_object(this_player(),HIW"忙忙大海，你欲何处飞去？\n"NOR);
	return 1;
}

int do_view()
{
	string msg,special;
	int wide,height;
	object jwhz,chuan;
	object me=this_player();
	jwhz=load_object("/adm/daemons/jwhz.lpc");
	wide=jwhz->query("wide");
	height=jwhz->query("height");
	msg=HIC"\n┏";
	tell_object(me,HIY"海域图：\n"NOR);
	for(int i=0;i<wide;i++) msg=msg+"━";
	msg=msg+"┓";
	msg+="\n"NOR;
	for(int i=0;i<height;i++)
	{
		msg+=HIC"┃"HIB;
		for(int j=0;j<wide;j++)
		{
			special=is_special(i,j);
			if(special=="NO")
			{
				if(jwhz->position(i,j)==NONE)
					if(random(8)==0) msg=msg+"≈";
					else if(random(16)==0) msg=msg+". ";
					else if(random(50)==0) msg=msg+"..";
					else msg=msg+"  ";
				else if(jwhz->position(i,j)==FRIEND)
				{
					//msg=msg+HIG+"▲"HIB;
					for(int k=0;k<sizeof(china_ship);k++)
					{
						chuan=load_object(china_ship[k]);
						if(chuan->get_x()==j&&chuan->get_y()==i)
						{
							msg=msg+chuan->get_damage_color()+"▲"HIB;
							break;
						}
					}
				}
				else if(jwhz->position(i,j)==ENEMY)
				{
					//msg=msg+HIY"▼"HIB;"▼"HIB;
					for( int k=0;k<sizeof(japan_ship);k++)
					{
						chuan=load_object(japan_ship[k]);
						if(chuan->get_x()==j&&chuan->get_y()==i)
						{
							msg=msg+chuan->get_damage_color()+"■"HIB;
							break;
						}
					}
				}
				else if(jwhz->position(i,j)==query("id"))
					msg=msg+BNK+HIR"★"NOR+HIB;
				else //if(jwhz->position(i,j)==SHOOTED)
					msg=msg+HIR"★"HIB;
			/*	else
					msg=msg+"  ";*/
			}
			else
			{
				msg=msg+special;
			}
		}
		msg=msg+HIC"┃\n"HIB;
		tell_object(me,msg);
		msg="";
	}
	msg=msg+HIC"┗";
	for(int i=0;i<wide;i++) msg=msg+"━";
	msg=msg+"┛"NOR;
	msg+="\n";
	tell_object(me,msg);
	return 1;
}
int get_wide()
{
	object jwhz;
	jwhz=load_object("/adm/daemons/jwhz.lpc");
	return jwhz->query("wide");
}
int get_height()
{
	object jwhz;
	jwhz=load_object("/adm/daemons/jwhz.lpc");
	return jwhz->query("height");
}
int ini_create_chuan()
{
	set("fire",0);
	set("fire_cause","none");
	set("fire_message",1);
	set("sink",0);
	set("sink_cause","none");
	set("no_die",1);
/*	remove_call_out("checking_fire");
	call_out("checking_fire",2);*/
	return 1;
}
int checking_fire()//第一个火源爆发时，一定要调用该房间的checking_fire()
{
	object *allperson;
//	message("vision","调试\n",users());
	if(!query("fire"))
	{
	/*	remove_call_out("checking_fire");
		call_out("checking_fire",2);*/
		return 1;
	}
	if(query("sink")) return 1;
	add_damage(1);
	if(!is_sinking()&&is_sink())
	{
		checking_sink();
		CHANNEL_D->do_channel(this_object(), "bd", HIR + query("shipname")+HIR"开始沉没！", -1);
		return 1;
	}
	if(query("fire_message"))
	{
		if(query("fire_cause")=="none")
			message("vision",RED"这里莫名其妙的就发起了大火!\n"NOR,this_object());
		else if(query("fire_cause")=="击中")
			message("vision",RED"由于这里被炮弹击中，引发了大火!\n"NOR,this_object());
		else if(query("fire_cause")=="相撞")
			message("vision",RED"由于相撞，这里立刻就火焰冲天!\n"NOR,this_object());
		else
			message("vision",RED"从"+query("fire_cause")+"传来的大火火势突然就大了起来，让你无法控制！\n"NOR,this_object());
		set("fire_message",0);
	}
	set("long",YEL+query("short")+YEL"已经陷入一片火海之中！\n"NOR);
	if(random(2)==0)
	{
		allperson=all_inventory(this_object());
		for(int i=0;i<sizeof(allperson);i++)
		{
			if(allperson[i]->is_character())
			{
				tell_object(allperson[i],HIY"你觉得浓烟让你感到窒息,你差点昏了过去!\n"NOR);
				if(allperson[i]->query("qi")<20||allperson[i]->query("eff_qi")<10)
				{
                    allperson[i]->receive_damage("qi", 0, "被大火活活烧");
					allperson[i]->die();
					if(living(allperson[i]))
                    CHANNEL_D->do_channel(this_object(), "bd", HIW + query("shipname")+HIW"："+allperson[i]->query("name")+HIW"被大火活活烧死，为国捐躯！", -1);
					continue;
				}

				allperson[i]->receive_wound("qi", 1, "被大火活活烧");
				allperson[i]->receive_damage("qi", 2, "被大火活活烧");
			}
		}
	}
	if(!query("spreading"))
	{
		//火势蔓延。
		set("spreading",1);
		remove_call_out("spead_fire");
		call_out("spead_fire",5,this_object());
	}
	remove_call_out("checking_fire");
	call_out("checking_fire",2);
	return 1;
}
int spead_fire(object source)
{
	mapping chukou;
	string *dir;
	object room;
	chukou=source->query("exits");
	dir=keys(chukou);
	set("spreading",0);
	if(!source->query("fire")) return 1;
	for(int i=0;i<sizeof(dir);i++)
	{
		room=load_object(chukou[dir[i]]);
		if(room->query("fire")) continue;
		message("vision",HIR"突然一阵大火从"+source->query("short")+HIR"传来！\n"NOR,room);
		room->set("fire_message",1);
		room->set("fire",1);
		room->set("fire_cause",source->query("short"));
		message("vision",HIR"火势向"+room->query("short")+HIR"蔓延过去！\n"NOR,source);
		room->checking_fire();
	}
	return 1;
}
int do_jiuhuo()
{
	
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(!query("fire"))
	{
                tell_object(me,HIC"根本没有着火，你救什么火呀？\n"NOR);
		return 1;
	}
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢!\n"NOR);
		return 1;
	}
	me->start_busy(1);
	add("jiuhuo",1);
	if(query("jiuhuo")>3)
	{
		message_vision(MAG"大火在努力的扑救下，终于熄灭了!\n"NOR,me);
		set("jiuhuo",0);
		set("fire",0);
		set("long",YEL"虽然大火已经扑灭了，但是"+query("short")+YEL"已经是被烧得一片狼藉了...\n"NOR);
	}
	else
	{
		message_vision(MAG"$N拿起一桶水，向船上的火苗泼去!\n"NOR,me);
		me->add_temp("jwhz/jiuhuo");
		tell_object(me,HIG"你觉得火势在你扑救下小了一些!\n"NOR,me);
	}
	return 1;
}
int checking_sink()
{
	set("sink",1);
	if(query("short")=="驾驶室")
	{
		object jwhz;
		jwhz=load_object("/adm/daemons/jwhz.lpc");
		jwhz->write_position(get_y(),get_x(),NONE);
	}
	set_sinking();
	if(query("sink_cause")=="none")
		message("vision",HIR"这里莫名其妙的就漏水了！\n\n"NOR,this_object());
	else if(query("sink_cause")=="击中")
		message("vision",HIR"由于这里被炮弹击中的地方破了一个大窟窿，海水哗的一下就涌了进来!\n\n"NOR,this_object());
	else if(query("sink_cause")=="相撞")
		message("vision",HIR"你的船被撞的地方突然出现了一个大窟窿，海水哗的一下就涌了进来!\n\n"NOR,this_object());
	else
		message("vision",HIR"这里水越漫越高，终于慢过了你的头顶！\n\n"NOR,this_object());
	remove_call_out("sink_die");
	call_out("sink_die",1);
	return 1;
}
int sink_die()
{
	object *allperson;
	allperson=all_inventory(this_object());
	for(int i=0;i<sizeof(allperson);i++)
	{
		string name;
		tell_object(allperson[i],HIR"苦涩的海水从你眼、耳、口、鼻一起涌了进来。\n你不停地喊救命，不停地挣扎，但这个时候已经毫无用处，你知道，你在这个世界上存在的时间已经开始以秒计数了...\n"NOR);
		name=allperson[i]->query("name");//避免有被destruct的npc
		if(!allperson[i]->is_character()) 
		{
			destruct(allperson[i]);
			continue;
		}
		if(allperson[i]->is_character()&&living(allperson[i]))
		{
			if(query("pai")=="中国")
				CHANNEL_D->do_channel(this_object(), "bd", HIW + query("shipname")+HIW"："+name+HIW"为国捐躯！", -1);
		}
        allperson[i]->receive_damage("qi", 0, "被水淹");
		allperson[i]->die();
	}
	//水的蔓延
	remove_call_out("spead_sink");
	call_out("spead_sink",1,this_object());
	return 1;
		
}
int spead_sink(object source)
{
	mapping chukou;
	string *dir;
	object room;
	chukou=source->query("exits");
	dir=keys(chukou);;
	for(int i=0;i<sizeof(dir);i++)
	{
		room=load_object(chukou[dir[i]]);
		if(room->query("sink")) continue;
		message("vision",HIB"突然一阵海水从"+source->query("short")+HIB"涌来！\n"NOR,room);
		room->set("sink",1);
		room->set("sink_cause",source->query("short"));
		message("vision",HIB"海水向"+room->query("short")+HIB"涌过去！\n"NOR,source);
		room->checking_sink();
	}
	return 1;
}
int valid_leave(object me, string dir)
{
	mapping chukou;
	object room;
	chukou=this_object()->query("exits");
	if(chukou[dir]) room=load_object(chukou[dir]);
	if(!room) return 1;
	if(room->query("sink")&&SECURITY_D->get_status(me)== "(player)") return notify_fail("那边都是水，你去找死呀?\n");
	return ::valid_leave(me, dir);
}

int is_sink()
{
	if(get_damage()>get_max_damage())	
		return 1;
	else
		return 0;
}

string get_damage_string()
{
	int damagelevel;
	string msg;
	damagelevel=damage_level();
	switch (damagelevel){
	case 0:
		msg=HIW+query("shipname")+get_damage_color()+"没有受到任何伤害！\n"NOR;
		return msg;
	case 1:
		msg=HIW+query("shipname")+get_damage_color()+"受到了些微伤害!\n"NOR;
		return msg;
	case 2:
		msg=HIW+query("shipname")+get_damage_color()+"的船体有些摇晃！\n"NOR;
		return msg;
	case 3:
		msg=HIW+query("shipname")+get_damage_color()+"的船体正在大幅度的摇晃！\n"NOR;
		return msg;
	case 4:
		msg=HIW+query("shipname")+get_damage_color()+"已经受到了很大的伤害了！\n"NOR;
		return msg;
	case 5:
		msg=HIW+query("shipname")+get_damage_color()+"的船身已经有些略微的倾斜了！\n"NOR;
		return msg;
	case 6:
		msg=HIW+query("shipname")+get_damage_color()+"的情况堪忧！\n"NOR;
		return msg;
	case 7:
		msg=HIW+query("shipname")+get_damage_color()+"的船身已经严重的倾斜了！\n"NOR;
		return msg;
	case 8:
		msg=HIW+query("shipname")+get_damage_color()+"已经受到了极大的损害了！\n"NOR;
		return msg;
	case 9:
		msg=HIW+query("shipname")+get_damage_color()+"已经受到了极其严重的损害，正在勉强支撑！\n"NOR;
		return msg;
	case 10:
		msg=HIW+query("shipname")+get_damage_color()+"已经不能再受到任何伤害了，船体随时都有可能沉下去！\n"NOR;
		return msg;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		msg=HIW+query("shipname")+RED+"如果现在还没有沉下去，那简直就是一个奇迹!\n"NOR;
		return msg;
	default:
		msg=BNK+RED+"船体伤害值异常！\n"NOR;
		return msg;
	}
}
		
int get_x()
{
	object chuan;
	int value;
	chuan=load_object(JIASHISHI);
	value=chuan->query("x");
	return value;
}
int get_y()
{
	object chuan;
	int value;
	chuan=load_object(JIASHISHI);
	value=chuan->query("y");
	return value;
}
int add_damage(int damage)
{
	int damagelevel;
	object chuan,cang;
	string *chuansheng,msg;
	chuan=load_object(JIASHISHI);
	chuan->add("damage",damage);
	damagelevel=damage_level();
	if(damagelevel!=get_damage_level())
	{
		chuan->set("damage_level",get_damage_level());
		chuansheng=query("chuansheng");
		for( int i=0;i<sizeof(chuansheng);i++)
		{
			cang=load_object(chuansheng[i]);
			msg=get_damage_string();
	//		message( "channel:" + "chat",HIW + "【】"+msg,users());

			message("vision",msg,cang);
		}
	}
	return 1;
}
int ini_create_special()
{
	set("shipname",SHIPNAME);
	set("pai",PAI);
	set("chuansheng",({
		CHUANSHENG
	}));
	return 1;
}
int get_damage()
{
	object chuan;
	chuan=load_object(JIASHISHI);
	return chuan->query("damage");
}
int is_sinking()//判断是否正在下沉
{
	object chuan;
	chuan=load_object(JIASHISHI);
	return chuan->query("sinking");
}
int set_sinking()
{
	object chuan;
	chuan=load_object(JIASHISHI);
	chuan->set("sinking",1);
}
int get_damage_level()
{
	int damage,max_damage;
	object chuan;
	chuan=load_object(JIASHISHI);
	damage=chuan->query("damage");
	max_damage=chuan->query("max_damage");
	if(damage==0)
		return 0;
	return damage*10/max_damage+1;
}
int damage_level()
{
	object chuan;
	chuan=load_object(JIASHISHI);
	return chuan->query("damage_level");
}
int get_max_damage()
{
	object chuan;
	chuan=load_object(JIASHISHI);
	return chuan->query("max_damage");
}
string get_damage_color()
{
	switch(damage_level()){
	case 0:
		return HIG;
	case 1:
		return GRN;
	case 2:
		return HIY;
	case 3:
		return YEL;
	case 4:
		return HIC;
	case 5:
		return CYN;
	case 6:
		return WHT;
	case 7:
		return HIM;
	case 8:
		return MAG;
	case 9:
		return HIR;
	case 10:
		return RED;
	default:
		return BLU;
	}
}
