// m_charaction.c by fire on Dec 1998
// this is used to handle npc chars auto action
nosave protected string *emotes;
private int m_heartworking=1;
private int m_life=0;
void add_hook(string, function);
string find_target() {
    object *who = all_inventory(environment());
    object o;
    if (!sizeof(who)) 
        return this_object()->query_id()[0];
    o=who[random(sizeof(who))];
    if(!o->is_living()) return this_object()->query_id()[0];
    return o->query_id()[0];
}
void do_my_semote()
{
    string which ;
    string *rules;
    string rule;
    string comm, token;

    if(!sizeof(emotes)) emotes=SOUL_D->list_emotes();
    which=emotes [ random ( sizeof (emotes) ) ];

    rules = keys(SOUL_D->query_emote(which));

    rule = rules[random(sizeof(rules))];
    if (!environment()) return;
    comm = which;
    foreach (token in explode(rule, " ")) {
        comm += " ";
        switch (token) {
        case "OBJ":
        case "LIV":
            comm += find_target();
            break;
        default:
            comm += token;
        }
    }
    this_object()->responda(comm);
}
void do_my_moving()
{
   string p_id;
   string p_area;
   string *obvious_exits;
   int random_exit,i;
   object env;
   string my_exit,fn;
   p_id=this_object()->query_primary_id();
   if(CHAR_D->get_char(p_id,"task")) return ; // can't move in task
   p_area=CHAR_D->get_char(p_id,"area");
   if(AREA_D->get_area(p_area,"leader")==p_id) return; // leader dontwander

   env=this_object()->query_room();
   if(!objectp(env)) return;

   obvious_exits=env->query_exit_directions();

   i = sizeof(obvious_exits);
   if(!i) {return;}

   random_exit = random(i);

   my_exit = obvious_exits[random_exit];

   fn=env->query_exit_value(my_exit);
   if(!fn) return;
   if(!objectp(find_object(fn))) return;
   this_object()->responda("go "+my_exit);
}
int valid_check()
{
    object env;
    env=environment(this_object());
    if(!objectp(env)) {
        SGSYS(this_object()->short()+"没有环境。");
        return 0;       
    }
    return 1;
}
void my_charaction()
{
   int act;
   act=random(5);
   if(random(m_life)>10) {
	("/sgdomain/event/ev_randdisapp")->disappear(this_object()->query_primary_id());
	return;
   }
   switch(act)
   {
      case 0:
/*	switch(random(10)) {
	case 0:
	    "/sgdomain/event/ev_npc_move"->npc_move(this_object()->query_primary_id());
		return;
	case 1:
		(EV_POSITION)->npc_aut_localposition(this_object()->query_primary_id());
	    return;
	case 2:
		(EV_LEAVE)->auto_leave(this_object()->query_primary_id());
	    return;
	case 3:
		if(random(3)==0) // make the disappear' probility much less
			("/sgdomain/event/ev_randdisapp")->disappear(this_object()->query_primary_id());
	    return;

	} */
      case 1:
      case 2:
          do_my_semote();
          return;         
      case 3:
      default:
          do_my_moving();
   }
}
void start_heart()
{
   m_heartworking=1;
}
void stop_heart()
{
   m_heartworking=0;
//   remove_call_out("my_heart");
}

void my_clean() 
{
   string p_id;
   object env;
   p_id=this_object()->query_primary_id();
   if(!CHAR_D->get_char(p_id,"task")) {
       env=environment(this_object());
       env->clean_up();         
   }
}
void my_heart()
{
//    call_out("my_heart",random(90)+30);
//    add_hook("remove",(: stop_heart :));
    m_life++;
    if(!m_heartworking) return; // no heart
    if(valid_check())
    {  if(random(10)==0) 
          { 
//          my_clean();  // my_clean may cause more cpu burden
            return;
          }
       my_charaction();
    }
    else
       this_object()->remove();
}

int query_life() {
	return m_life;
}