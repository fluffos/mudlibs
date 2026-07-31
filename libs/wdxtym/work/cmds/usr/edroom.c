// updateall.c
#include <ansi.h>

inherit F_CLEAN_UP;

mapping attrib =([
	"休息室":(["type":"sleep_room","need":"灵石","need_num":50,]),
	"闭关室":(["type":"close_room","need":"灵石","need_num":500,]),
	"练功房":(["type":"practice_room","need":"灵石","need_num":500,]),
	"开关门":(["type":"door_room","need":"金币","need_num":1,]),
]);

mapping lattrib =([
	"名字"	:(["type":"short","need":"金币","need_num":10,]),
	"描述"	:(["type":"long","need":"金币","need_num":10,]),
]);

// 判断是否是合法的汉字
int legal_chinese(string str)
{
	int i;

	if (strlen(str) < 2) return 0;

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] < 161 || str[i] == 255) return 0;
		if ((! (i % 2)) && str[i] >= 248) return 0;
	}

	return 1;
}

int main(object me, string arg)
{
	string *att,str,dir,list,*files,file,attr,atts;
	string nid,msg,txt1,txt2,txt3,room_type;
	int i,num;
	object env,npc;
	mapping guard;

	env = environment(me);

	if(env->query("price_build"))
		room_type = "price";
	else if(env->query("owner_build"))
		room_type = "owner";
	else
		room_type = "system";

	if(room_type!="owner"&&!SECURITY_D->valid_grant(me, "(admin)"))
		return notify_fail(HIY"系统场景只能由巫师改建！！"NOR"\n");
	else if(env->query("owner_build")!=me->query("id")&&me->query("id") != "dudu66")
		return notify_fail(HIY"你只能在自己的家里改建！！"NOR"\n");

	seteuid(geteuid(me));

	if (!arg)
	{
		str = ZJOBLONG"请选择你想修改"+env->query("short")+"的选项：\n";
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
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"%s %d",atts,num)==2)
	{
		if(num!=0 && num!=1)
			return notify_fail(HIG+"只能输入 0（关闭）或 1（打开）！"NOR"\n");
		file = base_name(env);
		list = BUILD_D->get_file_code(env);

		if (attrib[atts])
		{
			if(attrib[atts]["need"]=="灵石"&&me->query("yuanbao")<attrib[atts]["need_num"])
				return notify_fail(HIG+"你的灵石不足以支付改建费！"NOR"\n");
			if(attrib[atts]["need"]=="金币"&&!MONEY_D->player_pay(me,attrib[atts]["need_num"]*10000))
				return notify_fail(HIG+"你的金币不足以支付改建费！"NOR"\n");

			if(sscanf(list,"%s	set(\""+attrib[atts]["type"]+"\"%*s);\n%s",txt1,txt2)==3)
			{
				if(num==0)
				{
					env->delete(attrib[atts]["type"]);
					env->delete("owner_special");
					str = txt1 + txt2;
					str = replace_string(str,"	set(\"owner_special\", 1);\n","");
				}
				else
				{
					if(env->query("owner_special"))
						return notify_fail(HIG+"同一场景只能升级一种功能。"NOR"\n");
					else
						str = txt1 + "	set(\""+attrib[atts]["type"]+"\", " + num + ");\n"
							+ "	set(\"owner_special\", 1);\n" + txt2;
					env->set(attrib[atts]["type"],num);
					env->set("owner_special",1);
				}
				BUILD_D->build_file(me,file+".c",str);
				"/cmds/std/look"->main(me);
				write("修改成功！\n");
			}
			else
			{
				if(env->query("owner_special"))
					return notify_fail(HIG+"同一场景只能升级一种功能。"NOR"\n");
				else
					list = replace_string(list,"	setup();\n","	set(\""+attrib[atts]["type"]+"\", " + num + ");\n	set(\"owner_special\", 1);\n	setup();\n");
				BUILD_D->build_file(me,file+".c",list);
				env->set(attrib[atts]["type"],num);
				env->set("owner_special",1);
				"/cmds/std/look"->main(me);
				write("修改成功！\n");
			}
			if(attrib[atts]["need"]=="灵石"&&num!=0)
				me->add("yuanbao",-attrib[atts]["need_num"]);
		}
		return 1;
	}
	else if (sscanf(arg,"%s %s",atts,attr)==2)
	{
		file = base_name(env);
		list = BUILD_D->get_file_code(env);

		if (lattrib[atts])
		{
			if(atts=="名字")
			{
				if(!is_chinese(attr))
					return notify_fail(HIY"场景名字必须是纯中文！！"NOR"\n");
				if(strlen(attr)>12)
					return notify_fail(HIY"场景名字不能超过6个中文字！！"NOR"\n");
			}
			if(atts=="描述"&&strlen(attr)>300)
				return notify_fail(HIY"场景描述最多只能用150个汉字(300字符)！！"NOR"\n");
			if(atts=="描述"&&!legal_chinese(attr))
				return notify_fail(HIY"场景描述只能用汉字和规定的英文符号！！"NOR"\n");

			if(lattrib[atts]["need"]=="灵石"&&me->query("yuanbao")<lattrib[atts]["need_num"])
				return notify_fail(HIG+"你的灵石不足以支付改建费！"NOR"\n");
			if(lattrib[atts]["need"]=="金币"&&!MONEY_D->player_pay(me,lattrib[atts]["need_num"]*10000))
				return notify_fail(HIG+"你的金币不足以支付改建费！"NOR"\n");

			if(sscanf(list,"%s	set(\""+lattrib[atts]["type"]+"\"%*s);\n%s",txt1,txt2)==3)
			{
				if(attr=="0")
				{
					env->delete(lattrib[atts]["type"]);
					str = txt1 + txt2;
				}
				else
				{
					env->set(lattrib[atts]["type"],attr);
					str = txt1 + "	set(\""+lattrib[atts]["type"]+"\", \"" + attr + "\");\n" + txt2;
				}
				BUILD_D->build_file(me,file+".c",str);
				"/cmds/std/look"->main(me);
				write("修改成功！\n");
			}
			else
			{
				list = replace_string(list,"	setup();\n","	set(\""+lattrib[atts]["type"]+"\", \"" + attr + "\");\n	setup();\n");
				BUILD_D->build_file(me,file+".c",list);
				env->set(lattrib[atts]["type"],attr);
				"/cmds/std/look"->main(me);
				write("修改成功！\n");
			}
			if(lattrib[atts]["need"]=="灵石"&&attr!="0")
				me->add("yuanbao",-lattrib[atts]["need_num"]);
		}
	}
	else
	{
		if (attrib[arg])
		{
			write(INPUTTXT("你想把【"+env->query("short")+"】升级为【"+arg+"】吗？"ZJBR"目前该场景本属性的值为【"+env->query(attrib[arg]["type"])+"】。"
				ZJBR"输入0代表关闭该属性，输入1代表打开该属性。"ZJBR
				HIG"注意：升级需要消耗"+attrib[arg]["need_num"]+attrib[arg]["need"]+NOR"！请谨慎操作以免浪费改建费！","edroom "+arg+" $txt#")+"\n");
		}
		else if (lattrib[arg])
		{
			write(INPUTTXT("你想设定【"+env->query("short")+"】的【"+arg+"】为什么？"ZJBR
				HIG"注意：修改该属性需要消耗"+lattrib[arg]["need_num"]+lattrib[arg]["need"]+NOR"！","edroom "+arg+" $txt#")+"\n");
		}
		return 1;
	}

	return 1;
}
