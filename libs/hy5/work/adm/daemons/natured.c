//侠客行100海洋II
//星星(lywin)由前人的natured.c为基础！加入夜间出现的飞贼和通告。2000/5/30

// natured.c
#include <ansi.h>
#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)
//#define TIME_TICK (time()*60-890000000)
//#define TIME_TICK1 (time()*60-900000000)
//#define TIME_TICK ((time()-900000000)*24)
//#define TIME_TICK1 ((time()-900000000)*24)
static int current_day_phase, current_month;
static string ppl;
mapping *day_phase;
string  zuji(string str);
string *month_desc = ({
	"「隆冬」:",
	"「寒冬」:",
	"「初春」:",
	"「早春」:",
	"「阳春」:",
	"「初夏」:",
	"「盛夏」:",
	"「仲夏」:",
	"「初秋」:",
	"「高秋」:",
	"「深秋」:",
	"「初冬」:",
});

string *weather_msg = ({
        "天空中万里无云",
        "几朵淡淡的云彩妆点著清朗的天空",
        "白云在天空中飘来飘去",
        "厚厚的云层堆积在天边",
        "天空中乌云密布",
});
mapping *where=({
        (["party":        "少林派",
        "where" :         "/d/shaolin/guangchang2",]),
        (["party":      "武当派",
        "where" :       "/d/wudang/guangchang",]),
        (["party":       "灵鹫宫",
        "where" :       "/d/lingjiu/dating",]),
        (["party":       "华山派",
        "where" :       "/d/huashan/qunxianguan",]),
        (["party":       "丐帮",
         "where" :       "/d/city/pomiao",]),
         (["party":       "大理段家",
         "where" :       "/d/dali/wfdating",]),
       (["party":       "古墓派",
         "where" :       "/d/gumu/qianting",]),
              (["party":       "星宿派",
         "where" :       "/d/xingxiu/xxh2",]),
               (["party":       "神龙教",
         "where" :       "/d/shenlong/dating",]),
               (["party":       "逍遥派",
         "where" :       "/d/xiaoyao/qingcaop",]),
               (["party":       "铁掌帮",
         "where" :       "/d/tiezhang/wztang",]),
                (["party":       "昆仑派",
         "where" :       "/d/kunlun/guangchang",]),
               (["party":       "桃花岛",
         "where" :       "/d/taohua/dating",]),
              (["party":       "白驼山派",
         "where" :       "/d/baituo/dating",]),
               (["party":       "雪山寺",
         "where" :       "/d/xueshan/dadian",]),
               (["party":       "全真教",
         "where" :       "/d/quanzhen/datang1",]),
                (["party":       "姑苏慕容",
         "where" :       "/d/mr/yanziwu",]),
                (["party":       "凌霄城",
         "where" :       "/d/lingxiao/dadian",]),
                (["party":       "五毒教",
         "where" :       "/d/wudujiao/dating",]),
                (["party":       "唐门",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "飞天御剑流",
         "where" :       "/d/feitian/daochang",]),
                (["party":       "唐门",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "海南派",
         "where" :       "/d/hainan/jingtang",]),
                (["party":       "侠客岛",
         "where" :       "/d/xiakedao/shiroom24",]),
                (["party":       "崆峒派",
         "where" :       "/d/xibei/kongdong/xuanyuan_gong",]),
                (["party":       "梅庄",
         "where" :       "/d/meizhuang/xiaowu",]),
                (["party":       "靖海派",
         "where" :       "/d/jinghai/jhd19",]),
                (["party":       "红花会",
         "where" :       "/d/huizhu/zongduo",]),
                (["party":       "青城派",
         "where" :       "/d/qingcheng/qiandian",]),
                (["party":       "泰山派",
         "where" :       "/d/taishan/riguan",]),
                (["party":       "嵩山派",
         "where" :       "/d/songshan/chanyuan",]),
                (["party":       "衡山派",
         "where" :       "/d/henshan/zhurongdian",]),
                (["party":       "恒山派",
         "where" :       "/d/hengshan/baiyunan",]),
                (["party":       "中州苗家",
         "where" :       "/d/zhongzhou/miaojia_houting",]),
                (["party":       "关外胡家",
         "where" :       "/d/guanwai/xiaowu",]),
                (["party":       "雁荡派",
         "where" :       "/d/yandang/luoyan6",]),

 });
mapping *read_table(string file);
void init_day_phase();

void create()
{
//        day_phase = read_table("/adm/etc/nature/day_phase");
//        init_day_phase();
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "三":
		case "四":
		case "五":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "六":
		case "七":
		case "八":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "九":
		case "十":
		case "十一":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "零":
		case "二":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		case "一":
		        if(get_day=="一")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		        
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


	init_day_phase();
}
/*
void init_day_phase()
{
        mixed *local;
        int i, t;

        // Get minutes of today.
        local = localtime(TIME_TICK1);
        t = local[2] * 60 + local[1];           // hour * 60 + minutes

        // Find the day phase for now.
        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];
                else
                        break;

        current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

        // Since in our time scale, 1 minute == 1 second in RL, so we don't need
        // any conversion before using this number as call_out dalay, if you
        // changed the time scale, be sure to convert it.

        call_out("update_day_phase",
      (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}*/
void init_day_phase()
{
	mixed *local;
	int i, t;


	local = localtime(TIME_TICK1);
	t = local[2] * 60 + local[1];      


	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_month = local[4];


	remove_call_out("init_day_phase");
	call_out("init_day_phase", 180);


	remove_call_out("update_day_phase");	



	call_out("update_day_phase",
	(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
	int j,i;
	object where, ob, *ob_list;
        remove_call_out("update_day_phase");

        current_day_phase = (++current_day_phase) % sizeof(day_phase);
        switch (day_phase[current_day_phase]["outcolor"])
        {
              case "BLK":
                   message("channel:chat", HIG"【窗外】"BLK + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "RED":
                   message("channel:chat", HIG"【窗外】"RED + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIR":
                   message("channel:chat", HIG"【窗外】"HIR + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "GRN":
                   message("channel:chat", HIG"【窗外】"GRN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIG":
                   message("channel:chat", HIG"【窗外】"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "YEL":
                   message("channel:chat", HIG"【窗外】"YEL + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIY":
                   message("channel:chat", HIG"【窗外】"HIY + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "BLU":
                   message("channel:chat", HIG"【窗外】"BLU + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIB":
                   message("channel:chat", HIG"【窗外】"HIB + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "MAG":
                   message("channel:chat", HIG"【窗外】"MAG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIM":
                   message("channel:chat", HIG"【窗外】"HIM + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "CYN":
                   message("channel:chat", HIG"【窗外】"CYN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIC":
                   message("channel:chat", HIG"【窗外】"HIC + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "WHT":
                   message("channel:chat", HIG"【窗外】"WHT + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIW":
                   message("channel:chat", HIG"【窗外】"HIW + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              default:
                   message("channel:chat", HIG"【窗外】"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
        }
//        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
            call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

        call_out("update_day_phase", day_phase[current_day_phase]["length"]);
    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
if(!ob->query_temp("hdjoblb")) continue;
if(!ob->query_temp("hdjobtg")) continue;
if(!environment(ob)) continue;
    j++;
    }
    if (j<38) call_out("give_gift", random(5)+1,"/clone/money/gold",1,"test");
}

void test_robot()
{
	object *obs = users(), ob, robot;
    int i = sizeof(obs), j = 10;

	if (i < 1) return;
	while (j--) {
		ob = obs[random(i)];
		if (wiz_level(ob)) continue;
		if (!living(ob)) continue;
		if (!interactive(ob)) continue;
                if (query_idle(ob) > 30) continue;
		if (!environment(ob)) continue;
		break;
	}
	if (j < 0) return;
	ppl = ob->query("id");
        if (!ob->is_fighting() 
        && interactive(ob) && living(ob)
        || ob->query("combat_exp")> 1000000 )
        ob->set_temp("testrobot",1);
        call_out("ok_robot", 1, ob);
}

void ok_robot(object ob)
{
if (ob)
{
ob->set_temp("testrobot",0);
ob->delete_temp("testrobot");
}
}

void event_morning()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"【朝廷急报】"HIR + "在扬州城中发现日本奸细！\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"【朝廷急报】"HIM + "在北京城中发现日本奸细！\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/city3/guangchang")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
 message("channel:chat", HIY"【朝廷急报】"HIM + "在成都城中发现日本奸细！\n"NOR,users() );
	}
        if (random(12) == 4)
        {
		if(objectp(room=load_object("/d/quanzhen/zhongxin")) && 
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
  message("channel:chat", HIB"【朝廷急报】"GRN + "在武功镇中发现金国奸细！\n"NOR,users() );
	}
        if (random(12) == 5)
        {
		if(objectp(room=load_object("/d/dali/taihejiekou")) && 
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("channel:chat", HIB"【朝廷急报】"GRN + "在大理城中发现金国奸细！\n"NOR,users() );
	}
        if (random(12) == 6)
        {
		if(objectp(room=load_object("/d/foshan/street3")) && 
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("channel:chat", HIB"【朝廷急报】"GRN + "在佛山镇中发现金国奸细！\n"NOR,users() );
	}
        if (random(12) == 7)
        {
		if(objectp(room=load_object("/d/fuzhou/dongjiekou")) && 
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
  message("channel:chat", HIG"【朝廷急报】"CYN + "在福州城中发现蒙古奸细！\n"NOR,users() );
	}
        if (random(12) == 8)
        {
		if(objectp(room=load_object("/d/hangzhou/road13")) && 
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
  message("channel:chat", HIG"【朝廷急报】"CYN + "在杭州城中中发现蒙古奸细！\n"NOR,users() );
	}
        if (random(12) == 9)
        {
		if(objectp(room=load_object("/d/lingzhou/center")) && 
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
  message("channel:chat", HIG"【朝廷急报】"CYN + "在灵州城中中发现蒙古奸细！\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && 
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"【朝廷急报】"BLU + "在泉州城中发现西夏奸细！\n"NOR,users() );
	}
        if (random(12) == 11)
        {
		if(objectp(room=load_object("/d/suzhou/baodaiqiao")) && 
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"【朝廷急报】"BLU + "在苏州城中发现西夏奸细！\n"NOR,users() );
	}
        if (random(12) == 12)
        {
		if(objectp(room=load_object("/d/xiangyang/guangchang")) && 
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"【朝廷急报】"BLU + "在襄阳城中发现西夏奸细！\n"NOR,users() );
	}
        if (random(16) == 1)
        {
		if(objectp(room=load_object("/d/huanghe/yongdeng")) && 
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                message("channel:chat", HIR"【前线告急】"HIW + "西夏大军攻打西北的军事重镇永登！\n"NOR,users() );
	}
        if (random(16) == 2)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
  message("channel:chat", HIR"【前线告急】"HIW + "倭寇大军在泉州附近登陆！杀我百姓!!\n"NOR,users() );
	}
        if (random(16) == 4)
        {
		if(objectp(room=load_object("/d/xiangyang/eastgate1")) && 
		objectp(badguy = new("/quest/weiguo/menggu/mengu3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
               message("channel:chat", HIR"【前线告急】"HIW + "蒙古大军进军事重镇襄阳！襄阳告急!!\n"NOR,users() );
	}
        if (random(16) == 7)
        {
		if(objectp(room=load_object("/d/city2/di_anmen.")) && 
		objectp(badguy = new("/quest/weiguo/jinbing/jin3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
  message("channel:chat", HIR"【前线告急】"HIW + "金国完颜氏的部队杀入了京城！京城告危!!\n"NOR,users() );
	}
}

void event_night()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "扬州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "北京城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/city3/guangchang")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "成都城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 4)
        {
		if(objectp(room=load_object("/d/quanzhen/zhongxin")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "武功镇中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 5)
        {
		if(objectp(room=load_object("/d/dali/taihejiekou")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "大理城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 6)
        {
		if(objectp(room=load_object("/d/foshan/street3")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "佛山城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 7)
        {
		if(objectp(room=load_object("/d/fuzhou/dongjiekou")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "福州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 8)
        {
		if(objectp(room=load_object("/d/hangzhou/road13")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "杭州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 9)
        {
		if(objectp(room=load_object("/d/lingzhou/center")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "灵州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "泉州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 11)
        {
		if(objectp(room=load_object("/d/suzhou/baodaiqiao")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "苏州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 12)
        {
		if(objectp(room=load_object("/d/xiangyang/guangchang")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "襄阳城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}

}

void event_afternoon()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/weiguo/japan/japan1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}

void event_dawn()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/feizei/feizei");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$N笑道：天亮了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}

void event_midnight()
{
        string get_month, get_day;
        get_day = CHINESE_D->chinese_monthday(TIME_TICK1);
        get_month = CHINESE_D->chinese_month(TIME_TICK1);
        switch(get_month)
        {
                //spring weather
                case "三":
                case "四":
                case "五":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/spring_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/spring_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/spring_wind");
                           break;
                     }
                     break;
                //summer weather
                case "六":
                case "七":
                case "八":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/summer_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/summer_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/summer_wind");
                           break;
                     }
                     break;
                //autumn weather
                case "九":
                case "十":
                case "十一":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/autumn_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/autumn_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/autumn_wind");
                           break;
                     }
                     break;
                //winter weather
                case "十二":
                case "一":
                case "二":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/winter_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/winter_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/winter_wind");
                           break;
                     }
                     break;
                default:
                     day_phase = read_table("/adm/etc/nature/day_phase");
        }
//        switch(get_day)
//        {
//                case "一月一日":
//                     day_phase = read_table("/adm/etc/nature/spring");
//                     break;
//                case "五月五日":
//                case "七月七日":
//                case "八月十五日":
//                case "九月九日":
//                case "十二月八日":
//        }
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
        object *ob;
        int i, skill,con,con1,con2,con3;
        string get_month,ill,msg;
        get_month = CHINESE_D->chinese_month(TIME_TICK1);
        switch(get_month)
        {
                case "三":
                case "四":
                case "五":
                     ill = "ill_kesou";
                     msg = HIG + "忽然喉头一阵痕痒，你感觉似乎要咳嗽了。\n" + NOR;
                     break;
                case "六":
                case "七":
                case "八":
                     ill = "ill_zhongshu";
                     msg = HIG+"突然你胸臆之间一阵翻腾，你中暑了。\n" + NOR;
                     break;
                case "九":
                case "十":
                case "十一":
                     ill = "ill_shanghan";
                     msg = HIG+"陡的你打了个冷战，头昏沉沉的，你得伤寒病了。\n"+NOR;
                     break;
                case "十二":
                case "一":
                case "二":
                     ill = "ill_dongshang";
                     msg = HIG+"你肢体末端一阵僵直，看来你被冻伤了。\n"+NOR;
                     break;
        }
        if(random(2))
        {
                ill = "ill_fashao";msg = HIG+"你偶感风寒，竟而发起烧来。\n"+NOR;
        }
        ob = users();
        for(i=0; i<sizeof(ob); i++)
        {
                if( !environment(ob[i]) ) continue;
                if( !environment(ob[i])->query("outdoors") ) continue;
                if( ob[i]->query("age")==14 ) continue;
                con1 = ob[i]->query("qi");
                con2 = ob[i]->query("max_qi");
                (int)con = con1/con2*50;//形成第一个生病判断条件
                con3 = ob[i]->query("neili");
                con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
                (int)con1 = con3/con2*50;//形成第二个生病判断条件
                if(random(con)+random(50)+random(con1)<25)
                {
                        ob[i]->apply_condition(ill, 10);
                        tell_object(ob[i], msg);
                }
        }
}

string outdoor_room_description()
{
	return "    " + sprintf(
		day_phase[current_day_phase]["desc_msg"],
		month_desc[current_month]) + "。\n";
}
string outdoor_room_outcolor()
{
        return day_phase[current_day_phase]["outcolor"];
}

string game_time()
{
        return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}

void give_gift(string gift, int amount, string msg)
{
        int i,combatexp,rd,j,num,factor,timep,sl;
        object ob;
        object env,room2;
        object *players;
        string room;
        string *dir2;
        string file;
string *roomlines;
string location,local,fname;
mapping quest,item,npc,quests;
mapping target;
string envn;
object newob, *ob_list;
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
                  });
tag = "10000";
if (random(2)==1) tag="15000";
if (random(3)==1) tag="20000";
if (random(4)==1) tag="30000";
if (random(5)==1) tag="50000";
if (random(6)==1) tag="80000";
if (random(7)==1) tag="100000";
if (random(8)==1) tag="130000";
if (random(9)==1) tag="170000";
if (random(10)==1)tag="220000";
if (random(11)==1)tag="300000";
if (random(12)==1)tag="450000";
if (random(13)==1)tag="600000";
if (random(14)==1)tag="800000";
if (random(15)==1)tag="1000000";
if (random(16)==1)tag="2000000";
        players = users();
        if (sizeof(players) >= 3)
        {
                for (i = 0; i < 3; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->query_temp("hdjoblb")) continue;
                        env = environment(ob);
                        if (!env) continue;
                        while (env && env->is_character())
                                env = environment(env);
                        if (env) break;
                        
                }
//                if (i >= 3) return;

                //if (objectp(env))
                //        tell_room(env, msg);
                //for (i = 0; i < amount; i++)
                //{
                //        ob = new(gift);
                //       ob->move(env);
                //}
if (objectp(env))
{
dir2=explode(base_name(env),"/");
room=zuji(dir2[1])+env->query("short");
combatexp = (int) (ob->query("combat_exp"));
rd=random(6);
//rd=5;
//CHANNEL_D->do_channel( this_object(), "rumor", "玩家互动任务:"+ob->name()+"种类"+rd+"。\n");

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             combatexp=combatexp/4;
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

if (rd==0)
{
        if (random(2) == 0 )
     quest = QUESTS_D(tag)->query_quest();
       else
     quest = QUESTH_D(tag)->query_quest();
        timep = quest["time"];
        if (!quest["time"]) timep=600;
        timep = timep+360;

if (quest["quest"])
{
ob->set_temp("hdjoblb","送货");
ob->set_temp("hdjobtg",quest["quest"]);
ob->set_temp("hdjobsc","送货:"+quest["quest_city"]+"的"+quest["quest"]);
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"有批货物要送到"+quest["quest_city"]+"的"+quest["quest"]+"手上。\n");
}
}

if (rd==4)
{

ob->set_temp("hdjoblb","互动");
ob->set_temp("hdjobtg","互动");
ob->set_temp("hdjobsc","玩家互动任务");
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"有个礼物要送给某个玩家。\n");

}

if (rd==5)
{
target=where[random(sizeof(where))];
room2=load_object(target["where"]+".c");
if (room2)
{
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;		
ob->set_temp("hdjoblb","江湖");
ob->set_temp("hdjoben",local);
ob->set_temp("hdjobtg",target["where"]+".c");
ob->set_temp("hdjobsc","有批黑道人物出现在"+target["party"]+"的"+room);
CHANNEL_D->do_channel( this_object(), "rumor", ob->query("name")+"听说有批黑道人物要进攻"+target["party"]+HIM"。\n");
}
}

}

if (rd==1)
{
quest = QUESTW_D(tag)->query_quest();	
        timep = quest["time"];
        if (!quest["time"]) timep=600;
        timep = timep+360;
        
if (quest["quest"])
{
ob->set_temp("hdjoblb","寻物");
ob->set_temp("hdjobtg",quest["quest"]);
ob->set_temp("hdjobsc","寻物:"+quest["quest_city"]+"的"+quest["quest"]);
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"想要找到"+quest["quest_city"]+"的"+quest["quest"]+"。\n");
}
}
if (rd==2)
{
seteuid(geteuid(this_object()));	
file = read_file("/clone/medicine/dynamic_location");
	if (ob->query("combat_exp",1)<=2000000)
	file = read_file("/clone/medicine/dynamic_location1");
	else if (ob->query("combat_exp",1)<=4000000)
	file = read_file("/clone/medicine/dynamic_location2");
	else if (ob->query("combat_exp",1)<=6000000)
	file = read_file("/clone/medicine/dynamic_location3");
else if (ob->query("combat_exp",1)<=8000000)
	file = read_file("/clone/medicine/dynamic_location4");
else if (ob->query("combat_exp",1)>8000000)
	file = read_file("/clone/medicine/dynamic_location5");
if (!file)
	file = read_file("/clone/medicine/dynamic_location");

roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
//ob->apply_condition("roomjob",10);
//ob->set_temp("roomjob",local);
ob->set_temp("hdjoblb","刺探");
ob->set_temp("hdjobtg",local);
ob->set_temp("hdjobsc","刺探:"+room);
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"想要得到"+room+"的情报。\n");
//tell_object(ob,"任务:到"+room+"去刺探一下情况(citan)。\n" NOR);
//CHANNEL_D->do_channel( this_object(), "rumor", "任务3。\n");
//CHANNEL_D->do_channel( this_object(), "rumor", "任务3:到"+room+"去刺探一下情况(citan)。\n");
//	  tell_object(ob,HIC"任务使说:我听说在『"HIR+room+HIC"』，发生了一些江湖事件。"+
//           "你赶快去『"HIR+local+HIC"』刺探(citan)一下吧。\n"NOR);
//if (wizardp(ob))
//	  tell_object(ob,GRN"WIZ信息:刺探位置『"YEL+fname+GRN"』。\n"NOR);
}

if (rd==3)
{
seteuid(geteuid(this_object()));	
file = read_file("/clone/medicine/dynamic_location");
	if (ob->query("combat_exp",1)<=2000000)
	file = read_file("/clone/medicine/dynamic_location1");
	else if (ob->query("combat_exp",1)<=4000000)
	file = read_file("/clone/medicine/dynamic_location2");
	else if (ob->query("combat_exp",1)<=6000000)
	file = read_file("/clone/medicine/dynamic_location3");
else if (ob->query("combat_exp",1)<=8000000)
	file = read_file("/clone/medicine/dynamic_location4");
else if (ob->query("combat_exp",1)>8000000)
	file = read_file("/clone/medicine/dynamic_location5");
if (!file)
	file = read_file("/clone/medicine/dynamic_location");

roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
//ob->apply_condition("roomjob",10);
//ob->set_temp("roomjob",local);
ob->set_temp("hdjoblb","仇杀");
ob->set_temp("hdjobtg",location);
ob->set_temp("hdjobsc","仇杀:"+room);
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"有一个仇敌在"+room+"附近出现。\n");
}
}
sl=random(3);
if (sl==0)
{
   ob_list = users();
    newob = ob_list[random(sizeof(ob_list))];
if(newob->query("combat_exp",1)<100000 || !newob->query_temp("hdjob2tg") || !newob->query_temp("nhdjob2tg")) newob = ob_list[random(sizeof(ob_list))];
if(newob->query("combat_exp",1)<100000 || !newob->query_temp("hdjob2tg") || !newob->query_temp("nhdjob2tg")) newob = ob_list[random(sizeof(ob_list))];
if(newob->query("combat_exp",1)<100000 || !newob->query_temp("hdjob2tg") || !newob->query_temp("nhdjob2tg")) newob = ob_list[random(sizeof(ob_list))];

if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];

if (newob)
{
env=environment(newob);
if (env)
{
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
}
if (newob && envn)
{
newob->set_temp("hdjoblb","挑战");
newob->set_temp("hdjobtg",newob->query("id"));
newob->set_temp("hdjobsc","挑战"+newob->name());
CHANNEL_D->do_channel( this_object(), "rumor", "听说:有人悬赏挑战在"+envn+"附近的:"+newob->name()+"。\n");
}
}
}

if (sl==1)
{
quest = QUESTS_D(tag)->query_quest();
if (random(2) == 0 ) quest = QUESTH_D(tag)->query_quest();	
if (quest["quest"])
{
   ob_list = users();
    newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if (newob)
{
env=environment(newob);
if (env)
{
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
}
if (newob && envn && newob->query("age",1)>=20)
{
newob->set_temp("ishm",0);
newob->delete_temp("ishm");
newob->set_temp("hdjoblb","会面");
newob->set_temp("hdjobtg",quest["quest"]);
newob->set_temp("hdjobsc","会面:"+quest["quest_city"]+"的"+quest["quest"]+"想见一下"+newob->name()+"。");
CHANNEL_D->do_channel( this_object(), "rumor", "听说"+quest["quest_city"]+"的"+quest["quest"]+"想见一下"+newob->name()+"。\n");
}
}
}
}

if (random(8)==6)
{

seteuid(geteuid(this_object()));	
file = read_file("/clone/medicine/map1");	
if (random(2)==0) file = read_file("/clone/medicine/map4");

if (!file)
	file = read_file("/clone/medicine/map1");

roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/map1");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
ob->set_temp("hdjoblb","悬赏");
ob->set_temp("hdjobtg",local);
ob->set_temp("hdjobsc","悬赏:有个恶贼出现在"+room);
CHANNEL_D->do_channel( this_object(), "rumor", ob->name()+"听说有个悬赏追杀的恶贼出现在"+room+"附近。\n");

}	
}	

        }
}



string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="白驼山的";

if (str=="binghuodao")  

	output="冰火岛的";

if (str=="city")  

	output="扬州的";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="北京城的";

if (str=="city4" || str=="changan")   

	output="长安城的";

if (str=="dali")  

	output="大理的";

if (str=="emei")  

	output="娥眉山的";

if (str=="foshan")  

	output="佛山的";

if (str=="gaibang")  

	output="丐帮的";

if (str=="gaochang")  

	output="高昌迷宫的";

if (str=="guanwai")  

	output="关外的";

if (str=="guiyun")  

	output="归云庄的";

if (str=="gumu")  

	output="古墓派的";

if (str=="hangzhou")  

	output="杭州的";

if (str=="heimuya")  

	output="黑木崖的";

if (str=="hengshan")  

	output="恒山的";

if (str=="henshan")  

	output="衡山的";

if (str=="huanghe")  

	output="黄河九曲的";

if (str=="huashan")  

	output="华山的";

if (str=="jinshe")  

	output="金蛇山洞的";

if (str=="lingjiu")  

	output="灵鹫宫的";

if (str=="lingzhou")  

	output="灵州的";

if (str=="meizhuang")  

	output="梅庄的";

if (str=="mingjiao")  

	output="明教的";

if (str=="qingcheng")  

	output="青城山的";

if (str=="quanzhen")  

	output="全真派的";

if (str=="quanzhou")  

	output="泉州的";

if (str=="shaolin")  

	output="少林寺的";

if (str=="shenlong")  

	output="神龙岛的";

if (str=="songshan")  

	output="嵩山的";

if (str=="suzhou")  

	output="苏州的";

if (str=="taishan")  

	output="泰山的";

if (str=="taohua")  

	output="桃花岛的";

if (str=="tianlongsi")  

	output="天龙寺的";

if (str=="wanjiegu")  

	output="万劫谷的";

if (str=="wudang")  

	output="武当山的";

if (str=="xiakedao")  

	output="侠客岛的";

if (str=="xiangyang")  

	output="襄阳城的";

if (str=="xiaoyao")  

	output="逍遥林的";

if (str=="xingxiu")  

	output="星宿海的";

if (str=="xueshan")  

	output="雪山寺的";

if (str=="xuedao")  

	output="大雪山的";

if (str=="mr")  

	output="慕容世家的";

if (str=="kunlun")  

	output="昆仑山的";

if (str=="tiezhang")  

	output="铁掌门的";

if (str=="huizhu")  

	output="回族部落的";

if (str=="yinju")  

	output="一灯大师居的";

if (str=="menggu")  

	output="蒙古草原的";

if (str=="qianjin")  

	output="北京千金楼的";

if (str=="lingshedao")  

	output="灵蛇岛的";

if (str=="ruzhou")  

	output="汝州城的";

if (str=="kunming")  

	output="昆明的";

if (str=="jingzhou")  

	output="荆州的";

if (str=="yanjing")  

	output="盛京的";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="兰州的";

if (str=="jyguan")  

	output="兰州以北嘉峪关的";

if (str=="changcheng")  

	output="北京以北长城的";

if (str=="fairyland")  

	output="昆仑的红梅山庄";

if (str=="sdxl")  

	output="剑魔独孤求败墓";

if (str=="jqg")  

	output="绝情谷";

if (str=="nio")  

	output="牛家村的";

if (str=="feihu")  

	output="闯王宝藏的";

if (str=="wuguan")  

	output="襄阳武馆的";

if (str=="village")  

	output="华山村的";

if (str=="taohuacun")  

	output="桃花村的";

if (str=="pingan")  

	output="平安城的";

if (str=="lingxiao")  

	output="凌霄城的";

if (str=="wudujiao")  

	output="五毒教的";

if (str=="hj")  

	output="天山。草原的";
if (str=="dali/yuxu")  

	output="大理玉虚观的";
if (str=="dali/wuliang")  

	output="大理无量山的";
if (str=="huanghe/yyd")  

	output="黄河萧府的";
if (str=="kaifeng")  

	output="开封城的";
if (str=="feitian")  

	output="飞天御剑流的";
if (str=="japan")  

	output="日本神户的";
if (str=="tangmen")  

	output="唐门的";
if (str=="luoyang")  

	output="洛阳城的";

if (str=="chengdu" || str=="city3")  

	output="成都的";

if (str=="baihuagu")  

	output="百花谷的";

if (str=="heizhao")  

	output="百花谷黑沼的";

if (str=="jiaxing")  

	output="嘉兴的";

if (str=="shiliang")  

	output="温家庄的";

if (str=="wuyi")  

	output="武夷山区的";

if (str=="yanping")  

	output="延平城的";
	

if (str=="jiangling")  
{
	output="江陵城的";
}

if (str=="yueyang")  
{
	output="岳阳城的";	
}

if (str=="qilian")  
{
	output="祁连山的";	
}

if (str=="shouxihu")  
{
	output="瘦西湖的";	
}

if (str=="wuxi")  
{
	output="无锡城的";	
}

if (str=="yixing")  
{
	output="宜兴城的";	
}
if (str=="taiwan")  
{
	output="台湾的";	
}
if (str=="nanyang")  
{
	output="南阳的";	
}
if (str=="nanshaolin")  
{
	output="南少林的";	
}

if (str=="cangzhou")  
{
	output="沧州的";	
}

if (str=="tanggu")  
{
	output="塘沽城的";	
}

if (str=="yunhe")  
{
	output="京杭运河的";	
}

if (str=="hainan")  
{
	output="海南岛的";	
}

if (str=="jindezheng")  
{
	output="景德镇的";	
}

if (str=="yandang")  
{
	output="雁荡山的";	
}

if (str=="jinling")  
{
	output="金陵城的";	
}

if (str=="sandboy")  
{
	output="江南农村的";	
}

if (str=="huangshan")  
{
	output="黄山的";	
}

if (str=="yubifeng")  
{
	output="玉笔峰的";	
}

if (str=="quanzhouchen")  
{
	output="泉州城内的";	
}

if (str=="qingzh")  
{
	output="青藏高原";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="高丽 长白山的";	
}

if (str=="annan")  
{
	output="安南附近的";	
}

if (str=="taiyuan")  
{
	output="太原附近的";	
}

if (str=="hefei")  
{
	output="合肥附近的";	
}

if (str=="jiujiang")  
{
	output="九江附近的";	
}

if (str=="baling")  
{
	output="巴陵附近的";	
}

if (str=="xinjiang")  
{
	output="新疆附近的";	
}
if (str=="dingxiang")  
{
	output="定襄附近的";	
}
if (str=="suiye")  
{
	output="碎叶附近的";	
}


if (str=="mayi")  
{
	output="马邑边疆附近的";	
}
if (str=="xuzhou")  
{
	output="徐州城附近的";	
}
if (str=="jinan")  
{
	output="济南城附近的";	
}
if (str=="guizhou")  
{
	output="贵阳城附近的";	
}

if (str=="nanchang")  
{
	output="南昌城附近的";	
}


if (str=="changsha")  
{
	output="长沙城附近的";	
}


if (str=="zhongzhou")  
{
	output="中州城附近的";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="西藏或藏北附近的";	
}

if (str=="tianshui")  
{
	output="天水城附近的";	
}

if (str=="datong")  
{
	output="大同府附近的";	
}
if (str=="ny")  
{
	output="宁远城附近的";	
}
if (str=="fengtian")  
{
	output="盛京城附近的";	
}

if (str=="yanmen")  
{
	output="燕门关附近的";	
}
if (str=="cloud")  
{
	output="绮云镇附近的";	
}
if (str=="xueting")  
{
	output="雪亭镇附近的";	
}
if (str=="welcome")  
{
	output="古村附近的";	
}
if (!output)  
{
	output="未知区域的";	
}

if (output=="")  
{
	output="未知区域的";	
}


return output;
}



mapping *query_day_phase() { return day_phase; }

