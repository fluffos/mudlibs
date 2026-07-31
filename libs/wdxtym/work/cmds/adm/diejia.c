// updateall.c
#include <ansi.h>

inherit F_CLEAN_UP;

int update_dir(object me, string dir, int continueable, int *total);

string strs;

int main(object me, string arg)
{
	string dir;
	object ob,obj,env;
	int continueable;
	int *total = ({0});
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	seteuid(geteuid(me));
	continueable = 0;

	if(!arg)
		return notify_fail("你要整理什么物品数据？\n");
	if(file_size(arg+".c")<1)
		return notify_fail("该物品文件"+arg+"不存在，请核对！\n");

	strs = arg;

	log_file("diejia",sprintf("%s：%s(%s)叠加整理%s物品。\n",ctime(time()),me->query("name"),me->query("id"),arg));

	message_system("批量整理中，请稍候...");

	if (! update_dir(me, "/data/baibao/", 1, total))
	{
		write(HIR "整理百宝囊遇到错误中止。"NOR"\n");
	}
	else
		write(HIR "百宝囊整理完毕。"NOR"\n");

	if (! update_dir(me, "/data/user/", 2, total))
	{
		write(HIR "整理玩家背包遇到错误中止。"NOR"\n");
	}
	else
		write(HIR "玩家背包整理完毕。"NOR"\n");

	if (total[0] > 0)
	{
		write(HIC "总共有" + HIW + total[0] + HIC "个档案的"+arg+"被成功整理！"NOR"\n");
	}
	else
		write(HIC "没有整理任何档案。"NOR"\n");

	return 1;
}

int update_dir(object me, string dir, int continueable, int *total)
{
	int i,j,k;
	int l,pay,used,leav;
	int filecount, compcount;
	mixed *file;
	string npcs,filename,cname,tit,name,ids,id2,txt,tx2;

	if (! is_root(previous_object()))
		return 0;
	file = get_dir(dir, -1);
	if (! sizeof(file))
	{
		if (file_size(dir) == -2)
			write(dir + "这个目录是空的。\n");
		else
			write("没有" + dir + "这个目录。\n");
		return 1;
	}

	write (HIY "开始整理目录" + dir + "下面的所有文件。"NOR"\n");
	i = sizeof(file);
	compcount = 0;
	filecount = 0;
	k = 0;
	while (i--)
	{
		reset_eval_cost();
		if (file[i][1] != -2)
		{
			filecount++;
			filename = file[i][0];
			l = strlen(filename);
//替换重写
			cname = read_file(dir+filename);

			if(continueable==1)
			{
				if(strsrch(cname,"\"file\":\""+strs+"\",")!=-1)
				{
					cname = replace_string(cname,"\"file\":\""+strs+"\",","\"amount\":1,\"file\":\""+strs+"\",");
					write_file(dir+filename,cname,1);
					compcount++;
				}
			}
			else if(continueable==2)
			{
				k = 0;
				while(strsrch(cname,"\""+strs+"\",")!=-1)
				{
					cname = replace_string(cname,"\""+strs+"\",","",1,1);
					k++;
				}
				if(k)
				{
					cname = replace_string(cname,"autoload ({","autoload ({\""+strs+":"+k+"\",");
					write_file(dir+filename,cname,1);
					compcount++;
				}
			}
			total[0]++;

			if ((compcount%70)==0) write("\n");
		}

		// continue to compile next file
	}
	write(HIC "\n整理了目录" + dir + "下的" + HIW + filecount + HIC + "个文件，修改了其中" + HIW + compcount + HIC + "个档案。"NOR"\n" );

	i = sizeof(file);
	while (i--)
	{
		reset_eval_cost();
		if (file[i][1] == -2)
		{
			file[i][0] += "/";
			write("\n");

			if (!update_dir(me, dir + file[i][0], continueable, total))
				return 0;
		}
	}
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : updateall <路径名> [1]
 
这个指令可以更新某个路径下的全部档案, 并将新档的内容载入记
忆体内. 如果后面尾随标志1， 则编译遇到错误时将不会中止。
HELP
    );
    return 1;
}
