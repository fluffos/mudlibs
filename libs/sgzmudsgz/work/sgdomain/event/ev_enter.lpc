// ev_enter.c
// by fire on July 22, 1998
// to handle the event of an char enter the game
#include <move.h>
#include <mudlib.h>
#include <daemons.h>
int enter_replace(string c_id,object me)
{
	object env;
	object o=CHAR_D->find_npc_char(c_id);
	if(!objectp(o)) {
		CHAR_D->put_on_cloth(c_id);
            return 0;
	}
	env=environment(o);
	if(!objectp(env)) {
		o->remove();
        CHAR_D->set_char(c_id,"status",STATUS_ONLINE);
		CHAR_D->put_on_cloth(c_id);
            return 0;
	}
	(EV_QUIT)->char_swap(o,me);
	o->remove();
	if(environment(me)==env)
		return MOVE_OK;
	return 0;
}

int char_enter(string c_id,object me)
{
	string p_area;
	object o_room;
	p_area=CHAR_D->get_char(c_id,"area");
	if(!AREA_D->area_exist(p_area)) return 0;
        CHAR_D->set_char(c_id,"room",0); // in case his dummy sleep in some room
	if(CHAR_D->get_char(c_id,"in_prison")) {
		string pri_area;
		pri_area=CHAR_D->get_char(c_id,"caught_area");
		if(!AREA_D->area_exist(pri_area)) pri_area=p_area;
		CHAR_D->put_prison( c_id, CHAR_D->get_char(c_id,"in_prison"),pri_area);
		return 1;
        }
	if(CHAR_D->get_char(c_id,"nation")) // this is an officer
	   o_room=load_object(AREA_D->get_area(p_area,"path")+
               AREA_D->get_area(p_area,"meeting"));
	else
	   o_room=load_object(AREA_D->get_area(p_area,"path")+
               AREA_D->get_area(p_area,"fly"));
	if(!objectp(o_room)) return 0;
	me->move(o_room);
	if(environment(me)==o_room) return MOVE_OK;
		return 0;
}
int enter(string c_id)
{
        int p_status,ret;

	object o=previous_object();
	object oo=CHAR_D->find_npc_char(c_id);
//        "/daemons/gini_d"->play_enter(c_id);

	if(objectp(o)) HP_D->set_max_hp(o);
	if(objectp(o)) HP_D->set_max_mp(o);
	//added by suicide in 2001.8.16 for give cloth to all those naked players
        if(!CHAR_D->char_exist(c_id))
           {object cloth=OBJ_D->clone_obj("buyi");//非char角色给一件布衣
            if (objectp(cloth)&&objectp(0))
               {
               cloth->move(o);
               cloth->do_wear();
               }
            
            return 0;
        }
        else
           {mapping wear = CHAR_D->get_char(c_id,"wear");
            if (!wear || !wear["torso"])  //如果cahr没有衣服,给一件布衣
               CHAR_D->add_char_wear(c_id,"buyi");
           }

	if(objectp(oo)) {
		ret=enter_replace(c_id,o);
		return ret;
	}
	CHAR_D->put_on_cloth(c_id,o);
	return char_enter(c_id,o);
}
