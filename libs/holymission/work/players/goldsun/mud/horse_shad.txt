
/* horseshadow */

inherit "/players/whisky/obj/std_shadow";


hit_player(dam,kind)
{
 if (kind == 0 || kind == 7)
 {  
      say("But the horse protects "+me->query_name()+".\n");
      tell_object(me,"But your horse parries the hit of "+
                  this_player()->query_name()+" with it's hooves.\n");
      return 0;
 }
	return me->hit_player(dam,kind);
}

   
void end_shadow()
{
   tell_object(me,"You falls down from your horse.\n");
   ::end_shadow();
}

int horse_shad() 
{ 
    return 1; 
}

