// equip.c by Dank.  Copyright 1993 by Dan Kindsvater on everything but
// function names borrowed from Discworld mudlib.  Keep this header if you use
// any docs or code from this file.

inherit "/std/living/combat";  //this will go when combat.c is done.

//inherit "/std/armor_logic";
//inherit "weapon_logic";

private object *held_ob, *armors;
private int ac;
private string *armor_types;
private status *useless_hands, *cursed_hands, *amputated_hands, *free_hands;
private status hand;
string weapon;

// prototypes:
status remove_armor(object armor);
void do_equip(status mess);

object query_held_ob(int i) { return held_ob[i]; }
status set_held_ob(int i, object ob) { held_ob[i] = ob; return 1; }
object *query_armors() 
{ 
  int i;
  object *aa;
  aa = ({ });
  for(i=0; i<sizeof(armors); i++)
    if(armors[i]!=0 && objectp(armors[i]))
      aa += ({ armors[i] });
  armors = aa;
  return armors; 
}
/*
string query_pronoun() { return (string)this_object()->query_pronoun(); }
*/
create() {
  combat::create();
//  armor_logic::create();
  held_ob = ({ 0, 0 });
  armors = ({ });
  ac = 0;
  armor_types = ({ });
  useless_hands = ({ 0, 0 });
  cursed_hands = ({ 0, 0 });
  amputated_hands = ({ 0, 0 });
  free_hands = ({ 1, 1 });
  hand = 0;
  weapon = 0;
}

int query_ac() { return ac; }
status adjust_ac(int i) { ac += i;  return 1; }
status add_ac(int i) { ac += i;  return 1; }

void calc_free_hands() {
  int i; object ob;
  for (i=0; i<2; i++) {
    ob = held_ob[i];
    if ( (ob && ob->query_cursed() && (!ob->query_weapon() || !i))
      || (ob && ob->query_armor())
      || (ob && cursed_hands[i]) || useless_hands[i] )
      free_hands[i] = 0;
    else
      free_hands[i] = 1;
  }
  if (ob && ob==held_ob[0] && mini(free_hands)==0) {
    free_hands[0] = 0;
    free_hands[1] = 0;
  }
}


status set_amputated_hands(int i, status amputated) {
  int j, k; string *str; object ob, guild_ob;
  amputated_hands[i] = amputated;
  useless_hands[i] = amputated;
  if (amputated) {
    str = ({ "right", "left" });
    tell_room(environment(),this_object()->query_cap_name()+" loses "+this_object()->query_possessive()
      +" "+str[j]+ " hand!  "+this_object()->query_pronoun()+" drops everything from the "
      "shock!\n", this_object());
    tell_object(this_object(),"You lose your "+str[j]+" hand!  You drop "
      "everything from the shock!\n");
    for (j=0; j<2; j++)
      if (ob=held_ob[j]) {
        held_ob[j] = 0;
        if (!ob->query_weapon())
          ob->set_held(0);
        else
          ob->set_wielder(0);
        ob->set_drop();
        ob->move(environment());
        tell_room(environment(),this_object()->query_cap_name()+" drops "+this_object()->query_possessive()
          +" "+ob->short(0)+".\n", this_object());
        tell_object(this_object(),"You drop your "+ob->short(0)+".\n");
      }
    guild_ob = this_object()->query_guild_ob();
if (!guild_ob) guild_ob = "/std/guild";
    weapon_attack_out = (int *)guild_ob->set_weapon_attack_out(0, held_ob);
    if (j = member_array("gloves", armor_types)!=-1) {
      ob = armors[j];
      ob->set_wearer(0);
      adjust_ac(-((int)ob->query_ac()));
      ob->set_drop();
      ob->move(environment());
      tell_room(environment(),this_object()->query_cap_name()+" drops "+this_object()->query_possessive()
        +" "+ob->short(0)+".\n", this_object());
      tell_object(this_object(),"You drop your "+ob->short(0)+".\n");
      armors = delete(armors,j,1);
      armor_types = delete(armor_types,j,1);
    }
  }
  calc_free_hands();
  return 1;
}
status query_amputated_hands(status hand) { return amputated_hands[hand]; }

status set_useless_hands(int i, status useless) {
  int j; string *str; object ob, guild_ob;
  str = ({ "right", "left" });
  useless_hands[i] = useless;
  if (i == 1) {
    tell_room(environment(),this_object()->query_cap_name()+" loses the use of "+
      this_object()->query_possessive()+" "+str[j]+ " hand!  "+this_object()->query_pronoun()+
      " drops everything from the shock!\n", this_object());
    tell_object(this_object(),"You lose the use of your "+str[j]+" hand!  "
      "You drop everything from the shock!\n");
    for (j=0; j<2; j++)
     if (ob=held_ob[j]) {
        if (ob->query_armor())
          remove_armor(ob);
        if (!ob->move(environment())) { //MOVE_OK is 0 in move_failures.h
          tell_room(environment(),this_object()->query_cap_name()+" drops "+
            this_object()->query_possessive()+" "+ob->short(0)+".\n", this_object());
          tell_object(this_object(),"You drop your "+ob->short(0)+".\n");
        }
      }
  }
  guild_ob = this_object()->query_guild_ob();
if (!guild_ob) guild_ob = "/std/guild";
  weapon_attack_out = (int *)guild_ob->set_weapon_attack_out(0, held_ob);
  calc_free_hands();
  return 1;
}
status query_useless_hands(status hand) { return useless_hands[hand]; }

status set_cursed_hands(int i, status cursed) {
  cursed_hands[i] = cursed;
  calc_free_hands();
  return 1;
}
status query_cursed_hands(status hand) { return cursed_hands[hand]; }

status set_hand(status i) { hand = i; return 1; }
status query_hand() { return hand; }

// called from dest_me() in /obj/armor.c 
void dest_armor(object armor) {
  int i;
  if ((string)armor->query_type() == "shield") {
    held_ob[1] = 0;
    calc_free_hands();
  }
  i = member_array(armor, armors);
  armors = delete(armors, i, 1);
  armor_types = delete(armor_types, i, 1);
  adjust_ac(-((int)armor->query_ac()));
}


void wear_remove_mess(object armor, string str1, string str2, string str3) {
  tell_room(environment(), this_object()->query_cap_name()+" tries to "+str1+" "+
    add_a(armor->short(0))+", but "+this_object()->query_pronoun()+" "+str2+".\n",
    this_object());
  tell_object(this_object(), "You try to "+str1+" "+add_a(armor->short(0))+
    ", but you "+str3+".\n"); 
}


// mess = 1 means we want a message that the object is unheld.  Before 
// unhold_ob() is called, set_held(0) or set_wielder(0) is called in the
// item to make sure the item will successfully be unheld or unwielded.
int unhold_ob(status mess, object ob) {
  int i; object guild_ob;
  if ((i = member_array(ob, held_ob))==-1) {
    notify_fail("Bug! The object was not unheld or unwielded.\n");
    return 0;
  }
  held_ob[i] = 0;
  if (!ob->query_weapon()) {
    ob->set_held(0);
    if (mess = 1) {
      tell_room(environment(), this_object()->query_cap_name()+" puts "+
        this_object()->query_possessive()+" "+ob->short(0)+" away.\n", this_object());
      tell_object(this_object(),"You put your "+ob->short(0)+" away.\n");
    }
  }
  else {
    ob->set_wielder(0);
    guild_ob = this_object()->query_guild_ob();
if (!guild_ob) guild_ob = "/std/guild";
    weapon_attack_out = (int *)guild_ob->set_weapon_attack_out(mess,
      held_ob);
  }
  calc_free_hands();
  if (held_ob[1-i] == ob)             // ie if it's a twohanded item
    return unhold_ob(mess, held_ob[1-i]);
}


// Before calling hold_ob() we make sure that any item in that hand, or in
// both hands if it's a twohanded item, has been unheld, and that this
// item will be successfully held.
status hold_ob(object ob, int hand) {
  int i; object guild_ob; string curse;
  curse = "";
  held_ob[hand] = ob;
  if (ob->query_cursed() || cursed_hands[hand] )
    curse = "  It sticks to your hand!\n";
  if (ob->query_twohanded()) {
    held_ob[1-hand] = ob;
    if (cursed_hands[1-hand] || curse)
      curse = "It sticks to your hands!\n";
  }
  if (ob->query_weapon()) {
    ob->set_wielder(this_object());
    guild_ob = this_object()->query_guild_ob();
if (!guild_ob) guild_ob = "/std/guild";
    weapon_attack_out = (int *)guild_ob->set_weapon_attack_out(1, held_ob);
  }
  else {
    ob->set_held(1);
    tell_room(environment(), this_object()->query_cap_name()+" holds "+
      this_object()->query_possessive()+" "+ob->short(0)+ ".\n"+curse, this_object());
    tell_object(this_object(),"You hold your "+ob->short(0)+".\n"+curse);
  }
  calc_free_hands();
  return 1; 
}


status hold_wield(string str, int j) 
{              // j is which hand
  int i; 
  object *obs; 
  object ob, ob2; 
  string h;

  obs = find_match(str, this_object());
  if(!obs || !sizeof(obs))
    ob = 0;
  else
    ob = obs[0];

  if (j)
    h = "hold";
  else
  {
    weapon = str;
    h = "wield";
    j = 1;
  }
  if (j && (i=member_array("shield", armor_types))!=-1) 
    {
    tell_object(this_object(),"You must 'remove shield' to put away your " 
       +(str=ob->short(0))+".\n");
    tell_room(environment(), this_object()->query_cap_name()+" must 'remove shield' to put"
      " away "+this_object()->query_possessive()+" "+str+".\n",this_object());
    return 0;
  }
  if (!str || str == "hands" || str == "nothing")
    str = "";
  if (!held_ob[j] && str=="") {
    tell_room(environment(), this_object()->query_cap_name()+" isn't "+h+"ing anything.\n",
      this_object());
    tell_object(this_object(),"You aren't "+h+"ing anything.\n");
    return 0;
  }
  else if (held_ob[j])
    if (cursed_hands[j]||(held_ob[j]->query_twohanded()&&cursed_hands[1-j])){
      wear_remove_mess(held_ob[j], "put away", "can't get "+
        this_object()->query_possessive()+" hand to let go",
        "can't get your hand to let go");
      return 0;
    }
    else if (!free_hands[j]) {
      wear_remove_mess(held_ob[j], "put away", "can't!  It's cursed!",
         "can't!  It's cursed!");
      return 0;
    }
  if (str=="") {
    unhold_ob(1, held_ob[j]);
    return 1;
  }
  if (useless_hands[j]) {
    tell_room(environment(), this_object()->query_cap_name()+" tries to "+h+" "+str+
      ", but "+this_object()->query_pronoun()+" has no useful "+h+"ing hand.\n",
      this_object());
    tell_object(this_object(),"You try to "+h+" "+str+", but "
      "you have no useful "+h+"ing hand.\n");
    return 0;
  }
  obs = find_match(str, this_object());
  if (!sizeof(obs)) {
    tell_room(environment(), this_object()->query_cap_name()+" tries to "+h+" "+str+
      ", but "+this_object()->query_pronoun()+" doesn't have that.\n", this_object());
    tell_object(this_object(),"You try to "+h+" "+str+", but "
      "you don't have that.\n");
    return 0;
  }
  ob = 0; ob2 = 0;
  for (i=0;i<sizeof(obs);i++)
  {
    if (obs[i]->set_held(obs[i]->query_held()) )
    {
      if (member_array(obs[i], held_ob)==-1) 
      {
        if (!obs[i]->query_twohanded() || free_hands[1-j]) 
        {
          if (held_ob[j])
            unhold_ob(0, held_ob[j]);
          if (held_ob[1-j] && obs[i]->query_twohanded())
            unhold_ob(0, held_ob[1-j]);
          hold_ob(obs[i], j);
          return 1;
        }
        else if (!ob2) {
          ob = obs[i];
          continue;
        }
      }
      else if (!ob)
        ob2 = obs[i];
    }
  }
  if (ob)
  {
    if (ob == held_ob[j])
    {
      wear_remove_mess(ob, h, "is already "+h+"ing it", "are already "+
        h+"ing it");
    }
    else
    {
      wear_remove_mess(ob, h, "must first release it from the other hand",
        "must first release it from the other hand");
    }
  }
  else if (ob2)
  {
    wear_remove_mess(ob2, h, "doesn't have both hands free, "
      "and it take two hands to "+h+" it", "don't have both hands free, "
      "and it take two hands to "+h+" it");
  }
  else if (obs[0]->query_armor())
  {
    wear_remove_mess(obs[0], h, "probably wants to 'wear' it instead",
      "probably want to 'wear' it instead");
  }
  else {
    tell_room(environment(), this_object()->query_cap_name()+" doesn't have to "+h+" "+
// Aragorn temp fix until some1 can code it properly...
//       add_a(ob->short(0))+".\n",this_object());
//     
      str+".\n",this_object());
    tell_object(this_object(), "It's not necessary for you to "+h+" "+
//      add_a(ob->short(0))+".\n");
      str+".\n");
  }
  return 1;
}



status hold(string str) { return hold_wield(str, 1); }
status wield(string str) { return hold_wield(str, 0); }


status wear_armor(object armor) {
  int num, i; string type; object guild_ob;
  if (member_array(armor, armors)!=-1) {
    wear_remove_mess(armor, "wear", "is already wearing that",
      "are already wearing that");
    return 0;
  }
  type = armor->query_type();
  if (i=member_array(type, armor_types)!=-1) {
    num = 1;
    if (type=="ring" && member_array(type, armor_types[i+1..-1])!=-1)
      num = 2;
  }
// the guild object can query the race object if it needs to 
  guild_ob = this_object()->query_guild_ob();
if(!guild_ob) guild_ob = "/std/guild";
if(guild_ob)
  if (num > guild_ob->query_number_worn(type)) {
    if (num == 1)
      wear_remove_mess(armor, "wear", "isn't trained in wearing that",
        "aren't trained in wearing that");
    else
      wear_remove_mess(armor, "wear", "can't wear any more of those",
        "can't wear any more of those");
    return 0;
  }
  if (type == "armor" && member_array("cloak", armor_types)!=-1) {
    wear_remove_mess(armor, "wear", "forgot to remove a cloak first",
      "forgot to remove your cloak first");
    return 0;
  }
  if (type == "gloves" && mini(free_hands) == 0) {
    wear_remove_mess(armor, "wear", "doesn't have both hands free",
      "don't have both hands free");
    return 0;
  }
  if (type == "shield")
    if (free_hands[1] == 0) {
      wear_remove_mess(armor, "wear", "doesn't have "+this_object()->query_possessive()+
        " shield hand free", "don't have your shield hand free");
      return 0;
    }

// Well, finally...everything above this line means you don't wear the armor,
// everything below this line means you do.
    else if (held_ob[1]) {
      unhold_ob(0, held_ob[1]);
      held_ob[1] = armor;
      calc_free_hands();
    }
  if (type == "armor") {
    tell_room(environment(),this_object()->query_cap_name()+" begins to wear"+
      this_object()->query_possessive()+" body armor.\n", this_object());
    tell_object(this_object(), "You begin to wear your body armor.\n");
    call_out("armor_call_out", 2+2*random(3), "wearing", 0, armor, type);
  }
  else {
    armor->set_wearer(this_object());
    armors += ({ armor });
    armor_types += ({ type });
    adjust_ac((int)armor->query_ac());
  }
  return 1;
} // wear_armor() 


void armor_call_out(string str, int i, object armor, string type) {
  tell_room(environment(), this_object()->query_cap_name()+" is finally "
    "finished "+str+" "+this_object()->query_possessive()+" body armor.\n",
    this_object());
  tell_object(this_object(), "You're finally finished "+str+" your body"
    " armor.\n");
  if (str == "wearing") {
    armor->set_wearer(this_object());
    armors += ({ armor });
    armor_types += ({ type });
    adjust_ac((int)armor->query_ac());
  }
  else {
    armor->set_wearer(0);
    armors = delete(armors,i,1);
    armor_types = delete(armor_types,i,1);
    adjust_ac(-((int)armor->query_ac()));
  }
}


status remove_armor(object armor) {
  int i; string type;
  type = (string)armor->query_type();
  if (member_array(armor, armors)==-1) {
    wear_remove_mess(armor, "remove", "isn't wearing that",
      "aren't wearing that");
    return 0;
  }
  if (type == "armor" && member_array("cloak", armor_types)!=-1) {
    wear_remove_mess(armor, "remove", "forgot to remove a cloak first",
      "forgot to remove your cloak first"); 
    return 0;
  }
  if (type == "gloves" && (mini(free_hands)==0)) {
    wear_remove_mess(armor, "remove", "doesn't have both hands free",
      "don't have both hands free");
    return 0;
  }
  if (armor->query_cursed()) {
    wear_remove_mess(armor, "remove", "can't!  It's cursed",
      "can't!  It's cursed");
    return 0;
  }
  if (type == "shield") {
    wear_remove_mess(armor, "remove", "can't get "+this_object()->query_possessive()+
      " hand to let go", "can't get your hand to let go");
      return 0;
    }

// Well, finally...everything above this line means you don't remove the
// armor, everything below this line means you do.
    else {
      held_ob[1] = 0;
      calc_free_hands();
    }
  if (type == "armor") {
    tell_room(environment(),this_object()->query_cap_name()+" begins to remove "+
      this_object()->query_possessive()+" body armor.\n", this_object());
    tell_object(this_object(), "You begin to remove your body armor.\n");

// body armor takes 1 to 4 rounds longer than other armor to wear.
    call_out("armor_call_out", 2+2*random(3), "removing", i, armor, type);
  }

  else {
    armor->set_wearer(0);
    armors = delete(armors,i,1);
    armor_types = delete(armor_types,i,1);
    adjust_ac(-((int)armor->query_ac()));
  }
  return 1;
}


void wear(string str) {
  int i; object *obs;
  if (!str) {
    notify_fail("Wear what? Use remove if you want to remove armor.\n");
    return;
  }
  if (str == "all") {
    do_equip(1);
    return;
  }
  obs = find_match(str, this_object());
  if (!sizeof(obs)) {
    tell_room(environment(), this_object()->query_cap_name()+" tries to wear "+str+
      ", but "+this_object()->query_pronoun()+" doesn't have that.\n", this_object());
    tell_object(this_object(),"You try to wear "+str+", but "
      "you don't have that.\n");
    return;
  }
  for (i=0; i<sizeof(obs); i++)
    if (!obs[i]->query_armor())
      wear_remove_mess(obs[i], "wear", "doesn't think it's a type of armor",
        "don't think it's a type of armor");
    else
      wear_armor(obs[i]);
}


void remove(string str) {
  int i; object *obs;
  if (!str) {
    notify_fail("Remove what?\n");
    return;
  }
  obs = find_match(str, this_object());
  if (!sizeof(obs)) {
    tell_room(environment(), this_object()->query_cap_name()+" tries to remove "+str+
      ", but "+this_object()->query_pronoun()+" doesnt have that.\n", this_object());
    tell_object(this_object(),"You try to remove "+str+", but "
      "you don't have that.\n");
    return;
  }
  for (i=0; i<sizeof(obs); i++)
    if (member_array(obs[i], armors)==-1)
        wear_remove_mess(obs[i], "remove", "isn't wearing it",
          "aren't wearing it");
    else
      remove_armor(obs[i]);
}


int do_equip(status mess) {
  int i, j, *attack; 
  string str; 
  object ob, ob2, guild_ob, *obs;
  mixed *armor, *weapon;

  armor = ({  }); 
weapon = ({0,-50});

  guild_ob = this_object()->query_guild_ob();
if (!guild_ob) guild_ob = "/std/guild";
  obs = all_inventory(this_object());

  for (i=0; i<sizeof(obs); i++) 
  {
    ob = obs[i];
    if (ob->query_armor()) 
    {
      str = (string)ob->query_type();
      j = member_array(str, armor);
      ob2 = (object)ob->prev_wearer();
      if( j==-1  || (
          ( (int)ob->query_ac() > armor[j-1]) ) &&
          ( objectp(ob2) && ob2==this_object() ) &&
          ( (int)guild_ob->query_number_worn(str) ) )
      {
         if (j == -1)
         {
           j = 2;
           armor += ({ 0, 0, 0 });
         }
         armor[j-2] = ob;
         armor[j-1] = (int)ob->query_ac();
         armor[j] = str;
      }
    }
    else
    {
      ob2 = (object)ob->prev_wielder();
      if ( (ob->query_weapon() ) && 
        ( guild_ob->query_valid_melee_weapon(ob) ) &&
        ( attack=(int*)ob->query_attack_out() ) &&
        ( (ob2?(ob2==this_object()):1)  ) &&
        ( !( (ob->query_twohanded()) && (!free_hands[1])) ) &&
        ( (j=attack[4]*(1+attack[5])/2+attack[6])) > weapon[1] )
      {
        weapon[0] = ob;
        weapon[1] = j;
      }
    }
  }
 // printf("armors: %0\nweapon: %0\n",armor,weapon);

  if (i = member_array("shield", armor)!=-1) {
    if (held_ob[1]) {
      tell_room(environment(),this_object()->query_cap_name()+" decides not to wear a "         "shield since "+this_object()->query_possessive()+" shield hand is holding something"
        " already.\n", this_object());
      tell_object(this_object(),"You decide not to wear a shield since your"
        " shield hand is holding something already.\n");
      armor = delete(armor, i-2, 3);
    }
    else if (useless_hands[1]) {
      wear_remove_mess(armor[i-2], "wear", "can't use "+this_object()->query_possessive()+
        " shield hand", "can't use your shield hand");
      armor = delete(armor, i-2, 3);
    }
  }
  if (!sizeof(armor)) {
    tell_room(environment(), this_object()->query_cap_name()+" has nothing to wear.\n",
      this_object());
    tell_object(this_object(),"You have nothing to wear.\n");
//    return 1;
  }
  j = -1;
  for (i=0; i<sizeof(armor); i+=3)
    if (armor[i+2] != "cloak")
      wear_armor(armor[i]);
    else
      j = i;
  if (j != -1)
    wear_armor(armor[j]);

if(weapon[0])
  ob = weapon[0];
  if (!ob) {
    tell_room(environment(), this_object()->query_cap_name()+" has nothing to wield.\n",
      this_object());
    tell_object(this_object(),"You have nothing to wield.\n");
  }
else if (!free_hands[0]){
    tell_room(environment(), this_object()->query_cap_name()+" doesn't have a free weapon "
      "hand.\n", this_object());
    tell_object(this_object(),"You don't have a free weapon hand.\n");
  }
  else {
    if (held_ob[0])
      unhold_ob(0, held_ob[0]);
    if (held_ob[1] && ob->query_twohanded())
      unhold_ob(0, held_ob[1]);
    hold_ob(ob, 0);
  }
  return 1;
}

mixed *stats() {
  mixed *ret; string *str; int i, j;
  ret = ({ });
  i = query_hand();
  str = ({ "right", "left" });
  for (j=0; j<sizeof(armors); j++)
    ret += ({ ({ "Wearing", armors[i]->short(0) }) });
  return ({ ({ "Total armor protection", ac }),
 /*   ({ "Holding in "+str[i]+" hand:", held_ob[0]->short(0) }),
    ({ "Holding in "+str[1-i]+" hand:", held_ob[1]->short(0) }),  */
  }) + ret + combat::stats();
}

/* Add for new weapon_logic.c */
/* Look in /w/sojan/combat/excode.new for explanation. */
int shield_bonus()
  {
  return 0;
  }
