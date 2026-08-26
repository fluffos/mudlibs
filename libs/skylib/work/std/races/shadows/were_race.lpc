/* Werewolf Shadow *
*     Archana      */

object person;

void setup_shadow( object thing ) {
   shadow( thing, 1 );
   person = thing;
} /* setup_shadow() */

void destruct_shadow( object thing ) {
   if ( thing == this_object() )
      destruct( this_object() );
   else
      thing->destruct_shadow( thing );
} /* destruct_shadow() */

varargs int query_ac( string type, int damage, string zone ) {
   int amount;
   object attacker, weapon;
   string material;
   
   amount = (int)person->query_ac( type, damage, zone );
   
   attacker = (object)this_object()->query_attacker();
   
   if ( attacker ) {
      weapon = (object)attacker->query_weapon();
      if ( weapon && ( weapon != attacker ) )
         material = weapon->query_material();
         if ( ( type != "fire" ) && ( material != "silver" ) )
              return amount;
   }
   amount = amount + to_int( 0.95 *damage ); 
   return amount;
} /* query_ac() */   

int adjust_hp(int hp, object attacker) {
    int temp;
    
    temp = person->adjust_hp(hp, attacker );
    if(this_object()->query_property("dead")) { 
      return temp;
    }else{ 
     if(person->query_hp() < ((person->query_max_hp())/5) ){
       if(person->query_gender() == 0 ){   
         person->do_change(this_object());
       }else{
       if(person->query_hp() < ((person->query_max_hp())/2) ){  
        if(person->query_gender() > 0 ){    
         person->do_wolf(this_object());
         person->do_set(this_object()); 
       }else{
       return temp;   
      }
     }
    }
   }
 }
} 

