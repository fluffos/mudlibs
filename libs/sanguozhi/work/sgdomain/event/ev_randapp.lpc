// ev_randapp.c 
// by fire on Nov 27, 1998
// this is the event for char appear random
#define TESTTIME 5
#define THROUGHHOLD 100

void app(string p_id) {
	object o;
	if(CHAR_D->get_char(p_id,"is_tmp")) return;
	if(CHAR_D->get_char(p_id,"type")==TYPE_PLAYER) return;

	if(stringp(CHAR_D->get_char(p_id,"room"))) return;
	CHAR_D->appear(p_id,CHAR_D->get_char(p_id,"area"));
	o=CHAR_D->find_char(p_id);
        if(!objectp(o)) return;

	if(objectp(o))
      	{
           switch(random(5))
           {   case 0:  o->responda("xixi");break;
               case 1:  o->responda("hi");break;
               case 2:  o->responda("bow");break;
               case 3:  o->responda("hehe");break;
               case 4:  o->responda("grin");break;
           }
       }
}

void ran_appear() 
{
	int i;
	for(i=0;i<10;++i)
		app(CHAR_D->pick_char());

}
