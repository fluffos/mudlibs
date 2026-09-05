//点石成金
//created by Zine 26 Oct 2010

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "master_title.h"
int ask_title();
int ask_canceltitle();
int ask_color();
int ask_intro();
int ask_title1();
int askforhelp();
int base_exp=1000000;
int *exp_require=({800,1600,3200,6400,12800});
mapping all_color=(["深红":HIR,"暗红":RED,"深绿":HIG,"暗绿":GRN,"深黄":HIY,"暗黄":YEL,"深蓝":HIB,"暗蓝":BLU,"深紫":MAG,"暗紫":HIM,"天青":HIC,"靛青":CYN,"深白":HIW,"暗白":WHT]);
void create()
{
        set_name("北丑", ({ "bei chou","chou","bei"}) );
        set("gender", "男性" );
		
        set("age", 99);
        set("long", 
            "他是专门记载武林掌故的与南贤齐名的武林前辈——北丑。\n");
        set("str", 30);
        set("dex", 30);
        set("con", 20);
        set("int", 60);
		set("shen_type", 1);
		set_skill("force", 50);
		set("combat_exp", 500000000);
		set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
		set("uni_target",1);
		set("attitude", "friendly");
        set("inquiry", ([
            "name" : "招牌都竖起来了，你不会看吗？",
            "here" : "这里繁华的洛阳城。",
			"title" : (: ask_title :),
            "字号" : (: ask_title :),
			"minghao" : (: ask_title1 :),
			"名" : (: ask_title1 :),
            "取消字号" : (: ask_canceltitle :),
			"color" : (: ask_color :),
			"名号" : (: ask_color :),
			"我能干什么" : (: ask_intro :),
			
			
            
       	]) );
		set("chat_chance", 10);
        set("chat_msg", ({
                
                (:askforhelp:),
        }) );
        setup();
        
		carry_object("/d/city/npc/items/cloth1")->wear();

}

void init()
{
	add_action("do_colorselect", ({ "select" }));
	add_action("do_xuan","xuan");
	add_action("do_recolor","recolor");
}
int do_recolor()
{
	object me=this_player();
	if (!me->query("MyColors")) return notify_fail("你现在没有保存的个人颜色。\n");
	if (me->query("MyColor_ReSelect")) return notify_fail("你已经重新选择过了。\n");
	if (me->query("combat_exp")<800000000) return notify_fail("800M以下如果没有换过新颜色，可以直接ask bei chou about color换新颜色。\n");
	me->set("MyColor_ReSelect",1);
	me->delete("MyColors");
	command("say 你现在可以重新选择了。");
	return 1;
}
int askforhelp()
{
    if (random(100)>95&&time()-(int)this_object()->query("time")>600)
    {
        this_object()->set("time",time());
        CHANNEL_D->do_channel(this_object(), "jh", "实名认证玩家可来洛阳庙会ask bei chou about minghao咨询特殊新title事宜。");
    }
        
}

void unconcious()
{
        die();
}

void die()
{
        message_vision("$N道，难道你不知道尊重老年人吗？\n",this_object());
        this_object()->fullme();
        return;
}

int ask_intro()
{
    object ob=this_object();
    if (ob->is_busy() || ob->is_fighting())
	{
        command("say 没看我正忙着吗？\n");
		return 1;
    }
    else
    {
        command("say 嘿嘿，我能干得可多了。\n");
        command("say 最重要的就是帮人擦亮字号。\n");
        command("say 包装！你懂什么叫包装吗？\n");
        command("say 问我关于字号的消息，如果满足条件我会赠你一个响亮的字号，让江湖中人刮目相看。\n");
        command("say 问我关于名号的消息，如果你满足条件，我会帮你的名头在江湖中擦亮。\n");
        ob->add_busy(2);
        return 1;
    }
}

int do_xuan(string arg)
{
	object me=this_player();
	string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
    int i,flag=0;
    mapping title;
    if (!me->query_temp("personal_title_select"))
    {
        return 0;
    }
    if (!arg)
    {
        return notify_fail("你必须指定一个头衔，如不清楚，可以用ask master about 名号了解详情\n。");
    }
    for (i=0;i<sizeof(vip_titles);i++)
    {
        if (arg==vip_titles[i]["title"])
        {
            title=vip_titles[i];
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        for (i=0;i<sizeof(titles);i++)
        {
            if (arg==titles[i]["title"])
            {
                title=titles[i];
                flag=1;
                break;
            }
        }
    }
	if (flag==0)
	{
		return notify_fail("暂不支持自定义名号，你要选取的名号必须在列表中。\n");
	}
    if (title["gender"]!=""&&title["gender"]!=me->query("gender"))
    {
        return notify_fail("只有"+title["gender"]+"被尊称"+arg+"才比较合适！\n");
    }
    if (title["family"]!=""&&title["family"]!=me->query("family/family_name"))
    {
        return notify_fail("一般情况下，只有"+title["family"]+"的弟子才会被尊称"+arg+"！\n");
    }
    me->delete_temp("personal_title_select");
	me->set("honorbonus/oldtitle",me->query("title"));
    me->set("title",color[random(sizeof(color))]+arg+NOR);
	me->set_title(TITLE_HONOR, me->query("title"));
    me->set("honorbonus/honortitle",me->query("title"));
	me->set("honorbonus/realuser_title",1);
	CHANNEL_D->do_channel(this_object(), "jh", "今日"+me->query("name")+"名望一时无两，大家应该尊称一声"+me->query("title")+"。");
	return 1;
}

int ask_title1()
{
	object me=this_player();
	object ob=this_object();
	object user=me->query_temp("link_ob");
	if (ob->is_busy() || ob->is_fighting())
	{
        command("say 没看我正忙着吗？\n");
		return 1;
    }
	if (!user->query("realuser_verified"))
    {
		tell_object(me,"只有通过实名认证的玩家才可自定义头衔。\n");
		return 1;
    }
	if ((me->query("jobs/completed/task")<100 && me->query("jobs/completed/xiaofeng")<100)
		|| me->query("jobs/completed/hubiao")<100 
		|| me->query("jobs/completed/huyidao")<100
		|| me->query("newjobs/completed/hyw")<100
		|| me->query("newjobs/completed/pyh")<10 )
    {
		command("say 你还是去多做做各种主流任务，等满足以下条件再来找我吧。\n");
		tell_object(me,"TASK或萧峰任务至少有一项大于100次，护镖大于100次，胡一刀大于100次，韩员外大于100次，鄱阳湖寻宝大于10次。\n");
        return 1;
	}
	if (me->query("honorbonus/realuser_title"))
	{
		command("say 选过就不能再换了。");
		return 1;
	}
	tell_object(me, "你太厉害了，江湖中人常用的头衔有“万里追风”，“月夜人屠”，“千人斩”，“万人斩”，“剑胆琴心”,
“剑神”，“潇湘夜雨”，“狂风快剑”，“银钩铁划”，“河洛一剑”，“神机子”，“五花箭神”，“飞剑
客”，“血手天魔”，“血衣人”，“蝙蝠公子”,“大漠孤鸿”这些。\n");
	tell_object(me, HIY+"另有一些响亮的字号就不是人人可以拥有的了。“陆上龙王”，“塞上神龙”，“白玉魔丐”，“毒手书生”，
“九天鬼帝”，“九玄神丐”，“妙僧”，“神剑宰相”，“海棠仙子”，“断魂刀”，“断魂剑”，“毒手搜
魂”，“怒箭神弓斩鬼刀”，“魔眼摄魂”，“毒郎君”，“哀魔”，“大欢喜女菩萨”，“半面罗刹”，“地
煞”，“剑底游魂”，“锦衣侯”，“七指神偷”，“快活王”，“销魂夫人”，“玉面瑶琴神剑手”，“芙蓉
仙子”，“杀手之王”，“生死判”，“香川圣女”，“鬼王”，“鬼谷隐叟”，“朝阳夫人”，“云梦仙子”，
“鬼影无双”这些。\n"+NOR);
	tell_object(me, HIG+"你可以从中指定自己喜欢的头衔，用"+HIW+"xuan"+HIG+" 命令获得，比如"+HIW+"xuan 陆上龙王"+HIG+"，你就获得了这个头衔，以上提到的所
有头衔都可选择，后一列只对认证玩家开放。\n"+NOR);
	me->set_temp("personal_title_select",1);
	return 1;
}

int ask_title()
{
    string* title=({"万里追风","月夜人屠","千人斩","万人斩","剑胆琴心","剑神","潇湘夜雨","狂风快剑","银钩铁划","河洛一剑","神机子","五花箭神","飞剑客","血手天魔","血衣人","蝙蝠公子","大漠孤鸿"});
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
    object me=this_player();
    object ob=this_object();
    if (me->query("honorbonus/titlegiven"))
    {
        command("say 你不是要过头衔了嘛？不要贪得无厌啊！\n");
		return 1;
    }
    if (me->query("honorbonus/realuser_title")&&!me->query_temp("honorbonus/change_title_from_real"))
	{
        me->set_temp("honorbonus/change_title_from_real",1);
		command("say 你已经选过实名用户尊称了，再选就会覆盖掉以前的尊称，如愿意再次输入ask master about title。");
		return 1;
	}
    if (ob->is_busy() || ob->is_fighting())
	{
        command("say 没看我正忙着吗？\n");
		return 1;
    }
    if ((me->query("jobs/completed/task")>300 && me->query("jobs/completed/hubiao")>300 && me->query("jobs/completed/huyidao")>300 && me->query("jobs/completed/xiaofeng")>300)||me->query("jobs/completed/task")>1000 || me->query("jobs/completed/hubiao")>3000 || me->query("jobs/completed/huyidao")>1500 || me->query("jobs/completed/xiaofeng")>1800)
    {
        command("say 哇，你真蛮厉害的。\n");
        me->set("honorbonus/oldtitle",me->query("title"));
        me->set("title",color[random(sizeof(color))]+title[random(sizeof(title))]+NOR);
//title系统记录玩家title by seagate@pkuxkx
	      me->set_title(TITLE_HONOR, me->query("title"));
        me->set("honorbonus/honortitle",me->query("title"));
        me->set("honorbonus/titlegiven",1);
        command("say 照我看，武林中人应该尊称你一声"+me->query("title")+"。\n");
        return 1;
    }
    
    else
    {
        command("say 你还是去多做做主流任务，把名头擦亮了再来找我吧。\n");
        return 1;
    }
}

int ask_canceltitle()
{
    object me=this_player();
    if (!me->query("honorbonus/titlegiven"))
    {
        command("hmm");
        command("say 你来捣乱的吧？我什么时候赠你过名号？");
        return 1;
    }
    else
    {
        if (me->query("honorbonus/oldtitle"))
        {
            if (me->query("title")==me->query("honorbonus/honortitle"))
            {
                me->set("title",me->query("honorbonus/oldtitle"));
                command("hmm");
                command("say 既然你不喜欢我赠你的名号，那我帮你取消了它吧。");
                return 1;
            }
            else
            {
                command("say 你现在的名号和我以前给你的不符啊！");
                return 1;
            }

        }
        else
        {
            command("say 瞧我着记性，你原来叫什么我完全记不得啦。");
            return 1;
        }
    }

}
int color_me(object me,string color_desc,int flag)
{
	string *my_colors=({});
	if (!flag)
	{
		if (me->query("MyColors")&&arrayp(me->query("MyColors")))
		my_colors=me->query("MyColors");
		if (member_array(color_desc,my_colors)!=-1)
		{
			command("say 你已经拥有"+all_color[color_desc]+color_desc+NOR+"这种颜色了。");
			return 1;
		}
		my_colors+=({color_desc});
		me->set("MyColors",my_colors);
		me->set("honorbonus/colored",1);
		me->delete_temp("colorselect");
	}
	else
	{
		if (COLOR_D->get_color(me->query("name"))==all_color[color_desc])
		{
			command("say 你不是正用着这个颜色作为主色吗？");
			return 1;
		}
	}
	tell_object(me,"你选择了"+all_color[color_desc]+color_desc+NOR+"作为你的主色，伴你闯荡江湖。\n");
	me->set("name",all_color[color_desc]+COLOR_D->uncolor(me->query("name"))+NOR);
	me->set_face( FACE_FACT, me->query("name") );
	if (!flag)
	{
		if (me->query("MyColors")&&sizeof(me->query("MyColors"))>1)
		CHANNEL_D->do_channel(this_object(), "jh", "江湖同道们，今日"+me->query("name")+"获得了个人第"+chinese_number(sizeof(me->query("MyColors")))+"种颜色，成为武林中的一个神话。");
		else
		CHANNEL_D->do_channel(this_object(), "jh", "江湖同道们，今日"+me->query("name")+"达到个人声望顶峰，成为武林中的一个传奇。");
	}
	return 1;
}
int do_colorselect(string arg)
{
    object me=this_player();
	int flag=0;
    if (!me->query_temp("colorselect")) 
	{
		if (!me->query("MyColors")||(me->query("MyColors")&&!arrayp(me->query("MyColors"))))
		return 0;
		if (sizeof(me->query("MyColors"))<2)
		return 0;
		if (!arg) 0;
		if (member_array(arg,me->query("MyColors"))==-1)
		{
			command("tell "+me->query("id")+" 拥有多种颜色的玩家，调换名号颜色只能用中文。你可用的颜色有：");
			for (int i=0;i<sizeof(me->query("MyColors"));i++)
			command("tell "+me->query("id")+" "+all_color[me->query("MyColors")[i]]+me->query("MyColors")[i]+NOR);
			return 1;
		}
		else flag=1;		
	}
    if (!arg) return notify_fail("你必须指定一种颜色。");
	if (arg=="深红"||arg=="HIR") return color_me(me,"深红",flag);
	else if (arg=="暗红"||arg=="RED") return color_me(me,"暗红",flag);
    else if (arg=="深绿"||arg=="HIG") return color_me(me,"深绿",flag);
    else if (arg=="暗绿"||arg=="GRN") return color_me(me,"暗绿",flag);
    else if (arg=="深黄"||arg=="HIY") return color_me(me,"深黄",flag);
    else if (arg=="暗黄"||arg=="YEL") return color_me(me,"暗黄",flag);
    else if (arg=="深蓝"||arg=="HIB") return color_me(me,"深蓝",flag);
    else if (arg=="暗蓝"||arg=="BLU") return color_me(me,"暗蓝",flag);
    else if (arg=="深紫"||arg=="MAG") return color_me(me,"深紫",flag);
    else if (arg=="暗紫"||arg=="HIM") return color_me(me,"暗紫",flag);
    else if (arg=="天青"||arg=="HIC") return color_me(me,"天青",flag);
    else if (arg=="靛青"||arg=="CYN") return color_me(me,"靛青",flag);
    else if (arg=="深白"||arg=="HIW") return color_me(me,"深白",flag);
    else if (arg=="暗白"||arg=="WHT") return color_me(me,"暗白",flag);
    else return notify_fail("有这种颜色吗？\n");
}
int my_chance(object me)
{
	int chance=0,exp=me->query("combat_exp")/base_exp;
	for (int i=0;i<sizeof(exp_require);i++)
	{
		if (exp>exp_require[0]&&exp<exp_require[i])
		{
			chance=1+i;
			break;
		}
	}
	if (chance==0&&me->query("MyColor_ReSelect")) return -100;
	if (me->query("MyColors")&&!arrayp(me->query("MyColors"))) return -99;
	if (me->query("MyColors")&&arrayp(me->query("MyColors"))&&chance<=sizeof(me->query("MyColors"))) return chance-sizeof(me->query("MyColors"));
	return 1;
}
int ask_color()
{
    object me=this_player();
	int chance=my_chance(me);
    if (me->query("honorbonus/colored")&&chance<=0)
    {	
		if (chance==-100)
        command("say 你选择过一种颜色了，已经没有后悔的余地了。");
		else if (chance==-99)
		command("say 你的个人颜色库出错了，找巫师吧。");
		else if (chance>-99)
		{
			if (sizeof(me->query("MyColors"))<6)
			command("say 只有获得"+exp_require[sizeof(me->query("MyColors"))-1]+"M经验后你才能选择第"+chinese_number(sizeof(me->query("MyColors"))+1)+"种颜色。");
			else
			command("say 你不可能获得更多颜色了。");
		}
		return 1;
    }
    
    if (me->query("combat_exp")>=400000000 || (me->query("combat_exp")>=200000000 && me->query("jobs/completed/task")>1000 && me->query("jobs/completed/hubiao")>5000 && me->query("jobs/completed/huyidao")>2000 && me->query("jobs/completed/xiaofeng")>2000))
    {
        command("say 好吧，我来帮你擦亮字号，但是记住，人一辈子只能选择一次的哦，一定要慎重。");
        tell_object(me,"你可以选择(select)"+HIR+"深红"+NOR+"、"+RED+"暗红"+NOR+"、"+HIG+"深绿"+NOR+"、"+GRN+"暗绿"+NOR+"、"+HIY+"深黄"+NOR+"、"+YEL+"暗黄"+NOR+"、"+HIB+"深蓝"+NOR+"、"+BLU+"暗蓝"+NOR+"、"+MAG+"深紫"+NOR+"、\n"+HIM+"暗紫"+NOR+"、"+HIC+"天青"+NOR+"、"+CYN+"靛青"+NOR+"、"+HIW+"深白"+NOR+"、"+WHT+"暗白"+NOR+"这几种颜色来打响自己的字号。\n");
        me->set_temp("colorselect",1);
        return 1;
    }
    else
    {
        command("say 不好意思啊，非得个人名声达到顶峰，我才能帮你擦亮名号。");
        return 1;
    }
}