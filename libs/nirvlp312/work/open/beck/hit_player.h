mapping Objects;
mixed *specialprot;
int armor_res, magic_class, magic_res;

modify_armor_res(num){ armor_res += num; }
modify_magic_class(num){ magic_class += num; }
modify_magic_res(num){ magic_res += num; }

query_armor_res(){ return armor_res; }
query_magic_class(){ return magic_class; }
query_magic_res(){ return magic_res; }

modify_specialprot(type,class,res){
   string cat, subcat;
   int i;
   if(!specialprot) specialprot = ({ });
   if(sscanf(type, "%s|%s",cat,subcat) !=2) return;
   if(cat != "other") return; 
   if(member_array(type,specialprot) != -1){
      for(i=0;i<sizeof(specialprot);i++){
         if(type == specialprot[i]){
            specialprot[i+1] = class;
            specialprot[i+2] = res;
            return;
         }
      }
   }
   specialprot += ({type,class,res});
}

query_specialprot_res(type){
   int i;
   if(!specialprot) return 0;
   if(member_array(type,specialprot) != -1){
      for(i=0;i<sizeof(specialprot);i++){
         if(type == specialprot[i]){
            return specialprot[i+2];
         }
      }
   }
   return 0;
}

query_specialprot_class(type){
   int i;
   if(!specialprot) return 0;
   if(member_array(type,specialprot) != -1){
      for(i=0;i<sizeof(specialprot);i++){
         if(type == specialprot[i]){
            return specialprot[i+1];
         }
      }
   }
   return 0;
}

void RegisterObject(object gear, mixed *params){
   if(Objects == 0){ Objects = ([ ]); }
   Objects[gear] = params;
}

RemoveObject(object gear){
   if(Objects == 0){ Objects = ([ ]); }
   Objects[gear] = 0;
}




/*
 * This function is called from other players when they want to make
 * damage to us. We return how much damage we received, which will
 * change the attackers score. This routine is probably called from
 * heart_beat() from another player.
 */
hit_player(dam1, type1, dam2, type2,zap) {
   int i,dam,dam3,ac_tmp;
   int type1class,type2class,type1res,type2res,j,temp;
   string cat,subcat;
   mixed *armors2;
   object *armors;
   object pro_object;   /* paladin weapon pro & combat method object */
   object templar_ob; /*templar object*/
   if(dieing) {
      if(dieing < 8) return 0;
      dieing +=1;
   }
   /* if we are in the death sequence do not allow access to hit_player() */
   if(!is_npc)
      if(!this_object()->query_interactive()) {
         say(cap_name+" is disconnected.\n");
         stop_fight(); if(this_player()) this_player()->stop_fight();
         return 0;
      }
   if (this_player() && this_player() != this_object() && this_player()->query_level() < EXPLORE) {
      /* -= Protection =- */  
      if ( this_player()->is_player() &&
         this_player()->query_attack() != this_object() &&
         !this_player()->valid_attack( this_object())){
    /* bad attack, could be logged */
         write( "Your attack fails.\n");
         return 0;
      }
      if(this_object()->is_player() &&
         !is_npc && !this_object()->query_interactive())
         return 0;
      if ( attacker_ob == alt_attacker_ob || !alt_attacker_ob)
         attacked_by( this_player());
    /* -= Crime =- */
      if ( this_player()->query_level() < EXPLORE &&
         (!is_npc || this_object()->crime_to_attack()))
         if(!this_object()->query_crime() && !this_player()->query_crime())
            this_player()->set_crime();
   }
   if (level >= 21 && !is_npc)   /* You can't hit a wizard ! */
      return 0;
   if(ghost == 1) return 0; /* You cannot hit the dead! */
/* Feldegast's armor_special 11/12/98 */
   ac_tmp=armor_class;

   if(head_armor)
      ac_tmp+=head_armor->call_armor_special(this_object());

   if (!is_npc && armor_class > 9) {
      int rz;
      rz = random(9-armor_class);
      ac_tmp -= rz;
   }
/*
   if (!is_npc && armor_class > 9) {
      ac_tmp = 9;
   } 
   else {
      ac_tmp = armor_class;
   }
*/
   if(!is_npc && this_object()->query_pregnancy()){
      i = age - this_object()->query_pregnancy();
      i = i/5000;
      ac_tmp = ac_tmp - i;
   }
 
/************************************/
/*    BEGIN PALADIN ADDITIONS       */
/************************************/
/*   if(!is_npc && this_object()->query_guild_name()=="paladin") {*/
   pro_object = present("pro_object", this_object());
   if(pro_object && paladin_shield && pro_object->query_combat_method() == 2) {
     ac_tmp += call_other(paladin_shield, "shield_bonus", pro_object);
   }
/************************************/
/*     END PALADIN ADDITIONS        */
/************************************/
/***********************************/
/* START TEMPLAR ADD              */
/**********************************/
   if(!is_npc && this_object()->query_guild_name()=="Knights Templar") {
      templar_ob = present("KnightTemplar", this_object());
      if(templar_ob)
         ac_tmp += templar_ob->skill_check_def();
   }
/***********************************/
/*  END TEMPLAR ADD                */
/***********************************/
/***********************************/
/*  BEGIN ADDITIONS FOR MULTIPLE   */
/*  TYPES OF DEFENSE               */
/*  Coded by Beck                  */
/***********************************/
   /* If there is no damage dont need to call armor */
   if(dam1){ 
      /* If not valid attack type, make attack type physical */ 
      if(type1){
         if(sscanf(type1, "%s|%s",cat,subcat) !=2){
            if(type1 != "physical" && type1 != "magical") type1 = "physical";
         }
         else if(cat != "other") type1 = "physical";
      }
      else type1 = "physical";
   }

   /* If there is no damage dont need to call armor */
   if(dam2){    
      if(type2){
         if(sscanf(type2, "%s|%s",cat,subcat) !=2){
            if(type2 != "physical" && type2 != "magical") type2 = "physical";
         }
         else if(cat != "other") type2 = "physical";
      }
      else type2 = "physical";  
   }
   
   /* If both parameters are the same, combine them for efficiency */  
   if(type2 == type1){
      dam1 = dam2 + dam1;
      type2 = 0;
      dam2 = 0;
   }

   /* If there is no damage dont need to call armor */
   if(dam1 || dam2){
      /* make default armor class under old rules part of physical defense */
      if(type1 == "physical"){
         type1class = ac_tmp;
         type1res = armor_res;
      }
      else if(type1 == "magical"){
         type1class = magic_class;
         type1res = magic_res;
      }   
      else if(specialprot){
         if(member_array(type1,specialprot) != -1){
            for(i=0; i<sizeof(specialprot); i++){
               if(specialprot[i] == type1){ 
                  type1class = specialprot[1+1];
                  type1res = specialprot[i+2];
               }
            }
         }
      }
      else type1class = 0;

      if(type2){
         if(type2 == "physical"){
            type2class = ac_tmp;
            type2res = armor_res;
         }
         else if(type2 == "magical"){
            type2class = magic_class;
            type2res = magic_res;
         }   
         else if(specialprot){
            if(member_array(type2,specialprot) != -1){
               for(i=0; i<sizeof(specialprot); i++){
                  if(specialprot[i] == type2){ 
                     type2class = specialprot[1+1];
                     type2res = specialprot[i+2];
                  }
               }
            }
         }
         else type2class = 0;
      }   
      /* Add in individual object modifications from mapping Objects */
      if(Objects){
         armors = keys(Objects);
         for(i=0; i<sizeof(armors); i++){
            if(Objects[armors[i]]){
               armors2 = Objects[armors[i]];
               if(member_array(type1,armors2) != -1){
                  for(j=0; j<sizeof(armors2); j++){
                     if(type1 == armors2[j]){
                        type1class += armors2[j+1];
                        type1res += armors2[j+2];
                        if(armors2[j+3]){
                           temp = call_other(armors[i],armors2[j+3]);
                           type1res += temp/100;
                           type1class += temp - ((temp/100)*100);  
                        }
                     }
                  }
               }
               if(type2){
                  if(member_array(type2,armors2) != -1){
                     for(j=0; j<sizeof(armors2); j++){
                        if(type2 == armors2[j]){
                           type2class += armors2[j+1];
                           type2res += armors2[j+2];
                           if(armors2[j+3]){
                              temp = call_other(armors[i],armors2[j+3]);
                              type2res += temp/100;
                              type2class += temp - ((temp/100)*100); 
                           }
                        }
                     }
                  }
               }
            }     
         }
      }

      /* checks for ac limits */
      dam3 = dam1 + dam2;
      if(type1res > 100) type1res = 100;
      if(type2res > 100) type2res = 100;

      /* Isnt needed right now   */
      /*
      if(type1class > 9 && !is_npc) type1class = 9;
      if(type2class > 9 && !is_npc) type2class = 9;
      if((type2class + type1class) > 9) type2class = 0;
      */

      /* Calculate new damage */
      type1res = 100 - type1res;
      dam1 = type1res*dam1;
      dam1 = dam1/100;
      dam1 -= random(type1class +1 );
      type2res = 100 - type2res;
      dam2 = type2res*dam2;
      dam2 = dam2/100;
      dam2 -= random(type2class + 1);
   }
   say("Type1: "+type1+" Dam1: "+dam1+" Res1: "+(100-type1res)+"\n");
   say("Type2: "+type2+" Dam2: "+dam2+" Res2: "+(100-type2res)+"\n");
   dam = dam2 + dam1;
/*   dam -= random(ac_tmp + 1); */

/*******************************/
/*  END ADDITIONS FOR MULTIPLE */
/*  TYPES OF DEFENSE           */
/*******************************/

  lucky = random(500);
  if(is_npc) luck = 0;
  if (lucky < luck) {
    tell_object(this_object(), "Your luck comes through for you.\n");
    if (luck < 12)
       dam = dam/2;
    if (luck > 11 && luck <16)
       dam = dam/3;
    if (luck > 15)
       dam = dam/5;
  }
   if (lucky > 494)
    {
      dam = dam3*5/3;
      if(attacker_ob)
      tell_object(this_object(), attacker_ob->query_name() + " hits you with a crushing blow.\n");
      }
  if(hit_point<0 && dam <=0) dam = 1;
  if(hit_point<0) hit_point = 0;
  if (dam <= 0)
    return 0;
/* PUT a cap on damage a player can do in one hit. */
  if(!zap) zap = attacker_ob;
  if(attacker_ob && zap && zap->query_level() < EXPLORE){
     if (is_npc && dam > 50 && attacker_ob->query_level() < EXPLORE){
        if (attacker_ob->is_player()){
           if(dam > 56) dam=56;
        }
     }
  }
/* penalize multiple calls to hit_player() by the same player in one hb */
  if(this_player() && is_npc) { 
        if(this_player()->query_level() > 99) write("DAMAGE = "+dam+" \n");
     if(h_check==this_player()) { hcnum += 1; 
        if(hcnum > 2) dam = dam/(hcnum+2);
        if(this_player()->query_level() > 99) write("DAMAGE REDUCED to "+dam+" hcnum="+hcnum+"\n");
     }}
  if (dam > hit_point+1)
    dam = hit_point+1;
  hit_point = hit_point - dam;
/*
    if(name=="numberone") say("DAMAGE TO HITPLAYER DONE="+dam+"\n");
*/
  if (hit_point<0) {
    object corpse;
    /* We died ! */
    dieing = 1;
    if (hunter)
      call_other(hunter, "stop_hunter");
    hunter = 0;
    hunted = 0;
    say(cap_name + " died.\n");
    /* If this is a player, log the death for future reference */
    if(!is_npc && environment(this_object())->query_spar_area())
      log_file("DEATHS","Spar-> ");
    if (!is_npc) 
      if (attacker_ob)
    log_file("DEATHS", ctime(time()) + " " + name + " " + experience + " exp " + money + " gold killed by " +
		 call_other(attacker_ob, "query_real_name", 0) + ".\n");
       else
           {
	log_file("DEATHS", ctime(time()) + "  " + name + " " + experience + " exp "+money + " gold - killer unknown.\n");
        if(this_player()) log_file("DEATHS","this_player is "+this_player()->query_real_name() +"   "+this_player()->query_name()+"\n");
           }
   if (!is_npc)
   {
tell_object(this_object(), "\n\nYou feel very weak as your badly damaged body falls to the ground to die.\n");
    if(!environment(this_object())->query_spar_area()) {
    experience = (experience * 3) / 4;  /* Take away 1/4 of exp. */
     lower_attrib();
    }
   call_other(this_object(), "clear_crime");
     call_other(this_object(),"rm_pk",0);
     }
    if (max_hp)
      hit_point = max_hp/3;
    else
      hit_point = 10;
    corpse = clone_object("obj/corpse");
    call_other(corpse, "set_name", name);
    call_other(corpse, "set_corpse_level", level);
    if(!is_npc) { set_ghost(1);
    corpse->move_object(resolve_ob(environment(this_object()))); }
    transfer_all_to(corpse);
    if(!is_npc) set_ghost(0);
    if (!attacker_ob)
      attacker_ob = alt_attacker_ob;
    if (!is_npc) {
    see_if_other(3); /* prevent cheating */
      this_object()->save_me();
/*
      attacker_ob = 0;
      alt_attacker_ob = 0;
 zero out attackers, hopefully will cure death bug.*/
    }
    /* The player killing us will update his alignment */
    /* and experience if he exists. */
    /* Note that you get no experience for killing other players! */
    /* that last line was not true before.. it is now. */
    else if(attacker_ob && is_npc) {
      int wa_bonus, exp_diff, exp_bonus, base_bonus;
       object party;
      call_other(attacker_ob, "add_alignment", ADJ_ALIGNMENT(alignment));
      /* Give some more experience for staying in your alignment
       * All the following basically works out to
       * exp_bonus = abs(monster's align - player's align)/75000 * exp;
       * Of course we can't just say that because of underflow problems.
       */
      if (is_npc && experience > 1000000) {
/*
      log_file("EXTRA_EXP", name + " " + creator(this_object()) + call_other(attacker_ob, "query_name",0) + "\n");
*/
	 experience = 1000000;
	  }
      exp_diff = (alignment - call_other(attacker_ob,"query_alignment",0));
      if (exp_diff < 0)
	exp_diff = -exp_diff;   /* Get absolute value */
      exp_diff /= 10;   /* Scale this down so we don't overflow! */
      exp_bonus = experience / 100;
      exp_bonus *= exp_diff;
      exp_bonus /= ALIGN_EXP_DIVISOR;
      /* Base bonus regardless of alignment is experience/75 */
      base_bonus = experience/EXP_DIVISOR;
      /* Don't let the alignment bonus exceed 1/2 the base bonus */
      if (exp_bonus > base_bonus/2)
	exp_bonus = base_bonus/2;
      exp_bonus += base_bonus;
      wa_bonus = weapon_class * armor_class * WA_FACTOR;
      if (wa_bonus > base_bonus/3)
	   wa_bonus = base_bonus/3;
       exp_bonus += wa_bonus;
       party=present("party object", attacker_ob);
       if(party) exp_bonus = 24*exp_bonus/30;
       if(!no_exp_value) {
       if (party) party->share_exp(exp_bonus);
       if(!party)
       call_other(attacker_ob, "add_exp", exp_bonus);
       }
    }
    corpse->move_object(resolve_ob(environment(this_object())));
    dieing = 0;
    if (!call_other(this_object(), "second_life", 0))
      destruct(this_object());
  }
   if(this_player()&& is_npc)h_check=this_player();
  return dam;
}