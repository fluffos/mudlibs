// score.c
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□□□□□□□□□";
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);


void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob, obt;
        string hymsg;
	mapping my;
	string line, str, skill_type,zs,zs1,zs2;
	object weapon;
        int attack_points, dodge_points, parry_points, btmp, t, d, r,money,i,zs3,zs4,money2;
        int a,b,c,hylv;
	seteuid(getuid(me));
        btmp=1;
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
                obt = find_player(arg);
                if ( !obt ) btmp=0;
                if (!ob) ob = obt;
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");
        my = ob->query_entire_dbase();

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
	if( ob->query("mud_age") > 86400){
	t = ob->query("t");
	d = ob->query("d");
	r = ob->query("r");
	}
write("$score\n"NOR);
write(""+ob->short(1)+"\n");
write("【年岁】"+chinese_number(ob->query("age"))+"岁"+chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200 + 1 )+"月"+"\n");
write("【生日】"+CHINESE_D->chinese_date((ob->query("birthday") - 14*365*24*60) * 60-890000000)+"\n");
write("【性别】"+ob->query("gender")+"\n");
 if( ob->query("couple/couple_name") ){
write("【伴侣】"+ob->query("couple/couple_name")+"\n");
	}
else write("【伴侣】"+"无\n");
	if( mapp(my["family"]) ) {
		if( my["family"]["master_name"] ){
write("【师傅】"+my["family"]["master_name"]+"\n");
		}
else write("【师傅】"+"无\n");
	}
if( mapp(my["family"]) ) {
		if( my["family"]["family_name"] ){
write("【师门】"+my["family"]["family_name"]+"");
if (ob->query_condition("psgc")>0)
write("【""师门追杀""】"+chinese_number(ob->query_condition("psgc"))+"");
write("【师门贡献】"+chinese_number(my["mpgx"])+"\n");
		}
else write("【师门】"+"无\n");
}
       
zs="无";
zs1="无";
zs2="";
if (ob->query("zhuanshen"))
zs="一转";
if (ob->query("zhuanbest"))
zs="二转";
if (ob->query("4zhuan"))
zs="三转";
if (ob->query("5zhuan"))
zs="终转";
if (ob->query("zhuanfinal/7"))
zs1="【阴阳十二重天】";
if (ob->query("zhuanfinal/8"))
zs1=zs1+" 【不败神功】";
if (ob->query("zhuanfinal/1"))
zs2="【元气无穷】";
if (ob->query("zhuanfinal/2"))
zs2=zs2+" 【遁影擒踪】";
if (ob->query("zhuanfinal/3"))
zs2=zs2+" 【神魔金身】";
if (ob->query("zhuanfinal/4"))
zs2=zs2+" 【缚骨缠身】";
if (ob->query("zhuanfinal/5"))
zs2=zs2+" 【破元大法】";
if (ob->query("zhuanfinal/6"))
zs2=zs2+" 【国士无双】";
zs3=6000000+(ob->query("expmax",1)*500000);
zs4=ob->query_temp("menpaijob",1);
write("【转生】"+zs+"");
if (!ob->query("4zhuan"))
{
write("\n");


}
if (ob->query("4zhuan"))
{
write("【连续任务】"+zs4+"");write("【武功上限】"+zs3+"\n");
write("【转生技能】"+zs2+"\n");
//write("【忙乱时间】"+ob->query_busy()+"\n");

}
a=ob->query_temp("apply/damage");

if (userp(ob) && ob->query("str") && ob->query("age") >=18)
	{
		
		hylv=ob->query("age",1);
		if (hylv >30) hylv=30;
		c= ob->query("str",1)*hylv;
		if (c>3000) c=3000;
	a += c;
	}
	
b=ob->query_temp("apply/armor");
if (userp(ob) && ob->query("dex")  && ob->query("age") >=18)
	{
		
		hylv=ob->query("age",1);
		if (hylv >30) hylv=30;
		c= ob->query("dex",1)*hylv;
		if (c>3000) c=3000;
	b += c;
	}
	

write("【臂力】"+display_attr(my["str"], ob->query_str())+"("+ob->query("str")+")"+"【武器攻击】"+"(+"+a+")\n");
write("【悟性】"+display_attr(my["int"], ob->query_int())+"("+ob->query("int")+")"+"【防具防御】"+"(+"+b+")\n");
write("【根骨】"+display_attr(my["con"], ob->query_con())+"("+ob->query("con")+")"+"【杀死人数】"+chinese_number(my["MKS"] + my["PKS"])+"\n");
write("【身法】"+display_attr(my["dex"], ob->query_dex())+"("+ob->query("dex")+")"+"【杀玩家数】"+chinese_number(my["PKS"])+"\n");
if (wizardp(me)  || me->query("hyvip") || 1==1)
{
write("【福缘】"+display_attr(my["kar"], ob->query_kar())+"("+ob->query("kar")+")"+"【死亡次数】"+chinese_number(my["dietimes"])+"\n");
}
else write("【福缘】"+"???"+"【死亡次数】"+chinese_number(my["dietimes"])+"\n");
if (wizardp(me) || me->query("hyvip")  || 1==1)
{
write("【容貌】"+display_attr(my["per"], ob->query_per())+"("+ob->query("per")+")"+"【离奇死亡】"+chinese_number(my["dietimes"] - my["mal_die"])+"\n");
} else write("【容貌】"+"???"+"【离奇死亡】"+chinese_number(my["dietimes"] - my["mal_die"])+"\n");
write("【精神】"+my["jing"]+"/"+my["max_jing"] + "【判师次数】"+chinese_number(ob->query("betrayer"))+"\n");
write("【气血】"+my["qi"]+"/"+my["max_qi"] + "【风度魅力】"+chinese_number(ob->query("meili"))+"\n");
write("【饮水】"+my["water"]+"/"+ob->max_water_capacity() + "【江湖威望】"+chinese_number(ob->query("weiwang"))+"\n");
write("【食物】"+my["food"]+"/"+ob->max_food_capacity() + "【江湖阅历】"+ob->query("score")+"\n");
write("【攻击】"+"/cmds/std/looksj.c"->getatt(ob,1)+" ");
write("【防御】"+"/cmds/std/looksj.c"->getdef(ob,1)+" ");
write("【躲闪】"+"/cmds/std/looksj.c"->getdog(ob,1)+"\n");
if (wizardp(me))write("【攻击力】"+attack_points/100 + 1+"(+"+ob->query_temp("apply/damage")+")\n");
if (wizardp(me))write("【防御力】"+(dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1+"(+"+ob->query_temp("apply/armor")+")\n");
write("【侠义正气】"+ob->query("shen")+"\n");
write("【学习潜力】"+(ob->query("potential") - ob->query("learned_points"))+"\n");
write("【实战经验】"+ob->query("combat_exp")+"\n");
        if( ob->query("killbyname") && ob->query("killbyname")!="死因不明"){
write("【上次死因】"+"被"+ob->query("killbyname")+"杀死\n");
	}
        if( ob->query("killbyname") && ob->query("killbyname")=="死因不明"){
write("【上次死因】"+"死因不明\n");
	}
	if (ob->query("age")==14) money = 1000;
	if (ob->query("age")>14) money = 1000 + (ob->query("age")-15) * 20;
	if (ob->query("age")>20) money = 2000 + (ob->query("age")-20) * 20;
	if (ob->query("age")>30) money = 4000 + (ob->query("age")-30) * 30;
	if (ob->query("age")>40) money = 8000 + (ob->query("age")-40) * 40;
		
	money2=(int)ob->query("balance",1);
if (money2> 10000)
{
money2=money2/10000;	
write("【当前存款】"+money2+"两黄金"+"\n");	
}
else
{
write("【当前存款】"+money2+"文铜钱"+"\n");		
}

write("【存款上限】"+money+"两黄金"+"\n");
        if( !ob->query("killbyname")){
write("【上次死因】"+"无\n");
	}
if (me->query_temp("apply/strength") > 1800)
me->set_temp("apply/strength",1800);
if (me->query_temp("apply/intelligence") > 1800)
me->set_temp("apply/intelligence",1800);
if (me->query_temp("apply/constitution") > 1800)
me->set_temp("apply/constitution",1800);
if (me->query_temp("apply/dexerity") > 1800)
me->set_temp("apply/dexerity",1800);
if (me->query_temp("apply/attack") > 1800)
me->set_temp("apply/attack",1800);
if (me->query_temp("apply/defense") > 1800)
me->set("apply/defense",1800);
if (me->query_temp("apply/damage") > 18000)
me->set_temp("apply/damage",18000);
if (me->query_temp("apply/armor") > 18500)
me->set_temp("apply/armor",18500);
if (me->query_temp("apply/dodge") > 1800)
me->set_temp("apply/dodge",1800);

hylv   = (int)ob->query("hyvip"); 
if (hylv==0) hymsg="一般玩家";
if (hylv==1) hymsg="初级会员";
if (hylv==2) hymsg="中级会员";
if (hylv==3) hymsg="高级会员";		 
if (hylv==4) hymsg="骨灰会员";
 
write("【会员等级】"+hymsg+"\n");
if ((int)ob->query("hyday")>=1000000)
{
write("【会员天数】"+"终身会员 \n");
if (wizardp(ob)) write("【剩余天数】"+chinese_number(ob->query("hyday"))+"\n");	
}
else
{
write("【会员天数】"+chinese_number(ob->query("hyday"))+"\n");	
}	
write("【海洋币数】"+chinese_number(ob->query("hymoney"))+"\n");


if ( (int)ob->query_condition("killer" ) > 0)
write("【通缉追杀】 尚在\n");
else
write("【通缉追杀】 无有\n");

if ( (int)ob->query_condition("psgc" ) > 0)
write("【判师追杀】 尚在\n");
else
write("【判师追杀】 无有\n");

if ( (int)ob->query_condition("bonze_drug" ) > 0 || (int)ob->query_condition("putizi_drug" ) > 0 || (int)ob->query_condition("medicine" ) > 0)
write("【药物药性】 尚在\n");
else
write("【药物药性】 无有\n");
write("$#\n");
	return 1;
        
}
string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf(  "%3d" , value );
	else if( value < gift ) return sprintf( CYN "%3d" , value );
	else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return "";
	if( percent >= 90 ) return "";
	if( percent >= 60 ) return "";
	if( percent >= 30 ) return "";
	if( percent >= 10 ) return "";
	return "";
}

int help(object me)
{
	write(@HELP
指令格式 : score
           score <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的基本资料。
基本资料的设定请参阅 'help setup'。

see also : hp
HELP
    );
    return 1;
}
