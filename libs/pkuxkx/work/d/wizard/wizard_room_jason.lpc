// Room: /u/jason/workingroom.c
// Date: by jason(残叶) Tue Dec 25 22:32:33 2007
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "空空如也的房间");
	set("long", @LONG
这是一间冷冰冰的屋子，四壁，地板，屋顶都是由冰冷的大理石建造的。你来到这间屋子，感觉不到一丝的暖意。
仿佛所有的愉快，轻松，乐观，积极都被无情的岁月带走，只留下一个空空的口袋，呆呆着随波逐流。只有偶尔
的回忆，能带来一丝丝的温暖。
LONG
	);
	set("no_clean_up", 0);
	set("realmap", "                                               
                                    
                         [1;32m残叶工作室[2;37;0m            
                                    
                                               
");
	set("exits", ([ /* sizeof() == 2 */
		  "2" : "/d/wizard/wizard_room",
	    "1" : "/d/city/guangchang",
	    "3" : "/d/city/testshop",
        "4" : "/u/jason/hideroom",
		]));
	set("valid_startroom", 1);
	//set_heart_beat(1);
	set("ticket",0);
	setup();
}

void heart_beat()
{
	if(1345809600-time() < 60*10)
	{
		if(1345809600 <= time())
		{
			shout(BLK""HIW"北大侠客行狂欢活动现在开始！希望大家玩的开心！。\n"NOR);
			set_heart_beat(0);
			return;
		}
		if(query("ticket") % 60 == 0)
		{
			shout(BLK""HIW"距离北大侠客行狂欢活动还剩"+chinese_number(1345809600-time())+"秒。本次狂欢持续至26日23点59分59秒。\n"NOR);
		}
		add("ticket",1);
	}
}
int do_check();
int do_cure();

int check_family_reward(int value)
{

		return to_int(1.0*value/100*120);
	
}

mixed* data = ({});

int do_expell(string str)
{
    string* apps;
    string guider,app;
    object ob;
    if(sscanf(str,"%s %s",guider,app) != 2) 
    {
        write("expell 导师id 学生id\n");
        return 1;
    }
    ob = find_player(guider);
    if(!objectp(ob))
    {
        write("没有这个导师。\n");
        return 1;
    }
        apps = ob->query("guider/apps");
        if(!arrayp(apps) || member_array(app,apps) == -1)
        {
            return notify_fail("他不是你的徒弟。\n");
        }
        apps -= ({app});
        ob->set("guider/apps",apps);

    return 1;
}

void init()
{
	int i;
	object me = this_player();
	mixed* tmp_keys;
	if(me->query("id") == "jason")
	{
		add_action("do_check","check");
		add_action("do_cure","cure");
		add_action("do_checkmxp","checkmxp");
		add_action("do_gossip","gossip");

		add_action("do_search","search");

		add_action("do_tmp","tmp");
		add_action("do_kickout","kn");
   		add_action("do_base","base");
   		add_action("do_maze","maze");
   		add_action("do_expell","expell");		
        
        add_action("do_stat","stat");		
        add_action("do_test","test");		

        printf("%d\n",time());
		printf(__DIR__"test\n");
		printf(file_name(this_object()));

		add_action("do_skill_qn","stoqn");

		add_action("do_utf8","utf8");


	}
    

}

int do_utf8()
{
	return notify_fail("哈哈哈\n");
}
int do_skill_qn(string arg)
{
	int from,to;
	string id;
	object me;
	float imp_skill_factor;
	int my_con;
	int i;
	int qn_cost;
	int all_qn_cost;
	if(!arg || sscanf(arg,"%s %d %d",id,from,to) != 3)
	{
		write("本命令用于换算内功修炼所需要的大致。qnstoqn userid 开始级别 结束级别\n");
		return 1;
	}
	if(from <= 0 || from >= to)
	{
		printf("%s,%d,%d\n",id,from,to);
		write("from should be greater than 0 and smaller than to\n");
		return 1;
	}
	//每次修炼消耗当前技能等级*2的qn
	//获得imp_skill = my_skill * 2 * (30+random(pow((my_con-4)*100.0,0.5)));
	//my_con=(int)me->query("con")/2+(int)me->query("int")/2+5;
	//        me->improve_skill(skill, imp_skill/10);
    //    if (me->query("special_skill/corporeity"))
    //    me->improve_skill(skill, imp_skill/50);

	if(!userp(me=find_player(id)) )
	{
		write("user is not online\n");
		return 1;
	}
	my_con = (int)me->query("con")/2+(int)me->query("int")/2+5;
	//random相当于/2
	imp_skill_factor = 2 * (30+(pow((my_con-4)*100.0,0.5))/2);
	imp_skill_factor /= 10;
	if (me->query("special_skill/corporeity"))	
	{
		imp_skill_factor += 0.2;
	}

	for(i=from;i<=to;i++)
	{
		qn_cost = i * 2 * (i+1)*(i+1) / (imp_skill_factor*i);
		all_qn_cost += qn_cost;
	}
	printf("一共消耗潜能:%d点\n",all_qn_cost);
	return 1;
}

int test_str(string result)
{
    result += "xxxx\n";
    return 1;
}
int do_test()
{
    string result = "hi";
    test_str(result);
    printf(result);
    return 1;
}

int sort_users_by_bw(object u1,object u2)
{
    //降序
    if(u1->query_temp("stat_traffic/last_bw") < u2->query_temp("stat_traffic/last_bw"))
    {
        return 1;
    }
    else if(u2->query_temp("stat_traffic/last_bw") < u1->query_temp("stat_traffic/last_bw"))
    {
        return -1;
    }
    return 0;
}
int do_stat()
{
    int i;
    int total;
    object ob;
    object* us = users();
    total = 0;
    us = sort_array(us,"sort_users_by_bw");
    for(i=0;i<sizeof(us);i++)
    {
        printf("%s -- %dB -- %dK -- %dM\n",us[i]->query("id"),us[i]->query_temp("stat_traffic/last_bw"),us[i]->query_temp("stat_traffic/last_bw")/1024,us[i]->query_temp("stat_traffic/last_bw")/1024/1024);
        total = total + us[i]->query_temp("stat_traffic/last_bw");
    }
    printf("总带宽:%dK\n",total/1024);

    
    return 1;
}
int do_mask(string arg)
{
    string name,id;
    if(!wizardp(this_player())) return 0;
    if(sscanf(arg,"%s %s",name,id) == 2)
    {
        this_player()->set_name(name,({id}));
    }
    return 1;
}

int do_base(string arg)
{
    object obj = present(arg);
    if(!obj) obj = present(arg,this_player());
    if(obj)
    {
        printf(base_name(obj)+"\n");
    }
    return 1;
}
int do_search(string arg)
{
	write("haha\n");
    printf("%d",time());
	return 1;
}

int do_kickout(string arg)
{
	object* us = users();
	object ob;
	if(arrayp(us) && (!arg || arg==""))
	{
				ob = us[0];
        seteuid(ROOT_UID);
				tell_object(ob,"对不起，为了排查系统故障，请暂时退出。谢谢合作。\n");
				write("踢出"+ob->query("id")+"\n");
        ob->save();
        destruct(ob);
        seteuid(getuid());
	}
	else
	{
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("咦... 没有这个人?\n");
        seteuid(ROOT_UID);
				tell_object(ob,"对不起，为了排查系统故障，请暂时退出。谢谢合作。\n");
				write("踢出"+ob->query("id")+"\n");
        ob->save();
        destruct(ob);
        seteuid(getuid());

	}
	return 1;
}

int do_tmp(string arg)
{
    object pl = find_player(arg);
    if(objectp(pl))
    {
        printf("%d\n",LOGIN_D->check_multiple_login(pl));
    }
	return 1;
}

int do_checkmxp(string arg)
{
	string id;
	object pl = find_player(arg);

	if(objectp(pl))
	{
		tell_object(pl,ESC"[1z<SUPPORT>\r\n");
		
	}
	write("tell "+id+" "+arg+"\r\n");
	return 1;
}
int do_gossip(string arg)
{
	int i=0;
	string id,msg;	
	object pl ;
	if(sscanf(arg,"%s %s",id,msg) == 2)
	{
		pl = find_player(id);
		if(objectp(pl))
		{
			tell_object(pl,ESC"[1z<H1><H><COLOR FORE=Red>"+msg+"</COLOR><H></H1>\r\n");
			tell_object(pl,ESC"[1z<image FName=zmud256_orange.gif URL=http://www.zuggsoft.com/common/>\r\n");
		}
	}
	write("ok\r\n");
	return 1;
}

int do_cure()
{
	object* obs = users();
	for(int i=0;i<sizeof(obs);i++)
	{
		if(objectp(obs[i]) && obs[i]->query_condition("kuangre") != 0)
		{
			obs[i]->clear_condition("kuangre");
		}
	}
	return 1;
}
int do_check()
{
	object* obs = users();
	for(int i=0;i<sizeof(obs);i++)
	{
		if(objectp(obs[i]) && obs[i]->query_condition("kuangre") != 0)
		{
			write(obs[i]->query("name") + " " + obs[i]->query("id") + "\n");
		}
	}
	return 1;
}

int do_maze()
{
	string dataname,maze_map,inside;
	
	object me=this_player();
	dataname = "";    
    
    dataname = sprintf("/tool/data/chart%d.txt",random(10));
    
    inside = read_file(dataname, 1, 1);
    maze_map = read_file(dataname, 2, 100);
    if(sizeof(maze_map) > 0)
    {
    	me->set_temp("hyd/maze_map",inside);
    	tell_object(me,maze_map);
    }
	tell_object(me,"藏宝图收了无数，竟然没有一张是真的，看来你的眼力有些问题。我考考你，上面这张图里，红色的五角星是宝藏，黑色的实线是山脉，你说说看，宝藏在山谷里还是山谷外？\n");    
    return 1;
}
