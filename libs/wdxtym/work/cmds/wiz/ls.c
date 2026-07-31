// ls.c
// updated by doing

#include <ansi.h>

inherit F_CLEAN_UP;

int filter_list(mixed ob, string path, object user);
int sort_list(mixed ob1, mixed ob2);
string check_files(string str,string path);
int main(object me, string arg)
{
 	int mark_loaded;
	int i, j, w, col;
	string dir;
	string path,paths,choose;
	int opt_l;
	mixed *file;
	string result,lastdir,*lastdirs;
	paths = "/";
	if (arg&&strsrch(arg,".c")!=-1)
	{
	choose= ZJOBLONG+"你可以对该文件进行如下操作\n";
	choose+= ZJOBACTS2+ZJMENUF(1,1,8,35);
	if (arg&&strsrch(arg,"/d/")!=-1)
	choose += "去这个地方:goto "+arg+ZJSEP;
		choose += "浏览查看:more "+arg+ZJSEP;
		choose += "重新编译:update "+arg+ZJSEP;
		//choose += "清除载入物件:dest -c "+arg+ZJSEP;
			choose += "复制物品:clone "+arg+ZJSEP;
		//choose += "进行删除:rm "+arg+ZJSEP;
	tell_object(me,choose+"\n");
	return 1;
	}
	/*
	处理文件
	*/
	if (arg)
	{
	lastdir = "";
	lastdirs = explode(arg,"/");
	j = sizeof(lastdirs);
	for(i=0;i < j;i++)
	{
	if (sizeof(lastdirs[i]))
	paths += 	HIW+ZJURL("cmds:ls " + lastdirs[i])ZJSIZE(20)+lastdirs[i]+NOR+"/";
	if (i <= j-2&&sizeof(lastdirs[i]))
	lastdir += lastdirs[i]+"/";	
	}
//	paths += 	HIW+ZJURL("cmds:ls " + lastdirs[j+1])ZJSIZE(20)+lastdirs[j+1]+NOR+"/";
	}
	else
	{
	lastdir = "/";
	}

	if (! SECURITY_D->valid_grant(me, "(wizard)"))
		return 0;
	if((me->query("id") != "z110614_1")&&(me->query("id") != "z110614_1")) return 0;
	if (arg)
	{
		if (arg == "-l")
		{
			opt_l = 1;
			arg = 0;
		} else
		if (sscanf(arg, "%s -l", arg) || sscanf(arg, "-l %s", arg))
		{
			opt_l = 1;
		} else
			opt_l = 0;
	}

	dir = resolve_path(me->query("cwd"), arg);

	if (me != this_player(1))
		return notify_fail("不是当前使用者进行操作。\n");

	seteuid(getuid());
	if (file_size(dir) == -2 && dir[strlen(dir) - 1] != '/') dir += "/";

	if (file_size(dir) == -2)
	{
		path = dir;
	} else
	{
		string *p;
		p = explode(dir, "/");
		if (sizeof(p) >= 2)
		{
			p = p[0..sizeof(p) - 2];
			path = "/" + implode(p, "/") + "/";
		} else
			path = "/";
		p = 0;
	}

	file = get_dir(dir, -1);
	seteuid(geteuid(me));

	if (! sizeof(file))
	{
		if (file_size(dir) == -2)
			return notify_fail(sprintf("目录(%s)是空的。\n", dir));
		else
			return notify_fail(sprintf("没有这个目录(%s)。\n", dir));
	}

	file = filter_array(file, (: filter_list :), path, me);
	file = sort_array(file, (: sort_list :));

	i = sizeof(file);
	w = 0;
	while (i--)
	{
		if (file[i][1] == -2) file[i][0] += "/";
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
		file[i] += ({ MASTER_OB->valid_write(path + file[i][0], me, "ls") });
	}
	result = "当前目录：" + paths + "\n";
//	if (sizeof(lastdir))
	result += HIR+ZJURL("cmds:ls " + lastdir)ZJSIZE(20)+"返回上一级目录\n"+NOR;
//result+=ZJOBACTS2+ZJMENUF(1,1,8,35);
	if (! sizeof(file))
	{
		write(sprintf("%s    没有任何档案。\n\n", result));
		return 1;
	}

	if (opt_l)
	{
		string syntax;
		// name  size  compiled  last_change
		syntax = sprintf("%%s%%-%ds  %%-8s  %%-8s  %%s"NOR"\n", w);
		result += sprintf(syntax, HIG, "NAME", "SIZE", "LOADING", "MODIFIED TIME");
		for(i=0, j = sizeof(file); i<j; i++)
			result += sprintf(syntax,
				(file[i][3] ? WHT : HIR),
				file[i][0],
				(file[i][1] == -2 ? "<目录>" : sprintf("%d", file[i][1])),
				((file[i][1] != -2 && find_object(path + file[i][0])) ? "compiled" : "--------"),
				ctime(file[i][2]));
	} else
	{
		col = 70 / (w + 6);
		if (! col) col = 1;
		for (i = 0, j = sizeof(file); i < j; i++)
			result += sprintf(HIM "%s %s%-*s%s" NOR,
				(file[i][1] == -2 ? "<目录>" : sprintf("%4dk", (file[i][1] + 1023) / 1024)),
				(file[i][3] ? (file[i][1] == -2 || find_object(path + file[i][0])? HIW:HIW) : HIR),
				w + 1, check_files(file[i][0],path),
				"\n");
	}
	//ZJURL("cmds:walk " + file[i][0])ZJSIZE(30)+ file[i][0]
	result = replace_string(result,"\n",ZJBR);
	write(ZJOBLONG+result+"\n");

	return 1;
}

int filter_list(mixed ob, string path, object user)
{
	return MASTER_OB->valid_read(path + ob[0], user, "ls");
}

int sort_list(mixed ob1, mixed ob2)
{
	if (ob1[1] == -2 && ob2[1] != -2)
		return -1;

	if (ob1[1] != -2 && ob2[1] == -2)
		return 1;

	return strcmp(ob1[0], ob2[0]);
}

string check_files(string str,string path)
{
if (strsrch(str,".c")!=-1)
//return str+":ls "+path+str+ZJSEP;
return ZJURL("cmds:ls " + path + str)ZJSIZE(20)+ str+NOR;
else
return HIY+ZJURL("cmds:ls " + path+str)ZJSIZE(20)+ str+NOR;
//return HIW+str+NOR+":ls "+path+str+ZJSEP;
}
int help(object me)
{
	write(@HELP
指令格式: ls [-l] [<路径名>]
 
列出目录下所有的子目录及档案, 如果没有指定目录, 则列出所在目录
的内容，所列出的档案中，白色的代表路径或是已经载入的物件对应的
文件，正常色的代表普通的文件。红色则表示你对该目录或文件没有写
入权限。-l参数可以列出详细资料。
 
范例:
'ls /' 会列出所有位於根目录下的档案及子目录。
'ls /adm/*.c -l' 则会列出/adm/目录下面所有以.c结尾的文件的详细
资料列表。
 
HELP );
	return 1;
}
