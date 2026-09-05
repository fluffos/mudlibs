inherit F_DBASE;
inherit F_SAVE;
#include <ansi.h>
#include <title.h>
#include "/d/song/config/jue.h"
#include "/d/song/config/id.h"
int get_my_pin(object me);
string song_title(object me);
object *song_all()
{
	return DASONG_D->song_players();
}
object record()
{
	return load_object("/d/song/record/positions");
}
mapping *departs()
{
	return "/d/song/config/all_positions"->departs();
}

mapping *juns()
{
	return "/d/song/config/all_positions"->juns();
}
mapping *lus()
{
	return "/d/song/config/all_positions"->lus();
}
string *zhous()
{
	return "/d/song/config/all_positions"->zhous();
}
mapping *upper_title()
{
	return "/d/song/config/all_positions"->upper_title();
}
mapping *lower_title()
{
	return "/d/song/config/all_positions"->lower_title();
}
 mapping *lowest_title()
 {
	 return "/d/song/config/all_positions"->lowest_title();
}
mapping *sanjie_title_huan()
{
	return "/d/song/config/all_positions"->sanjie_title_huan();
}
mapping *sanjie_title_wen()
{
	return "/d/song/config/all_positions"->sanjie_title_wen();
}
mapping *sanjie_title_wu()
{
	return "/d/song/config/all_positions"->sanjie_title_wu();
}
mapping *tiezhi()
{
	return "/d/song/config/all_positions"->tiezhi();
}
int assign_pro(object me)
{
	if (me->query("song/pro"))
	return 1;
	if (me->query("gender")=="无性")
	me->set("song/pro","宦");
	else
	me->set("song/pro",random(100)>49?"文":"武");
	return 1;
}
int if_give_tiezhi(object me)
{
	mapping *tz;
	if (!record()->query("tiezhi_list"))
	return 1;
	else
	tz=record()->query("tiezhi_list");
	for (int i=0;i<sizeof(tz);i++)
	{
		if (tz[i]["name"]==me->query("id")&&tz[i]["grant"]==get_my_pin(me))
		return 0;
	}
	return 1;
}
int get_tiezhi(object me,int flag)
{
	mapping *tz=tiezhi(),*give_outs;
	int i;
	string title="";
	if (me->query("song/pro")!="文"||get_my_pin(me)<1||get_my_pin(me)>4||!if_give_tiezhi(me))
	return 1;
	if (record()->query("tiezhi_list"))
	tz=record()->query("tiezhi_list");
	if (flag!=-1)
	{
		if (me->query("song/title")=="同中书门下平章事")
		{
			for (i=0;i<sizeof(tz);i++)
				if (tz[i]["xiang"]&&tz[i]["name"]=="")
				{
					tz[i]["name"]=me->query("id");
					me->set_title(TITLE_SONG3,tz[i]["title"]);
					title=tz[i]["title"];
					break;
				}
		}
		else if (me->query_temp("song/retire_xiang"))
		{
			me->delete_temp("song/retire_xiang");
			title="观文殿大学士";
			me->set_title(TITLE_SONG3,title);
		}
		else
		{
			for (i=0;i<sizeof(tz);i++)
				if (tz[i]["name"]==""&&!tz[i]["no_given"]&&get_my_pin(me)==tz[i]["grant"])
				{
					tz[i]["name"]=me->query("id");
					me->set_title(TITLE_SONG3,tz[i]["title"]);
					title=tz[i]["title"];
					break;
				}
		}
	}
	for (i=0;i<sizeof(tz);i++)
	{
		if (flag==-1&&tz[i]["name"]==me->query("id"))
		{
			tz[i]["name"]="";
			break;
		}
		if (tz[i]["name"]==me->query("id")&&tz[i]["title"]!=title&&title!="")
		{
			tz[i]["name"]="";
			break;
		}
	}
	if (title!="")
	tell_object(me,HIW+"恭喜你获得了"+title+"的馆阁贴职。\n"NOR);
	record()->set("tiezhi_list",tz);
	record()->save();
	return 1;
}

int xufeng(object me)
{//节度使2品或3500+，节度留后3品或3000+观察使4品团练使4品防御使4品刺使4品团练副使5品防御副使5品
	string xufeng_title=COLOR_D->uncolor(me->get_title(TITLE_SONG3)),*ranks=({"节度使","节度留后","观察使","团练使","防御使","刺使","团练副使","防御副使"});
	int current_rank=10;
	if (xufeng_title)
	{
		for (int i=0;i<sizeof(ranks);i++)
		{
			if (strsrch(xufeng_title,ranks[i])!=-1)
			current_rank=i;
		}
	}
	if (get_my_pin(me)<=2&&me->query("song/credit")>5000&&current_rank>0)
	{
		me->set_temp("song/xufeng","节度使");
	}
	else if (get_my_pin(me)<=3&&me->query("song/credit")>3500&&current_rank>1)
	{
		me->set_temp("song/xufeng","节度留后");
	}
	else if (get_my_pin(me)<=4)
	{
		if (me->query("song/credit")>2000&&current_rank>2)
		{
			me->set_temp("song/xufeng","观察使");
		}
		else if (me->query("song/credit")>1700&&current_rank>4)
		{
			me->set_temp("song/xufeng",random(2)?"团练使":"防御使");
		}
		else
		{
			me->set_temp("song/xufeng","刺使"&&current_rank>5);
		}
	}
	else if (get_my_pin(me)<=5&&current_rank>7)
	{
		me->set_temp("song/xufeng",random(2)?"团练副使":"防御副使");
	}
	if (!me->query_temp("song/xufeng"))
	return 1;
	else
	{
		song_title(me);
		tell_object(me,HIW+"恭喜你被虚封为"+me->get_title(TITLE_SONG3)+"。\n"NOR);
		return 2;
	}
}
mapping *sanjie_list(string pro)
{
	if (pro=="文")
	return sanjie_title_wen();
	else if (pro=="武")
	return sanjie_title_wu();
	else
	return sanjie_title_huan();
}
int jilu_pin(object me)//寄禄官品
{
	mapping *sanjie_list;
	string pro=me->query("song/pro");
	sanjie_list=sanjie_list(pro);
	for (int i=0;i<sizeof(sanjie_list);i++)
	if (me->get_title(TITLE_SONG2)==sanjie_list[i]["title"])
	return sanjie_list[i]["pin"];
	return -1;
}
int chaiqian_pin(object me)
{
	int i;
	mapping *list;
	list=upper_title();
	for (i=0;i<sizeof(list);i++)
	if (list[i]["title"]==me->query("song/title"))
	return list[i]["pin"];
	list=lower_title();
	for (i=0;i<sizeof(list);i++)
	if (list[i]["title"]==me->query("song/title"))
	return list[i]["pin"];
	list=lowest_title();
	for (i=0;i<sizeof(list);i++)
	if (list[i]["title"]==me->query("song/title"))
	return list[i]["pin"];
	return -1;
}
int get_my_pin(object me)
{
	int pin1,pin2;
	pin2=chaiqian_pin(me);
	pin1=jilu_pin(me);
	if (pin1<=0)
	pin1=0;
	if (pin2<=0)
	pin2=0;
	if (!pin1&&!pin2)
	return 10;
	if (pin1>pin2&&pin2>0)
	return pin2;
	return pin1;
}
string my_pin(object me)
{
	mapping *list;
	int i,pin1,pin2=0;
	string cpin1="",cpin2="";
	string pro=me->query("song/pro");
	
	list=upper_title();
	for (i=0;i<sizeof(list);i++)
	{
		if (list[i]["title"]==me->query("song/title"))
		{
			cpin2=list[i]["major"]?"正":"从";
			cpin2+=chinese_number(list[i]["pin"])+"品";
			pin2=list[i]["pin"]*10-list[i]["major"];
			break;
		}
	}
	if (pin2==0&&cpin2=="")
	{
		list=lower_title();
		for (i=0;i<sizeof(list);i++)
		{
			if (list[i]["title"]==me->query("song/title"))
			{
				pin2=list[i]["pin"]*10-list[i]["major"];
				cpin2=list[i]["major"]?"正":"从";
				cpin2+=chinese_number(list[i]["pin"])+"品";
				break;
			}
		}
	}
	if (pin2==0&&cpin2=="")
	{
		list=lowest_title();
		for (i=0;i<sizeof(list);i++)
		{
			if (list[i]["title"]==me->query("song/title"))
			{
				pin2=list[i]["pin"]*10-list[i]["major"];
				cpin2=list[i]["major"]?"正":"从";
				cpin2+=chinese_number(list[i]["pin"])+"品";
				break;
			}
		}
	}
	list=sanjie_list(pro);
	for (i=0;i<sizeof(list);i++)
	{
		if (list[i]["title"]==me->get_title(TITLE_SONG2))
		{
			pin1=list[i]["pin"]*10-list[i]["major"];
			cpin1=list[i]["is_major"]?"正":"从";
			cpin1+=chinese_number(list[i]["pin"])+"品";
			break;
		}
	}
	if (pin1>pin2&&pin2>0)
	return cpin2;
	else if (pin1<=0)
	return "不入品";
	return cpin1;
}
string get_pin(string pro,string title)
{
	mapping *sanjie_list;
	string pin;
	sanjie_list=sanjie_list(pro);
	for (int i=0;i<sizeof(sanjie_list);i++)
	{
		if (title==sanjie_list[i]["title"]&&!sanjie_list[i]["no_pin"])
		{
			if (sanjie_list[i]["pin"]==-1)
			return "不入品";
			pin=sanjie_list[i]["is_major"]?"正":"从";
			pin+=chinese_number(sanjie_list[i]["pin"])+"品";
			return pin;
		}
	}
	return "不入品";
}

int credit_accumulate_require(string pro,int duty_rank)
{
	int *wen=({1800,880,640,760,570,550,450,400,600,380,460,280,260,220,210,210,200,150,250,150,135,120,140,95,90,80,50,45,30,0});
	int *wu=({780,620,505,500,475,470,420,415,400,395,500,280,270,320,155,150,150,150,145,145,140,140,135,130,125,120,115,110,110,100,95,95,95,95,90,90,90,85,85,80,75,105,60,55,50,50,45,30,20,15,10,8,0});
	int *huan=({150,120,100,200,85,60,30,10,0});
	if (pro=="文")
	return wen[duty_rank];
	else if (pro=="武")
	return wu[duty_rank];
	else
	return huan[duty_rank];
}
int time_accumulate_require(string pro,int duty_rank)
{
	return credit_accumulate_require(pro,duty_rank)*3600;
}
int get_duty_rank_no(object me)
{
	return me->query("song/duty_rank");
}

int init_me_duty(object me)
{
	if (!me->query("song/duty_promote/credit"))
	me->set("song/duty_promote/credit",me->query("song/credit"));
	if (!me->query("song/duty_promote/promote_time"))
	me->set("song/duty_promote/promote_time",me->query("mud_age"));
	me->save();
	return 1;
}
int get_new_duty(object me)
{
	string pro;
	int credit,i;
	int *wen=({1800,880,640,760,570,550,450,400,600,380,460,280,260,220,210,210,200,150,250,150,135,120,140,95,90,80,50,45,30,0});
	int *wu=({780,620,505,500,475,470,420,415,400,395,500,280,270,320,155,150,150,150,145,145,140,140,135,130,125,120,115,110,110,100,95,95,95,95,90,90,90,85,85,80,75,105,60,55,50,50,45,30,20,15,10,8,0});
	int *huan=({150,120,100,200,85,60,30,10,0}),*credits;
	pro=me->query("song/pro");
	credit=me->query("song/credit")*8/10;
	if (pro=="文")
	credits=wen;
	else if (pro=="武")
	credits=wu;
	else if (pro=="宦")
	credits=huan;
	for (i=sizeof(credits)-1;i>=0;i--)
	{
		credit-=credits[i];
		if (credit<=0)
		return i;
	}
}
int init_sanjie(object me)//大明转大宋专用，只用一次
{
	string pro;
	mapping *sanjie_list;
	int duty;
	if (!me->query("song/pro"))
	assign_pro(me);
	duty=get_new_duty(me);
	pro=me->query("song/pro");
	sanjie_list=sanjie_list(pro);
	me->set_title(TITLE_SONG2,sanjie_list[duty]["title"]);
	me->set("song/duty_rank",duty+1);
	init_me_duty(me);
	return 1;
}
int new_sanjie(object me)//新官
{
	string pro;
	mapping *sanjie_list;
	mapping buttom_rank=(["文":29,"武":51,"宦":8]);
	int duty;
	if (!me->query("song/pro"))
	assign_pro(me);
	pro=me->query("song/pro");
	sanjie_list=sanjie_list(pro);
	duty=buttom_rank[pro];
	me->set_title(TITLE_SONG2,sanjie_list[duty]["title"]);
	me->set("song/duty_rank",duty+1);
	init_me_duty(me);
	return 1;
}
int set_me_duty(object me)
{
	mapping *sanjie_list;
	string pro,pin;
	int duty,leap=0;
	if (!me->query("song/pro"))
	assign_pro(me);
	pro=me->query("song/pro");
	sanjie_list=sanjie_list(pro);
	duty=me->query("song/duty_rank");
	if (duty<1||(pro=="文"&&duty>30)||(pro=="宦"&&duty>9)||(pro=="武"&&duty>52))
	{
		log_file("user/song_error",sprintf("%s-%s-%s-%d\n",me->query("id"),pro,"rank:",duty));
		return 1;
	}
	if (duty==1)
	return 1;
	if ((me->query("mud_age")-me->query("song/duty_promote/promote_time")>=time_accumulate_require(pro,duty-1)&&get_my_pin(me)>6)||me->query("song/credit")-me->query("song/duty_promote/credit")>=credit_accumulate_require(pro,duty-1))
	{
		me->set("song/duty_promote/credit",me->query("song/credit"));
		me->set("song/duty_promote/promote_time",me->query("mud_age"));
		if (me->query("song/credit")-me->query("song/duty_promote/credit")>=credit_accumulate_require(pro,duty-1)*2)
		leap=1;
	}
	else if (me->query_temp("song/mokan_promote"))
	{
		me->set("song/duty_promote/credit",me->query("song/credit"));
		me->set("song/duty_promote/promote_time",me->query("mud_age"));
	}
	else
	return 1;
	duty-=1;
	if (duty>1&&leap)
	{
		duty-=1;
		leap=2;
	}
	me->set("song/duty_rank",duty);
	for (int i=0;i<sizeof(sanjie_list);i++)
	{
		if (sanjie_list[i]["rank"]==duty)
		{
			me->set_title(TITLE_SONG2,sanjie_list[i]["title"]);
			pin=get_pin(pro,me->get_title(TITLE_SONG2));
			if (leap==2)
			tell_object(me,"因为勤勉奉公，你被破格提升散阶至"+pin+me->get_title(TITLE_SONG2)+"。\n");
			else
			tell_object(me,"任上磨勘完成，你被提升散阶至"+pin+me->get_title(TITLE_SONG2)+"。\n");
			break;
		}
	}
	return 1;
}
int reset_me_duty(object me)
{
	int duty;
	mapping *sanjie_list;
	duty=get_new_duty(me);
	sanjie_list=sanjie_list(me->query("song/pro"));
	me->set_title(TITLE_SONG2,sanjie_list[duty]["title"]);
	me->set("song/duty_rank",duty+1);
	tell_object(me,"你的散阶变更为"+me->get_title(TITLE_SONG2)+"。\n");
	init_me_duty(me);
	return 1;
}
//部门相关
int get_my_depart(object me)
{
    mapping *titles;
    int i,pin=chaiqian_pin(me);
    string title=me->query("song/title");
    if (!pin||!title)
    return 0;
	if (pin<=3)
	titles=upper_title();
    else if (pin<=7)
	titles=lower_title();
	else
    titles=lowest_title();
    for (i=0;i<sizeof(titles);i++)
	if (title==titles[i]["title"])
	return titles[i]["department"];
	return 0;
}

string retro_classify_depart(string arg)
{
	mapping * departs=departs();
	for (int i=0;i<sizeof(departs);i++)
		if (arg==departs[i]["depart_id"])
			return departs[i]["depart_name"];
    return "NULL";
}
string classify_depart(object me)
{
	mapping * departs=departs();
	for (int i=0;i<sizeof(departs);i++)
		if (me->query("song/depart")==departs[i]["depart_no"])
		{
			me->set("song/depart_name",departs[i]["depart_name"]);
			return departs[i]["depart_id"];
		}
	return "NULL";
}
string add_officer_in(object me,string depart_name)
{
	mapping * departs=departs();
    int i,flag=0;
    string save_path,old_depart,*all_departs=({});
    if (!me)
    return "调动哪位官员？\n";  
    if (!depart_name)
	return "调动官员到哪个部门？\n";
	for (i=0;i<sizeof(departs);i++)
	{
		all_departs+=({departs[i]["depart_id"]});
	}
    if (member_array(depart_name,departs)==-1)
	return "没有这个部门。\n";
    for (i=100;i<301;i++) 
    {
        if (record()->query(depart_name+"/officers/"+i+"/id")==me->query("id"))
		return depart_name+"已有此官员记录。\n";
    }
    if (me->query("song/depart"))
	old_depart=classify_depart(me);
    if (me->query("song/depart_name_serial"))
	old_depart=me->query("song/depart_name_serial");
    for (i=100;i<301;i++) 
    {
        if (record()->query(old_depart+"/officers/"+i+"/id")==me->query("id"))
        {
            record()->delete(old_depart+"/officers/"+i);
            record()->save();
        }
    }
    for (i=100;i<301;i++)
    {
        save_path=depart_name+"/"+"officers/";
        if (!record()->query(save_path+i))
        {
            if (!userp(me))
			me->save_npc(save_path,i);
            else
            {
                record()->set(save_path+i+"/name",me->query("name"));
                record()->set(save_path+i+"/id",me->query("id"));
                record()->set(save_path+i+"/tongyu",me->query("song/ability/tongyu"));
                record()->set(save_path+i+"/zhengwu",me->query("song/ability/zhengwu"));
                record()->set(save_path+i+"/lianbing",me->query("song/ability/lianbing"));
                record()->set(save_path+i+"/renji",me->query("song/ability/renji"));
                record()->set(save_path+i+"/zhihui",me->query("song/ability/zhihui"));
                record()->set(save_path+i+"/qinmian",me->query("song/ability/qinmian"));
                record()->save();
            }
            me->set("song/depart_name_serial",depart_name);
            flag=1;
            return "添加官员记录成功。\n";
        }
    }
    if (flag==1)
	return "添加官员记录成功。\n";
    else
	return "添加官员失败，可能原因：人员超编。\n";
}
int delete_officer(object me)//非正常情况去除，玩家辞官,npc死亡。
{
    string old_depart;
    int i;
	if (!me)
	return 0;
    if (me->query("song/depart"))
	old_depart=classify_depart(me);
    if (me->query("song/depart_name_serial"))
	old_depart=me->query("song/depart_name_serial");
    for (i=100;i<301;i++) 
		if (record()->query(old_depart+"/officers/"+i+"/id")==me->query("id"))
		record()->delete(old_depart+"/officers/"+i);
	record()->save();
    return 1;
}

//升官相关
string random_unit(string unit)
{
	mapping * juns=juns();
	mapping * lus=lus();
	string *pre=({});
	if (unit=="jun")
	{
		for (int i=0;i<sizeof(juns);i++)
		pre+=({juns[i]["name"]});
	}
	if (unit=="lu")
	{
		for (int i=0;i<sizeof(lus);i++)
		pre+=({lus[i]["name"]});
	}
	if (unit=="zhou")
	{
		pre=zhous();
		return pre[random(sizeof(pre))]+"州";
	}
	return pre[random(sizeof(pre))];
}
string jun_lu(object me,string title,string type)
{
	mapping *records,trans=(["观察使":"guancha","节度使":"shi","节度留后":"liuhou","安抚使":"anfu","经略使":"jinglue","转运使":"zhuanyun","按察使":"ancha","都总管":"zongguan","副都总管":"fuzongguan","都钤辖":"qianxia"]);
	if (type=="JIEDUSHI")
	{
		if (record()->query("JIEDUSHI"))
		records=record()->query("JIEDUSHI");
		else
		records=juns();
	}
	if (type=="LU")
	{
		if (record()->query("LU"))
		records=record()->query("LU");
		else
		records=lus();
	}
	for (int i=0;i<sizeof(records);i++)
	{
		if (records[i][trans[title]]=="")
		{
			records[i][trans[title]]=me->query("id");
			record()->set(type,records);
			record()->save();
			return records[i]["name"];
		}
	}
	return "NULL";
}

mapping *giveouts(object ob,string savepath,mapping *backup)
{
	if (objectp(ob)&&ob->query(savepath))
	return ob->query(savepath);
	else
	return backup;
}
int prefix(object me,string title,mapping give_out)
{
	string *zhous=zhous();
	string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	//凡官员的寄禄官高于职事官一品的，带行字；寄禄官低于职事官一品的，带守字；寄禄官低于职事官二品以上者带试字
	//通常用于地方行政长官的差遣，例如知开封府、知杭州、知陈留县、知永兴军、知利国监；但也有中央部门负责官员如知枢密院事、知谏院、知审官院等；
	//判：通常用于一般行政部门主管的差遣，例如判太府寺事、判国子监事、判职方司等；
	//勾当：大多和军队有关，常见的就是以知州或知县的头衔勾当驻泊/屯驻禁军；
	string junlutitle,prefix,real_title="",*multis=({"节度使","节度留后","观察使",}),*multi_lu=({"安抚使","经略使","转运使","按察使","都总管","副都总管","都钤辖"}),*multi_zhou=({"团练使","防御使","团练副使","防御副使","刺史",}),*multi_zhou2=({"知"});
	int my_pin=jilu_pin(me),pin=give_out["pin"];
	if (my_pin==pin||pin==1||give_out["no_prefix"]||give_out["xufeng"])
	prefix="";
	else if (my_pin<pin)
	prefix="行";
	else if (my_pin-pin==1)
	prefix="守";
	else
	prefix="试";
	if (member_array(title,multis)!=-1)
	{
		junlutitle=jun_lu(me,title,"JIEDUSHI");
		if (junlutitle!="NULL")
		title=junlutitle+title;
	}
	if (member_array(title,multi_lu)!=-1)
	{
		junlutitle=jun_lu(me,title,"LU");
		if (junlutitle!="NULL")
		title=junlutitle+title;
	}
	if (member_array(title,multi_zhou)!=-1)
	title=zhous[random(sizeof(zhous))]+"州"+title;
	if (member_array(title,multi_zhou2)!=-1)
	title=title+zhous[random(sizeof(zhous))]+"州";
	if (give_out["random_unit"])
	title=random_unit(give_out["random_unit"])+title;
	me->set("title",color[random(sizeof(color))]+title+NOR);
	if (give_out["xufeng"])
	me->set_title(TITLE_SONG3,me->query("title"));
	else
	me->set_title(TITLE_SONG1,me->query("title"));
	return 1;
}
int success_got_title(mapping *give_outs,object me,string savepath,object ob,int i)
{
	if (give_outs[i]["vacancy"]>0)
	give_outs[i]["vacancy"]-=1;
	if (arrayp(give_outs[i]["owner"]))
	{
		give_outs[i]["owner"]+=({me->query("id")});
		give_outs[i]["owner_name"]+=({me->query("name")});
	}
	if (stringp(give_outs[i]["owner"])&&give_outs[i]["owner"]=="")
	{
		give_outs[i]["owner"]=me->query("id");
		give_outs[i]["owner_name"]=me->query("name");
	}
	if (savepath!="")
	{
		record()->set(savepath,give_outs);
		record()->save();
	}
	prefix(me,give_outs[i]["title"],give_outs[i]);
	me->delete_temp("song/anti_no_promote");
	me->set("song/last_promote_credit",me->query("song/credit"));
	if (give_outs[i]["term"])
	me->set("song/term/"+give_outs[i]["title"]+"/start_date",time());
	me->set_temp("song/promote/titles",give_outs[i]);
	return 1;
}
string get_prop_title(object me,object ob,string savepath,mapping *give_outs,string pro,int flag)
{
	for (int i=0;i<sizeof(give_outs);i++)
	{
		if ((stringp(give_outs[i]["owner"])&&give_outs[i]["owner"]!="")||((arrayp(give_outs[i]["owner"])||!give_outs[i]["owner"])&&give_outs[i]["vacancy"]<=0))
			continue;
		if (give_outs[i]["no_promote"]&&!me->query_temp("song/anti_no_promote")&&me->query_temp("song/hor_promote")!=3)
			continue;
		if ((jilu_pin(me)-give_outs[i]["pin"]>=3&&pro=="文")||(jilu_pin(me)-give_outs[i]["pin"]>=4&&pro!="文"))//寄禄官和差遣最多差2级。4品寄禄官可以干到2品参知政事。
			continue;
		if (give_outs[i]["term"]&&time()-me->query("song/term/"+give_outs[i]["title"]+"/start_date")<5184000)
			continue;
		if (give_outs[i]["credit"]>me->query("song/credit"))
			continue;
		if (give_outs[i]["pro"]!=pro&&give_outs[i]["pro"]!="兼")
			continue;
		if (me->query("song/title")&&strsrch(me->query("song/title"),give_outs[i]["title"])!=-1&&me->query("song/last_promote_credit")!=-1)
			continue;
		if (give_outs[i]["no_promote"]&&me->query_temp("song/hor_promote")!=3)
			continue;
		if (me->query_temp("song/hor_promote")==3&&give_outs[i]["title"]!=me->query_temp("song/hor_promote_title"))
			continue;
		if (give_outs[i]["title"]==me->query_temp("song/xufeng"))
		{
			success_got_title(give_outs,me,savepath,ob,i);
			me->delete_temp("song/xufeng");
			return "SUCCESS_GOT_PROP_TITLE";
		}
		if (me->query_temp("song/hor_promote")==3&&give_outs[i]["title"]==me->query_temp("song/hor_promote_title"))
		{
			success_got_title(give_outs,me,savepath,ob,i);
			return "SUCCESS_GOT_PROP_TITLE";
		}
		if (me->query_temp("song/must_transfer")||(me->query("song/last_promote_credit")&&give_outs[i]["credit"]>me->query("song/last_promote_credit"))||me->query("song/last_promote_credit")<=0)
		{
			success_got_title(give_outs,me,savepath,ob,i);
			me->delete_temp("song/must_transfer");
			return "SUCCESS_GOT_PROP_TITLE";
		}
		/*if (give_outs[i]["credit"]<=me->query("song/credit")&&give_outs[i]["pro"]==pro&&give_outs[i]["department"]==me->query("song/depart"))
			if ((flag==1&&(give_outs[i]["owner"]==""||give_outs[i]["vacancy"]>0))||(flag==2&&give_outs[i]["vacancy"]>0)||flag==3)
				suit_titles+=({give_outs[i]});*/
	}
	if (!mapp(me->query_temp("song/promote/titles")))//分配失败
	return "";
	
}

string assign_prop_title(object me)
{
	mapping give_title;
	string title;
	give_title=me->query_temp("song/promote/titles");
	title=give_title["title"];
	if (give_title["department"])
	me->set("song/depart",give_title["department"]);
	if (give_title["salary"])
	me->set("song/zhi_salary",give_title["salary"]);
	if (!me->query("song/salary_zhi"))
	me->set("song/salary_zhi",me->query("mud_age"));
	DASONG_D->reset_positions();
	return title;
}

string song_title(object me)
{
    mapping *give_outs;
    string pro;
	if (!me->query("song/pro"))
	assign_pro(me);
	if (me->query("song/suikao_longtime_not_in"))
	{
		tell_object(me,"朝中暂无职位，你且等一段时间吧。\n");
		return "";
	}
	pro=me->query("song/pro");
	give_outs=giveouts(record(),"give_titles",upper_title());
	if (get_prop_title(me,record(),"give_titles",give_outs,pro,1)!="SUCCESS_GOT_PROP_TITLE")
	{
		give_outs=giveouts(record(),"give_mediate_titles",lower_title());
		if (get_prop_title(me,record(),"give_mediate_titles",give_outs,pro,2)!="SUCCESS_GOT_PROP_TITLE")
		{
			give_outs=lowest_title();
			if (get_prop_title(me,record(),"",give_outs,pro,3)!="SUCCESS_GOT_PROP_TITLE")
			return "";
		}
	}
	return assign_prop_title(me);
}
int clear_position(object me,string unit)
{
	int i,j,no;
	mapping *jiedu,trans=(["观察使":"guancha","节度使":"shi","节度留后":"liuhou"]),trans2=(["安抚使":"anfu","经略使":"jinglue","转运使":"zhuanyun","按察使":"ancha"]);
	string *names=({"观察使","节度使","节度留后",}),*names2=({"安抚使","经略使","转运使","按察使","都总管","副都总管"});
	if (!me->query("song/title"))
		return 1;
	if (unit=="jun")
	{
		if (!record()->query("JIEDUSHI"))
		return 1;
		jiedu=record()->query("JIEDUSHI");
		for (i=0;i<sizeof(names);i++)
		if (strsrch(me->query("song/title"),names[i])!=-1)
		for (j=0;j<sizeof(jiedu);j++)
		if (jiedu[j][trans[names[i]]]==me->query("id")&&COLOR_D->uncolor(me->get_title(TITLE_SONG3))!=jiedu[j]["name"]+names[i])
		jiedu[j][trans[names[i]]]="";
		record()->set("JIEDUSHI",jiedu);
	}
	if (unit=="lu")
	{
		if (!record()->query("LU"))
		return 1;
		jiedu=record()->query("LU");
		for (i=0;i<sizeof(names2);i++)
		if (strsrch(me->query("song/title"),names2[i])!=-1)
		for (j=0;j<sizeof(jiedu);j++)
		if (jiedu[j][trans2[names2[i]]]==me->query("id")&&COLOR_D->uncolor(me->get_title(TITLE_SONG1))!=jiedu[j]["name"]+names2[i])
		jiedu[j][trans2[names2[i]]]="";
		record()->set("LU",jiedu);
	}
	if (unit=="all")
	{
		jiedu=record()->query("give_titles");
		for (i=0;i<sizeof(jiedu);i++)
		{
			if (jiedu[i]["multi"]&&strsrch(me->query("song/title"),jiedu[i]["title"])!=-1)
			{
				no=member_array(me->query("id"),jiedu[i]["owner"]);
				if (no>=0)
				{
					jiedu[i]["owner"]-=({me->query("id")});
					jiedu[i]["owner_name"]-=({jiedu[i]["owner_name"][no]});
					jiedu[i]["vacancy"]+=1;
				}
			}
			if (stringp(jiedu[i]["owner"])&&strsrch(me->query("song/title"),jiedu[i]["title"])!=-1)
			{
				jiedu[i]["owner"]="";
				jiedu[i]["owner_name"]="";
			}
		}
		record()->set("give_titles",jiedu);
		jiedu=record()->query("give_mediate_titles");
		for (i=0;i<sizeof(jiedu);i++)
		if ((me->query("song/title")&&strsrch(me->query("song/title"),jiedu[i]["title"])!=-1)||(me->get_title(TITLE_SONG3)&&strsrch(COLOR_D->uncolor(me->get_title(TITLE_SONG3)),jiedu[i]["title"])!=-1))
		jiedu[i]["vacancy"]+=1;
		record()->set("give_mediate_titles",jiedu);
	}
	record()->save();
	return 1;
}

int position_me(object me)
{
	string title;
	mapping announce_depart=(["文":"政事堂","武":"枢密院","宦":"入内内侍省"]);
	if(me->query("class") == "officer")
	return 0;
	if (me->query("family/family_name")=="朝廷")
	return 0;
	if ((me->query("song/suikao/time")>0&&me->query("mud_age")-me->query("song/suikao/time")>86400)||me->query("song/suikao/overall")<-2)
	return 2;
	if (me->query("env/no_promote"))
	return 3;
	if (!me->query("song/pro"))
	assign_pro(me);
	if (me->query("song/term/"+COLOR_D->uncolor(me->get_title(TITLE_SONG1)))&&time()-me->query("song/term/"+COLOR_D->uncolor(me->get_title(TITLE_SONG1))+"/start_date")>=2592000)
	me->set_temp("song/must_transfer",1);
	title=song_title(me);
	me->delete_temp("song/promote");
    if (title=="")
	return -1;
	DASONG_D->multi_record(me,1,"提升",3);
	if (me->query("song/pro")=="武"&&get_my_pin(me)<=5&&get_my_pin(me)>=1)
	xufeng(me);
	clear_position(me,"lu");
	clear_position(me,"jun");
	clear_position(me,"all");
	me->set("song/title",title);
	if (me->query("song/title")!="同中书门下平章事"&&member_array(me->get_title(TITLE_SONG3),({"昭文馆大学士","监修国史","集贤院大学士"}))!=-1)
	{
		me->set_temp("song/retire_xiang",1);
		tell_object(me,"因为你从政事堂退出，同时卸下了"+me->get_title(TITLE_SONG3)+"的贴职。\n");
	}
	if (me->query("song/pro")=="文"&&get_my_pin(me)<=4&&get_my_pin(me)>=1)
	get_tiezhi(me,1);
	if (!me->query_temp("song/hor_promote"))
	{
		DASONG_D->promote_list(me);
		tell_object(me,"恭喜"+me->query("name")+NOR+"大人，获得了"+me->query("title")+"的差遣。\n"NOR);
		if (member_array(my_pin(me),({"正二品","从二品","正一品","从一品"}))==-1)
		message( "channel:" + "chat",HIR + "【大宋】"+announce_depart[me->query("song/pro")]+"行文：" +me->query("name")+HIR+"即日调任"+me->query("title")+HIR+"。\n"+NOR,song_all());
		else
		message( "channel:" + "chat",HIR + "【大宋】门下：" +me->query("name")+HIR+"公忠体国，转任"+me->query("title")+"。\n"+NOR,users());
	}
    add_officer_in(me,classify_depart(me));
	if (me->query_temp("song/hor_promote")==1)
		tell_object(me,"因为官位重叠，你被调任"+title+"。\n");
	if (me->query_temp("song/hor_promote")==2)
		tell_object(me,"你被上峰调任"+title+"。\n");
    if (me->query_temp("song/hor_promote")=="change_pro")
    {
		reset_me_duty(me);
        tell_object(me,"你转职后，调任"+title+"。\n");
    }
	"/d/song/commands/title"->main(me,"song2 song1");
	me->delete_temp("song/hor_promote");
    return 1;
}
int re_position(string arg)
{
	object me;
	if (!me=find_player(arg))
	return notify_fail("查无此人！\n");
	if (!me->query("song/pro"))
	return notify_fail("此人非大宋官员！\n");
	return position_me(me);
}

int if_pro_permit(string pro)
{
	string *wen=({}),*wu=({});
	object ob=load_object("/d/song/record/other");
	if (arrayp(ob->query("pro_文")))
	wen=ob->query("pro_文");
	if (arrayp(ob->query("pro_武")))
	wu=ob->query("pro_武");
	if (pro=="文"&&sizeof(wen)>sizeof(wu)*3/2&&sizeof(wen)-sizeof(wu)>5)
	return -1;
	if (pro=="武"&&sizeof(wu)>sizeof(wen)*3/2&&sizeof(wu)-sizeof(wen)>5)
	return -1;
	return 1;
}

