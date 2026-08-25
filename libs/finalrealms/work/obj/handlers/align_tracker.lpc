#include "alignment.h"
inherit "/std/object";

int *align_array = ({ });

string curved_align_string(object ob);

void save_function() {
  if(sizeof(align_array)) 
    save_object("/save/aligntracker");
}

void restore_function() {
  if(!sizeof(align_array))
    restore_object("/save/aligntracker");
}
void reset_align_array() {
  int i;
  for(i=0; i<sizeof(align_array); i++)
    align_array[i] = 330;
  save_function();
}

void setup() {
    set_name("aligntracker");
    restore_function();
}

int check_player_al(object leave) {
  int i,tim_on,reset_time,aint;
  if(leave) {
    if(!interactive(leave)) return 0;
    if(leave->query_creator() ||
      strsrch(leave->query_name(),"test") != -1) return 0;
    if(!(leave->query_property("alignment_reset2"))) {
      leave->add_property("alignment_reset2",leave->query_time_on()+1);
      leave->remove_property("alignment_reset");
      return leave->set_align(0);
    }
//tell_object(find_player("anirudh"),leave->query_time_on()+" "+leave->query_property("alignment_reset2")+" "+leave->query_name()+"\n");
    if(!(leave->query_timed_property("alignment_checked2")) &&
      ((tim_on=leave->query_time_on()) < -AL_CHK_RATE) &&
      (((reset_time=leave->query_property("alignment_reset2"))-tim_on)
      >AL_CHK_RATE)) {
      if((aint=leave->query_align_int()) > 0.9*MAX_ALIGN_INT) return 0;
      if(aint < -0.9*MAX_ALIGN_INT) return 0;
      restore_function();
      if(sizeof(align_array) <= NUM_SAVED) {
        for(i=sizeof(align_array);i<=NUM_SAVED;i++)
          align_array += ({330});
      }
      for(i=NUM_SAVED-1;i>=0;i--) {
        align_array[i+1] = align_array[i];
      }
      align_array[0] = (aint+0.0)/(tim_on-reset_time+0.0)*(0.0-TDIV);
      leave->add_timed_property("alignment_checked2",1,AL_CHK_RATE/2);
    }
    save_function();
    return align_array[0];
  }
  return 0;
}

int curved_align_num(object obj) {
  switch(curved_align_string(obj)) {
    case "diabolical":
      return 10000;
    case "extremely evil":
      return 3500;
    case "very evil":
      return 1500;
    case "evil":
      return 600;
    case "neutral":
      return 0;
    case "good":
      return -600;
    case "very good":
      return -1500;
    case "extremely good":
      return -3500;
    case "angelic":
      return -10000;
  }
  return 0;
}

string curved_align_string(object obj) {
  int i, lt, al, aint;
  restore_function();
  if(!(obj->query_time_on())) return 0;

  if(obj) {
    aint = obj->query_align_int();
    if(aint > 0.9*MAX_ALIGN_INT) return "diabolical";
    if(aint < -0.9*MAX_ALIGN_INT) return "angelic";
    al = (aint+0.0)/(obj->query_time_on()-(obj->
         query_property("alignment_reset2"))+0.0)*(0.0-TDIV);
  }
  else return 0;
      if(sizeof(align_array) <= NUM_SAVED) {
        for(i=sizeof(align_array);i<=NUM_SAVED;i++)
          align_array += ({330});
      }
  for(i=0;i<NUM_SAVED;i++) {
    if(al <= align_array[i])
      lt++;
  }
  lt = lt*100/NUM_SAVED;
  switch(lt) {
    case -1 .. A_E_E:
      return "diabolical";
    case 1+A_E_E .. A_V_E:
      return "extremely evil";
    case 1+A_V_E .. A_EV:
      return "very evil";
    case 1+A_EV .. A_NE:
      return "evil";
    case 1+A_NE .. A_GO:
      return "neutral";
    case 1+A_GO .. A_V_G:
      return "good";
    case 1+A_V_G .. A_E_G:
      return "very good";
    case 1+A_E_G .. A_AN:
      return "extremely good";
    default:
      return "angelic";
    break;
  }
}

int *query_align_array() {
    return align_array;
}

void dest_me() {
    save_function();
    ::dest_me();
}
