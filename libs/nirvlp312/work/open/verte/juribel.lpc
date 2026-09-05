#include "../define.h"

int flames;
#define MLOG "/players/vertebraker/log/Monster"
inherit "/obj/monster";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("juribel");
   set_alias("ancient gypsy");
   set_alt_name("gypsy");
   set_gender("male");
   set_short("Juribel the Gypsy");
   set_long(
      "  Flowing purple robes have wrapped themselves overtop\n"
      +"of the shoulders of this wizened old man.  A glint in his\n"
      +"eye belies that he may provide somewhat of a fight, for\n"
      +"those who are foolish enough to attack him.  He holds\n"
      +"a thin hickory staff and a golden earring is in his left\n"
      +"lobe.  Dark grey hair cascades down his back.\n" +
      "He looks a little different.\n");
   set_race("human");
   set_level(20);
   MO(CO(OBJ_DIR+"staff"),TO);
   MO(CO(OBJ_DIR+"j_robes"),TO);
   MO(CO(OBJ_DIR+"j_earring"),TO);
   init_command("wield staff");
   init_command("wear robes");
   init_command("wear earring");
   set_hp(900+random(250));
   add_money(200+random(100));
   set_wc(38);
   set_ac(23);
   set_chat_chance(10);
   set_a_chat_chance(20);
   load_chat("Juribel smiles faintly at you.\n");
   load_chat("Juribel asks, \"What may I help you with my son?\"\n");
   load_chat("Juribel says, \"I built this village... Look how it has taken shape...\"\n");
   load_chat("Juribel says, \"Ask me about anything.. I will try to answer...\"\n");
   load_chat("Juribel warns, \"Beware the swamp...\"\n");
   load_chat("Juribel asks, \"Where has little Celia gone now?\"\n");
   load_a_chat("Juribel's eyes seem to roll back in his head in meditation.\n");
   load_a_chat("Juribel mutters a few gutteral words.\n");
   load_a_chat("Juribel's face seems to deepen in concentration.\n");
   set_chance(40);
   set_spell_dam(90);
   set_spell_mess1("Juribel casts a sonic blast upon his foe!\n");
   set_spell_mess2("You are hit by a sonic blast!\n");
   set_ac_bonus(12);
   set_wc_bonus(40);
   set_dead_ob(TO); }

monster_died() {
    if(attacker_ob) write_file(MLOG, HIB + "[" + NORM + ctime()[4..15] + HIB + "] " + NORM + (string)capitalize(attacker_ob->query_real_name()) + " [" + (int)attacker_ob->query_level() + "+" + (int)attacker_ob->query_extra_level() + "] - Juribel.\n");
   tell_room(USER,

      "As you strike Juribel for the last time, he smiles faintly.\n");
   if(!random(3)) {
     object ob, ob2;
     tell_room(USER, "\n\t\t"+HIY+" | || | | || | | | | || \n\n" + NORM);
     tell_room(USER, "\n\tLightning soars from the heavens!\n\n");
     ob=first_inventory(USER);
     while(ob) { ob2=next_inventory(ob);
       if(living(ob) && (ob != this_object()))
         ob->hit_player(60 + random(30), "other|lightning");
         ob=ob2;
      }
    }
    tell_room(USER,
      "A wisp of smoke arises from the ground and Juribel disappears,\n"+
      " leaving his items.\n");
   USER->new_long();
   destruct(present("corpse",USER)); }

heart_beat() {
   if(attacker_ob) {
      switch(random(4)) {
         case 0: do_heal(); break;
         case 1: check_flames(); break;
         case 2: do_ac_increase(); break;
         case 3: do_wc_increase(); break; } }
   ::heart_beat(); 
   if(armor_class > 16) armor_class = 16;
   if(weapon_class > 38) weapon_class = 28; }

do_heal() {
   tell_room(USER,
      "Juribel quietly intones to himself.\n"+
      "A sudden look of rejuvenation comes to his face.\n");
   heal_self(25); }

check_flames() {
   if(!flames) cast_flames();
   else do_wc_increase(); }
cast_flames() {
   string idiot;
   if(attacker_ob) idiot = attacker_ob->QN;
   tell_room(USER,
      RED+"Juribel's eyes blaze a deep crimson....\n"+NORM+
      "He mutters a few words and points at "+idiot+"...\n");
   tell_room(USER,
      BOLD+BLK+"\n\nShadowy flames erupt all over "+idiot+"!\n\n"+NORM,({ attacker_ob }));
   tell_object(attacker_ob,BOLD+BLK+"\n\nShadowy flames erupt all over you!\n\n\n"+NORM);
   MO(CO(OBJ_DIR+"spell_flames"),attacker_ob); flames = 1; }

do_ac_increase() {
   tell_room(USER,
      "Juribel mutters a few words.\n"+
      "The environment seems to "+BLU+"  ri P p L e "+NORM+"  around him!\n");
   armor_class += 20; }

do_wc_increase() {
   tell_room(USER,
      "Juribel utters a small phrase and rubs a small powder over his weapon.\n"+
      "The hickory staff glows with power!\n");
   weapon_class += 30+random(20); }

ask(str) {
   string x;
   if(!str) return;
   str = LOWER(str);
   switch(random(3)) {
      case 0: tell_room(USER,"Juribel furrows his brow in concentration.\n"); break;
      case 1: tell_room(USER,"Juribel says: \"hmm...\"\n"); break;
      case 2: tell_room(USER,"Juribel smiles and nods...\n"); break; }
   if(sscanf(str,"%sswamp%s",x,x)) {
      answer("swamp");
      return 1; }
   if(sscanf(str,"%svillage%s",x,x)) {
      answer("village");
      return 1; }
   if(sscanf(str,"%scelia%s",x,x)) {
      answer("celia");
      return 1; }
   answer("nothing");
   return 1; }

answer(str) {
   switch(str) {
      case "swamp": call_out("swamp",3); break;
      case "village": call_out("village",3); break;
      case "celia": call_out("celia",3); break;
      case "nothing": call_out("nothing",1); break; } }

swamp() {
   tell_room(USER,"Juribel says:\n\n"+
      "\" The swamp holds many mysteries and secrets.  Legend speaks of\n"
      +"   evil monsters that live within, but we have not penetrated that\n"
      +"   deep within its clutches.  Our guards are the only ones excluding\n");
   tell_room(USER,
      "   I who have ventured within, and even we have not gotten very far.\n"
      +"   The few remaining documents about the swamp have referred to it\n"
      +"   as the Shi'ah SwampLands, the reasons for which I don't even\n");
   tell_room(USER,
      "   know about.\"\n"
      +"\n\n\" Some of the villagers believe Celia is there.\"\n\n"); return 1; }

village() {
   tell_room(USER,"Juribel says:\n\n"+
      "\" I established this village many years ago as I fled from\n"
      +"   Gurther infestation within my native land.\"\n\n");
   tell_room(USER,
      "He frowns darkly.\n\n"+
      "\" I established a refuge near the swamp because I believed that the\n"
      +"Gurthers would not follow me here.   I was correct.  But due to the\n");
   tell_room(USER,
      "recent population boom, we need to expand.  Our few huts that have\n"
      +"been erected are not large enough.  And I wish to go back to my native\n");
   tell_room(USER,
      "homeland to find any other survivors of the attacks.  All this\n"
      +"has been waylaid by the disappearance of Celia.\"\n\n");
   return 1; }

celia() {
   tell_room(USER,"Juribel says:\n\n"+
      "\" Celia is a young child from our small village.  Her mother worries\n"
      +"  that she may have been lost to the SwampLands, but I cannot sense\n");
   tell_room(USER,"  her death.  I feel she is very much alive, although scared.  We\n"
      +"  sent a few of our remaining guards to patrol the swamp, looking\n"
      +"  for her.  They have not yet returned.\"\n\n");
   return 1; }

nothing() {
   switch(random(3)) {
      case 0: tell_room(USER,"Juribel says, \"On second thought, I know nothing about that.\"\n"); break;
      case 1: tell_room(USER,"Juribel says, \"Sorry.  I honestly don't remember.\"\n"); break;
      case 2: tell_room(USER,"Juribel says, \"Hmm.. I don't think I know anything about that.\"\n"); break;
   }
   return 1; }

init() {
   ::init();
   add_action("ask","ask"); }
