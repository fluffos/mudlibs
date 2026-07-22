#include <ansi.h>

mixed about_panlong()
{
	string str;
	int i,v,need,base = 30000;
	object xin,me = this_player();
	
	if( me->query("family/family_name")!="方寸山三星洞")
      		return "此乃贫道于东海观「盘龙出沧海，踏云啸九天」而悟出的绝招。";
   	
   	if( me->is_knowing("puti_panlong")=="succ" )
		return "此招精要在于运气全身，以气驭器，重在于「盘龙出沧海，踏云啸九天」的气势。";
	else if( me->is_knowing("puti_panlong") )
	{
		if( me->query("betray/方寸山三星洞")>1 )
			return "你这三心二意的泼户！";
		if( me->query("betray/count")>=3 )
			return "唉，贫道见你眉稀目斜，背生反骨，可不放心教予你知。";
		if( !intp(v=me->query("family/panlong_return"))
		 || v<1 )
		 	v = 1;
		need = v*base;
		if( me->query("faith")<need )
		{
			tell_object(me,HIR"你的门派贡献不足"+need+"点。"NOR"\n");
			return 1;
		}
		if( me->query("family/panlong_r_visit")>=12 )
		{
			EMOTE_D->do_emote(this_object(), "smile",geteuid(me),CYN,0,0,0);
			tell_object(me,CYN+name()+CYN"说道：看在你诚心可嘉的份上，便给你一次「灵台观礼」的机会。"NOR"\n");
			me->delete_knowing("puti_panlong");
			message_vision(HIC"$N"HIC"伸出手来在$n"HIC"头上敲了几敲。\n"NOR,this_object(),me);
			tell_object(me,HIR"你顿时觉得脑海中似乎失去抑或得到了什么。\n"NOR);
			me->delete("family/panlong_r_visit");
			me->delete("family/PLCW");
			me->delete_temp("PLCW_xin");
			me->add("family/panlong_return",1);
			me->add("faith",-need);
			return 1;
		}
		if( me->query("faith")<5000 )
		{
			tell_object(me,HIR"你的门派贡献不足5000点。"NOR"\n");
			return 1;
		}
		if( objectp(xin=me->query_temp("PLCW_xin")) )
		{
			if( stringp(str=xin->query("quest/msg")) )
				return str;
			else	return "还不快去将贫道的信函交出去？！";
		}
		
		xin = new("/quest/family/fc/panlong_xin");
		if( stringp(str=xin->information(me)) 
		 && xin->move(me) )
		{
			message_vision("$N递给$n一封信函。\n",this_object(),me);
			message_vision(CYN"$N"CYN"说道："+str,this_object());
			me->add("faith",-5000);
			return 1;
		}
		else	
		{
			if( xin )
				destruct(xin);
			return 0;	
		}	
	}		
	else	return "要得盘龙真谛，你且先去得「灵台观礼」。";
}
