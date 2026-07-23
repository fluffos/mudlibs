int ask()
{
	object me=this_player();
	object ob2;

	if( me->query_temp("sl/pks")<3 )
		return 0;

    ob2 = new("/clone/npc/zhong-shentong");
    if( ob2 )
    {
        if( ob2->query("winner") == me->query("id"))
		{
            command( "say 大师是当今武林盟主，如何能轻言“舍身”二字。" );
			destruct(ob2);
			return 1;
		}
		destruct(ob2);
    }

	if( me->query("PKS")<50 )
	{
		command( "say 大师杀孽不重，只要精研佛法，就可逐步消去戾气。" );
		me->delete_temp("sl/pks");
		return 1;
	}

	command( "say 大师过去杀人甚多，颇伤无辜，像木瓜、冰石、天天、"
		+"路客、宝马、驽马、血滴子、乐乐，实是不该杀的。" );
	command( "say 但大师既有舍身消业之心，我有几句话，不妨说给你听听。" );
	me->start_busy(2);
	me->delete_temp("sl/pks");
	call_out("ask2",1,me);
	return 1;
}

int ask2(object me)
{
	int skill = me->query_skill("buddhism",1),
		pks = me->query("PKS");

	message_vision( HIW "无名老僧端坐念到：即心即佛，即佛即心，心明识佛，"
		+"识佛明心，离心非佛，离佛非心……\n" NOR, me );
	message_vision( "$N沉思良久，若有所捂。\n", me );
	me->set_skill("buddhism", skill-pks/20);
	me->set("PKS",pks/2);
	me->start_busy(2);
	return 1;
}
int ask_fofa()
{
object me=this_player();
if(!me->query("guilty"))
{ command("buddhi wuming");return 1;}
if(me->query_skill("buddhism",1)<200)
{ command("say 大师佛法修为不足，恐怕我无法点拨于你。");
return 1;}
if( me->query("family/master_name")!="无名老僧") return 0;
if( me->query("shen")<0) { command("say 你这等奸诈小人，我怎能传你佛法？\n");return 1;}
command("buddhi");
 message_vision( HIW "无名老僧端坐念到：即心即佛，即佛即心，心明识佛，识佛明心，离心非佛，离佛非心……\n" NOR, me );
 message_vision( "$N沉思良久，若有所捂。\n", me );
 me->start_busy(1);
me->delete("guilty");
return 1;
}
