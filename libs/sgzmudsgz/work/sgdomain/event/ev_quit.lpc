//ev_quit.c
// by fire on July 22, 1998
// to handle the event of char quit
#include <mudlib.h>
#include <daemons.h>
mixed char_swap(object me,object cop) {

	object env,wep;
	object *obs;
	object *targets=me->query_targets();
	string c_id;
	int cur_max_hp,cur_hp;

        c_id=me->query_primary_id();
	env=environment(me);
	obs=all_inventory(me);
	wep=me->query_weapon();
	
	me->simple_action("$N一抱拳：要换班了。\n");
	me->move(load_object(VOID_ROOM));

	if(sizeof(obs))
	{
		foreach(object o in obs){
			if(o->query_is_money()) continue; // money will not give npc
			if(o->not_give_npc()) continue; // dont give them so can save
			if(o==wep) {
				me->unwield();
				o->move(cop);
				cop->do_wield(o);
				continue;
			}
			else 
			if(stringp(o->ob_state()))
			{
				o->do_remove();
				o->move(cop);
				o->do_wear();
				continue;
			}
			else
				o->move(cop);
		}
	}
	cur_max_hp=me->query_cur_max_hp();
	cur_hp=me->query_cur_hp();
	cop->set_cur_max_hp(cur_max_hp);
	HP_D->set_max_hp(cop);
	cop->set_cur_max_hp(cur_max_hp);
	cop->set_cur_hp(cur_hp);
	CHAR_D->set_char(c_id,"room",file_name(env));
	cop->move(env);
	if(sizeof(targets))
	{
		foreach(object t in targets)
		{
			if(objectp(t))
				if(t->attackable())
					cop->start_fight(t);
		}
	}
	return cop;

}
void quit(string c_id)
{
	object cop,me;
	if(!CHAR_D->char_exist(c_id))
		return;

	me=previous_object();
	cop=CHAR_D->creat_row_npc_char(c_id);

	char_swap(me,cop);

    CHAR_D->set_char(c_id,"status",STATUS_ACTIVE);
}
