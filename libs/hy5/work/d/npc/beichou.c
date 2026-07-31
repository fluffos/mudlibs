// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
int ask_pk();
inherit NPC;
int ask_hy();
int ask_hygoods();
string ask_liwu15();
string ask_liwu16();
#include "/quest/givegift.c"
private string chinese_types(string types)
{
        switch(types)
        {
        case "object"             :    return HIC "物品" NOR;
        case "objamount"          :    return HIC "物品" NOR;
        case "special"            :    return HIG "特殊技能" NOR;
        case "special2"           :    return HIW "转世技能" NOR;
        case "story"              :    return HIM "故事" NOR;
        case "package"            :    return HIR "※" NOR;
        case "card"               :    return HIY "★" NOR;
        case "gold"               :    return HIY "＄" NOR;
        default                   :    return HIR "未知" NOR;
        }
}

mapping goods = ([
        "double"  :          "双倍奖励:1:double:card:本次登陆,双倍奖励",
        "monthcard"  :          "月度会员:30:monthcard:card:会员月卡 送初级会员资格",
        "seasoncard"            : "季度会员:60:seasoncard:card:会员季卡 送中级会员资格 ",
        "yearcard"              : "年度会员:200:yearcard:card:会员年卡 送10个替身娃娃 高级会员资格",
        "forevercard"           : "终身会员:500:forevercard:card:终身会员 送冲穴铜人 骨灰会员资格",
   "strdan"  : "臂力丹:5:/clone/buy/strdan:object:增加先天臂力的丹药 最高到30",
        "intdan"  : "悟性丹:5:/clone/buy/intdan:object:增加先天悟性的丹药 最高到30(转后后50)",
        "condan"  : "根骨丹:5:/clone/buy/condan:object:增加先天根骨的丹药 最高到30(转后后50)",		
        "dexdan"  : "身法丹:5:/clone/buy/dexdan:object:增加先天身法的丹药 最高到30(转后后50)",
        "kardan"  : "福貌丹:10:/clone/buy/kardan:object:增加先天福源和相貌的丹药 最高到30(转后后50)",	
        "force2"  : "双内丹:20:/clone/buy/force2:object:可以重新选择双内功",	
        "zqdan"  : "正气丹:2:/clone/buy/zqdan:object:增加正气 一次五十万",	
        "hcdan"  : "回春丹:5:/clone/buy/hcdan:object:改变年龄到十八岁",	
        "zndan"  : "壮年丹:5:/clone/buy/zndan:object:改变年龄到三十岁",		
        "xqdan"  : "邪气丹:2:/clone/buy/xqdan:object:增加邪气 一次五十万",			
        "htdan"  : "糊涂丹:5:/clone/buy/htdan:object:减少先天悟性 最低到10",				
        "wldan"  : "无力丹:5:/clone/buy/wldan:object:减少先天臂力 最低到10",					
        "neilidan"  : "内力神丹:1:/clone/buy/neilidan:object:增加内力上限200点",
        "ygdan"  : "免因果丹:10:/clone/buy/ygdan:object:解一切毒 消除身上不良状态,判师标志",					        	        		
        "newbie"  : "新手包:30:/clone/buy/newbie:object:增加一万两黄金10个内力神丹 10点门贡",	
        "czdan2"  : "成长银丹:5:/clone/buy/czdan2:object:四转五转玩家，获得成长资历6点",	
        "czdan3"  : "成长金丹:20:/clone/buy/czdan:object:四转五转玩家，获得成长资历50点",	
        "newbiezs"  : "新手上路丹:5:/clone/buy/newbiezs:object:十万经验 八万潜能 八十点内力上限 八点门贡",					
        "psdan"  : "平民丹:5:/clone/buy/psdan:object:改变师门，玩家变为平民 无判师记录",		
        "wgwan"  : "武功丹:5:/clone/buy/wgdan:object:直接增加某种武功100级 最高支持到600级 ",			
        "learn1"  : "学习勋章:50:/clone/buy/learn-emblem:object:学习速度加倍",					        	        	
        "study1"  : "汲取勋章:50:/clone/buy/study-emblem:object:学习不减精",				
        "tishenwawa"  : "替身娃娃:1:/clone/buy/tishenwawa:object:替身娃娃可以为你档死一次",
        "tongren"  : "冲穴铜人:50:/clone/buy/tongren:object:冲穴铜人冲穴时不产生意外",
        "dushi"  : "朱睛冰蟾油:100:/clone/buy/dushi:object:朱睛冰蟾油 解一切毒 可反复使用",
        "migongfu"  : "迷宫寻路:5:/clone/buy/migongfu:object:迷宫寻路",
        "yangwan"  : "真阳丸:10:/clone/box/new2/24:object:变为男性",
        "yinwan"  : "真阴丸:10:/clone/box/new2/23:object:变为女性",

]);



string get_types(string arg)
{
        string strtmp;
        mixed * items;

        strtmp = goods[arg];
        items = explode(strtmp, ":");

        return items[3];
}
int sort_object(string str1, string str2)
{
        if( get_types(str1) == "package" ) return 1;
        if( get_types(str2) == "package" ) return -1;

        if( get_types(str1) == "objamount" ) return 1;
        if( get_types(str2) == "objamount" ) return -1;

        if( get_types(str1) == "object" ) return 1;
        if( get_types(str2) == "object" ) return -1;

        if( get_types(str1) == "story" ) return 1;
        if( get_types(str2) == "story" ) return -1;

        if( get_types(str1) == "special" ) return 1;
        if( get_types(str2) == "special" ) return -1;

        if( get_types(str1) == "special2" ) return 1;
        if( get_types(str2) == "special2" ) return -1;
        
        if( get_types(str1) == "card" ) return 1;
        if( get_types(str2) == "card" ) return -1;

        if( get_types(str1) == "gold" ) return 1;
        if( get_types(str2) == "gold" ) return -1;

        return -1;
}

public varargs void show_goods(string arg)
{
        string strtmp;
        int i, j;
        mixed * obs, all, items;

        obs = keys(goods);

        all = unique_array(obs, (:  get_types($1) == "objamount" ? 1 : get_types($1) == "object" ? 2 :
                                    get_types($1) == "story" ? 3 : get_types($1) == "special" ? 4 :
                                    get_types($1) == "special2" ? 5 : get_types($1) == "card" ? 6 : 
                                    get_types($1) == "package" ? 7 : 8 :));

        all = sort_array(all, (: sort_object($1[0], $2[0]) :));

        write(HIY "会员商店目前出售以下货物：\n" NOR);
        write(sprintf(HIW "%-16s%-16s%-10s%-10s%s\n" NOR,
                      "名称", "代号", "价格($HY)", "种类", "简要说明"));
        write(HIG "-------------------------------------------------------------------------------\n\n" NOR);

        for (i = 0; i < sizeof(all); i ++)
        {
                strtmp = "";
                items = ({});

                for(j = 0; j < sizeof(all[i]); j ++)
                {
                        strtmp = goods[all[i][j]];
                        items = explode(strtmp, ":");
                        if (sizeof(items) != 5)
                        {
                                write("strtmp made items != 5 is : " + strtmp + "\n");
                                return;
                        }
                        write(sprintf(HIW "%-16s%-16s" HIY "%-10s" HIW "%-26s%-50s\n" NOR,
                                      items[0], all[i][j], items[1], chinese_types(items[3]), items[4]));
                }
        }

        write(HIG "购买指令" HIY ":" HIG "buygoods 代号\n" NOR);
        write(HIG "凡是种类带有" HIY "★" HIG "标记的服务均为购买会员期限。\n" NOR);
        write(HIG "请认真阅读有关说明，购买前请考虑清楚， 如无差错，恕不退货！\n" NOR);
        write(HIG "-------------------------------------------------------------------------------\n\n" NOR);
}

void create()
{
        set_name("北丑", ({ "bei chou", "bei", "chou", "beichou" }));
        set("long", @LONG
这是一个身着戏子打扮的瘦小老头，长得尖嘴
猴腮，天生一副奸相。谁人能知这便是当今武
林中号称「南贤北丑」戏子北丑。虽其排名在
南贤之下，但却也是南贤生平最畏惧之人。
LONG);
        set("nickname", HIW "北戏子" NOR);
        set("title", HIC "武林泰斗" NOR);
        set("gender", "男性" );
        set("age", 68);
        set("attitude", "friendly");
	set("no_kill",1);
	    set("qi",   99999999);
	    set("jing", 99999999);
	set("eff_qi",   99999999);
	set("eff_jing", 99999999);
	set("max_qi",   99999999);
	set("max_jing", 99999999);
	set("neili", 554500);
	set("max_neili", 554500);
	set("jiali", 0);
	set("combat_exp", 85000000);
	set("score", 50000);                
        set_skill("strike",1200);
        set_skill("unarmed",1200);
        set_skill("dodge",1200);
        set_skill("force", 1200);
        set_skill("unarmed", 1200);
        set_skill("sword", 1200);
	set_skill("parry", 1210);
	set_skill("literate", 1200);
	set_skill("canzhi-duanhun",1300);
	set_skill("ai-sword",1300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");
        map_skill("sword", "ai-sword");

        set("inquiry", ([
                "月度会员"  :"购买(buygoods)月度会员卡,送会员背包,初级会员资格 每天领取会员奖励。\n",
                "季度会员"  :"购买(buygoods)季度会员卡,送会员背包,中级会员资格 可领取会员奖励(部分加2倍)。\n",
                "年度会员"  :"购买(buygoods)年度会员卡,送会员背包,高级会员资格 送10个替身娃娃 可领取会员奖励(部分加3倍)。\n",
                "终身会员"  :"购买(buygoods)终身会员卡,送会员背包,骨灰会员资格 送10个替身娃娃 冲穴铜人 可领取会员奖励(部分加4倍)。\n",
                "挑战": (: ask_pk :),
                "challenge": (: ask_pk :),	
                "会员卡": (: ask_hygoods :),
                "membergoods": (: ask_hygoods :),
                "membercards": (: ask_hygoods :),	
        	      "membergift":(: ask_hy :),
            		"会员奖励": (: ask_hy :),
            			"任务" : (: ask_liwu15 :),
"job" : (: ask_liwu15 :),
"ok" : (: ask_liwu16 :),
"结束" : (: ask_liwu16 :),
        ]) );

        set("chat_chance", 1);
        set("chat_msg",({
                CYN "北丑贼眯眯的说：天算地算不如人算，可是再怎么算戏子我都知道。\n" NOR,
        }));

set_temp("apply/intelligence", 200);
set_temp("apply/strength",200);
set_temp("apply/dexerity",200);
set_temp("apply/constitution",200);
set_temp("apply/karey", 200);
set_temp("apply/percao", 200);	
set_temp("apply/armor", 5000);
set_temp("apply/defense", 200);
set_temp("apply/attack", 200);
set_temp("apply/damage", 5000);  
            
       	setup();
     carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/misc/cloth")->wear();


}


void init()
{
	add_action("buy_goods", "buygoods");
}


int ask_hygoods()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	object me = this_player();
show_goods();
        return 1;
}



public int buy_goods(string which)
{
        mixed * all, items;
        mixed specials;
        string strtmp;
        int i, vip, value, money;
        object buy_ob;
object ob=this_player();



        all = keys(goods);
        if (member_array(which, all) == -1)
        {
                write("对不起，没有您要购买的物品 " + HIR + which + NOR + "， 请问一下"
                      "我吧(ask bei chou about 会员卡) 。\n" NOR);
                return 1;

        }

        strtmp = goods[which];
        items = explode(strtmp, ":");
        sscanf(items[1], "%d", value);

        if (items[2] == "manual")
        {
                write("对不起，该服务必须由 admin 手动实现，请及时与 admin 联系！\n");
                return 1;
        }

        vip   = ob->query("hyvip");
        money = ob->query("hymoney");

        // 会员折扣
        // 会员折扣
if (items[3]=="object")
{
        if (vip == 4)
                value = value * 80 / 100;
        else
        if (vip == 3)
                value = value * 85 / 100;
        else
        if (vip == 2)
                value = value * 90 / 100;
}


        if (value < 1) value = 1;
        if (!value) value = 1;

        
        
        if (value < 1) value = 1;
        if ((int)ob->query("hymoney") < 1)
        {
                write("对不起，您的海洋金币数量不够！\n");
                return 1;
        }

        if (money < value)
        {
                write("对不起，您的海洋金币数量不够！\n");
                return 1;
        }

        switch(items[3])
        {
        case "package":


                switch( which )
                {
                case "newbie" :
                        //MEMBER_D->db_fee_member(ob, 31);
                        break;


                case "yj-rune" :
                        for (i = 0; i < 7; i++)
                        {
                        }
                        break;
                default :
                        break;
                }

                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        case "object":

                buy_ob = new(items[2]);
                if (! objectp(buy_ob))
                {
                        write("复制物品失败，请与本站ADMIN联系！\n");
                        return 0;
                }


                buy_ob->move(ob, 1);
                ob->add("hymoney",-value);
                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        case "objamount":
                buy_ob = new(items[2]);
                if (! objectp(buy_ob))
                {
                        write("复制物品失败，请与本站ADMIN联系！\n");
                        return 0;
                }

                if (which == "putizi")
                        buy_ob->set_amount(20);
                else
                if (which == "jiuzhuan")
                        buy_ob->set_amount(10);
                else
                if (which == "yuqingsan")
                        buy_ob->set_amount(120);
                else
                if (which == "tianxiang")
                        buy_ob->set_amount(15);
                else
                if (which == "xuanhuang1")
                        buy_ob->set_amount(5);

                buy_ob->move(ob, 1);

                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        case "card":

                if (which != "double" && which != "monthcard" && which != "seasoncard" &&
                    which != "yearcard"  && which != "forevercard")
                {
                        write("没有这种类型的会员卡！\n");
                        return 0;
                }


                if (which == "double")
{
ob->set_temp("hyjlexpok",1);
}
                if (which == "monthcard")
{
ob->add("hyday",31);
ob->set("hyvip",1);
}
                else
                if (which == "seasoncard")
{
ob->add("hyday",92);
ob->set("hyvip",2);
}
                else
                if (which == "yearcard")
{
ob->add("hyday",365);
ob->set("hyvip",3);
                        for (i = 0; i < 10; i++)
                        {
                                buy_ob = new("/clone/buy/tishenwawa");
                                buy_ob->move(ob, 1);
                        }


}
                else
                if (which == "forevercard")
{
ob->add("hyday",1800000);
ob->set("hyvip",4);
ob->add("mpgx",88);
                        for (i = 0; i < 10; i++)
                        {
                                buy_ob = new("/clone/buy/tishenwawa");
                                buy_ob->move(ob, 1);
                        }
                                buy_ob = new("/clone/buy/tongren");
                                buy_ob->move(ob, 1);
}
ob->add("hymoney",-value);

if (which != "double")
{
        buy_ob = new("/clone/money/gold");
        tell_object(ob, HIY "你获得了一万两黄金。\n" NOR);

        buy_ob->set_amount(10000);
        buy_ob->move(ob,1);
}


                write(HIC "您总共花费了 " HIY + value + HIC + " $HY, 祝您好运！\n" NOR);
                return 1;

        
                
        default:
                write("无效物品种类！\n");
                return 0;
        }
}


int ask_hy()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx,hylv,cz;
 	object me = this_player();
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);

if ( !me->query("hyvip"))
{
command("say 你没有会员权限!");
        return 1;
}

if ( !me->query("hyday"))
{
command("say 你的会员资格已经到期!");
        return 1;
}

if ( (int)me->query("hyvip") < 1)
{
command("say 你没有会员权限!");
        return 1;
}

if ( (int)me->query("hyday") < 1)
{
command("say 你的会员资格已经不到一天了!");
        return 1;
}

if ( (int)me->query("hyday") == 0)
{
command("say 你的会员资格已经为零了!");
        return 1;
}


//    write("现在是:");
    //write(year);
    //write(month);
    //write(day);
hydata=year+month+day;
//write(hydata);

    if ( me->query("hydata")==hydata)
{
command("say 会员奖励一天只能领取一次! "+me->query("name")+"上次领取时间是"+me->query("hydata")+"!");
        return 1;
}



//neili=280+random(888);
exp=30000;
pot=exp/3;
neili=8;
//mpgx=2;

hylv   = (int)me->query("hyvip"); 
exp=exp+(20000*hylv);
pot=exp/3;
if (hylv==1)
{	
pot=pot+(pot*0.3);
neili=neili*2;
mpgx=mpgx*2;
}
if (hylv==2)
{	
pot=pot+(pot*0.6);
neili=neili*3;
mpgx=mpgx*3;
}

	
if (hylv==3)
{	
pot=pot+(pot*0.8);
neili=neili*3;
mpgx=mpgx*3;
}	
	
if (hylv==4)
{	
exp=exp+50000;
pot=pot+pot+20000;
neili=neili*4;
mpgx=mpgx*4;
}

me->add("max_neili",neili);
me->add("combat_exp",exp);
me->add("potential",pot);
//me->add("mpgx",mpgx);
me->set("hydata",hydata);
if ((int)me->query("hyday")<1700000) me->add("hyday",-1);
me->set_temp("hyjlexpok",1);
message_vision(HIC"$n领取了"+ctime(time())+"的会员奖励 !\n"+me->query("name")+"的经验增加"+exp+"。潜能增加"+pot+"点。内力增加"+neili+"点。\n"NOR , this_object(), me );
if (me->query("4zhuan")
    || me->query("5zhuan"))
{
if (hylv==4)
{	

cz=1;
me->add("expmax",cz);

message_vision(HIC"$n领取了"+cz+"点成长上限。\n"NOR , this_object(), me );


}
}


	return 1;
}

int ask_pk()
{
    string week, month, year, day, time,hydata;
    string check,mt;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
	object *inv;
 	 object target;
 	 	int sizeinv;
 	 	object me = this_player();
target=this_object();
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);

if(me->is_busy())
{
write("对不起，你正忙，你一会再来吧 ！\n");
                return 1;	
}

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你背着人想给里面的怪物送点心去？\n");
       		
		}

if (!wizardp(me) && me->query("combat_exp",1) && me->query("combat_exp",1) < 200000 && me->query("nbjob",1)!=36)
{
write("对不起，你的经验太小少了，去挑战是送死 ！\n");
                return 1;	
}

if (!wizardp(me) && me->query("combat_exp",1) > 25000000)
{
write("对不起，你的能力太强了，请去找南贤挑战别的吧 ！\n");
                return 1;	
}

if (!wizardp(me) && me->query_condition("pkjob"))
{
write("对不起，你才挑战过啊，过一会再来吧 ！\n");
                return 1;	
}

hydata=year+month+day;
//write(hydata);

    if ( !wizardp(me) && me->query("pkdata")==hydata && me->query("pktime",1)>3)
{
command("say 每个人每天只有三次挑战机会!");
        return 1;
}

if ( me->query("pkdata")!=hydata)
{
me->set("pktime",1);	
}
if (!me->query("startroom")) me->set("startroom","/d/city/kedian");

command("say 好的，挑战开始! 想结束了，请输入recall 返回你的出生点。");

if (me->query("combat_exp",1) < 400000)    mt="/d/migong/nlev1/dong21";
if (me->query("combat_exp",1) >= 400000 && me->query("combat_exp",1) < 800000)   mt="/d/migong/nlev2/dong21";
if (me->query("combat_exp",1) >= 800000 && me->query("combat_exp",1) < 1000000) mt="/d/migong/nlev3/dong21";
if (me->query("combat_exp",1) >= 1000000 && me->query("combat_exp",1) <= 2000000) mt="/d/migong/nlev4/dong21";
if (me->query("combat_exp",1) >= 2000000 && me->query("combat_exp",1) <= 2900000) mt="/d/migong/nlev5/dong21";
if (me->query("combat_exp",1) >= 2900000 && me->query("combat_exp",1) <= 3500000) mt="/d/migong/nlev6/dong21";
if (me->query("combat_exp",1) >= 3500000 && me->query("combat_exp",1) <= 4500000) mt="/d/migong/nlev7/dong21";
if (me->query("combat_exp",1) >= 4500000 && me->query("combat_exp",1) <= 5500000) mt="/d/migong/nlev8/dong21";
if (me->query("combat_exp",1) >= 5500000 && me->query("combat_exp",1) <= 6500000) mt="/d/migong/nlev9/dong21";
if (me->query("combat_exp",1) >= 6500000 && me->query("combat_exp",1) <= 9500000) mt="/d/migong/nlev10/dong21";
if (me->query("combat_exp",1) >= 9500000 && me->query("combat_exp",1) <= 12500000) mt="/d/migong/nlev11/dong21";
if (me->query("combat_exp",1)>= 12500000 && me->query("combat_exp",1) <= 14500000) mt="/d/migong/nlev12/dong21";
if (me->query("combat_exp",1)>= 14500000 && me->query("combat_exp",1) <= 17000000) mt="/d/migong/nlev13/dong21";
if (me->query("combat_exp",1)>= 17000000 ) mt="/d/migong/nlev14/dong21";
me->set_temp("nbjob35",1);

me->move(mt);
me->apply_condition("pkjob",50);
me->set("pkdata",hydata);
if (me->query("pktime",1) >3 || !me->query("pktime",1)) 
{
me->set("pktime",1);
}
else
{
me->add("pktime",1);
}
me->start_busy(2);

        return 1;
}



string ask_liwu15()
{
  string msg;
  object ob1;
  object me=this_player();
  int exp_bound,qn_bound,neili;
if (me->query("nbjob",1)<20)
{
	msg=HIY"北丑说道：\n你先去古村找村长吧!"NOR;
}

if (me->query("nbjob",1)>=50)
{
	msg=HIY"北丑说道：\n我这暂时没什么任务了!"NOR;
}

if (me->query("nbjob")==20)
{
msg=HIY"北丑说道：\n第一个任务
  熟悉一下扬州吧 找到扬州武庙 找到南贤 
  你以后可能要经常出入那个地方
  ask nan xian about job
  查看当前地图map
  完成后 ask beichou about ok"NOR;
me->delete_temp("nbjob19");
me->set_temp("nbjob19",0);
me->delete_temp("nbjob20");
me->set_temp("nbjob20",0);
}
if (me->query("nbjob")==21)
msg=HIY"北丑说道：\n第二个任务
  熟悉一下扬州吧 找到当铺和当铺内室  
  以后你可以在那卖东西，当东西
  去和唐楠 香菱 打个招呼吧 ask about job
  查看当前地图map
  完成后 ask beichou about ok"NOR;
  
if (me->query("nbjob")==22)
msg=HIY"北丑说道：\n第三个任务
  熟悉一下扬州吧 找到春来茶馆 找到叶济世 
  以后你要找叶济世帮你看病
  打个招呼吧 ask about job
  查看当前地图map
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==23)
msg=HIY"北丑说道：\n第四个任务
  熟悉一下扬州吧 找到扬州钱庄 找到钱眼开
  以后你要找钱眼开存钱
  打个招呼吧 ask about job
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==24)
msg=HIY"北丑说道：\n第五个任务
  熟悉一下大车吧  找到客店的大车
  坐一次大车吧
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==25)
msg=HIY"北丑说道：\n第六个任务
  熟悉一下马厩吧  找到扬州的马厩
  骑一次马吧
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==26)
msg=HIY"北丑说道：\n第七个任务
  熟悉一下武林车马票吧  找到扬州的杂货铺
  使用一次 武林车马票
  完成后 ask beichou about ok"NOR;
  
if (me->query("nbjob")==27)
msg=HIY"北丑说道：\n第八个任务
  做10次最简单的任务 磨药任务 
  chen job2然后ask ping about job
  相关帮助help moyao
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==28)
msg=HIY"北丑说道：\n第九个任务
  做10次最简单的任务 伐木任务 
  chen job3然后ask songque about job
  相关帮助help kanshu
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==29)
msg=HIY"北丑说道：\n第十个任务
  做10次最简单的任务 唱戏任务 
  chen job4然后ask guan about job
  相关帮助help changxi
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==30)
{
msg=HIY"北丑说道：\n第十一个任务
  做一次打猎任务 要杀死十个猎物
  chen job5然后south 后杀死猎物获得奖励
  相关帮助help dalie
  我指点你一下武功
  相关: 清风细雨温柔剑 的绝招 剑神一笑(perform yixiao) 
  完成后 ask beichou about ok"NOR;
if (me->query_skill("jingyiforce",1)<200)
me->set_skill("jingyiforce",200);
if (me->query_skill("softsword",1)<200)
me->set_skill("softsword",200);


}  
if (me->query("nbjob")==31)
msg=HIY"北丑说道：\n第十二个任务
  做1次比较难的任务 巡城任务
  chen job7然后ask wang about job
  相关帮助help xunchen
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==32)
msg=HIY"北丑说道：\n第十三个任务
  现在你应该学会如何生存了，你找个门派加入吧。
  相关帮助help menpai 
  相关指令apprentice 师傅id
  完成后 ask beichou about ok"NOR;
  
if (me->query("nbjob")==33)
{
msg=HIY"北丑说道：\n第十四个任务
  熟悉一下打造武器吧 找点材料 去打造件武器吧
  可以在我这坐大车去苏州铸剑室 qu dazao
  我已经打过招呼，给个一两银子就行了
  相关帮助help dazao
  完成后 ask beichou about ok"NOR;
if (!me->query_temp("givewq") && !me->query("nbtjob32"))
{
if (!present("qingtong",me))
{
                  ob1=new("/p/item/kuangshi1");
                  ob1->move(me); 
                  ob1=new("/p/item/kuangshi1");
                  ob1->move(me); 
}
if (!present("youyu",me))
{
                  ob1=new("/p/item/material1");
                  ob1->move(me); 
}
me->set_temp("givewq",1);
tell_object(me,HIY"北丑给了你一些打造武器的材料!\n"+NOR);
}

}
if (me->query("nbjob")==34)
{
msg=HIY"北丑说道：\n第十五个任务
  熟悉一下打造武器吧 找点材料 去打造件防具吧
  可以在我这坐大车去苏州铸剑室 qu dazao
  我已经打过招呼，给个一两银子就行了
  相关帮助help dazao
  完成后 ask beichou about ok"NOR;
if (!me->query_temp("givefj")  && !me->query("nbtjob33"))
{
if (!present("mianhua",me))
{	
                  ob1=new("/p/item/buliao1");
                  ob1->move(me); 
}
if (!present("qingtong",me))
{
                  ob1=new("/p/item/kuangshi1");
                  ob1->move(me); 
 }
 if (!present("banyu",me))
{	
                  ob1=new("/p/item/material7");
                  ob1->move(me); 
}                  
me->set_temp("givefj",1);
tell_object(me,HIY"北丑给了你一些打造防具的材料!\n"+NOR);
}

}
if (me->query("nbjob")==35)
msg=HIY"北丑说道：\n第十六个任务
  熟悉一下门派对练任务吧 找到门派任务吏 
  输入job后duilian 本门人员 要求完成10次
  相关帮助help geren
  完成后 ask beichou about ok"NOR;
  
if (me->query("nbjob")==36)
msg=HIY"北丑说道：\n第十七个任务
  做一次挑战洞窟任务吧 
  chen job10然后ask bei chou about challenge
  相关帮助help boss 新手试炼-挑战洞窟
  如果想离开 请输入recall gc
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==37)
msg=HIY"北丑说道：\n第十八个任务
  熟悉一下门派个人任务吧 找到门派任务吏 
  输入quest 后，完成相应任务 要求完成10次
  相关帮助help geren
  完成后 ask beichou about ok"NOR;
  
if (me->query("nbjob")==38)
msg=HIY"北丑说道：\n第十九任务
  完成江湖互动任务一次 
  输入taskjob 找到相应人物 ask 人物 about job 
  相关帮助help taskjobs
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==39)
msg=HIY"北丑说道：\n第二十任务
  完成玩家互动任务一次 
  输入hdjob 找到相应玩家 ask 玩家 about job 
  相关帮助help hdjobs
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==40)
msg=HIY"北丑说道：\n第二十一任务
  找到扬州春来茶馆 找到叶济世 
  向他要根银针，学点妙手回春的技能吧
  使用银针 完成行医任务10次
  相关帮助help medical
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==41)
msg=HIY"北丑说道：\n第二十二任务
  完成十次做武器任务 
  先到襄阳附近找到矿山，然后挖到矿后去襄阳兵器铺做成武器
  相关帮助help zhaowuqi
  提示 产生的收获，可以卖钱
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==42)
msg=HIY"北丑说道：\n第二十三任务
  完成十次务农任务 
  先到北京附近找到农庄，然后去务农
  相关帮助help zhaoeat
  提示 产生的收获，可以卖钱
  完成后 ask beichou about ok"NOR;
  
if (me->query("nbjob")==43)
msg=HIY"北丑说道：\n第二十四任务
  完成十次做菜任务 
  先到北京附近找到龙泉酒家，然后去做菜
  相关帮助help penlen
  提示 产生的收获，可以卖钱
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==44)
msg=HIY"北丑说道：\n第二十五任务
  完成十次练丹任务 
  先到扬州附近找到药铺，然后买个药锄去挖药
  挖药到手后，到药铺炼丹房 练丹
  相关帮助help liandan
  提示 产生的收获，可以卖钱
  完成后 ask beichou about ok"NOR;
  
if (me->query("nbjob")==45)
msg=HIY"北丑说道：\n第二十六任务
  完成十次襄阳保护任务 
  去襄阳找到郭靖 完成10次保护任务
  此任务有难度 要求玩家有一定武学基础
  相关帮助help guojob  [1]保护任务(单人)
  完成后 ask beichou about ok"NOR;

if (me->query("nbjob")==46)
msg=HIY"北丑说道：\n第二十七任务
  完成十次黄蓉任务 
  去襄阳找到黄蓉 完成10次除恶任务
  此任务有难度 要求玩家有一定武学基础
  相关帮助help huangjob
  完成后 ask beichou about ok"NOR;
  
 if (me->query("nbjob")==47)
msg=HIY"北丑说道：\n第二十八任务
  完成十次护镖任务
  找到福州福威镖局 完成10次护镖任务
  此任务有难度 要求玩家有一定武学基础
  相关帮助help hubiao
  完成后 ask beichou about ok"NOR;
  
if (me->query("nbjob")==48)
msg=HIY"北丑说道：\n第二十九任务
  完成迷宫第一层 
  去襄阳附近，找到眠龙洞 杀死第一层的BOSS
  此任务有难度 要求玩家有一定武学基础
  相关帮助help migong
  完成后 ask beichou about ok"NOR;
  
if (me->query("nbjob")==49)
msg=HIY"北丑说道：\n最后一个任务
  完成一次神书任务 
  去扬州广场，到无名居士 完成一次神书任务
  此任务有难度 要求玩家有一定武学基础
  找到一本神书 并归还
  相关帮助help tasks
  完成后 ask beichou about ok"NOR;
           
message("vision", msg+"\n", me);  
  return me->query("name")+"你快去完成这件事吧。";
}             


string ask_liwu16()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili,exp,pot;
  object ob1;
  object weapon;
weapon = me->query_temp("weapon");
if (me->query("nbjob",1)==20 && me->query_temp("nbjob19",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",21);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==21 && me->query_temp("nbjob20",1)>=2)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",22);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==22 && me->query_temp("nbjob21",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",23);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==23 && me->query_temp("nbjob22",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",24);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==24 && me->query_temp("nbjob23",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",25);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==25 && me->query_temp("nbjob24",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",26);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==26 && me->query_temp("nbjob25",1)==1)
{
exp=2888+random(888);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",27);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==27 && me->query_temp("nbjob26",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",28);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==28 && me->query_temp("nbjob27",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",29);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==29 && me->query_temp("nbjob28",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",30);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==30 && me->query_temp("nbjob29",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",31);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==31 && me->query_temp("nbjob30",1)>=1)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",32);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==32 && me->query("family/family_name"))
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",33);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==33 && (me->query_temp("nbjob32",1)==1 || me->query("nbtjob32")==1))
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",34);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==34 && (me->query_temp("nbjob33",1)==1 || me->query("nbtjob33")==1))
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",35);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==35 && me->query_temp("nbjob34",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",36);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==36 && me->query_temp("nbjob35",1)==1)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",37);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==37 && me->query_temp("nbjob36",1)>=10)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",38);
return "不错，不错，请继续努力 ask beichou about job";
}
if (me->query("nbjob",1)==38 && me->query_temp("nbjob37",1)==1)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",39);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==39 && me->query_temp("nbjob38",1)==1)
{
exp=5888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",40);
return "不错，不错，请继续努力 ask beichou about job";
}


if (me->query("nbjob",1)==40 && me->query_temp("nbjob41",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",41);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==41 && me->query_temp("nbjob42",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",42);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==42 && me->query_temp("nbjob43",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",43);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==43 && me->query_temp("nbjob44",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",44);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==44 && me->query_temp("nbjob45",1)>=10)
{
exp=8888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",45);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==45 && me->query_temp("nbjob46",1)>=10)
{
exp=18888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",46);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==46 && me->query_temp("nbjob47",1)>=10)
{
exp=18888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",47);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==47 && me->query_temp("nbjob48",1)>=10)
{
exp=18888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",48);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==48 && me->query("migong/lev1"))
{
exp=28888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",49);
return "不错，不错，请继续努力 ask beichou about job";
}

if (me->query("nbjob",1)==49 && me->query_temp("nbjob49",1)>=1)
{
exp=28888+random(300);
addnl(me,"exp",exp);me->add("max_neili",60);	
me->set("nbjob",50);
return "不错，不错，现在你应该能一个人行走江湖了！ ";
}

  return "不错，不错！有空多看看帮助信息吧(help) 查看任务的情况请 ask beichou about job";
}