// storyd.c

#include <ansi.h>

inherit F_DBASE;

protected string *story_name = ({//选择故事
#if 1
        "gem", //宝石
	"new1", //pantao
	"new1",
	"new1",
	"new2", //unconcious, smash
	"new3", //bible
	"new3",
	"new4", //michun
	"new4",
	"new4",
	"new5", //yuxiao
	"new5",
	"new6", //zhenwu
	"new6",
	"new7", //unconcious, box
	"new8", //claw
	"new9", //sword
	"new10", //guigu book
	"new10",
	"new11", //mengzi book
	"new11",
	"new12", //unconcious, or apply armor
	"new13", //9yang
	"new14", //blade
	"new15", //finger
	"new16", //ling
	"new17", //zhentian hammer
	"new18", //potian hammer
	"laojun", //dex dan
  "tbh", //temp int dan
  "linghu", //wuxian jiu
	"xiyou", //50 gold
	"xiyou",
	"guanzhang", //str dan
	"nanji", //con dan
	"liandan", //unknown dan
	"caishen", //money
	"caishen",
	"zhengxi", //axe
	"zagang", //bingtang hulu
	"zagang",
	"songdai", //20 gold
	"songdai",
	"niulang", //wannian lingzhi
	"niulang",
	"pergive", //per dan
	"pergive",
	"kargive", //kar dan
	"kargive",
	"neiligive", //max_neili
	"neiligive",
	"advent", //unconcious
	"lastone", //dodge
         "sun","water","feng", //天灾人祸
	"lastone", //dodge
	"qingr", //wujidan
	"qingr", //wujidan
	"yagami", //yupai
	"nichqe", //stealing
	"nichqe", //stealing
	"fadai", //parry
        "rumoring", //rumoring
	"fadai", //parry
	"npcer", //chenyi
	"npcer", //chenyi
	"pofeng", //pofeng
	"ahp", //poxie
	"ahp", //poxie
	"life", //xiandou
	"life",
	"life",
#endif
	"normal",
});

protected object  running_story;
protected mapping history;
protected int step;
int filter_listener(object ob);

void ready_to_start()
{
	remove_call_out("process_story");
	call_out("start_story", 10800);//间隔时间
//	call_out("start_story", 3 + random(1));//间隔时间
}
void go_on_process(object ob)
{
	remove_call_out("start_story");
	remove_call_out("process_story");
	call_out("process_story", 3, ob);
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

	for (i = 0; i < sizeof(story_name); i++)
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

	if (i >= sizeof(story_name)) return;

	CHANNEL_D->do_channel(this_object(), "sys", "事件系统选择了事件(" + name + ")。");

//        name = STORY_DIR + name;
	name = "/clone/story/" + name;

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
		CHANNEL_D->do_channel(this_object(), "jh", prompt + WHT + line, -1);
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

	players = users();
	if (sizeof(players) >= 10)
	{
		for (i = 0; i < 10; i++)
		{
			ob = players[random(sizeof(players))];
			if (wizardp(ob)) continue;
			if (ob->query("combat_exp") > 100000) continue;

			env = environment(ob);
			while (env && env->is_character())
				env = environment(env);
			if (env) break;
		}
		if (i >= 5) return;

		if (objectp(env))
			tell_room(env, msg);
/*modify by pal
		for (i = 0; i < amount; i++)
		{
			ob = new(gift);
			ob->move(env);
		}
*/
		if(amount>0)
		{
			ob=new(gift);
			ob->set_amount(amount);
			ob->move(env);
		}
		CHANNEL_D->do_channel( this_object(),
			"sys", sprintf(NOR WHT "赠品%s" NOR WHT "掉到了"
				HIC "%s" NOR WHT "(%O" NOR WHT ")。",
				ob->name(), env->query("short"), env));
	}
}
