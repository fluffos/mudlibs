// Create by smallfish

#include <ansi.h>
#include <combat.h>
#include <net/dns.h>


inherit F_CLEAN_UP;
string bar_string = "■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□";
string blank_string3 = "□□□□□□□□□□□□";
string blank_string2 = "　　　　　　　　　　　　";

string age_string(int time)
{
        int month, day, hour, min, sec;
        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "月":"") + (day?day + "天":"") +
        (hour?hour + "小时":"") + min + "分";
}

int color_len(string str)
{
        int i;
        int extra;

        extra = 0;
        for (i = 0; i < strlen(str); i++)
        {
                if (str[i] == ESC[0])
                {
                        while ((extra++, str[i] < 'A' ||
                                         str[i] > 'z' ||
                                         str[i] > 'Z' && str[i] < 'a') && i < strlen(str))
                                i++;
                }
        }
        return extra;
}



mapping oprank = ([
        "宗师"     : HIW "★★★★★",
        "登峰造极" : HIY "★★★★☆",
        "超凡脱俗" : HIY "★★★★  ",
        "臻至化境" : HIR "★★★☆  ",
        "炉火纯青" : HIR "★★★    ",
        "已有大成" : HIC "★★☆    ",
        "非同凡响" : HIC "★★      ",
        "出类拔萃" : HIG "★☆      ",
        "身手不凡" : HIG "★        ",
        "已有小成" : HIM "☆        ",
]);

string display_attr(int gift, int value);
string status_color(int current, int max);
string tribar_graph(int val, int eff, int max, string color);
string tribar_graph2(int val, int eff, int max, string color);
string tribar_graph3(int a);
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob;
        mapping my,mci;
        string line , skill_type,zs,zs1,zs2;
        string hymsg;
        object weapon;
        int jings, qis, j, i, need, lv;
        mixed attack_points, dodge_points, parry_points, btmp,  money,zs3,zs4,money2;
        string jbd, msg;
        int a,b,c,hylv;
        int can_score = 0;
        int age, month;
//        string idx;
        int exp;
        int lvl, level;
        string startroom = "";
        object the_room = 0;

        seteuid(getuid(me));
btmp=1;
if (me->query_temp("nbjob2",1) < 3 || !me->query_temp("nbjob2")) me->add_temp("nbjob2",1);
if (me->query_temp("nbjob2",1)>3) me->set_temp("nbjob2",3);
        if(! arg)
                ob = me;
        else
                ob = present(arg, environment(me));

        if (! ob) ob = find_player(arg);
        if (! ob) ob = find_living(arg);
        if (! ob || ! me->visible(ob)) return notify_fail("你要察看谁的状态？\n");

        if (wizardp(me) || ob == me) 
                can_score = 1;
        else 
        //if (ob->is_pet() && ob->query("owner") == me->query("id")) 
        //        can_score = 1;
        //els/ 
        if (me->query("couple/couple_id") == ob->query("id"))
                can_score = 1;
        else 
        if (stringp(startroom = ob->query("startroom")) &&
            objectp(the_room = load_object(startroom)) &&
            the_room->query("room_owner_id") == me->query("id"))
                can_score = 0;
        if (! can_score)
                return notify_fail("只有巫师能察看别人的状态。\n");

        my = ob->query_entire_dbase();



       if (userp(ob) )
{
exp = (int)ob->query("combat_exp", 1);
level = (int)ob->query("levels", 1);
if (! level || level < 1) 
{
ob->set("levels", 1);
	level = 1;	
}
//tell_object(ob, level);
if (exp> 10000)
{
for (i = level; ;i++) {
if ((i + 1) * (i + 1) * (i + 1) > (exp / 1000))
   {
                                        lvl = i;
                                        break;
   }
}

                
                        if (lvl > level)
                        {
                                j = lvl - level;
                                ob->set("levels", lvl);
                                ob->add("combat_exp", 10000 * j);
                                ob->add("potential", 8000 * j);
                                ob->add("max_neili", 100 * j);
                                if (exp> 600000)  
{
	                        ob->add("mpgx", 10 * j);
                                tell_object(ob, HIY "只见一道红光飞进你的体内，你的人物等级提升了"+j+"级！\n" +
                                        "此次升级，你获得了" + chinese_number(10000 * j) +
                                        "点经验、" + chinese_number(8000 * j) +
                                        "点潜能、" + chinese_number(100 * j) +
                                        "点内力上限和" + chinese_number(10 * j) +
                                        "点门派贡献！\n" NOR);
}
else
{
                                tell_object(ob, HIY "只见一道红光飞进你的体内，你的人物等级提升了"+j+"级！\n" +
                                        "此次升级，你获得了" + chinese_number(10000 * j) +
                                        "点经验、" + chinese_number(8000 * j) +
                                        "点潜能、" + chinese_number(100 * j) +
                                        "点内力上限！\n" NOR);

}
                        return notify_fail(HIR"你的等级提升了"+j+"级。\n"NOR);
                        }
                lv=(int)ob->query("levels", 1);
                need = (lv + 1) * (lv + 1) * (lv + 1) * 1000 - exp;
                if (need < 1) need = 1;

}	       
}
	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
        
        mci = my["combat"];
        if (! mci) mci = ([ ]);
        
//        if (userp(ob) && (! stringp(my["born"]) || ! my["born"])) 
//                return notify_fail("还没有出生呐，察看什么？\n"); 

        jings = (my["eff_jing"] * 12 / my["max_jing"]) * 2;
        qis = (my["eff_qi"] * 12 / my["max_qi"]) * 2;
        
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
zs1=zs1+"【不败神功】";
if (ob->query("zhuanfinal/1"))
zs2="【元气无穷】";
if (ob->query("zhuanfinal/2"))
zs2=zs2+"【遁影擒踪】";
if (ob->query("zhuanfinal/3"))
zs2=zs2+"【神魔金身】";
if (ob->query("zhuanfinal/4"))
zs2=zs2+"【缚骨缠身】";
if (ob->query("zhuanfinal/5"))
zs2=zs2+"【破元大法】";
if (ob->query("zhuanfinal/6"))
zs2=zs2+"【国士无双】";
zs3=6000000+(ob->query("expmax",1)*500000);
if ( ob->query("5zhuan")) 
zs3=5000000+(ob->query("expmax",1)*200000);

zs4=ob->query_temp("menpaijob",1);        
        // line = sprintf("                          【" + MUD_NAME + "】个人档案                      \n\n", ob->query("language"),);
//if (me->query_temp("xmud")) write("$score");
        line = sprintf( BOLD "\n%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
        // ob->update_age();
        
        line += sprintf( YEL "┏━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━┓\n" NOR );

        if (userp(ob))
        {
                age = ob->query("age");
                month = ob->query("mud_age");
                if (age >= 60)
                {
                        month -= (age - 60) * 86400 * 4;
                        month = (month - 118 * 86400) / 7200 / 4 + 1;
                } else
                if (age >= 30)
                {
                        month -= (age - 30) * 86400 * 3;
                        month = (month - 28 * 86400) / 7200 / 3 + 1;
                } else
                if (age >= 18)
                {
                        month -= (age - 18) * 86400 * 2;
                        month = (month - 4 * 86400) / 7200 / 2 + 1;
                } else
                {
                        month -= (age - 14) * 86400;
                        month = month / 7200 + 1;
                }

                // not show invalid month
                if (month > 12 || month < 1)
                        month = 1;

                line += sprintf( YEL "┃" HIY "【年龄】" NOR "%-24s  " YEL "  ┃" NOR ,
                        chinese_number(ob->query("age"))+"岁"+chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200 + 1 )+"月");
        } else
                line += sprintf( YEL "┃" HIY "【年龄】" NOR "%-24s  " YEL "  ┃" NOR , 
                        chinese_number(ob->query("age"))+"岁"+chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200 + 1 )+"月"); 
                



        line += sprintf( HIW "【战斗攻击力】" NOR " %10d" YEL " ┃\n" NOR ,
                attack_points/100 + 1);

        line += sprintf( YEL "┃" HIY "【性别】" NOR "%-26.8s" YEL "  ┃" NOR ,
                    ob->query("gender")+ob->query("race"));

                                  
        line += sprintf( HIW "【战斗防御力】" NOR " %10d" YEL " ┃\n" NOR ,
                (dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1);

        line += sprintf( YEL "┃" HIY "【转生】" NOR "%-28.28s" YEL "┃" NOR ,
                zs );
a=ob->query_temp("apply/damage");

if (userp(ob) && ob->query("str") && ob->query("age") >=18)
	{
		
		hylv=ob->query("age",1);
		if (hylv >30) hylv=30;
		c= ob->query("str",1)*hylv;
		if (c>3000) c=3000;
	a += c;
	}

        line += sprintf( HIW "【战斗伤害力】" NOR " %10d" YEL " ┃\n" NOR ,
                weapon ? a
                               : a);

        line += sprintf( YEL "┃" HIY "【生辰】" MAG "%-28.28s" NOR+YEL "┃" NOR ,
                CHINESE_D->chinese_date(ob->query("birthday")));
b=ob->query_temp("apply/armor");
if (userp(ob) && ob->query("dex")  && ob->query("age") >=18)
	{
		
		hylv=ob->query("age",1);
		if (hylv >30) hylv=30;
		c= ob->query("dex",1)*hylv;
		if (c>3000) c=3000;
	b += c;
	}
        line += sprintf( HIW "【战斗保护力】" NOR " %10d" YEL " ┃\n" NOR ,
                b);

        line += sprintf( YEL "┃                          ┏━━━━┻━━━━━━━━━━━━━┫\n" NOR,);      
        if (mapp(my["family"]))
        {
                if( my["family"]["family_name"] )
                        line += sprintf( YEL "┃" HIG "【门派】" NOR "%-18.8s" YEL "┃" NOR,
                                my["family"]["family_name"] );
                else  
                        line += sprintf( YEL "┃" HIG "【门派】" NOR "普通百姓          " YEL "┃" NOR );
        }
        else  
                line += sprintf( YEL "┃" HIG "【门派】" NOR "普通百姓          " YEL "┃" NOR );
        line += sprintf( HIY "【膂力】" HIW "%2d |%3d   " HIY "【悟性】" HIW "%2d |%3d" NOR+YEL "   ┃\n" NOR , 
                ob->query("str"),
                ob->query_str(),
                ob->query("int"), 
                ob->query_int());

        if (mapp(my["family"]))
        {
                if( my["family"]["master_name"] )
                        line += sprintf( YEL "┃" HIG "【师承】" NOR "%-18.18s" YEL "┃" NOR,
                                my["family"]["master_name"] );
                else
                        line += sprintf( YEL "┃" HIG "【师承】" NOR "你还没有拜师      " YEL "┃" NOR );
        }
        else  
                line += sprintf( YEL "┃" HIG "【师承】" NOR "你还没有拜师      " YEL "┃" NOR );
        line += sprintf( HIY "【根骨】" HIW "%2d |%3d   " HIY "【身法】" HIW "%2d |%3d" NOR+YEL "   ┃\n" NOR , 
                ob->query("con"),           
                ob->query_con(),
                ob->query("dex"), 
                ob->query_dex());

        if (! ob->query("home"))
                line += sprintf(YEL "┃" HIG "【住宅】" NOR "%-18.8s" , "流浪街头");
        else
                line += sprintf(YEL "┃" HIG "【住宅】" NOR "%-18.8s" , ob->query("home/home_name") );
        line += sprintf( YEL "┃" HIY "【福缘】" HIW "%2d |%3d   " HIY "【容貌】" HIW "%2d |%3d" NOR YEL "   ┃\n" NOR ,                 ob->query("kar"),           
                ob->query_kar(),
                ob->query("per"), 
                ob->query_per());


        //line += sprintf( YEL "┃" HIG "【门贡】" NOR "%-18.18s", chinese_number(my["mpgx"]));
        line += sprintf( YEL "┃" HIG "【等级】" NOR "%-18.18s", chinese_number(my["levels"]));
        line += sprintf( YEL "┃" HIC "【拳脚】" NOR "%s" HIC "【兵器】" NOR "%s" NOR YEL "┃\n" NOR,HIY+"/cmds/std/looksj.c"->getatt2(ob,1)+NOR+"  ",HIY+"/cmds/std/looksj.c"->getatt3(ob,1)+NOR+"  "); 
        //line += sprintf( YEL "┃" HIG "【连续】" NOR "%-18.18s", chinese_number(zs4));
        line += sprintf( YEL "┃" HIG "【门贡】" NOR "%-18.18s", chinese_number(my["mpgx"]));
        line += sprintf( YEL "┃" HIC "【内功】" NOR "%s" HIC "【轻功】" NOR "%s" NOR YEL "┃\n" NOR,HIY+"/cmds/std/looksj.c"->getdef(ob,1)+NOR+"  ",HIY+"/cmds/std/looksj.c"->getdog(ob,1)+NOR+"  "); 
        /*
        if (ob->query("is_vendor"))
                line += sprintf(YEL "┃" HIG "【职业】" NOR "商人              " );
        else
                line += sprintf(YEL "┃" HIG "【职业】" NOR "无                " );
        */
        line += sprintf(YEL "┃" HIG "【魅力】" NOR "%-10d        ", ob->query("meili"));
        line += sprintf( YEL "┃" HIY "【经验】" HIW "%-10d" HIY "【潜能】" NOR "%s%-10d" NOR YEL "┃\n" NOR ,my["combat_exp"],(int)ob->query("potential")>=(int)ob->query_potential_limit()?HIM:HIW,(int)ob->query("potential") - (int)ob->query("learned_points") );
        line += sprintf( YEL "┃" HIG "【威望】" NOR "%-18d" YEL "┃" NOR, ob->query("weiwang") );
        line += sprintf( HIY "【%s】" HIW "%-10d" HIY "【阅历】" HIW "%-10d" NOR YEL "┃\n" NOR ,(ob->query("shen")>=0)?"正气":"邪气",ob->query("shen"),ob->query("score") );

        
        if (mapp(my["couple"]))
        {
c=0;
if (ob->is_busy() && !ob->query_temp("pending/exercise")) c=ob->query_busy();

                line += sprintf(YEL "┃" HIW "【婚姻】" NOR "%-18.8s" , my["couple"]["couple_name"] ? "结婚" : "丧偶");
                line += sprintf(YEL "┃" HIY "【判师】" NOR HIW "%-10d" NOR HIY "【忙乱】"NOR HIW "%-10d" NOR YEL "┃\n" NOR ,ob->query("betrayer")?ob->query("betrayer"):0,c );
                if (my["couple"]["couple_name"])
                {
                        line += sprintf(YEL "┃" HIW "【%s】" NOR "%-18s" YEL "┗━━━━━━━━━━━━━━━━━━┫\n" NOR , "伴侣",my["couple"]["couple_name"] + "(" + my["couple"]["couple_id"]  + ")");
                } else
                {
                        line += sprintf(YEL "┃" HIW "【伴侣】" NOR "%-18.8s" YEL "┗━━━━━━━━━━━━━━━━━━┫\n" NOR , "没有");
                }                       
                line += sprintf(YEL "┃" HIW "【子女】" NOR "%-56s" NOR YEL "┃\n", my["child"] ? "已有" : "没有");
        }
        else
        { 
c=0;
if (ob->is_busy() && !ob->query_temp("pending/exercise")) c=ob->query_busy();

                line += sprintf( YEL "┃" HIW "【婚姻】" NOR "单身              " );
                line += sprintf( YEL "┃" HIY "【判师】" NOR HIW "%-10d" NOR HIY "【忙乱】"NOR HIW "%-10d" NOR YEL "┃\n" NOR ,ob->query("betrayer")?ob->query("betrayer"):0,c);
                line += sprintf( YEL "┃" HIW "【伴侣】" NOR "没有              " YEL "┗━━━━━━━━━━━━━━━━━━┫\n" NOR );
                line += sprintf( YEL "┃" HIW "【子女】" NOR "%-56s" NOR YEL "┃\n", "没有" );
        }

        if (my["gender"] == "无性")
                line += sprintf( YEL "┃" HIW "【两性】" NOR "%-56s" NOR YEL "┃\n","太监" );
        else if (! ob->query("makeloved"))
        {
                if (my["gender"] == "女性")
                        line += sprintf( YEL "┃" HIW "【两性】" NOR "%-56s" NOR YEL "┃\n","处女" );
                else
                        line += sprintf( YEL "┃" HIW "【两性】" NOR "%-56s" NOR YEL "┃\n","童男" );
        }
        line += sprintf(YEL "┃" HIW "【侍者】" NOR "%-56s" NOR YEL "┃\n", mapp(ob->query("guard/active")) ? "拥有" : "没有");

        line += sprintf(YEL "┃" HIW "【坐骑】" NOR "%-56s" NOR YEL "┃\n", mapp(ob->query("marks/pet")) ? "拥有" : "没有");
        if (ob->query("age")==14) money = 1000;
	if (ob->query("age")>14) money = 1000 + (ob->query("age")-15) * 20;
	if (ob->query("age")>20) money = 2000 + (ob->query("age")-20) * 20;
	if (ob->query("age")>30) money = 4000 + (ob->query("age")-30) * 30;
	if (ob->query("age")>40) money = 8000 + (ob->query("age")-40) * 40;
		
	money2=(int)ob->query("balance",1);
        if (! ob->query("balance"))
                line += sprintf( YEL "┃" HIY "【钱庄】" HIY "没有积蓄                                                " NOR+YEL "┃\n" NOR );
        else
        {
                line += sprintf ( YEL "┃"  HIY "【钱庄】" NOR );
                line += sprintf (HIY"%-56.56s"NOR,
                MONEY_D->money_str(ob->query("balance")));


//                line += sprintf (HIY"%-56.56s"NOR,
//                chinese_number(money)+"两黄金");

                line += sprintf ( NOR+YEL "┃\n" NOR );
        }
                if (! ob->query("balance"))
                line += sprintf( YEL "┃" HIY "【存款】" HIY "没有积蓄                                                " NOR+YEL "┃\n" NOR );
        else
        {
                line += sprintf ( YEL "┃"  HIY "【上限】" NOR );
                line += sprintf (HIY"%-56.56s"NOR,
                chinese_number(money)+"两黄金");
                line += sprintf ( NOR+YEL "┃\n" NOR );
        }
        
        
if (ob->query_temp("temp_exp"))
{
if (ob->query("mud_age") - ob->query_temp("mud_age") > 1)
{
if (ob->query("combat_exp") > ob->query_temp("temp_exp"))
{
if ((i = (ob->query("combat_exp") - ob->query_temp("temp_exp")) * 60
/ (ob->query("mud_age") - ob->query_temp("mud_age"))) > 100)
i = i*60;

}
}
}        
if (i<0) i=0;
if (i>300000)
{
		i=300000;
		ob->set_temp("mud_age",ob->query("mud_age"));
              }
              if (wizardp(me)) 
              line += sprintf ( YEL "┃"  HIY "【速度】" NOR );
                if (wizardp(me)) line += sprintf (HIY"%-56.56s"NOR,
                chinese_number(i)+"/小时");
                if (wizardp(me)) line += sprintf ( NOR+YEL "┃\n" NOR );

        
        //line += sprintf( YEL "┃                                                                ┃\n" NOR );
        
        /*
        msg = "";
        if (ultrap(ob))
                msg = " 你已经成为大宗师";
        if (ob->query("breakup"))
                msg += "、打通任督二脉";
        if (ob->query("animaout"))
                msg += "、修成元婴出世";
        if (ob->query("tianmo_jieti/times"))
                msg += "、天魔解体" + chinese_number((int)ob->query("tianmo_jieti/times")) + "次";

        if (msg != "")
        {       
                msg += "。";
                line += sprintf( YEL "┃" NOR HIC "%-64s" NOR YEL "┃\n" NOR, msg );
                line += sprintf( YEL "┃                                                                ┃\n" NOR );
        }
        */
        if( my["max_jing"] >= my["eff_jing"])
                line += sprintf( YEL "┃" HIC" 精  "NOR"：%-24s   ", tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"])) + tribar_graph3(jings));
        else
                line += sprintf( YEL "┃" HIC" 精  "NOR"：%-24s   " , tribar_graph2(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"]))+ tribar_graph3(jings));

        if( my["max_jingli"] > 0 )
                line += sprintf( HIC "精力"NOR"：%-24s"+ NOR+YEL+"┃\n"NOR, tribar_graph(my["jingli"], my["max_jingli"], my["max_jingli"], status_color(my["jingli"], my["max_jingli"])));
        else
                line += sprintf( HIC "精力"NOR "：" HIG "%-24s"+ NOR+YEL+"┃\n"NOR, blank_string );

        if( my["max_qi"] >= my["eff_qi"])
                line += sprintf( YEL "┃" HIC" 气  "NOR"：%-24s   ", tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));
        else    
                line += sprintf( YEL "┃" HIC" 气  "NOR"：%-24s   ", tribar_graph2(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));

        if( my["max_neili"] > 0 )
                line += sprintf( HIC "内力"NOR"：%-24s"+ NOR+YEL+"┃\n"NOR, tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"])));
        else
                line += sprintf( HIC "内力"NOR "：" HIG "%-24s"+ NOR+YEL+"┃\n"NOR, blank_string );

        if( ob->max_food_capacity() > 0 )
                line += sprintf( YEL "┃" HIC" 食物"NOR"：%-24s   ", tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL));
        else
                line += sprintf( YEL "┃" HIC" 食物"NOR"："YEL   "%-24s"+ NOR+YEL+"┃\n"NOR, blank_string );
        
        if( ob->max_water_capacity() > 0 )
                line += sprintf( HIC "饮水"NOR"：%-24s"+ NOR+YEL+"┃\n"NOR , tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN));
        else
                line += sprintf( HIC "饮水"NOR CYN"：%-24s"+ NOR+YEL+"┃\n"NOR, blank_string );

        line += sprintf( YEL "┃                                                                ┃\n" NOR );
//        line += sprintf( YEL "┃" NOR HIY " 武学宗师： %s" NOR HIY "    任督二脉： %s" NOR HIY "   元婴出世： %s" NOR HIY "    转世重生：%s " NOR YEL "┃\n" NOR,
//                userp(ob) ? "○" : HIC "×", ob->query("breakup") ? "○" : HIC "×", ob->query("animaout") ? "○" : HIC "×", ob->query("reborn") ? "○" : HIC "×" );  
        
        line += sprintf( YEL "┣━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┫\n" NOR );        

        line += sprintf( YEL "┃" HIC "【杀生次数】" NOR HIR"%6d位"NOR, 
                my["MKS"] + my["PKS"]);
        line += sprintf( YEL "┃" HIC "【杀死玩家】" NOR HIR"%6d位"NOR, 
                my["PKS"]);
        line += sprintf( YEL "┃" HIC "【死亡次数】" NOR HIR"%6d次"NOR, 
                my["dietimes"]);
        line += YEL "┃\n" NOR;

if ( (int)ob->query_condition("bonze_drug" ) > 0 || (int)ob->query_condition("putizi_drug" ) > 0 || (int)ob->query_condition("medicine" ) > 0)
    	msg=HIC"尚在";
else
    	msg=HIC"无有";

    	

    	


        line += sprintf( YEL "┃" HIC "【药物药性】" NOR HIR"%15s"NOR, 
                msg);
if ( (int)ob->query_condition("killer" ) > 0)
    	msg=HIR"尚在";
else
    	msg=HIR"无有";
        line += sprintf( YEL "┃" HIC "【武林通缉】" NOR HIR"%15s"NOR, 
                msg);

if ( (int)ob->query_condition("psgc" ) > 0)
    	msg=HIW"尚在";
else
    	msg=HIW"无有";  
        line += sprintf( YEL "┃" HIC "【江湖追杀】" NOR HIR"%15s"NOR, 
                msg);

        line += YEL "┃\n" NOR;

        line += sprintf( YEL "┣━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┫\n" NOR );
hylv   = (int)ob->query("hyvip"); 
if (hylv==0) hymsg="一般玩家";
if (hylv==1) hymsg="初级会员";
if (hylv==2) hymsg="中级会员";
if (hylv==3) hymsg="高级会员";		 
if (hylv==4) hymsg="骨灰会员";
msg=chinese_number(ob->query("hyday"));
if ((int)ob->query("hyday")>=1000000) msg="终身";

        line += sprintf( YEL "┃" NOR HIB " 会员等级：%-53s"NOR YEL "┃\n" NOR,
                        hymsg+"("+msg+")" );
        line += sprintf( YEL "┃" NOR HIB " 海洋币数：%-53s"NOR YEL "┃\n" NOR,
                        chinese_number(ob->query("hymoney")) );

        line += sprintf( YEL "┃" NOR HIB " 连续任务：%-53d"NOR YEL "┃\n" NOR,
                        zs4 );	
        line += sprintf( YEL "┃" NOR HIB " 下次升级：%-53d"NOR YEL "┃\n" NOR,
                        need );	

if (ob->query("4zhuan") || ob->query("combat_exp",1) > 90000000)
{
	
	
	        line += sprintf( YEL "┃" NOR HIB " 武功上限：%-53d"NOR YEL "┃\n" NOR,
                        zs3 );	
}
if (ob->query("4zhuan"))
{
	
        line += sprintf( YEL "┃" NOR HIB " 转生技能：%-53s"NOR YEL "┃\n" NOR,
                        zs2 );	

}
        msg = "";
        if ((int)mci["dietimes"])
                msg = sprintf(HIB " 你到目前为止总共到黑白无常那里"
                                "串门%s次。" NOR,
                                chinese_number(mci["dietimes"]));
        if (msg != "")
                line += sprintf( YEL "┃" NOR "%" + sprintf("%d",(64 + color_len(msg))) + "-s" NOR YEL "┃\n" NOR, msg );

        msg = "";
        if (stringp(ob->query("killbyname")))
                        msg += sprintf(HIB " 上次死因：%s" NOR,
                                        ob->query("killbyname"));
 
 
 
        if (msg != "")
                line += sprintf( YEL "┃" NOR "%" + sprintf("%d",(64 + color_len(msg))) + "-s" NOR YEL "┃\n" NOR, msg );
        line += YEL "┗━━━━━━━━━━━━━━━━━━━━━━━━━【个人档案】━┛\n" NOR;
        
        write(line);
write(HIC" "+ob->name()+" 在游戏中已经度过了"+age_string((int)ob->query("mud_age"))+"。\n"NOR);
if (wizardp(ob)) write(HIC" "+ob->name()+" 时间:"+(int)ob->query("mud_age")+"。\n"NOR);
//if (me->query_temp("xmud")) write("$#\n");
        return 1;
}


string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%6s" NOR, chinese_number(value) );
        else if( value < gift ) return sprintf( CYN "%6s" NOR, chinese_number(value) );
        else return sprintf("%6s", chinese_number(value));
}

string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;

        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return HIB;
}

string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph2(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string2[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph3(int a)
{
        return BLU + blank_string3[0..(23-a)] + NOR;
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

