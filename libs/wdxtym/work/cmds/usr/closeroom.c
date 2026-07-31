// updateall.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,list,dir,*dirs,*attr,file,*files;
	string room_type,txt1,txt2,txt3;
	int i,k;
	mapping obs;
	object env;

	seteuid(geteuid(me));

	env = environment(me);
	if(env->query("price_build"))
		room_type = "price";
	else if(env->query("owner_build"))
		room_type = "owner";
	else
		room_type = "system";

	if(room_type!="price")
		return notify_fail(HIY"只能在门口外设定开关！！"NOR"\n");

	if(!arg)
	{
		str = ZJOBLONG"请选择你的家门所在的方向："ZJBR+ZJBR;
		str += "　　　　　　　　"ZJURL("cmds:closeroom north")+ZJSIZE(15)"北面"NOR+ZJBR+ZJBR;
		str += "　"ZJURL("cmds:closeroom west")+ZJSIZE(15)"西面"NOR"　　　　　　　　　　";
		str += ZJURL("cmds:closeroom east")+ZJSIZE(15)"东面"NOR+ZJBR+ZJBR;
		str += "　　　　　　　　"ZJURL("cmds:closeroom south")+ZJSIZE(15)"南面"NOR+ZJBR;
		write(str+"\n");
		return 1;
	}

	dirs = explode(base_name(env),"/");
	dirs = dirs[0..(sizeof(dirs)-2)];
	dir = "/"+implode(dirs,"/")+"/";
	obs = env->query("exits");
	if(!mapp(obs)||!obs[arg])
		return notify_fail("那个方向没有场景。\n");

	if(obs[arg]->query("owner_build")!=me->query("id"))
		return notify_fail(obs[arg]->query("short")+"不是你的家。\n");

	dirs = keys(obs);
	
	list = BUILD_D->get_file_code(find_object(obs[arg]));

	if(strsrch(list,"	set(\"door_room\", 1);\n")!=-1)
	{
		list = replace_string(list,"	set(\"door_room\", 1);\n","");
		find_object(obs[arg])->delete("door_room");
		write("家园已设定为开放！\n");
	}
	else
	{
		list = replace_string(list,"	setup();\n","	set(\"door_room\", 1);\n	setup();\n");
		find_object(obs[arg])->set("door_room",1);
		write("家园已设定为关闭！\n");
	}
	BUILD_D->build_file(me,obs[arg]+".c",list);
	return 1;
}
