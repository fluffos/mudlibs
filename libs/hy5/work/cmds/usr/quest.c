#include <ansi.h>
 
inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object me, string arg)
{
	      string str,str2;
	      int k;
        int nowtime = time();
        mapping quest;
        object ob;
        ob=me;

//        if(!(quest =  me->query("quest")))
//               return notify_fail("你现在没有任何任务！\n");    
               
if (me->query("jobtg",1) && me->query("jobtime"))
{
	if ((int)me->query("jobtime",1)==1)
		str2="到任务吏那用quest领"+me->query_temp("mpjobn1",1)+"/"+me->query("jobtg",1)+"个人任务(help geren)";
		
	if ((int)me->query("jobtime",1)==2)
		str2="到任务吏那用job领"+me->query_temp("mpjobn3",1)+"/"+me->query("jobtg",1)+"对练任务(help geren)";
		
	if ((int)me->query("jobtime",1)==3)
		str2="比武战胜"+me->query_temp("mpjobn4",1)+"/"+me->query("jobtg",1)+"个玩家(不同IP)  ";
		
	if ((int)me->query("jobtime",1)==4)
		str2="扬威"+me->query("jobtgn")+"。"+me->query_temp("mpjobn5",1)+"/"+me->query("jobtg",1)+"个敌人 干掉他们(kantou)";
		
			if ((int)me->query("jobtime",1)==5)
		str2="完成"+me->query_temp("mpjobn6",1)+"/"+me->query("jobtg",1)+"次襄阳守城任务 (help guojob)";
		
	if ((int)me->query("jobtime",1)==6)
		str2="完成"+me->query_temp("mpjobn7",1)+"/"+me->query("jobtg",1)+"次襄阳护送任务 (help wangjob)";
		
	if ((int)me->query("jobtime",1)==7)
		str2="玩成"+me->query_temp("mpjobn8",1)+"/"+me->query("jobtg",8)+"次 完整的江湖任务 杀死最后boss (help taskjobs)";
		
	if ((int)me->query("jobtime",1)==8)
		str2="完成"+me->query_temp("mpjobn2",1)+"/"+me->query("jobtg",1)+"次个门派组队任务 (help teamjob)";
		
	if ((int)me->query("jobtime",1)==9)
		str2="完成"+me->query_temp("mpjobn9",1)+"/"+me->query("jobtg",1)+"次官府任务       (help guanfu)";			

write("你现在的师傅任务是:" + str2+"。\n");
}        
   if (me->query("quest"))
   	{
   		quest =  me->query("quest");
if (quest["quest"]==0 || me->query("songxin"))
{
write("你现在的任务是:" + quest["quest_type"] + "『" + quest["quest_name"] + "』。\n");
}
else
{
        write("你现在的任务是" + quest["quest_type"] + "『" + quest["quest"] + "』。\n");
}

        nowtime = (int) me->query("task_time") - time();
        if( nowtime  > 0 )
                time_period(nowtime, me);
        else
{
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
write("但是你已经没有足够的时间来完成它了。\n");
}
}
str="";                
if (me->query_temp("nhdjob2lb"))
{
    str += sprintf(HIR"江湖任务:%s。help taskjobs\n"NOR, me->query_temp("nhdjob2sc"));
}

if (me->query_temp("hdjob2lb"))
{
str += sprintf("互动任务:%s。help hdjobs\n", me->query_temp("hdjob2sc"));
}


if (me->query_temp("obj/liangong"))
{
str += sprintf("对练任务。help geren\n");
}

if (me->query("nbjob",1)<20)
{
str += sprintf("古村新手任务未完成。help nbjob\n");
}

if (me->query("nbjob",1)>=20 && me->query("nbjob",1)<50)
{
str += sprintf("北丑新手任务未完成。help nbjob\n");
}

if (me->query_temp("xunchen"))
{
str += sprintf("巡城任务。help xunchen\n");
}
if (me->query_temp("findgirl"))
{
str += sprintf("田伯光任务。help tianjob\n");
}


if (me->query_condition("lyjob"))
{
str += sprintf("灵隐讲经任务。help lyjob\n");
}


if (me->query_condition("husong_busy") || me->query_temp("hu_song"))
{
str += sprintf("襄阳护送任务 目标"+me->query_temp("hstarget")+"。help wangjob\n");
}

if (me->query_condition("guanfu_task") || me->query_temp("guanfu_task"))
{
str += sprintf("官府任务。help guanfu\n");
}

if (me->query_temp("zzz_job_target") || (int)me->query_condition("zzz_mission"))
{
str += sprintf("襄阳任务 保护任务(单人)。help guojob\n");
}
if ((int)me->query_condition("zzz_busy"))
{
str += sprintf("襄阳任务 阻击任务(多人)。help guojob\n");
}
if (me->query_temp("mark/job_shadi"))
{
str += sprintf("襄阳任务 爱国任务(多人)。help guojob\n");
}
if (me->query_temp("in_dart") || (int)me->query_condition("dart_limit"))
{
str += sprintf("林家护镖任务。help hubiao\n");
}
if (me->query_temp("huang_job_target") || (int)me->query_condition("huang_mission"))
{
str += sprintf("黄蓉任务。help huangjob\n");
}
if (me->query_temp("job_moyao"))
{
str += sprintf("磨药任务。help moyao\n");
}
if (me->query_temp("work/kan"))
{
str += sprintf("砍树任务。help kanshu\n");
}
if (me->query_temp("obj/changxi"))
{
str += sprintf("唱戏任务。help changxi\n");
}

if ((int)me->query_condition("pkjob"))
{
str += sprintf("挑战任务\n");
}

if (me->query_temp("yljob2"))
{
str += sprintf("云龙救援任务。help yunlongjob\n");
}

if (me->query_temp("yljob2/changxi"))
{
str += sprintf("云龙宣传任务。help yljob2\n");
}

if (me->query_temp("xsjob2"))
{
str += sprintf("雪山抢美女任务。help xuedaojob\n");
}
if (me->query_condition("xsjob"))
{
str += sprintf("雪山讲经任务。help xueshanjob\n");
}
if (me->query_temp("作法事"))
{
str += sprintf("雪山法事任务。help mizongjob\n");
}

if (me->query_temp("xxjob2"))
{
str += sprintf("星宿抢富商任务。help xingxiujob\n");
}
if (me->query_temp("flattering"))
{
str += sprintf("星宿拍马任务。help xxpaimajob\n");
}

if (me->query_temp("singsong"))
{
str += sprintf("逍遥练琴任务。help xysingjob\n");
}
if (me->query("kill_xiaoyao"))
{
str += sprintf("逍遥七宝指环任务。help xiaoyaojob\n");
}

if (me->query_temp("wudujiao"))
{
str += sprintf("五毒捉毒虫任务。help wdjiaojob\n");
}
if (me->query_temp("wdhwjob"))
{
str += sprintf("五毒迎击任务。help wdyingjijob\n");
}

if (me->query("job/supervisor")) 
{
str += sprintf("武当制香任务。help wdzhixiang\n");
}
if (me->query_temp("in_guard"))
{
str += sprintf("武当守门任务。help wudangjob\n");
}

if (me->query_temp("job_name") || me->query_condition("tz_job") )
{
str += sprintf("铁掌守山任务。help tzjob2\n");
}

if (me->query("taohuajob"))
{
str += sprintf("桃花抢官船任务。help taohuajob\n");
}


if (me->query_temp("tangmen"))
{
str += sprintf("唐门做暗器任务。help tangmenjob\n");
}
if (me->query_temp("tmhw"))
{
str += sprintf("唐门护卫任务。help tmhuchengjob\n");
}


if (this_player()->query_temp("sld"))
{
str += sprintf("神龙钓鱼任务。help sldjob2\n");
}
if (me->query("kill_shenlong"))
{
str += sprintf("神龙42章经任务。help shenlongjob\n");
}

if (me->query_temp("wsdjob"))
{
str += sprintf("少林武僧堂任务。help slwsdjob\n");
}
if (me->query("shaolinjob"))
{
str += sprintf("少林救援任务。help shaolinjob\n");
}

if (me->query_temp("ryjob2/changxi"))
{
str += sprintf("日月游说任务。help ryjob2\n");
}
if (me->query_temp("in_guard"))
{
str += sprintf("日月守卫任务。help riyuejob\n");
}


if (me->query_temp("qz_caiyao"))
{
str += sprintf("全真采药任务。help qzcaiyao\n");
}
if (me->query_temp("qztjob") || me->query_condition("qztjob"))
{
str += sprintf("全真守护任务。help quanzhenjob\n");
}


if (me->query_temp("mrjob"))
{
str += sprintf("慕容玉玺任务。help mrjob\n");
}
if (me->query_temp("mr_job")=="浇花")
{
str += sprintf("慕容浇花任务。help mrjob2\n");
}

if (me->query_temp("mj2job"))
{
str += sprintf("明教反元任务。help mjjob2\n");
}
if (me->query("mjjob") )
{
str += sprintf("明教保卫任务。help mjjob\n");
}

if (me->query_temp("lxhw"))
{
str += sprintf("凌霄护卫任务。help lxhuweijob\n");
}
if (me->query_temp("lingxiao"))
{
str += sprintf("凌霄扫雪任务。help lingxiaojob\n");
}

if (me->query_temp("player_working"))
{
str += sprintf("灵鹫守门任务。help ljjob2\n");
}
if (me->query_temp("ljjob2"))
{
str += sprintf("灵鹫教援任务。help lingjiujob\n");
}


if (me->query_temp("xunshan"))
{
str += sprintf("华山巡山任务。help huashanjob\n");
}
if (me->query_temp("hs_times"))
{
str += sprintf("华山抓猴子任务。help zhuamonkey\n");
}

if (me->query_temp("gmjob"))
{
str += sprintf("古墓抓蜜蜂任务。help longnvjob\n");
}
if (me->query("kill_gumu"))
{
str += sprintf("古墓杀蒙古元帅任务。help gumujob\n");
}


if (me->query_temp("shouwei"))
{
str += sprintf("丐帮守卫任务。help gaibangjob\n");
}
if (me->query_temp("begging"))
{
str += sprintf("丐帮乞讨任务。help gbbegjob\n");
}



if (me->query_temp("fthwjob"))
{
str += sprintf("飞天护卫任务。help ftshouwei\n");
}

if (me->query_temp("smith/mo") || me->query_temp("smith/fenyao") || me->query_temp("smith/zhengli")) 
{
str += sprintf("飞天药店任务。help ftyaojob\n");
}


if (me->query_temp("emjob2") )
{
str += sprintf("峨眉除魔任务。help emeijob\n");
}
if (me->query_temp("dushi"))
{
str += sprintf("峨眉劝架任务。help xiuxingjob\n");
}


if (me->query_temp("garden_working"))
{
str += sprintf("大理除草任务。help dalijob2\n");
}
if (me->query_temp("tufei"))
{
str += sprintf("大理送军机任务。help dalijob\n");
}

if (me->query_temp("qljob"))
{
str += sprintf("白驼讨债任务。help baituojob\n");
}
if (me->query_temp("bt2_song"))
{
str += sprintf("白驼牧蛇任务。help btjob2\n");
}

if (me->query_temp("kl_working"))
{
str += sprintf("昆仑练琴任务。help btjob2\n");
}

if (me->query_temp("dl_job_target"))
{
str += sprintf("对练除恶任务。help geren\n");
}

if (me->query_temp("nmp1tg"))
{
str += sprintf("门派刺探任务。目标:"+me->query_temp("nmp1chinese")+"。\n");
}

if (me->query_temp("nmp2tg"))
{
str += sprintf("门派刺杀任务。目标:"+me->query_temp("nmp2tg")+"。\n");
}
 write(str);
        return 1;
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
指令格式 : quest  这个指令可以显示出你当前的任务。
HELP
        );
        return 1;
}