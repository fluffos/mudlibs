#include <ansi.h>
#include <localtime.h>
string time_change(int timep);
int time_period(int timep, object me);

string c_date()
{
	mixed *tm;
	
	tm=localtime(time());
	return sprintf("%d-%d-%d", tm[LT_YEAR], tm[LT_MON]+1, tm[LT_MDAY] );
}

mixed main(object ob, string arg)
{
  object me=this_player();
  mapping quest,wsquest;
  string time;
  int timep;
  int nowtime = time();
  
  tell_object(me, HIY"======================================================\n");
  tell_object(me, HIY"==  任务积分： "+ chinese_number( me->query("cjg/point") ) +"\n");
  tell_object(me, HIY"======================================================\n"NOR);
  quest = me->query("quest");
  if(!me->query("quest/type"))
  {
       tell_object(me,HIW"你现在没有师门任务！\n"NOR);
  }
	else {
		tell_object(me,HIG"门忠任务：\n"NOR);
	  if (quest["type"] == "find")
			{
			tell_object(me,HIW"你的任务是找回『"+quest["name"]+"』。\n" NOR);
			}
			   else if (quest["type"] == "kill")
			{
			tell_object(me,HIW"你的任务是杀了『"+quest["name"]+"』。\n" NOR);        
			if( me->query("quest/finish"))
			tell_object(me,HIW"你已经杀了『"+quest["name"]+"』,赶快回去复命吧。\n" NOR); 
			}  
			  else if (quest["type"] == "扫")
			{
			tell_object(me,HIW"你的任务是打扫『"+quest["quest"]+"』。\n" NOR);        
			if( me->query_temp("quest_finish"))
			tell_object(me,HIW"你已经把『"+quest["quest"]+"』打扫干净了,赶快回去复命吧。\n" NOR); 
			}  
			else if (quest["type"] == "give")
			{
			tell_object(me,HIW"你的任务送『" + quest["objname"] + "』给『"+quest["name"]+"』。\n" NOR);        
			if( me->query("quest/finish"))
			tell_object(me,HIW"你已经把『" + quest["objname"] + "』送给了『"+quest["name"]+"』,赶快回去复命吧。\n" NOR); 
			}
			else if (quest["type"]=="win")
			{
			tell_object(me,HIW"你的任务是战胜『"+quest["name"]+"』。\n" NOR);        
			if( me->query("quest/finish"))
			tell_object(me,HIW"你已经战胜了『"+quest["name"]+"』,赶快回去复命吧。\n" NOR); 
	        }
	 if (me->query("quest/time") <= time() )
		   tell_object(me,HIW"但你已经没有时间完成了。\n"NOR);
	 else
	 {
	 timep=me->query("quest/time")-time();
	 time=time_change(timep);
	 tell_object(me,HIW"你还有"+time+"来完成它。\n"NOR); 
	 }
}
//门派任务
if(wsquest =  me->query("wsquest"))
{
	tell_object(me,HIG"门派任务：\n"NOR);
	tell_object(me,HIW"你现在的任务是" + wsquest["quest_type"] + "『" + wsquest["quest"] + HIW"』。\n"NOR);
	nowtime = (int) me->query("task_time") - time();
	if( nowtime  > 0 )
		time_period(nowtime, me);
	else
		tell_object(me,HIW"但是你已经没有足够的时间来完成它了。\n"NOR);
}
//投名状任务 whuan
if (me->query("jiaofei/tmz/on_job") && me->query_temp("jiaofei/tmz/questmsg"))
	{
	  tell_object(me,HIG"投名状任务：\n"NOR);		
		tell_object(me,HIW+me->query_temp("jiaofei/tmz/questmsg")+"");
	}

 //护镖任务
 if (me->query("in_dart"))
 {
	tell_object(me,HIG"护镖任务：\n"NOR);
	if (me->query_temp("dart_name"))
                tell_object(me,HIW"你需要把镖车运给"+me->query_temp("dart_name") + "的伙计"+me->query_temp("huoji_name")+"，他会在"+me->query_temp("huoji_where")+"接应你！\n"NOR);
	else
		tell_object(me,HIW"你上次的运镖任务没有完成。\n"NOR);
	if (me->query_temp("over_dart"))
		tell_object(me,HIW"你的镖已经运到了，赶快回去复命吧！\n"NOR);
 }
//小宝任务
  quest = me->query("wquest");
  if(me->query("wquest"))
{
	tell_object(me,HIG"满不懂任务：\n"NOR);
  if (quest["quest_type"] == "寻")
        {
        tell_object(me,HIW"你的任务是找回『"+quest["quest"]+"』。\n" NOR);
        }
           else if (quest["quest_type"] == "杀")
        {
        tell_object(me,HIW"你的任务是杀了『"+quest["quest"]+"』。\n" NOR);        
        if( me->query("quest/finish"))
        tell_object(me,HIW"你已经杀了『"+quest["quest"]+"』,赶快回去复命吧。\n" NOR); 
        }  
          else if (quest["type"] == "扫")
        {
        tell_object(me,HIW"你的任务是打扫『"+quest["quest"]+"』。\n" NOR);        
        if( me->query_temp("quest_finish"))
        tell_object(me,HIW"你已经把『"+quest["quest"]+"』打扫干净了,赶快回去复命吧。\n" NOR); 
        }  
        else if (quest["type"] == "give")
        {
        tell_object(me,HIW"你的任务送『" + quest["objname"] + "』给『"+quest["name"]+"』。\n" NOR);        
        if( me->query("quest/finish"))
        tell_object(me,HIW"你已经把『" + quest["objname"] + "』送给了『"+quest["name"]+"』,赶快回去复命吧。\n" NOR); 
        }
        else if (quest["type"]=="win")
        {
        tell_object(me,HIW"你的任务是战胜『"+quest["name"]+"』。\n" NOR);        
        if( me->query("quest/finish"))
        tell_object(me,HIW"你已经战胜了『"+quest["name"]+"』,赶快回去复命吧。\n" NOR); 
        }
 if (me->query("wjob/task_time") <= time() )
       tell_object(me,HIW"但你已经没有时间完成了。\n"NOR);
 else
 {
 timep=me->query("wjob/task_time")-time();
 time=time_change(timep);
 tell_object(me,HIW"你还有"+time+"来完成它。\n"NOR); 
 }
}
//唱戏任务
if ( me->query("obj/changxi") && me->query("combat_exp") < 100000)
{
	tell_object(me,HIG"唱戏任务：\n"+HIW"你现在应该去"+me->query("obj/where")+"表演。\n"NOR);
	if (me->query("obj/done"))
		tell_object(me,HIW"你已经表演完了，赶快回去复命吧。\n"NOR);
}
//玉玺任务
	if (me->query("murong/yuxi"))
	{
		tell_object(me,HIG"玉玺任务:\n"NOR);
		tell_object(me,HIW"你要去找回在" + me->query_temp("murong/yuxi_where") + "出现的大燕传国玉玺。\n"NOR);
	}
    /*
    task 以图片显示地点，不再支持quest命令
//task
if (me->query_temp("task_target"))
{
	tell_object(me,HIG"TASK：\n"NOR);
	tell_object(me,HIW"你现在应该去追杀"+me->query_temp("task_where")+"的"+me->query_temp("task_target_name")+"。\n"NOR);
}*/

//胡一刀任务
  if (!me->query_temp("yidao/done") && me->query("yidao/on_job"))
{
	      if ( time()-me->query_temp("yidao/showtime")>=60 )
	      {
          tell_object(me,HIG"胡一刀任务：\n"NOR);
          if ( arg == "-m" )
          {
	          me->set_temp("yidao/showtime",time());
            if ( me->query("yidao/questid")=="still" )
        	    ANTIROBOT_D->mxpantirobot_ex(me, "到"+me->query_temp("yidao/where")+"找"+me->query_temp("yidao/killer"));
            else if ( me->query("yidao/questid")=="maze" )
        	    ANTIROBOT_D->mxpantirobot_ex(me, "到"+me->query_temp("yidao/where")+"找"+me->query_temp("yidao/suicong"));
            else
              tell_object(me,HIW"你现在去"+me->query_temp("yidao/where")+"寻找盗宝人"+me->query_temp("yidao/killer")+"。\n"NOR);
          }
          else
          {
            if ( me->query("yidao/questid")=="still" )
        	    tell_object(me,HIW"你正在进行胡一刀任务。\n"NOR);
            else if ( me->query("yidao/questid")=="maze" )
        	    tell_object(me,HIW"你正在进行胡一刀任务。\n"NOR);
            else
              tell_object(me,HIW"你现在去"+me->query_temp("yidao/where")+"寻找盗宝人"+me->query_temp("yidao/killer")+"。\n"NOR);
          }
        }
        else
        	tell_object(me, "胡一刀任务：\n一分钟以后再敲命令。\n");
}
//护卫
if (me->query_temp("ljhwjob"))
{
        tell_object(me,HIG"护卫：\n"NOR);
        tell_object(me,HIW"你现在去"+me->query_temp("ljhwjob")+"护卫"+"。\n"NOR);
}
//杀手
if (me->query("xiaofeng/on_job")==1)
	{
        tell_object(me,HIG"杀手任务：\n"NOR);
        tell_object(me,HIW"你现在应该去"+me->query_temp("xiaofeng/job")+",他会在"+me->query_temp("xiaofeng/target_place")+"出没。\n"NOR);		
	}
if (me->query_temp("huashan/on_songxin"))
        {
        tell_object(me,HIG"华山送信任务：\n"NOR);
 tell_object(me,HIW"你现在应该去"+me->query_temp("huashan/songxin/target_name")+"送信,他在"+me->query_temp("huashan/songxin/where")+"附近。\n"NOR); 
        }
//送信
if (me->query("songxin")&&me->query("combat_exp")<10000&&me->query("mud_age")<86400)
{
	tell_object(me,HIG"送信：\n"NOR);
	tell_object(me,HIW"你现在要去给" + me->query("songxin/target_name") + "送信。\n"NOR);
	if (!objectp(present("xin jian",me)))
		tell_object(me,HIW"但是已经没有时间了，信件被风吹雨淋弄得破损掉了。\n"NOR);
}
//锻造
if (me->query("forgingjob/onduty")==1)
{
	tell_object(me,HIG"锻造术：\n"NOR);
	tell_object(me,HIW"你现在要做3次" + me->query("forgingjob/nextjob") + "任务。\n"NOR);
}
//韩元外
if (me->query_temp("hyw/start"))
{
    tell_object(me,HIG"韩员外复仇：\n"NOR);
    if (me->query_temp("hyw/pic"))
    {
        tell_object(me,HIW"图片版任务。\n"NOR);
    }
    else
    {
        tell_object(me,HIW"你现在要去" + me->query_temp("hyw/where") + "杀死"+me->query_temp("hyw/name")+"。\n"NOR);
    }
}

if ( me->query("cjg") )
{
  tell_object(me, HIM"\n藏经阁任务：\n"NOR);
  if ( me->query("cjg/date") != c_date() ||
       !me->query("cjg/number") )
    tell_object(me, HIM"今天还能完成2次藏经阁任务。\n" NOR);
  else
    tell_object(me, HIM"今天还能完成"+(2-me->query("cjg/number"))+"次藏经阁任务。\n"NOR );
}

 return 1;
}

string time_change(int timep)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        
        return time;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        tell_object(me,"你还有" + time + "去完成它。\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quest

这个指令可以显示你当前的任务状态，包括门忠任务，满不懂任务等等。
quest -m 显示胡一刀任务的图片
HELP
    );
    return 1;
}
