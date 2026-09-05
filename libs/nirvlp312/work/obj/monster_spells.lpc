/* Extra Spell functionality for monsters
 * Illarion 6.10.04
 */

inherit "/obj/monster";
#define EMOTER(a,b) (string)call_other("/bin/std","x",a,b)
#define ANSI(x) (string)call_other("/obj/monitor","replace_ansi",x)
#define NONPHYS 3/2;

mixed *spells;
status multi_cast;

mixed *query_spell_info(string name) {
  int x,s;
  if(!spells)
    return 0;
  s=sizeof(spells);
  for(x=0;x<s;x++)
    if(spells[x][0]==name)
      return spells[x];
  return 0;
}

mixed *query_spells() {
  int s;
  string *spnames;
  if(!spells)
    return 0;
  s=sizeof(spells);
  spnames=allocate(s);
  while(s--)
    spnames[s]=spells[s][0];
  return spnames;
}

/* Redid this part because calling m_decode in /obj/monitor
   directly would eat the #s from the string */
string process_ansi(string str) {
  string *words,as;
  int s;
  if(!str)
    return 0;
  words=explode(str,"$");
  s=sizeof(words);
  while(s--)
    if(as=ANSI(words[s])) {
      words[s]=as;
    }
  return implode(words,"");
}

varargs status add_spell(string name, string mess_target, string mess_room,
                        int chance, mixed damage, mixed type, status hit_all_attackers,
                        string ex_fun, object ex_ob) {
  mixed *nspell;
  if(!name)
    return 0;
  if(chance <= 0 || chance > 100)
    return 0;
  if(!spells)
    spells=({});
  if(query_spell_info(name))
    return 0;
  nspell=allocate(9);
  nspell[0]=name;
  nspell[1]=process_ansi(mess_target);
  nspell[2]=process_ansi(mess_room);
  nspell[3]=chance;
  if(intp(damage))
    nspell[4]=({damage});
  else if(pointerp(damage))
    nspell[4]=damage;
  else
    return 0;
  if(!type)
    nspell[5]=({"physical"});
  else if(stringp(type))
    nspell[5]=({type});
  else if(pointerp(type))
    nspell[5]=type;
  else
    return 0;
  if(sizeof(nspell[4])!=sizeof(nspell[5]))
    return 0;
  nspell[6]=hit_all_attackers;
  if(ex_fun) {
    nspell[7]=ex_fun;
    if(ex_ob && objectp(ex_ob))
      nspell[8]=ex_ob;
    else
      nspell[8]=this_object();

  } else {
    nspell[7]=0;
    nspell[8]=0;
  }
  spells+=({nspell});
  return 1;
}

status remove_spell(string name) {
  mixed *rspell;
  if(!spells)
    return 0;
  rspell=query_spell_info(name);
  if(rspell) {
    spells-=({rspell});
    return 1;
  }
  return 0;
}

status set_multi_cast(status x) {
  if(x) 
    multi_cast=1;
  else
    multi_cast=0;
}

int *rand_dam(int *idam) {
  int *ndam;
  int s,x;
  s=sizeof(idam);
  ndam=allocate(s);
  for(x=0;x<s;x++)
    ndam[x]=1+random(idam[x]);
  return ndam;
}
void execute_spell(mixed *cur_spell,object target,object room) {
  int dam;
  if(!cur_spell[6]) {
    if(cur_spell[1])
      tell_object(target,EMOTER(cur_spell[1],target));
    if(cur_spell[2])
      tell_room(room,EMOTER(cur_spell[2],target),({this_object(),target}));
    dam=(int)target->do_damage(rand_dam(cur_spell[4]),cur_spell[5]);
    if(cur_spell[7])
      call_other(cur_spell[8],cur_spell[7],target,room,dam);
  } else {
    object *ppl;
    int s,x;
    ppl=all_inventory(room);
    s=sizeof(ppl);
    if(cur_spell[2])
      tell_room(room,EMOTER(cur_spell[2],target),({this_object()}));
    for(x=0;x<s;x++) {
      if((object)ppl[x]->query_attack() == this_object()) {
        dam=(int)ppl[x]->do_damage(rand_dam(cur_spell[4]),cur_spell[5]);
        if(cur_spell[1])
          tell_object(ppl[x],EMOTER(cur_spell[1],ppl[x]));
        if(cur_spell[7])
          call_other(cur_spell[8],cur_spell[7],ppl[x],room,dam);
      }
    }
  }
}

attack() {
  if(spells && attacker_ob) {
   object room;
   room=environment();
   if(room && present(attacker_ob,room)) {
     int spchance,s,x;
     s=sizeof(spells);
     if(multi_cast) {
       for(x=0;x<s;x++) {
         if(attacker_ob) {
           spchance=random(100)+1;
           if(spchance<spells[x][3])
             execute_spell(spells[x],attacker_ob,room);
         }
       }
     } else {
       int chance_total;
       spchance=random(100)+1; 
       chance_total=0;
       for(x=0;x<s;x++) {
         if(spchance > chance_total && spchance <= spells[x][3]+chance_total) {
           execute_spell(spells[x],attacker_ob,room);
           break;
         } else if(room) {
           chance_total+=spells[x][3];
         }
       }
     }     
   } 
  }
  ::attack();
}

int query_spell_exp() {
  int x,y,s,ss;
  int extra_exp_tot;
  int extra_exp_round;
  int chance_total;
  int spells_used;
  chance_total=0;
  extra_exp_tot=0;
  if(!spells || !sizeof(spells)) return 0;
  s=sizeof(spells);
  for(x=0;x<s;x++) {
    extra_exp_round=0;
    ss=sizeof(spells[x][4]);
    /* Calculate total damage with a bonus for non-physical */
    for(y=0;y<ss;y++) {
      if(spells[x][5][y]=="physical")
        extra_exp_round+=spells[x][4][y];
      else
        extra_exp_round+=spells[x][4][y]*NONPHYS;
    }
    /* Average damage is damage*chance/2 in multicast mode */
    if(multi_cast)
      extra_exp_tot+= (extra_exp_round * spells[x][3] / 200);
    else {
      chance_total+=spells[x][3];
      extra_exp_tot+=extra_exp_round;
    }
    if(chance_total>=100)
      break;
  }
  if(multi_cast)
    return extra_exp_tot;
  else /* In non multi-cast motive the chance is cumulative not averaged */
    return extra_exp_tot * chance_total / 200 / x;
}

calculate_worth() {
  int hp_factor, wc_factor, ac_factor, exp_worth;

  hp_factor = (max_hp / 50) + 1;
  hp_factor += hp_bonus / 50;

  wc_factor = weapon_class;
  wc_factor += this_object()->query_spell_chance() * this_object()->query_spell_dam()/ 200;
  wc_factor += this_object()->query_spell_exp();
  wc_factor += wc_bonus;

  ac_factor = armor_class;
   if(this_object()->query_heal_rate() > 0 && this_object()->query_heal_intv() > 0)
      ac_factor += (this_object()->query_heal_rate() * 3) / this_object()->query_heal_intv();
  ac_factor += ac_bonus;

  exp_worth = hp_factor * wc_factor * ac_factor;
  return exp_worth;
}
