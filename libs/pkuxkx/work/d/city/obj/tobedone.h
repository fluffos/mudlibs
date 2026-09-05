#include <ansi.h>
#include <title.h>
int to_do1(object me)//荣誉title重新定义
{
    if (!me->query("honorbonus/titlegiven")&&!me->query("honorbonus/realuser_title"))
    {
        return 1;
    }
    if (me->query("honorbonus/remove_title"))
    {
        return 1;
    }
    me->set("honorbonus/remove_title",1);
    if (me->query("honorbonus/titlegiven"))
    me->delete("honorbonus/titlegiven");
    if (me->query("honorbonus/realuser_title"))
    me->delete("honorbonus/realuser_title");
    me->set_title(TITLE_HONOR,"");
    tell_object(me,HIW+"荣誉title已经重新定义，先把每个人的荣誉头衔清零，请重新去洛阳点石成金处领取。\n"+NOR);
    return 1;
}
int to_do2(object me)//保存荣誉title
{
    object ob=this_object();
    string title=COLOR_D->uncolor(me->get_title(TITLE_HONOR));
    string *titles=({});
    if (!title)
    {
        return 1;
    }
    
    ob->restore();
    if (ob->query(title))
    {
        titles=ob->query(title);
    }
    if (member_array(me->query("id"),titles)==-1)
    {
        titles+=({me->query("id")});
    }
    ob->set(title,titles);
    ob->save();
    return 4;
}

int to_do3(object me)//解决人物失去某项title（比如排行榜 top）后仍设定最初query("multi_title")显示0的错误
{
    int i;
    string *title;
    if (!me->query("multi_title"))
    {
        return 1;
    }
    title=me->query("multi_title");
    for (i=0;i<sizeof(title);i++)
    {
        if (me->get_title(title[i])==""||!me->get_title(title[i]))
        {
            title-=({title[i]});
        }
    }
    me->set("multi_title",title);
    return 1;
}
int to_do4(object me)//将小龙女和杨过置为一辈（夫妻关系），高手拜杨过，反而出现比新手低
{
	if (me->query("family/family_name")=="古墓派"&&me->query("family/master_id")=="yang guo"&&me->query("family/generation")==5)
	{
		me->set("family/generation",4);
	}
	return 1;
}
int to_do5(object me)//朝廷title更新
{
	string title;
    string * province=({"两广","两江","四川","直隶"});
    string * pin9=({"外委把总","兰翎长","协领"});
    string * pin8=({"典仪","亲军校","前锋校","护军校","骁骑校","千总"});
    string * pin7=({"七品典仪","盛京游牧副尉","城门史","马厂协领","把总","安抚使司佥事"});
    string * pin6=({"卫千总","安抚使司副使","内务府六品兰翎长","六品典仪","门千总","营千总","宣抚使司佥事","安抚使司同知","副招讨使","百户","兰翎侍卫","整仪尉"});
    string * pin5=({"关口守御","防御","守备","宣慰使司佥事","宣抚使司同知","千户","分管佐领","监守信礮官","步军校","步军副尉","三等侍卫","治仪正","守御所千总","河营协办守备","安抚使","招讨使","宣抚使司副使","副千户","四等侍卫","委署前锋参领","委署护军参领","委署鸟枪护军参领","委署前锋侍卫","下五旗包衣参领","五品典仪","印物章京","三等护卫"});
    string * pin4=({"贝勒府司仪长","侍卫领班","指挥佥事","宣慰使司同知","二等侍卫","云麾使","副护军参领","副前锋参领","副骁骑参领","太仆寺马厂驼厂总管","宣抚使","宣慰使司副使","二等护卫","四品典仪","城门领","包衣副护军参领","包衣副骁骑参领","包衣佐领","防守尉","佐领","都司"});
    string * pin3=({"城守尉","骁骑参领","王府长史","参将","指挥使","一等侍卫","火器营翼长","健锐营翼长","前锋参领","护军参领","游击","五旗参领","协领","宣慰使","指挥同知","包衣护军参领","包衣骁骑参领","王府一等护卫"});
    string * pin2=({"副将","散秩大臣","副都统","总兵","右翼前锋营统领","左翼前锋营统领","八旗护军统领","銮仪使"});
    string * pin1=({province[random(sizeof(province))]+"将军",province[random(sizeof(province))]+"都统",province[random(sizeof(province))]+"提督","提督九门步军巡捕五营统领","内大臣","领侍卫内大臣","掌銮仪卫事大臣"});
    string * jue3=({"忠诚伯"});
    string * jue2=({"延恩侯","同安侯"});
    string * jue1=({"忠襄公","承恩公","孝愍公","海澄公","忠锐公","辅国公","镇国公","鹿鼎公"});
	int pin;
	if ((string)me->query("class")== "officer"&&!me->query("chaoting/newtitle")&&me->query("chaoting/officer")&&me->query("pin")&&!me->query("chaoting/wang")&&!me->query("chaoting/jiawang"))
	{
		pin=(int)me->query("pin");
		switch (pin)
		{
		case 9:
		if (me->query("gender") == "男性")
		title = YEL+pin9[random(sizeof(pin9))]+NOR;
		else if(me->query("gender") == "女性")
		title = YEL+pin9[random(sizeof(pin9))]+NOR;
		else
		title = HIM"尚膳监太监"NOR;
		break;

		case 8:
		title=YEL+pin8[random(sizeof(pin8))]+NOR;
		break;

		case 7:
		title=HIY+pin7[random(sizeof(pin7))]+NOR;
		break;

		case 6:
		title=WHT+pin6[random(sizeof(pin6))]+NOR;
		break;

		case 5:
		title=HIW+pin5[random(sizeof(pin5))]+NOR;
		break;

		case 4:
		title=CYN+pin4[random(sizeof(pin4))]+NOR;
		break;

		case 3:
		title=HIY+jue3[random(sizeof(jue3))]+" "+HIB+pin3[random(sizeof(pin3))]+NOR;
		break;

		case 2:
		title=HIY+jue2[random(sizeof(jue2))]+" "+RED+pin2[random(sizeof(pin2))]+NOR;
		break;

		case 1:
		if (!me->query("chaoting/wang")&&!me->query("chaoting/jiawang"))
		{
			title=HIY+jue1[random(sizeof(jue1))]+" "+HIR+pin1[random(sizeof(pin1))]+NOR;
		}
		break;
		}
		title = HIG+ "朝廷" + chinese_number(pin) + "品官员 "NOR + title;
		me->set("title", title);
		me->set_title(TITLE_RANK, title);
		me->set("chaoting/newtitle",1);
		tell_object(me,"恭喜你！你的新官衔是"+title+"\n");
	}
	return 1;
}
int to_do6(object me)//修改太极刀为玄虚刀的情况
{
	if (me->query_skill("taiji-dao"))
	{
		me->set_skill("xuanxu-dao",me->query_skill("taiji-dao",1));
		me->delete_skill("taiji-dao");
		tell_object(me,HIM+BLINK+"你的太极刀已经被自动转化成玄虚刀法，请自行enable,wbei。\n"NOR);
	}
	return 1;
}
int to_do7(object me)//全真飞仙步改为金雁功
{
	if (me->query_skill("fx-step"))
    {
        me->set_skill("jinyan-gong",me->query_skill("fx-step",1));
        me->delete_skill("fx-step");
        me->set_skill_mapped("dodge","jinyan-gong");
        tell_object(me,HIM+BLINK+"你的飞仙步已经被自动转化成金雁功。\n"NOR);
    }
	return 1;
}
int to_do8(object me)//丐帮净衣派的颜色
{
	string title;
	if (me->query("family/family_name")=="丐帮"&&me->query("is_beggar"))
    {
        title=me->get_title(TITLE_RANK);
		if (title)
		{
			title=replace_string(title,"污衣派",WHT+"污衣派");
			me->set("title",title);
			me->set_title(TITLE_RANK, me->query("title"));
			me->save();
		}
    }
	return 1;
}
int to_do9(object me)//桃花岛title的切换
{
	string title;
	if (me->query("family/family_name")=="桃花岛"&&!me->query("taohua_title_change"))
    {
        me->set("taohua_title_change",1);
		if (me->query("family/generation")==2)
		{
			if ((string)me->query("gender")=="女性")
			title=RED+"桃花岛"+HIW+" 岛主亲传弟子"NOR;
			else
			title=RED+"桃花岛"+YEL+" 岛主亲传弟子"NOR;
		}
		if (me->query("family/generation")==3)
		{
			if ((string)me->query("gender")=="女性")
			title=RED+"桃花岛"+HIW+" 第三代弟子"NOR;
			else
			title=RED+"桃花岛"+YEL+" 第三代弟子"NOR;
		}
		if (me->query("family/generation")==4)
		{
			if ((string)me->query("gender")=="女性")
			title=RED+"桃花岛"+HIW+" 第四代弟子"NOR;
			else
			title=RED+"桃花岛"+YEL+" 第四代弟子"NOR;
		}
			me->set("title",title);
			me->set_title(TITLE_RANK, me->query("title"));
			me->save();
    }
	return 1;
}
int to_do10(object me)//一阳指的合并
{
	int lv1,lv2,true_lv,flag1=0,flag2=0;
	if (!me->query_skill("yiyangzhi")&&!me->query_skill("yiyang-zhi"))
	{
		return 1;
	}
	if (me->query_skill("yiyangzhi"))
	{
		me->set("yiyang_zhi/tianlong",1);
		lv1=me->query_skill("yiyangzhi",1);
		me->prepare_skill("finger");
		me->delete_skill("yiyangzhi");
		flag1=1;
	}
	if (me->query_skill("yiyang-zhi"))
	{
		me->set("yiyang_zhi/quanzhen",1);
		lv2=me->query_skill("yiyang-zhi",1);
		flag2=1;
	}
	if (lv1>lv2)
	true_lv=lv1;
	else
	true_lv=lv2;
	me->set_skill("yiyang-zhi",true_lv);
	if (flag1&&!flag2)
	{
		tell_object(me,"你的技能yiyangzhi已经被系统自动修正为yiyang-zhi，请重新激发。\n");
	}
	if (flag1&&flag2)
	{
		tell_object(me,"你的技能yiyangzhi和yiyangzhi已经被系统自动合并为yiyang-zhi，请重新激发。\n");
		tell_object(me,"如需使用全真的一阳指pfm请set yiyang quanzhen，系统默认优先使用天龙的一阳指。\n");
	}
	return 1;
}
int to_do11(object me)//天龙的提示
{
	if (me->query("family/family_name")=="天龙寺"&&me->query("class")!="monk"&&!me->query("tianlong_transform"))
	{
		me->set("tianlong_transform",1);
		tell_object(me,BLINK+"天龙寺将完成门派转换，武功将不会有变化，但将只收"+BLINK+HBBLU+HIW+"男性出家"+NOR+BLINK+"弟子。\n");
		tell_object(me,BLINK+"如果你是在本次更新前之前拜师，可以通过脱离门派的方式离开(不会增加判师次数)。\n");
		tell_object(me,BLINK+"否则在下次登录时将视为接受此结果，自动转化为男性出家弟子。\n"+NOR);
		if (me->query("family/generation")==2)
		{
			me->set("family/generation",15);
			me->set("title", GRN "天龙寺" NOR + YEL "第十五代代弟子" NOR);
			me->set_title(TITLE_RANK, me->query("title"));
			me->set("family/master_name","枯荣大师");
			me->set("family/master_id","kurong dashi");
			tell_object(me,"现已将你的辈份按原著修改为天龙寺第15代弟子。\n");
		}
		if (me->query("family/generation")==3)
		{
			me->set("family/generation",16);
			me->set("title",GRN"天龙寺"NOR+RED"第十六代弟子"NOR);
			me->set_title(TITLE_RANK, me->query("title"));
			tell_object(me,"现已将你的辈份按原著修改为天龙寺第16代弟子。\n");
		}
	}
	return 1;
}
int to_do12(object me)//天龙的转换
{
	string name=me->query("name");
	if (me->query("family/family_name")=="天龙寺"&&me->query("class")!="monk"&&me->query("tianlong_transform")&&time()>1344754622)//8月12日后默认为同意转换
	{
		name=name[0..0];
		me->set("class","monk");
		me->set("tianlong_transform",1);
		if (me->query("family/generation")==15)
		{
			name="本"+name;
		}
		else
		{
			name="了"+name;
		}
		if (me->query("gender")!="男性")
		{
			me->set("gender","男性");
		}
		tell_object(me,"你接受了天龙寺转换的条件，从此你法号"+name+"。\n");
		me->set("name",name);
	}
	return 1;
}

int to_do13(object me)//为奥运加油
{
	int exp;
	if (time()<1344815999&&!me->query("olympic/start"))
	{
		me->set("olympic/start",1);
		exp=(int)me->query("combat_exp")/100;
		if (exp<100000)
		{
			exp=100000;
		}
		me->set("olympic/target_exp",exp+(int)me->query("combat_exp"));
		tell_object(me,BLINK+HIR+"你被选入参加为奥运加油的临时任务，在奥运结束(伦敦时间8月13日0点前)前，只要你的经验达到"+me->query("olympic/target_exp")+"点即可完成！\n"NOR);
	}
	if (time()>1344815999&&me->query("olympic/start")&&me->query("olympic/target_exp"))
	{
		if (me->query("combat_exp")>me->query("olympic/target_exp"))
		{
			me->set("olympic_london_finish",1);
			tell_object(me,"恭喜你，你完成了为奥运加油的临时任务！\n");
		}
		me->delete("olympic");
		tell_object(me,"很遗憾，你并没有完成为奥运加油的临时任务！\n");
	}
	return 1;
}
int to_do14(object me)
{
	string ming_title="",ming_jue="",*titles=({TITLE_QUEST1,TITLE_QUEST2,TITLE_QUEST3,TITLE_QUEST4,TITLE_QUEST5,TITLE_QUEST6,TITLE_QUEST7,TITLE_QUEST8,TITLE_QUEST9,TITLE_QUEST10});
	string* title1a_pre=({"太师","太傅","太保","少师","少傅","少保",});
    string* title2a_pre=({"太子太师","太子太傅","太子太保",});
    string* title3a_pre=({"太子少师","太子少傅","太子少保",});
	string* title_pre_remove=({"建威将军","荣禄大夫","光禄大夫","龙虎将军","定国将军","骠骑将军","金吾将军","镇国将军","奉国将军","昭勇将军","昭毅将军","怀远将军","定远将军","昭武将军","安远将军"});
	int i,j;

	if (me->query("mingpin")||me->query("ming/tj/pin"))
	{
		for (i=0;i<sizeof(titles);i++)
		{
			if (me->get_title(titles[i]) && strsrch(me->get_title(titles[i]), "闲云野鹤")>=0 )
			{
				ming_title=me->get_title(titles[i]);
				me->set_title(titles[i]);
			}
			if (me->get_title(titles[i]) && strsrch(me->get_title(titles[i]), "大明")>=0 )
			{
				ming_title=me->get_title(titles[i]);
				for (j=0;j<sizeof(title_pre_remove);j++)
				{
					ming_title=replace_string(ming_title,title_pre_remove[j],"");
				}
				me->set_title(titles[i]);
			}
			if (me->query("ming/juewei_3")&&me->get_title(titles[i]) && member_array(COLOR_D->uncolor(me->get_title(titles[i])),title3a_pre)!=-1 )
			{
				ming_jue=me->get_title(titles[i]);
				me->set_title(titles[i]);
			}
			if (me->query("ming/juewei_2")&&me->get_title(titles[i]) && member_array(COLOR_D->uncolor(me->get_title(titles[i])),title2a_pre)!=-1 )
			{
				ming_jue=me->get_title(titles[i]);
				me->set_title(titles[i]);
			}
			if (me->query("ming/juewei_1")&&me->get_title(titles[i]) && member_array(COLOR_D->uncolor(me->get_title(titles[i])),title1a_pre)!=-1 )
			{
				ming_jue=me->get_title(titles[i]);
				me->set_title(titles[i]);
			}
		}
		ming_title=replace_string(ming_title,"大明",HIW"大明"NOR);
		//tell_object(me,ming_title);
		if (ming_title!="")
		me->set_title(TITLE_MING1,ming_title);
		if (ming_jue!="")
		me->set_title(TITLE_MING3,ming_jue);
	}
	return 1;
}
int to_do15(object me)
{
	string *ids=({"npckill","qcxqcxqcx","zine","henryw","kickcat","fflower","lkyun","ytywwqqt","labaz","liuke","inkcrane","inkflower","tuya","hawks","chfe","wcg","jing","xuhuan"});
	int bonus,*exp=({11577,503,88,14520,11000,19423,83587,53776,93091,18153,170949,123373,111509,249777,101648,127525,398870,493445});
	if (member_array(me->query("id"),ids)==-1)
	return 1;
	if (me->query("exp/PYH_TEST_ZINE_2012_12_19"))
	return 1;
	bonus=2*exp[member_array(me->query("id"),ids)];
	me->add("exp/PYH_TEST_ZINE_2012_12_19",bonus);
	me->add("combat_exp",bonus);
	me->add("potential",bonus);
	tell_object(me,BLINK+HIG+"你因为参与了鄱阳湖多人版的测试工作，被奖励了"+chinese_number(bonus)+"点经验，"+chinese_number(bonus)+"点潜能。\n"+NOR);
	return 1;
}
int notice(object me,object ob)
{
    int i,num,news_num,flag=0;
    mapping* notes;
    string msg;
    num=me->query("group/news_notice/num");
    notes=ob->query("notes");
    if (!notes)
    {
        return 1;
    }
    news_num=sizeof(notes)-1;
	if (ob->query("group_name"))
	msg="\n"+HIW+"你接到了"+ob->query("group_name")+HIW+"的飞鸽传书：\n";
	else
    msg="\n"HIW+"你接到了本宗派的飞鸽传书：\n"NOR;
    me->set("group/news_notice/num",news_num);
    for (i=num;i<=news_num;i++)
    {
		if (i!=num)
		{
			msg+=HBYEL+HIB+notes[i]["content"]+"<"+notes[i]["authorid"]+">"+NOR;
			msg+="\n";
		}
        flag=1;
        if (num==news_num)
        flag=0;
	}
    msg+="\n";
    if (flag)
    tell_object(me,msg);
	return 1;
}
int to_do16(object me)
{
	object ob;
	if (!me->query("group_title_by"))
	return 1;
	if (ob=load_object(me->query("group_title_by")))
	if (ob->is_group_base())
	{
		remove_call_out("notice");
		call_out("notice",10,me,ob);
	}
	return 1;
}
int to_do_list()//gemlocker是每个人都有的东西，一些全面性的修改可以加在这里，不用全部放logind里
{
    object me=environment(this_object());
    if (!me)
    {
        return 1;
    }
    if (!userp(me))
    {
        return 1;
    }
	to_do15(me);//玩家帮助测试的奖励，所以放上面
	to_do16(me);//检查玩家在流派里的东东
	if (time()-me->query("GL_login_checklist")<3600*24)//检查1天之内不做2次，降低消耗，Zine
	{
		return 1;
	}
    if( !LOGIN_D->check_legal_name(COLOR_D->uncolor(me->query("name"))) )
    {
        me->set("name", "名字非法");
    }
	me->set("GL_login_checklist",time());
    to_do1(me);
    to_do2(me);
    to_do3(me);
	to_do4(me);
	to_do5(me);
	to_do6(me);
	to_do7(me);
	to_do8(me);
	to_do9(me);
	to_do10(me);
	to_do11(me);
	to_do12(me);
	to_do13(me);
	to_do14(me);
    return 2;
}