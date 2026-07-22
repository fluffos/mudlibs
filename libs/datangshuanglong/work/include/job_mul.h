/*
该文件定义了所有JOB的奖励在原有基础上的倍数控制，100表示不变
LinuX@SJ 04/03/01
*/

// Ciwei@SJ 提高烧草料、星宿抢劫、刺杀任务 三个任务的奖励
// 即GBLU_JOB_MUL XXQJ_JOB_MUL 实际影响到的任务 提高烧草料、星宿抢劫、刺杀任务 还有告急
// 分别提高50% 7,7,2004-2:30

/*
一些小说明： 
gifted 是指该job已经加上了GIFTD的job奖励。
nogiftd指没有加上GIFTD奖励。
如果什么都没有说明没有做任何处理
joblist后的名字是该job的job_time/xxxx中的xxxx名字
后面的路径是涉及到的文件的路径。
便于今后更新查找
*/
#ifndef _JOBMUL_H_
#define _JOBMUL_H_

#define VIP_MUL		  110	//贵宾玩家和普通玩家的增长速度控制
#define VIP_LINGWU_MUL	  110   //贵宾玩家和普通玩家的领悟速度控制
#define VIP_LEARN_MUL	  110   //贵宾玩家和普通玩家的学习速度控制
#define VIP_STUDY_MUL	  110   //贵宾玩家和普通玩家的读书速度控制
#define ROBOT_MUL	50	 //ROBOT玩家的成长速度

#define SL_LINGWU_MUL	  100   //少林领悟
#define MR_LINGWU_MUL	  100   //慕容领悟
#define LEARN_MUL	  100   //学习速度
#define STUDY_MUL	  100   //读书速度

/*公众任务(个人)*/
#define WG_JOB_MUL        120	//武官任务 gifted joblist:武馆 /d/wuguan/npc/dizi1.c
#define XC_JOB_MUL        120	//巡城任务 gifted joblist:大理	巡城			   /d/dali/npc/zhudanchen.c			
#define SX_JOB_MUL        50	//送信任务 gifted joblist:大理  送信               /d/dali/job/dali_letter.c
#define GBWU_JOB_MUL      60	//丐帮吴长老杀人任务            gifted    joblist:丐帮                     /adm/daemons/taskd.c
																									// /kungfu/gaibang/wu.c
#define GBLU_JOB_MUL      120	//丐帮鲁长老报效国家任务           gifted  joblist:告急           // 告急: /kungfu/class/gaibang/obj/gaoji-wenshu.c
							///kungfu/class/gaibang/gb_lujob.h
																  // gifted		joblist:报效国家 草料场			// 草料场：/kungfu/class/gaibang/lu.c	
																  // gifted	joblist:报效国家 刺杀		// 刺杀：/d/gb/npc/yuanshuai.c
#define SS_JOB_MUL        60	//嵩山任务			gifted					/adm/daemons/taskd.c    taskd 统一计算， 实际变化为GBWU_JOB_MUL
																				// /kungfu/class/songshan/zuo.c zuo.h
#define WD_JOB_MUL        80	//武当任务 gifted    joblist:武当 武当恶贼                           /kungfu/class/wudang/song.c
#define LAOZU_JOB_MUL     80	//雪山任务 gifted    joblist:雪山                            
#define XX_JOB_MUL        80	//星宿任务 gifted    joblist:星宿               /adm/daemons/taskd.c     taskd 统一计算， 实际变化为GBWU_JOB_MUL 
																							// /d/xingxiu/npc/ding.c
#define XXQJ_JOB_MUL 	  100	//星宿抢劫任务           nogifted  joblist:抢劫                              /d/xingxiu/npc/anran.c
#define HS_JOB_MUL        50   //华山任务               gifted    joblist:华山                  /d/huashan/npc/yuebuqun.c


#define TDH_JOB_MUL       55	//天地会任务  /clone/npc/tdh/man1.h
#define CHANGLE_JOB_MUL	  100	//长乐帮任务  /d/changle/npc/bei.c
#define HZ_JOB_MUL        40	//海战任务 玩家已经有全自动robot，速度可以达到8K/小时 /d/sld/seawar/seaward.c
#define SWZB_JOB_MUL      100	//狮王争霸任务 测试期间，先调低看看

/*特殊JOB*/
#define ZHUANJI_JOB_MUL			100   //传记JOB /clone/npc/zha
#define LOSELETTER_JOB_MUL		100   //丢失的信JOB /clone/gift/loseletter.c
/*这两个任务是补pot的*/
#define ZM_JOB_MUL        100	//赵敏任务            gifted    joblist:赵敏                                    /d/city/kedian/zhao.c
#define H7G_JOB_MUL       70	//洪七公任务          nogifted   joblist:洪七公                         /kungfu/class/gaibang/h7g.c
/*这两个job暂时不理会*/

/*公众任务(团队)*/
#define HUBIAO_JOB_MUL    120   //护镖任务            gifted   joblist:护镖            /d/fuzhou/hubiao/obj/cart.c /d/fuzhou/hubiao/hubiao.h
#define JIUYUAN_JOB_MUL   100	//少林救援任务        gifted     joblist:少林                                   /kungfu/class/shaolin/fang-zheng.c
#define SMY_JOB_MUL       100	//摩颂崖抗敌任务      gifted   joblist:报效国家 颂摩崖                              /kungfu/condition/smy_job.c

/*门派任务*/

/*
sld job
///d/sld/npc/obj/suomp.c -> /tmp/ciwei/job/suomp.c 成功。
///d/sld/npc/obj/zhaohp.c -> /tmp/ciwei/job/zhaohp.c 成功。
*/

#define SL_AOZHOU_JOB_MUL 	70	//少林熬粥任务        nogifted    joblist:少林 少林熬粥                               /d/shaolin/xjchu.c
#define SL_CAIDI_JOB_MUL  	70	//少林菜地任务        nogifted    joblist:少林菜地                               /d/shaolin/obj/tie-tong.c
#define SL_LUNZHI_JOB_MUL       70	//少林轮值任务    nogifted    joblist:少林 少林轮值                              /kungfu/class/shaolin/hui-xiu.c
#define SL_MONK_JOB_MUL      	70	//少林武僧堂任务  nogifted    joblist:少林  罗汉堂                             /kungfu/class/shaolin/wuseng.h
                                                                                                         // job 次数统计在 /kungfu/class/shaolin/xuan-can.h
#define SL_DUSHI_JOB_MUL      	70	//少林渡世济人任务 nogifted   joblist:佛法降魔                               /kungfu/class/shaolin/xuan-du.h
/*这个job暂时不理会*/
#define MJ_XUNLUO_JOB_MUL       70	//明教巡逻任务     nogifted   joblist:明教 明教巡逻                               /kungfu/class/mingjiao/wei.c
#define MJ_SHOUWEI_JOB_MUL      70//明教守卫任务     nogifted   joblist:明教守卫                              /kungfu/class/mingjiao/chang.c
#define THD_SHOUMU_JOB_MUL      70	//桃花岛守墓任务   nogifted   joblist:桃花岛                               /d/thd/npc/thdjob.h
#define GM_HUMU_JOB_MUL     	70	//古墓护墓任务     nogifted   joblist:古墓护墓                               /d/gumu/fang.c
#define GM_FENGCHAO_JOB_MUL     70	//古墓蜂巢任务     nogifted   joblist:古墓蜂巢                               /d/gumu/yaofang.c
#define TZ_JOB_MUL 	  	70	//铁掌帮任务               nogifted   joblist:铁掌                               /d/tiezhang/npc/tz_job1.c
#define MR_TOUXUE_JOB_MUL       70	//慕容偷学任务     nogifted   joblist:慕容                               /d/mr/npc/murong-fu.c
#define EM_YUANBING_JOB_MUL 	70	//峨嵋元兵任务     nogifted   joblist:峨嵋元兵                               /kungfu/condition/em_job1.c
#define WD_SHOUDING_JOB_MUL     70	//武当守鼎任务     nogifted   joblist:看守铜鼎                               /d/wudang/ldfang.c

/*职业系统*/
#define ZY_CAIKUANG_MUL         70     ///采矿            nogifted   no joblist  /d/zhiye/caikuang-chang.h
#define ZY_CAIKUANG_JOB_MUL     70     //采矿job          nogigted   no joblist  /d/zhiye/npc/tiejiang.c
#define ZY_ZHUJIAN_JOB_MUL      70     //送剑job          nogifted   no joblist  /d/zhiye/npc/zhujian-shi.c
#define ZY_ZHUJIAN_MUL          70     //                 nogifted   no joblist  /d/zhiye/obj/zhujianlu.c
#define ZY_NONGSANG_MUL         70     //农桑             nogifted   no joblist  /d/zhiye/nongtian.h   sanglin.h
#define ZY_ZHIZAO_JOB_MUL       70     //zhizaojob        nogited    no joblist  /d/zhiye/npc/caifeng.c
#define ZY_ZHIZAO_MUL           70     //zhizao           nogifted   no joblist  /d/zhiye/obj/caifengzhuo.c

#define JOB_GIFT_MUL ([ \
	"抢劫"               :70,/**/\
	"雪山"               :100,/**/\
	"长乐帮"             :100,/**/\
	"武馆"               :120,/**/\
	"巡城"               :100,/**/\
	"送信"               :100,/**/\
	"嵩山"               :100,/**/\
	"丐帮"               :150,/**/\
	"星宿"               :100,/**/\
	"告急"               :120,/**/\
	"草料场"             :100,/**/\
	"刺杀"               :100,/**/\
	"武当"               :120,/**/\
	"华山"               :100,/**/\
	"天地会"             :150,/**/\
	"神龙岛海战"         :100,/**/\
	"大清国海战"         :150,/**/\
	"传记"               :100,/**/\
	"丢失的信"           :100,/**/\
	"护镖"               :130,/**/\
	"少林救援"           :70,/**/\
	"颂摩崖"             :150,/**/\
	"神龙索命"           :70,/**/\
	"神龙招魂"           :70,/**/\
	"少林熬粥"           :70,/**/\
	"少林菜地"           :70,/**/\
	"少林轮值"           :70,/**/\
	"少林教和尚"         :70,/**/\
	"明教巡逻"           :70,/**/\
	"明教守卫"           :70,/**/\
	"桃花岛"             :70,/**/\
	"古墓护墓"           :70,/**/\
	"古墓蜂巢"           :70,/**/\
	"铁掌"               :70,/**/\
	"慕容"               :70,/**/\
	"峨嵋元兵"           :70,/**/\
	"看守铜鼎"           :70,/**/\
	"采矿"               :70,/**/\
	"采矿任务"           :70,/**/\
	"送剑任务"           :70,/**/\
	"铸剑"               :70,/**/\
	"农桑"               :70,/**/\
	"织造任务"           :70,/**/\
	"织造"               :70,/**/\
	"七窍玲珑"           :70,/**/\
	"华山砍柴"           :70,/**/\
	"嵩山砌石"           :70,/**/\
])

#endif
