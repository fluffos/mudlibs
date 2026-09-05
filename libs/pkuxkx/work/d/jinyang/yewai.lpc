inherit "/include/random_map";
#include <ansi.h>
void create() 
{ 
        set("short", "荒郊野外");
        set("long", @LONG
这里是荒郊野外，人迹罕至。
LONG
        );
	
        set("exits", ([
]));
        set("migong_name","野外"),
        set("no_clean_up", 1);
        set("no_reset", 1);
		set("no_task",1);
        set("outdoors", "jinyang");
		set("real_dark",1);
		setup();
	::create();
}

int start()
{
	string *types=({"山地","林地","湖泽","草原"});
    object ob=this_object();
    object exit3=load_object(__DIR__"tangmingzhen");
	if (query("x")!=0||query("y")!=0||query("z")!=0)
	return 1;
    set("migong_name","野外"),
	set("initialized",1);
    gene(types[random(4)],2,ob,0,0,exit3,0,1); //样本，随机迷宫8个参数，第一个为迷宫地貌类型，在include/random_map.h可查，第二个为迷宫复杂度，3为迷宫原点，4-7为出口，无出口则需补0,第八个参数为迷宫出口对于真实地图是否可见，不可见为1，可见为0
    //call_out("over",3600*24);
    return 1;
}

int over()
{
	if (query("x")!=0||query("y")!=0||query("z")!=0)
	return 1;
	delete("initialized");
    clear_all();
	start();
    return 1;
}
string get_dir(object env1,object env2,object me)
{
	string desc1,desc2,desc3,desc;
	if (env1->query("x")>env2->query("x"))
	desc1="西";
	if (env1->query("x")==env2->query("x"))
	desc1="";
	if (env1->query("x")<env2->query("x"))
	desc1="东";
	if (env1->query("y")>env2->query("y"))
	desc2="南";
	if (env1->query("y")==env2->query("y"))
	desc2="";
	if (env1->query("y")<env2->query("y"))
	desc2="北";
	if (env1->query("z")>env2->query("z"))
	desc3="低";
	if (env1->query("z")==env2->query("z"))
	desc3="";
	if (env1->query("z")<env2->query("z"))
	desc3="高";
	if (desc1!=""||desc2!="")
	desc=desc1+desc2+"面";
	else
	desc="";
	if (desc3!="")
	desc+="略"+desc3;
	if (desc1==""&&desc2==""&&desc3=="")
	{
		desc="附近";
	}
	desc+="的地方。\n";
	if (desc1==""&&desc2==""&&desc3=="")
	{
		if (objectp(me->query_temp("banhe/zhonghui"))&&environment(me->query_temp("banhe/zhonghui"))!=this_object())
		desc+="如果在这里找不到萧中慧，就回到起点换条路找找，"+HIR+"比如提示西南面，可能是直接向西南走，也可能是先向西再向南走。"+NOR+"请注意。\n";
	}
	return desc;
}
int report_zhonghui(object me,object env)
{
	string dir;
	if (objectp(env)&&env->blind_random_map()&&environment(me)!=env)
	tell_object(me,"萧中慧可能在"+dir=get_dir(environment(me),env,me));
	return 1;
}
void init()
{
	object npc;
	if (objectp(npc=this_player()->query_temp("banhe/zhonghui"))&&this_player()->query_temp("banhe/zhonghui_report")!=this_object())
	{
		report_zhonghui(this_player(),environment(npc));
		this_player()->set_temp("banhe/zhonghui_report",this_object());
	}
	::init();
}
int Show_Local_Map()
{
	object origin=this_object()->query("origin_file");
	string file="/d/hangzhou/obj/han_map";
	string *list=({"roomA0","room01","room02","room03","room04","room05","room06","room07","room08","room18","room11","room12","room21","room22","room23",
		"room31","room33","room35","room43","room44","room45","room54","room55","room56","room65","room66","room67","room71","room75","room77","room81","room87","room88"});
	if (stringp(origin->query("LocalMap")))
	file=origin->query("LocalMap");
	else
	{
		if (!origin||!file)
		{
			write("这里暂无详细地图。\n");
			return 1;
		}
		file = read_file(file); //调用map文件
		for (int i=0;i<sizeof(list);i++ )
		file = replace_string(file, list[i],stringp(COLOR_D->uncolor(origin->query("MAZE_LIST")[list[i]]))?sprintf("%|6s",COLOR_D->uncolor(origin->query("MAZE_LIST")[list[i]])[0..5]):sprintf("%|6s","×"));
		origin->set("LocalMap",file);
	}
	this_player()->start_more(file);
	write(" ___________________________________________________________\n×表示此方向不通。\n");
	return 1;
}