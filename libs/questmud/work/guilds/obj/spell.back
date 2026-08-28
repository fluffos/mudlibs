#define SPELLFUN "/guilds/obj/spellfun"

/* This is the spell object. It is cloned inside the caster. */

string category,class,type,target,current_word;
int phase, effect_bonus, special_chance_bonus, resolving, control_left;
int offensive, multi_due_fail;
object target_ob, caster_ob;

/*
 *  Start_spell is called first after cloning, when someone tries to cast
 *  a spell.
 */

start_spell(str, object caster) {
  int attack_chance;
  if (!caster) { caster_ob = this_player(); }
  else { caster_ob = caster; }

  if (caster_ob->query_stunned()) {
    tell_object(caster_ob, "You are stunned and unable to concentrate.\n");
    interrupt_spell();
    return 1;
  }
  if (sscanf(str, "%s %s %s at %s", category, class, type, target) == 4 ||
      sscanf(str, "%s %s %s", category, class, type) == 3) {
    if (present("spellbook", caster_ob)) {
      if (present("spellbook",caster_ob)->query_words(category + " "+class + " " + type)) {
        special_chance_bonus = 50; /* 5% */
        tell_object(caster_ob, "You quickly eye your spellbook as you start chanting.\n");
      }
    }
    if (type == "blt" || type == "strm" || type == "rhj" && !random(5)) {
      tell_object(caster_ob, "You start concentrating on the offensive spell.\n");
      if (target) { target_ob = present(target, environment(caster_ob)); }
      if (!target_ob && target) {
        tell_object(caster_ob, "You don't see "+capitalize(target)+" here, but still decide to cast your spell.\n");
      }
      offensive = 1;
      if(!elusive_check()) {
        tell_room(environment(caster_ob), capitalize(caster_ob->query_name()) +" starts concentrating on an offensive spell.\n", ({ caster_ob }));
        notice_check();
      }
    } else {
      if(type == "rhj") tell_object(caster_ob, "You manage to hide the offensive nature of your spell.\n");
      tell_object(caster_ob, "You start concentrating on the spell.\n");
      if(!elusive_check()) {
        tell_room(environment(caster_ob), capitalize(caster_ob->query_name()) + " starts concentrating on a spell.\n", ({ caster_ob }));
      }
    }
  } else {
      tell_object(caster_ob, "You can't cast anything without the three spell words!\n");
      interrupt_spell();
      return 1;
  }
    phase = 0;
    call_out("check_category",2);
}
/* Check if such a category exists. */

check_category() {
    if (caster_ob->query_tester()) { tell_object(caster_ob, "check_category_called.\n"); }
    if (!call_other(SPELLFUN, "spell_categories", category)) {
        tell_object(caster_ob, "You utter the word; " + category + ", but your concentration fails.\n");
        interrupt_spell();
        return 1;
    }
    current_word = category;
    next_phase();
}

next_phase(status no_counter) {
    int time,check, extra_time;
    string text;
    phase += 1;
    check = 1;
    if (phase == 1) {
        current_word = class;
        check = get_class_check();
    }
    if (phase == 2) {
        current_word = type;
        check = get_type_check();
    }
    /* extra_time is spelldelay by counter */
    if (extra_time = get_word_text(no_counter)) {
        if (phase >= 3) {
            spell_effect();
            interrupt_spell(1);
            return 1;
        }
    }

    if(extra_time != 4) extra_time = 0;
    else {
      no_counter = 1;
      extra_time = (random(2)+1)*2;
    }
    time = get_time();
    call_out("next_phase", time+extra_time, no_counter);
}

get_class_check() {
    return call_other(SPELLFUN, "spell_classes",category,class,type);
}

get_type_check() {
    return call_other(SPELLFUN, "spell_types", category,class,type);
}

/* how many rounds does it take to cast a spell? */
get_time() {
    int time, control, cost;

    cost = SPELLFUN->sp_cost(current_word)*2;

    if (category == "chl") {
        control = caster_ob->query_skills("channel");
    } else if (category == "exs") {
        control = caster_ob->query_skills("mana control");
    } else if (category == "doo") {
        control = caster_ob->query_skills("dark power");
    } else if (category == "kyo") {
        control = caster_ob->query_skills("abjuration");
    } else if(category == "dcs") {
		control = caster_ob->query_skills("demonology");
	}
    control = (control*3/4)+random(control/2+5);
    cost -= control_left;
    control_left = 0;
    time = cost / (control + 1);

    control_left = (control * time) - cost;
    return time;
}

get_word_text(status no_counter) {
  int counter;
  string text,text_to_others,word;
/* if caster is dead by uncon*/
  if(!caster_ob) {
    interrupt_spell(1);
    return 1;
  }

  if (phase == 1)
        word = category;
  if (phase == 2)
        word = class;
  if (phase == 3) {
    word = type;
    if(!no_counter && category != "chl") {
      counter = counter_spell();
      if(counter == 1) {
        interrupt_spell(1);
        return 0;
      } else if(counter == -1) {
        phase = 2;
        return 4;
      }
    }
  }
    if(caster_ob->casting_sp_reduce(call_other(SPELLFUN,"sp_cost", word)))
        return 1;

    text = call_other(SPELLFUN, "get_text", word);
    text_to_others = call_other(SPELLFUN, "get_text_to_others",word);

    tell_object(caster_ob, text);
    if(!elusive_check()) {
      tell_room(environment(caster_ob), text_to_others);
      notice_check();
    }

    if (check_fail(word,text)) {
        return 0;
    }
    return 1;
}

check_fail(word,text) {
  int rnd,chance,fail,tmp,cost,skill;
  string skill_num, chance_str;
  skill_num = get_skill_name(word);
  cost = call_other("/guilds/obj/skillfun.c","skill_costs",skill_num,0,"base_cost");
  if (skill_num) { skill = caster_ob->query_skills(skill_num); }
  /* jos skilli on 30%, chance on 80% */
  if(skill < 30) {
    chance = skill*27;
  } else {
    chance = 800;
    chance += (skill-30)*2;
  }
  chance += caster_ob->query_skills("chanting")/2; /* max +5% */
  if (category == "chl") {
    chance += caster_ob->query_wis() / 3;
  }
  if (category == "doo") {
    chance += (caster_ob->query_int()+caster_ob->query_wis()) / 4;
  }
  if (category == "exs") {
    chance += caster_ob->query_int() / 3;
  }
  if (category == "kyo") {
    chance += caster_ob->query_int() / 3;
  }
  if (category == "dcs") {
	chance += caster_ob->query_int() / 3;
}
  /* skillcost reducaa chancea */
  chance -= (cost*10) - 30;
  /* spellbook */
  chance += special_chance_bonus;
  /* yli 99% */
  if(caster_ob->query_skill()) {
    tell_object(caster_ob, "Your skill concentration makes the casting harder.\n");
    chance -= chance/4;
  }
  if(chance > 990) chance = 990 + (chance-990) / 2;
  if (chance > 1000) { chance = 1000; }
  if (!skill_num || caster_ob->query_skills(skill_num) == 0) chance = 0;
  if(chance) {
    chance_str = to_string(chance);
    chance_str = chance_str[0..1]+"."+chance_str[2..2];
    if(chance == 1000) chance_str = "100";
    tell_object(caster_ob, "Syllabe chance: "+chance_str+"%\n");
  }
  /* chance tuhansina, etteivat pyoristelyt haittaisi kauheasti */
  rnd = random(1000)+1;
  if (rnd > chance) {
    chance = cast_failure(chance, caster_ob);
    if(!chance) {
      caster_ob->lited("You fail the spell.\n");
      interrupt_spell();
      return 1;
    }
  }
  effect_bonus += chance/10;
  return 0;
}

/* return 0 if spell fails. chance [1,1000]  */
cast_failure(int chance, object ob) {
  int i;
  if(ob) caster_ob = ob;
  i = random(20);
  if(i == 0) {
    tell_object(caster_ob, "You feel that your spell has gone wild!\n");
    multi_due_fail = 1;
    return chance*3;
  }
  if(i == 1) {
    tell_object(caster_ob, "You feel that your spell went awry!\n");
    multi_due_fail = -1;
    return -chance*10;
  }
  if(i == 2) {
    tell_object(caster_ob, "You sense a magical gap draining all your energy!\n");
    caster_ob->set_sp(0);
    return 0;
  }
  if(i == 3) {
    tell_object(caster_ob, "You sense a surge of energy filling you from an unknown source!\n");
    caster_ob->set_sp(caster_ob->query_sp()+300);
    return chance;
  }
  if(i > 3) {
    tell_object(caster_ob, "Suddenly your concentration fails and so does your spell.\n");
    tell_room(environment(caster_ob), "Suddenly " + caster_ob->query_name() + " falters and fails the spell.\n", ({ caster_ob}));
    return 0;
  }
  /* Should not execute this far. */
  tell_object(caster_ob, "Utter failure.\n");
  return 0;
}

get_additional_rounds(word) {
    if (!word) {
        if (phase == 1)
             word = category;
        if (phase == 2)
             word = class;
        if (phase == 3)
             word = type;
    }
    return call_other(SPELLFUN, "additional_rounds",word);
}

interrupt_spell(status force) {
    remove_call_out("next_phase");
    if (this_object() && (!resolving || force)) {
       destruct(this_object());
    }
}

match_fail() {
    tell_object(caster_ob, "You feel something is not matching.\n");
    caster_ob->lited("You fail the spell.\n");
    tell_room(environment(caster_ob), capitalize(caster_ob->query_name()) + " looks confused and fails the spell.\n", ({ caster_ob }));
    interrupt_spell(1);
    return 1;
}

/* Add your spell words skill number in this list as following: */
get_skill_name(word) {
    return call_other(SPELLFUN, "get_skill_num", word);
}

query_resolving() { return resolving; }

/* start counter spell resolve. recode by Celtron */

string *get_total_counter(object caster, object target) {
  object *all;
  int i, tmp, total_counter;
  string names;
  all = all_inventory(environment(caster));
  names = "";
  for(i=0; i < sizeof(all); i++) {
   tmp = all[i]->query_skills("counter spell");
   if(all[i]->query_counter() == "all" || all[i]->query_counter() == lower_case(caster->query_name()) || all[i] == target ) {
      if(tmp > 0 && all[i] != caster && all[i]->query_counter() != "none" && (!caster->query_npc() || !all[i]->query_npc())) {
        if(names != "") names += ", ";
        names += all[i]->query_name();
        total_counter += tmp;
        tell_object(all[i], "You attempt to counter "+caster->query_name()+"'s spell!\n");
        if(caster->query_tester()) tell_object(caster, all[i]->query_name()+" attempts to counter your spell!\n");
        all[i]->casting_sp_reduce(50+random(50));
      }
    }
  }

  return ({ names, total_counter });
}

counter_spell() {
  object ob;
  int roll;
  string *total_counter;
  if (target)
    ob = present(lower_case(target),environment(caster_ob));
  total_counter = get_total_counter(caster_ob, ob);
  /* disable (accidental) attempts to make spellcasting impossible //Celtron */
  if(total_counter[1] > 100) total_counter[1] = 100;
  roll = caster_ob->query_skills("counter spell");
  if(roll > 100) roll = 100;
  roll = random(roll+40);

  if(caster_ob->query_wiz()) write("Counter: "+total_counter[1]+"<"+roll+"\n");

  /* spelli tulee ihan normaalisti */
  if(!total_counter[1] || total_counter[1] < roll+caster_ob->query_anticounter_bonus()) return 0;
  /* tsekkaa onnistuuko total counter, muuten tulee delay */
  if (total_counter[1] > random(effect_bonus)+caster_ob->query_anticounter_bonus()) {
         /*  log_file("COUNTER_SPELL", total_counter[0]+" countered "+caster_ob->query_name()+"'s spell. "+
                category+"_"+class+"_"+type+". total_counter(effect_bonus):"+total_counter[1]+"("+effect_bonus+") ["+ctime(time())+"]\n");
        */
           tell_object(caster_ob, "Your spell was countered by "+total_counter[0]+"!\n");
           tell_room(environment(caster_ob), caster_ob->query_name()+"'s spell was countered by "+
                total_counter[0]+"!\n", ({ caster_ob, }));
           interrupt_spell();
           return 1;
  }
  tell_object(caster_ob, "Your spell was somewhat delayed by "+total_counter[0]+"!\n");
  tell_room(environment(caster_ob), caster_ob->query_name()+"'s spell was delayed by "+
                total_counter[0]+"!\n", ({ caster_ob, }));
  return -1;
}
/* end of counter spell resolve */

spell_effect() {
    object ob,bane;
    string god;
    resolving = 1;
    caster_ob->lited("You are done with the chant.\n");
    if(bane = present("magic_bane", caster_ob)) {
          if(random(100) > 65) {
          tell_room(environment(caster_ob), caster_ob->query_name()+" fails the spell.\n", ({ caster_ob }));
          tell_object(caster_ob, "You fail the spell.\n");
          interrupt_spell(1);
          return 1;
  }
}
    if(ob = present("amf", environment(caster_ob))) {
      if(ob->query_amf()) {
      tell_room(environment(caster_ob), "The force field glows bright and radiates purple light.\n");
      tell_object(caster_ob, "Nothing happens.\n");
      interrupt_spell(1);
      return 1;
      }
    }
    if (target) {
        ob = present(lower_case(target),environment(caster_ob));
    }
    if (category == "chl") {
        if (!call_other("/guilds/obj/cleric_fail_check", "check",type,class)) {
           interrupt_spell(1);
           return 1;
        }

/*      if (target) { sscanf(target, "%s from %s", target, god); }
        if (target && sscanf(target, "from %s", god)) { target = 0; }
        if (god) { god = lower_case(god); }
        if (!god && caster_ob->query_god_status() > 30) {
           tell_object(caster_ob, "You feel Cyral is not pleased.\n");
           caster_ob->add_god_status(-5);
        }
        if (!god && caster_ob->query_god_status() < -30) {
           tell_object(caster_ob, "You feel Morai is not pleased.\n");
           caster_ob->add_god_status(5);
        }  */
    }
if (file_size("/guilds/spells/necromancy/_"+category+"_"+class+"_"+type+".c") != -1) {
call_other("/guilds/spells/necromancy/_"+category+"_"+class+"_"+type,"resolve",effect_bonus, target);
return 1;
}
    if (file_size("/guilds/spells/_"+category+"_"+class+"_"+type+".c") != -1) {
        call_other("/guilds/spells/_"+category+"_"+class+"_"+type,"resolve",
                effect_bonus, target);
        return 1;
    }
    if (file_size("/guilds/spells/essence/_"+category+"_"+class+"_"+type+".c") != -1) {
        call_other("/guilds/spells/essence/_"+category+"_"+class+"_"+type,"resolve",effect_bonus, target);
        return 1;
    }
    if (file_size("/guilds/spells/channel/_"+category+"_"+class+"_"+type+".c") != -1) {
        call_other("/guilds/spells/channel/_"+category+"_"+class+"_"+type,"resolve",effect_bonus, target);
        return 1;
    }
    if (file_size("/guilds/spells/chaos/_"+category+"_"+class+"_"+type+".c") != -1) {
		call_other("/guilds/spells/chaos/_"+category+"_"+class+"_"+type,"resolve",effect_bonus, target);
        return 1;
	}
    if(category == "kyo") {
      if(!(int)"/guilds/abjurer/prot_resolve"->resolve(category,class,type,effect_bonus,target) ) {
        if(file_size("/guilds/spells/abjuration/_"+category+"_"+class+"_"+type+".c") != -1) {
          call_other("/guilds/spells/abjuration/_"+category+"_"+class+"_"+type,"resolve",effect_bonus, target);
          return 1;
        }
      } else {
        return 1;
      }
    }
    if(category == "exs" && class == "hmm" || category == "exs" && class == "ahm") {
      call_other("/guilds/obj/invis_resolve","resolve",type,class,category,effect_bonus,target);
      return 1;
    }
    if (category == "exs") {
      if (call_other("/guilds/obj/offensive_resolve","offensive_resolve",type,class,category,effect_bonus,target,caster_ob)) {
        return 1;
      }
    }
    tell_object(caster_ob, "Nothing happens.\n");
}

elusive_check() {
 if (caster_ob->query_elusive() && !caster_ob->query_attacker()) {
   if (caster_ob->query_skills("elusive spellcasting") > random(110)) {
      if(offensive) {
        if(caster_ob->casting_sp_reduce(random(30)+30))
          return 1;
      }
      tell_object(caster_ob, "You feel like you successfully hid your spellcasting.\n");
      return 1;
   }
 }
 return 0;
}

notice_check() {
  if (offensive && target_ob && !target_ob->query_attack() && random(100) <
     (target_ob->query_level()*4-35)) {
    if(random(3)) return 0;
    if(caster_ob == target_ob) return 0; /* idiot check */
    tell_object(caster_ob, target_ob->query_name()+" notices your offensive spellcasting and attacks!\n");
    caster_ob->attack_object(target_ob, 1);
    return 1;
  }
  return 0;
}
