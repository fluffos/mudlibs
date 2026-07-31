// updateall.c
#include <ansi.h>

inherit F_CLEAN_UP;

mapping attrib =([
	"安全区":"no_fight",
	"休息室":"sleep_room",
	"开口费":"price_build",
]);

mapping lattrib =([
	"描述"	:"long",
]);

int main(object me, string arg)
{
	string *att,str,dir,list,*files,file,attr,atts;
	string nid,msg,txt1,txt2,txt3;
	int i,num;
	object env,npc;
	mapping guard;

	env = environment(me);
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	seteuid(geteuid(me));

	if (!arg)
	{
		str = ZJOBLONG"请选择你想调整"+env->query("short")+"的选项：\n";
		str += ZJOBACTS2+ZJMENUF(4,4,9,30);
		att = sort_array(keys(lattrib),1);
		for(i=0;i<sizeof(att);i++)
		{
			str += att[i]+":edroom "+ att[i]+ZJSEP;
		}
		att = sort_array(keys(attrib),1);
		for(i=0;i<sizeof(att);i++)
		{
			str += att[i]+":edroom "+ att[i]+ZJSEP;
		}
		str += "守卫设置:edroom guard"+ZJSEP;
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"%s %d",atts,num)==2)
	{
		if(num<0||num>999999)
			return notify_fail(HIG+"只能输入0关闭或大于1-999999之间的值打开！"NOR"\n");
		file = base_name(env);
		list = read_file(file+".c");

		if (attrib[atts])
		{
			if(sscanf(list,"%s	set(\""+attrib[atts]+"\"%*s);\n%s",txt1,txt2)==3)
			{
				if(num==0)
					str = txt1 + txt2;
				else
					str = txt1 + "	set(\""+attrib[atts]+"\", " + num + ");\n" + txt2;
				write_file(file+".c",str,1);
				me->force_me("update here");
				me->force_me("look");
				write("修改成功！\n");
			}
			else
			{
				list = replace_string(list,"	setup();\n","	set(\""+attrib[atts]+"\", " + num + ");\n	setup();\n");
				write_file(file+".c",list,1);
				me->force_me("update here");
				me->force_me("look");
				write("修改成功！\n");
			}
		}
		return 1;
	}
	else if(arg=="guard")
	{
		str = ZJOBLONG"请选择要守卫的方向："ZJBR+ZJBR;
		str += "　　　　　　　　"ZJURL("cmds:edroom guard north")+ZJSIZE(15)"北面"NOR+ZJBR+ZJBR;
		str += "　"ZJURL("cmds:edroom guard west")+ZJSIZE(15)"西面"NOR"　　　　　　　　　　";
		str += ZJURL("cmds:edroom guard east")+ZJSIZE(15)"东面"NOR+ZJBR+ZJBR;
		str += "　　　　　　　　"ZJURL("cmds:edroom guard south")+ZJSIZE(15)"南面"NOR+ZJBR;
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"guard %s",attr)==1)
	{
		file = base_name(env);
		list = read_file(file+".c");
		if(!mapp(guard = env->query("guard")))
			guard = ([]);

		if(sscanf(attr,"%s %s",dir,atts)==2)
		{
			if(atts=="del")
			{
				map_delete(guard,dir);
				write("此方向守卫设置已清除。\n");
			}
			else if(sscanf(atts,"%s/%s",nid,msg)!=2)
			{
				write(INPUTTXT("请输入守卫拦路消息：","edroom "+arg+"/$txt#")+"\n");
				return 1;
			}
		}
		else
		{
			str = ZJOBLONG"请选择守卫NPC：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
			if(!env->query("objects"))
				return notify_fail("本场景没有调用固定NPC，不能放置守卫。\n");
			files = keys(env->query("objects"));
			if(!sizeof(files))
				return notify_fail("本场景没有调用固定NPC，不能放置守卫。\n");

			str += "取消守卫:edroom "+arg+" del"ZJSEP;
			for(i=0;i<sizeof(files);i++)
			{
				if(file_size(files[i]+".c")<0) continue;
				str += files[i]->query("name")+":edroom "+arg+" "+files[i]->query("id")+ZJSEP;
			}
			write(str+"\n");
			return 1;
		}

		if(dir!="east"&&dir!="south"&&dir!="west"&&dir!="north")
			return notify_fail(HIG+"方向选择有误！"NOR"\n");
		if(atts!="del")
			guard[dir] = nid+"/"+msg;
		files = keys(guard);
		if(sscanf(list,"%s	set(\"guard\"%*s);\n%s",txt1,txt2)==3)
		{
			str = txt1+"	set(\"guard\", ([\n";
			for(i=0;i<sizeof(files);i++)
			{
				str += "		\""+files[i]+"\" : \""+guard[files[i]]+"\",\n";
			}
			str += "	]));\n";
			str += txt2;
			write_file(file+".c",str,1);
			me->force_me("update here");
			me->force_me("look");
			write("修改成功！\n");
		}
		else if(atts!="del")
		{
			list = replace_string(list,"	setup();","	set(\"guard\", ([\n		\""+dir+"\" : \""+nid+"/"+msg+"\",\n	]));\n	setup();");
			write_file(file+".c",list,1);
			me->force_me("update here");
			me->force_me("look");
			write("修改成功！\n");
		}

		return 1;
	}
	else if (sscanf(arg,"%s %s",atts,attr)==2)
	{
		file = base_name(env);
		list = read_file(file+".c");

		if (lattrib[atts])
		{
			if(sscanf(list,"%s	set(\""+lattrib[atts]+"\"%*s);\n%s",txt1,txt2)==3)
			{
				if(attr=="0")
					str = txt1 + txt2;
				else
					str = txt1 + "	set(\""+lattrib[atts]+"\", \"" + attr + "\");\n" + txt2;
				write_file(file+".c",str,1);
				me->force_me("update here");
				me->force_me("look");
				write("修改成功！\n");
			}
			else
			{
				list = replace_string(list,"	setup();\n","	set(\""+lattrib[atts]+"\", \"" + attr + "\");\n	setup();\n");
				write_file(file+".c",list,1);
				me->force_me("update here");
				me->force_me("look");
				write("修改成功！\n");
			}
		}
	}
	else
	{
		if (attrib[arg])
		{
			write(INPUTTXT("你想把【"+env->query("short")+"】的【"+arg+"】从"+env->query(attrib[arg])+"调整为多少？"
				ZJBR"0代表关闭该属性，大于0的值打开该属性并设定值。","edroom "+arg+" $txt#")+"\n");
		}
		else if (lattrib[arg])
		{
			write(INPUTTXT("你想设定【"+env->query("short")+"】的【"+arg+"】为什么？","edroom "+arg+" $txt#")+"\n");
		}
		return 1;
	}

	return 1;
}
