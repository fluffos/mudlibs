#include <ansi.h>

mixed about_chou()
{
	string name;
	object ob = this_object(),me = this_player();
	
	if( me->query("family/family_name")!="盘丝洞" )
	 	return "我凭什么要告诉你？！";
	if( me->query("family/pansi_JMTX") )
		return "嘻嘻，百年修得姐妹缘，我和她也没甚深仇大恨。";
	if( me->query_temp("JMTX/bai") )
	{
		if( ob->query("name")=="白晶晶" )
		{
			if( !me->query_temp("JMTX/niang") )
				return "你不知道过犹不及吗？！哼！";
		}
		else if( ob->query("name")=="春三十娘" )
			return "怎么？她有东西给我？";
		else	return "找我何事？还是把你手中的事先做完吧。";	
	}
	if( me->query_temp("JMTX/niang") )
	{
		if( ob->query("name")=="春三十娘" )
		{
			if( !me->query_temp("JMTX/bai") )
				return "你不知道过犹不及吗？！哼！";
		}
		else if( ob->query("name")=="白晶晶" )
			return "怎么？她有东西给我？";
		else	return "找我何事？还是把你手中的事先做完吧。";	
	}
	if( me->query_temp("JMTX/qingxia") )
	{
		if( ob->query("name")=="青霞仙子" )
		{
			if( !me->query_temp("JMTX/zixia") )
				return "你不知道过犹不及吗？！哼！";
		}
		else if( ob->query("name")=="紫霞仙子" )
			return "怎么？她有东西给我？";
		else	return "找我何事？还是把你手中的事先做完吧。";	
	}
	if( me->query_temp("JMTX/zixia") )
	{
		if( ob->query("name")=="紫霞仙子" )
		{
			if( !me->query_temp("JMTX/qingxia") )
				return "你不知道过犹不及吗？！哼！";
		}
		else if( ob->query("name")=="青霞仙子" )
			return "怎么？她有东西给我？";
		else	return "找我何事？还是把你手中的事先做完吧。";	
	}
	if( stringp(name=me->query_temp("JMTX/target")) )
	{
		if( name==ob->query("name") )
			return "那贱人有什么东西要给我？";
		else	return "找我何事？还是把你手中的事先做完吧。";		
	}
	
	//梦醒时分
	if( ob->query("name")=="春三十娘" || ob->query("name")=="青霞仙子" )
	{
		EMOTE_D->do_emote(ob, "hmm",geteuid(me),CYN,0,0,0);
		tell_object(me,HIC+ob->name()+"说道：我那妹纸，一片痴心寄清风，奈何还不自知，看了就让人生气。\n"NOR);
		tell_object(me,HIC+ob->name()+"说道：喏，你去长安找那喜福会老板娘酿制一坛「梦醒时分」给她，让她醒醒吧！\n"NOR);
		if( ob->query("name")=="春三十娘" )
			me->set_temp("JMTX/target","白晶晶");
		else	me->set_temp("JMTX/target","紫霞仙子");	
	}
	else
	{
		EMOTE_D->do_emote(ob, "hmm",geteuid(me),CYN,0,0,0);
		tell_object(me,HIC+ob->name()+"说道：我那姐姐，只知常年修炼，怎知我的苦恼，天路漫漫，若无梦想，做人和一条咸鱼有甚区别？\n"NOR);
		tell_object(me,HIC+ob->name()+"说道：喏，你去长安找那喜福会老板娘酿制一坛「醉生梦死」给她，让她明我心意。\n"NOR);
		if( ob->query("name")=="白晶晶" )
			me->set_temp("JMTX/target","春三十娘");
		else	me->set_temp("JMTX/target","青霞仙子");	
	}
	return 1;
/*
	if( me->query_temp("JMTX/type")=="doing" )
	{
		if( me->query_temp("JMTX/target")==ob->query("name") )
			return "听闻你有东西要给我？";
		else if( me->query_temp("JMTX/target")=="白晶晶" )
		{
			if( ob->query("name")!="春三十娘" )
				return "找我何事？还是把你手中的事先做完吧。";
			else	return "你还不快去？手脚放麻利点。";
		}
		else if( me->query_temp("JMTX/target")=="春三十娘" )
		{
			if( ob->query("name")!="白晶晶" )
				return "找我何事？还是把你手中的事先做完吧。";
			else	return "你还不快去？手脚放麻利点。";
		}
		else if( me->query_temp("JMTX/target")=="青霞仙子" )
		{
			if( ob->query("name")!="紫霞仙子" )
				return "找我何事？还是把你手中的事先做完吧。";
			else	return "你还不快去？手脚放麻利点。";
		}
		else if( me->query_temp("JMTX/target")=="紫霞仙子" )
		{
			if( ob->query("name")!="青霞仙子" )
				return "找我何事？还是先把你手中的事先做完吧。";
			else	return "你还不快去？手脚放麻利点。";
		}
		else	return "找我何事？还是把你手中的事先做完吧。";
	}
	else if( me->query_temp("JMTX/type")=="done" )
	{
		me->set("family/pansi_JMTX",1);
		EMOTE_D->do_emote(ob, "jump",geteuid(me),CYN,0,0,0);
		tell_object(me,HIC+ob->name()+"媚眼如丝，朝你细细打量了一番，嘻嘻笑出了声来。\n"NOR);
		EMOTE_D->do_emote(ob, "thank",geteuid(me),CYN,0,0,0);
		message("channel:rumor",HIC"【谈天说地】金灵圣母(Jinling shengmu)：感谢"+me->query("name")+HIC"化解盘丝「同心恩怨」。\n"NOR,users());
		message("channel:rumor",HIM"【小道消息】某人不置可否地道：“难说！”\n"NOR,users());
		message("channel:rumor",HIC"【谈天说地】金灵圣母(Jinling shengmu)：呵呵，只望这段恩怨能彻底泯去。。。\n"NOR,users());
		message("channel:rumor",HIM"【小道消息】某人：呵呵，三世恩仇，不是你说消便消的。\n"NOR,users());
		message("channel:rumor",HIC"【谈天说地】金灵圣母(Jinling shengmu)：呵呵，只望这段恩怨能彻底泯去。。。\n"NOR,users());
		message("channel:rumor",HIC"【谈天说地】金灵圣母的脸上露出疑惑的表情。\n"NOR,users());
		message("channel:rumor",HIC"【谈天说地】金灵圣母「嗯」的一声，一副欲言又止的样子。\n"NOR,users());
		message_vision("\n"HIC"半空中显出金灵圣母的身影。\n\n"NOR CYN"金灵圣母由衷地感谢$N"CYN"。"NOR"\n",me);
		me->add("faith",20000);
		me->delete_temp("JMTX");
		tell_object(me,HIG"【门派】你得到了"HIR+20000+HIG"点门派贡献。\n"NOR);
	}
	else
	{
		//梦醒时分
		if( ob->query("name")=="春三十娘" || ob->query("name")=="青霞仙子" )
		{
			EMOTE_D->do_emote(ob, "hmm",geteuid(me),CYN,0,0,0);
			tell_object(me,HIC+ob->name()+"说道：我那妹纸，一片痴心寄清风，奈何还不自知，看了就让人生气。\n"NOR);
			tell_object(me,HIC+ob->name()+"说道：喏，你去长安找那喜福会老板娘酿制一坛「梦醒时分」给她，让她醒醒吧！\n"NOR);
			me->set_temp("JMTX/type","doing");
			if( ob->query("name")=="春三十娘" )
				me->set_temp("JMTX/target","白晶晶");
			else	me->set_temp("JMTX/target","紫霞仙子");	
			return 1;
		}
		else
		{
			EMOTE_D->do_emote(ob, "hmm",geteuid(me),CYN,0,0,0);
			tell_object(me,HIC+ob->name()+"说道：我那姐姐，只知常年修炼，怎知我的苦恼，天路漫漫，若无梦想，做人和一条咸鱼有甚区别？\n"NOR);
			tell_object(me,HIC+ob->name()+"说道：喏，你去长安找那喜福会老板娘酿制一坛「醉生梦死」给她，让她明我心意。\n"NOR);
			me->set_temp("JMTX/type","doing");
			if( ob->query("name")=="白晶晶" )
				me->set_temp("JMTX/target","春三十娘");
			else	me->set_temp("JMTX/target","青霞仙子");	
			return 1;
		}
	}
	return 1;
*/	
}	