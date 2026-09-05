#define CMD_DIR "/players/pestilence/closed/dark/cmds/"
#define ATT USER->query_attack()
nosave string *cmds;
int here;

guild_update() {
  clone_object("/players/pestilence/closed/dark/dark.lpc")->move_object(resolve_ob(tp));
  write("<"+
HIK+"Dark Knight"+NORM+"> Guild Status Updated.\n");
  destruct(this_object());
return 1; }


add_cmds() 
  {
   int x; string cmd;
   cmds = get_dir(CMD_DIR);
   for(x=0;x<sizeof(cmds);x++)
   if(sscanf(cmds[x],"%s.lpc",cmd)) 
     {
     if(cmd == "\"") 
       { 
       add_action("cmd_hook", cmd, 1); 
       }
     else if(cmd == "'") 
       { 
       add_action("cmd_hook", cmd, 1); 
       }
     else add_action("cmd_hook",cmd); 
     }
   add_action("cmd_emote", ":", 1);
  }

cmd_hook(str) 
  {
  string verb;
  verb = query_verb();
  /* sloppy communication bug fix */
  if(verb == "'") 

    { 
    call_other(CMD_DIR+"say.lpc","main",str); 
      return 1; 
    }
  if(call_other(CMD_DIR+verb+".lpc","main",str)) 
    return 1; 
  }

cmd_emote(str)
  {
  if(!str) return;
  write("You "+str+"\n");
  TP->remote_say(capitalize(TPRN)+" "+str+"\n");
    return 1;
  }

guild_login(str) {
  if(!str){write("Where do you want to login? (church/guild)\n"); return 1;}
  if(str == "church") {tp->set_home("/room/church.lpc"); }
  if(str == "guild") {tp->set_home("/players/pestilence/ice/room/entry.lpc"); }
  write("<"+HIK+"Dark Knight"+NORM+"> Your login position has been changed.\n");
  return 1;
}

guild_quit() {
      tp->set_guild_name(0);
      tp->add_exp(tp->query_guild_exp());
      tp->add_guild_exp(-tp->query_guild_exp());
      tp->add_guild_rank(-tp->query_guild_rank());
          tp->add_exp(-(tp->query_exp()/2));
      tp->set_attrib("sta",1);
          tp->reset(1);
          command("save",tp);
          write("FOOL!\n");
          destruct(this_object());
return 1; } 

/*
punch(str){
    int dam;
    object ob, att;
    dam = 5 + random(10);
    if(environment() != this_player()) return;  
    if (!str && !USER->query_attack()){
        write("Punch who???\n");
        return 1;
    }
        else if(!str && USER->query_attack()){
                att = USER->query_attack();
        }

    else{ 
                att = present(str, environment(USER)); 
        }
    if(USER->query_spell_dam()) return 1;
    if (!att){ 
        write("There is no "+str+" here to punch"); 
        return 1; 
    }
    if(att->is_player()){
        write("You may not cast this spell at a player.\n");
        return 1; 
    }
    if(USER->query_sp() < 10){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }
    write("You hit "+att->query_name()+" with a flurry of punches.\n");
    say(USER->query_name() +" hits "+att->query_name()+" with a flurry of punches.\n");
    USER->set_spell_dam(dam);
    USER->add_spell_point(-10);
    return 1;
}

*/
/*
fatal(){
        object target, comp;
        int spamount;
        int cost;
        int gr;
        if(USER->query_ghost()) return 0;
if(this_player()->query_guild_rank() < 2){ write("You can't use ability yet.\n"); return 1; }
        if(!USER->query_attack()){
                tell_object(USER,
                "You can only do this in combat!\n");
                return 1;
        }
   if(!USER->query_weapon()){
      tell_object(USER,
      "You must have a weapon wielded!\n");
      return 1;
      }
        target = USER->query_attack();
        if(!target->query_npc()){
                tell_object(USER,
                "You cannot do this to players!\n");
                return 1;
        }
   if(!living(target)){
      tell_object(USER,
      "That didn't work.\n");
      return 1;
      }
        cost = target->query_hp()/3;
        if(cost > USER->query_sp()){
                tell_object(USER,
                "You are too weak.\n");
                return 1;
        }
        
        if(USER->query_attack() && ATT->query_hp() < 60){
                if((ATT->query_hp()*10)/(ATT->query_mhp()) < 1){
*/
        
/*
tell_object(USER,
HIK+"You pierce your opponent's heart with a solid blow"+HIW+"..."+NORM+"\n\n"+
HIR+"                   |          |          |\n"+
HIR+"               -"+HIW+"     ["+HIR+"  D  E  A  T  H"+HIW+"  ]"+HIR+"    - "+NORM+"\n"+
HIR+"                   |          |          |\n"+
ATT->query_name()+" crumbles from your blow!\n"+NORM);
*/
/*
here = environment(this_player());
tell_room(here, 
HIK+USER->query_name()+" pierces "+USER->query_possessive()+" opponent's heart with a solid blow"+HIW+"..."+NORM+"\n\n");
tell_room(here,
HIR+"                   |          |          |\n"+
HIR+"               -"+HIW+"     ["+HIR+"  D  E  A  T  H"+HIW+"  ]"+HIR+"     -"+NORM+"\n"+
HIR+"                   |          |          |"+NORM+"\n");
tell_room(here,
"\n"+ATT->query_name()+" crumbles from "+USER->query_name()+"'s blow!\n");
                USER->add_spell_point(-cost);
                        target->heal_self(-(target->query_hp()));
                        target->hit_player(gr * 20);
                        return 1;
                }
                tell_object(USER, "Your opponent is still too strong.\n");
                return 1;

        }
        tell_object(USER, "Your opponent is still too strong.\n");
        return 1;
}
*/

/*
offwield(string str) {
  object firstwep, firstshad, wep, shadow, offwep, mygob;
  mygob = present("dknight_ob", TP);
if(this_player()->query_guild_rank() < 8){ write("You can't use ability yet.\n"); return 1; }
  if(TP->query_level() < 19) {
    write("You are not worthy enough for this skill.\n");
    return 1; }
  if(!str) {
    if(offwep) {
    TP->stop_offwielding(); return 1; }
  else write("Offwield what?\n"); return 1; }
  wep = present(str, TP);
  offwep = mygob->query_offwep();
  if(!wep) { write("You don't have that!\n"); return 1; }
  if(!wep->weapon_class()) { write("That is not a weapon!\n"); return 1; }
  if(wep->two_handed()) {
   write("You cannot offwield a two-handed weapon.\n"); return 1; }
  firstwep = TP->query_weapon();
  if(!firstwep) {
    write("You must wield a weapon before you can offwield.\n");
    return 1; }
  if(firstwep->two_handed()) {
    write("You cannot offwield while wielding a two-handed weapon.\n");
    return 1; }
  if(wep->query_wielded()) {
    write("You cannot offwield a wielded weapon.\n"); return 1; }
  if(wep->offwield_function() == 2) {
    write("You cannot offwield this weapon.\n"); return 1; }
  TP->offwield(wep);
  write(BOLD+RED+"Dark powers combine with your soul, to let you offwield "+
      wep->short()+".\n"+NORM);
  shadow = clone_object("/players/pestilence/closed/guild/obj/wepshad.lpc");
  shadow->start_wep_shadow(wep);
  mygob->set_offwep(wep);
  mygob->set_firstwep(firstwep);
  firstshad = clone_object("/players/pestilence/closed/guild/obj/wepshad2.lpc");
  firstshad->start_wep_shadow(firstwep);
  return 1; }
*/

save_me(object ob) {
  string file;
  int tellme;
  if(ob) tellme++;
  if(!ob) ob = ENV();
  file = "players/pestilence/closed/dark/members/" + ob->query_real_name();
  if(!save_object(file)) {
    if(tellme) tell_object(ob,"Save error...\n");
    return 0;
    }
  if(tellme) tell_object(ob,"Saving the Dark Order...\n");
  write(""+HIK+"Saving the Dark Order"+NORM+"...\n");
  return 1;

}


restore_me(object ob) {
  string file2;
  int tellme;
  if(ob) tellme++;
  if(!ob) ob = ENV();
  file2 = "players/pestilence/closed/dark/members/" + ob->query_real_name();
  if(!restore_object(file2)) {
  if(tellme) tell_object(ob,"Dark order restoration order...\n");
    return 0;
    }
  if(tellme) tell_object(ob,"Your mark of the Dark Order darkens...\n");
  return 1;
}
/*
restore_me(object ob) {
  string file2;
  file2 = "players/pestilence/closed/dark/members/" + ob->query_real_name();
  if(!restore_object(file2)) {
    tell_object(ob,"Dark order restoration order...\n");
    return 0;
    }
  tell_object(ob,"Your mark of the Dark Order darkens...\n");
  return 1;
}
*/

/*
stun(str) {
int dam, armorchange, wepchange;
object ob, ob2, att;

ob = present("dknight_ob",this_player());
dam = random(5);
armorchange = 2;
wepchange = 1;

if(this_player()->query_guild_rank() < 7){ write("You can't use ability yet.\n"); return 1; }
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Stun who???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_sp() < 25) {
write("You do not have the spell points available for this spell.\n");


return 1; }
if (!att) { write ("There is no "+str+" here to target"); return 1; }
if(att->is_player()) {write("You may not cast this spell at a player.\n");
return 1; }
  if(!att->query_attack()) att->attack_object(tp);
if(!(ob2 = present("ac_check",att))) {
  ob2 = clone_object("/players/pestilence/closed/dark/obj/ac_check.lpc");
  ob2->move_object(resolve_ob(att));
}
  if(ob2->query_ac_times() > 1) {
  write("You can only stun the same target twice.\n");
  return 1; }
  else ob2->add_ac_times(1);
  
  tp->add_spell_point(-25);

write("\nYou reach into your very soul, pulling out "+HIK+"darkness"+NORM+".\n"+
      "You totally stun "+att->query_name()+" with your "+HIK+"dark"+NORM+" magic.\n");
write(att->query_name() +" breaks down, and becomes slower.\n");
say(tp->query_name() +" gathers power from "+HIK+"dark"+NORM+" within the depths of "+HIR+"Hell"+NORM+".\n");
say(tp->query_name() +" weakens "+att->query_name()+" with a "+HIK+"dark"+NORM+" incantation.\n");
  att->set_ac(att->query_ac() - armorchange);
  att->set_wc(att->query_wc() + wepchange);
return 1; }
*/
