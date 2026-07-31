// set.c
#include <ansi.h>

#define MAX_ENV_VARS	40
 
int help();

#define LIST_TERM	       1
#define STRING_TERM	     2
#define NUMBER_TERM	     4
#define NON_ZERO		8
#define ENABLE_COLOR	    16
#define NON_NEG		 0x10
#define WIZ_ONLY		0x80

mapping query_terms() { return ([
	"auto_ban"	  : LIST_TERM,
	"auto_drinkout"   : 0,
	"auto_invite"	  : LIST_TERM,
	"auto_regenerate" : 0,
	"auto_say"	: 0,
	"no_vip"	: 0,
	"brief"	   : 0,
	"nocha_skills"	   : 0,
	"combatd"	 : 0,
	"combatd2"	 : 0,
	"careful"	 : 0,
	"can_accept"      : LIST_TERM,
	"can_emote"       : LIST_TERM,
	"can_snoop"       : LIST_TERM,
	"can_tell"	: LIST_TERM,
	"default_sign"    : NUMBER_TERM | NON_NEG | NON_ZERO,
	"halt_age"	: 0,
	"jam_talk"	: 0,
	"keep_idle"       : 0,
	"no_tan"       : 0,	
	"no_give_me"       : 0,	//对方拒绝
	"no_exp"       : 0,	
	"no_new_hp1"	: 0,//新的血条状态栏显示方式 0关闭 1开启
	"look_window"     : 0,
	"no_accept"       : LIST_TERM,
	"no_autoultra"    : 0,
	"no_emote"	: LIST_TERM,
	"no_more"	 : 0,
	"no_teach"	: 0,
	"no_tell"	 : LIST_TERM,
	"no_story"	: 0,
	"no_show"	: 0,
	"no_follow"       : 0,
	"prompt"	  : 0,
	"public"	  : 0,
	"pure_say"	: 0,
	"sign1"	   : STRING_TERM,
	"sign2"	   : STRING_TERM,
	"sign3"	   : STRING_TERM,
	"sign4"	   : STRING_TERM,
	"sign5"	   : STRING_TERM,
	"wimpy"	   : 0,
	"yuanshen"	   : 0,
	"hpp"	   : 0,
	"hppp"	   : 0,
	"yuanshenk"	   : 0,

	"wimpy_apply"     : 0,
	"combat_test"     : WIZ_ONLY,
	"invisible"       : WIZ_ONLY,
	"immortal"	: WIZ_ONLY,
	"msg_out"	 : WIZ_ONLY | STRING_TERM | ENABLE_COLOR,
	"msg_in"	  : WIZ_ONLY | STRING_TERM | ENABLE_COLOR,
	"no_prefix"	  : WIZ_ONLY,
]); }

mapping query_env_domains() { return ([
	"combatd" : ([
		"normal" : 0,
		"damage" : 1,
		"brief"  : 2,
		"self"   : 3,
		"null"   : 4,
		"new"   : 5,
	]),
	"combatd2" : ([
		"all" : 0,
		"self"   : 1,
	]),
	"jam_talk" : ([
		"none" : 0,
		"half" : 1,
		"abs"  : 2,
	]),
]); }

int main(object me, string arg)
{
	int i,num;
	int k;
	mapping env_domains;
	string msg;

	mapping term_map;
	string *terms;
	string term;
	mixed data;
	mapping env;
	mapping d;
	string *ks;
	mixed *bs;

	int opt_add, opt_del;
 
	env = me->query("env");

	term_map = query_terms();
	env_domains = query_env_domains();
 
	if (! arg || arg == "")
	{
		msg = "你目前设定的环境变数有：\n";
		if (! mapp(env) || ! sizeof(env))
			msg = "你目前没有设定任何环境变数。\n";
		else
		{
			terms = sort_array(keys(env), 1);
			for (i = 0; i < sizeof(terms); i++)
			{
				if (mapp(d = env_domains[terms[i]]))
				{
					ks = keys(d);
					for (k = 0; k < sizeof(ks); k++)
						if (d[ks[k]] == env[terms[i]])
							break;
					if (k < sizeof(ks))
					{
						msg += sprintf("%-20s  %O\n",
						       terms[i], ks[k]);
						continue;
					}
				}
				msg += sprintf("%-20s  %O\n", terms[i], env[terms[i]]);
			}
		}
		write(msg);
		return 1;
	}
 
	if(arg=="sign5")
	{
		write(INPUTTXT("请输入要自动循环执行的命令或命令组：$br#命令组格式为分号连接的5个以下命令。","set sign5 $txt#")+"\n");
		return 1;
	} else
	if (arg == "nocha_skills")
	{
		msg = ZJOBLONG"特殊设定：";
		msg += NOR"\n"ZJOBACTS2+ZJMENUF(1,1,10,32);
		msg += "自动逃跑-当前设定： "HIG+me->query("env/wimpy")+NOR"%:set wimpy"ZJSEP;			
		if (me->query("env/nocha_skills"))
		msg += "展示技能-当前设定： "HIG"隐藏"NOR":unset nocha_skills"ZJSEP;
		else		
		msg += "展示技能-当前设定： "HIR"不隐藏"NOR":set nocha_skills 1"ZJSEP;	
		if (me->query("env/keep_idle"))		
		msg += "发呆离线-当前设定： "HIG"不离线"NOR":unset keep_idle"ZJSEP;
		else
		msg += "发呆离线-当前设定： "HIR"离线"NOR":set keep_idle 1"ZJSEP;	
		if (me->query("env/auto_regenerate"))		
		msg += "自动吸气-当前设定： "HIG"自动"NOR":unset auto_regenerate"ZJSEP;
		else
		msg += "自动吸气-当前设定： "HIR"不自动"NOR":set auto_regenerate 1"ZJSEP;
		if (me->query("env/no_exp"))		
		msg += "师门获取修为-当前设定： "HIR"不获取"NOR":unset no_exp"ZJSEP;
		else
		msg += "师门获取修为-当前设定： "HIG"获取"NOR":set no_exp 1"ZJSEP;	
		if (me->query("env/no_tan"))		
		msg += "私聊弹窗-当前设定： "HIR"关闭"NOR":unset no_tan"ZJSEP;		
		else		
		msg += "私聊弹窗-当前设定： "HIG"开启"NOR":set no_tan 1"ZJSEP;	
	
		if (me->query("env/no_new_hp1"))		
			msg += "新战斗状态-当前设定： "HIG"已开启"NOR":unset no_new_hp1"ZJSEP;		
		else		
			msg += "新战斗状态-当前设定： "HIR"未开启"NOR":set no_new_hp1 1"ZJSEP;	
		
		
		if (me->query("env/no_give_me"))		
			msg += "拒绝接收对方物品-当前设定： "HIG"已开启"NOR":unset no_give_me"ZJSEP;		
		else		
			msg += "拒绝接收对方物品-当前设定： "HIR"未开启"NOR":set no_give_me 1"ZJSEP;	
		if (me->query("env/yuanshen"))		
			msg += "攻击附带元神伤害-当前设定： "HIG"已开启"NOR":set yuanshen 0"ZJSEP;		
		else		
			msg += "攻击附带元神伤害-当前设定： "HIR"未开启"NOR":set yuanshen 1"ZJSEP;		
		if (me->query("env/hpp"))		
			msg += "设置状态条显示-当前设定： "HIG"已设置新版"NOR":set hpp 0"ZJSEP;		
		else		
			msg += "设置状态条显示-当前设定： "HIR"已设置旧版"NOR":set hpp 1"ZJSEP;		
		if (me->query("env/hppp"))		
			msg += "师门刷屏-当前设定： "HIG"不刷屏"NOR":set hppp 0"ZJSEP;		
		else		
			msg += "师门刷屏-当前设定： "HIR"刷屏"NOR":set hppp 1"ZJSEP;		
		if (me->query("env/yuanshenk"))		
			msg += "屏蔽元神伤害刷屏-当前设定： "HIG"不屏蔽"NOR":set yuanshenk 0"ZJSEP;		
		else		
			msg += "屏蔽元神伤害刷屏-当前设定： "HIR"屏蔽"NOR":set yuanshenk 1"ZJSEP;		
		write(msg + "\n");
		return 1;
	} 	else if(arg=="wimpy")
	{
		return notify_fail(INPUTTXT("你在血量低于多少百分比时尝试自动逃跑？","set wimpy $txt#")+"\n");
	} 
	else if(sscanf(arg,"wimpy %d",num)==1)
	{
		me->set("env/wimpy",num);
		me->force_me("set nocha_skills");
		return 1;
	}else
	if(arg=="combatd")
	{
		msg = ZJOBLONG"你目前个人战斗信息显示方式为："ZJBR HIG;
		if(me->query("env/combatd")==1) msg += "有伤害时显示战斗信息";
		else if(me->query("env/combatd")==2) msg += "只显示双方受伤信息";
		else if(me->query("env/combatd")==3) msg += "只显示自己的受伤信息";
		else if(me->query("env/combatd")==4) msg += "不显示任何战斗信息";
		else if(me->query("env/combatd")==5) msg += "数字化精简显示战斗信息";
		else msg += "显示所有战斗信息";
		msg += NOR ZJBR"你目前他人战斗信息显示方式为："ZJBR HIG;
		if(me->query("env/combatd2")==1) msg += "不显示他人战斗信息";
		else msg += "显示他人战斗信息";

		msg += NOR"\n"ZJOBACTS2+ZJMENUF(2,2,10,32);
		msg += "显示所有战斗信息:set combatd normal"ZJSEP;
		msg += "有伤害时显示战斗信息:set combatd damage"ZJSEP;
		msg += "只显示双方受伤信息:set combatd brief"ZJSEP;
		msg += "只显示自己的受伤信息:set combatd self"ZJSEP;
		msg += "不显示任何战斗信息:set combatd null"ZJSEP;
		msg += "数字精简显示战斗信息:set combatd new"ZJSEP;
		msg += "屏蔽他人战斗信息:set combatd2 self"ZJSEP;
		msg += "显示他人战斗信息:set combatd2 all";
		write(msg + "\n");
		return 1;
	}

	opt_add = 0;
	opt_del = 0;
	if (sscanf(arg, "%s -a %s", term, data) == 2 ||
	    sscanf(arg, "-a %s %s", term, data) == 2)
	{
		opt_add = 1;
	} else
	if (sscanf(arg, "%s -d %s", term, data) == 2 ||
	    sscanf(arg, "-d %s %s", term, data) == 2)
	{
		opt_del = 1;
	} else
	if (sscanf(arg, "%s %s", term, data) != 2)
	{
		term = arg;
		if (term_map[term] & STRING_TERM ||
		    term_map[term] & NUMBER_TERM)
			return notify_fail("你必须指明这个参数的内"
					   "容，否则请用 unset 取消这个参数。\n");
		else
			data = "YES";
	}
 
	if (data == "")
		return notify_fail("设定的参数值不能为空。\n");

	if (term_map[term] & NUMBER_TERM)
	{
		sscanf(data, "%d", data);
		if (! intp(data)) data = 0;
		if ((term_map[term] & NON_ZERO) && ! data)
			return notify_fail("这个参数值不能设置为零。\n");

		if ((term_map[term] & NON_NEG) && data < 0)
			return notify_fail("这个参数值不能设置为负数。\n");
	} else
	if (term_map[term] & STRING_TERM &&
	    term_map[term] & ENABLE_COLOR)
	{
		data = color_filter(data);
		if (strsrch(data, ESC) != -1)
			data += NOR;
	}

	if (term && term != "")
	{
		if (mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS)
			return notify_fail("你设的环境变数太多了，请先用 unset 删掉几个吧。\n");

		if (undefinedp(term_map[term]))
			return notify_fail("你只能设定规定的参数，请参见help settings。\n");

		if ((wiz_level(me) == 0) && (term_map[term] & WIZ_ONLY))
			return notify_fail("只有巫师能用这个设定。\n");

		if (term_map[term] & LIST_TERM)
		{
			if (! stringp(data) || data == "YES")
				return notify_fail("列表参数只能以字符串为取值。\n");

			ks = explode(data, ",") - ({ "" });
			bs = ({ });
			for (i = 0; i < sizeof(ks); i++)
			{
				if (member_array(ks[i], bs) == -1)
					bs += ({ ks[i] });
			}
			data = implode(bs, ",");
		}

		if (opt_add || opt_del)
		{
			if (! (term_map[term] & LIST_TERM))
				return notify_fail("这个参数不具有列表属性，不"
						   "能使用-a或则是-d参数。\n");
			if (opt_add)
				data = add_sub(data, me->query("env/" + term));
			else
				data = remove_sub(data, me->query("env/" + term));
			if (strlen(data) > 256)
				return notify_fail("参数取值太长了。\n");

			if (! data)
			{
				me->delete("env/" + term);
				write("取消环境参数：" + term + "\n");
				return 1;
			}
		}

		if (mapp(d = env_domains[term]))
		{
			if (! undefinedp(d[data])) data = d[data];

			// check the data
			ks = keys(d);
			for (k = 0; k < sizeof(ks); k++)
				if (d[ks[k]] == data) break;
			if (k >= sizeof(ks))
			{
				write("该项参数不能设置成该值，请参见help settings。\n");
				return 1;
			}
			me->set("env/" + term, data);
			write(sprintf("设定环境变数：%s = %O\n", term, ks[k]));
			return 1;
		} else
		if (stringp(data) && ! (term_map[term] & LIST_TERM) &&
		    ! (term_map[term] & STRING_TERM))
			sscanf(data, "%d", data);

		me->set("env/" + term, data);
		write(sprintf("设定环境变数：%s = %O\n", term, data));

		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
指令格式：set <变数名> -a | -d [<参数>]
 
这个指令让你设定一些环境变数，不加参数时会显示你目前设定的环境变数，不指定
变数值，则内定值为 "YES"。如果使用了-a参数，表示将参数加入到原有的参数中，
如果使用了-d参数则表示将参数从原有的参数中去掉。只有具有多值属性的参数才能
使用这两个参数。

比如no_tell参数，可以设定为不收听test和work的讲话：
set no_tell test,work

如果这时候你不希望收听nothing的讲话，则可以：
set no_tell -a nothing  也可以：set no_tell test,work,nothing

如果这时候你希望收听test的讲话，则可以：
set no_tell -d test     也可以：set no_tell work,nothing

取消变数设定请用 unset 指令。

至於有哪些环境变数可以设定，请见 help settings。
TEXT
	);
	return 1;
}
