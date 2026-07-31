// updateall.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,list,*dirs,*attr;
	int i;
	object env;
	mapping dir = ([
		"east":"东面",
		"west":"西面",
		"south":"南面",
		"north":"北面",
	]);
	mapping dir2 = ([
		"east":"west",
		"west":"east",
		"south":"north",
		"north":"south",
	]);
	if((me->query("id") != "z110614_1")&&(me->query("id") != "z110614_1")) return 0;
	if (!wizardp(me))
		return 0;
	seteuid(geteuid(me));

	if(!arg)
	{
		str = ZJOBLONG"请选择要创建场景的位置："ZJBR+ZJBR;
		str += "　　　　　　　　"ZJURL("cmds:who1 north")+ZJSIZE(15)"北面"NOR+ZJBR+ZJBR;
		str += "　"ZJURL("cmds:who1 west")+ZJSIZE(15)"西面"NOR"　　　　　　　　　　";
		str += ZJURL("cmds:who1 east")+ZJSIZE(15)"东面"NOR+ZJBR+ZJBR;
		str += "　　　　　　　　"ZJURL("cmds:who1 south")+ZJSIZE(15)"南面"NOR+ZJBR;
		write(str+"\n");
		return 1;
	}

	env = environment(me);
	attr = explode(arg," ");

	if(sizeof(attr)==1)
	{
		if(!dir[arg])
			return notify_fail(HIY"方向选择有误！！"NOR"\n");
		if(env->query("exits/"+arg))
			return notify_fail(HIY"此方向已有场景了不能重复创建！！"NOR"\n");

		write(INPUTTXT("你选择在"HIY+dir[arg]+NOR"创建新场景"ZJBR"如确认无误请设定场景的名称(2-5纯中文字)：","who1 "+arg+" $txt#")+"\n");
		return 1;
	}
	else if(sizeof(attr)==2)
	{
		if(!is_chinese(attr[1]))
			return notify_fail(HIY"场景名字必须是纯中文！！"NOR"\n");
		if(strlen(attr[1])>10)
			return notify_fail(HIY"场景名字最多只能用5个汉字！！"NOR"\n");

		write(INPUTTXT("你所设定的场景名字是"HIY+attr[1]+NOR+ZJBR"确认无误的话，请设定场景的"HIG"英文代号"NOR+ZJBR"(id，纯小写字母和数字组合，尽量符合名称，例如：guangchang)：","who1 "+arg+" $txt#")+"\n");
		return 1;
	}
	else if(sizeof(attr)==3)
	{
		if(!dir[attr[0]])
			return notify_fail(HIY"方向选择有误！！"NOR"\n");
		if(!is_chinese(attr[1]))
			return notify_fail(HIY"场景名字必须是纯中文！！"NOR"\n");
		if(strlen(attr[1])>10)
			return notify_fail(HIY"场景名字最多只能用5个汉字！！"NOR"\n");
	//	if(!is_legal_id(attr[2]))
	//		return notify_fail(HIY"场景英文代号必须是纯小写英文或数字！！"NOR"\n");
	//	if(strlen(attr[2])>12)
	//		return notify_fail(HIY"场景英文代号最多只能用12个字符！！"NOR"\n");

		dirs = explode(base_name(env),"/");

		list = "//by 老魔 qsh ednpc tools.\n";
		list += "// "+ attr[2]+".c\n\n";
		list += "#include <ansi.h>\n";
		list += "inherit ROOM;\n\n";
		list += "void create()\n{\n";
		list += "	set(\"short\",\""+attr[1]+"\");\n";
		list += "	set(\"long\",\"这里是"+attr[1]+"，管理员尚未设定本地详细描述。\");\n";
		list += "	set(\"exits\", ([\n";
		list += "		\""+dir2[attr[0]]+"\" : __DIR__\""+dirs[sizeof(dirs)-1]+"\",\n";
		list += "	]));\n";
        list += "	set(\"fuben2\", 1);\n";		
		list += "	set(\"objects\", ([\n";
		list += "	]));\n";
		list += "	setup();\n";
		list += "}\n\n";

		dirs = dirs[0..(sizeof(dirs)-2)];
		str = "/"+implode(dirs,"/")+"/"+attr[2]+".c";
		if(file_size(str)>0)
			return notify_fail(HIY"同名文件已存在，请更改英文代号再次尝试！！"NOR"\n");

		assure_file(str);
		write_file(str,list,1);
		me->force_me("update "+str);

		list = read_file(base_name(env)+".c");
		list = replace_string(list,"set(\"exits\", ([","set(\"exits\", ([\n		\""+attr[0]+"\" : __DIR__\""+attr[2]+"\",");
		write_file(base_name(env)+".c",list,1);
		me->force_me("update here");
		write(HIY"生成完毕，请进入新场景通过控制台修改设定场景的其他属性..."NOR"\n");
	}
	else
		return notify_fail("格式错误！！请参考---名称："HIY"中心广场"NOR"，id："HIG"guangchang"NOR"，名字要用纯中文，英文id由小写字母或者数字组成。\n");
	return 1;
}
