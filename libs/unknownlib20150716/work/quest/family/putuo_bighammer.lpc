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
		if( !query_owner() )
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