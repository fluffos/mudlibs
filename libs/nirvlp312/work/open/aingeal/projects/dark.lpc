#define ETO environment(this_object())
#define SAVE "players/pestilence/closed/dark/members/"
#define tpn      ENV()->query_real_name()
#include "/players/pestilence/define.h"
#include "/players/pestilence/closed/dark/obj/id.h"
#include "/players/pestilence/closed/dark/obj/weapon.h"
#include "/players/pestilence/closed/dark/obj/init.h"
#include "/players/pestilence/closed/dark/obj/heartbeat.h"
#include "/players/pestilence/closed/dark/obj/action.h"
#include "/players/pestilence/closed/dark/obj/slash.h"
#include "/players/pestilence/closed/dark/obj/demon.h"
#include "/players/pestilence/closed/dark/obj/mud_who.h"
#include "/players/pestilence/closed/dark/obj/darken.h"
#include "/players/pestilence/closed/dark/obj/decorpse.h"
#include "/players/pestilence/closed/dark/obj/misc.h"
#include "/players/pestilence/closed/dark/obj/stalk.h"
#include "/players/pestilence/closed/dark/obj/torment.h"
#include "/players/pestilence/closed/dark/obj/dhelp.h"
#include "/players/pestilence/closed/dark/obj/distraught.h"
#include "/players/pestilence/closed/dark/obj/punch.h"
#include "/players/pestilence/closed/dark/obj/stun.h"
#include "/players/pestilence/closed/dark/obj/offwield.h"
#include "/players/pestilence/closed/dark/obj/fatal.h"
#include "/players/pestilence/closed/dark/obj/enrage.h"
#include "/players/pestilence/closed/dark/obj/score.h"
#include "/players/pestilence/closed/dark/obj/wound.h"
#include "/players/pestilence/closed/dark/obj/align.h"
reset(arg) {
  if (arg) return 0;
/*
restore_object("players/pestilence/closed/dark/members/"+this_player()->query_real_name());
*/
call_out("align_hurt",3);
call_out("light_damage",3);
set_heart_beat(1);
}

query_auto_load() {
    return "/players/pestilence/closed/dark/dark.c:";
}

drop() {return 1;}

light_damage() {
int hurt;

if(!environment()) return 1;
if(!environment(environment()) || environment(environment())->no_light_damage()) return (call_out("light_damage", 3), 1);
hurt = set_light(0);
if(environment(TO)->query_level() < 50 &&
  !environment(TO)->query_ghost()) {

  if(hurt > 1)
  tell_object(environment(TO),
    HIR+"You feel the light scorch your flesh making it bubble...\n"+NORM);

if(hurt < -1 &&
  environment(TO)->query_mhp() != environment(TO)->query_hp())
    tell_object(environment(TO),
      HIK+"Darkness comforts your soul...\n"+NORM);
  if((environment(TO)->query_hp() - hurt) > 0) {
    if(hurt > 5) hurt = 5;
    if(hurt < -5) hurt = -5;
if(environment(TO)->query_interactive()){
    environment(TO)->add_hit_point(-hurt);
    environment(TO)->add_spell_point(-hurt);
}
  }
call_out("light_damage",3);
return 1; }
}

align_hurt() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    if(USER->query_alignment() > 250) {
    tell_object(environment(this_object()),
      ""+HIK+"You feel pain from the goodness inside you"+NORM+".\n");
    if(interactive(ETO)) 
    ETO->hit_player(20 + random(20), "other|poison");
    call_out("align_hurt",60);
    return 1; }
  }
}
}

/*
score(){
        write(" Name: \n");
        if(USER->query_pretitle()) write(""+USER->query_pretitle()+" ");
        write(""+capitalize(USER->query_name())+" ");
        if(USER->query_title())write(""+USER->query_title()+" ");
        write("("+USER->query_al_title()+")\n  [Level: "+USER->query_level()+"+ "+USER->query_extra_level()+"\n");
        write("_____________________________________________________\n");
        write(BLU+"HP"+NORM+BOLD+"("+NORM+HIB+USER->query_hp()+NORM+BOLD+"/"+NORM+HIB+USER->query_mhp()+NORM+BOLD+")"+NORM+"\t\t");
        write(RED+" SP"+NORM+BOLD+" ("+NORM+HIR+USER->query_sp()+NORM+BOLD+"/"+NORM+HIR+USER->query_msp()+NORM+BOLD+")"+NORM+"\t\n");
        write(
                " Food["+BOLD+USER->query_stuffed()*100/(USER->query_level()*8)+NORM+"%] "+
                " Soak["+BOLD+USER->query_soaked()*100/(USER->query_level()*8)+NORM+"%] "+
        " Intox["+BOLD+USER->query_intoxination()*100/(USER->query_level()+3)+NORM+"%]\n");

        write(" ___________________________________________________\n");
        write("Experience ["+USER->query_exp()+"]     Coins ["+USER->query_money()+"]  \n\n");
        write("Gxp : "+TP->query_guild_exp()+"\t\tGlvl: "+TP->query_guild_rank()+"\n"); 
        if(USER->query_quest_point())
        write("QPS        ["+USER->query_quest_point()+"]\n");
        write("\n");
        USER->show_age();
        write("\n");
        USER->check_fight_area();
        if(USER->query_fight_area()){
                write(""+HIR+"PK Area"+NORM+"\n");
        }
        else{
                write(""+HIB+"NON-PK Area"+NORM+" \n");
        }
        return 1;
}
*/
