// warai_d.c
// this is used to design some fomular and ai
// for the war
// by fire on Sep 19, 1998
#include <train.h>
#define TROOP_TYPE(x) load_object("/sgdomain/troops/"+x+".c")

inherit __DIR__+"warai_d/misc";
inherit __DIR__+"warai_d/attack";
inherit __DIR__+"warai_d/neighbor";
inherit __DIR__+"warai_d/array_attack";
inherit __DIR__+"warai_d/display";
inherit __DIR__+"warai_d/lose";
inherit __DIR__+"warai_d/order_display";
inherit __DIR__+"warai_d/kill";
inherit __DIR__+"warai_d/attack_rate";
inherit __DIR__+"warai_d/automatch";
inherit __DIR__+"warai_d/horse_attack";
inherit __DIR__+"warai_d/siege_attack";
inherit __DIR__+"warai_d/match";
inherit __DIR__+"warai_d/guard";
inherit __DIR__+"warai_d/pursue";
// Types.c controls general properties of varous type of troops
inherit __DIR__+"warai_d/types";
// Apply.c controls applied the ability such as applied attack,
// etc. used for jimou
inherit __DIR__+"warai_d/apply";
inherit __DIR__+"warai_d/condition";
inherit __DIR__+"warai_d/jimou";

mixed check_move(object troop, object target);
int auto_action(int t_id)
{
        object o_troop,o_char;
        string c_id;
        mixed mtmp;
	
        mtmp=TROOP_D->get_troops(t_id,"chars");
        c_id=mtmp[0];
        o_char=CHAR_D->find_char(c_id);
        if(!objectp(o_char))
                return -1;
        o_troop=TROOP_D->find_troop(t_id);
        if(!objectp(o_troop))
                return -2;
        
	mtmp=TROOP_D->get_troops(t_id,"command");
        if(!mtmp)
        {
	   string p_side,p_area,p_point;
		
	   mtmp=([]);	
	   p_area=TROOP_D->get_troops(t_id,"area");
	   p_side=TROOP_D->get_troops(t_id,"side");
           if(p_side=="a")
	   {  mtmp["action"]="match";
              mtmp["target"]=point_tostring(MAP_D->get_city(p_area,"center")); 
           }
           else
		{   
//			int task_id,leader_troop;
//			string p_leader;
//			task_id=TROOP_D->get_troops(t_id,"task_id");
//		        p_leader=TASK_D->get_task(task_id,"att_leader");
//			leader_troop=CHAR_D->get_char(p_leader,"troop");
//			if(!leader_troop) return 0; // nothing to do
//			mtmp["action"]="pursue";
//			mtmp["aim"]=leader_troop;

			mtmp["action"]="guard";
              mtmp["position"]=point_tostring(MAP_D->get_city(p_area,"center")); 
              mtmp["range"]=random(2);
           }
           TROOP_D->set_troops(t_id,"command",mtmp);
         }   
         switch(mtmp["action"])
         {
            case "stay": return 0; // donothing
            case "match": 
                 do_command_match(t_id,mtmp);
                 return 1; 
            case "guard":
                 do_command_guard(t_id,mtmp);
                 return 2;
            case "pursue":
                 do_command_pursue(t_id,mtmp);
                 return 3;
            default: return -1;  // should not come here
         }
         return -1; // can't come here
}
mixed check_move(object troop, mixed target)
{
        int t_id, x, y, p_reng, too_tired, weather;
        object env;
        string a_id, m_here, m_side, *forbiden, tt;
        mixed p_soldier, t_here, pos;

        t_id = troop->get_id();
        if( !stringp(target) ) return "前面没路。\n";
        if( !target->is_gridroom() ) return "部队只能在战场上走．\n";
        env = target;
        pos = env->query_pos();
        a_id = env->query_aid();
	weather = AREA_D->get_area(a_id, "weather");
        m_here = MAP_D->get_map_cell(a_id, pos[1],pos[0],"m");
        p_soldier=TROOP_D->get_troops(t_id,"soldier");

	if( mapp(p_soldier) ){
		foreach(tt in keys(p_soldier)){
			forbiden = query_type(tt, "forbiden");
			if( !arrayp(forbiden) || !sizeof(forbiden) )
				forbiden = ({"※", });
			if( member_array(m_here, forbiden) != -1 )
				return query_type(tt,"name")+ "不能进入“"+m_here+"”的地形。\n";
		}
	}

        t_here=MAP_D->get_map_cell(a_id,pos[1],pos[0],"t");
        if(sizeof(t_here)){
           	m_side = TROOP_D->get_troops(t_id,"side");
           	if( m_side != (TROOP_D->get_troops(t_here[0],"side")) )
                	return "有敌兵，不能通行。\n";
        }

        if(sizeof(t_here)>=2){
               	return "前面有多支部队，要等它们疏通后才能行军。\n";
        }
	if (TROOP_D->get_troops(t_id, "conds"))
        { if (TROOP_D->get_troops(t_id, "conds")["confuse"])
        return "混乱中，无法行军。\n";
        }	
        env = environment(troop);  // other check should be before this
        pos = env->query_pos();
        a_id= env->query_aid();
        m_here = MAP_D->get_map_cell(a_id, pos[1],pos[0],"m");
        if(sizeof(p_soldier)){
		foreach(tt in keys(p_soldier)){
			if(p_soldier[tt]["energy"]<
TROOP_TYPE(tt)->query_energy_cost(m_here,weather,troop->query("zhenfa"))/2)
// /2 is used temporily, need modify later ********************
				too_tired = 1;
		}
                if(too_tired) return "部队太累了，无法行军．\n";
		foreach(tt in keys(p_soldier)){
			if(TROOP_D->get_troops(t_id,"sugong"))
			p_soldier[tt]["energy"]-=
TROOP_TYPE(tt)->query_energy_cost(m_here,weather,troop->query("zhenfa"))/4;
		else {
			p_soldier[tt]["energy"]-=
				TROOP_TYPE(tt)->query_energy_cost(m_here,weather,troop->query("zhenfa"))/2;
		}
		}
                TROOP_D->set_troops(t_id,"soldier",p_soldier);
        }
	troop_busy(t_id,MOV_BUSY_TIME,"部队正行军呢。\n");
	
        return 1;
}
int recover_eng(mixed soldier)
{       string p_type;
        int p_base,p_morale,p_train,p_energy;
        int p_point;
        p_type=soldier["type"];
        switch(p_type)
        {       case "cavalry" : p_base=4;break;
                default : p_base=2; break;
        }
        p_morale=soldier["morale"];
        p_train=soldier["train"];
        p_energy=soldier["energy"];
        p_point=p_base*((p_morale+p_train)/8+5)/10;
        p_energy+=p_point;
        if(p_energy>20)
                p_energy=20;
        return p_energy;
}
//:FUNCTION this is used to set a troop to busy, so
// the char in that troop can't give any order. hoho
void troop_busy(int t_id,int p_time,string msg) {
	string *chars;
	object o;
	if(!msg) msg="你的部队正忙呢。\n";
	chars=TROOP_D->get_troops(t_id,"chars");
	if(!sizeof(chars)) return;
	foreach(string ch in chars) {
		o=find_body(ch);
		if(objectp(o)) o->start_busy(p_time,msg);
	}
}
