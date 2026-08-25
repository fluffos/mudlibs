/* Hamlet, November 1995 -- Things that respond to gives. */

#define MONEY_HAND "/obj/handlers/money_handler"

int likesgive = 0;
string *givefunc = ({ });
mixed *givecond = ({ });
object *oldinv;
int value = 0;
int RECALC_VALUE = 1;

void give_init() {
  if(likesgive) {
    add_action("give_trigger","give");
    add_action("give_trigger","put");
    add_action("give_trigger","slip");
  }
}

/* This function just does validity checking and then stores values */
varargs void respond_give(string func, mixed *to_match) {
  int VALID = 0;
  
  if(!func)  return;
  
  if(to_match && !sizeof(to_match))
    to_match = 0;
      
  if(!to_match)  VALID = 1;  /* if no to_match, we unconditionally call */
    
  if(!VALID && stringp(to_match))  VALID = 1;  /* Match by name */
      
  if(!VALID && to_match[0] == "unconditional")  VALID = 1; /* see !to_match */
      
  if(!VALID && (to_match[0] == "name") && (sizeof(to_match) == 2) )
    VALID = 1;  /* same as the stringp case */
      
  if(!VALID && (to_match[0] == "property") && (sizeof(to_match) > 1) )
    VALID = 1;  /* match by property */

  if(!VALID && (to_match[0] == "money") && (sizeof(to_match) > 1) ) {
    if(sizeof(to_match) > 2)
      to_match = ({ to_match[0] , MONEY_HAND->
                   query_total_value(to_match[1..sizeof(to_match)-1]) });
    VALID = 1;  /* match by augmented money */
  }
          
  if(VALID) { /* Turn stuff on */
    likesgive = 1;
    givefunc += ({ func });
    if(to_match)  givecond += ({ to_match });
    else givecond += ({ 0 });
  }
}

void give_trigger(string str) {
  int i;
  
  oldinv = all_inventory(this_object());
  value = 0;
  
  if(RECALC_VALUE && sizeof(oldinv))
    for(i=0;i<sizeof(oldinv);i++)
      if(oldinv[i]->query_name() == "coin") {
        value = oldinv[i]->query_value();
        break;
      }
      
  call_out("give_response",2,this_player());
  return 0;
}

void give_response(object player) {
  int i,j;
  object *inv;
  object *inv2 = ({ });
  string namematch;
  int MATCHBYNAME = 0;

  /* These next two shouldn't be possible, but let's be paranoid */  
  if(!sizeof(givefunc))  return;
  if(!player)  return;

  for(j=0;j<sizeof(givecond);j++) {
    /* unconditional */  
    if(!givecond[j]) {
      if(sizeof(all_inventory(this_object())) - sizeof(oldinv))
        call_other(this_object(),givefunc[j],player);
      continue;
    }
  
    /* Match by name */  
    MATCHBYNAME = 0;
    if(stringp(givecond[j])) {
      namematch = givecond[j];
      MATCHBYNAME = 1;
    }
    else if(givecond[j][0] == "name") {
      namematch = givecond[j][1];
      MATCHBYNAME = 1;
    }
    
    if(MATCHBYNAME) {
      inv = find_match(namematch, this_object());
      for(i=0;i<sizeof(oldinv);i++) /* looks stupid, but it's the best way */
        inv -= ({ oldinv[i] });
      if(sizeof(inv))
        call_other(this_object(),givefunc[j],player,inv);
      continue;
    }

    /* This is truly unconditional */  
    if(givecond[j][0] == "unconditional") {
      if(sizeof(all_inventory(this_object())))
        call_other(this_object(),givefunc[j],player);
      continue;
    }
  
    /* Match by property? */  
    if(givecond[j][0] == "property") {
      inv = all_inventory(this_object());
      for(i=0;i<sizeof(oldinv);i++) /* looks stupid, but it's the best way */
        inv -= ({ oldinv[i] });
      
      inv2 = ({ });
      if(sizeof(inv)) 
        for(i=0;i<sizeof(inv);i++) 
          if(sizeof(givecond[j]) == 2) {
            if(inv[i]->query_property(givecond[j][1]))
              inv2 += ({ inv[i] });
          }
          else {
            if(inv[i]->query_property(givecond[j][1]) == givecond[j][2])
              inv2 += ({ inv[i] });
          }
        
      if(sizeof(inv2))
        call_other(this_object(),givefunc[j],player,inv2);
      continue;
    }
    
    /* Match on money */
    if(givecond[j][0] == "money") {
      inv = all_inventory(this_object());
      for(i=0;i<sizeof(inv);i++)
        if(inv[i]->query_name() == "coin")
          break;
      
      if(i<sizeof(inv)) {
        if( (inv[i]->query_value() - value) >= givecond[j][1] ) {
          RECALC_VALUE = 1;
          call_other(this_object(),givefunc[j],player,({ inv[i] }));
        }
        else 
          RECALC_VALUE = 0;
      }
    }
  }
  
  return;    
}

mixed tell_me_gives() {
  return ({ givefunc, givecond });
}
