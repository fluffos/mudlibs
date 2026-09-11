// ev_randdisapp.c 
// by fire on Nov 27, 1998
// this is the event for char disappear random
#define TESTTIME 10
#define THROUGHHOLD 50
void disappear(string p_id) {
	string area;
	object o;
	area=CHAR_D->get_char(p_id,"area");
        if(CHAR_D->get_char(p_id,"is_tmp")) return;
        if(CHAR_D->get_char(p_id,"task")) return;
	if(AREA_D->get_area(area,"leader")==p_id) return;
	o=CHAR_D->find_char(p_id);
	if(!objectp(o)) {
		SGSYS("Can't find "+p_id+"'s my body.");
		return;
	}
        switch(random(5))
        {   case 0:  o->responda("bye");break;
            case 1:  o->responda("wave");break;
            case 2:  o->responda("wake");break;
            case 3:  o->responda("xixi");break;
            case 4:  o->responda("hehe");break;
        }
        o->simple_action("$N离开了。\n");  
        CHAR_D->remove_npc_char(p_id);
        return;
}
void ran_disappear() // this is used for the leader to come every day
{
   string *list;
   object o;
   int i,sum,j;
   string p_id;
   list=CHAR_D->check_char("status",STATUS_ACTIVE);
   list=filter_array(list,(: CHAR_D->get_char($1,"task") == 0 :));
   list=filter_array(list,(: CHAR_D->get_char($1,"is_tmp") == 0 :));
   sum=sizeof(list);
   for(i=0;i<TESTTIME;++i)
   {
      j=random(sum);
      if(j>THROUGHHOLD)
      {
	   p_id=list[random(sum)];
	   if(objectp(find_body(p_id))) continue; // because this is a player
           o=CHAR_D->find_char(p_id);
           if(objectp(o))
           {
               switch(random(5))
               {   case 0:  o->responda("bye");break;
                   case 1:  o->responda("wave");break;
                   case 2:  o->responda("wake");break;
                   case 3:  o->responda("xixi");break;
                   case 4:  o->responda("hehe");break;
	       }
               o->simple_action("$N离开了。\n");  
            }
	    CHAR_D->remove_npc_char(p_id);
	    list-=({p_id});
	    sum--;
       } //if(j>THROUGHHOLD)
   }
}
