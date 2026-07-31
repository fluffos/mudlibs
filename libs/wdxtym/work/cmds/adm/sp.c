// updateall.c
#include <ansi.h>

inherit F_CLEAN_UP;

int update_dir(object me, string dir, int continueable, int *total);
int update_file(object me, string file);
string stra="";

int main(object me, string arg)
{
	string t1,t2,dir,*strs;
	object ob,obj,env,*users;
	int continueable;
	int *total = ({0});
	int i,m,n,k;
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	users = children("/d/tulong/obj/miji");

	write(sizeof(users)+"....\n");
	for(i=0;i<sizeof(users);i++)
	{
		if(environment(users[i]))
		write(environment(users[i])->query("name")+"....\n");
		destruct(users[i]);
	}
	return 1;
	seteuid(geteuid(me));
	if(!( ob = find_object("/d/lunjian/jingji")) )
		ob = load_object("/d/lunjian/jingji");
	users = filter_array(all_inventory(ob),(: playerp($1) :));
	write(sizeof(users)+"........\n");
	return 1;

env = environment(me);
ob = new("/clone/user/comb_ob");
ob->set("name",me->query("name")+"的战斗");
ob->set("out_room",file_name(env));
ob->move(env);
me->move(ob);
ob->add_apteam(me);
if(arg&&obj=present(arg,env))
{
	obj->move(ob);
	ob->add_dpteam(obj);
}
return 1;
	continueable = 0;
	if (! arg || sscanf(arg, "%s %d", dir, continueable) != 2)
		dir = arg;

	if (! dir)
	{
		dir = me->query("cwd");
		if (! dir)
			return notify_fail("你要重新编译那个路径下档案？\n");
	} else
	{
		dir = resolve_path(me->query("cwd"), dir);
	}
	if (dir[strlen(dir) - 1] != '/')
		dir += "/";

	if (file_size(dir) != -2)
		return notify_fail("没有" + dir + "这个路径。\n");

	me->set("cwd", dir);

	message_system("整理批量档案中，请稍候...");
	if (! update_dir(me, dir, continueable, total))
	{
		write(HIR "编译遇到错误中止。"NOR"\n");
	}

	if (total[0] > 0)
	{
		write(HIC "总共有" + HIW + total[0] + HIC "个档案被成功编译！"NOR"\n");
		write_file("/clone/npc.txt",stra,1);
	}
	else
		write(HIC "没有编译任何档案。"NOR"\n");

	return 1;
}

int update_dir(object me, string dir, int continueable, int *total)
{
	int i,j;
	int l,pay,used,leav;
	int filecount, compcount;
	mixed *file;
	string *strs,npcs,filename,cname,tit,name,ids,id2,txt,tx2;

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

	write (HIY "开始编译目录" + dir + "下面的所有文件。"NOR"\n");
	i = sizeof(file);
	compcount = 0;
	filecount = 0;
	while (i--)
	{
		reset_eval_cost();
		if (file[i][1] != -2)
		{
			filecount++;
			filename = file[i][0];
			l = strlen(filename);

/*抓取npc数据
			name = dir+filename;
			if(name->query("name"))
			{
				stra += name->query("name")+"^"+name->query("id")+"^"+name->query("gender")+"^"+name->query("title")+"^"
					+name->query("age")+"^"+name->query("per")+"^"+name->query("combat_exp")+"^"+name->query("max_qi")+"^"
					+name->query("max_jing")+"^"+name->query("max_neili")+"^"+name->query("family/family_name")+"^"+name->query("long")
						+"\n";
			}
			else continue;
*/

/* 替换重写object
			cname = read_file(replace_string(dir,"/src","/d")+"/"+filename);
			txt = read_file(dir+"/"+filename);
			if(!txt||!cname)
			{
				write(filename+"出现错误。\n");
				continue;
			}
			strs = explode(txt,"\"");
			npcs = "";
			for(j=0;j<sizeof(strs);j++)
			{
				if(sscanf(strs[j],".npc.%s",name)==1)
					npcs += "		__DIR__\"npc/"+lower_case(name)+ "\" : 1,\n";
			}
			if(npcs!="")
			{
				if(strsrch(cname,"//		__DIR__\"npc/baixiaosheng\" : 1,\n")!=-1)
				write_file(replace_string(dir,"/src","/d")+"/"+filename,replace_string(cname,"//		__DIR__\"npc/baixiaosheng\" : 1,\n",npcs),1);
			}
*/

/* 替换重写object
			cname = read_file(replace_string(dir,"/src","/d")+"/"+filename);
			txt = read_file(dir+"/"+filename);
			if(!txt||!cname)
			{
				write(filename+"出现错误。\n");
				continue;
			}
			strs = explode(txt,"\"");
			npcs = "";
			for(j=0;j<sizeof(strs);j++)
			{
				if(sscanf(strs[j],".npc.%s",name)==1)
					npcs += "		__DIR__\"npc/"+lower_case(name)+ "\" : 1,\n";
			}
			if(npcs!="")
			{
				if(strsrch(cname,"//		__DIR__\"npc/baixiaosheng\" : 1,\n")!=-1)
				write_file(replace_string(dir,"/src","/d")+"/"+filename,replace_string(cname,"//		__DIR__\"npc/baixiaosheng\" : 1,\n",npcs),1);
			}
*/

/* 替换重写id,name
			cname = read_file(dir+filename);
			if(sscanf(cname,"%s	set_name(\"%s\");\n%s	setIdName(\"%s\");\n%s",tit,name,txt,ids,tx2)==5)
			{
				int k = 0;
				for(j=0;j<strlen(ids);j++)
				{
					if(ids[j]>='A'&&ids[j]<='Z'&&j>0)
					{
						id2 = replace_string(ids,sprintf("%c",ids[j]),sprintf(" %c",ids[j]));
						write(id2+"\n");
						break;
					}
				}
				if(!id2) id2 = ids+" n";
				id2 = lower_case(id2);
				ids = lower_case(ids);
				write_file(dir+"/"+filename,tit+"	set_name(\"" +name+ "\",({\"" +id2+ "\",\"" +ids+ "\"}));\n"+txt+tx2,1);
			}
*/

///* 检查all_pay,yuanbao_used
			cname = read_file(dir+filename);
			sscanf(cname,"%*s\"id\":\"%s\",%*s",ids);
			sscanf(cname,"%*s\"all_pay\":%d,%*s",pay);
			sscanf(cname,"%*s\"yuanbao_used\":%d,%*s",used);
			sscanf(cname,"%*s\"yuanbao\":%d,%*s",leav);
			if(!pay) pay = 0;
			if(!used) used = 0;
			if(!leav) leav = 0;
			if((used+leav)>(pay*10+2000))
				stra += ids +":充值"+ pay +"元，消费灵石"+used+"，剩余"+leav+"灵石。\n";
			
//*/

/* 重命名
			cname = replace_string(filename,".java",".c");
			rename(dir+"/"+filename,dir+"/"+cname);
*/

/* 重新编译文件
			if (filename[l - 1] != 'c' || filename[l - 2] != '.')
				continue;

			if (! update_file(me, dir + filename) && ! continueable)
				return 0;
*/
			compcount++;
			total[0]++;
			if ((compcount % 70) == 0)
				write("\n");
		}

		// continue to compile next file
	}
	write(HIC "\n整理了目录" + dir + "下的" + HIW + filecount + HIC +
	      "个文件，编译了其中" + HIW + compcount + HIC + "个档案。"NOR"\n" );

	i = sizeof(file);
	while (i--)
	{
		reset_eval_cost();
		if (file[i][1] == -2)
		{
			file[i][0] += "/";
			write("\n");
			if (! update_dir(me, dir + file[i][0], continueable, total) && ! continueable)
				return 0;
		}
	}
	return 1;
}

int update_file(object me, string file)
{
	object obj;
	object *inv;
	string err;
	int i;

	if (file == "/cmds/adm/updateall.c")
		// Don't re-compile the updateall.c
		return 1;

	write (".");
	if (obj = find_object(file))
	{
		if (obj == environment(me))
		{
			if (file_name(obj) == VOID_OB)
				return notify_fail("\n你不能在 VOID_OB 里重新编译 VOID_OB。\n");

			inv = all_inventory(obj);
			i = sizeof(inv);
			while(i--)
			{
				if (userp(inv[i])) inv[i]->move(VOID_OB, 1);
				else inv[i] = 0;
			}
		}
		destruct(obj);
	}

	if (obj) return notify_fail("\n无法清除旧程式码。\n");

	err = catch( call_other(file, "???") );
	if (err)
	{
		printf( "\n发生错误：\n%s\n", err );
		return 0;
	} else
	{
		if ((i = sizeof(inv)) && (obj = find_object(file)))
		{
			while(i--)
				if (inv[i] && userp(inv[i])) inv[i]->move(obj, 1);
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
