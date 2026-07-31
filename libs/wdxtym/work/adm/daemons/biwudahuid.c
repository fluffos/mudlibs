// storyd.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;

// 初始化BOSS系统
#define REFRESH_INTERVAL	10 * 3600

string *story_name;
mapping history;
int     last_update = 0;

static mapping interval;
static object  running_story;
static int flag;
static int a_flag;
static int c_flag;
static int d_flag;
static int e_flag;
static int f_flag;

static int b_flag;
static int yitian_flag;
static int tulong_flag;
static int step;
static int wjg_flag;
static int wjgl_flag;
int    filter_listener(object ob);

void init_story();
void go_on_process(object ob);
varargs void start_story(string sname);

string query_save_file()
{
	return DATA_DIR "bossd";
}

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "老魔");
	CHANNEL_D->do_channel( this_object(), "sys", "比武大会系统启动。");

	// 恢复BOSS发生状况
	restore();

	if (! arrayp(story_name))
		init_story();

	if (! mapp(history))
		history = ([ ]);

	interval = ([ ]);
	set_heart_beat(20);
}

int query_next_update()
{
	return last_update + REFRESH_INTERVAL - time();
}

void init_story()
{
//	CHANNEL_D->do_channel(this_object(), "chat", "公共boss启动，更新所有boss。");
	story_name = get_dir("/adm/daemons/boss/" + "*.c");
	//story_name = map_array(story_name, (: $1[0..<3] :));

	last_update = time();
}

void heart_beat()
{
	object *players;
	mixed* r;
	int a1,a2,a3,i,a4;
	int q=random(100),w=random(100),e=random(100),t=random(100),y=random(100),u=random(100);
	object dao,jian,a,ob;
	object jing,road3,wjg,khy;
	int time = time();
	r = localtime(time);


	if(r[1]==02&&r[2]==20)
	{
		players = users();
		b_flag=1;
		a1=random(2);
       tell_object(players[i],HIR"比武大会报名开始！"NOR"\n"); 
		if(a1==2)
		{
//		ob=new("/d/boss/asan");
//		  ob->move("d/city/beimen");
	CHANNEL_D->do_channel(this_object(), "chat", HIR"比武大会报名开始，奖励多多，不容错过！"NOR"");		
		}
		else if(a1==2)
		{
//		ob=new("/d/boss/asan");
//		  ob->move("d/gumu/huangshaling");
	CHANNEL_D->do_channel(this_object(), "chat", HIR"比武大会报名开始，奖励多多，不容错过！"NOR"");		
		}else 
		{
//		ob=new("/d/boss/asan");
//		  ob->move("d/baiyun/dongjiekou");
	CHANNEL_D->do_channel(this_object(), "chat", HIR"比武大会报名开始，奖励多多，不容错过！"NOR"");		
		}

		
		
	}
	if(r[1]==01)
	{	
players = users();
	b_flag=0;

	}
	if(r[1]==42)b_flag=0;
	if(r[1]==29)b_flag=0;
	if(r[1]==39)b_flag=0;
	if(r[1]==49)b_flag=0;

	
}

