// apprentice.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob, old_app, pre_master;
	mapping family, skills, menpai, my_menpai;
	int i, t;
	string *skname, st;
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if( !arg ) 
		return notify_fail("指令格式：apprentice | bai [cancel]|<对象>\n");
	if ( me->query("自创门派/generation",1)==1 )
		return notify_fail("你堂堂一派之主，竟然改投他人门下，岂不丢人？\n");
	if( arg=="cancel" )
	{
		old_app = me->query_temp("pending/apprentice");
		if( !objectp(old_app) )
			return notify_fail("你现在并没有拜任何人为师的意思。\n");
		write("你改变主意不想拜" + old_app->name() + "为师了。\n");
		tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
		me->delete_temp("pending/apprentice");
		return 1;
	}	
	if( !(ob = present(arg, environment(me))) || !ob->is_character() )
		return notify_fail("你想拜谁为师？\n");
	if( !living(ob) ) 
		return notify_fail("你必须先把" + ob->name() + "弄醒。\n");
	if( ob==me ) 
		return notify_fail("拜自己为师？好主意....不过没有用。\n");
	if ( ob->query("自创门派",1)&&me->query("family",1)&&me->query("family/family_name",1)!=ob->query("family/family_name",1) )
		return notify_fail("你已有了门派，就不能再拜其他玩家为师了。\n");
	if( userp(ob))
	{
		if ( ob->query("自创门派/generation",1) <= me->query("自创门派/generation",1)&&me->query("自创门派/generation",1)>0)
		{
			message_vision("$N笑着对$n说道：您见笑了，我这点雕虫小技怎够资格做您师父呢？\n",ob,me);
			return 1;
		}
	}
	if( me->is_apprentice_of(ob) || me->query("family/master_id") == ob->query("id") )
	{
		message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", me, ob);
		if (! userp(ob) )
			ob->re_rank(me);
		return 1;
	}
	// If the target is willing to recruit us already, we do it.
	if( (object)ob->query_temp("pending/recruit") == me )
	{
		if( me->query("family") ) 
		{
			message_vision("$N决定背叛师门，改投入$n门下！！\n$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n", me, ob);
			me->set("score", 0);
			if ( me->query("combat_exp") >= 1000 ) me->add("betrayer", 1);
		}
		else
			message_vision("$N决定拜$n为师。\n$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n", me, ob);
		if ( !userp(ob))
		{
			ob->recruit_apprentice(me);
			ob->delete_temp("pending/recruit");
			tell_object(ob, "恭喜你新收了一名弟子！\n");
			family = me->query("family");
			printf("恭喜您成为%s的第%s代弟子。\n",me->query("family/family_name"),chinese_number( me->query("family/generation")));
			return 1;
		}
		else
		{
			switch(ob->query("family/generation",1))
			{
				case 1: 
					if(ob->query("family/弟子",1)>=5) return 0;
					break;
				case 2: 
					if(ob->query("family/弟子",1)>=3) return 0;
					break;
				default: return 0;
			}
		}
		me->set("family/family_name",ob->query("family/family_name",1));
		me->set("family/master_id",ob->query("id",1));
		me->set("family/master_name",ob->query("name",1));
		me->set("family/generation",ob->query("family/generation",1)+1);
		me->set("自创门派/generation",me->query("family/generation",1));
		tell_object(ob, "恭喜你新收了一名弟子！\n");
		printf("恭喜您成为%s的第%s代弟子。\n",ob->query("family/family_name",1),chinese_number(me->query("family/generation",1) ) );
		return 1;
	}
	else
	{
		old_app = me->query_temp("pending/apprentice");
		if( ob==old_app )
			return notify_fail("你想拜" + ob->name() + "为师，但是对方还没有答应。\n");
		else if( objectp(old_app) ) {
			write("你改变主意不想拜" + old_app->name() + "为师了。\n");
			tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
		}		
		message_vision("$N想要拜$n为师。\n", me, ob);
		me->set_temp("pending/apprentice", ob );
		if( userp(ob) )	
			tell_object(ob, YEL "如果你愿意收" + me->name() + "为弟子，用 recruit 指令。\n" NOR);
		else 
			ob->attempt_apprentice(me);
		return 1;
	}
}


int help(object me)
{
	write(@HELP
		指令格式 : apprentice|bai [cancel]|<对象>
		
		这个指令能让你拜某人为师，如果对方也答应要收你为徒的话，就会立即行
		拜师之礼，否则要等到对方用 recruit 指令收你为弟子才能正式拜师。
		
		请注意你已经有了师父，又背叛师门投入别人门下，所有技能会减半，并且
		评价会降到零。
		
		如果对你的师父使用这个指令，会变成向师父请安。
		
		请参考相关指令 expell、recruit
HELP
        );
	return 1;
}


