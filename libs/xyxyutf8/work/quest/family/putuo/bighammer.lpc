inherit ROOM;
#include <ansi.h>

object query_owner()
{
	object who;
	if( !clonep(this_object()) )
		return 0;
	if( !query("owner_id") )
		return 0;
	who = find_player(query("owner_id"));
	if( !who || !living(who) || who->is_ghost() )
		return 0;
	if( !present(who,this_object()) )
	{
		if( time()>=query("start_time")+900
		 || who->is_knowing("putuo_bighammer") )
			return 0;
	}
	return who;
}

void reset()
{
	if( clonep(this_object()) )
	{
		if( !query_owner() && query("owner_id") )
		{
			destruct(this_object());
			return;
		}
	}
	::reset();
}

void create()
{
	set("short", "静室");
  	set("long", @LONG
这里便是普陀弟子静修的地方，屋子里空空荡荡，就
地上摆着一个蒲团。

LONG);
	set("exits",([
		"out" : "/d/nanhai/chanfang",
	]));
	set("channel_id","观音菩萨(Guanyin pusa)");	
	setup();
}

int valid_leave(object who,string dir)
{
	if( !clonep(this_object()) )
		return 0;
	if( who!=query_owner() )
		return 0;
	if( dir=="out" )
	{
		if( who->is_knowing("putuo_bighammer") )
			CHANNEL_D->do_channel(this_object(),"chat","我派弟子"+HIY+who->name()+HIC"历经艰苦，终于悟得「"HIY"大力降魔杵"HIC"」奥义，可喜可贺。"NOR);
		else	message_vision("$N参悟了半天，结果一脑子的浆糊，不禁对自己的人生产生了极大的疑问。\n$N垂头丧气的离开了静室。\n\n",who);
		delete_temp("owner_id");
		remove_call_out("reset");
		call_out("reset",5);
	}
	return ::valid_leave(who,dir);		
}

void init()
{
	if( clonep(this_object()) && query_owner()
	 && this_player()==query_owner() )
	{
		remove_call_out("canwu");
		call_out("canwu",5+random(5),this_player());
	}
}

void canwu(object who)
{
	object npc;
	remove_call_out("canwu");
	if( !clonep(this_object()) )
		return;
	if( !who || !present(who,this_object()) )
	{
		delete_temp("owner_id");
		remove_call_out("reset");
		call_out("reset",5);
		return;
	}
	message_vision("$N盘膝在蒲团上坐下，低头潜思起来。\n\n",who);
	if( random(who->query("betrayer"))>10 )
	{
		tell_object(who,"\n你静坐片刻，忽觉心底升起一股无由的戾气，怎么也压制不住。\n\n");
		message("vision",who->name()+"忽地变得面目狰狞，双眸通红，仿若疯狂。\n\n",this_object(),who);
		EMOTE_D->do_emote(who, "life",geteuid(who),CYN,0,0,0);
		EMOTE_D->do_emote(who, "life",geteuid(who),CYN,0,0,0);
		EMOTE_D->do_emote(who, "life",geteuid(who),CYN,0,0,0);
		message_vision("\n\n半空祥云阵阵，露出一位菩萨，朝$N叹了一口气。\n\n",who);
		tell_object(who,HIY"【师门】佛门六度：「戒度」任务失败。"NOR"\n");
		who->set_temp("pending/putuo_bighammer_fail",1);
		return;
	}
	if( random(who->query("water"))<5 || random(who->query("food"))<5 )
	{
		tell_object(who,"\n你静坐片刻，忽地肚子里咕噜噜响了起来，却原来是饥渴难耐。\n\n");
		message_vision("\n\n半空祥云阵阵，露出一位菩萨，朝$N叹了一口气。\n\n",who);
		tell_object(who,HIY"【师门】佛门六度：「忍度」任务失败。"NOR"\n");
		who->set_temp("pending/putuo_bighammer_fail",1);
		return;
	}
	if( random(who->query_skill("buddhism",1))<400 )
	{
		tell_object(who,"\n你静坐片刻，却是毫无心得，只觉得脑中一片糊涂。\n\n");
		message_vision("\n\n半空祥云阵阵，露出一位菩萨，朝$N叹了一口气。\n\n",who);
		tell_object(who,HIY"【师门】佛门六度：「精进度」任务失败。"NOR"\n");
		who->set_temp("pending/putuo_bighammer_fail",1);
		return;
	}
	if( random(who->query_kar()+who->query_int())<30 )
	{
		tell_object(who,"\n你静坐片刻，只坐得形容枯槁，还是对佛法无甚理会。。。。\n\n");
		message_vision("\n\n半空祥云阵阵，露出一位菩萨，朝$N叹了一口气。\n\n",who);
		tell_object(who,HIY"【师门】佛门六度：「禅度」任务失败。"NOR"\n");
		who->set_temp("pending/putuo_bighammer_fail",1);
		return;
	}
	if( random(who->query_skill("literate",1))<400 )
	{
		tell_object(who,"\n你静坐片刻，却无法做到心境如如，对耳边的佛音无法领会。\n\n");
		message_vision("\n\n半空祥云阵阵，露出一位菩萨，朝$N叹了一口气。\n\n",who);
		tell_object(who,HIY"【师门】佛门六度：「慧度」任务失败。"NOR"\n");
		who->set_temp("pending/putuo_bighammer_fail",1);
		return;
	}
	npc = new(__DIR__"give");
	npc->set("owner_id",who->query("id"));
	if( npc->move(this_object()) )
	{
		message_vision("\n房门一开，从外面偷偷摸摸进来了一个人。\n\n",who);
		return;	
	}
	else
	{
		if( npc )
			destruct(npc);
		message_vision("\n\n$N参悟了半天，结果一脑子的浆糊，不禁对自己的人生产生了极大的疑问。\n\n",who);
		delete_temp("owner_id");
		remove_call_out("reset");
		call_out("reset",5);
		return;	
	}
}