// emote.c (Mon  09-04-95)



inherit F_CLEAN_UP;
 
int main(object me, string str)
{
	string *emotes,prefix,estr;
	string emote, id;
	object env, ob;
	mixed info;
	object *obj;
	int i, ok=0;

	if (me->ban_say())
		return 0;

	env = environment(me);
	if (info = env->query("no_say"))
	{
		if (stringp(info))
		{
			write(info);
			return 1;
		}

		write("这个地方不能乱做动作。\n");
		return 1;
	}

	if (! str)
	{
		emotes = EMOTE_D->query_all_emote();
		estr = ZJOBLONG+"当前频道【"+me->query_temp("pindao/name")+"】，请选择表情动作：\n"ZJOBACTS2+ZJMENUF(3,3,8,30);
		i = 50;
		while(i--)
		{
			estr += emotes[i]+":emote "+emotes[i]+ZJSEP;
		}
		write(estr+"\n");
		return 1;
	} else
	if (sscanf(str, "%s %s", emote, id)==2) {
		if (!ob = find_object(id))
			return 1;
		
		id = ob->query("id");

		me->force_me(me->query_temp("pindao/id")+"* "+emote+" "+id);
		return 1;
	} else {
		emote = str;
		obj = all_inventory(env);
		if (sizeof(obj)>0) {
			estr = ZJOBLONG+"当前频道【"+me->query_temp("pindao/name")+"】：\n"ZJOBACTS2+ZJMENUF(2,2,8,30);
			for(i=0;i<sizeof(obj);i++)
			{
				if (me->is_fighting(obj[i]) || obj[i]->is_fighting(me)) continue;
				if (!obj[i]->is_character()) continue;
				if (obj[i]->is_corpse()) continue;
				if (me == obj[i]) continue;
					
				estr += "对"+obj[i]->name()+"使用："+emote+":emote "+emote+" "+file_name(obj[i])+ZJSEP;
				ok =1;
			}
			if (ok < 1) {
				estr = ZJOBLONG+"当前频道【"+me->query_temp("pindao/name")+"】："+"\n"ZJOBACTS2+ZJMENUF(2,2,8,30);
				estr += "发送表情："+emote+":"+me->query_temp("pindao/id")+"* "+emote+ZJSEP;
			} else
				estr += "发送表情："+emote+":"+me->query_temp("pindao/id")+"* "+emote+ZJSEP;
			estr += CYN"返回"NOR":emote";
		} else {
			estr = ZJOBLONG+"当前频道【"+me->query_temp("pindao/name")+"】："+"\n"ZJOBACTS2+ZJMENUF(2,2,8,30);
			estr += "发送表情："+emote+":"+me->query_temp("pindao/id")+"* "+emote;
			estr += ZJSEP+CYN"返回"NOR":emote";
		}
		write(estr+"\n");
		return 1;
	}
	
	prefix = me->query("env/no_prefix") ? "" : "～";
	write(CYN "你" + str + ""NOR"\n");
	tell_room(env, CYN + prefix + (string)me->name() +  str + ""NOR"\n", me);
	return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式: emote <动作词>

这个指令可以让你表达一个系统没有预设的动作词, 系统会将你所输入
的文字加上你的姓名後显示给所有在同一个地方的生物看。为了避免造
成困扰, 玩家所输入的词句前面会加上 ~ 以供区别。

范例: emote 坐了下来。
你会看见: 你坐了下来。
其他人会看到: ~包子坐了下来。

其中, 包子就是你的名字.

相关指令: semote
HELP );
	return 1;
}
