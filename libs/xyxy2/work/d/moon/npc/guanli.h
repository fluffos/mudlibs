#include <ansi.h>

string random_name()
{
	string *names = ({
		"蝶衣","扫红","锄药","抱琴","茗烟","菊影",
		"蝶衣","扫红","锄药","抱琴","茗烟","菊影",
	});
	return names[random(sizeof(names))];	
}

string ture_me(object me)
{
	if( !me || !living(me) || !present(me,environment()) )
		return 0;
	EMOTE_D->do_emote(this_object(), ({"bigsis","mm","wuwu","baobao1"})[random(4)],0,CYN,0,0,0);
	tell_object(me,CYN+name()+CYN"说道：说来说去，又要我去服侍这扁毛畜生！\n"NOR);
	EMOTE_D->do_emote(this_object(), "xixi",geteuid(me),CYN,0,0,0);
	message_vision("$N巧目盼兮，乌溜溜的大眼睛朝四周看了看，不怀好意的朝$n笑了一声。\n",this_object(),me);
	message("vision",name()+"在"+me->name()+"耳边小声地说了些话。\n",environment(),me);
	tell_object(me,HIG+name()+HIG"在你的耳边悄声说道：要我服侍那扁毛畜生也不难，只是最近我在长安城内看到一件心仪的衣裳，嘻嘻，怎耐囊中羞涩，。。。，你懂的。\n"NOR);
	return "嘻嘻，该怎么做，你看着办吧。";
}		

string ask_guanli()
{
	string name;
	object me = this_player();
	if( !me->query_temp("pendding/fc_visite")
    	 || me->is_knowing("puti_panlong")
    	 || me->query_temp("pendding/fc_visite_moon") 
    	 || me->query_temp("pendding/fc_visite_moonask")
    	 || !me->query_temp("pendding/fc_moonask") )
		return "那扁毛畜生，提起来就有气。";    	 
	if( me->query_temp("pendding/moon_ask") )
	{
		if( (me->query_temp("pendding/moon_ask"))==(this_object()->query("name")) )
		{
			if( random((me->query_kar()/10))>3 && random(3)==2 )
				return ture_me(me);
			else
			{
				name = random_name();
				if( name==this_object()->query("name") )
					return ture_me(me);
				else
				{	
					me->set_temp("pendding/moon_ask",name);	
					return "谁说轮到我了，明明应该是"+name+"！";	
				}
			}	
		}
		else	return "不是轮到"+me->query_temp("pendding/moon_ask")+"了吗？";
	}
	name = random_name();
	if( name==(this_object()->query("name")) )
	{
		if( random((me->query_kar()/10))>3 && random(3)==2 )
			return ture_me(me);
		else
		{
			name = random_name();
			if( name==this_object()->query("name") )
				return ture_me(me);
		}
	}			
	me->set_temp("pendding/moon_ask",name);	
	return "这事照着顺序来，应该轮到"+name+"了，管我什么事儿？！";
}

int accept_money(object me,int amount)
{
	if( amount<100000 )
		return 0;
	if( !me->query_temp("pendding/fc_visite")
    	 || me->is_knowing("puti_panlong")
    	 || me->query_temp("pendding/fc_visite_moon") 
    	 || me->query_temp("pendding/fc_visite_moonask")
    	 || !me->query_temp("pendding/fc_moonask") )
    	 	return 0;
    	if( me->query_temp("pendding/moon_ask")!=this_object()->query("name") )
    		return 0;
    	EMOTE_D->do_emote(this_object(), "xixi",geteuid(me),CYN,0,0,0);
	message_vision("$N巧目盼兮，乌溜溜的大眼睛朝四周看了看，不怀好意的朝$n笑了一声。\n",this_object(),me);
	message("vision",name()+"在"+me->name()+"耳边小声地说了些话。\n",environment(),me);
	tell_object(me,HIG+name()+HIG"在你的耳边悄声说道：此事天知，地知，你知，我知，王母娘娘不知。\n"NOR);
	message_vision("$N义正词严的道：这事本来就是小女子的分内事，你尽管去和娘娘交差。\n",this_object());
	message_vision("$N将自己小胸脯拍的砰砰作响：这事包在我身上！\n",this_object());
	me->delete_temp("pendding/moon_ask");
	me->delete_temp("pendding/fc_moonask");
    	me->set_temp("pendding/fc_visite_moonask",1);
    	return 1;
}	 		