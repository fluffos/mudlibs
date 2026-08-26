/*  Vampire Shadow *
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
         if ( ( material != "wood" ) )
              return amount;
   }
   amount = amount + to_int( 0.95 *damage ); 
   return amount;
} /* query_ac() */   

int attack_ob(object thing){
    object *symbols = filter (deep_inventory (thing) ,(:$1->query_property ("holy symbol") :));
    
    if(sizeof(thing->effects_matching("mouth.smell.garlic"))){
        
     this_object()->do_command(": sniffs the air carefully before screaming about garlic and running away.");
      
     this_object()->run_away();
     return 0;
    }else{ 
     if(sizeof (symbols)){
      this_object()->do_command(": notices your holy symbol and with a look of sheer terror runs away.");
      tell_creator(find_living("archana"), "symbols: %O\n", symbols); 
      this_object()->run_away();
     return 0; 
     }else{
       return 1;
      /*return this_object()->attack_ob(thing);*/
     }
   }   
 }/*attack_ob()*/    
        

