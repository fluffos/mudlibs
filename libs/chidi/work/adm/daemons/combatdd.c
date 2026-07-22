// combatd.c
#pragma save_binary
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_DBASE;
mapping prepare;
mapping limb_damage = ([
    // 人类身体部位
    "头部"  :   100,
    "颈部"  :   90,
    "胸口"  :   90,
    "后心"  :   80,
    "左肩"  :   50,
    "右肩"  :   55,
    "左臂"  :   40,
    "右臂"  :   45,
    "左手"  :   20,
    "右手"  :   30,
    "腰间"  :   60,
    "小腹"  :   70,
    "左腿"  :   40,
    "右腿"  :   50,
    "左脚"  :   35,
    "右脚"  :   40,
    //  动物身体部位
    "身体"  :   80,
    "前脚"  :   40,
    "后脚"  :   50,
    "腿部"  :   40,
    "尾巴"  :   10,
    "翅膀"  :   50,
    "爪子"  :   40,
]);

string *guard_msg = ({
    CYN "$N注视著$n的行动，企图寻找机会出手。\n" NOR,
    CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
    CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
    CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。\n" NOR,
    CYN "$N慢慢地移动著脚步，伺机出手。\n" NOR,
});
string *catch_hunt_msg = ({
    HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
    HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
    HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
    HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
    HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
    HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
    HIW "$N喝道：「$n，看招！」\n" NOR,});
string *winner_msg = ({
    CYN "\n$N哈哈大笑，愉快地说道：承让了！\n\n" NOR,
    CYN "\n$N双手一拱，笑著说道：知道我的利害了吧！\n\n" NOR,
    CYN "\n$N哈哈大笑，双手一拱，笑著说道：承让！\n\n" NOR,
    CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
    CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
    CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
    CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});
void create()
{
	seteuid(getuid());
	set("name", "战斗精灵");
	set("id", "combatd");
}
string damage_msg(int damage, string type,object ob)
{
	 string str;
    int qi=ob->query("qi");
    return (HIR"造成 " + damage + " 点" + type + "。\n"NOR);
    if( damage == 0 ) return "结果没有造成任何伤害。\n";
    if (qi>0&&qi<10000000){
        damage=damage*100;
        damage /= qi;
    }else
    if (qi>=10000000) damage /= (qi/100);
        damage=120;
	switch( type ) {
	case "擦伤":
	case "割伤":
		if( damage < 5 ) return "结果只是轻轻地划破$p的皮肉。\n";
		else if( damage < 10 ) return "结果在$p$l划出一道细长的"RED"血痕"NOR"。\n";
		else if( damage < 20 ) return "结果「嗤」地一声划出一道伤口！\n";
		else if( damage < 40 ) return "结果「嗤」地一声划出一道"RED"血淋淋"NOR"的伤口！\n";
		else if( damage < 80 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸"HIR"鲜血"NOR"！\n";
		else return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！\n";
		break;
	case "刺伤":
		if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
		else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
		else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
		else if( damage < 60 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
		else if( damage < 80 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的"RED"血窟窿"NOR"！\n";
		else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，"HIR"鲜血"NOR"溅得满地！\n";
		break;
	case "瘀伤":
		if( damage < 5 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
		else if( damage < 10 ) return "结果在$p的$l造成一处瘀青。\n";
		else if( damage < 25 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
		else if( damage < 40 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
		else if( damage < 50 ) return "结果「砰」地一声，$n退了两步！\n";
		else if( damage < 60 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
		else if( damage < 80 ) return "结果重重地击中，$n「哇」地一声吐出一口"HIR"鲜血"NOR"！\n";
		else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！\n";
		break;
	case "内伤":
		if( damage < 10 ) return "结果只是把$n打得退了半步，毫发无损。\n";
		else if( damage < 20 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
		else if( damage < 30 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
		else if( damage < 40 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
		else if( damage < 60 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
		else if( damage < 75 ) return "结果重重地击中，$n「哇」地一声吐出一口"HIR"鲜血"NOR"！\n";
		else if( damage < 90 ) return "结果「轰」地一声，$n全身气血倒流，口中"HIR"鲜血"NOR"狂喷而出！\n";
		else return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！\n";
		break;
	default:
		if( !type ) type = "伤害";
		if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
		else if( damage < 20 ) str = "结果造成轻微的";
		else if( damage < 30 ) str = "结果造成一处";
		else if( damage < 50 ) str = "结果造成一处严重";
		else if( damage < 60 ) str = "结果造成颇为严重的";
		else if( damage < 70 ) str = "结果造成相当严重的";
		else if( damage < 80 ) str = "结果造成十分严重的";
		else if( damage < 90 ) str = "结果造成极其严重的";
		else str =  "结果造成非常可怕的严重";
		return str + type + "！\n";
	}
}
string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
	if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
	if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
	if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
	if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
	if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
	if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
	if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
	return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}
string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
	if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
	if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
	if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
	if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
	if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
	if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
	return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

varargs void report_status(object ob, int effective)
{
    if( effective )
	{
		if((int)ob->query("max_qi") <= 100000)
		{
			message_vision( "( $N" + eff_status_msg(
				((int)ob->query("qi")*100) / (int)ob->query("max_qi") )
				+ " )\n", ob);
		}
		else
		{
			message_vision( "( $N" + eff_status_msg(
				(int)ob->query("qi") / ((int)ob->query("max_qi")/100) )
				+ " )\n", ob);
		}
	}
    else
	{
		if((int)ob->query("max_qi") <= 100000)
		{
			message_vision( "( $N" + status_msg(
				((int)ob->query("qi")*100) / (int)ob->query("max_qi") )
				+ " )\n", ob);
		}
		else
		{
			message_vision( "( $N" + status_msg(
				(int)ob->query("qi") / ((int)ob->query("max_qi")/100) ) 
				+ " )\n", ob);
		}
	}
}
varargs int skill_power(object ob, string skill, int usage,int baoji)
{
    int status, level, power,qi,jing,max_qi,max_jing, dj, djexp;
  
dj = ob->query_level();
if ( dj > 1 ) {
djexp=(50+(dj+1))*(50+(dj+1))*(50+(dj+1))*(50+(dj+1));
}
/*
else {
if ( ob->query("combat_exp")>500 )
     djexp=(int)ob->query("combat_exp")/500;
else
djexp=(int)ob->query("combat_exp");
}  
*/

    if( !living(ob) ) return 0;
    if (ob->over_encumbranced())    return 0;
    status=1;
    if (ob->query("max_qi")<1 || ob->query("max_jing")<1) return 1;

    else
	{
        qi=ob->query("eff_qi");
        if (qi > 800000000) qi=800000000;
        jing=ob->query("eff_jing");
        if (jing >800000000) jing=800000000;
        max_qi=ob->query("max_qi");
        if (max_qi > 800000000) max_qi=800000000;
        max_jing=ob->query("max_jing");
        if (max_jing >800000000) max_jing=800000000;

        status=qi*10/max_qi;
        status=status*jing*10/max_jing;
    }
    if (status<1)   return 1;
	
    level = ob->query_skill(skill)/150;
    switch(usage)
	{
        case SKILL_USAGE_ATTACK:
            level += ob->query_temp("apply/attack") + ob->query_temp("apply/attack1");
            if (ob->is_fighting())
                level +=  ob->query_temp("fight/attack");
            break;
        case SKILL_USAGE_DEFENSE:
            level += ob->query_temp("apply/defense") +ob->query_temp("apply/defense1");
            if (ob->is_fighting())
                level += ( ob->query_temp("fight/dodge")+ ob->query_temp("fight/parry"))/2;
            break;
    }
    if( !level || level<1)
{
          if ( dj > 1)
  {
	power= ob->query_str() + ob->query_con() + ob->query_int()+ ob->query_dex();
 }
        if (power>10000000)
 {
            power /= 100;
            power*=status;
 }      else
 {
            power *= status;
            power/=100;
  }
     //爆击
	if(baoji)
	{
		power*=2;
	}
	
  if(power > 1) return  power;
}
   //  power=level*10;
    if (usage == SKILL_USAGE_ATTACK)
	{
        if (skill=="unarmed")
			power+=(ob->query_str() + ob->query_temp("str")-ob->query("jiali"));
        else
			power+=(ob->query("str") + ob->query_temp("str")+ob->query_skill(skill,1)/10);
       
        }
    else
	{
        power+=(ob->query_dex()/3 + ob->query_temp("dex"));
	}

	power +=  (status*dj*1000+ob->query("combat_exp")/1000000);
    if (power>10000000)
	{
        power /= 100;
        power*=status;
    }
	else
	{
        power *= status;
        power/=100;
    }
    //爆击
    if(baoji)
    {
	power*=2;
    }
    
    if (level>300000 && power<0) return 1700000000;

    return power;
}


varargs int do1_attack(object me, object victim,object who)     //功城的执行
{
int myda,vda;
int one,two,three;
int ap,dp;
one=me->query("soilder");
two=victim->query("soilder");
three=victim->query("defendance");
message_vision("$N将手中长刀一挥。兵将蚁聚，涌至城边，一边架起云梯攀越城墙，一边掘土而进。\n",me);
message_vision("$N只见城墙上万箭齐飞，擂石并发，守得是雷打不动，水泼不进。\n",me);
ap=one*me->query("train_level");
dp=two*(victim->query("train_level")+three);
if((ap<=0)&&(dp>0))
{
message("vision",HIY+"【飞鸽传书】:"+NOR+HIC+me->query("name")+"对"+
victim->query("short")+"的进攻无功而返。"+who->query("name")+"守卫胜利.\n"NOR,users());
tell_object(who,"你保卫了城市，得到了一千点的战斗经验奖励。\n");
who->add("combat_exp",1000);
me->set("soilder",0);
me->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");        
victim->delete("receive_attack");
victim->save();
return 1;
}
if((ap>0)&&(dp<=0) )
{
message("vision",HIY+"【飞鸽传书】:"+NOR+HIC+me->query("name")+"攻占了"+
victim->query("short")+" ,"+who->query("name")+"守卫失利.\n"NOR,users());
victim->set("owner",me->query("id"));
victim->set("soilder",0);
victim->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");
victim->delete("receive_attack");
victim->save();
return 1;
}
if(ap < dp )
{
message_vision("$N的守势当真牢靠，在一阵激烈的肉搏之后，$n的攻势缓了下来。\n",who,me);
myda=(dp-ap)/1000;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"敌人拼命抵抗，你折损了:"+chinese_number(myda)+"名人马。\n");
me->add("soilder",-myda);
if((int)me->query("soilder")<0){me->set("soilder",0);me->set("train_level",0);}
tell_object(who,"敌人拼命进攻，你折损了:"+chinese_number(myda/2)+"名人马。\n");
victim->add("soilder",-myda/5);
if((int)victim->query("soilder")<0){victim->set("soilder",0);victim->set("train_level",0);}
}else
if(ap < 5*dp)
{
message_vision("$N的守势当真顽强，在一阵激烈的肉搏之后，$n还是拿不下来。\n",who,me);
myda=(ap-dp)*dp/(ap*1000);
vda=(ap-dp)*ap/(dp*1000);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"敌人拼命抵抗，你折损了:"+chinese_number(myda)+"名人马。\n");
me->add("soilder",-myda);
tell_object(who,"敌人拼命进攻，你折损了:"+chinese_number(vda)+"名人马。\n");
victim->add("soilder",-vda);
victim->add("defendance",-1);
if(victim->query("defendance")<0) victim->set("defendance",0);
}else 
{
message_vision("$N的守势虽然顽强，在一阵激烈的肉搏之后，$n还是渐渐占了优势。\n",who,me);
myda=(ap-dp)*dp/(ap*2000);
vda=(ap-dp)*ap/(dp*500);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;

tell_object(me,"敌人抵抗渐弱，你折损了:"+chinese_number(myda)+"名人马。\n");
me->add("soilder",-myda);
tell_object(who,"敌人拼命进攻，你折损了:"+chinese_number(vda)+"名人马。\n");
victim->add("soilder",-vda);
victim->add("defendance",-2);
if(victim->query("defendance")<0) victim->set("defendance",0);
}
}

string skill_info_color(string msg)
{
	string tmps1,tmps2,tmps3,result,color;

	if(!stringp(msg)) return "";

	switch(random(16))
	{
		case 0  : color = HIM; break;
		case 1  : color = RED; break;
		case 2  : color = GRN; break;
		case 3  : color = YEL; break;
		case 4  : color = BLU; break;
		case 5  : color = MAG; break;
		case 6  : color = CYN; break;
		case 7  : color = WHT; break;
		case 8  : color = HIR; break;
		case 9  : color = HIG; break;
		case 10 : color = HIY; break;
		case 11 : color = HIB; break;
		case 12 : color = HIM; break;
		case 13 : color = HIC; break;
		case 14 : color = HIW; break;
		case 15 : color = HBK; break;
	}   
        
	if(sscanf(msg,"%s「%s」%s",tmps1,tmps2,tmps3) == 3)
	{   
		//使用技能名
		result = sprintf("%15s%s%s%s%s\n","",BLINK,color,tmps2,NOR);
		//技能实际描述
		result = sprintf("%s%s%s「%s%s」%s"NOR,result,color,tmps1,tmps2,color,tmps3);
	}   
	else result = sprintf("%s%s"NOR,color,msg);
		
	if(result) return result;
	else return "";
}       
void send_equip_lasting(object me)
{
	int i,size;
	object *equip;

	if(random(100) > 3) return;

	equip = "/adm/daemons/energy"->get_all_equip(me);
	size = sizeof(equip);	

	for( i = 0; i < size; i ++ )
	{
		if(!equip[i]->query_xy()) continue;
		if(!equip[i]->query("weapon_prop") && random(100) > 35) continue;
		if(equip[i]->query("max_lasting") < 2 )
		{
			equip[i]->set("max_lasting",1);
			tell_object(me,sprintf(HIR"你的%s"HIR"(%s)耐久度不足,装备已经损坏。\n"NOR,equip[i]->name(),equip[i]->query("id")));
			equip[i]->unequip();
		}
		else equip[i]->add("max_lasting",-1);

		equip[i]->delete("long");
		equip[i]->init();
	}
}




varargs int do_attack(object me, object victim, object weapon, int attack_type,string msg)
{
	mapping my, your,action;
	string limb, *limbs,result,dodge_msg,parry_msg;
	string attack_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
    object shield;
	int vic_exp, me_exp;
	int ap, dp, pp;
	int damage, damage_bonus, defense_factor;
	int cost,rand,baoji;
	int wounded = 0;

	if(me->is_ghost())
	{ me->die(); return 1; } 
	if (!living(me)) return 1;
// npc不可战斗区 by lonely
	if(environment(me)->query("no_fight_npc")&&userp(me)&&!userp(victim)) 
		return 0;

	if (!victim || !me || victim && me && environment(me)!=environment(victim) )
		return 0;
//add by lonely for bug of find none 
	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();
	prepare = me->query_skill_prepare();
	vic_exp = victim->query("combat_exp");
	me_exp = me->query("combat_exp");
	if (!prepare) prepare = ([]);
	//
	// (0) Choose skills.
	//
	me->delete_temp("fight");
	victim->delete_temp("fight");

	if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
       else if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
       else if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];
       else if ( sizeof(prepare) == 0) attack_skill = "unarmed";
       else attack_skill = "unarmed";

	//
	// (1) Find out what action the offenser will take.
	//
	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) )
	{
		me->reset_action();
		action = me->query("action");
		if( !mapp(action) )
		{
			CHANNEL_D->do_channel( this_object(), "sys",
			    sprintf("%s(%s): bad action = %O",
				me->name(1), me->query("id"), me->query("actions", 1)));
			return 0;
		}
	}
	if (stringp(me->query_temp("action_msg")))
	{
		result = "\n" + (string)me->query_temp("action_msg")+ action["action"] + "！\n";
		me->delete_temp("action_msg");
	}
	else if (me->query_temp("action_flag") == 0)
		result = "\n" + action["action"] + "！\n";
	else
		result = "\n" + "紧跟着"+action["action"] + "!\n"; 

		if(random(100) < 20 && (me->query_skill(attack_skill)/1000) > 1)
	{
		switch(me->query_skill(attack_skill)/1000)
		{
			case 1 : result += "\n" + RED; break;
			case 2 : result += "\n" + YEL; break;
			case 3 : result += "\n" + BLU; break;
			case 4 : result += "\n" + MAG; break;
			case 5 : result += "\n" + CYN; break;
			case 6 : result += "\n" + HIR; break;
			case 7 : result += "\n" + HIG; break;
			case 8 : result += "\n" + HIY; break;
			case 9 : result += "\n" + HIB; break;
			case 10 : result += "\n" + HIM; break;
			case 11 : result += "\n" + HIC; break;
			default : result += "\n" + HIW; break;
		}

		switch(attack_skill)
		{
			case "force" :   result += me->query("name")+"内劲使出，内力犹如长江浪涛，源源不绝的涌向"+victim->name()+"\n"+victim->name()+"避无可避，出手招架，喀喇一声，臂骨立时震成了六七截，骨骼碎裂，内脏重创，鲜血狂吐。"+ NOR +"\n"; break;
			case "strike" :  result += me->query("name")+"挥手出掌，刚猛无比，凌厉无伦的掌力激荡而出，力道叠加，排山倒海的压向"+victim->name()+"。\n"+victim->name()+"避无可避，出手招架，喀喇一响，手骨应声断折，鲜血狂吐。"+ NOR +"\n"; break;
			case "finger" :  result += me->query("name")+"出指虚点,嗤嗤声响，凌空射出浑厚无比的劲力，意到即至，瞬间朝"+victim->name()+"袭去。\n"+victim->name()+"腾挪闪跃，竭力招架，始终脱不出"+me->query("name")+"的指力，身中数指，鲜血狂吐。"+ NOR +"\n"; break;
			case "claw" :    result += me->query("name")+"化掌为爪，夹杂内劲的五指嗤嗤声响，凌厉的抓向"+victim->name()+"\n"+victim->name()+"腾挪闪跃，竭力招架，始终躲不过"+me->query("name")+"的利爪，被抓出鲜血淋漓的窟窿。"+ NOR +"\n"; break;
			case "hand" :    result += me->query("name")+"五指分开而袭，快捷无伦，变化间带着浑厚的内力袭向"+victim->name()+"\n"+victim->name()+"腾挪闪跃，竭力招架，始终躲不过"+me->query("name")+"的袭击，中招吐血。"+ NOR +"\n"; break;
			case "array" :   result += me->query("name")+"使斧已俱臻炉火纯青之境，招数精奥，深得醇厚稳实之妙诣\n"+victim->name()+"避无可避，出手招架，喀喇一响，手骨应声断折，鲜血狂吐。"+ NOR +"\n"; break;
			case "sword" :   result += me->query("name")+"随手出剑，招式精妙，攻守兼备，夹杂锋利无匹的剑芒指向"+victim->name()+"的破绽所在。\n"+victim->name()+"腾挪闪跃，竭力招架，始终脱不出"+me->query("name")+"的剑光笼罩，顿时血花飞舞。"+ NOR +"\n"; break;
			case "blade" :   result += me->query("name")+"刀锋回转，凌厉狠辣，刚猛迅捷，刀锋势挟锋利无比的劲风劈向"+victim->name()+"。\n"+victim->name()+"腾挪闪跃，竭力招架，始终脱不出"+me->query("name")+"的刀芒笼罩，顿时血花四溅。"+ NOR +"\n"; break;
			case "pike" :    result += me->query("name")+"使枪突刺，捷如闪电，势若奔雷，枪头银光飞舞，带着浑厚内力刺向"+victim->name()+"。\n"+victim->name()+"腾挪闪跃，竭力招架，始终躲不过"+me->query("name")+"的枪刃，顿时血光四溅。"+ NOR +"\n"; break;
			case "cuff" :
			case "stick" :
			case "staff" :
			case "club" :    result += me->query("name")+"甩手出杖，奥妙无穷杖头未至，一股风已将"+victim->name()+"逼得难以喘气\n"+victim->name()+"腾挪闪跃，竭力招架，始终躲不过"+me->query("name")+"的杖影笼罩，中招吐血。"+ NOR +"\n"; break;
			case "hook" :    result += me->query("name")+"使钩疾伸，凌厉狠辣，捷如闪电，夹着锐利无比的利芒钩向"+victim->name()+"\n"+victim->name()+"腾挪闪跃，竭力招架，始终脱不出"+me->query("name")+"的钩影笼罩，顿时血花四溅。"+ NOR +"\n"; break;
			//case "dodge" :   dodge_msg = "轻功"; break;
			//case "parry" :   dodge_msg = "招架"; break;
			case "whip" :    result += me->query("name")+"使鞭一抖，劲道凌厉之极，犹如出水蛟龙，"+victim->name()+"难挡难避\n"+victim->name()+"腾挪闪跃，竭力招架，始终脱不出"+me->query("name")+"的鞭圈笼罩，身中数鞭，狂吐鲜血。"+ NOR +"\n"; break;
			case "hammer" :  result += me->query("name")+"使锤已俱臻炉火纯青之境，招数精奥，深得醇厚稳实之妙诣\n"+victim->name()+"避无可避，出手招架，喀喇一响，手骨应声断折，鲜血狂吐。"+ NOR +"\n"; break;
			case "axe" :     result += me->query("name")+"使斧已俱臻炉火纯青之境，招数精奥，深得醇厚稳实之妙诣\n"+victim->name()+"避无可避，出手招架，喀喇一响，手骨应声断折，鲜血狂吐。"+ NOR +"\n"; break;
			case "unarmed" : result += me->query("name")+"拳脚击出，力近千斤，夹带浑厚内力的拳风呼啸着涌向"+victim->name()+"。\n"+victim->name()+"腾挪闪跃，竭力招架，始终躲不过"+me->query("name")+"的劲力，身中数招，狂吐鲜血。"+ NOR +"\n"; break;
			default : result += me->query("name")+"眼中神光爆闪，招式中带出一股似有似无的力道，震向对方!"+ NOR +"\n"; break;
		}
	}
	
	if(victim->is_npc())
	{
	    	ap = me->query_level() + skill_power(me, attack_skill, SKILL_USAGE_ATTACK,1)*2;
	        damage = me->query_level()*10 + me->query_temp("apply/damage")+random(me->query_skill(attack_skill)/10);	
	}
	//对方是玩家
	else
	{
	    	ap = me->query_level() + skill_power(me, attack_skill, SKILL_USAGE_ATTACK,1);
	    	damage = me->query_level() + me->query_temp("apply/damage")+random(me->query_skill(attack_skill)/10);
	}

	//
	// (2) Prepare AP, DP for checking if hit.
	//
	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];

	// 以下可能在query_xxxx_msg中，加入招式的特殊防御,
	//比如,victim->set_temp("fight/dodge",100)
	// 因此,应该在计算前先进行调用
	dodge_skill = me->query_skill_mapped("dodge");
	if( !dodge_skill ) dodge_skill = "dodge";
	dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(limb,me);

	dodge_skill = victim->query_skill_mapped("dodge");
	if( !dodge_skill ) dodge_skill = "dodge";
	dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(limb,victim);    
	if (!dodge_msg || dodge_msg=="")
		dodge_msg = SKILL_D("dodge")->query_dodge_msg(limb,victim); 

	parry_skill = victim->query_skill_mapped("parry");
	if( !parry_skill ) parry_skill = "parry";
	parry_msg = SKILL_D(parry_skill)->query_parry_msg(victim,weapon);
	if (!parry_msg || parry_msg=="")
		parry_msg = SKILL_D("parry")->query_parry_msg(victim,weapon);

	// --------------------------------------------------------
	// 以下增加攻击招式的特殊攻防
	if (intp(action["dodge"]))
		victim->add_temp("fight/dodge", action["dodge"]/10);
	if (intp(action["parry"]))
		victim->add_temp("fight/dodge", action["parry"]/10);
	if (intp(action["attack"]))
		me->set_temp("fight/attack", action["attack"]/10);
	// ---------------------------------------------------------

	    //爆击
	rand = random(10000);
	if((baoji = me->query_temp("apply/baoji")) < 0)
	{
		me->delete_temp("apply/baoji");
	}
//    tell_object(find_player("rock"),sprintf("combat_d: rand: %d  baoji:%d  name:%s\n",rand,baoji,me->name()));
	//命中率
	if(victim->is_npc())
	{
	    if(rand < baoji)
	    {
	    	tell_object(environment(me), sprintf(HIR"%s『爆击』，尽数击向%s！！\n"NOR,me->name(),victim->name()));
	        damage = me->query_temp("apply/damage")*600;
	    }
	}
	//对手是玩家
	else
	{
	    if(rand < baoji)
	    {
	    	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK,1);
	    	tell_object(environment(me), sprintf(HIR"%s『爆击』，尽数击向%s！！\n"NOR,me->name(),victim->name()));
	        damage += me->query_level();
	    }
	}

    ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

	if (cost=sizeof(me->query_enemy())>1)
	{
		me->delete_temp("fighting");
		if (cost>6) cost=6;
		ap /= cost;
	}
	if( ap < 1) ap = 1;

	if( ap > 1700000000 ) ap = 1700000000;

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( victim->is_busy()) dp = dp/2;

	if (cost=sizeof(victim->query_enemy())>1)
	{
		victim->delete_temp("fighting");
		if (cost>6) cost=6;
		dp /= cost;
	}
	if (!victim->visible(me)) dp /= 5;

	if( dp < 1 ) dp = 1;
	if( dp > 1700000000 ) dp = 1700000000;

	cost=skill_power(me, "dodge", SKILL_USAGE_DEFENSE);
	if (cost<1) cost=1;
	if (ap>0 && cost>0 && (ap+cost)<0) cost=1700000000-ap;
	if (!me->visible(victim)) { ap /= 5; cost /= 5; }
	
	
	//
	// (3) Fight!
	//     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
	//     AP and DP are greater than zero, so we always have chance to hit
	//     or be hit.
	//

       // rewrite by lonely@yxcs to avoid exp increase by player fighting with player
        // 躲闪和招架不增加exp和pot
	if( random(ap + cost) < dp && living(victim) && living(me)) 
	{      // Does the victim dodge this hit?
		result += dodge_msg;
		if( ap+cost > dp&& !victim->query_temp("netdead") && random(your["jing"]*100/your["max_jing"] + victim->query_int()) > 60)
		{ if(vic_exp<900000000)
                  {
			if(vic_exp>100000000)
			{
				{
					victim->improve_skill("dodge", random(victim->query_int())/10);
				}
                              
			}
			else if(vic_exp>300000000)
			{
				{
					victim->improve_skill("dodge", random(victim->query_int())/20);
				}
			}
			else
			{
				victim->improve_skill("dodge", random(victim->query_int())/10);
			}       //  message_vision(CYN"$N"+CYN+"在实战中获得"+HIG+chinese_number(your["combat_exp"])+CYN+"点实战经验。\n"NOR,me);
		}
               }
		// This is for NPC only. NPC have chance to get exp when fail to hit.
		if( (ap < dp) && !userp(me) ) 
		{
			if( random(me->query_int()) > 15 ) my["combat_exp"] += me->query_int()/10;
			me->improve_skill(attack_skill, random(me->query_int()));
		}
		damage = RESULT_DODGE;
	}
	else
	{
		//
		//  (4) Check if the victim can parry this attack.
		//
		if (intp(action["parry"]))
			victim->add_temp("fight/parry", action["parry"]);

		pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);

		if( victim->is_busy()) pp = pp/2;


		if (sizeof(victim->query_enemy())>1)
		{
			pp-=pp*(sizeof(victim->query_enemy())/4);
		}
		if (!victim->visible(me)) pp /= 5;
		if( pp < 1 ) pp = 1;
		if( pp > 1700000000 ) pp = 1700000000;

		if( random(ap + cost)< pp ) 
		{
			result += parry_msg;
			if( (ap+cost) > pp && !victim->query_temp("netdead")&& random(your["jing"]*100/your["max_jing"] + victim->query_int()/2) > 30) 
			{   if(vic_exp<900000000)
                          {
				if(vic_exp>100000000)
				{
					{
						victim->improve_skill("parry", random(victim->query_int())/10);
					}
				}
				else if(vic_exp>300000000)
				{
					{
						victim->improve_skill("parry", random(victim->query_int())/20);
					}
				}
				else 
				{
					// your["combat_exp"] += victim->query_int()/2;
					victim->improve_skill("parry", random(victim->query_int())/10);
				}       // message_vision(CYN"$N"+CYN+"在实战中获得"+HIG+chinese_number(your["combat_exp"])+CYN+"点实战经验。\n"NOR,me);
                          }
			}
			damage = RESULT_PARRY;
		}
		else
		{
			//
			//  (5) We hit the victim and the victim failed to parry
			//
			if (weapon) damage = weapon->query("weapon_prop/damage");
			damage += me->query_temp("apply/damage");
			damage = (damage + random(damage)) / 2;
                        if( me->query_temp("secondary_weapon") )
				damage = damage * 2 / 3;
			if( action["damage"] )
				damage += action["damage"] * damage / 100;
			damage_bonus = me->query_str();
			// Let force skill take effect.
			if( my["jiali"] && (my["neili"] > my["jiali"]) )
			{
				if( stringp(martial_skill = me->query_skill_mapped("force")) )
				{
					foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
					if( stringp(foo) ) result += foo;
					else if( intp(foo) ) damage_bonus += foo;
				}
			}
			if( action["force"] )
				damage_bonus += action["force"] * damage_bonus / 100;
			if( stringp(martial_skill = me->query_skill_mapped(attack_skill)) ) {
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
			// Let weapon or monster have their special damage.
			if( weapon )
			{
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
			else
			{
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if( damage < 0 ) damage = 0;
			// Let combat exp take effect
			defense_factor = your["combat_exp"];
			while( random(defense_factor) > my["combat_exp"] )
			{
				damage -= damage / 3;
				defense_factor /= 2;
			}
			//
			//  (6) Inflict the damage.
			//
			if (!undefinedp(limb_damage[limb]))
				damage = (damage*limb_damage[limb]/100);

			dodge_skill = victim->query_skill_mapped("dodge");         
            if( dodge_skill && SKILL_D(dodge_skill)->is_special() )
			{   
				foo = SKILL_D(dodge_skill)->ob_hit_dodge(me, victim, damage);   
				if (stringp(foo)) result += foo;   
				else if (intp(foo)) damage = foo;   
				else if (mapp(foo))
				{
					result += (string)foo["result"];   
					damage = (int)foo["damage"];   
				}
			}
			if( stringp(martial_skill = victim->query_skill_mapped("force")) && (int)victim->query_temp("apply/armor_vs_force") )
			{
				foo = SKILL_D(martial_skill)->armor_ob(me, victim, damage,(int)victim->query_temp("apply/armor_vs_force"));
				if( stringp(foo) ) {result += foo;  damage=0;}
				else if( intp(foo) ) damage = foo;
			}
			// npc的特殊防御
			foo = victim->weapon_ob(victim,me, damage);
			if( stringp(foo) ) result += foo;
			else if(intp(foo) ) damage += foo;

//start 用于太极拳和乾坤大挪移等反震效果 Added by lonely
			if(stringp(parry_skill) && SKILL_D(parry_skill)->is_reinpose(victim, me))
				damage=SKILL_D(parry_skill)->reinpose(victim,me,damage); 
//end

//加入北冥和混元一气神功护体效果
			if(victim->query_skill("beiming-shengong", 1) > 400
				&& victim->query_skill_mapped("force") == "beiming-shengong"
				&& victim->query_temp("shield")
				&& victim->query("family/family_name")=="逍遥派"
				&& victim->query("neili")>5000
				&& random((int)victim->query_skill("force")*2/3)>(int)me->query_skill("force"))
			{
				message_vision(HIW"$N试图攻击$n，但与$n身体仆一接触，"
					+"只觉着力之处一滑，攻势全偏了去处。\n"NOR, me, victim);
				damage=damage-(int)victim->query_skill("beiming-shengong",1);
				victim->add("neili",-200);
				if(damage<0) damage=50;
			}

			if(victim->query_skill("xiantian-gong", 1) > 400
				&& victim->query_skill_mapped("force") == "xiantian-gong"
				//&& victim->query_temp("powerup/jingang")
				&& victim->query("family/family_name")=="全真教"   
				&& victim->query("neili")>1000
				&& random((int)victim->query_skill("force")*2/3)>(int)me->query_skill("force"))
			{
				message_vision(HIC"$N试图攻击$n，但是被$n的先天护体神功"
					+"挡住了。\n"NOR, me, victim);
				damage=damage-(int)victim->query_skill("xiantian-gong");
				victim->add("neili",-200);
				if(damage<0) damage=10;
			}

			if(victim->query_skill("buddhism-force", 1) > 600
				&& victim->query_skill_mapped("force") == "buddhism-force"
				&& victim->query_temp("protect")
				&& victim->query("family/family_name")=="少林寺"
				&& victim->query("neili")>5000
				&& random((int)victim->query_skill("force")*2/3)>(int)me->query_skill("force"))
			{
				message_vision(HIC"$N试图攻击$n，但是被$n的金刚不坏体神功"
				+"挡住了,没有造成任何伤害。\n"NOR, me, victim);
				damage=0;
				victim->add("neili",-200);
			}

			if(victim->query_skill("taixuan-gong", 1) > 400
				&& victim->query_skill_mapped("force") == "taixuan-gong"
				&& victim->query_temp("powerup")=="taixuan"
				&& !me->query_temp("weapon")
				&& random(victim->query_skill("force")) > me->query_skill("force")/2)
			{
				message_vision(result, me, victim,"fight");

				damage=random(damage/2);
				me->receive_damage( "qi", damage/2);
				me->receive_wound( "qi", damage/4);
				victim->add("neili",-100);
				if( damage < 100 )
					message_vision(HIR"$N受到$n太玄功护体神功反震，发出一声闷哼。\n"NOR,me,victim);
				else if( damage < 200 )
					message_vision(HIR"$N被$n太玄功护体神功反震，「嘿」地一声退了两步。\n"NOR,me,victim);
				else if( damage < 400 )
					message_vision(HIR"$N被$N太玄功护体神功一震，胸囗有如受到一记重锤，"
						+"连退了五六步。\n"NOR,me,victim);
				else message_vision(HIR"$N被$n太玄功护体神功一震，眼前一黑，身子如断线风筝"
						+"向後飞了出去。\n"NOR,me,victim);
				return 1;
			}
//ended

			result += damage_msg(damage, action["damage_type"],victim);
			damage = victim->receive_damage("qi", damage, me );

			if( random(damage) > (int)victim->query_temp("apply/armor")
			    && ( (me->is_killing(victim)) 
				&& ((!weapon) && !random(4) || weapon && !random(2) )
				|| ( (!weapon) && !random(7) || weapon && !random(4) ) )  )
			{
				// We are sure that damage is greater than victim's armor here.
				victim->receive_wound("qi",damage - (int)victim->query_temp("apply/armor"), me);
				wounded = 1;
			}

			if (me->query_temp("sum_power"))
				victim->receive_wound("qi", damage - (int)victim->query_temp("apply/armor"), me);

			if(me_exp<2000000000&&vic_exp+10000000 > me_exp)
                           {
                             int expup,potup;
                                  if(me->query("zhuanshi/times")<1)
                                  expup=200;
                                  else
                                  expup=100;                                  
	 		     if(me_exp<100000000)
				{ my["combat_exp"] += expup;
                                  if( my["potential"]  < me_exp/5 ) 
                                  { potup=expup/5;  
                                  }else potup=expup/2;
                                   my["potential"] += potup;   
				}
				else if(me_exp<300000000)
				{   expup=expup; 
                                    my["combat_exp"] += expup;   
                                  if( my["potential"]  < me_exp/5 ) 
                                  { potup=expup/2; 
                                  }else potup=expup/10  ;
                                   my["potential"] += potup;     
                                } 
				else if(me_exp<600000000)
				{   expup=expup; 
                                    my["combat_exp"] += expup;   
                                  if( my["potential"]  < me_exp/5 ) 
                                  { potup=expup/5; 
                                  }else potup=expup/2  ;
                                   my["potential"] += potup;                               
				}
				else if(me_exp<900000000)
				{   expup=expup; 
                                    my["combat_exp"] += expup;   
                                  if( my["potential"]  < me_exp/5 ) 
                                  { potup=expup/5; 
                                  }else potup=expup/10  ;
                                   my["potential"] += potup;   
                                } 
				else 
                                {   expup=random(expup); 			
	                            my["combat_exp"] += expup;
                                  if( my["potential"]  < me_exp/5 ) 
                                  { potup=expup/5; 
                                  }else potup=expup/2;
                                   my["potential"] += potup;    
                                }

                 tell_object(me, CYN"\n你在实战中获得"+HIG+chinese_number(expup)+NOR+CYN+"点实战经验和"+HIG+chinese_number(potup)+NOR+CYN+"点潜能。\n"NOR );
           //     message_vision(CYN"\n$N"+CYN+"在实战中获得"+HIG+chinese_number(expup)+NOR+CYN+"点实战经验和"+HIG+chinese_number(potup)+NOR+CYN+"点潜能。\n"NOR,me);
                             }                                 
				me->improve_skill(attack_skill, random(me->query_int()));
                           
				
			
		}
	} 
// add by lonely for set combatd
//武器 装备耐久度
    send_equip_lasting(me);

	if(msg)
	{
		msg += "\n"NOR;
		msg = replace_string( msg, "$l", limb );
		if( objectp(weapon) )
			msg = replace_string( msg, "$w", weapon->name() );
		else if( stringp(action["weapon"]) )
			msg = replace_string( msg, "$w", action["weapon"] );
		else if( attack_skill == "unarmed" ) 
			msg = replace_string( msg, "$w", HIW"无形劲气"NOR );      
		else if( attack_skill == "strike" )
			msg = replace_string( msg, "$w", HIW"无形掌力"NOR );
		else if( attack_skill == "finger" ) 
			msg = replace_string( msg, "$w", HIW"指间真气"NOR );
		else msg = replace_string( msg, "$w", HIC"无形杀气"NOR );

		message_combatd(msg, me, victim );
	}
	else
	{
		result = replace_string( result, "$l", limb );
		if( objectp(weapon) )
			result = replace_string( result, "$w", weapon->name() );
		else if( stringp(action["weapon"]) )
			result = replace_string( result, "$w", action["weapon"] );
		else if( attack_skill == "unarmed" ) 
			result = replace_string( result, "$w", HIW"无形劲气"NOR );      
		else if( attack_skill == "strike" )
			result = replace_string( result, "$w", HIW"无形掌力"NOR );
		else if( attack_skill == "finger" ) 
			result = replace_string( result, "$w", HIW"指间真气"NOR );
		else result = replace_string( result, "$w", HIC"无形杀气"NOR );

		message_combatd(result, me, victim );
	}
// the combatd is end

	
	//宠物伤害吸收
			if(me->query_temp("congwu/xishou"))
			{
				damage = (damage*me->query_temp("congwu/xishou"))/100;
			}
            result += damage_msg(damage, action["damage_type"],victim);
            damage = victim->receive_damage("qi", damage, me );

            if( random(damage) > (int)victim->query_temp("apply/armor")
            && ( (me->is_killing(victim)) 
                && ((!weapon) && !random(4) || weapon && !random(2) )
                || ( (!weapon) && !random(7) || weapon && !random(4) ) )  )
            {
            	//宠物伤害反射
            	if(me->query_temp("congwu/xishou"))
            	{
            		damage = (damage*me->query_temp("congwu/xishou"))/100;
            		me->receive_wound("qi",damage , victim);
            	}
                victim->receive_wound("qi",damage, me);
                wounded = 1;
            }
			if (me->query_temp("sum_power"))
			{
		//宠物伤害反射
            	if(me->query_temp("congwu/xishou"))
            	{
            		damage = (damage*me->query_temp("congwu/xishou"))/100;
            		me->receive_wound("qi", damage, victim);
            	}
                victim->receive_wound("qi", damage, me);
             }
			if(wizardp(me)) tell_object(me,sprintf( BOLD "my AP：%d，victim DP：%d，victim PP：%d，伤害力：%d\n" NOR,ap, dp, pp, damage));
	   
    
    
	
	if(wizardp(me) && me->query("env/combat"))
	{
		if( damage > 0 )
			tell_object(me, sprintf( BOLD "my AP：%d，victim DP：%d，victim PP：%d，伤害力：%d\n" NOR,
				ap+cost, dp, pp, damage));
		else
			tell_object(me, sprintf( BOLD "my AP：%d，victim DP：%d，victim PP：%d\n" NOR,
				ap+cost, dp, pp));
	}

	if( wizardp(victim) && victim->query("env/combat") )
	{
		if( damage > 0 )
			tell_object(victim, sprintf( BOLD "victim AP：%d，my DP：%d，my PP：%d，伤害力：%d\n" NOR,
				ap, dp, pp, damage));
		else
			tell_object(victim, sprintf( BOLD "victim AP：%d，my DP：%d，my PP：%d\n" NOR,
				ap, dp, pp));
	}
	

	if( damage > 0 )
	{
		report_status(victim, wounded);
		if( victim->is_busy() )
			victim->interrupt_me(me);
		if( (!me->is_killing(victim)) && 
		    (!victim->is_killing(me)) &&
			victim->query("qi")*2 <= victim->query("max_qi"))
		{
			//不打了，怒消失
			me->set("anger",0);
			victim->delete_temp("anger_attack");
			victim->set("anger",0);
			me->delete_temp("anger_attack");
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			tell_object(victim,HIR"你在战斗中积累的怒气开始平息！\n"NOR);
			tell_object(me,HIR"你在战斗中积累的怒气开始平息！\n"NOR);
			if (me->query("family/family_name")!="少林派"
			    && victim->query_temp("fighting")==me
			    && me->query("family/master_id")==(string)victim->query("id"))
			{
				me->delete("family");
				me->set("title","普通百姓");
				me->delete("class");
				victim->delete_temp("fighting");
				CHANNEL_D->do_channel(victim, "chat",
					sprintf("真不愧是青出于蓝而胜于蓝！%s，你可以出师了，从此另立门户吧！", me->name(1)));
			}
			else
				message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
		}
	}
	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);
	else
		WEAPON_D->bash_weapon(me, victim, weapon, damage);
	// See if the victim can make a riposte.
	if( attack_type==TYPE_REGULAR && damage < 1 && victim->query_temp("guarding") )
	{
		victim->set_temp("guarding", 0);
		if( random(my["dex"]) < 5 )
		{
			message_vision("$N一击不中，露出了破绽！\n", me);
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
		}
		else
		{
			message_vision("$N见$n攻击失误，趁机发动攻击！\n", victim, me);
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
		}
	}
}
//  fight()
//
//  This is called in the attack() defined in F_ATTACK, which handles fighting
//  in the heart_beat() of all livings. Be sure to optimize it carefully.
//
// rewrite for hubei of weapon by lonely@yxcs
void fight(object me, object victim)
{
    object ob,weapon1,weapon2;
    string skill_name,skill_p;
    mapping prepare;
    int i;
        if( !living(me) || me->is_busy() ) return;
        if (!me->visible(victim)) return;
        if (environment(me)!=environment(victim) ) return;
        //    if (userp(me) && environment(me)->query("freeze"))  return;

// If me have no weapon in hand,surely we should cancel the weapon 
// prepared skills.
    prepare = me->query_skill_prepare();       
    if( sizeof(prepare) > 0 && stringp(skill_p=(keys(prepare))[0]) )
    {
          if( !me->query_temp("weapon") && (skill_p == "sword" ||
              skill_p == "whip" || skill_p == "blade") )
          {
              for (i=0; i<sizeof(keys(prepare)); i++)
              me->prepare_skill((keys(prepare))[i]);
              tell_object(me,HIY"你现在采用"HIR"空手技能"HIY"进行攻击，"
             +"取消所备"HIR"兵器技能"HIY"攻击。\n"NOR);
          }
    }
 
	// If victim is busy or unconcious, always take the chance to make an attack.
	if( victim->is_busy() || !living(victim) )
	{
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		if ((random(me->query_int())>50 || random(10)<3) && victim->is_fighting(me))
		{
			me->set_temp("secondly_weapon",1);
			do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
			me->delete_temp("secondly_weapon");
		}
		else if( me->is_fighting(victim) && victim->is_fighting(me))
		{
			if(  objectp( weapon1=me->query_temp("weapon") )
				&& objectp( weapon2=me->query_temp("secondary_weapon") )
				&& sizeof( me->query_skill_prepare() ) > 1 
				&& stringp( me->query_skill_prepared(weapon1->query("skill_type")))
				&& stringp( me->query_skill_prepared(weapon2->query("skill_type"))))
			{
					me->set_temp("action_flag",1);
					do_attack(me, victim, weapon2, TYPE_QUICK);
					me->set_temp("action_flag",0);
			}
			else if( ( !objectp(me->query_temp("weapon") ) 
					&& sizeof(me->query_skill_prepare()) > 1)
				|| ( objectp(me->query_temp("weapon")) 
					&&(me->query_temp("weapon"))->query("skill_type") == "sword"
					&& me->query_skill("dugu-jiujian", 1) >= 400
					&& me->query_skill_mapped("sword") == "dugu-jiujian" )
				|| ( objectp(me->query_temp("weapon")) 
					&&(me->query_temp("weapon"))->query("skill_type") == "sword"
					&& me->query_skill("pixie-jian", 1) >= 60
					&& me->query_skill_mapped("sword") == "pixie-jian" ) )
            {
					me->set_temp("action_flag",1);
					do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
					me->set_temp("action_flag",0);
            }
        }

		if (living(victim))
		{
			if(  !objectp(ob=me->query_temp("weapon")))
				skill_name="unarmed";
			else skill_name=ob->query("skill_type");
			skill_name=me->query_skill_mapped(skill_name);

			if (stringp(skill_name))
			{
				me->set_temp("action_flag",1);
				SKILL_D(skill_name)->do_interlink(me, victim);
				me->set_temp("action_flag",0);
			}
		}
		// Else, see if we are brave enough to make an aggressive action.
	}
	else if( random( (int)victim->query_dex() * 2 ) < (int)me->query_dex() || random(10)<3)
	{
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);  
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
		if( me->is_fighting(victim) && victim->is_fighting(me))
		{
			if(  objectp( weapon1=me->query_temp("weapon") )
				&& objectp( weapon2=me->query_temp("secondary_weapon") )
				&& sizeof( me->query_skill_prepare() ) > 1 
				&& stringp( me->query_skill_prepared(weapon1->query("skill_type")))
				&& stringp( me->query_skill_prepared(weapon2->query("skill_type"))))
			{
                me->set_temp("action_flag",1);
                do_attack(me, victim, weapon2, TYPE_QUICK);
                me->set_temp("action_flag",0);
			}
			else if( (!objectp(me->query_temp("weapon")) 
				&& sizeof(me->query_skill_prepare()) > 1)
				|| ( objectp(me->query_temp("weapon")) 
				&&(me->query_temp("weapon"))->query("skill_type") == "sword"
				&& me->query_skill("dugu-jiujian", 1) >= 400
				&& me->query_skill_mapped("sword") == "dugu-jiujian" ) 
				|| ( objectp(me->query_temp("weapon")) 
				&&(me->query_temp("weapon"))->query("skill_type") == "sword"
				&& me->query_skill("pixie-jian", 1) >= 60
				&& me->query_skill_mapped("sword") == "pixie-jian" ) ) 
			{
				me->set_temp("action_flag",1);
				do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
				me->set_temp("action_flag",0);
			}
		}
		else if ((random(me->query_int())>50 || random(10)<2) && victim->is_fighting(me))
		{
            me->set_temp("secondly_weapon",1);
            do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
            me->delete_temp("secondly_weapon");
		}

		if(  !objectp(ob=me->query_temp("weapon")))
			skill_name="unarmed";
		else skill_name=ob->query("skill_type");

		skill_name=me->query_skill_mapped(skill_name);
		if (stringp(skill_name))
		{
            me->set_temp("action_flag",1);
            SKILL_D(skill_name)->do_interlink(me, victim);
            me->set_temp("action_flag",0);
		}
	}
	else if( !me->query_temp("guarding") ) 
    {
         me->set_temp("guarding", 1);
         message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
         return;
    }
	else return;
}

//  auto_fight()
//
//  This function is to start an automatically fight. Currently this is
//  used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;
	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_"+type ) ) return;
	me->set_temp("looking_for_"+type, 1);
	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
	me->set_temp("looking_for_hatred", 0);
	if (!me->query("demogorgon") && !obj->query("demogorgon")  )
		if( me->is_fighting(obj)                // Are we busy fighting?
		    ||  !living(me)                         // Are we capable for a fight?
		    ||  environment(me)!=environment(obj)   // Are we still in the same room?
		    ||  environment(me)->query("no_fight")  // Are we in a peace room?
		)   return;
		// We found our hatred! Charge!
	message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
	obj->fight_ob(me);
}
//取消帮派追杀
/*
// by lonely for bangpai
void start_vendetta(object me, object obj)
{
     string vendetta_mark;
	if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
	me->set_temp("looking_for_vendetta", 0);
	if( me->is_fighting(obj)                // Are we busy fighting?
	    ||  !living(me)                         // Are we capable for a fight?
	    ||  environment(me)!=environment(obj)   // Are we still in the same room?
	    ||  environment(me)->query("no_fight")  // Are we in a peace room?
//            || !(stringp(vendetta_mark = me->query("vendetta_mark"))&& obj->query("vendetta
//  /" + vendetta_mark)&&stringp(vendetta_mark = query("banghui")) )

	)   return;
	// We found our vendetta opponent! Charge!
      message_vision(HIC"$N怒道：帮主有令，见到$n格杀勿论！\n"NOR,me,obj);
        tell_object(obj,HIR "看起来" + me->name()+"想杀死你！\n" NOR);
        me->fight_ob(obj);
        obj->kill_ob(me);
}
*/
void start_adverse(object me, object obj)
{
        if( !me || !obj ) return;                              
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                        
// Are we busy fighting?         
     || !living(me) ||me->query_temp("disable_command")
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        ||      obj->query("combat_exp")<=10000000
// 保护新手
        )       return;
        if(userp(me)&&userp(obj)) return;
        // We found our hatred! Charge!
        message_vision(HIW"$N喝道：「$n，我们两派之间的恩恩怨怨该有个了断了！」\n" NOR,
me,obj);
        me->kill_ob(obj);
        obj->fight_ob(me);
}

// the end for bangpai
void start_wanted(object me, object obj)
{
        if( !me || !obj ) return;
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                        
// Are we busy fighting?         
     || !living(me) 
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        ||      me->query("combat_exp")<=10000000
// 经验太低不用自动杀叛师的人。以保护新手 
        )       return;
        message_vision( "$N对$n大喝一声：贼子，还不束手就擒！\n", me,obj);
        me->kill_ob(obj);
          obj->fight_ob(me);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
	me->set_temp("looking_for_aggressive", 0);
	if( me->is_fighting(obj)                // Are we busy fighting?
	    ||  !living(me)                         // Are we capable for a fight?
	    ||  environment(me)!=environment(obj)   // Are we still in the same room?
	    ||  environment(me)->query("no_fight")  // Are we in a peace room?
	)   return;
	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
	obj->fight_ob(me);
}
// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
	object *target;
	int i;
	switch(event) {
	case "dead":
		if(random(20) > 10)
			message_vision( NOR"\n$N扑在地上挣扎了几下，腿一伸，口中喷出几口"HIR"鲜血"NOR"，死了！\n\n" NOR, ob);
		else if(random(20)>10)
			message_vision( NOR"\n$N大叫一声倒在地上，挣扎了几下，"HIR"死了"NOR"！\n\n", ob);
		else message_vision( NOR"\n$N口中喷出几口"HIR"鲜血"NOR"，倒在地上,死了！\n\n", ob);
		break;
	case "unconcious":
		if(random(20) > 10)
			message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
		else message_vision("\n$N突然觉得头晕目眩，跌在地上不省人事了。\n\n", ob);
		break;
	case "revive":
		if(random(20) > 10)
			message_vision("\n$N慢慢睁开眼睛，清醒了过来。\n\n", ob);
		else message_vision("\n慢慢的,$N又恢复了神智。\n\n", ob);
		if (sizeof(target=ob->query_killer())>0)
			for (i=0;i<sizeof(target);i++){
				if (objectp(target[i]))
					if (present(target[i],environment(ob))){
						auto_fight(ob, target[i], "hatred");
						return;
					}
				break;
			}
	}
}
void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}
int die_for(object victim)
{
      object killer;
	if (!userp(victim)) return 0;
        
	victim->add("DIED",1);
        victim->add("int", -victim->query("wuxingdan"));
        victim->delete("wxdan", 1);
        victim->delete("wuxingdan", victim->query("wuxingdan"));
	victim->clear_condition();       
	// Give the death penalty to the dying user.
	victim->add("shen", -(int)victim->query("shen") / 10);
	victim->delete("vendetta");
        victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);

        // Give the death penalty to the dying user.
	if( victim->query("thief") )
		victim->set("thief", (int)victim->query("thief") / 2);
	if( (int)victim->query("potential") > 0)
		victim->add("potential",- (int)victim->query("potential")/4 );
	victim->skill_death_penalty();
	if (stringp(victim->query_temp("die_for"))){
		CHANNEL_D->do_channel(this_object(), "rumor",
		    sprintf("听说%s%s死了。", victim->name(1),victim->query_temp("die_for")));
		victim->delete_temp("die_for");
	}else
	{
		CHANNEL_D->do_channel(this_object(),"sys",victim->name(1)+"死于"+environment(victim)->query("short")+"("+file_name(environment(victim))+")\n");
		message("channel:rumor",HIW"\n〖江湖传闻〗: 听说"+victim->name(1)+"死了，而且死的很离奇！\n\n"NOR,users());
	}
}
void killer_reward(object killer, object victim)
{
    int bls,chousha;
    string vmark,killer_master_id,*die_msg,msg,*skills;
    mapping quest, actions,all_skills;
    object link_ob,money;   
    int exp, pot, score, bonus,factor,i,pktime;
    int chousha_exp, chousha_pot, chousha_score;   

    die_msg = ({"死的时候还面带微笑。","死状极其恐怖。","真是惨不忍睹啊！","哎,真是人生悲剧！","真是可怜！","大家默哀吧！","可悲，可叹啊！",});
   if (!killer)     return;
   //战斗结束，怒气消失
   killer->set("anger",0);
   victim->delete_temp("anger_attack");
   victim->set("anger",0);
   killer->delete_temp("anger_attack");
   tell_object(killer,HIR"你在战斗中积累的怒气开始平息！\n"NOR);
	killer->killed_enemy(victim);
	killer_master_id=killer->query("family/master_id");
	if (userp(killer) && (int)victim->query_condition("killer"))
	{
       killer->add("combat_exp",(int)victim->query("combat_exp")/1000);
	killer->add("score",(int)victim->query("score")/10);
       if(victim->query("combat_exp") > 500000){
			money = new("/clone/money/gold");
			money->set_amount((random(5)+1) * 100);
			money->move(killer);}
       message("channel:rumor",HIW"\n〖江湖传闻〗: 官府通缉犯"+victim->name()+"被"+killer->name()+"就地正法，"+killer->name()+"获得了应有的奖励！\n\n"NOR,users());
	killer->clear_condition("killer");	
       killer->delete_temp("pker_time");
	victim->clear_condition("killer");
       return;    
	}
	else if( userp(victim)) {
		if (wiz_level(killer)>1) return;
              if (userp(killer)&&(int)victim->query("age")<18) return;
//我这样保护新手,可能会被玩家用age<18岁的id 去pk超过１８岁的id,sigh,目前还没有想到好的办法 add by lonely
             if ( victim->is_att_killing(killer) ){
			victim->set_temp("die_for","活腻而被"+killer->query("name")+"杀");
                        die_for(victim);
                victim->delete_temp("last_damage_from");
			return;
		} else
		if (userp(killer))
		{
			killer->add("PKS", 1);
			victim->add("PKD",1);
		}
		victim->add("DIED",1);
        victim->add("int", -victim->query("wuxingdan"));
        victim->delete("wxdan", 1);
        victim->delete("wuxingdan", victim->query("wuxingdan"));
		victim->clear_condition();

		// Give the death penalty to the dying user.
		victim->add("shen", -(int)victim->query("shen") / 10);
              victim->delete("bellicosity");
		victim->delete("vendetta");
		if( victim->query("thief") )
		victim->set("thief", (int)victim->query("thief") / 2);
		//在updated.c调用鬼王做惩罚pker的杀手，惩罚杀人次数>3的pker //add by luoyun
             if (!userp(killer) && killer->query("id")=="demogorgon"){
	          all_skills=this_player()->query_skills();
                 skills=keys(all_skills);
                 pktime=(int)victim->query_temp("pker_time");
                 for(i=0;i<sizeof(skills);i++)                   
                     if (all_skills[skills[i]] > 1)	{		
			    victim->set_skill(skills[i],all_skills[skills[i]]-(1000));//全部技能减1000级
                     if (all_skills[skills[i]] < 0) //防止技能出现负数
                         victim->set_skill(skills[i],0);
                         victim->clear_condition("killer"); //取消追杀
                         victim->delete_temp("pker_time");  //取消追杀
                     if( (int)victim->query("max_neili") > 0 )//惩罚降内力
                             victim->add("max_neili", - (int)victim->query("max_neili")/10);
                     if ((int)victim->query("max_jingli") > 0)//惩罚降精力
                             victim->add("max_jingli", -(int)victim->query("max_jingli")/20); 
                     if( (int)victim->query("potential") > 0)//惩罚降潜能
                              victim->add("potential", - (int)victim->query("potential")/2 );
                     if ((int)victim->query("combat_exp") > 0)//惩罚降经验
                              victim->add("combat_exp", -(int)victim->query("combat_exp")/5);
                     if ((int)victim->query("card_potential") > 0)//惩罚降银行卡潜能
                              victim->add("card_potential", -(int)victim->query("card_potential")/10);                                     
                              }
                else{  if( (int)victim->query("potential") > 0)
                              victim->add("potential", - (int)victim->query("potential")/2 );
                              victim->add("combat_exp", -(int)victim->query("combat_exp") / 5);
			}
              }else if(userp(killer)) {
                 if((int)victim->query("age")<18 ) return;
                       victim->skill_death_penalty();
                       victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);
                        if( (int)victim->query("potential") > 0)
                       victim->add("potential", - (int)victim->query("potential")/4 );
              }
   else {
                  victim->skill_death_penalty();
                  victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);
                      if( (int)victim->query("potential") > 0)
                  victim->add("potential", - (int)victim->query("potential")/4 );
		}


		bls = 10;
		if(objectp(killer))
		{
			   if(environment(killer)&&environment(killer)->query("short"))
			   msg = "在"+environment(killer)->query("short");
			   else msg = "在一个不为人知的地方";
			msg="被"+killer->name();
			actions = killer->query("actions");
			switch(actions["damage_type"]) {
			case "擦伤":
			case "割伤":
				msg+=HIM"用武器砍死了。";
				break;
			case "刺伤":
				msg+=HIM"用利器刺死了。";
				break;
			case "瘀伤":
				msg+=HIM"用掌力击毙了。";
				break;
			case "内伤":
				msg+=HIM"用掌力震死了。";
				break;
			default:
				msg+=HIM"杀害了。";
			}
                        msg+=die_msg[random(7)];

     if(victim->query_temp("chousha/fam")
      && killer->query("family/family_name")==victim->query_temp("chousha/fam"))
     {
      msg+=HIR"\n"+victim->query("name")+NOR
      +HIB"在此次仇杀中绥难，自动退出此次江湖仇杀！\n";
      victim->delete_temp("chousha");
     }

                message("channel:rumor",HIM"\n〖江湖传闻〗: 听说"
                        +victim->name(1)+msg+"\n"NOR,users());
                }

		if (killer_master_id==(string)victim->query("id")) 
			CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s将自己的师傅%s杀死了,真是惨无人道啊。", killer->name(0),victim->name(1)));
		else	
			CHANNEL_D->do_channel(this_object(), "rumor",
			    sprintf("听说%s"+msg, victim->name(1)));

	
       if (userp(killer) && !chousha && killer != victim
        && (killer->query_temp("invaded_usrs/"+(string)victim->query("id"))
            || !victim->query_temp("invaded_usrs/"+(string)killer->query("id")))) 
       {
       write_file("/log/static/KILL_PLAYER",sprintf("%s(%s) killed by %s(%s) on %s\n",
       victim->name(1), victim->query("id"),
       killer->name(1),killer->query("id"),ctime(time()) ));
       //UPDATE_D->check_user(killer);//更新这个玩家，如果是杀人犯就会派杀手追杀
       if ((killer->query_temp("pker_starttime")+3600*killer->query_temp("pker_time")) < killer->query("mud_age"))
       {
                killer->set_temp("pker_starttime",killer->query("mud_age"));
                killer->delete_temp("pker_time");
       }
       killer->add_temp("pker_time",1); 
       if(!victim->query_condition("killer")&&!(victim->is_att_killing(killer)))
       CHANNEL_D->do_channel(this_object(), "rumor",
                                sprintf("官府开始捉拿%s,并奖励将杀人犯就地正法之江湖好汉。", killer->name(0)));
     victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);       }
    } else 
    {
        killer->add("MKS", 1);
        bls = 1;
    }

	if (killer_master_id==(string)victim->query("id") && !userp(victim)) 
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s将自己的师傅%s杀死了,真是惨无人道啊。", killer->name(0),victim->name(1)));
	if (!killer->is_ghost())
		killer->add("shen", -(int)victim->query("shen") / 10);
          if (userp(victim) && userp(killer)&&!victim->query_condition("killer"))
		killer->apply_condition("killer", 1000);

	exp=killer->query("combat_exp");
	if (exp<200000 && exp<victim->query("combat_exp")){
		exp+=random(exp/10);
		killer->set("combat_exp", exp);
	}
	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);
	if( killer->query("family/master_id")==(string)victim->query("id")) {
		if ( victim->query_temp("fighting")==killer){
			killer->delete("family");
			killer->set("title","普通百姓");
			killer->delete("class");
			victim->delete_temp("fighting");
			CHANNEL_D->do_channel(victim, "chat",
			    sprintf("真不愧是青出于蓝而胜于蓝！%s，你可以出师了，从此另立门户吧！", killer->name(1)));
		}else   if (killer->query("class") == "bonze" && victim->query("class") == "bonze"){
			killer->set("kill_bonze",time());
			killer->delete("family");
			if (link_ob=killer->query_temp("link_ob"))
				killer->set("name",link_ob->query("name"));
			killer->set("title","普通百姓");
			killer->delete("class");
			CHANNEL_D->do_channel(victim, "chat",
			    sprintf("%s，你谋害自己的师傅，为我佛门所不容，你走吧！", killer->name(1)));
		}           
	}
// 下面是杀人任务 
        if (userp(victim))
        {
                return;
        }
            if( interactive(killer) && (quest = killer->query("quest"))
                && ( (int)killer->query("task_time") >= time())
                &&(quest["quest"]==victim->query("name")))
        {
                tell_object(killer,"恭喜你！你又完成了一项任务！\n");
                exp = quest["exp_bonus"]*20 + random(quest["exp_bonus"]*20);
                pot = quest["pot_bonus"]*20 + random(quest["pot_bonus"]*20);
                score = quest["score"]*20 + random(quest["score"]*20);
                factor=victim->query("quest_factor");
                if (factor)
                {
                        exp=exp*factor*10;
                        pot=pot*factor*10;
                        score=score*factor*10;
                }
               if( exp > 30000) exp = 30000;
               if( pot > 15000) pot = 15000;
                bonus = (int) killer->query("combat_exp");
                bonus += exp;
                killer->set("combat_exp", bonus);
                bonus = (int) killer->query("potential");
             // bonus = bonus - (int) killer->query("learned_points");
                bonus = bonus + pot;
                bonus += (int)killer->query("potential");
                killer->set("potential", bonus );
                bonus = (int)killer->query("shen");
                if(bonus >= 0)
                        bonus += score;
                else
                        bonus -= score;
                killer->set("shen", bonus);
                killer->add("score",score);
                tell_object(killer,HIW"你被奖励了：" +
                chinese_number(exp) + "点实战经验，"+
                chinese_number(pot) + "点潜能，" +
                chinese_number(score)+"点江湖阅历。\n" NOR);
                killer->set("quest", 0 );
        }
}


