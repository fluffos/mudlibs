//modified by Zine 20110727 分门派类新手任务主流任务特殊任务四类 加入cd时间查询
#include <ansi.h>
#include <math.h>
string time_change(int timep);
#define HEAD   HIW"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"NOR
#define LINE   HIW"――――――――――――――――――――――――――――\n"NOR
#define START 1 //所有任务开始结束
#define END 22
#define START_M 1 //门忠任务开始结束
#define END_M 2
#define START_X 3 //新手任务开始结束
#define END_X 5
#define START_Z 6 //主流任务开始结束
#define END_Z 14
#define START_T 15 //特殊任务开始结束
#define END_T 22

string get_job_info(object me,string info,int flag)
{
	int nowtime=time(),timep,cd,cd1,cd2,cd3,cd4,cd5,cd6;
	mapping quest;
	switch (flag)
	{
		case 1:
		info+=HIG"门忠任务[门]      "NOR;
		if(me->query("quest/type")) 
		{
			quest = me->query("quest");
			if (quest["type"] == "find")
			info+=HIM"你的任务是找回『"NOR+quest["name"]+HIM"』。\n" NOR;
			else if (quest["type"] == "kill")
			{
                info+=HIM"你的任务是杀了『"NOR+quest["name"]+HIM"』。\n" NOR;        
                if( me->query("quest/finish"))
                info+=HIM"              你已经杀了『"NOR+quest["name"]+HIM"』,赶快回去复命吧。\n" NOR; 
			}  
			else if (quest["type"] == "扫")
			{
                info+=HIM"你的任务是打扫『"NOR+quest["quest"]+HIM"』。\n" NOR;        
                if( me->query_temp("quest_finish"))
                info+=HIM"              你已经把『"NOR+quest["quest"]+HIM"』打扫干净了,赶快回去复命吧。\n" NOR; 
			}  
			else if (quest["type"] == "give")
			{
                info+=HIM"你的任务送『"NOR + quest["objname"] + HIM"』给『"+quest["name"]+"』。\n" NOR;        
                if( me->query("quest/finish"))
                info+=HIM"              你已经把『"NOR + quest["objname"] + HIM"』送给了『"NOR+quest["name"]+HIM"』,赶快回去复命吧。\n" NOR; 
			}
			else if (quest["type"]=="win")
			{
                info+=HIM"你的任务是战胜『"NOR+quest["name"]+HIM"』。\n" NOR;        
                if( me->query("quest/finish"))
                info+=HIM"              你已经战胜了『"NOR+quest["name"]+HIM"』,赶快回去复命吧。\n" NOR; 
	        }
	        if (me->query("quest/time") <= time() )
		        info+=HIM"              但你已经没有时间完成了。\n"NOR;
	        else
	        {
                 timep=me->query("quest/time")-time();
                 info+=HIM"              你还有"NOR+time_change(timep)+HIM"来完成它。\n"NOR; 
            }
		}
		else info+=HIM"未接受任务。\n"NOR;
		break;
		case 2:
		info+=HIG"门派任务[门]      "NOR;
		if(quest =  me->query("wsquest"))
		{
			info+=HIM"你现在的任务是"NOR + quest["quest_type"] + HIM"『"NOR + quest["quest"] + HIM"』。\n"NOR;
			nowtime = (int) me->query("task_time") - time();
			if( nowtime  > 0 )
			time_change(nowtime);
			else
			info+=HIM"              但是你已经没有足够的时间来完成它了。\n"NOR;
		}
		else info+=HIM"未接受任务。\n"NOR;
		break;
		case 3:
		info+=HIG"送信[新]          "NOR;
		if (me->query("songxin")&&me->query("combat_exp")<10000&&me->query("mud_age")<86400)
		{
			info+=HIM"你现在要去给"NOR + me->query("songxin/target_name") + HIM"送信。\n"NOR;
			if (!objectp(present("xin jian",me)))
			info+=HIM"              但是已经没有时间了，信件被风吹雨淋弄得破损掉了。\n"NOR;
		}
		else info+=HIM"未接受任务。\n"NOR;
		break;
		case 4:
		info+=HIG"唱戏任务[新]      "NOR;
		if ( me->query("obj/changxi") && me->query("combat_exp") < 100000)
		{
            info+=HIM"你现在应该去"NOR+me->query("obj/where")+HIM"表演。\n"NOR;
            if (me->query("obj/done"))
            info+=HIM"              你已经表演完了，赶快回去复命吧。\n"NOR;
		}
		else info+=HIM"未接受任务。\n"NOR;
		break;
		case 5:
		info+=HIG"灵柩护卫任务[新]  "NOR;
		if (me->query_temp("ljhwjob"))
		info+=HIM"你现在去"NOR+me->query_temp("ljhwjob")+HIM"护卫。\n"NOR;
		else info+=HIM"未接受任务。\n"NOR;
		break;
		case 6:
		info+=HIR"玉玺任务[主]      "NOR;
		if (me->query("murong/yuxi"))
		{
			if (me->query_temp("murong/yuxi_where"))
			info+=HIM"你要去找回在"NOR + me->query_temp("murong/yuxi_where") + HIM"出现的大燕传国玉玺。\n"NOR;
			else
			info+=HIR"你的慕容任务已经失败。\n"NOR;
		}
		else
		{
			cd=0;
			if (me->query("murongjob/mayberobot")&&me->query("combat_exp")>3000000 && me->query("antirobot/deactivity") > 1)
			cd+=120;
			if (me->query_combatgrade() >=20)
			cd1=cd+40;
			if (me->query("murong/lianxu_fail") > 4)
			{
				cd1=(cd+60)*(me->query("murong/lianxu_fail")-4);
				if (time()- me->query("mrjob_busy")>=cd1)
				info+=HIM+"现在即可接到下个任务。\n"+NOR;
				else
				info+=HIR"仍需"NOR+time_change(cd1+me->query("mrjob_busy")-time())+HIR"才能接到下个任务。\n"NOR;
			}
			else
			{
				if (time()- me->query("mrjob_busy")>=cd1)
				info+=HIM+"现在即可接到下个任务。\n"+NOR;
				else
				info+=HIR"仍需"NOR+time_change(cd1+me->query("mrjob_busy")-time())+HIR"才能接到下个任务。\n"NOR;
            }
        }
		break;
		case 7:
		info+=HIR"韩员外复仇[主]    "NOR;
		if (me->query_temp("hyw/start"))
		{
			if (me->query_temp("hyw/pic"))
			info+=HIM"图片版任务。\n"NOR;
			else
			info+=HIM"你现在要去"NOR + me->query_temp("hyw/where") + HIM"杀死"NOR + me->query_temp("hyw/name")+ HIM"。\n"NOR;
		}
		else
		{
			cd=0;
			if (me->query("hyw/jobmayberobot")&&me->query("combat_exp")>3000000 && me->query("antirobot/deactivity") > 1)
			cd+=180;
			if (me->query("hyw/lianxu_fail") > 3)
			{
				cd1=60*(me->query("hyw/lianxu_fail")-4);
				if (time()- me->query("hyw/lasttime")>=cd1)
				info+=HIM+"现在即可接到下个任务。\n"+NOR;
				else
				info+=HIR"仍需"NOR+time_change(cd1+me->query("hyw/lasttime")-time())+ HIR"才能接到下个任务。\n"NOR;
            }
			else
			{
				if (time()-me->query_temp("shilian/start")<1800)
				{
					cd1 = cd+90;
				}
				else
				{
					cd1 = cd+180;
				}
				if (time()- me->query("hyw/lasttime")>=cd1)
				info+=HIM+"现在即可接到下个任务。\n"+NOR;
				else
				info+=HIR"仍需"NOR+time_change(cd1+me->query("hyw/lasttime")-time())+HIR"才能接到下个任务。\n"NOR;
            }
		}
		break;
		case 8:
		info+=HIR"都统制府刺杀[主]  "NOR;
		if (me->query("mzj/is_on"))
		info+=HIM"你的任务是刺杀卖国求荣的汉奸某某。\n"NOR;
		else
		if (time()-me->query("mzj/last_task")<"/d/yingtiansouth/dufu/npc/meng"->cd(me))
		info+=HIR"仍需"NOR+time_change("/d/yingtiansouth/dufu/npc/meng"->cd(me)-(time()-me->query("mzj/last_task")))+HIR"才能接到下个任务。\n"NOR;
		else
		info+=HIM+"现在即可接到下个任务。\n"+NOR;
		break;
		case 9:
		info+=HIR"护镖任务[主]      "NOR;
		if (me->query("in_dart"))
		{
			if (me->query_temp("dart_name"))
			info+=HIM"你需要把镖车运给"NOR+me->query_temp("dart_name") + HIM"的伙计"NOR + me->query_temp("huoji_name")+HIM"，他会在"NOR+me->query_temp("huoji_where")+HIM"接应你！\n"NOR;
			else
			info+=HIM"你上次的运镖任务没有完成。\n"NOR;
			if (me->query_temp("over_dart"))
			info+=HIM"              你的镖已经运到了，赶快回去复命吧！\n"NOR;
		}
		else
		{
			cd = 180 + (me->query("last_yunbiao_ask_eslvl")-1)*60 + me->query("last_yunbiao_time") - time();
			if (cd <= 0)
			{
				info+=HIM"现在即可接到下个";
				switch(me->query("last_yunbiao_ask_eslvl"))
				{
					case 0:
                    info+="新手镖局";
                    break;
					case 1:
                    info+="普通镖局";
                    break;
					case 2:
                    info+="长途镖局";
                    break;
				}
            info+="的任务。\n"NOR;
			}
			else
			{
				info+=HIR"仍需"NOR+time_change(cd)+HIR"才能接到下个";
				switch(me->query("last_yunbiao_ask_eslvl"))
				{
					case 0:
                    info+="新手镖局";
                    break;
					case 1:
                    info+="普通镖局";
                    break;
					case 2:
                    info+="长途镖局";
                    break;
				}
            info+="的任务。\n"NOR;
			}
		}
		break;
		case 10:
		info+=HIR"胡一刀任务[主]    "NOR;
		if (!me->query_temp("yidao/done") && me->query("yidao/on_job"))
		{
			if ( me->query("yidao/questid")=="random" )
			info+=HIM"你现在去"NOR+me->query_temp("yidao/where")+HIM"寻找盗宝人"NOR+me->query_temp("yidao/killer")+HIM"。\n"NOR;
			else 
			info+=HIM"正在进行胡一刀任务。\n"NOR;
		}
		else
		{
			cd = ((int)me->query("yidao/times")-250)/70;
			if (cd<=0) cd=0;
			if (cd>=5) cd=5;
			if ((int)me->query("yidao/times")>1600)
			{
				cd=cd-((int)me->query("yidao/times")-1600)/500;
				if (cd<=0)
				cd=0;
			}
			if (me->query_temp("yidaonotrobot")>0)
			cd=5;
			if(ANTIROBOT_D->stopped())
			{
			cd = ((int)me->query("yidao/times")-250)/70;
            if (cd<=0) cd=0;
            if (cd>=5) cd=5;
			}
			cd=cd*60;
			if( (int)me->query("yidao/last_asked") + 600 - cd< time() )
			info+=HIM+"现在即可接到下个任务。\n"+NOR;
			else
			info+=HIR"仍需"NOR+time_change(600-cd-time()+(int)me->query("yidao/last_asked"))+HIR"才能接到下个任务。\n"+NOR;
        }
		break;
		case 11:
		info+=HIR"萧峰任务[主]      "NOR;
		if (me->query("xiaofeng/on_job")==1)
		info+=HIM"你现在应该去"NOR+me->query_temp("xiaofeng/job")+HIM",他会在"NOR+me->query_temp("xiaofeng/target_place")+HIM"出没。\n"NOR;		
		else
		{
			if (me->query("hansz/on_job")==1)
			info+=HIM+"你现在身上有韩世忠任务在身，无法同时接到萧峰任务。\n"+NOR;
			else if (me->query("gongsun/on_job")==1)
			info+=HIM+"你现在身上有公孙止任务在身，无法同时接到韩世忠任务。\n"+NOR;
			else if(time() - me->query("hansz/last_fail") >= 300&&time() - me->query("hansz/last_job") >= 180
			&&time() - me->query("xiaofeng/last_fail") >= 300&&time() - me->query("xiaofeng/last_job") >= 180
			&&time() - me->query("gongsun/last_fail") >= 300&&time() - me->query("gongsun/last_job") >= 180)
			info+=HIM+"现在即可接到下个任务。\n"+NOR;
			else
			{
				cd1=300-(time()-me->query("xiaofeng/last_fail"));
				cd2=180-(time()-me->query("xiaofeng/last_job"));
				cd3=300-(time()-me->query("hansz/last_fail"));
				cd4=180-(time()-me->query("hansz/last_job"));
				cd5=300-(time()-me->query("gongsun/last_fail"));
				cd6=180-(time()-me->query("gongsun/last_job"));
				cd=max(({cd1,cd2,cd3,cd4,cd5,cd6}));
				info+=HIR"仍需"NOR+time_change(cd)+HIR"才能接到下个任务。\n"+NOR;
			}
		}
		break;
		case 12:
		info+=HIR"韩世忠任务[主]    "NOR;
		if (me->query("hansz/on_job")==1)
		{
			if (objectp(me->query_temp("hansz/task_place")))
			{
				if (me->query_temp("hansz/pic_job"))
				info+=HIM+"图片版任务。\n";
				else
				info+=HIM+"你被要求去打探消息的地点是"+NOR+me->query_temp("hansz/task_place")->query("short")+HIM+"。\n"NOR;	
			}
			else
			info+=HIR+"你的韩世忠任务已经失败。\n"+NOR;
		}
		else
		{
			if (me->query("xiaofeng/on_job")==1)
			info+=HIM+"你现在身上有萧峰任务在身，无法同时接到韩世忠任务。\n"+NOR;
			else if (me->query("gongsun/on_job")==1)
			info+=HIM+"你现在身上有公孙止任务在身，无法同时接到韩世忠任务。\n"+NOR;
			else if(time() - me->query("hansz/last_fail") >= 300&&time() - me->query("hansz/last_job") >= 180
			&&time() - me->query("xiaofeng/last_fail") >= 300&&time() - me->query("xiaofeng/last_job") >= 180
			&&time() - me->query("gongsun/last_fail") >= 300&&time() - me->query("gongsun/last_job") >= 180)
			{
				info+=HIM+"现在即可接到下个任务。\n"+NOR;
			}
			else
			{
				cd1=300-(time()-me->query("xiaofeng/last_fail"));
				cd2=180-(time()-me->query("xiaofeng/last_job"));
				cd3=300-(time()-me->query("hansz/last_fail"));
				cd4=180-(time()-me->query("hansz/last_job"));
				cd5=300-(time()-me->query("gongsun/last_fail"));
				cd6=180-(time()-me->query("gongsun/last_job"));
				cd=max(({cd1,cd2,cd3,cd4,cd5,cd6}));
				info+=HIR"仍需"NOR+time_change(cd)+HIR"才能接到下个任务。\n"+NOR;
			}
		}
		break;
		case 13:
		info+=HIR"公孙止任务[主]    "NOR;
		if (me->query("gongsun/on_job")==1)
		{
			info+=HIR+"你的公孙止任务正在进行中……\n"+NOR;
		}
		else
		{
			if (me->query("xiaofeng/on_job")==1)
			info+=HIM+"你现在身上有萧峰任务在身，无法同时接到公孙止任务。\n"+NOR;
			else if (me->query("hansz/on_job")==1)
			info+=HIM+"你现在身上有韩世忠任务在身，无法同时接到公孙止任务。\n"+NOR;
			else if(time() - me->query("hansz/last_fail") >= 300&&time() - me->query("hansz/last_job") >= 180
			&&time() - me->query("xiaofeng/last_fail") >= 300&&time() - me->query("xiaofeng/last_job") >= 180
			&&time() - me->query("gongsun/last_fail") >= 300&&time() - me->query("gongsun/last_job") >= 180)
			{
				info+=HIM+"现在即可接到下个任务。\n"+NOR;
			}
			else
			{
				cd1=300-(time()-me->query("xiaofeng/last_fail"));
				cd2=180-(time()-me->query("xiaofeng/last_job"));
				cd3=300-(time()-me->query("hansz/last_fail"));
				cd4=180-(time()-me->query("hansz/last_job"));
				cd5=300-(time()-me->query("gongsun/last_fail"));
				cd6=180-(time()-me->query("gongsun/last_job"));
				cd=max(({cd1,cd2,cd3,cd4,cd5,cd6}));
				info+=HIR"仍需"NOR+time_change(cd)+HIR"才能接到下个任务。\n"+NOR;
			}

		}
		break;
		case 14:
		info+=HIR"万安塔任务[主]    "NOR;
		if (environment(me)->query("main_dir")=="/d/wananta/")
		info+=HIM+"进行中……\n"NOR;
		else if (time()-me->query("wananta/start")>900)
		info+=HIM+"现在即可接到下个任务。\n"+NOR;
		else
		info+=HIR"仍需"NOR+time_change(900-time()+me->query("wananta/start"))+HIR"才能接到下个任务。\n"+NOR;
		break;
		case 15:
		info+=HIG"华山送信任务[特]  "NOR;
		if (me->query_temp("huashan/on_songxin"))
		info+=HIM"你现在应该去"NOR+me->query_temp("huashan/songxin/target_name")+HIM"送信,他在"NOR+me->query_temp("huashan/songxin/where")+HIM"附近。\n"NOR; 
		else
		{
			if(time() - me->query("huashan/last_fail") >= 180&&time() - me->query("huashan/last_songxin")>=60)
			info+=HIM+"现在即可接到下个任务。\n"+NOR;
			else
			{
				cd1=180-(time()-me->query("huashan/last_fail"));
				cd2=60-(time()-me->query("huashan/last_songxin"));
				cd=max(({cd1,cd2}));
				info+=HIR"仍需"+time_change(cd)+"才能接到下个任务。\n"NOR;
			}

		}
		break;
		case 16:
		info+=HIG"投名状任务[特]    "NOR;	
		if (me->query("jiaofei/tmz/on_job") && me->query_temp("jiaofei/tmz/questmsg"))
		info+= me->query_temp("jiaofei/tmz/questmsg");
		else if (time()-me->query("jiaofei/tmz/last_time")>0)
		info+=HIM+"现在即可接到下个任务。\n"+NOR;
		else
		info+=HIR"仍需"NOR+time_change(me->query("jiaofei/tmz/last_time")-time())+HIR"才能接到下个任务。\n"+NOR;
		break;
		case 17:
		info+=HIG"锻造术任务[特]    "NOR;
		if (me->query("forgingjob/onduty")==1)
		info+=HIM"你现在要做3次"NOR + me->query("forgingjob/nextjob") + HIM"任务。\n"NOR;
		else
		info+=HIM+"未接受任务。\n"+NOR;
		break;
		case 18:
		info+=HIG"满不懂任务[特]    "NOR;
		quest = me->query("wquest");
		if(me->query("wquest"))
		{
			if (quest["quest_type"] == "寻")
			info+=HIM"你的任务是找回『"NOR+quest["quest"]+HIM"』。\n"NOR;
			else if (quest["quest_type"] == "杀")
			{
				info+=HIM"你的任务是杀了『"NOR+quest["quest"]+HIM"』。\n" NOR;        
				if( me->query("quest/finish"))
				info+=HIM"              你已经杀了『"NOR+quest["quest"]+HIM"』,赶快回去复命吧。\n"NOR; 
			}  
			else if (quest["type"] == "扫")
			{
				info+=HIM"你的任务是打扫『"NOR+quest["quest"]+HIM"』。\n" NOR;        
				if( me->query_temp("quest_finish"))
				info+=HIM"              你已经把『"NOR+quest["quest"]+HIM"』打扫干净了,赶快回去复命吧。\n"NOR; 
			}  
			else if (quest["type"] == "give")
			{
				info+=HIM"你的任务送『"NOR + quest["objname"] + HIM"』给『"NOR+quest["name"]+HIM"』。\n" NOR;        
				if( me->query("quest/finish"))
				info+=HIM"              你已经把『"NOR + quest["objname"] + HIM"』送给了『"NOR+quest["name"]+HIM"』,赶快回去复命吧。\n" NOR; 
			}
			else if (quest["type"]=="win")
			{
				info+=HIM"你的任务是战胜『"NOR+quest["name"]+HIM"』。\n"NOR;        
				if( me->query("quest/finish"))
				info+=HIM"              你已经战胜了『"NOR+quest["name"]+HIM"』,赶快回去复命吧。\n" NOR; 
			}
			if (me->query("wjob/task_time") <= time() )
            info+=HIM"              但你已经没有时间完成了。\n"NOR;
			else
			{
				timep=me->query("wjob/task_time")-time();
				info+=HIM"              你还有"NOR+time_change(timep)+HIM"来完成它。\n"NOR; 
			}
		}
		else info+=HIM+"未接受任务。\n"+NOR;
		break;
		case 19:
		info+=HIC+"萧半和任务[特]    "+NOR;
		if (!me->query_temp("banhe")) info+=HIM+"未接受任务。\n"+NOR;
		else if (!me->query_temp("banhe/lianxu"))  
		info+=HIM"你的任务是解决找萧中慧麻烦的贼人。\n"NOR;
		else if (me->query_temp("banhe/zhonghui"))
		info+=HIM"你的任务是把迷路的萧中慧带回家。\n"NOR;
		else
		info+=HIM"你的任务是解决找萧中慧麻烦的贼人同伙『"NOR+me->query_temp("banhe/current_qiangdao")+HIM"』。\n"NOR;
		break;
		case 20:
		info+=HIC+"鄱阳湖寻宝[特]    "+NOR;
		if (!me->query("pyh/start")&&time()-(me->query("pyh/starttime"))<7200)
		info+=HIR"仍需"NOR+time_change(7200+me->query("pyh/starttime")-time())+HIM"才能接到下个任务。\n"NOR;
		else
		{
			if (me->query("pyh/start"))
			info+=HIM+"进行中……\n"+NOR;
			else
			info+=HIM+"现在即可接到下个任务。\n"+NOR;
		}
		break;
		case 21:
        info+=CYN+"铜雀台任务[特]    "+NOR;
        if (me->query("safari"))
        info+=HIM+"进行中……\n"+NOR;
		else if (time()-me->query("safari_init_time")<3600*24*3)
		info+=HIR"仍需"NOR+time_change(3600*24*3+me->query("safari_init_time")-time())+HIR"才能接到下个任务。\n"NOR;
		else
		info+=HIM+"现在即可接到下个任务。\n"+NOR;
		break;
        case 22:
        info+=CYN+"百晓生任务[特]    "+NOR;
        if (me->query("baixiaosheng/tiaozhan"))
        info+=HIM+"进行中……\n"+NOR;
        else
        {
            if (time()-me->query("baixiaosheng/tz_time")<720)
            info+=HIR"仍需"NOR+time_change(720+me->query("baixiaosheng/tz_time")-time())+HIR"才能接到下个任务。\n"NOR;
            else
			info+=HIM+"现在即可接到下个任务。\n"+NOR;
		}
		break;
	}
	return info;
}

int my_setting(object me,int no,int flag)
{
	int *list=({});
	string act="减去";
	if (me->query("MyJobqueryCustom")&&arrayp(me->query("MyJobqueryCustom")))
	list=me->query("MyJobqueryCustom");
	if (flag)//+
	{
		act="加上";
		if (member_array(no,list)==-1)
			list+=({no});
	}
	else
	{
		if (member_array(no,list)!=-1)
			list-=({no});
	}
	me->set("MyJobqueryCustom",list);
	tell_object(me,"你"+act+"了"+no+"号任务查询。\n");
	if (sizeof(list)<1)
	{
		me->delete("MyJobqueryCustom");
		tell_object(me,"你自定义jobquery为空，下次将显示所有任务。\n");
	}
	return 1;
}
int main(object me,string arg)
{
    string info="",msg="",space;
	int start=START,end=END,no;
	if (arg=="-m")
	{
		start=START_M;
		end=END_M;
	}
	if (arg=="-x")
	{
		start=START_X;
		end=END_X;
	}
	if (arg=="-z")
	{
		start=START_Z;
		end=END_Z;
	}
	if (arg=="-t")
	{
		start=START_T;
		end=END_T;
	}
	if (arg=="cancel")
	me->delete("MyJobqueryCustom");
	if (arg&&sscanf(arg,"++%d",no)==1)
	{
		if (no>END||no<START)
		return notify_fail("你设置的数字不在列表中。("+START+"~"+END+")\n");
		return my_setting(me,no,1);
	}
	if (arg&&sscanf(arg,"--%d",no)==1)
	{
		if (no>END||no<START)
		return notify_fail("你设置的数字不在列表中。("+START+"~"+END+")\n");
		return my_setting(me,no,0);
	}
	if (me->query("MyJobqueryCustom")&&arrayp(me->query("MyJobqueryCustom"))&&arg!="-all")
	for (int i=0;i<sizeof(me->query("MyJobqueryCustom"));i++)
	{
		if (me->query("MyJobqueryCustom")[i]<10) space=" ";
		else space="";
		msg+=sprintf("[%d]",me->query("MyJobqueryCustom")[i])+space+get_job_info(me,info,me->query("MyJobqueryCustom")[i]);
	}
	else
	for (int i=start;i<=end;i++)
	{
		if (i<10) space=" ";
		else space="";
		msg+=sprintf("[%d]",i)+space+get_job_info(me,info,i);
	}
	msg="\t\t       "HBRED+HIW+"任務查詢助理\n"+NOR+HEAD+msg;
tell_object(me,msg);
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

int help(object me)
{
        write(@HELP
指令格式 : jobquery

这个指令可以显示你当前的任务状态，包括门忠任务，满不懂任务等等。
自定义jobquery -m 显示门派任务 -x 新手任务 -z 主流任务 -t 特殊
任务，jobquery ++ 加入自定义任务列表，比如jobquery ++1 把1号任
务加入列表。 --从自定义列表中删除。
HELP
    );
    return 1;
}
