#include <ansi.h>
inherit NPC;
int ask_force2();
int ask_force(string arg);
int ask_me();
int ask_zs1();
int ask_zs2();
string ask_clear();
string ask_buchang();
string ask_panshi();
string ask_job();
#include "/clone/guard/party.h"
//int ask_gift();
int ask_bing();
int ask_yahuan();
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
	set("qi",   99999999);
	set("jing", 99999999);
	set("eff_qi",   99999999);
	set("eff_jing", 99999999);
	set("max_qi",   99999999);
	set("max_jing", 99999999);
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
            "book": "神书共有四十二本，你可以用help tasks获得有关方面知识！",
            "shi": "只有靠"HIR"七"+HIC+"彩"+HIY+"向"+HIM+"导"+HIG+"石"NOR+CYN"才能找到神书，灵石二十两一块！",
	     "mengzhu": (: ask_me :),
	     "一转": (: ask_zs1 :),
	     "二转": (: ask_zs2 :),
	     "三转": (: ask_zs2 :),
	     "zhuanshen": (: ask_zs1 :),
	     "zhuanshenup": (: ask_zs2 :),
	     "双内功": (: ask_force2 :),
	     "force": (: ask_force2 :),
	     "任务":(: ask_job :),
	     "job":(: ask_job :),
		"随从": (: ask_yahuan :),
		"guard": (: ask_yahuan :),
//重要，申请和发礼物，只能开放一个，发礼物时关申请!!申请是关发礼物!!
	     "申请礼物":(: ask_clear :),
	     "yaogift":(: ask_clear :),
//             "gift":(: ask_buchang :),
//	     "春节":(: ask_buchang :),
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
if(this_player()->query("combat_exp")<1500000)  tell_object(this_player(),"无名居士说道：你经验太低，想要做盟主，必死无疑！\n");
else {
tell_object(this_player(),"无名居士说道： 好吧，里面危险重重，千万别乱来，否则有生命危险。自己小心吧！\n");
this_player()->move("/d/biwu/hole");
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

	me->delete("guard");
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
//        ob->set_amount(1);
//        ob->move(me);
return HIW"“这位"+RANK_D->query_respect(me)+"春节快乐。"NOR;
}
string ask_clear()
{
        mapping quest,item,npc;
        object ob;
        object me=this_player();

 me->delete("liwuopen");

return HIW"“这位"+RANK_D->query_respect(me)+"你已经申请好了。"NOR;
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
    if ( (int)obj->query("combat_exp") < 5000000)
{
command("say 你没有资格转生!");
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
        if ( obj->query("per")*2 > 50)
        {
	obj->set("per",50);
        }
        else obj->set("per",obj->query("per")*2);

//2
        if ( obj->query("str")*2 > 50)
        {
	obj->set("str",50);
        }
        else obj->set("str",obj->query("str")*2);

//3
        if ( obj->query("dex")*2 > 50)
        {
	obj->set("dex",50);
        }
        else obj->set("dex",obj->query("dex")*2);

//4
        if ( obj->query("int")*2 > 50)
        {
	obj->set("int",50);
        }
        else obj->set("int",obj->query("int")*2);

//5
        if ( obj->query("con")*2 > 50)
        {
	obj->set("con",50);
        }
        else obj->set("con",obj->query("con")*2);


//6
        if ( obj->query("kar")*2 > 50)
        {
	obj->set("kar",50);
        }
        else obj->set("kar",obj->query("kar")*2);

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",100);
        obj->set("max_jing",100);
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
        obj->set("PKS",0);
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
    if ( (int)obj->query("combat_exp") < 8000000)
{
command("say 你没有资格转生!");
        return notify_fail("此人没有资格转生!\n");
}
    if (obj->query("guard/flag") && (int)obj->query("combat_exp") < 20000000 )
{
command("say 你没有资格3转!");
        return notify_fail("此人没有资格3转!\n");
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
	obj->set("per",60);
        }
        if ( obj->query("str") < 60)
        {
	obj->set("str",60);
        }
        if ( obj->query("dex")< 60)
        {
	obj->set("dex",60);
        }
        if ( obj->query("int")< 60)
        {
	obj->set("int",60);
        }
        if ( obj->query("con")< 60)
        {
	obj->set("con",60);
        }
        if ( obj->query("kar")< 60)
        {
	obj->set("kar",60);
        }

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",100);
        obj->set("max_jing",100);
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
        obj->set("PKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
                obj->set("combat_exp",0);
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));

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
tell_object(obj,HIR"转生成功,请重新登陆!\n"NOR);
if (obj->query("zhuanbest"))
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +"三转了。");
else
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +"二转了。");
    "/cmds/usr/quit"->main(obj);

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
&& sname[i]!="taixuan-gong")
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

if (j > 4) 
{
command("say 你已经有四种内功了!!机会只给一次!!");
        return notify_fail("你先练一会武功再来!\n");
}

if (arg=="wudang")
{
obj->set_skill("taiji-shengong",100);
obj->set("tforceok",1);
}
else if (arg=="huashan")
{
obj->set_skill("zixia-shengong",100);
obj->set_skill("huashan-neigong",100);
obj->set("tforceok",1);
}
else if (arg=="lingjiu")
{
obj->set_skill("beiming-shengong",100);
obj->set_skill("bahuang-gong",100);
obj->set("tforceok",1);
}
else if (arg=="mingjiao")
{
obj->set_skill("jiuyang-shengong",100);
obj->set_skill("shenghuo-shengong",100);
obj->set("tforceok",1);
}
else if (arg=="shaolin")
{
obj->set_skill("yijinjing",100);
obj->set_skill("hunyuan-yiqi",100);
obj->set("tforceok",1);
}
else if (arg=="xueshan")
{
obj->set_skill("longxiang",100);
obj->set_skill("xiaowuxiang",100);
obj->set("tforceok",1);
}
else if (arg=="xiaoyao")
{
obj->set_skill("beiming-shengong",100);
obj->set_skill("bahuang-gong",100);
obj->set("tforceok",1);
}
else if (arg=="taohua")
{
obj->set_skill("bibo-shengong",100);
obj->set("tforceok",1);
}
else if (arg=="tiandihui")
{
obj->set_skill("yunlong-shengong",100);
obj->set("tforceok",1);
}
else if (arg=="gumu")
{
obj->set_skill("yunv-xinfa",100);
obj->set("tforceok",1);
}
else if (arg=="gaibang")
{
obj->set_skill("huntian-qigong",100);
obj->set("tforceok",1);
}
else if (arg=="quanzhen")
{
obj->set_skill("xiantian-qigong",100);
obj->set("tforceok",1);
}
else if (arg=="dali")
{
obj->set_skill("kurong-changong",100);
obj->set("tforceok",1);
}
else if (arg=="tiezhang")
{
obj->set_skill("guiyuan-tunafa",100);
obj->set("tforceok",1);
}
else if (arg=="murong")
{
obj->set_skill("shenyuan-gong",100);
obj->set("tforceok",1);
}
else if (arg=="kunlun")
{
obj->set_skill("xuantian-wuji",100);
obj->set("tforceok",1);
}
else if (arg=="lingxiao")
{
obj->set_skill("bingxue-xinfa",100);
obj->set("tforceok",1);
}
else if (arg=="wdjiao")
{
obj->set_skill("wudu-shengong",100);
obj->set("tforceok",1);
}
else if (arg=="emei")
{
obj->set_skill("linji-zhuang",100);
obj->set("tforceok",1);
}
else if (arg=="xingxiu")
{
obj->set_skill("huagong-dafa",100);
obj->set("tforceok",1);
}
else if (arg=="shenlong")
{
obj->set_skill("shenlong-xinfa",100);
obj->set("tforceok",1);
}
else if (arg=="baituo")
{
obj->set_skill("hamagong",100);
obj->set("tforceok",1);
}
else if (arg=="tangmen")
{
obj->set_skill("biyun-xinfa",100);
obj->set("tforceok",1);
}
else if (arg=="feitian")
{
obj->set_skill("shayi-xinfa",100);
obj->set("tforceok",1);
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
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +"获得了新的内功。");
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
