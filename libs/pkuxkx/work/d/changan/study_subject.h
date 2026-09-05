//国子监课程列表
#include <ansi.h>
protected string show_time(int time);
protected int check_callout();
protected varargs void remove_listens(int remove_flag, string subject);

mapping subject_list=
(["literate":
	(["name":"四书五经",                    //课程名称
		"skills":"literate",                  //课程对应的技能
	  "level":({({50,100}),({100,150}),({150,200}),({200,300})}), //学习的级别范围，这个分别对应四个级别学院的最低等级和最高等级
	  "diff":({10,12,14,18}),               //学习难度，也就是获得经验的速率
	  "cost":({100, 500, 1000, 2000}),      //学习花费，这个指的是花费的金钱
	  "weight":150 ]),                      //出现几率
	"music-theory":
	(["name":"音律入门",
		"skills":"music::music-theory",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({7,9,11,14}),
		"cost":({100, 500, 1000, 2000}),
		"weight":100 ]),
	"qin":
	(["name":"琴入门",
		"skills":"music::qin",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({7,9,11,14}),
		"cost":({100, 500, 1000, 2000}),
		"require":"基础乐理50级",             //前置技能要求
		"weight":20 ]),
	"pipa":
	(["name":"琵琶入门",
		"skills":"music::pipa",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({7,9,11,14}),
		"cost":({100, 500, 1000, 2000}),
		"require":"基础乐理50级",             //前置技能要求
		"weight":20 ]),
	"zheng":
	(["name":"筝入门",
		"skills":"music::zheng",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({7,9,11,14}),
		"cost":({100, 500, 1000, 2000}),
		"require":"基础乐理50级",             //前置技能要求
		"weight":20 ]),
	"shaw":
	(["name":"箫入门",
		"skills":"music::shaw",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({7,9,11,14}),
		"cost":({100, 500, 1000, 2000}),
		"require":"基础乐理50级",             //前置技能要求
		"weight":20 ]),
	"flute":
	(["name":"横笛入门",
		"skills":"music::flute",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({7,9,11,14}),
		"cost":({100, 500, 1000, 2000}),
		"require":"基础乐理50级",             //前置技能要求
		"weight":20 ]),
	"drum":
	(["name":"鼓入门",
		"skills":"music::drum",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({7,9,11,14}),
		"cost":({100, 500, 1000, 2000}),
		"require":"基础乐理50级",             //前置技能要求
		"weight":10 ]),
	"cymbals":
	(["name":"铜钹入门",
		"skills":"music::cymbals",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({7,9,11,14}),
		"cost":({100, 500, 1000, 2000}),
		"require":"基础乐理50级",             //前置技能要求
		"weight":10 ]),
	"gaoshan-liushui.qin":
	(["name":"高山流水"HIY"(琴)"NOR,
		"skills":"music::qin::gaoshan-liushui",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({5,7,9,12}),
		"cost":({200, 1000, 2000, 4000}),
		"require":"基础乐理80级，琴基础50级",
		"weight":10 ]),
	"gaoshan-liushui.zheng":
	(["name":"高山流水"HIY"(筝)"NOR,
		"skills":"music::zheng::gaoshan-liushui",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({5,7,9,12}),
		"cost":({200, 1000, 2000, 4000}),
		"require":"基础乐理80级，筝基础50级",
		"weight":10 ]),
	"meihua-sannong.flute":
	(["name":"梅花三弄"HIY"(横笛)"NOR,
		"skills":"music::flute::meihua-sannong",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({5,7,9,12}),
		"cost":({200, 1000, 2000, 4000}),
		"require":"基础乐理80级，横笛基础50级",
		"weight":10 ]),
	"meihua-sannong.shaw":
	(["name":"梅花三弄"HIY"(箫)"NOR,
		"skills":"music::shaw::meihua-sannong",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({5,7,9,12}),
		"cost":({200, 1000, 2000, 4000}),
		"require":"基础乐理80级，箫基础50级",
		"weight":10 ]),
	"hangong-qiuyue.pipa":
	(["name":"汉宫秋月"HIY"(琵琶)"NOR,
		"skills":"music::pipa::hangong-qiuyue",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({5,7,9,12}),
		"cost":({200, 1000, 2000, 4000}),
		"require":"基础乐理80级，琵琶基础50级",
		"weight":10 ]),
	"hangong-qiuyue.zheng":
	(["name":"汉宫秋月"HIY"(筝)"NOR,
		"skills":"music::zheng::hangong-qiuyue",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({5,7,9,12}),
		"cost":({200, 1000, 2000, 4000}),
		"require":"基础乐理80级，筝基础50级",
		"weight":10 ]),
	"hujia-pai.qin":
	(["name":"胡笳十八拍"HIY"(琴)"NOR,
		"skills":"music::qin::hujia-pai",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({5,7,9,12}),
		"cost":({200, 1000, 2000, 4000}),
		"require":"基础乐理80级，琴基础50级",
		"weight":10 ]),
	"yangchun-baixue.qin":
	(["name":"阳春白雪"HIY"(琴)"NOR,
		"skills":"music::qin::yangchun-baixue",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({5,7,9,12}),
		"cost":({200, 1000, 2000, 4000}),
		"require":"基础乐理80级，琴基础50级",
		"weight":10 ]),
	"yangchun-baixue.pipa":
	(["name":"阳春白雪"HIY"(琵琶)"NOR,
		"skills":"music::pipa::yangchun-baixue",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({5,7,9,12}),
		"cost":({200, 1000, 2000, 4000}),
		"require":"基础乐理80级，琵琶基础50级",
		"weight":10 ]),
	"xiyang-xiaogu.pipa":
	(["name":"夕阳箫鼓"HIY"(琵琶)"NOR,
		"skills":"music::pipa::xiyang-xiaogu",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({3,6,8,10}),
		"cost":({400, 2000, 3000, 6000}),
		"require":"基础乐理150级，琵琶基础100级，琵琶乐器下的基础乐谱80级",
		"weight":5 ]),
	"xiyang-xiaogu.zheng":
	(["name":"夕阳箫鼓"HIY"(筝)"NOR,
		"skills":"music::zheng::xiyang-xiaogu",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({3,6,8,10}),
		"cost":({400, 2000, 3000, 6000}),
		"require":"基础乐理150级，筝基础100级，筝乐器下的基础乐谱80级",
		"weight":5 ]),
	"yuqiao-wenwan.qin":
	(["name":"渔樵问答"HIY"(琴)"NOR,
		"skills":"music::qin::yuqiao-wenwan",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({3,6,8,10}),
		"cost":({400, 2000, 3000, 6000}),
		"require":"基础乐理150级，琴基础100级，琴乐器下的基础乐谱80级",
		"weight":5 ]),
	"yuqiao-wenwan.shaw":
	(["name":"渔樵问答"HIY"(箫)"NOR,
		"skills":"music::shaw::yuqiao-wenwan",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({3,6,8,10}),
		"cost":({400, 2000, 3000, 6000}),
		"require":"基础乐理150级，箫基础100级，箫乐器下的基础乐谱80级",
		"weight":5 ]),
	"guangling-san.qin":
	(["name":"广陵散"HIY"(琴)"NOR,
		"skills":"music::qin::guangling-san",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({3,6,8,10}),
		"cost":({500, 2500, 4000, 8000}),
		"require":"基础乐理200级，琴基础150级，琴乐器下的基础乐谱100级",
		"weight":3 ]),
	"shimian-maifu.pipa":
	(["name":"十面埋伏"HIY"(琵琶)"NOR,
		"skills":"music::pipa::shimian-maifu",
		"level":({({0,100}),({0,150}),({100,200}),({200,300})}),
		"diff":({3,6,8,10}),
		"cost":({500, 2500, 4000, 8000}),
		"require":"基础乐理200级，琵琶基础150级，琵琶乐器下的基础乐谱100级",
		"weight":3 ]) ]);
//由起始时间start_time，结束时间end_time，课程编号subject组成
mapping *subjects;

//自动产生课程
void choice_subject()
{
	int lp,p2,delidx,sttime,wgt,randwgt,subs;
	string *subkey, corsub;
	mixed *wgtkey;
	
	if ( !subjects )
		subjects=({});
	else
	{
		delidx=-1;
		for(lp=0;lp<sizeof(subjects);lp++)
		  if ( subjects[lp]["end_time"]<=time() )
		  	delidx=lp;
		  else
		  	break;
		
		if ( delidx==sizeof(subjects) )
			subjects=({});
		else if ( delidx>=0 )
			subjects=subjects[delidx+1..];
	}
	
	subs=sizeof(subjects);
	if ( subs<12 )
	{
		if ( subs==0 )
			sttime=time();
		else
			sttime=subjects[subs-1]["end_time"]+60;
		
		wgt=0;
		subkey=keys(subject_list);
		wgtkey=({});
		for(lp=0;lp<sizeof(subkey);lp++)
		{
			wgt+=subject_list[subkey[lp]]["weight"];
			wgtkey+=({({subkey[lp],wgt})});
		}
		
		for(lp=0;lp<12-subs;lp++)
		{
			randwgt=random(wgt);
			corsub=0;
			for(p2=0;p2<sizeof(wgtkey);p2++)
			{
				if ( randwgt<wgtkey[p2][1] )
				{
					corsub=wgtkey[p2][0];
					break;
				}
			}

			if ( corsub )
			  subjects+=({(["start_time":sttime+lp*(900+60),
				            "end_time":sttime+lp*(900+60)+900,
				            "subject":corsub])});
		}
	}
}

//显示课程信息
string show_subject()
{
	string msg,subject;
	int level;
	
	msg="";
	choice_subject();
	level=query("subject_level");
	
	for(int lp=0;lp<sizeof(subjects);lp++)
	{
		subject=subjects[lp]["subject"];
		msg+="课程名称："+subject_list[subject]["name"]+"("+subject_list[subject]["skills"]+")\n";
		msg+="课程开始时间："+show_time(subjects[lp]["start_time"])+" 课程结束时间：" + show_time(subjects[lp]["end_time"]) +"\n";
		msg+="课程费用："+chinese_number(subject_list[subject]["cost"][level]/100)+"两银子/分钟 技能等级范围："+
		     subject_list[subject]["level"][level][0] +"级到" + subject_list[subject]["level"][level][1] +"级\n";
		if ( subject_list[subject]["require"] )
			msg+="注意事项："+subject_list[subject]["require"]+"\n\n";
		else
			msg+="\n";
	}
	
	return msg;
}

//设置听课标志，听课标志是一堂课一个标记，课堂结束或者离开课堂就必须清除该标记
int do_listen(string arg)
{
	object me=this_player(), *inv;
	string subject, *subsk;
	int minlevel, maxlevel,level,lp,lis;
	string *jw_name=({"普通百姓","开国县男","开国县子","开国县伯","开国县侯","开国县公","开国郡公","国公","郡王","王"});
	
	choice_subject();
	
	if ( me->query("changan/level")<query("locate_level") )
	{
		tell_object(me, "你的爵位太低，这个学堂至少要达到『"+jw_name[query("locate_level")]+"』爵位才能听讲。\n");
		return 1;
	}
	
	subject=subjects[0]["subject"];
	subsk=explode(subject_list[subject]["skills"],"::");
	if ( sizeof(subsk)<=1 &&
		   !SKILL_D(subsk[0])->valid_learn(me) )
	{
		tell_object(me, subject_list[subject]["name"]+"这门课程对你来说过于高深，请以后再来听讲。\n");
	  return 1;
	}
	else if ( sizeof(subsk)>1 &&
		   !SKILL_D(subsk[0])->valid_learn_subskill(me,subsk) )
	{
		tell_object(me, subject_list[subject]["name"]+"这门课程对你来说过于高深，请以后再来听讲。\n");
	  return 1;
	}
	
	level=query("subject_level");
	minlevel=subject_list[subject]["level"][level][0];
	maxlevel=subject_list[subject]["level"][level][1];
	if ( sizeof(subsk)<=1 &&
		   ( me->query_skill(subsk[0],1)<minlevel ||
		     me->query_skill(subsk[0],1)>maxlevel ) )
	{
		if ( me->query_skill(subsk[0],1)<minlevel )
		  tell_object(me, subject_list[subject]["name"]+"这门课程对你来说过于高深，请以后再来听讲。\n");
		else
			tell_object(me, subject_list[subject]["name"]+"这门课程对你来说过于浅显，请以后再来听讲。\n");
	  return 1;
	}
	else if ( sizeof(subsk)>1 &&
		   ( me->query_sub_skill(subject_list[subject]["skills"],1)<minlevel ||
		     me->query_sub_skill(subject_list[subject]["skills"],1)>maxlevel ) )
	{
		if ( me->query_sub_skill(subject_list[subject]["skills"],1)<minlevel )
		  tell_object(me, subject_list[subject]["name"]+"这门课程对你来说过于高深，请以后再来听讲。\n");
		else
			tell_object(me, subject_list[subject]["name"]+"这门课程对你来说过于浅显，请以后再来听讲。\n");
	  return 1;
	}
	
	inv=all_inventory(this_object());
	lis=0;
	for ( lp=0; lp<sizeof(inv); lp++)
	{
		if ( userp(inv[lp]) && living(inv[lp]) &&
			   inv[lp]->query_temp("changan/listen") )
		  lis++;
	}
	
	if ( lis>=10 )
	{
		tell_object(me, "听课的人太多了，请稍后再来。\n");
		return 1;
	}
	
	if ( !check_callout() )
	{
		choice_subject();
		remove_listens();
		remove_call_out("listen_subject");
		call_out("listen_subject", 10, subjects[0]);
		tell_object(me, "课堂出现意外情况，正在重新选课中，请重新尝试。\n");
		return 1;
	}
	
	me->set_temp("changan/listen",1);
	me->delete_temp("changan/listens");
	tell_object(me, "你坐下来开始听国子监里面的博士讲授课程"+subject_list[subject]["name"]+"方面的一些知识。\n");
	return 1;
}

//循环听课，每10秒听一次课，每听6次课收费一次
void listen_subject(mapping sub_info)
{
	object *inv;
	int tm, end, free,lp,level,lis;
	string subject;
	mapping tmp_sub;
	
	inv=all_inventory(this_object());
	tm=time();
	end=0;
	free=0;
	level=query("subject_level");
	if ( !sub_info )
	{
		choice_subject();
		tmp_sub=subjects[0];
	}
	else
		tmp_sub=sub_info;
	
	subject=tmp_sub["subject"];
	if ( tm>tmp_sub["end_time"] )
	  end=1;
	
	if ( tm<tmp_sub["start_time"] )
		free=tmp_sub["start_time"]-tm;

/*对课堂上不符合资格的听课者进行驱除	
	if ( !end && !free )
	{
		remove_listens(1, tmp_sub["subject"]);
	}*/
	
	for( lp=0; lp<sizeof(inv); lp++ )
	{
		if ( userp(inv[lp]) && living(inv[lp]) &&
			   inv[lp]->query_temp("changan/listen") )
		{
			if ( !inv[lp]->query_temp("changan/listens") )
			{
				tell_object(inv[lp], "国子监的博士开始讲授"+subject_list[subject]["name"]+"的相关知识。\n");
				inv[lp]->set_temp("changan/listens", 1);
			}
			else if ( !free )
				inv[lp]->add_temp("changan/listens", 1);
			
			if ( inv[lp]->query("balance")<subject_list[subject]["cost"][level] )
			{
				tell_object(inv[lp], "你由于囊中羞涩，被停止了听课资格。\n");
				inv[lp]->delete_temp("changan/listen");
				inv[lp]->delete_temp("changan/listens");
				continue;
			}
			
			lis=inv[lp]->query_temp("changan/listens");
			if ( !free && 
				   lis==(lis/6)*6 )
			{
				inv[lp]->add("balance", -1*subject_list[subject]["cost"][level]);
				tell_object(inv[lp], "你缴纳了"+chinese_number(subject_list[subject]["cost"][level]/100)+"两白银的听课费。\n");
			}
			
			if (end)
			{
				tell_object(inv[lp], "国子监的博士结束了"+subject_list[subject]["name"]+"的讲授，学生们站起来欢送博士的离开。\n");
				inv[lp]->improve_skill(subject_list[subject]["skills"], subject_list[subject]["diff"][level]*inv[lp]->query("int") );
			}
			else if ( free )
			{
				tell_object(inv[lp], "距离下一节课"+subject_list[subject]["name"]+"的讲授还有"+free+"秒。\n");
			}
			else if ( inv[lp]->query_temp("changan/listens")>1 )
			{
				tell_object(inv[lp], "你专心听博士讲授"+subject_list[subject]["name"]+"，感觉自己对这方面的知识又掌握了一些。\n");
				inv[lp]->improve_skill(subject_list[subject]["skills"], subject_list[subject]["diff"][level]*inv[lp]->query("int") );
			}
		}
	}
	
	if ( !end )
		call_out("listen_subject", 10, tmp_sub);
	else
	{
		choice_subject();
		remove_listens();
		call_out("listen_subject", 10, subjects[0]);
	}
}

//标准时间显示
protected string show_time(int time)
{
	mixed *tm=localtime(time);
	
	if ( !time )
		return "未知时间";
	else
	  return sprintf("%d-%d-%d %d:%d:%d", tm[5], tm[4]+1, tm[3], tm[2], tm[1]+1, tm[0]+1);
}

//检查讲课循环是否还在运行
protected int check_callout()
{
	mixed *cinfo;
	int lp;
	
	cinfo= filter_array(call_out_info(), (: $1[1]==$2 :), "listen_subject");
	
	for(lp=0;lp<sizeof(cinfo);lp++)
	{
		if ( cinfo[lp][0]==this_object() )
			return 1;
	}
	return 0;
}

//取消所有听课资格
protected varargs void remove_listens(int remove_flag, string subject)
{
  object *inv;
  int lp;
  int minlevel, maxlevel,level;
  string *subsk;
  
  inv=all_inventory(this_object());
  
  if ( remove_flag && stringp(subject) && mapp(subject_list[subject]) )
  {
	  subsk=explode(subject_list[subject]["skills"],"::");
	  level=query("subject_level");
	  minlevel=subject_list[subject]["level"][level][0];
	  maxlevel=subject_list[subject]["level"][level][1];	  
	  
	  for( lp=0; lp<sizeof(inv); lp++ )
	  {
		  if ( userp(inv[lp]) &&
			     inv[lp]->query_temp("changan/listen") )
		  {
	      if ( sizeof(subsk)<=1 &&
		         !SKILL_D(subsk[0])->valid_learn(inv[lp]) )
	      {
	      	tell_object(inv[lp], "由于你不能满足课程"+subsk[0]+"的基本条件被停止了听课资格。\n");
			    inv[lp]->delete_temp("changan/listen");
			    inv[lp]->delete_temp("changan/listens");
			    continue;
	      }
	      else if ( sizeof(subsk)>1 &&
		              !SKILL_D(subsk[0])->valid_learn_subskill(inv[lp],subsk) )
	      {
	      	tell_object(inv[lp], "由于你不能满足课程"+subject_list[subject]["skills"]+"的基本条件被停止了听课资格。\n");
			    inv[lp]->delete_temp("changan/listen");
			    inv[lp]->delete_temp("changan/listens");
			    continue;
	      }

      	if ( sizeof(subsk)<=1 &&
		       ( inv[lp]->query_skill(subsk[0],1)<minlevel ||
		         inv[lp]->query_skill(subsk[0],1)>maxlevel ) )
	      {
	      	tell_object(inv[lp], "由于你不能满足课程"+subsk[0]+"的最低级别"+minlevel+"和最高级别"+maxlevel+"要求被停止了听课资格。\n");
			    inv[lp]->delete_temp("changan/listen");
			    inv[lp]->delete_temp("changan/listens");
			    continue;
	      }
	      else if ( sizeof(subsk)>1 &&
		       ( inv[lp]->query_sub_skill(subject_list[subject]["skills"],1)<minlevel ||
		         inv[lp]->query_sub_skill(subject_list[subject]["skills"],1)>maxlevel ) )
	      {
	      	tell_object(inv[lp], "由于你不能满足课程"+subject_list[subject]["skills"]+"的最低级别"+minlevel+"和最高级别"+maxlevel+"要求被停止了听课资格。\n");
			    inv[lp]->delete_temp("changan/listen");
			    inv[lp]->delete_temp("changan/listens");
			    continue;
	      }
      }
    }
    return;
  }
  
	for( lp=0; lp<sizeof(inv); lp++ )
	{
		if ( userp(inv[lp]) &&
			   inv[lp]->query_temp("changan/listen") )
		{
			inv[lp]->delete_temp("changan/listen");
			inv[lp]->delete_temp("changan/listens");
		}
	}
}