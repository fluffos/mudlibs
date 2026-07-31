// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <localtime.h>
#include <mudlib.h>
#include <command.h>

inherit F_DBASE;

#define MIN             0
#define HOUR            1
#define WDAY            2
#define MDAY            3
#define MON             4
#define YEAR            5

#define DATA_PATH       "/data/timed.o"
#define MAZE_DOOR1      "/clone/misc/maze_door1"

#define VRM00      "vrm00"
#define VRM01      "vrm01"
#define VRM02      "vrm02"
#define VRM03      "vrm03"
#define VRM04      "vrm04"
#define VRM05      "vrm05"
#define VRM06      "vrm06"
#define VRM07      "vrm07"
#define VRM08      "vrm08"
#define VRM09      "vrm09"
#define VRM10      "vrm10"
#define VRM11      "vrm11"

int gametime;
static int realtime;
static int tick;
static mapping event = allocate_mapping(0);
static int *real_time = allocate(6);
static int *game_time = allocate(6);

string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="白驼山";

if (str=="binghuodao")  

	output="冰火岛";

if (str=="city")  

	output="扬州";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="北京城";

if (str=="city4" || str=="changan")   

	output="长安城";

if (str=="dali")  

	output="大理";

if (str=="emei")  

	output="娥眉山";

if (str=="foshan")  

	output="佛山";

if (str=="gaibang")  

	output="丐帮";

if (str=="gaochang")  

	output="高昌迷宫";

if (str=="guanwai")  

	output="关外";

if (str=="guiyun")  

	output="归云庄";

if (str=="gumu")  

	output="古墓派";

if (str=="hangzhou")  

	output="杭州";

if (str=="heimuya")  

	output="黑木崖";

if (str=="hengshan")  

	output="恒山";

if (str=="henshan")  

	output="衡山";

if (str=="huanghe")  

	output="黄河九曲";

if (str=="huashan")  

	output="华山";

if (str=="jinshe")  

	output="金蛇山洞";

if (str=="lingjiu")  

	output="灵鹫宫";

if (str=="lingzhou")  

	output="灵州";

if (str=="meizhuang")  

	output="梅庄";

if (str=="mingjiao")  

	output="明教";

if (str=="qingcheng")  

	output="青城山";

if (str=="quanzhen")  

	output="全真派";

if (str=="quanzhou")  

	output="泉州";

if (str=="shaolin")  

	output="少林寺";

if (str=="shenlong")  

	output="神龙岛";

if (str=="songshan")  

	output="嵩山";

if (str=="suzhou")  

	output="苏州";

if (str=="taishan")  

	output="泰山";

if (str=="taohua")  

	output="桃花岛";

if (str=="tianlongsi")  

	output="天龙寺";

if (str=="wanjiegu")  

	output="万劫谷";

if (str=="wudang")  

	output="武当山";

if (str=="xiakedao")  

	output="侠客岛";

if (str=="xiangyang")  

	output="襄阳城";

if (str=="xiaoyao")  

	output="逍遥林";

if (str=="xingxiu")  

	output="星宿海";

if (str=="xueshan")  

	output="雪山寺";

if (str=="xuedao")  

	output="大雪山";

if (str=="mr")  

	output="慕容世家";

if (str=="kunlun")  

	output="昆仑山";

if (str=="tiezhang")  

	output="铁掌门";

if (str=="huizhu")  

	output="回族部落";

if (str=="yinju")  

	output="一灯大师居";

if (str=="menggu")  

	output="蒙古草原";

if (str=="qianjin")  

	output="北京千金楼";

if (str=="lingshedao")  

	output="灵蛇岛";

if (str=="ruzhou")  

	output="汝州城";

if (str=="kunming")  

	output="昆明";

if (str=="jingzhou")  

	output="荆州";

if (str=="yanjing")  

	output="燕京";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="兰州";

if (str=="jyguan")  

	output="兰州以北嘉峪关";

if (str=="changcheng")  

	output="北京以北长城";

if (str=="fairyland")  

	output="昆仑的红梅山庄";

if (str=="sdxl")  

	output="剑魔独孤求败墓";

if (str=="jqg")  

	output="绝情谷";

if (str=="nio")  

	output="牛家村";

if (str=="feihu")  

	output="闯王宝藏";

if (str=="wuguan")  

	output="襄阳武馆";

if (str=="village")  

	output="华山村";

if (str=="taohuacun")  

	output="桃花村";

if (str=="pingan")  

	output="平安城";

if (str=="lingxiao")  

	output="凌霄城";

if (str=="wudujiao")  

	output="五毒教";

if (str=="hj")  

	output="天山。草原";
if (str=="dali/yuxu")  

	output="大理玉虚观";
if (str=="dali/wuliang")  

	output="大理无量山";
if (str=="huanghe/yyd")  

	output="黄河萧府";
if (str=="kaifeng")  

	output="开封城";
if (str=="feitian")  

	output="飞天御剑流";
if (str=="japan")  

	output="日本神户";
if (str=="tangmen")  

	output="唐门";
if (str=="luoyang")  

	output="洛阳城";

if (str=="chengdu" || str=="city3")  

	output="成都";

if (str=="baihuagu")  

	output="百花谷";

if (str=="heizhao")  

	output="百花谷。黑沼";

if (str=="jiaxing")  

	output="嘉兴";

if (str=="shiliang")  

	output="温家庄";

if (str=="wuyi")  

	output="武夷山区";

if (str=="yanping")  

	output="延平城";
	

if (str=="jiangling")  
{
	output="江陵城";
}

if (str=="yueyang")  
{
	output="岳阳城";	
}

if (str=="qilian")  
{
	output="祁连山";	
}

if (str=="shouxihu")  
{
	output="瘦西湖";	
}

if (str=="wuxi")  
{
	output="无锡城";	
}

if (str=="yixing")  
{
	output="宜兴城";	
}
if (str=="taiwan")  
{
	output="台湾地区";	
}
if (str=="nanyang")  
{
	output="南阳地区";	
}
if (str=="nanshaolin")  
{
	output="南少林地区";	
}

if (str=="cangzhou")  
{
	output="沧州地区";	
}

if (str=="tanggu")  
{
	output="塘沽城地区";	
}

if (str=="yunhe")  
{
	output="京杭大运河";	
}

if (str=="hainan")  
{
	output="海南岛";	
}

if (str=="jindezheng")  
{
	output="景德镇";	
}

if (str=="yandang")  
{
	output="雁荡山";	
}

if (str=="jinling")  
{
	output="金陵城";	
}

if (str=="sandboy")  
{
	output="江南农村";	
}

if (str=="huangshan")  
{
	output="黄山";	
}

if (str=="yubifeng")  
{
	output="玉笔峰";	
}

if (str=="quanzhouchen")  
{
	output="泉州城内";	
}

if (str=="qingzh")  
{
	output="青藏高原";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="高丽 长白山";	
}

if (str=="annan")  
{
	output="安南附近";	
}

if (str=="taiyuan")  
{
	output="太原附近";	
}

if (str=="hefei")  
{
	output="合肥附近";	
}

if (str=="jiujiang")  
{
	output="九江附近";	
}

if (str=="baling")  
{
	output="巴陵附近";	
}

if (str=="xinjiang")  
{
	output="新疆附近";	
}
if (str=="dingxiang")  
{
	output="定襄附近";	
}
if (str=="suiye")  
{
	output="碎叶附近";	
}


if (str=="mayi")  
{
	output="马邑边疆附近";	
}
if (str=="xuzhou")  
{
	output="徐州城附近";	
}
if (str=="jinan")  
{
	output="济南城附近";	
}
if (str=="guizhou")  
{
	output="贵阳城附近";	
}

if (str=="nanchang")  
{
	output="南昌城附近";	
}


if (str=="changsha")  
{
	output="长沙城附近";	
}


if (str=="zhongzhou")  
{
	output="中州城附近";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="西藏或藏北附近";	
}

return output;
}

    object get_object(string name) 
    { 
            object ob; 
            
            if (ob = find_object(name)) 
                    return ob; 
                     
           sscanf(name, "%s#%*s", name);  
            return load_object(name); 
     } 

static mapping vrm_name_list = ([
        "vrm00"  : "原始森林",
        "vrm01"  : "海底迷宫",
        "vrm02"  : "天之尽头",
        "vrm03"  : "苍之风云",
        "vrm04"  : "忘忧之园",
        "vrm05"  : "火龙之窟",
        "vrm06"  : "迷雾森林",
        "vrm07"  : "百花之谷",
        "vrm08"  : "回音山谷",
        "vrm09"  : "九天雷云",
        "vrm10"  : "无底溶洞",        	        	        	        	        	        	        	
        "vrm11"  : "万蛇魔洞",        	        	        	        	        	        	        	        	
]);

void auto_relaim()
{
        int i;
        if (i = reclaim_objects())
                CHANNEL_D->do_channel( this_object(), "sys",
                        sprintf("系统自动清除 %d 个变量。", i));
}

void game_new_year()
{
        shout( WHT "\n" + CHINESE_MUD_NAME + CHINESE_D->chinese_number(game_time[YEAR]) + "年终于来到，举世欢腾！！！\n" NOR);
}

void real_new_year()
{
        shout( WHT"\n西元" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"年终于来到，举世欢腾！！！\n"NOR);
        shout( WHT"\n西元" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"年终于来到，举世欢腾！！！\n"NOR);
        shout( WHT"\n西元" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"年终于来到，举世欢腾！！！\n"NOR);
}

void broadcast_message()
{
        shout(HIW "【系统提示】加入会员享受更多的会员服务(help member)，详情请查看帮助文件！！！\n" NOR);
        shout(HIW "【系统提示】目前游戏是删档内测，玩家在论坛发布功略请注明游戏ID！\n"
              HIW "            发贴获得玩家认可可获得风云币 http://www.nbyingqi.com.cn\n" NOR);
}

void double_reward_start()
{
        //shout(BEEP BLINK HIR"【会员通告】现在的时间为 20 点，系统开放会员双倍奖励时间开始！！！\n"NOR);
}

void double_reward_end()
{
        //shout(BEEP BLINK HIR"【会员通告】现在的时间为 24 点，系统开放会员双倍奖励时间结束！！！\n"NOR);
}





void create_vrm_entry(string arg)
{
        object room, maze_door;
        string filename;
        string rooms;
string *dir2;        
        switch( arg )
        {
        case VRM00 :    
                filename = "/d/kunming/nanmen";  
                room = get_object(filename);          
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0000/entry");
                maze_door->move(room);
                break;

        case VRM01 :    
                filename = "/d/xiakedao/wangyun";  
                room = get_object(filename);          
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0001/entry");
                maze_door->move(room);
                break;
        case VRM02 :
                filename = "/d/guanwai/tianchi1";  
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0002/entry");
                maze_door->move(room);
                break;
        case VRM03 :
                filename = "/d/xueshan/hubian3";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0003/entry");
                maze_door->move(room);
                break;
        case VRM04 :
                filename = "/d/taiwan/riyuetan";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0004/entry");
                maze_door->move(room);
                break;
        case VRM05 :
                filename = "/d/qingcheng/path1";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0005/entry");
                maze_door->move(room);
                break;
        case VRM06 :
                filename = "/d/hengshan/daziling";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0006/entry");
                maze_door->move(room);
                break;
        case VRM07 :
                filename = "/d/xiangyang/caodi5";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0007/entry");
                maze_door->move(room);
                break;
        case VRM08 :
                filename = "/d/emei/yunufeng";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0008/entry");
                maze_door->move(room);
                break;
        case VRM09 :
                filename = "/d/songshan/fengchantai";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0009/entry");
                maze_door->move(room);
                break;
        case VRM10 :
                filename = "/d/dali/yuxiashan";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0010/entry");
                maze_door->move(room);
                break;
        case VRM11 :
                filename = "/d/xizang/timetree";
                room = get_object(filename); 
                maze_door = new(MAZE_DOOR1);
                maze_door->set("maze_entry", "/p/migong/boss/vrm_0011/entry");
                maze_door->move(room);
                break;
                                                                                                                                               
        default:
                return;
        }


dir2=explode(base_name(room),"/");
rooms=zuji(dir2[1]);
log_file("log", ctime(time())+" 生成迷宫：" + arg +"\n", 1);        


        
        message("vision", HIG "【" HIR "江湖传言" HIG "】" HIW +
                room->query("short") + HIW "(" + rooms + 
                ")一带出现了" + vrm_name_list[arg] + HIW "。\n" NOR, users());
        
        SCHEDULE_D->set_event(3600, 0, this_object(), "close_vrm_entry", arg, room, maze_door);
}

void close_vrm_entry(string arg, object room, object maze_door)
{
        string rooms;
string *dir2; 
        if ( !room || !maze_door ) return;
        
        destruct(maze_door);
    dir2=explode(base_name(room),"/");
rooms=zuji(dir2[1]);
        message("vision", HIG"【" HIR"江湖传言" HIG"】" HIW +
                room->query("short") + HIW "(" + rooms+ ")一带出现的" + 
                vrm_name_list[arg] + HIW "消失了。\n" NOR, users());
}

// 游戏时间的工作排程
static mixed  game_crontab = ({
//"min hour wday mday mon year" : ({ function })
"0 0 * 0 0 *"           , (: game_new_year :),                  "每年发一次红包",
});

// 真实时间的工作排程
static mixed  real_crontab = ({
"0 0 * 0 0 *"           , (: real_new_year :),                  "真实时间过年",
"* * * * * *"           , (: SCHEDULE_D->start_events() :),     "每分钟检测排程心跳情况",
"1 */2 * * * *"         , (: create_vrm_entry(VRM00) :),  "每 2 个小时刷新一次",
"5 */2 * * * *"         , (: create_vrm_entry(VRM01) :),   "每 2 个小时刷新一次",
"9 */3 * * * *"         , (: create_vrm_entry(VRM02) :),   "每 3 个小时刷新一次",
"15 */3 * * * *"         , (: create_vrm_entry(VRM03) :),   "每 3 个小时刷新一次",
"20 */4 * * * *"         , (: create_vrm_entry(VRM04) :),   "每 4 个小时刷新一次",
"25 */4 * * * *"         , (: create_vrm_entry(VRM05) :),   "每 4 个小时刷新一次",
"30 */5 * * * *"         , (: create_vrm_entry(VRM06) :),   "每 5 个小时刷新一次",
"35 */5 * * * *"         , (: create_vrm_entry(VRM07) :),   "每 5 个小时刷新一次",
"35 */6 * * * *"         , (: create_vrm_entry(VRM08) :),   "每 6 个小时刷新一次",
"45 */6 * * * *"         , (: create_vrm_entry(VRM09) :),   "每 6 个小时刷新一次",						
"50 */7 * * * *"         , (: create_vrm_entry(VRM10) :),   "每 7 个小时刷新一次",						
"55 */7 * * * *"         , (: create_vrm_entry(VRM11) :),   "每 7 个小时刷新一次",						
			
});

// 可取代 call_out 之功能
void add_event(function fevent, int delay_time)
{
        if( !sizeof(event) || !event[fevent] )
                event = ([ fevent : delay_time ]);
        else
                event[fevent] = delay_time;
}

// 执行事件
void exec_event(function fevent)
{
        if( objectp(function_owner(fevent)) )
                evaluate(fevent);

        map_delete(event, fevent);
}

string replace_ctime(int t)
{
        string month, ctime = ctime(t);

        switch(ctime[4..6])
        {
                case "Jan"      :       month = "01";break;
                case "Feb"      :       month = "02";break;
                case "Mar"      :       month = "03";break;
                case "Apr"      :       month = "04";break;
                case "May"      :       month = "05";break;
                case "Jun"      :       month = "06";break;
                case "Jul"      :       month = "07";break;
                case "Aug"      :       month = "08";break;
                case "Sep"      :       month = "09";break;
                case "Oct"      :       month = "10";break;
                case "Nov"      :       month = "11";break;
                case "Dec"      :       month = "12";break;
        }

        return sprintf("%s/%s/%s %s", month, (ctime[8]==' '?"0"+ctime[9..9]:ctime[8..9]), ctime[<4..<1], ctime[11..15]);
}

string season_period(int m)
{
        switch(m)
        {
                case 2..4:      return "春";
                case 5..7:      return "夏";
                case 8..10:     return "秋";
                case 11:        return "冬";
                case 0..1:      return "冬";
                default:        return 0;
        }
}

string week_period(int w)
{
        switch(w)
        {
                case 0:         return "日";
                case 1:         return "一";
                case 2:         return "二";
                case 3:         return "三";
                case 4:         return "四";
                case 5:         return "五";
                case 6:         return "六";
                default:        return 0;
        }
}

string hour_period(int h)
{
        switch(h)
        {
                case 0..5:      return "凌晨";
                case 6..11:     return "上午";
                case 12:        return "中午";
                case 13..18:    return "下午";
                case 19..23:    return "晚上";
                default:        return 0;
        }
}

/* 回传时间阵列 ({ 分 时 礼 日 月 年 }) */
int *query_gametime_array()
{
        return game_time;
}

int *query_realtime_array()
{
        return real_time;
}

/* 回传数位时间表示 下午 3:39 */
string gametime_digital_clock()
{
        int h = game_time[HOUR];
        int m = game_time[MIN];

        return hour_period(h)+" "+(h==12 || (h%=12)>9?""+h:" "+h)+":"+(m>9?""+m:"0"+m);
}
string realtime_digital_clock()
{
        int h = real_time[HOUR];
        int m = real_time[MIN];

        return hour_period(h)+" "+(h==12 || (h%=12)>9?""+h:" "+h)+":"+(m>9?""+m:"0"+m);
}

string time_description(string title, int *t)
{
        return sprintf( NOR WHT+title+NOR"%s年，%s，%s月%s日星期%s，%s%s点%s分"NOR
            ,t[YEAR]==1?"元":CHINESE_D->chinese_number(t[YEAR])
            ,season_period(t[MON])
            ,!t[MON]?"元":CHINESE_D->chinese_number(t[MON]+1)
            ,CHINESE_D->chinese_number(t[MDAY]+1)
            ,week_period(t[WDAY])
            ,hour_period(t[HOUR])
            ,CHINESE_D->chinese_number(t[HOUR] > 12 ? t[HOUR]%12 : t[HOUR])
            ,CHINESE_D->chinese_number(t[MIN])
        );
}

string game_time_description()
{
        return time_description(CHINESE_MUD_NAME, game_time);
}

string real_time_description()
{
        return time_description("公元", real_time);
}

int query_game_time()
{
        return gametime*60;
}

int query_real_time()
{
        return realtime;
}

int *analyse_time(int t)
{
        int *ret = allocate(6);
        string ctime;

        ctime = ctime(t);

        sscanf(ctime,"%*s %*s %d %d:%d:%*d %d",ret[MDAY], ret[HOUR], ret[MIN], ret[YEAR]);

        switch(ctime[0..2])
        {
                case "Sun": ret[WDAY] = 0; break;
                case "Mon": ret[WDAY] = 1; break;
                case "Tue": ret[WDAY] = 2; break;
                case "Wed": ret[WDAY] = 3; break;
                case "Thu": ret[WDAY] = 4; break;
                case "Fri": ret[WDAY] = 5; break;
                case "Sat": ret[WDAY] = 6; break;
                default   : return 0;
        }

        switch(ctime[4..6])
        {
                case "Jan": ret[MON] = 0; break;
                case "Feb": ret[MON] = 1; break;
                case "Mar": ret[MON] = 2; break;
                case "Apr": ret[MON] = 3; break;
                case "May": ret[MON] = 4; break;
                case "Jun": ret[MON] = 5; break;
                case "Jul": ret[MON] = 6; break;
                case "Aug": ret[MON] = 7; break;
                case "Sep": ret[MON] = 8; break;
                case "Oct": ret[MON] = 9; break;
                case "Nov": ret[MON] = 10; break;
                case "Dec": ret[MON] = 11; break;
                default   : return 0;
        }
        ret[MDAY] -= 1;
        return ret;
}

void process_crontab(mixed * crontab, int *timearray)
{
        int i, j, row, divider, fit, timecost, crontabsize;
        string s, script, note, *timescript;
        function fp;

        crontabsize = sizeof(crontab);

        for(row=0;row<crontabsize;row+=3)
        {
                reset_eval_cost();
                script = crontab[row];
                fp = crontab[row+1];
                note = crontab[row+2];

                timescript = allocate(6);

                // %s%*(( |\t)+) 的意思是 %s(空格 or \t 跳过)接著 + 可以相配一串一个以上符合的单元
                if( sscanf(script, "%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s",
                        timescript[0],
                        timescript[1],
                        timescript[2],
                        timescript[3],
                        timescript[4],
                        timescript[5]) != 11 ) continue;

                for( i=0;i<6;i++ )
                {
                        fit = 0;

                        foreach(s in explode(timescript[i], ","))
                        {
                                j = to_int(s);

                                // 不同的mudos的undefinedp函数返回的值有区别
                                if( s == "*" || (sscanf(s, "*/%d", divider) && !(timearray[i]%divider)) )
                                {
                                        fit = 1;
                                        break;
                                }
                                else if( !undefinedp(j) )
                                {
                                        if( j == timearray[i] )
                                        {
                                                fit = 1;
                                                break;
                                        }
                                }
                        }

                        if( !fit ) break;
                }

                if( !fit )
                        continue;

                timecost = time_expression {
                        catch(evaluate(fp));
                };

                if( timecost > 1000000 )
                        CHANNEL_D->do_channel(this_object(), "sys",
                                sprintf("TIME_D: crontab '%s'(%.6f sec) %s", script, timecost/1000000., note));

        }
}

// 独立出来每秒执行函式
void process_per_second()
{

}

void reset_gametime()
{
        gametime = -20000000;
}

/* 游戏时间每一分钟(即实际时间每2.5秒)执行一次 process_gametime */
void process_gametime()
{
        game_time = analyse_time(++gametime * 60);
        game_time[YEAR] -= 1970;

        process_crontab(game_crontab, game_time);
}

/* 真实时间每一秒钟执行一次 process_realtime */
void process_realtime()
{
        mixed * localtime = localtime(realtime);

        real_time = ({
                localtime[LT_MIN],
                localtime[LT_HOUR],
                localtime[LT_WDAY],
                localtime[LT_MDAY]-1,
                localtime[LT_MON],
                localtime[LT_YEAR] });
        
        // 每秒执行函式
        process_per_second();

        //if( !localtime[LT_SEC] )
        //        process_crontab(real_crontab, real_time);
}

// 每 1 秒运算一次
// 实际一天等于游戏一月

void heart_beat()
{
        realtime = time();

        // 执行 event 处理
        if( sizeof(event) )
        foreach( function fevent, int delay_time in event )
                if( !--event[fevent] )
                        exec_event(fevent);

        // 每 2 秒相当于游戏一分钟, time 每增加 1 代表游戏一分钟
        if( !(++tick % 2) )
                process_gametime();

        process_realtime();
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "时间精灵");
        write("时间精灵已经启动。\n");
        if( !restore_object(DATA_PATH) )
                save_object(DATA_PATH);

        game_time = allocate(6);
        real_time = allocate(6);
        event = allocate_mapping(0);

        process_gametime();
/*
create_vrm_entry(VRM00);
create_vrm_entry(VRM01);
create_vrm_entry(VRM02);
create_vrm_entry(VRM03);
create_vrm_entry(VRM04);
create_vrm_entry(VRM05);
create_vrm_entry(VRM06);
create_vrm_entry(VRM07);
create_vrm_entry(VRM08);
create_vrm_entry(VRM09);
create_vrm_entry(VRM10);
create_vrm_entry(VRM11);
*/


        set_heart_beat(1);
}

int remove()
{
        return save_object(DATA_PATH);
}

string query_name()
{
        return "时间系统(TIME_D)";
}




