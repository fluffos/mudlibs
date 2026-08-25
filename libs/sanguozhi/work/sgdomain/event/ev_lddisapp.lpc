// ev_lddisapp.c 
// by fire on July 23, 1998
// this is the event for area leader disappear regular
void dis(string a_id) {
   string c_id;
   int st;
   object o_c;   
   if(!AREA_D->get_area(a_id,"meeting")) return;
   c_id=AREA_D->get_area(a_id,"leader");
   if(!c_id) return;
   if(CHAR_D->get_char(c_id,"task")!=TASK_NONE) return;

   o_c=CHAR_D->find_npc_char(c_id);
   if(objectp(o_c))
   {
      o_c->simple_action("$N一拱手道：时辰不早，诸位有事明日再谈。\n");
      o_c->simple_action("$N起身快步离开了。\n");
      CHAR_D->remove_npc_char(c_id);
   }
    
}
void leader_disappear() // this is used for the leader to come every day
{
        string *list;
        list=AREA_D->list_areas();
        foreach(string p_id in list)
        {
           call_out("dis",0,p_id);
        }
}
