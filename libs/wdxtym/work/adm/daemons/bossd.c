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
static int yitian_flag;
static int tulong_flag;
static int step;
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
	set("channel_id", "BOSS精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "BOSS系统已经启动。");

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
	CHANNEL_D->do_channel(this_object(), "sys", "BOSS系统更新所有BOSS。");
	story_name = get_dir("/adm/daemons/boss/" + "*.c");
	story_name = map_array(story_name, (: $1[0..<3] :));

	last_update = time();
}

void heart_beat()
{
	mixed* r;
	object dao,jian,jing,road3;
	int time = time();
	r = localtime(time);

	if(r[1]==0&&r[2]>9&&r[2]<24)
	{
		if(!objectp(running_story)&&!flag)
		{
			flag = 1;
			remove_call_out("start_story");
			remove_call_out("process_story");
			call_out("start_story", 0);
		}
	}
	else flag = 0;

	if(r[1]==30&&r[2]==21)
	{
		jian = find_object("/d/tulong/obj/yitianjian");
		jing = find_object("/d/tulong/obj/zhenjing");
		if ( !yitian_flag && (!jian||!environment(jian)) && (!jing||!environment(jing)) ) 
		{
			road3 = find_object("/d/heimuya/road3");
			if(!road3) road3 = load_object("/d/heimuya/road3");
			road3->start_yitian();
			yitian_flag = 1;
		}
	}
	else yitian_flag = 0;

	if(r[1]==30&&r[2]==20)
	{
		dao = find_object("/d/tulong/obj/tulongdao");
		jing = find_object("/d/tulong/obj/zhenjing");
		if ( !tulong_flag && (!dao||!environment(dao)) && (!jing||!environment(jing)) ) 
		{
			road3 = find_object("/d/beijing/haigang");
			if(!road3) road3 = load_object("/d/beijing/haigang");
			road3->start_tulong();
			tulong_flag = 1;
		}
	}
	else tulong_flag = 0;

}

void go_on_process(object ob)
{
	remove_call_out("start_story");
	remove_call_out("process_story");
	call_out("process_story", 1, ob);
}

int clean_up()
{
	return 1;
}

object query_running_story()
{
	return running_story;
}

varargs void start_story(string sname)
{
	string *all_story;
	string name;
	object ob;

	CHANNEL_D->do_channel(this_object(), "sys", "BOSS系统开始选择BOSS。");

	if (sname)
		all_story = explode(sname, ",");
	else
		all_story = story_name;

	while (sizeof(all_story))
	{
		name = all_story[random(sizeof(all_story))];
		if (undefinedp(history[name]))
			history += ([ name : 0 ]);
		else
			history[name] = (int)time();

		CHANNEL_D->do_channel(this_object(), "sys","BOSS系统选择了BOSS(" + name + ")。");
 
		if (ob = find_object("/adm/daemons/boss/" + name))
			destruct(ob);
	
		catch(ob = load_object("/adm/daemons/boss/" + name));
		running_story = ob;
	
		if (objectp(ob))
		{
			step = 0;
			go_on_process(ob);
			break;
		}
	}
}

string *query_all_story()
{
	return story_name;
}

void process_story(object ob)
{
	mixed line;
	object *listeners;
	string prompt;

	go_on_process(ob);

	if (! objectp(ob))
	{
		return;
	}

	line = ob->query_story_message(step);
	step++;

	prompt = ob->prompt();
	if (! prompt) prompt = HIG "【异域挑战】" NOR;
	if (functionp(line)) catch(line = evaluate(line));
	if (stringp(line))
	{
		listeners = filter_array(users(), (: filter_listener :));
		message("story",  prompt + WHT + line + ""NOR"\n", listeners);
	}

	if (intp(line) && ! line)
	{
		destruct(ob);
	}
}

int filter_listener(object ob)
{
	if (ob->query("env/no_story")) return 0;
	return 1;
}
