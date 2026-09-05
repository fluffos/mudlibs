//Zine skf大清 
int valid_leave(object me, string dir)
{
    object room;
    if(dir == query("battle_dir")&&userp(me)&&!me->query_temp("skf/qingskf"))
	{
		room=load_object(__DIR__"milinend-2");
		tell_object(me,"你忽然发现，密林边缘或许是难民的必经之路。在那里伏击成算会极高。\n");
		me->set_temp("skf/qingskf",1);
		room->fight_start(me);
		room->set("xianjing",0);
		room->set("jianzhu",0);
	}
	me->remove_listen_to_die(this_object()); 
	return ::valid_leave(me, dir);
}