// look.c
#pragma optimize
#pragma save_binary

#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <armor.h>
#include <zjmud.h>

#define SHOW_IMMEDIATELY	0
#define RETURN_RESULT	 1
#define TIME_TICK1 ((time()-900000000)*60)

inherit F_CLEAN_UP;

int look_room(object me, object env, int brief);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string look_equiped(object me, object obj, string pro);
string look_all_inventory_of_room(object me, object env, int ret_str);
string gettof(object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
	HIG "明劲·入门" NOR,     // 0    exp: 0--10000 
	HIG "明劲·初期" NOR,     // 1    exp: 10000--20000  
	HIG "明劲·中期" NOR,     // 2    exp: 20000--30000 
	HIG "明劲·后期" NOR,     // 3    exp: 30000--40000
	HIB "明劲·圆满" NOR,     // 4    exp: 40000--50000
	HIB "暗劲·入门" NOR,     // 5    exp: 50000--60000
	HIB "暗劲·初期" NOR,     // 6    exp: 60000--70000
	HIB "暗劲·中期" NOR,     // 7    exp: 70000--80000
	HIB "暗劲·后期" NOR,     // 8    exp: 80000--90000
	HIB "暗劲·圆满" NOR,     // 9    exp: 120000--160000
	HIB "内劲·入门" NOR,     // 10   exp: 160000--250000
	HIB "内劲·初期" NOR,     // 11   exp: 250000--350000
	HIB "内劲·中期" NOR,     // 12   exp: 350000--550000
	HIB "内劲·后期" NOR,     // 13   exp: 550000--750000
	HIB "内劲·圆满" NOR,     // 14   exp: 750000--900000
	HIM "化劲·入门" NOR,     // 15   exp: 900000--1150000
	HIM "化劲·初期" NOR,     // 16   exp: 1150000--1350000
	HIM "化劲·中期" NOR,     // 17   exp: 1350000--1500000
	HIM "化劲·后期" NOR,     // 18   exp: 1500000--1700000
	HIM "化劲·圆满" NOR,     // 19   exp: 1700000--1900000
	HIM "罡劲·入门" NOR,     // 20   exp: 1900000--2150000
	HIM "罡劲·初期" NOR,     // 21   exp: 2150000--2400000
	HIM "罡劲·中期" NOR,     // 22   exp: 2400000--2550000
	HIM "罡劲·后期" NOR,     // 23   exp: 2550000--2700000
	HIM "罡劲·圆满" NOR,     // 24   exp: 2700000--2850000
	HIM "涅槃·入门" NOR,     // 25   exp: 2850000--3000000
	HIY "涅槃·初期" NOR,     // 26   exp: 3000000--3500000
	HIY "涅槃·中期" NOR,     // 27   exp: 3500000--4000000
	HIY "涅槃·后期" NOR,     // 28   exp: 4000000--5250000
	HIY "涅槃·圆满" NOR,     // 29   exp: 5250000--7000000
	HIY "超凡·入门" NOR,     // 30   exp: 7000000--7500000
	HIY "超凡·初期" NOR,     // 31   exp: 7500000--8250000
	HIY "超凡·中期" NOR,     // 32   exp: 8250000--9000000
	HIY "超凡·后期" NOR,     // 33   exp: 9000000--12000000
	HIY "超凡·圆满" NOR      // 34   exp: 12000000--15000000
	HIY "天君·入门" NOR,     // 35   exp: 2850000--3000000
	HIY "天君·初期" NOR,     // 36   exp: 3000000--3500000
	HIY "天君·中期" NOR,     // 37   exp: 3500000--4000000
	HIY "天君·后期" NOR,     // 38   exp: 4000000--5250000
	HIY "天君·圆满" NOR,     // 39   exp: 5250000--7000000
	HIY "真王·入门" NOR,     // 40   exp: 2850000--3000000
	HIY "真王·初期" NOR,     // 41   exp: 3000000--3500000
	HIY "真王·中期" NOR,     // 42   exp: 3500000--4000000
	HIY "真王·后期" NOR,     // 43   exp: 4000000--5250000
	HIY "真王·圆满" NOR,     // 44   exp: 5250000--7000000
	HIY "圣皇·入门" NOR,     // 45   exp: 2850000--3000000
	HIY "圣皇·初期" NOR,     // 46   exp: 3000000--3500000
	HIY "圣皇·中期" NOR,     // 47   exp: 3500000--4000000
	HIY "圣皇·后期" NOR,     // 48   exp: 4000000--5250000
	HIY "圣皇·圆满" NOR,     // 49   exp: 5250000--7000000
	HIY "帝尊·入门" NOR,     // 50   exp: 2850000--3000000
	HIY "帝尊·初期" NOR,     // 51   exp: 3000000--3500000
	HIY "帝尊·中期" NOR,     // 52   exp: 3500000--4000000
	HIY "帝尊·后期" NOR,     // 53   exp: 4000000--5250000
	HIY "帝尊·圆满" NOR,     // 54   exp: 5250000--7000000
});
int *look_exp=({
	10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,200000,300000,400000,500000,600000,
	700000,800000,900000,1000000,2000000,3000000,4000000,5000000,6000000,7000000,8000000,9000000,
	10000000,20000000,30000000,40000000,50000000,60000000,70000000,80000000,90000000,100000000,
    150000000,200000000,250000000,300000000,350000000,400000000,450000000,500000000,550000000,
    600000000,650000000,700000000,750000000,800000000,850000000,900000000,9500000000,
});
string *heavy_level_desc= ({
	"极轻",
	"很轻",
	"不重",
	"不轻",
	"很重",
	"极重"	
});
string *first_name = ({ YEL,HIY,HIM,HIG,HIW,HIR});
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object obj;
	object env;
	int result;
	string objid, where;

	if (! arg) result = look_room(me, environment(me), 0);
	else
	{
		if (sscanf(arg, "%s of %s", objid, where) == 2)
		{
			if (where == "here")
			obj = present(objid, environment(me));
			else
			if (where == "me")
			obj = present(objid, me);
			else
			{
				env = present(where, environment(me));
				if (! objectp(env))
				return notify_fail("你要看哪里的东西？\n");
				obj = present(objid, env);
				if (env->is_character() && env != me)
				{
					if (! objectp(obj) ||
							! obj->query("equipped") &&
							env->query_temp("handing") != obj)
					return notify_fail("这人好像并没有漏出来你想看的东西啊。\n");
					message("vision", me->name() + "盯着你的" + obj->name() + "看了一会儿，不知道在打什么主意。\n", env);
					message("vision", me->name() + "盯着" + env->name() + "的" +obj->name() + "看了一会儿，不知道在打什么主意。\n",
					environment(me), ({ me, env }));
				}
			}

			if (! obj)
			return notify_fail("那里没有这样东西。\n");
		}	

		if( obj || (obj = find_player(arg)) || (obj = present(arg, environment(me))) || (obj = present(arg, me))|| (obj = find_object(arg)) )
		{
			if( obj->is_character() && ! obj->is_corpse()) result = look_living(me, obj);
			else result = look_item(me, obj);
		} else result = look_room_item(me, arg);
	}

	return result;
}

int look_room(object me, object env, int brief)
{
	int i;
	mapping exits,descs,actlist;
	string str, *dirs,*desc;
	object room;
	mixed *cmds;
	string *mapped;

	if( !env ) {
		tell_object(me, "你的四周灰蒙蒙地一片，什么也没有。\n");
		me->move("/d/wizard/guest_room");
		return 1;
	}

	if( !brief )
	{
		str = sprintf(ZJTITLE"%s\n"ZJLONG "%s",env->short(),replace_string(env->long(),"\n",""));
	} else
	{
		str = sprintf(ZJTITLE"%s\n"ZJLONG"～～～场景信息已屏蔽～～～"+ZJURL("cmds:unset brief")+"取消屏蔽"NOR,env->short());
	}

	if (mapp(exits = env->query("exits")))
	{
		dirs = keys(exits);
		dirs -= ({ 0 });
		str += "\n" + ZJEXIT;
        str += "save:"HIR"●存档●"NOR+ZJSEP;
		str += "help kuaijie:"HIR"快捷功能"NOR+ZJSEP;
		str += "use quest sss:"HIG"自动师门"NOR+ZJSEP;
		str += "help mapb:"HIY"驭雕飞行"NOR+ZJSEP;

		if (!me->query("map_all")&&env->query("outdoors")&&env->query("outdoors")!="hell"&&me->query("out_family")&&me->query("id")!="a3901500")
		{
			mapped = me->query("map/"+env->query("outdoors"));
			if (!arrayp(mapped)) mapped = ({ });
			if (member_array(env->short(), mapped)==-1)
			str += "map here:"HIG"画  图"NOR+ZJSEP;
			//str += "use quest sss;accept quest;eat bt dan;jiqu:"HIG"自动师门"NOR+ZJSEP;
		}
		if (FUBEN_D->query_where(base_name(env)))
		{
			str += "fuben:"HIG"副本列表"NOR+ZJSEP;
		}
		if (env->query("price_build"))
		{
			str += "crroom:"HIM"建设家园"NOR+ZJSEP;
		}
		
		if (env->query("resource/fish")&&present("diao gan",me)&&present("yu er",me))
		{
			str += "fish:"HIM"钓鱼"NOR+ZJSEP;
			str += "draw diao gan:"HIG"拉杆"NOR+ZJSEP;
			str += "halt:"HIR"中断"NOR+ZJSEP;
		}
		if (env->query("short")=="狂盗谷" || env->query("short")=="狂盗谷入口")
		{
			str += "quest1:"HIC"剩余时间"NOR+ZJSEP;
		}
		if(wizardp(me))
		{
			str += "help kuaijie1:"HIC"天  神"NOR+ZJSEP;
			str += "update here:更新此地"+ZJSEP;
			//			str += ZJSEP;
			//			str += "full:"HIM"恢复状态"NOR+ZJSEP;
		}
		
		//str += "help ts:"HIM"特色功能"NOR+ZJSEP;
		
		for (i=0;i<sizeof(dirs);i++)
		{
			if(!room=find_object(exits[dirs[i]]))  room=load_object(exits[dirs[i]]);
			if(room)  str+=sprintf("%s:%s",dirs[i],room->query("short"));
			if(i<(sizeof(dirs)-1)) str += ZJSEP;
		}
	}
	if (mapp(actlist = env->query("action_list")))
	{
		if(!mapp(exits))
		str += "\n" + ZJEXIT;
		else
		str += ZJSEP;
		dirs = keys(actlist);
		dirs -= ({ 0 });
		for (i=0;i<sizeof(dirs);i++)
		{
			str += sprintf("%s:%s",actlist[dirs[i]],dirs[i]);
			if(i<(sizeof(dirs)-1)) str += ZJSEP;
		}
	}

	str += look_all_inventory_of_room(me, env, RETURN_RESULT);

	if (mapp(descs = env->query("item_desc")))
	{
		str += "\n"+ZJOBIN;
		desc = keys(descs);
		for (i=0;i<sizeof(desc);i++)
		{
			str += desc[i] + ":look " + desc[i];
			if(i<(sizeof(desc)-1)) str += "$zj#";
		}
	}
	tell_object(me, str+"\n");

	return 1;
}

string desc_of_objects(object *obs,object me)
{
	int i,n;
	string  str,rid,*id,rname;
	string name2;
	name2 = first_name[random(sizeof(first_name))];
	if (obs && sizeof(obs) > 0)
	{
		str = "\n" + ZJOBIN;
		for (i = 0; i < sizeof(obs); i++)
		{
			if(obs[i]->query_amount())
			rname = obs[i]->query("name")+"("+obs[i]->query_amount()+")";
			else
			rname = obs[i]->query("name");

			if(playerp(obs[i]))
			str += HIC+rname+NOR":look "+file_name(obs[i]);
			else if(obs[i]->query("id") == me->query("quest/id") )
			str += name2+rname+NOR":look "+file_name(obs[i]);
			else
			str += rname+":look "+file_name(obs[i]);
			if(i<(sizeof(obs)-1)) str += ZJSEP;
		}
		return str;
	}

	return "";
}

string look_all_inventory_of_room(object me, object env, int ret_str)
{
	object *inv;
	object *obs;

	string  str;

	if (! env || ! me) return "";

	inv = all_inventory(env);
	if (! sizeof(inv)) return "";

	str = "";

	obs = filter_array(inv, (: $(me) != $1 && userp($1) && $(me)->visible($1) :));
	str += desc_of_objects(obs,me);

	obs = filter_array(inv, (: $(me) != $1 && !userp($1) && $1->is_character() && $(me)->visible($1) :));
	str += desc_of_objects(obs,me);

	obs = filter_array(inv, (: !$1->is_character() :), me);
	str += desc_of_objects(obs,me);

	if (!ret_str)
	tell_object(me, str);

	return str;
}

string get_inv_act(object me, object obj)
{
	mapping acts;
	string act,look_msg3="";

	if(present(obj,me))
	{
		if (obj->query("equipped")&&stringp(obj->query("skill_type")))
		look_msg3 += "放下 "+obj->query("name")+":unwield "+file_name(obj)+ZJSEP;
		else if (obj->query("equipped")&&stringp(obj->query("armor_type")))
		look_msg3 += "脱掉 "+obj->query("name")+":remove "+file_name(obj)+ZJSEP;
		else if (stringp(obj->query("skill_type")))
		look_msg3 += "装备 "+obj->query("name")+":wield "+file_name(obj)+ZJSEP;
		else if (stringp(obj->query("armor_type")))
		look_msg3 += "穿戴 "+obj->query("name")+":wear "+file_name(obj)+ZJSEP;
		else if (obj==me->query_temp("is_riding"))
		look_msg3 += "下来 "+obj->query("name")+":unride "+file_name(obj)+ZJSEP;	

		if (obj->is_item_make())
		{
			if(obj->query("consistence")<100&&me->query("zjvip/times"))
			look_msg3 += "修理 "+obj->query("name")+":repairv "+file_name(obj) +ZJSEP;

			look_msg3 += "强化 "+obj->query("name")+":enhance "+file_name(obj) + " with jin sha" +ZJSEP;
			look_msg3 += "圣化 "+obj->query("name")+":san "+file_name(obj)  + ZJSEP;
			look_msg3 += "浸透 "+obj->query("name")+":imbue "+file_name(obj)  + ZJSEP;
			if(obj->query("magic/tessera"))
			look_msg3 += "摘除 "+obj->query("magic/tessera")+":zhaichu "+file_name(obj)  + ZJSEP;
			else
			look_msg3 += "镶嵌 "+obj->query("name")+":enchase "+file_name(obj)  + ZJSEP;
		}

		if(obj->query("can_be_enchased")&&obj->query("enchased_need"))
		look_msg3 += "合成 "+(obj->query("can_be_enchased"))->query("name")+":combine "+file_name(obj)+ZJSEP;

		if(acts = obj->query("action_list"))
		{
			foreach(act in keys(acts))
			look_msg3 += act +" "+obj->query("name")+":"+acts[act]+ZJSEP;
		}
		if (obj->query("food_remaining"))
		look_msg3 += "吃 "+obj->query("name")+":eat "+file_name(obj)+ZJSEP;
		else if (obj->query("only_do_effect"))
		look_msg3 += "使用 "+obj->query("name")+":use "+file_name(obj)+ZJSEP;
		else if (obj->query("liquid/remaining"))
		look_msg3 += "喝 "+obj->query("name")+":drink "+file_name(obj)+ZJSEP;
		else if (obj->query("liquid/bei"))
		look_msg3 += "喝 "+obj->query("name")+":drinkjiu2 "+file_name(obj)+ZJSEP;	//新酒喝法
		else if (obj->query("skill") )
		look_msg3 += "研读 "+obj->query("name")+":study "+file_name(obj)+ZJSEP;

		else if (obj->query("id")=="kuihua baodian")
		look_msg3 += "研读 "+obj->query("name")+":study kuihua baodian"+ZJSEP;

		look_msg3 += "查看 "+obj->query("name")+":lookmore "+file_name(obj)+ZJSEP;

		if(objectp(present("chuwu dai",me)))
		look_msg3 += "存入 "+present("chuwu dai",me)->query("name")+":mystore put "+file_name(obj)+ZJSEP;
		
		if(objectp(present("du wan",me)))			
		look_msg3 += HIG"投毒 "NOR+obj->query("name")+":drug du wan in "+obj->query("id")+" "ZJSEP;
		
		look_msg3 += "展示 "+obj->query("name")+":showitem "+file_name(obj)+ZJSEP;
		look_msg3 += "手持 "+obj->query("name")+":hand "+file_name(obj)+ZJSEP;
		look_msg3 += "出售 "+obj->query("name")+":sellob "+file_name(obj)+ZJSEP;
		look_msg3 += "丢弃 "+obj->query("name")+":drop "+file_name(obj)+ZJSEP;
		look_msg3 += HIC"<返回背包>"NOR":i ";

	}
	return look_msg3;
}

int look_item(object me, object obj)
{
	object hob;
	mixed *inv;
	mapping acts,count;
	mapping equiped;
	mapping unit;
	string short_name;
	mapping du;
	string act,str;
	string *dk;
	string type="";
	int i;
	int line;
	count   = ([]);
	unit    = ([]);
	equiped = ([]);

	//鉴定
	if (obj->query("ok_jianding") && (obj->query("weapon_prop") || obj->query("armor_prop")))
	{
		type = obj->query("jianding") ? HIG"  ■已鉴定"NOR : HIR"  ■待鉴定"NOR;
	}
	if (obj->query("spoil"))
		type = HIR"(已损坏)"NOR;
	
	
	str = ZJOBLONG+obj->short()+"\n";
	str += "一一一一一一一一一一一一一一一一一一一一一一\n";
	str += obj->long();
	if(obj->long()=="") return 1;
	str = ZJOBLONG+obj->short()+(type)+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR+obj->long();
	if(obj->query("id")=="board" ||  obj->query("id")=="mailbox" || obj->query("id")=="corpse" || obj->query("id")=="sleepbag" || obj->query("id")=="skeleton")
	line=0;
	else
	line=1;
	if((int)obj->query("value")==0)
	{
		line=0;  
	}
	if(!present(obj,me)&&(obj->query("id")=="coin"||obj->query("id")=="silver"||obj->query("id")=="gold"||obj->query("id")=="cash"))
	{
		str = replace_string(str,"\n",ZJBR);
		str += "\n";
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "捡起来:get " + file_name(obj);
		write(str+"\n");
		return 1;
	}
	if(obj->query("id")=="newbie" ) return 1;
	if(line)
	{
		str += "一一一一一一一一一一一一一一一一一一一一一一\n";
	}
	/*
	//毒物的话
	if(obj->query("poison_type")=="poison")
	{
		if(mapp(du=obj->query("poison")))
		{
			str += HIG"【类　别】: "+du["name"]+NOR"\n";
			str += HIG"【级　别】: "+chinese_number((int)du["level"])+NOR"\n";
			str += HIG"【持续度】: "+chinese_number((int)du["duration"])+NOR"\n";
			str += HIG"【制作者】: "+du["id"]+NOR"\n";
			if(obj->query("value"))
			{
				str += YEL"【价　值】: "+MONEY_D->money_str((int)obj->query("value"))+NOR"\n";
			}
		}
	}
	else
	{
		if(obj->item_owner() && obj->apply_damage())
		{
			str += YEL"【经　验】: "+obj->weapon_exp()+NOR" / "HIY+obj->level_max_exp(obj->weapon_level())+NOR" / "HIY+chinese_number(obj->level_now(obj->weapon_level()))+NOR"级\n"; 
			if(obj->query("magic/imbue_ob"))
				str += MAG"【圣　化】: 已圣化，需"+obj->query("magic/imbue_name")+"浸透"+NOR"\n";
			else
				str += MAG"【圣　化】: 未圣化"+NOR"\n";
			str += HIM"【浸　透】: "+chinese_number((int)obj->query("magic/imbue"))+NOR"\n";
			str += HIR"【血　腥】: "+chinese_number((int)obj->query("combat/MKS")+(int)obj->query("combat/PKS"))+NOR"\n"; 
		}
		else if(obj->item_owner())
		{
			str += HIY"【等　级】: "+chinese_number((int)obj->armor_level())+NOR"\n"; 
		}
		if(obj->query("weapon_prop/damage"))
		{
			str += HIR"【攻击力】: "+chinese_number((int)obj->query("weapon_prop/damage"))+NOR"\n";
		}
		if(obj->query("armor_prop/unarmed_damage"))
		{
			str += HIR"【攻击力】: "+chinese_number((int)obj->query("armor_prop/unarmed_damage"))+HIR"　　--<注：仅空手有效>\n"NOR;
		}
		if(obj->query("power"))
		{
			str += HIR"【破坏力】: "+chinese_number((int)obj->query("power"))+NOR"\n";
		}
		if(obj->query("accuracy"))
		{
			str += HIG"【精确度】: "+chinese_number((int)obj->query("accuracy"))+NOR"\n";
		}
		if(obj->query("armor_prop/armor"))
		{
			str += HIG"【防御力】: "+chinese_number((int)obj->query("armor_prop/armor"))+NOR"\n";
		}
		if(obj->query("armor_prop/warm"))
		{
			str += HIG"【保暖度】: "+chinese_number((int)obj->query("armor_prop/warm"))+NOR"\n";
		}
		if(obj->query("armor_buwei"))
		{
		str += GRN"【部　位】: "+obj->query("armor_buwei")+NOR"\n";
		}
		if(obj->query("material") && !obj->item_owner())
		{
			str += GRN"【材　质】: "+to_chinese(obj->query("material"))+NOR"\n";
		}
	
		if(obj->query("value") && !obj->item_owner() && line)
		{
			str += YEL"【价　值】: "+MONEY_D->money_str((int)obj->query("value"))+NOR"\n";
		}
		if(obj->item_owner() && obj->apply_damage())
		{
			if (me->query("can_summon/"+obj->query("id")))
			{
				str += GRN"【开　光】: "GRN"已绑定\n"NOR;
			}
			else
			{
				str += GRN"【开　光】: "WHT"未开光 < 寻找张天师开光 > \n"NOR;
			}   
		}	 
	}
*/
	while (mapp(obj->query_temp("daub")))
	{
		if (! obj->query_temp("daub/poison/remain"))
		// no poison remain now
		break;

		if (obj->query_temp("daub/poison/id") == me->query("id"))
		{
			str += HIG "你发现这上面还有你炼制的" + obj->query_temp("daub/poison/name") + HIG "呢。"NOR"\n";
			break;
		}

		if (obj->query_temp("daub/who_id") == me->query("id"))
		{
			str += HIG "这上面还有你亲手布下的" + obj->query_temp("daub/poison/name") + HIG "呢。"NOR"\n";
			break;
		}

		if (random(4) && random((int)me->query_skill("poison", 1)) < 30)
		// nothing was worked out
		break;

		str += HIG "忽然间你发现上面似乎泛着一些奇异荧光";
		if (me->query_skill("poison", 1) >= 120)
		{
			str += "，可能是" + obj->query_temp("daub/poison/name");
		}

		str += "。"NOR"\n";
		break;
	}

	if(obj->query("weapon_prop/damage"))
	{
		str += HIR"【攻击力】："+chinese_number((int)obj->query("weapon_prop/damage"))+NOR"\n";
	}
	if(obj->query("armor_prop/unarmed_damage"))
	{
		str += HIR"【攻击力】："+chinese_number((int)obj->query("armor_prop/unarmed_damage"))+NOR"\n";
	}
	if(obj->item_owner() && obj->apply_damage()&&obj->query("magic/power"))
	{
		str += HIM"【魔　力】："+chinese_number((int)obj->query("magic/power"))+NOR"\n";
	}
	if(obj->query("armor_prop/armor"))
	{
		str += HIG"【防御力】："+chinese_number((int)obj->query("armor_prop/armor"))+NOR"\n";
	}

	if (obj->query("consistence"))
	str += sprintf("【耐久度】：" WHT "%d%%"NOR"\n", obj->query("consistence"));

	inv = all_inventory(obj);
	if (!sizeof(inv))
	{
		str = replace_string(str,"\n",ZJBR);
		if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
		str = str[0..(strlen(str)-5)];
		if(!obj->query("no_get")&&!present(obj,me)&&present(obj,environment(me)))
		{
			str += "\n"+ZJOBACTS2+ZJMENUF(3,3,10,30);
			str += "捡起来:get " + file_name(obj);
			if(obj->is_cutable())
			{
				str += ZJSEP"解:cut " + obj->query("id");
			}
		}
		else if(acts = obj->query("acts_list"))
		{
			str += "\n"+ZJOBACTS2+ZJMENUF(3,3,10,30);
			foreach(act in keys(acts))
			str += act +" "+obj->query("name")+":"+acts[act] + ZJSEP;
		}

		if(present(obj,me))
		{
			str += "\n"+ZJOBACTS2+ZJMENUF(3,3,10,30);
			str += get_inv_act(me,obj)+"\n";
		}
		if(str==ZJOBLONG) return 1;
		message("vision", str+"\n", me);
		return 1;
	}

	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
	str = str[0..(strlen(str)-5)];
	str += "\n";

	str += ZJOBACTS2+ZJMENUF(3,3,10,30);
	if(present(obj,me))
	{
		str += get_inv_act(me,obj);
	}
	if(!present(obj,me)&&present(obj,environment(me)))
	{
		str += "捡起来:get " + file_name(obj);
		for(i=0;i<sizeof(inv);i++)
		{
			str += ZJSEP+inv[i]->query("name")+(inv[i]->query_amount()?"("+inv[i]->query_amount()+")":"")+":get "+file_name(inv[i])+" from " + file_name(obj);
		}
	}
	if(obj->is_cutable())
	{
		str += ZJSEP"细致解刨:cut " + obj->query("id");
		str += ZJSEP"斩首示众:cut head from " + obj->query("id");
	}
	if(acts = obj->query("acts_list"))
	{
		foreach(act in keys(acts))
		str += ZJSEP + act +" "+obj->query("name")+":"+acts[act];
	}

	str += "\n";
	if (strlen(str) > 4096)
	me->start_more(str);
	else
	message("vision", str, me);
	return 1;
}
//人物评价代码
string gettof(object ob)
{
	int exp_temp ,i;
	exp_temp=(int)ob->query("combat_exp");
	for(i=0;i<sizeof(tough_level_desc);i++)
	{
		if(exp_temp<500)
		{
			return HIR+"不堪一击"+NOR;
		}
		if((i+1)==sizeof(tough_level_desc))
		{
			return tough_level_desc[i];
		}
		if(exp_temp>=look_exp[i] && exp_temp<look_exp[i+1])
		{
			return tough_level_desc[i+1];
		}
		
	}
	return HIR+"深不可测"+NOR;
}
string look_equiped(object me, object obj, string pro)
{
	mixed *inv;
	string str;
	string subs;
	object hob;
	int i;
	int n;

	inv = all_inventory(obj);
	n = 0;

	str = "";
	subs = "";
	for (i = 0; i < sizeof(inv); i++)
	{
		if(!inv[i]->query("skill_type")&&inv[i]->query("armor_type")!="armor"&&inv[i]->query("armor_type")!="cloth")
		continue;
		switch (inv[i]->query("equipped"))
		{
		case "wielded":
			n++;
			subs = HIC "㊣" NOR + inv[i]->short() + "\n" + subs;
			break;

		case "worn":
			n++;
			subs += HIC "㊣" NOR + inv[i]->short() + "\n";
			break;

		default:
			break;
		}
	}

	if (n)
	str += pro + "装备着：\n" + subs;

	if (objectp(hob = obj->query_temp("handing")) &&
			(me == obj || obj->query_weight() > 200))
	{
		int mad;

		// dress nothing but handing a cloth !
		mad = (! objectp(obj->query_temp("armor/cloth")) &&
		hob->query("armor_type") == "cloth");

		str = pro + "手中" + (mad ? "却" : "" ) + "握着一" +
		(hob->query_amount() ? hob->query("base_unit")
		: hob->query("unit")) +
		hob->name() +
		(mad ? "，疯了，一定是疯了！\n" : "。\n") + str;
	}

	if (playerp(obj) &&! objectp(obj->query_temp("armor/cloth")))
	{
		str = pro + "身上没有穿衣服啊！\n" + str;
	}

	return str;
}

string description(object obj)
{
	if (playerp(obj))
	{
		int per;
		int age;
		per = obj->query_per();
		age = obj->query("age");
		if (obj->query("special_skill/youth")) age = 14;
		if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "无性")
		{
			if (obj->query("id")=="luoyun")
			return HIG"就是本游戏最帅的人，集容貌与才华为一身的千古才子。\n"NOR;	  
			if (per >=50)
			return HIG"现在一派神人气度，仙风道骨，举止出尘。\n"NOR;
			if (per <= 50 && (per > 40))
			return HIG"现在神清气爽，骨格清奇，宛若仙人。\n"NOR;
			if (per <= 40 && (per > 37))
			return HIG"现在丰神俊朗，长身玉立，宛如玉树临风。\n"NOR;
			if (per <= 37 && (per > 36))
			return HIG"现在飘逸出尘，潇洒绝伦。\n"NOR;
			if (per <= 36 && (per > 35))
			return HIG"现在面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
			if (per <= 35 && (per > 34))
			return HIG"现在丰神如玉，目似朗星，令人过目难忘。\n"NOR;
			if (per <= 34 && (per > 33))
			return HIY"现在粉面朱唇，身姿俊俏，举止风流无限。\n"NOR;
			if (per <= 33 && (per > 32))
			return HIY"现在双目如星，眉梢传情，所见者无不为之心动。\n"NOR;
			if (per <= 32 && (per > 31))
			return HIY"现在举动如行云游水，独蕴风情，吸引所有异性目光。\n"NOR;
			if (per <= 31 && (per > 30))
			return HIY"现在双眼光华莹润，透出摄人心魄的光芒。\n"NOR;
			if (per <= 30 && (per > 29))
			return HIY"生得英俊潇洒，风流倜傥。\n"NOR;
			if (per <= 29 && (per > 28))
			return MAG"生得目似点漆，高大挺俊，令人心动。\n"NOR;
			if (per <= 28 && (per > 27))
			return MAG"生得面若秋月，儒雅斯文，举止适度。\n"NOR;
			if (per <= 27 && (per > 26))
			return MAG"生得剑眉星目，英姿勃勃，仪表不凡。\n"NOR;
			if (per <= 26 && (per > 25))
			return MAG"生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。\n"NOR;
			if (per <= 25 && (per > 24))
			return MAG"生得眉如双剑，眼如明星，英挺出众。\n"NOR;
			if (per <= 24 && (per > 23))
			return CYN"生得虎背熊腰，壮健有力，英姿勃发。\n"NOR;
			if (per <= 23 && (per > 22))
			return CYN"生得肤色白皙，红唇墨发，斯文有礼。\n"NOR;
			if (per <= 22 && (per > 21))
			return CYN"生得浓眉大眼，高大挺拔，气宇轩昂。\n"NOR;
			if (per <= 21 && (per > 20))
			return CYN"生得鼻直口方，线条分明，显出刚毅性格。\n"NOR;
			if (per <= 20 && (per > 19))
			return CYN"生得眉目清秀，端正大方，一表人才。\n"NOR;
			if (per <= 19 && (per > 18))
			return YEL"生得腰圆背厚，面阔口方，骨格不凡。\n"NOR;
			if (per <= 18 && (per > 17))
			return YEL"生得相貌平平，不会给人留下什么印象。\n"NOR;
			if (per <= 17 && (per > 16))
			return YEL"生得膀大腰圆，满脸横肉，恶形恶相。\n"NOR;
			if (per <= 16 && (per > 15))
			return YEL"生得獐头鼠须，让人一看就不生好感。\n"NOR;
			if (per <= 15 && (per > 14))
			return YEL"生得面颊深陷，瘦如枯骨，让人要发恶梦。\n"NOR;
			if (per <= 14 && (per > 13))
			return RED"生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。\n"NOR;
			if (per <= 13 && (per > 12))
			return RED"生得贼眉鼠眼，身高三尺，宛若猴状。\n"NOR;
			if (per <= 12 && (per > 11))
			return RED"生得面如桔皮，头肿如猪，让人不想再看第二眼。\n"NOR;
			if (per <= 11 && (per > 10))
			return RED"生得呲牙咧嘴，黑如锅底，奇丑无比。\n"NOR;
			if (per <= 10)
			return RED"生得眉歪眼斜，瘌头癣脚，不象人样。\n"NOR;
			return "长得有点对不住别人。\n";
		}
		else
		{
			if (per >=40) 
			return HIW"现在宛如玉雕冰塑，似梦似幻，已不再是凡间人物。\n"NOR;
			if (per <= 39 && (per > 38))
			return HIG"现在美若天仙，不沾一丝烟尘。\n"NOR;
			if (per <= 38 && (per > 37))
			return  HIG"现在灿若明霞，宝润如玉，恍如神妃仙子。\n"NOR;
			if (per <= 37 && (per > 36))
			return HIG"现在气质美如兰，才华馥比山，令人见之忘俗。\n"NOR;
			if (per <= 36 && (per > 35))
			return HIG"现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。\n"NOR;
			if (per <= 35 && (per > 34))
			return HIG"现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。\n"NOR;
			if (per <= 34 && (per > 33))
			return HIY"现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。\n"NOR;
			if (per <= 33 && (per > 32))
			return HIY"现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。\n"NOR;
			if (per <= 32 && (per > 31))
			return HIY"现在眉目如画，肌肤胜雪，真可谓闭月羞花。\n"NOR;
			if (per <= 31 && (per > 30))
			return HIY"现在娇若春花，媚如秋月，真的能沉鱼落雁。。\n"NOR;
			if (per <= 30 && (per > 29))
			return HIY"生得闲静如姣花照水，行动似弱柳扶风，体态万千。\n"NOR;
			if (per <= 29 && (per > 28))
			return MAG"生得娇小玲珑，宛如飞燕再世，楚楚动人。\n"NOR;
			if (per <= 28 && (per > 27))
			return MAG"生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。\n"NOR;
			if (per <= 27 && (per > 26))
			return MAG"生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。\n"NOR;
			if (per <= 26 && (per > 25))
			return MAG"生得丰胸细腰，妖娆多姿，让人一看就心跳不已。\n"NOR;
			if (per <= 25 && (per > 24))
			return MAG"生得粉嫩白至，如芍药笼烟，雾里看花。\n"NOR;
			if (per <= 24 && (per > 23))
			return CYN"生得腮凝新荔，目若秋水，千娇百媚。\n"NOR;
			if (per <= 23 && (per > 22))
			return CYN"生得鲜艳妍媚，肌肤莹透，引人遐思。\n"NOR;
			if (per <= 22 && (per > 21))
			return CYN"生得巧笑嫣然，宛约可人。\n"NOR;
			if (per <= 21 && (per > 20))
			return CYN"生得如梨花带露，清新秀丽。\n"NOR;
			if (per <= 20 && (per > 19))
			return CYN"生得风姿楚楚，明丽动人。\n"NOR;
			if (per <= 19 && (per > 18))
			return YEL"生得肌肤微丰，雅淡温宛，清新可人。\n"NOR;
			if (per <= 18 && (per > 17))
			return YEL"生得虽不标致，倒也白净，有些动人之处。\n"NOR;
			if (per <= 17 && (per > 16))
			return YEL"生得身材瘦小，肌肤无光，两眼无神。\n"NOR;
			if (per <= 16 && (per > 15))
			return  YEL"生得干黄枯瘦，脸色腊黄，毫无女人味。\n"NOR;
			if (per <= 15 && (per > 14))
			return YEL"生得满脸疙瘩，皮色粗黑，丑陋不堪。\n"NOR;
			if (per <= 14 && (per > 13))
			return RED"生得一嘴大暴牙，让人一看就没好感。\n"NOR;
			if (per <= 13 && (per > 12))
			return RED"生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。\n"NOR;
			if (per <= 12 && (per > 11))
			return RED"生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。\n"NOR;
			if (per <= 11 && (per > 10))
			return RED"生得歪鼻斜眼，脸色灰败，直如鬼怪一般。\n"NOR;
			return "长得和无盐有点相似耶。\n";

		}
	} else
	if (! obj->query("can_speak") && living(obj))
	{
		if (! obj->query_temp("owner"))
		return "是一只未被驯服的畜生，眼光里满是戒心和敌意。\n";
		else
		return "是一只被" + obj->query_temp("owner_name") +
		"驯服的畜生，一副很温驯的样子。\n";
	}

	return "";
}

string desinq(object me,object obj)
{
	mapping inq;
	string tmpinq,str,*jiaoliu;
	int i;

	str = ZJOBACTS+ZJMENUF(1,4,10,32);

	if(obj->is_quester())
	{
		if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
		str += "江湖历练:ask "+obj->query("id")+" about 历练"ZJSEP; 
		str += "首席奖励:ask "+obj->query("id")+" about 首席奖励"ZJSEP; 
	}
	if(mapp(inq = obj->query("inquiry"))) 
	{
		jiaoliu = sort_array( keys(inq), (: strcmp :) );
		for(i=0; i<sizeof(jiaoliu); i++)
		{
			if(sscanf(jiaoliu[i],"#%*d-%s",tmpinq)!=2)
			tmpinq = jiaoliu[i];
			str += tmpinq+":ask "+obj->query("id")+" about "+jiaoliu[i]; 
			if(i<(sizeof(jiaoliu)-1)) str += ZJSEP;
		}
	}
	if(obj->query("id")=="nian shou")
	{
		str += "扔鞭炮:duobao"ZJSEP;
	}
	if(obj->is_knower())
	{
		if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
		str += "打听消息:ask "+obj->query("id")+" about 消息"; 
	}
	if(str==(ZJOBACTS+ZJMENUF(1,4,10,32))) str = "";
	return str+"\n";
}

string getact(object me,object obj)
{
	mapping inq;
	string str,*jiaoliu;
	int i;

	if(mapp(inq = obj->query("inquiry"))&&inq!=([])||obj->is_knower()||obj->is_quester()) 
	str = ZJOBACTS2+ZJMENUF(3,4,10,32);
	else
	str = ZJOBACTS2+ZJMENUF(4,4,10,32);

	if(obj->is_vendor())
	{
		str += "购物:list"ZJSEP; 
	}
	if(present("shua zi",me)&&present("xie you",me))
	{
		str += "擦鞋:caxie " + obj->query("id")+ZJSEP;
	}
	if(present("mian ju",me))
	{
		str += HIC"易容:pretend " + obj->query("id")+ZJSEP;
		str += HIC"取消易容:pretend none"NOR +ZJSEP;
	}
	if(me->query("p_master/id")==obj->query("id"))
	{
		str += "请安:learnto master " + file_name(obj)+ZJSEP;
	}
	if(obj->query("p_master/id")==me->query("id"))
	{
		str += "指点:learnto dizi " + file_name(obj)+ZJSEP;
	}

	

	//	if(obj->query("ridable"))
	//	{
	//		str += "骑上:ride " + obj->query("id")+ZJSEP;
	//	}
	if(obj->query("race")=="人类")
	{
		str += NOR"给予:give " + obj->query("id")+ZJSEP;
	}

	if (sizeof(obj->query_skills()) )
	{
		str += "查看技能:skills " + obj->query("id")+ZJSEP;
	}
	if(obj->query("family") && !userp(obj))
	{
		str += "拜师:bai " + obj->query("id")+ZJSEP;
	}

	if(obj->is_quester())
	{
		str += "领取任务:quest " + obj->query("id")+ZJSEP;
	}
	if (obj->query("id")==me->query("quest/master_id"))
	{
		str += "献首级:give head to "+ obj->query("id")+ZJSEP;
		str += "取消任务:quest cancel"+ZJSEP;
	}

	if(userp(obj))
	{
		str += "禁言:vote chblk " + file_name(obj)+ZJSEP;
		str += "组队:team with " + file_name(obj)+ZJSEP;
		str += HIC"私聊"NOR":bei2 " + obj->query("id")+ZJSEP;
	}
	if(me->query("family/family_name")=="唐门"&&me->query_skill_mapped("force") == "biyun-xinfa")
	str += HIC"碧云驱毒"NOR":exert force.jiedu " + file_name(obj)+ZJSEP;
	else
	str += HIC"解毒"NOR":exert dispel " + file_name(obj)+ZJSEP;

	if((me->query("family/family_name")=="欧阳世家"&&me->query_skill_mapped("force") == "hamagong")||(me->query("family/family_name")=="星宿派"&&me->query_skill_mapped("force") == "huagong-dafa"))
	str += HIC"弹射毒药"NOR":exert force.tan " + file_name(obj)+ZJSEP;

	str += "跟随:follow " + obj->query("id")+ZJSEP;
	if(userp(obj))
	{
		str += "查看装备:arm " + obj->query("id")+ZJSEP;
		str += "添加好友:friend -add " + obj->query("id")+ZJSEP;

	}

	if(obj->is_character())
	{
		str += HIR"行窃"NOR":steal " + obj->query("id")+ZJSEP;
	}
	if(obj && !environment(obj)->query("no_fight"))
	{
		str += HIR"比武切磋"NOR":fight " + obj->query("id")+ZJSEP;
		str += RED"突然袭击"NOR":touxi " + obj->query("id")+ZJSEP;
		str += RED"生死决斗"NOR":kill " + obj->query("id")+ZJSEP;
		str += HIM"幻兽攻击"NOR":attack " + obj->query("id")+ZJSEP;
	}
	if( wizardp(me)) 
	{ 
		str += "闪电秒杀:smash " + obj->query("id")+ZJSEP;
		str += "查看包裹:i " + obj->query("id")+ZJSEP;
		str += "查看状态:hp " + obj->query("id")+ZJSEP;
		str += "查看综合:score " + obj->query("id")+ZJSEP;
		str += "查看装备:arm " + obj->query("id")+ZJSEP;
		str += "更新数据:update " + obj->query("id")+ZJSEP;
		str += "复制武功:copyskill " + obj->query("id")+ZJSEP;
		str += HIM"显示资料"NOR":data " + obj->query("id")+ZJSEP;
		
	} 
	if(wizardp(me)&&playerp(obj))
	{
		str +=  HIY"恢复状态"NOR":full " + obj->query("id")+ZJSEP; 
		str += "到他身边:goto " + obj->query("id")+ZJSEP;
		str += "抓他过来:summon " + obj->query("id")+ZJSEP;
		
		str += "监听消息:snoop " + obj->query("id")+ZJSEP;
		str += "停止监听:snoop none"+ZJSEP;
		
		if(obj->query("chblk_on"))
		str += HIG"恢复频道"NOR":unchblk " + obj->query("id")+ZJSEP;
		else
		str += HIM"关闭频道"NOR":chblk " + obj->query("id")+ZJSEP;	
		
		str += "IP查询:sameip " + obj->query("id")+ZJSEP;
		
		str += HIR"踢出游戏"NOR":kickout " + obj->query("id")+ZJSEP;
		str += HIG"玩家回档"NOR":huidang " + obj->query("id")+ZJSEP;
		str +=  HIY"充值灵石"NOR":paym " + obj->query("id")+ZJSEP; 
		str +=  HIY"充值天机"NOR":GMCZtianji " + obj->query("id")+ZJSEP; 

	}
	return str+"\n";
}

int look_living(object me, object obj)
{
	int per;
	int spi;
	int age;
	int weight;
	string str, limb_status, pro, desc;
	mixed *inv;
	mapping my_fam, fam;
	int me_shen, obj_shen;
	obj_shen = (int)obj->query("shen");
	per = obj->query_per();
	age = obj->query("age");
	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	/*
	if (playerp(obj) && ! (obj->query("born")))
	{
		tell_object(me, pro + "还没有投胎，只有一股元神，什么都看不到耶！\n");
		return 1;
	}
*/
	me_shen = (int)me->query("shen");
	if (me != obj)
	{
		if (!wizardp(me)) {
			if (!obj->query("env/no_show")) 
			message("vision", me->name() + "正在上下打量着你。\n", obj);
			message("vision", me->name() + "正在上下打量着" + obj->name() + "。\n", environment(me), ({ me, obj }));
		}
	}
	if (wizardp(me) || !userp(obj) || environment(me) == environment(obj))
	str = ZJOBLONG+obj->short()+ZJBR+(!userp(obj) ? obj->long():"")+"\n";
	else
	str = ZJOBLONG+obj->query("title") + " "+obj->name()+"\n";
	//if obj no long
	//	if(obj->query("long")) str += obj->query("long");
	
	if(obj->query("banghui"))
	{
		str += obj->query("banghui/name")+obj->query("banghui/zhiwei")+"\n";
	}
	str += "一一一一一一一一一一一一一一一一一一一一一一一\n";
	if (me != obj && objectp(obj->query_temp("is_riding")))
	str += sprintf("%s正骑在%s上，低头看着你。\n", pro, obj->query_temp("is_riding")->name());

	if (obj->is_character() &&
			obj->query("can_speak"))
	{
		// 是人物角色
		if (age >= 25 && obj->query("special_skill/youth"))
		str += pro + "看不出年纪的大小，好像只有二十多岁\n";
		else
		{
			if (age >= 200)
			str += pro + "看起来年纪很大了，难以估计。\n";
			else
			if (age < 10)
			str += pro + "看起来年纪尚幼。\n";
			else
			str += pro + "看起来有" + chinese_number(age / 10 * 10) +
			"多岁。\n";
		}
		str += sprintf("%s的实力看来", pro);
		str +=gettof(obj);
		str +=sprintf("，");
		str +=sprintf("出手似乎");
		str +=getdam(me,obj);
		str +=sprintf("。\n");
	}

	desc = description(obj);
	if (desc && desc != "")
	str += pro + desc;

	//check about wife and husband
	if (obj->query("id")== me->query("couple/id"))
	{
		// 夫妻关系
		if ((string)me->query("gender") == "女性")
		str += sprintf("%s就是你的夫君。\n", pro);
		else
		str += sprintf("%s就是你的妻子。\n", pro);
	} else
	if (obj->is_brother(me))
	{
		// 兄弟
		if (obj->query("gender") == "女性")
		{
			if (obj->query("mud_age") > me->query("mud_age"))
			str += sprintf("%s是你的义姐。\n", pro);
			else
			str += sprintf("%s是你的结义妹子。\n", pro);
		} else
		{
			if (obj->query("mud_age") > me->query("mud_age"))
			str += sprintf("%s是你的结义兄长。\n", pro);
			else
			str += sprintf("%s是你的义弟。\n", pro);
		}
	} else
	if (obj != me && obj->query("league") &&
			obj->query("league/league_name") == me->query("league/league_name"))
	{
		str += sprintf("%s和你均是%s的同盟义士。\n", pro,
		obj->query("league/league_name"));
	}

	// If we both has family, check if we have any relations.
	if (obj != me &&
			mapp(fam = obj->query("family")) &&
			mapp(my_fam = me->query("family")) &&
			fam["family_name"] == my_fam["family_name"])
	{

		if (fam["generation"] == my_fam["generation"])
		{

			if ((string)obj->query("gender") == "男性" ||
					(string)obj->query("gender") == "无性")
			str += sprintf( pro + "是你的%s%s。\n",
			my_fam["master_id"] == fam["master_id"]? "": "同门",
			my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
			else
			str += sprintf( pro + "是你的%s%s。\n",
			my_fam["master_id"] == fam["master_id"]? "": "同门",
			my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
		} else
		if (fam["generation"] < my_fam["generation"])
		{
			if (my_fam["master_id"] == obj->query("id"))
			str += pro + "是你的师父。\n";
			else
			if (my_fam["generation"] - fam["generation"] > 1)
			str += pro + "是你的同门长辈。\n";
			else
			if (fam["enter_time"] < my_fam["enter_time"])
			str += pro + "是你的师伯。\n";
			else
			str += pro + "是你的师叔。\n";
		} else
		{
			if (fam["generation"] - my_fam["generation"] > 1)
			str += pro + "是你的同门晚辈。\n";
			else
			if (fam["master_id"] == me->query("id"))
			str += pro + "是你的弟子。\n";
			else
			str += pro + "是你的师侄。\n";
		}
	}

	if (obj->is_chatter())
	{
		message("vision", str, me);
		return 1;
	}

	if (stringp(obj->query_temp("eff_status_msg")))
	{
		str += obj->query_temp("eff_status_msg") + "\n";
	} else
	if (obj->query("max_qi"))
	str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if (obj->query_temp("daub/poison/remain") &&
			(me == obj || random((int)me->query_skill("poison", 1)) > 80))
	{
		str += pro + HIG "身上现在" + (me == obj ? "" : "似乎") +
		"淬了" + (me == obj ? obj->query_temp("daub/poison/name") : "毒") +
		NOR "。\n";
	}

	str += look_equiped(me, obj, pro);
	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
	str = str[0..(strlen(str)-5)];
	str += "\n";
	str += desinq(me,obj);
	str += getact(me,obj);
	message("vision", str+"\n", me);

	if (obj != me && living(obj) &&
			! me->is_brother(obj) &&
			me->query("couple/id") != obj->query("id") &&
			(me_shen < -1000 && obj_shen > 1000 ||
				me_shen > 1000  && obj_shen < -1000))
	{
		tell_object(me, obj->name() + "突然转过头来瞪你一眼。\n");
		if (obj->query("total_hatred") > 4 * obj->query_skill("force") &&
				! wizardp(obj) && ! wizardp(me))
		COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;
	string str,str1,str2,*strs;
	int i;

	str1 = "";
	str2 = "";
	if (! objectp(env = environment(me)))
	return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
	if (mapp(item = env->query("item_desc")) && !undefinedp(item[arg]))
	{
		if (stringp(item[arg]))
		str = item[arg];
		else if(functionp(item[arg]))
		str = (string)(*item[arg])(me);
		strs = explode(str,"\n");
		for(i=0;i<sizeof(strs);i++)
		{
			if(strlen(strs[i])>4&&(strs[i][0..3]==ZJOBACTS||strs[i][0..3]==ZJOBACTS2))
			str2 += strs[i]+"\n";
			else
			str1 += strs[i]+"\n";
		}
		str = replace_string(str1,"\n",ZJBR);
		if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
		str = str[0..(strlen(str)-5)];
		str += "\n"+str2+"\n";
		tell_object(me, ZJOBLONG+str);

		return 1;
	}
	if (mapp(exits = env->query("exits")) && ! undefinedp(exits[arg]))
	{
		if (objectp(env = find_object(exits[arg])))
		look_room(me, env, 0);
		else
		{
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]), 0);
		}
		return 1;
	}
	return notify_fail("你要看什么？\n");
}

string getdam(object me, object obj)
{

	int level;
	level = obj->query_temp("apply/damage") + obj->query("jiali");
	level = level / 30;
	if( level >= sizeof(heavy_level_desc) )
	level = sizeof(heavy_level_desc)-1;
	return heavy_level_desc[((int)level)];
}
int help(object me)
{
write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

这个指令让你查看你所在的环境、某件物品、生物、或是方向。如果
在look指令后面有参数，将先察看身上是否有该物品，如果没有则察
看你所在的环境中是否有该物品或人物。如果你身上的物品和你所在
的环境有ID相同的物品，你可以指明look ??? of me/here 以指明你
想要察看自己身上的物品还是附近环境中的物品。同时，如果使用命
令 look ??? of <id> 可以看他人的装备或是亮出来的物品。

HELP
);
	return 1;
}

