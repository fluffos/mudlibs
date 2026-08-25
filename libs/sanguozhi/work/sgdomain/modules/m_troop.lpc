// m_troop.c by fire on Jan 9 1998
#include <playerflags.h>
#include <move.h>
inherit NON_ROOM;
inherit M_SMARTMOVE;
inherit M_MESSAGES;
string short();
private int m_id;
string* get_arrival_msg()
{
	string p_name;
                mixed position;
                string p_area;
                p_area=TROOP_D->get_troops(m_id,"area");
        TROOP_D->set_troops(m_id,"room",file_name(environment(this_object())));
        position=TROOP_D->get_troops(m_id,"position");
        MAP_D->set_map_cell(p_area, position[1],position[0],"addtroop",m_id);
	p_name=TROOP_D->get_troops(m_id,"name");
	return ({p_name+"冲了过来．\n",
 p_name+"浩浩荡荡地开了过来．\n"});
}
string* get_departure_msg()
{
	string p_name;
	mixed position;
		string p_area;
		p_area=TROOP_D->get_troops(m_id,"area");
		position=TROOP_D->get_troops(m_id,"position");
	MAP_D->set_map_cell(p_area, position[1],position[0],"subtroop",m_id);
	p_name=TROOP_D->get_troops(m_id,"name");
        return ({p_name+"向$o开去．\n",
p_name+"在一阵喧闹中向$o离去了．\n"});
}
string *get_player_message(string message, mixed arg) {
    string *mess;
    if ( message == "leave" )
      {
    mess = get_departure_msg();
      }
    else if ( message == "enter" )
      {
    mess = get_arrival_msg();
      }
    return action( ({ this_object() }), mess, arg);
}
string query_final_exit_value(string str, int is_normal)
{
  string ret;
  if((!(ret = ::query_exit_value(str, is_normal)) || ret[0] == '#')
     && environment())
    return environment()->query_exit_value(str, is_normal);
  return ret;
}
int can_travel()
{
  return 1;
}
string show_obj() {
	string ret="\n";
	object env;
	object *obs;
	string tmp;
	env=environment(this_object());
	if(!objectp(env)) return "";
	obs=all_inventory(env);
	if(!sizeof(obs)) return "";
	foreach(object o in obs){
		if(!o->is_troop()) continue;
		tmp=o->query_in_room_desc();
		if(o==this_object())
			tmp="%^H_GREEN%^□%^RESET%^"+tmp;
		else
			tmp="  "+tmp;
		ret=ret+tmp+"\n";
	}
	return ret;
}
void notify_move()
{
    object *inv;
    object curr;
	object env;
    inv = all_inventory(this_object());
	if(!sizeof(inv)) return;
	env = environment(this_object());
	if(!objectp(env)) return;
    foreach(curr in inv)  {
        if(curr->query_link())
			tell(curr,sprintf(
               "%%^ROOM_EXIT%%^%s [位置：%s可行军方向：%s]%%^RESET%%^\n", 
			   env->short(),env->query_str_pos(), env->show_exits()));
        if (!curr->test_flag(F_BRIEF))
		   tell(curr, env->long());
		tell(curr,show_obj());
    }
}
int is_vehicle()
{
  return 1;
}
void do_looking(int forced_look)
{
    string p_name;
	object env;
	env=environment(this_object());
	if(!objectp(env)) return;
	p_name=query_in_room_desc();
    this_look_is_forced = forced_look;
	printf("%%^ROOM_EXIT%%^%s [位置：%s可行军方向：%s]%%^RESET%%^\n", 
			   env->short(),env->query_str_pos(), env->show_exits());
	//    printf("%s [exits: %s]\n", environment(this_object())->long(),
//environment(this_object())->show_exits());
//    write((get_location_description()));
	if(this_look_is_forced || (!this_body()->test_flag(F_BRIEF)));
		write(env->long());
	write(show_obj());
		/*    switch(random(3))
    {
        case 0: write("你正运筹帷幄于"+p_name+"中．\n"); break;
	case 1: write("你正巡视于"+p_name+"中．\n"); break;
	case 2: write("你高马阔步于"+p_name+"中．\n"); break;
    } */
}
varargs string inventory_recurse(int depth, mixed avoid) 
{
    return "";
}
void put_id(int p_id)
{
        m_id=p_id;
}
int get_id()
{
        return m_id;
}
int is_troop()
{
        return 1;
}
string long()
{
        string p_ret;
        string* chars;
	object o;
        int i, sum;
	mixed soldier;
        p_ret=TROOP_D->get_troops(m_id,"name");
        p_ret+="\n军中大将：\n";
        
        chars=TROOP_D->get_troops(m_id,"chars");
        for(i=0;i<sizeof(chars);++i)
        {
		o=CHAR_D->find_char(chars[i]);
		if(objectp(o))
		{
			if(environment(o)!=this_object())
				o->move(this_object());
	                p_ret+=o->in_room_desc()+"\n";
		}
        }
	soldier=TROOP_D->get_troops(m_id,"soldier");
	if(sizeof(soldier))
	{	string *s_typ;
		s_typ=keys(soldier);
		sum=sizeof(soldier);
		p_ret+=" 兵种　  数量　 训练  士气　机动力\n";	
		for(i=0;i<sum;++i)
		{
                        p_ret+=sprintf(" %s  %6d %s %4d %s %4d %s %4d %s\n",
			WARAI_D->get_soldier(s_typ[i],"name"),
			soldier[s_typ[i]]["number"],
			M_OUT->get_disp_color(soldier[s_typ[i]]["train"]),
			soldier[s_typ[i]]["train"],
			M_OUT->get_disp_color(soldier[s_typ[i]]["morale"]),
			soldier[s_typ[i]]["morale"],
			M_OUT->get_disp_color(soldier[s_typ[i]]["energy"]*5),
			soldier[s_typ[i]]["energy"],"%^RESET%^");
		}
	}
        return p_ret;
}
string look_in( string relation )
{
        return "";
}
string in_room_desc()
{
        return query_in_room_desc();
}

void setup(int p_id)
{
    string c_id;
    put_id(p_id);
    clear_id();
    c_id=TROOP_D->get_troops(p_id,"name");
    set_id("troop"+p_id, c_id);
   set_relations("on");
    set_unit("个");
    set_max_capacity(VERY_LARGE*20);
    
    set_in_room_desc(c_id+"(troop"+p_id+")");
}
// dont' clean me, i can maintain myself
int query_clean_up() {
	return 1;
}