// storyd.c

#include <ansi.h>

inherit F_DBASE;
string  zuji(string str);
private string *story_name = ({//选择故事
#if 1
        "new1",
        "new1",
        "new2",
        "new2",
        "new3",
        "new3",
        "new4",                
        "new4",                
        "new5",
        "new5",//10
        "new6",
        "new6",
        "new7",
        "new7",
        "new8",
        "new8",
        "new9",
        "new9",
        "new10",
        "new10",//20
        "new11",
        "new11",
        "new12",
        "new12",
        "new13",
        "new13",
        "new14",
        "new14",
        "new15",
        "new15",//30
        "new16",
        "new16",
        "laojun",
        "xiyou",
        "xiyou",
        "guanzhang",
        "nanji",
        "liandan",
	"caishen",
	"caishen",//40
	"zhengxi",
	"zhengxi",
	"zagang",
	"zagang",
	"songdai",
	"songdai",
	"niulang",
	"niulang",
	"pergive",
	"pergive",//50
	"kargive",
	"kargive",
	"neiligive",
	"neiligive",
#endif
        "normal",
});

private object  running_story;
private mapping history;
private int step;
int filter_listener(object ob);

void ready_to_start()
{
        remove_call_out("process_story");
        call_out("start_story", 2800);//间隔时间
//        call_out("start_story", 3 + random(1));//间隔时间
}
void go_on_process(object ob)
{
        remove_call_out("start_story");
        remove_call_out("process_story");
        call_out("process_story", 1, ob);
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "事件精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "事件系统已经启动。\n");

        history = allocate_mapping(sizeof(story_name));
        ready_to_start();
}

int clean_up()
{
        return 1;
}

object query_running_story()
{
        return running_story;
}

void start_story()
{
        string name;
        object ob;
        int i;

        ready_to_start();
        CHANNEL_D->do_channel( this_object(), "sys", "事件系统开始选择事件。\n");

        for (i = 0; i < 54; i++)
        {
                name = story_name[random(sizeof(story_name))];
                if (undefinedp(history[name]))
                        history += ([ name : 0 ]);

                if (time() - history[name] > 14400 || name == "normal")
                {
                        history[name] = (int)time();
                        break;
                }
        }

        if (i >= 54) return;

        CHANNEL_D->do_channel( this_object(), "sys", "事件系统选择了事件(" + name + ")。\n");

        name = STORY_DIR + name;
        if (ob = find_object(name))
                destruct(ob);

        catch(ob = load_object(name));
        running_story = ob;

        if (! objectp(ob))
                return;

        step = 0;
        go_on_process(ob);
}

void process_story(object ob)
{
        mixed line;
	object *listeners;
        string prompt;

        go_on_process(ob);

        if (! objectp(ob))
        {
                ready_to_start();
                return;
        }

        line = ob->query_story_message(step);
        step++;

        prompt = ob->prompt();
        if (! prompt) prompt = HIY "【江湖逸事】 " NOR;
        if (functionp(line)) catch(line = evaluate(line));
        if (stringp(line))
	{
		listeners = filter_array(users(), (: filter_listener :));
                message( "story",  prompt + WHT + line + "\n" NOR, listeners );
	}

        if (intp(line) && ! line)
        {
                ready_to_start();
                destruct(ob);
        }
}

int filter_listener(object ob)
{
	if (ob->query("env/no_story")) return 0;
	return 1;
}

void give_gift(string gift, int amount, string msg)
{
        int i;
        object ob;
        object env;
        object *players;
        string room;
string *dir2;

        players = users();
        if (sizeof(players) >= 5)
        {
                for (i = 0; i < 5; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                                
                        env = environment(ob);
                        while (env && env->is_character())
                                env = environment(env);
                        if (env) break;
                }
                if (i >= 5) return;

                if (objectp(env))
                        tell_room(env, msg);
                for (i = 0; i < amount; i++)
                {
                        ob = new(gift);
                        ob->move(env);
                        ob->set("no_get",0);
                        ob->set("no_give",0);
                        ob->set("no_drop",0);
                }
dir2=explode(base_name(env),"/");
room=zuji(dir2[1])+env->query("short");
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+" 在"+room+"附近出现。\n");
                
	        CHANNEL_D->do_channel( this_object(),
			"sys", sprintf(NOR WHT "赠品%s" NOR WHT "掉到了"
				HIC "%s" NOR WHT "(%O" NOR WHT ")。\n" NOR,
                               ob->name(), env->query("short"), env));

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

	output="燕京的";

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

	output="百花谷。黑沼的";

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
	output="台湾地区的";	
}
if (str=="nanyang")  
{
	output="南阳地区的";	
}
if (str=="nanshaolin")  
{
	output="南少林地区的";	
}

if (str=="cangzhou")  
{
	output="沧州地区的";	
}

if (str=="tanggu")  
{
	output="塘沽城地区的";	
}

if (str=="yunhe")  
{
	output="京杭大运河的";	
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
