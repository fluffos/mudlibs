// user.c
// Modified by iszt@pkuxkx, 2007-03-26, set_temp("netdead") to time() now

#include <origin.h>
#include <user.h>
#include <ansi.h>


inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_LOGIN;

#include <title.h>

void create()
{
    ::create();
    set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
    set_temp("terminal_type", term_type);
    message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
    if( (int)query("potential") - (int)query("learned_points") < 100 )
	add("potential", 1);
    if( (int)query("thief") > 0 )
	add("thief", -1 );
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
    string id;

    id = geteuid();
    if( !id ) id = getuid();
    if( !stringp(id) ) return 0;
    return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
    int res;

    save_autoload();
    res = ::save();
    clean_up_autoload();		// To save memory
    return res;
}

void decrease_activity()
{
	if(time() - query("antirobot/last_deactivity_time") < 900) return;

	if(query("antirobot/deactivity") < 10)
	{
	    add("antirobot/deactivity",1);
  }

	set("antirobot/last_deactivity_time",time());
	if(query("antirobot/deactivity") >= 2)
	{
		if(query("combat_exp") >= 5000000)
		{
			tell_object(this_object(),HIR"请注意，你的活跃度已经偏低。如果你不是机器人，请在半小时内执行fullme命令补充你的活跃度。\r\n"NOR);
			tell_object(this_object(),HIR"请注意，你的活跃度已经偏低。如果你不是机器人，请在半小时内执行fullme命令补充你的活跃度。\r\n"NOR);
			tell_object(this_object(),HIR"请注意，你的活跃度已经偏低。如果你不是机器人，请在半小时内执行fullme命令补充你的活跃度。\r\n"NOR);
		}
		else
		{
			tell_object(this_object(),HIR"请注意，你的活跃度已经偏低。exp 5M以前，你可以使用fullme每15分钟补满全部状态，double内力。\r\n5M后长时间不使用fullme，会被系统判定为机器人。\r\n"NOR);
		}
	}

    if (query("antirobot/deactivity") <= 4)
    {
        set("antirobot/last_activity_time", time());
        if (query("antirobot/seg_first_activity_time"))
        {
            add("antirobot/total_activity_time", time()-query("antirobot/seg_first_activity_time"));
        }
    }
    if (query("antirobot/deactivity") >= 4)
    {
		set("antirobot/seg_first_activity_time", 0);
	}
    else
    {
        set("antirobot/seg_first_activity_time", time());
    }
    if (time()-query("antirobot/last_activity_time")>3600*5)
    {
		set("antirobot/first_activity_time", 0);
        set("antirobot/first_activity_exp", 0);
		set("antirobot/total_activity_time", 0);
        set("antirobot/last_activity_time", 0);
        set("antirobot/pic_fullme_times", 0);
        set("antirobot/hand_fullme_times", 0);
    }
    TOPTEN_D->topten_checkonetype(this_object(), "fullme");
}

void setup()
{
  // We want set age first before new player got initialized with
  // random age.
  update_age(); //计算角色的年龄
  
  ::setup();
  
  
  restore_autoload();

//脸谱初始化，设置原始脸谱，如果存在脸谱则会自动跳过
  init_face(query_temp("link_ob"));

//初始化头衔
  init_title();

//自动创建通用的基本物品
	create_base_item();
  
  //转换旧版本的数据
  transfer_olddata();
  
  //自动装载随机武器/盔甲
  create_autoload_equip();
  
//基本属性检查	
	check_attribute();

//检查技能，经验等等	
	check_skills();

//毒药效果初始化	
	init_poison();


}

//private
void user_dump(int type)
{
	//jason添加这个东西，以冒充有更多的玩家，希望能吸引人来玩。
	//人多了以后，可以渐渐去掉。不知道能不能起作用。
	if(query("noDeadNetnoIdle") == "Pkuxkx")
		return;
    switch(type) {
    case DUMP_NET_DEAD:
	tell_room( environment(), query("name") + "断线超过 "
	  + NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
	command("quit");
	break;
    case DUMP_IDLE:
	if (!wizardp(this_object()))
	{
	    tell_object( this_object(), "对不起，您已经发呆超过 "
	      + IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
	    tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
	      + "化为一堆飞灰，消失了。\n", ({this_object()}));
	    command("quit");
	}
	break;
    default: return;
    }
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
//private
void net_dead()
{
    object link_ob;

    // set_heart_beat(0);
    if( objectp(link_ob = query_temp("link_ob")) )
	destruct(link_ob);

	//lost query_ip_number when net_dead
	LOGIN_D->sub_ip_numbers(query_temp("ip"));

    // Stop fighting, we'll be back soon.
    remove_all_enemy();
	set_temp("netdead", time());
    if( userp(this_object()) ) {
		if(this_object()->query("noDeadNetnoIdle") != "Pkuxkx")
		{
			call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
			tell_room(environment(), query("name") + "断线了。\n", this_object());
		}
		CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
    } else {
	command("quit");
    }
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
    set_heart_beat(1);
    set_temp("netdead",0);
    remove_call_out("user_dump");
    tell_object(this_object(), "重新连线完毕。\n");
}

int is_user_ob()
{
	return 1;
}

int is_realuser()
{
    object loginob;
    loginob = query_temp("link_ob");
    while( loginob && loginob->is_character() ) loginob = loginob->query_temp("link_ob");
    if(!loginob || !loginob->query("realuser_verified")) return 0;
    return 1;

}

//脱离门派设定
int expell_family(string family)
{
  mapping expell_clean=
  (["少林派":({"buddhism","hunyuan-yiqi","yijin-jing","jingang-buhuai"}),
  	"武当派":({"taoism","taiji-shengong"}),
  	"峨嵋派":({"linji-zhuang","mahayana"}),
  	"丐帮":({"huntian-qigong","begging","checking","stealing"}),
  	"天龙寺" : ({"beiming-shengong","kurong-shengong","feihua-zhuyue","liumai-shenjian","yiyang-zhi"}),
  	"天地会" : ({"cangming-gong"}),
  	"全真派" : ({"xiantian-gong","daoxue-xinfa","tiangang-beidou","qixing-array","yiyang-zhi"}),
  	"华山派" : ({"huashan-neigong","zixia-shengong","kuangfeng-kuaijian","yunushijiu-jian","dugu-jiujian"}),
  	"星宿派" : ({"huagong-dafa","xiaowuxiang-gong","poison"}),
  	"白驼山" : ({"hamagong","poison","training"}),
  	"神龙教" : ({"shenlong-xinfa","yangsheshu","zhaosheshu"}),
  	"大轮寺" : ({"longxiang-boruo","huanxi-chan"}),
  	"日月神教" : ({"riyue-shengong","kuihua-shengong","daguangming-xinfa","xixing-dafa","pixie-jian"}),
  	"桃花岛" : ({"bihai-shengong","qimen-bagua","music"}),
  	"古墓派" : ({"yunu-xinfa","xuantie-jian","quanzhen-jian","changhen-bian","meinu-quan","yunu-jianfa","xiaohun-zhang","qianmie-shou"}),
  	"姑苏慕容" : ({"shenyuan-gong","douzhuan-xingyi"}),
  	"明教" : ({"jiuyang-shengong","qiankun-danuoyi"}),
  	"朝廷" : ({"bixue-xinfa","strategy","leadership"}),
  	"灵鹫宫" : ({"beiming-shengong","bahuang-gong","xiaowuxiang-gong"}),
  	"雪山派" : ({"xueshan-neigong"})]);

	delete("task_time");
	delete("quest");  
  delete("family");
  delete("class");
  set("score",0);
  set("title","平民百姓");
//title系统记录玩家title by seagate@pkuxkx
	set_title(TITLE_RANK, query("title"));
	if ( expell_clean[family] )
	{
		for(int lp=0;lp<sizeof(expell_clean[family]);lp++)
		{
			delete_skill(expell_clean[family][lp]);
	//		delete("backup_neili/"+expell_clean[family][lp]);
		}
	}
	restore_face(FACE_ORIGIN);
	add("leave_family/betrayer",1);
	set("leave_family/family_"+query("leave_family/betrayer")+"_"+replace_string(gctime(time(),1),"-",""), family);
	return 1;
}

void pre_destruct()
{
	if( environment() )
	{		
		environment()->add("player_num",-1);
		if(environment()->query("player_num") < 0) environment()->set("player_num",0);
		F_MOVE->RecursiveCalculate(this_object(),environment(),-1);
	}
	if(interactive(this_object()))
	{
		LOGIN_D->sub_ip_numbers(query_ip_number(this_object()));
	}
}
