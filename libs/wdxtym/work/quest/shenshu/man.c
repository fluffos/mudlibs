#include <ansi.h>
inherit NPC;
int ask_force2();
int ask_force(string arg);
int ask_me();
int ask_nk();
int ask_zs1();
int ask_zs2();
int ask_zs3();
int ask_zs4();
string ask_clear();
string ask_buchang();
string ask_panshi();
string ask_job();
int ask_ggs();
int ask_ggso();
#include "/clone/guard/party.h"
//int ask_gift();
int ask_bing();
int ask_yahuan();
int ask_yahuan2();
void create()
{
       set_name("无名居士", ({ "noname", "man" }));
        set("title",HIW"一代宗师"NOR);
	set("long",
              "他就是无名居士，没有人知道他的来历。\n"
              "如果你想收集神书，你可以问问他(book)和(shi).\n"
              );
        set("age", 57);
        set("class", "beggar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 700);
	set("int", 40);
	set("con", 40);
	set("dex", 700);
	set("no_kill",1);
	set("qi",   99999);
	set("jing", 99999);
	set("eff_qi",   99999);
	set("eff_jing", 99999);
	set("max_qi",   99999);
	set("max_jing", 99999);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 0);
	set("combat_exp", 25000000);
	set("score", 50000);
        set_skill("strike",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("parry", 210);
	set_skill("literate", 200);
	set_skill("canzhi-duanhun",300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");


set("inquiry", ([
            "神书": "神书共有四十二本，你可以用help tasks获得有关方面知识！",
            "向导石": "只有靠"HIR"七"+HIC+"彩"+HIY+"向"+HIM+"导"+HIG+"石"NOR+CYN"才能找到神书，灵石二十两一块！",
	     "盟主": (: ask_me :),
	     "免战": (: ask_nk :),
	     "一转": (: ask_zs1 :),
	     "二转": (: ask_zs2 :),
	     "三转": (: ask_zs2 :),
	     "转生技能": (: ask_zs3 :),
	     "成长": (: ask_zs4 :),
	     "双内功": (: ask_force2 :),
	     "任务":(: ask_job :),
		"随从": (: ask_yahuan :),
		"更换随重": (: ask_yahuan2 :),
      //  "武曲附体" : (: ask_ggs :),
      //  "武曲离体" 	: (: ask_ggso :),
//重要，申请和发礼物，只能开放一个，发礼物时关申请!!申请是关发礼物!!
	     "购买仓库":(: ask_clear :),


//重要，申请和发礼物，只能开放一个，发礼物时关申请!!申请是关发礼物!!
            ]) );
       	setup();
}
void init()
{
	add_action("do_answer", "answer");
	add_action("ask_force", "yaoforce");
}
int accept_object(object me, object ob)
{
	object shi;
	if( ob->query("money_id") && ob->value() >= 2000)
	{
		if (!present("xdshi", me))
		{
			shi = new("/clone/misc/findbook");
			command("say 好吧,"+me->query("name")+"既然给了钱，我就给你一块！\n");
			shi->move(me);
			message_vision("$N将一块"HIR"七"+HIC+"彩"+HIY+"向"+HIM+"导"+HIG+"石"NOR"交给了$n。\n" , this_object(), me );
		} else
	command("say 你不是有了一块嘛，还想要？钱我没收！\n");
	return 1;
	}

	command("say 谢谢，但我不要这东西！");
	return 0;
}
int ask_me()
{
if(this_player()->query("combat_exp")<1500000)  tell_object(this_player(),"无名居士说道：你修为太低，想要做盟主，必死无疑！\n");
else {
tell_object(this_player(),"无名居士说道： 好吧，里面危险重重，千万别乱来，否则有生命危险。自己小心吧！\n");
this_player()->move("/d/biwu/hole");
}
return 1;
}

int ask_nk()
{
if(this_player()->query("PKS",1)> 10
||this_player()->query_condition("killer")
//||this_player()->query("guard/flag")
||this_player()->query("age") < 18
 )
{
tell_object(this_player(),"无名居士说道：你没有资格，不能启用免战系统！\n");
}
else {
tell_object(this_player(),"无名居士说道： 好吧，你启用了免战系统！\n");
this_player()->set_temp("nokill",1);
}
return 1;
}



string ask_job()
{

        mapping quest,item,npc;
        object me;
        int j, combatexp, timep,factor,num;
        string room;
        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "15000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                        "2000000"
        });

        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
     if ((int)me->query_condition("guojob2_busy"))
if ((int)me->query_condition("nonamejob"))
{
return HIR"“这位"+RANK_D->query_respect(me)+"等会再来吧。"NOR;
}

if ((int)me->query_condition("nonamejob"))
{
message_vision(HIY"$N对着$n摇了摇头说：你刚接过任务!等会再来!\n"NOR, this_object(), me);
return HIR"“这位"+RANK_D->query_respect(me)+"等会再来吧。"NOR;
}
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        }
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];

item  = QUESTW_D(tag)->query_quest();
npc = QUESTS_D(tag)->query_quest();
if (random(2)==1)
npc = QUESTH_D(tag)->query_quest();
me->set_temp("jobitem",item["quest"]);
me->set_temp("jobnpc",npc["quest"]);
me->apply_condition("nonamejob",8);
tell_object(me,HIC"把『"HIG+item["quest"]+HIC"』找到，并交给『"HIG+npc["quest"]+HIC"』。\n" NOR);
return HIW"“这位"+RANK_D->query_respect(me)+"快点去做吧。"NOR;
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "无名居士笑着说：动武对我没有用！\n");
	command("hehe");
}

void die()
{
	unconcious();
}

int ask_yahuan2()
{
 	object me = this_player();

	if (!me->query("guard/flag"))
		command("say 凭你现在的条件，还没有资格问我要随从呢！");
	if (!me->query("guard/active"))
		command("say 你现在还没有随从!");
	else {
		command("nod " + me->query("id"));
		command("say 你已经重新可以换一个侍女了！");
		command("say 你会减去八分之一的修为");
	me->delete("guard/active");
  me->add("combat_exp",-(int)me->query("combat_exp")/8);
	}
	return 1;
}


int ask_yahuan()
{
 	object me = this_player();

	if (!me->query("guard/flag"))
		command("say 凭你现在的条件，还没有资格问我要随从呢！");
	else if (me->query("guard/active"))
		command("say 你不是已经有随从了么？");
	else {
		command("nod " + me->query("id"));
		if (me->query("gender") == "男性") {
			command("say 我现在正收了一些义女，她们都是名门弟子，有
\t\t武当派\t\t(wudang)
\t\t华山派\t\t(huashan)
\t\t灵鹫宫\t\t(lingjiu)
\t\t桃花岛\t\t(taohua)
\t\t天地会\t\t(tiandihui)
\t\t明教\t\t(mingjiao)
\t\t古墓派\t\t(gumu)
\t\t丐帮\t\t(gaibang)
\t\t全真教\t\t(quanzhen)
\t\t大理\t\t(dali)
\t\t铁掌帮\t\t(tiezhang)
\t\t慕容世家\t(murong)
\t\t昆仑派\t\t(kunlun)
\t\t凌霄城\t\t(lingxiao)
\t\t五毒教\t\t(wdjiao)
\t\t白驼山\t\t(baituo)
\t\t峨嵋派\t\t(emei)
\t\t逍遥派\t\t(xiaoyao)
\t\t雪山派\t\t(mizong)
\t\t星宿派\t\t(xingxiu)
\t\t御剑流\t\t(feitian)
\t\t神龙教\t\t(shenlong)
\t\t唐门\t\t(tangmen)
\t\t日月教\t\t(riyue)
\t\t少林\t\t(shaolin)
你想要收哪一个做你的丫环？请用answer回答我！");
		} else {
			command("say 我现在正收了一些义子，他们都是名门弟子，有
\t\t武当派\t\t(wudang)
\t\t华山派\t\t(huashan)
\t\t灵鹫宫\t\t(lingjiu)
\t\t桃花岛\t\t(taohua)
\t\t天地会\t\t(tiandihui)
\t\t明教\t\t(mingjiao)
\t\t古墓派\t\t(gumu)
\t\t丐帮\t\t(gaibang)
\t\t全真教\t\t(quanzhen)
\t\t大理\t\t(dali)
\t\t铁掌帮\t\t(tiezhang)
\t\t慕容世家\t(murong)
\t\t昆仑派\t\t(kunlun)
\t\t凌霄城\t\t(lingxiao)
\t\t五毒教\t\t(wdjiao)
\t\t白驼山\t\t(baituo)
\t\t峨嵋派\t\t(emei)
\t\t逍遥派\t\t(xiaoyao)
\t\t雪山派\t\t(mizong)
\t\t星宿派\t\t(xingxiu)
\t\t御剑流\t\t(feitian)
\t\t神龙教\t\t(shenlong)
\t\t唐门\t\t(tangmen)
\t\t日月教\t\t(riyue)
\t\t少林\t\t(shaolin)
你想要收哪一个做你的侍童？请用answer回答我！");
		}
		me->set_temp("guard/answer", 1);
	}
	return 1;
}
int do_answer(string arg)
{
	object me = this_player(), ob;
	int i, flag = 0;

	if (!me->query_temp("guard/answer"))
		return 0;

	// 要九阴传人需要一定的条件限制！
	for (i = 0; i < sizeof(ps); i++)
		if (arg == ps[i]["party"]) {
			flag = 1;
			break;
		}
	if (!flag) {
		command("kick " + me->query("id"));
		command("say 你想要的随从我可没有！");
		return 1;
	}
	command("ok");
	me->delete_temp("guard/answer");

	me->delete("guard/status");
	me->delete("guard/skills");
	me->delete("guard/gender");
	me->delete("guard/learned");
	me->delete("guard/skill_map");
	me->delete("guard/skill_prepare");
	me->set("guard/flag", 1);
	me->set("guard/active", 1);
	if (me->query("gender") == "男性")
		me->set("guard/gender", "girl");
	else
		me->set("guard/gender", "boy");
	me->set("guard/status", ps[i]["status"]);
	me->set("guard/skills", ps[i]["skills"]);
	me->set("guard/learned", ps[i]["learned"]);
	me->set("guard/skill_map", ps[i]["skill_map"]);
	me->set("guard/skill_prepare", ps[i]["skill_prepare"]);
	me->save();

	command("say 从今天起，她就跟着你了，你可以使用(zhaohuan)命令来召唤她！");

	return 1;
}

/*string ask_panshi()
{

        mapping quest,item,npc;
        object me=this_player();
if (me->query("npanshi"))
return HIR"“这位"+RANK_D->query_respect(me)+"我已经为你清过叛师记录了。"NOR;
command("say 由于系统调整，就帮你一次吧");
me->set("betrayer",0);
me->set("npanshi",1);
return HIW"“这位"+RANK_D->query_respect(me)+"以后要好好做人。"NOR;
}
*/

string ask_buchang()
{
        mapping quest,item,npc;
        object ob;
        object me=this_player();
		if ((int)me->query("combat_exp") < 5000)
			return HIR"“这位"+RANK_D->query_respect(me)+"是新手吧。"NOR;
		if(me->query("liwuopen/1")>0)
			return HIR"“这位"+RANK_D->query_respect(me)+"已经来拿过了吧。"NOR;
		if(me->query("liwuopen/2")>0)
			return HIR"“这位"+RANK_D->query_respect(me)+"已经来拿过了吧。"NOR;

		me->set("liwuopen/2",1);
		ob=new("/clone/gift/biggift");
        ob->set_amount(1);
        ob->move(me);
		return HIR"“这位"+RANK_D->query_respect(me)+"节日快乐。祝身体健康!!"NOR;
}
string ask_clear()
{
	object me = this_player();
    object obj;
    if (me->query("yuanbao") < 200 || present("cangku", me))
	{
		command("say 你身上已有随身仓库了或灵石不足200。");
            return 0;
	}
	else
	{
			me->add("yuanbao",-200);
			obj=new("clone/spec/xiang.c");
			obj->move(me);
			return HIG"购买成功，请查看背包。"NOR;;
	}
}


int ask_zs1()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");

     if(obj->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if ( obj->query("zhuanshen"))
{
command("say 你已经转生过了!");
        return notify_fail("此人已经转生过了!\n");
}
    if (!obj->query("migong/lev3")
    ||!obj->query("migong/lev2")
    ||!obj->query("migong/lev1"))
{
command("say 你没有资格转生!请至少完成迷宫任务到第3层!");
        return notify_fail("此人没有资格转生\n");
}
    if ( (int)obj->query("combat_exp") < 8000000)
{
command("say 你没有资格转生!需要8M修为。");
        return notify_fail("此人没有资格转生!需要8M修为。\n");
}
    if ( (int)obj->query("max_neili") < 5000)
{
command("say 你没有资格转生!你的内力不足!!");
        return notify_fail("此人没有资格转生!\n");
}
   if(obj->query_skill("dodge",1)<300 ||
		obj->query_skill("force",1)<300 ||
		obj->query_skill("parry",1)<300 ||
		obj->query_skill("unarmed",1)<300 ||
		obj->query_skill("literate",1)<300)
{
command("say 你没有资格转生!你的武功等级不足!!");
        return notify_fail("此人没有资格转生!\n");
}



    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//删除自己所有功夫
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");
		obj->map_skill("finger");
		obj->map_skill("hand");
		obj->map_skill("cuff");
		obj->map_skill("claw");
		obj->map_skill("strike");

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");
		obj->prepare_skill("cuff");
		obj->prepare_skill("claw");
		obj->prepare_skill("strike");
                obj->reset_action();
                obj->set("combat_exp",300000);
            obj->set("potential",obj->query("learned_points")+100000);
// 1
        if ( obj->query("per")+10 > 50)
        {
	obj->set("per",50);
        }
        else obj->set("per",obj->query("per")+10);

//2
        if ( obj->query("str")+10 > 50)
        {
	obj->set("str",50);
        }
        else obj->set("str",obj->query("str")+10);

//3
        if ( obj->query("dex")+10 > 50)
        {
	obj->set("dex",50);
        }
        else obj->set("dex",obj->query("dex")+10);

//4
        if ( obj->query("int")+10 > 50)
         {
	obj->set("int",50);
        }
        else obj->set("int",obj->query("int")+10);

//5
        if ( obj->query("con")+10 > 50)
        {
	obj->set("con",50);
        }
        else obj->set("con",obj->query("con")+10);


//6
        if ( obj->query("kar")+10 > 50)
        {
	obj->set("kar",50);
        }
        else obj->set("kar",obj->query("kar")+10);

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("blade_get");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
        obj->save();
obj->set("tforceok",2);
    write(HIR"转生成功,请重新登陆!\n"NOR);
tell_object(obj,HIR"转生成功,请重新登陆!\n"NOR);
	log_file("static/ZS",
		sprintf("%s 一转，时间: %s\n", geteuid(obj), ctime(time())) );

        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +
                              "一转了。");
    "/cmds/usr/quit"->main(obj);

    return 1;
}

int ask_zs2()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");

     if(obj->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if ( !obj->query("zhuanshen"))
{
command("say 你没经过一转!");
        return notify_fail("此人没经过一转!\n");
}
    if (!obj->query("migong/lev8")
    ||!obj->query("migong/lev4")
    ||!obj->query("migong/lev5")
    ||!obj->query("migong/lev6")
    ||!obj->query("migong/lev7"))
{
command("say 你没有资格转生!请至少完成迷宫任务到第8层!");
        return notify_fail("此人没有资格转生\n");
}
    if ( (int)obj->query("combat_exp") < 18000000)
{
command("say 你没有资格转生!需要18M修为。");
        return notify_fail("此人没有资格转生,需要18M修为!\n");
}
    if ( (int)obj->query("max_neili") < 6000)
{
command("say 你没有资格转生!你的内力不足!!");
        return notify_fail("此人没有资格转生!\n");
}

   if(obj->query_skill("dodge",1)<400 ||
		obj->query_skill("force",1)<400 ||
		obj->query_skill("parry",1)<400 ||
		obj->query_skill("unarmed",1)<400 ||
		obj->query_skill("literate",1)<300)
{
command("say 你没有资格转生!你的武功等级不足!!");
        return notify_fail("此人没有资格转生!\n");
}

if (obj->query("guard/flag"))
{
    if (obj->query("guard/flag") && !obj->query("migong/lev12")
    ||!obj->query("migong/lev9")
    ||!obj->query("migong/lev10")
    ||!obj->query("migong/lev11"))
{
command("say 你没有资格3转!请至少完成迷宫任务到第12层!");
        return notify_fail("此人没有资格3转!\n");
}
}
    if (obj->query("guard/flag") && (int)obj->query("combat_exp") < 20000000 )
{
command("say 你没有资格3转!3转需要20M修为 ");
        return notify_fail("此人没有资格3转!3转需要20M修为\n");
}


if (obj->query("guard/flag")
&& (int)obj->query("combat_exp") > 20000000 )
{
obj->delete("last_alert");
    write(HIR"3转成功!\n"NOR);
obj->set("jiuyin/full",1);
    write(HIR"增加九阴!\n"NOR);
obj->set("szj/passed",1);
    write(HIR"增加神照!\n"NOR);
    obj->set("zhuanbest",1);
obj->delete("last_alert");
}
    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//删除自己所有功夫
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");
		obj->map_skill("finger");
		obj->map_skill("hand");
		obj->map_skill("cuff");
		obj->map_skill("claw");
		obj->map_skill("strike");

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");
		obj->prepare_skill("cuff");
		obj->prepare_skill("claw");
		obj->prepare_skill("strike");
                obj->reset_action();
        if ( obj->query("per") < 60)
        {
	obj->set("per",obj->query("per")+10);
        }
        if ( obj->query("str") < 60)
        {
	obj->set("str",obj->query("str")+10);
        }
        if ( obj->query("dex")< 60)
        {
	obj->set("dex",obj->query("dex")+10);
        }
        if ( obj->query("int")< 60)
        {
	obj->set("int",obj->query("int")+10);
        }
        if ( obj->query("con")< 60)
        {
	obj->set("con",obj->query("con")+10);
        }
        if ( obj->query("kar")< 60)
        {
	obj->set("kar",obj->query("kar")+10);
        }

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
                obj->set("combat_exp",0);
	obj->set("learned_points",0);
	obj->set("potential",obj->query("learned_points"));

	obj->delete("blade_get");
	obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
//obj->delete("jiuyin");
//obj->delete("szj");
//obj->delete("zhou");
obj->set("guard/flag",1);
obj->set("tforceok",2);
        obj->save();
    write(HIR"转生成功,请重新登陆!\n"NOR);
tell_object(obj,HIR"转生成功,请保存一下重新登陆!\n"NOR);
if (obj->query("zhuanbest"))
{
	log_file("static/ZS",
		sprintf("%s 三转，时间: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +"三转了。");
}
else
{
	log_file("static/ZS",
		sprintf("%s 二转，时间: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +"二转了。");
}
   // "/cmds/usr/quit"->main(obj);

    return 1;
}

int ask_force(string arg)
{
    int i,temp,j;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();
if (!arg)
return notify_fail("你要要做什么呢？\n");
if (obj->is_busy())
{
command("say 你正忙着呢!");
        return notify_fail("你正忙着呢!\n");
}
    if (obj->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if ( !obj->query("zhuanshen")
    &&!obj->query("guard/flag")
    &&!obj->query("zhuanbest")
    )
{
command("say 你没有能力使用两种内功!");
        return notify_fail("你没有资格使用两种内功!\n");
}
    if ( !obj->query("tforceok"))
{
command("say 你已经有这种能力了吗!");
        return notify_fail("你没有资格使用两种内功!\n");
}

    if ( (int)obj->query("tforceok")==1)
{
command("say 我不是已经给过你这种能力了吗!");
        return notify_fail("你没有资格使用两种内功!\n");
}

    if ( (int)obj->query("combat_exp") < 800000)
{
command("say 你先练一会武功再来!只有一次机会!!");
        return notify_fail("你先练一会武功再来!\n");
}
    if ( (int)obj->query("combat_exp") < 1000000)
{
command("say 你先练熟一种内功再来吧!只有一次机会!!");
        return notify_fail("你先练一会武功再来!\n");
}
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
j =0;
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
if (SKILL_D(sname[i])->exert_function_file()
&& sname[i]!="force"
&& sname[i]!="taixuan-gong"
&& sname[i]!="jiuyin-zhengong")
{
j=j+1;
}
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->query("name") +"共有" + j +"种内功。");
}
if (j < 1)
{
command("say 你先学一种内功再来!机会只给一次!!");
        return notify_fail("你先练一会武功再来!\n");
}

if (j > 5)
{
command("say 你已经有六种内功了!!机会只给一次!!");
        return notify_fail("你先练一会武功再来!\n");
}

if (arg=="wudang")
{
obj->set_skill("taiji-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );
}
else if (arg=="huashan")
{
obj->set_skill("zixia-shengong",105);
obj->set_skill("huashan-neigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );
}
else if (arg=="lingjiu")
{
obj->set_skill("beiming-shengong",105);
obj->set_skill("bahuang-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="mingjiao")
{
obj->set_skill("jiuyang-shengong",105);
obj->set_skill("shenghuo-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="shaolin")
{
obj->set_skill("yijinjing",105);
obj->set_skill("hunyuan-yiqi",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="xueshan")
{
obj->set_skill("longxiang",105);
obj->set_skill("xiaowuxiang",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="xiaoyao")
{
obj->set_skill("beiming-shengong",105);
obj->set_skill("bahuang-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="riyue")
{
obj->set_skill("kuihua-xinfa",105);
obj->set_skill("tmdafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}

else if (arg=="taohua")
{
obj->set_skill("bibo-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="tiandihui")
{
obj->set_skill("yunlong-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="gumu")
{
obj->set_skill("yunv-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="gaibang")
{
obj->set_skill("huntian-qigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="quanzhen")
{
obj->set_skill("xiantian-qigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="dali")
{
obj->set_skill("kurong-changong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="tiezhang")
{
obj->set_skill("guiyuan-tunafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="murong")
{
obj->set_skill("shenyuan-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="kunlun")
{
obj->set_skill("xuantian-wuji",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="lingxiao")
{
obj->set_skill("bingxue-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="wdjiao")
{
obj->set_skill("wudu-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="emei")
{
obj->set_skill("linji-zhuang",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="xingxiu")
{
obj->set_skill("huagong-dafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="shenlong")
{
obj->set_skill("shenlong-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="baituo")
{
obj->set_skill("hamagong",105);
obj->set("tforceok",1);

	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );
}
else if (arg=="tangmen")
{
obj->set_skill("biyun-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="feitian")
{
obj->set_skill("shayi-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else
command("say 武林中有很多种内功，分别为
\t\t武当派\t\t(wudang)
\t\t华山派\t\t(huashan)
\t\t灵鹫宫\t\t(lingjiu)
\t\t桃花岛\t\t(taohua)
\t\t天地会\t\t(tiandihui)
\t\t明教\t\t(mingjiao)
\t\t古墓派\t\t(gumu)
\t\t丐帮\t\t(gaibang)
\t\t全真教\t\t(quanzhen)
\t\t大理\t\t(dali)
\t\t铁掌帮\t\t(tiezhang)
\t\t慕容世家\t(murong)
\t\t昆仑派\t\t(kunlun)
\t\t凌霄城\t\t(lingxiao)
\t\t五毒教\t\t(wdjiao)
\t\t少林派\t\t(shaolin)
\t\t峨嵋派\t\t(emei)
\t\t星宿派\t\t(xingxiu)
\t\t神龙教\t\t(shenlong)
\t\t白驼山\t\t(baituo)
\t\t唐门\t\t(tangmen)
\t\t飞天御剑流\t(feitian)
\t\t雪山寺\t\t(xueshan)
\t\t逍遥派\t\t(xiaoyao)
\t\t日月神教\t(riyue)
你想要哪一门内功为辅助！");
    "/cmds/usr/save"->main(obj);
if (!wizardp(obj))
obj->start_busy(8);
    return 1;
}

int ask_force2()
{
    int i,temp,j;
    object obj;

obj=this_player();

if (obj->is_busy())
{
command("say 你正忙着呢!");
        return notify_fail("你正忙着呢!\n");
}
    if (obj->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");


command("say 武林中有很多种内功，分别为
\t\t武当派\t\t(wudang)
\t\t华山派\t\t(huashan)
\t\t灵鹫宫\t\t(lingjiu)
\t\t桃花岛\t\t(taohua)
\t\t天地会\t\t(tiandihui)
\t\t明教\t\t(mingjiao)
\t\t古墓派\t\t(gumu)
\t\t丐帮\t\t(gaibang)
\t\t全真教\t\t(quanzhen)
\t\t大理\t\t(dali)
\t\t铁掌帮\t\t(tiezhang)
\t\t慕容世家\t(murong)
\t\t昆仑派\t\t(kunlun)
\t\t凌霄城\t\t(lingxiao)
\t\t五毒教\t\t(wdjiao)
\t\t少林派\t\t(shaolin)
\t\t峨嵋派\t\t(emei)
\t\t星宿派\t\t(xingxiu)
\t\t神龙教\t\t(shenlong)
\t\t白驼山\t\t(baituo)
\t\t唐门\t\t(tangmen)
\t\t飞天御剑流\t(feitian)
\t\t雪山寺\t\t(xueshan)
\t\t逍遥派\t\t(xiaoyao)
\t\t日月神教\t(riyue)
你想(yaoforce)要哪一门内功为辅助！");
if (!wizardp(obj))
obj->start_busy(8);
    return 1;
}

int ask_zs3()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");

     if(obj->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if (!obj->query("4zhuan")
    && !obj->query("5zhuan"))
{
command("say 你没有资格要技能!");
        return notify_fail("此人没有资格要技能\n");
}
    if ( (int)obj->query("combat_exp") < 800000)
{
command("say 你修为高点再来要吧!");
        return notify_fail("你修为高点再来要吧!\n");
}
    if ( (int)obj->query("max_neili") < 1000)
{
command("say 你没有资格转生!你的内力不足!!");
        return notify_fail("此人没有资格转生!\n");
}
if (obj->query("4zhuan",1) || obj->query("5zhuan",1))
{
obj->set_skill("tianrenheyi",105);
write(HIY"获得武功【归真道经】!\n"NOR);
}

if (obj->query("zhuanfinal/7",1)==1)
{
obj->set_skill("yinyang-shiertian",105);
write(HIY"获得武功【太始帝经】!\n"NOR);
}
if (obj->query("zhuanfinal/8",1)==1)
{
obj->set_skill("never-defeated",105);
write(HIY"获得武功【不败神功】!\n"NOR);
}
    write(HIR"技能获得成功!\n"NOR);
tell_object(obj,HIR"技能获得成功!\n"NOR);
    return 1;
}


int ask_zs4()
{
    int i,temp,maxexp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");

     if(obj->is_busy())
        return notify_fail("你现在正忙着呢。\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if (!obj->query("4zhuan")
    && !obj->query("5zhuan"))
{
command("say 你不需要要获得成长资历!");
        return notify_fail("此人不需要要获得成长资历\n");
}
    if ( (int)obj->query("combat_exp") < 590000)
{
command("say 你修为高点再来要吧!");
        return notify_fail("你修为高点再来要吧!\n");
}
    if ( (int)obj->query("max_neili") < 1000)
{
command("say 你没有资格转生!你的内力不足!!");
        return notify_fail("此人没有资格转生!\n");
}

    /*if ( (int)obj->query_temp("menpaijob",1) < 5)
	{
			command("say 你还没有做满5个门派任务呢!!");
			return notify_fail("你还没有做满12个门派任务呢!!\n");
	}*/

	maxexp=6000000+(obj->query("expmax",1)*500000);

    if ( (maxexp-(int)obj->query("combat_exp",1)) > 800000)
	{
			command("say 你没有达到成长瓶颈，不需来!");
			return notify_fail("你没有达到成长瓶颈，不需来!\n");
	}


	/*if (obj->query_temp("menpaijob",1) >= 5)
	{
		if (obj->query("expmax",1) < 1)
		{
			obj->set("expmax",1);
		}
		else
		{
			obj->add("expmax",1);
		}
	}*/
	obj->add("expmax",1);
	obj->set_temp("menpaijob",0);
	tell_object(obj,HIR"成长资历获得成功!\n"NOR);
    return 1;
}

/*

int ask_ggs()
{
	object me,ob;
	int this_week = time()/86400/7;
	ob = this_object();
	me = this_player();


	if (me->query("registered")!=3)
	{
		tell_object(me, "对不起啊，目前武曲附体只对会员开放强化学习功能。\n");
		return 1;
	}

	if(!me->query("ggs/last_week") || me->query("ggs/last_week")=="" || me->query("ggs/last_week")!=this_week)
	{
		me->set("ggs/last_week", this_week);
		me->set("ggs/started",0);
		me->set("ggs/start_time","");
		me->set("ggs/over_time","");
		me->set("ggs/left_time",10*3600);
	}

	//For all Bug By Ciwei@SJ
	while(me->query("ggs/left_time")>10*3600)
		me->add("ggs/left_time",-10*3600);

	if(me->query("ggs/left_time") < 1)
	{
		command("say 你虽然天资聪慧，但是贪多嚼不烂，不能再冒进了，请下周再来询问吧。");
		return 1;
	}
	if(me->query("ggs/started")==1)
	{
		if(me->query_temp("ggs/started")=="")
		{
			tell_object(me, "你先要问我休息，才能再开始使用武曲附体。\n");
		}
		else
		{
			tell_object(me, "你不是正在研习修炼武曲附体中么？还不快点抓紧时间……\n");
			command("kick " + me->query("id"));
		}
		return 1;
	}

	me->set("ggs/started",1); //使用状态标记
	me->set_temp("ggs/started",1); //使用状态标记
	me->set("ggs/start_time",time()); //使用状态标记

	me->apply_condition("guigushu",1); //这个condition 不会自动减少
	tell_object(me, "武曲附体，是我这些年精心研究的修心妙法，若能参悟，可以加倍提高学习领悟的能力。\n");
	tell_object(me, "不过武曲附体博大渊深，甚劳心神，每周最多也就应用十个小时吧。\n");
	tell_object(me, "现在是 "+ CHINESE_D->chinese_date(time(),1) + "。");
	tell_object(me, "你本周还可以使用武曲附体"+CHINESE_D->chinese_time(me->query("ggs/left_time"))+"，现在开始计时了，切记在不使用时进行正常关闭，否则会浪费掉你的时间，或可能会出错减少时间。\n");

	//command("say 武曲附体，是我这些年精心研究的修心妙法，若能参悟，可以加倍提高学习领悟的能力。");
	//command("say 不过武曲附体博大渊深，甚劳心神，每周最多也就应用十个小时吧。");
	//command("look " + me->query("id"));
	//command("say 现在是 "+ CHINESE_D->chinese_date(time(),1) + "。");
	//command("say 你本周还可以使用武曲附体"+CHINESE_D->chinese_time(me->query("ggs/left_time"))+"，现在开始计时了，切记在不使用时进行正常关闭，否则会浪费掉你的时间，或可能会出错减少时间。");
	log_file( "quest/ggs",sprintf("%s(%s)在第%d周开始武曲附体,剩:%s.\n",
			me->name(),
			me->query("id"),
			this_week,
			CHINESE_D->chinese_time(me->query("ggs/left_time"))
			));

return 1;
}

int ask_ggso()
{
	object me,ob;
	int user_time;
	//int an_hour = 60*60*60;
	int this_week = time()/86400/7;
	ob = this_object();
	me = this_player();

	if (me->query("registered")!=3)
	{
		tell_object(me, "对不起啊，目前武曲附体只对会员开放强化学习功能。\n");
		return 1;
	}
	if(me->query("ggs/started")!=1)
	{
		command("say 还没有开始就要休息……");
		command("pig " + me->query("id"));
		return 1;
	}
	if(me->query_temp("ggs/started")!=1)
	{
		command("say 你是不是没问休息就下线了？结束时间就按照你上次下线时间算吧。");
		me->set("ggs/over_time",FINGER_D->get_last_on(me->query("id")));
	}
	else
	{
		me->set("ggs/over_time",time());
	}

	user_time=(int)me->query("ggs/over_time")-(int)me->query("ggs/start_time");
	tell_object(me, "是啊，劳逸结合，读书领悟久了，是该休息休息。\n");
	tell_object(me, "你的武曲附体开始时间是：" + CHINESE_D->chinese_date((int)me->query("ggs/start_time"),1) + "。\n");
	tell_object(me, "结束时间是：" + CHINESE_D->chinese_date((int)me->query("ggs/over_time"),1) + "。\n");
	tell_object(me, "这次你一共修炼了：" + CHINESE_D->chinese_time(user_time)+"。\n");

	me->set("ggs/left_time",me->query("ggs/left_time") - user_time);

	log_file( "quest/ggs",sprintf("%s(%s)在第%d周结束ggs,剩:%s,用:%s.\n",
			me->name(),
			me->query("id"),
			this_week,
			CHINESE_D->chinese_time(me->query("ggs/left_time")),
			CHINESE_D->chinese_time(user_time)
			));



	if (me->query("ggs/left_time") < 0 ) //防止bug
		me->set("ggs/left_time",0);

	if (me->query("ggs/left_time"))
		tell_object(me, "你本周还可以使用武曲附体"+CHINESE_D->chinese_time(me->query("ggs/left_time"))+"。\n");
		//command("say ");
	else
		command("say 你的武曲附体时间用完了，下周再来吧。");

	me->set_temp("ggs/started",0);
	me->set("ggs/started",0);
	me->set("ggs/start_time","");
	me->set("ggs/over_time","");

	me->clear_condition("guigushu"); //清除了


return 1;
}
*/