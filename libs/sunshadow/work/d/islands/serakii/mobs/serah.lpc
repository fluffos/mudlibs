
//Serah
#include <std.h>
#include <daemons.h>
#include "../serakii.h"
inherit MONSTER;

object *weapon, ob;
int stage = 0;

void create(){
   ::create();
   set_id(({"serah","Serah Kava", "archmage", "archmage of oblivion"}));
   set_name("Serah Kava");
   set_short("%^C031%^Serah Kava%^C074%^,%^CRST%^ "+
   "%^C074%^Archmage of %^C246%^Oblivion%^CRST%^");
   set_long("Is human, dressed in a %^C073%^light silk robe%^CRST%^ "+
   "tied around her waist with a %^C087%^bright sash%^CRST%^. She is "+
   "stunningly beautiful with %^C179%^doll %^CRST%^like features "+
   "and %^C230%^porcelain skin%^CRST%^. %^C242%^Long black hair%^CRST%^ is "+
   "tied up in a complicated braid. She has a %^C059%^short staff%^CRST%^ "+
   "in one hand that glows with a %^C195%^soft light%^CRST%^.\n");
   set_race("human");
   set_body_type("human");
   set_gender("female");
   set_alignment(3);
   set_size(2);
   set_class("fighter");
   set_class("mage");
   set_mlevel("fighter",70);
   set_mlevel("mage",70);
   set_skill("perception",55);
   set_guild_level("fighter",70);
   set_guild_level("mage",70);
   add_search_path("/cmd/fighter");
   add_search_path("/cmd/mage");
   set_hd(70,20);
   set_spells(({
     "black tentacles",
     "fester",
	 "massacre"
     "ghoul touch",
     "meteor swarm",
     "frost orb",
     "greater ruin",
     "ray of enfeeblement",
     "touch of idiocy",
     "horrid wilting", 
   }));
   
   set_spell_chance(100);
   set_stats("strength",25);
   set_stats("constitution",25);
   set_stats("dexterity",15);
   set_stats("charisma",19);
   set_stats("intelligence",30);
   set_stats("wisdom",19);
   
   set_max_hp(63500);
   set_hp(query_max_hp());
   set_overall_ac(-45);
   set_exp(3000000);

   set_mob_magic_resistance("high");

   set_property("no death", 1);
   set_property("no fear", 1);
   set_property("fear_immunity", 1);
   set_property("no bows", 1);
   set_property("no knockdown", 1);
   set_property("no trip", 1);
   set_property("no tripped", 1);
   set_property("no paralyze", 1);
   set_property("no steal", 1);
   set_property("no dominate", 1);
   set_property("no hold", 1);
   set_property("no_random_treasure", 1);
   set_property("hidden inventory", 1);
   set_property("cast and attack", 1);
   set_property("darkvision", 1);
   set_property("disease immunity", 1);
   set_property("poison immunity", 1);
   set_property("darkvision", 1);
   set_property("swarm", 1);
   set_true_seeing(1);


   set_skill("perception",50);
   command("speak wizish");
   command("speech %^C187%^speak in a voice "+
   "like %^C172%^honey%^CRST%^");
   set("aggressive","aggfunc");
    set_func_chance(100);
   set_funcs(({
     "whistle",
     "kdit",
     "bonespike",
   }));

   set_monster_feats(({
     "toughness",
     "improved toughness",
     "damage resistance",
     "improved damage resistance",
     "regeneration",
     "perfect caster",
     "spell focus",
     "spell penetration",
     "greater spell penetration",


   }));

ob = new(OBJ"agraths_memory");
    ob->move(TO);
	
ob = new(OBJ"oni_dance");
    ob->move(TO);

ob = new(OBJ"sapper");
    ob->move(TO);


}

void init(){
   ::init();
   add_action("no_rush","crit");
   add_action("no_rush","toss");
   add_action("no_rush","throw");
}

int no_rush(string str){
   string player_name;
   player_name = this_player()->query_name();
   if(player_name="chitering gibling"){return 0;}
   force_me("say Oh I do not think so "+ player_name +".%^RESET%^");
    tell_object(this_player(), "%^C139%^Serah grabs you with a %^C129%^vortex %^C139%^of arcane force!%^CRST%^\n%^CRST%^");
    tell_room(this_object(), "%^C139%^Serah grabs %^CRST%^" + player_name + "%^C129%^ in a vortex of arcane force!%^CRST%^\n",this_player());
   this_player()->cause_typed_damage(this_player(), this_player()->return_target_limb(), random(200)+100, "force");
   return 1;
}

void bonespike(object target){
    // Targetted damage or death

    object room;

    room = environment(this_object());

   if(!objectp(target)) return 0;
   if(!objectp(TO)) return 0;
    if(!target->fort_save(60)) {
      if(target->query_property("no death")){
         tell_object(target,"%^C186%^Serah chants and %^C195%^spikes of bone%^C186%^ start "+
		 "to emerge from the wall! Your whole body is wracked with %^C088%^pain %^C186%^as "+
		 "one skewers you and holds you to the wall.%^CRST%^");
         tell_room(room,"%^C195%^Spikes of bone%^C186%^ emerge from the wall "+
		 "and impale%^CRST%^ "+target->QCN+"%^C186%^ against the wall!%^CRST%^",target);
         target->cause_typed_damage(target, target->return_target_limb(), random(300)+350, "piercing");
         target->set_tripped(1,"%^C186%^You are still %^C195%^impaled %^C186%^against the wall!%^CRST%^");
         return(random(3)+1);
      }
         tell_object(target,"%^C186%^Serah chants and %^C195%^spikes of bone%^C186%^ start "+
		 "to emerge from the wall! %^C186%^Your world goes black as a bone skewer "+
		 "%^C088%^impales%^C186%^ your %^C195%^skull%^C186%^...%^CRST%^");
         tell_room(room,"%^C186%^A %^C195%^skewer of bone%^C186%^ slams "+
		 "into%^CRST%^ "+target->QCN+"%^C186%^'s %^C231%^skull %^C186%^and spears "+
		 "them into the wall.%^CRST%^ "+target->QCN+"%^C186%^'s body goes limp.%^CRST%^",target);
      target->cause_typed_damage(target, "torso", random(500)+5500, "untyped");
      tell_object(target,"%^C160%^You die!%^CRST%^");
      return 1;
   }
      tell_object(target,"%^C186%^Serah chants and %^C195%^spikes of bone%^C186%^ start "+
       "to emerge from the wall! You manage to dodge the worst of it.%^CRST%^");
         tell_room(room,"%^C195%^Spikes of bone%^C186%^ emerge from the wall "+
       "and almost impale%^CRST%^ "+target->QCN+"%^C186%^ against the wall!%^CRST%^",target);
      return 1;
}


void whistle(){
    object obx;
    object bodyguard;
    object room;
    
    room = environment(this_object());
      tell_room(room,"%^C068%^Serah gestures to "+
	   "a %^C058%^cabinet %^C068%^and something skitters out.%^CRST%^");
         bodyguard = new(MOBS"gibling");
         bodyguard->move(room);
         bodyguard->move(room);
         bodyguard->set_property("minion", this_object());
         this_object()->add_follower(bodyguard);
         this_object()->add_protector(bodyguard);
         bodyguard->move(room);
      if(!random(2)){
         bodyguard = new(MOBS"rat");
         bodyguard->move(room);
         bodyguard->move(room);
         bodyguard->set_property("minion", this_object());
         this_object()->add_follower(bodyguard);
         this_object()->add_protector(bodyguard);
         bodyguard->move(room);
       }
}


void aggfunc(object targ) {
      if(wizardp(TP)) return;
      tell_object(targ,"%^C140%^Serah looks over from her %^C094%^mirror %^C140%^and sneers!%^CRST%^");
      force_me("say You will not end my research! I shall join Agrath and be together forever!");
      tell_object(targ,"%^C132%^Serah pulls %^C147%^arcane force%^C132%^ around her and lifts off her feet%^CRST%^");
      force_me("kill " + TPQN + " ");
      force_me("watch");
      call_out("whistle",1);
}

int die(object ob){
   object construct;
   object room;
   int power;
    
   room = environment(this_object());

   if(stage == 0)
   {
      tell_room(room, "%^C069%^One of the %^C241%^half-built "+
	   "constructs %^C069%^shambles out of the pile and glows "+
	   "with %^C061%^fell energy%^C069%^!%^CRST%^");
      tell_room(room, "%^C187%^Sarah speaks in a voice like %^C172%^honey %^CRST%^'Echo save me!'");
	   construct = new(MOBS"echo");
      construct->move(room);
      construct->set_property("minion", this_object());
      this_object()->add_follower(construct);
      this_object()->add_protector(construct);
      stage = 1;
      TO->set_hp(query_max_hp() / 2);
    return 0;
   }

   if(stage == 1)
   {
      tell_room(room, "%^C115%^The %^C094%^closet %^C115%^explodes "+
	   "and a %^C244%^half-built construct%^C115%^ leaps out at you!%^CRST%^");
      tell_room(room, "%^C187%^Sarah speaks in a voice like %^C172%^honey %^CRST%^'Sliver KILL THEM!'");
	   construct = new(MOBS"sliver");
      construct->move(room);
      construct->set_property("minion", this_object());
      this_object()->add_follower(construct);
      this_object()->add_protector(construct);
      stage = 2;
      TO->set_hp(query_max_hp() / 2);
      return 0;
   }

   // final death
   tell_room(room, "%^C075%^Serah collapses onto the %^C059%^ground%^C075%^, "+
   "reaching desperately towards the pile of half-built %^C241%^constructs%^C075%^.%^CRST%^");
      tell_room(room, "%^C187%^Sarah speaks in a voice like %^C172%^honey %^CRST%^'Please no, I was so close...'");
   tell_room(room, "%^C153%^Her whole form starts to shudder and %^C062%^fell "+
   "energy%^C153%^ starts to erupt into small %^C056%^fires %^C153%^along her body.%^CRST%^");
      tell_room(room, "%^C187%^Sarah speaks in a voice like %^C172%^honey %^CRST%^'Agrath...'");
   power = 10;
   WORLD_EVENTS_D->kill_event("Ended the Archmage of Oblivion");
   WORLD_EVENTS_D->inject_event((["Ended the Archmage of Oblivion" : (["start message" : "%^C062%^Arcane power%^C081%^ explodes over "+
      "the %^C022%^forest%^C081%^ of %^C061%^Serakii %^C081%^as the %^C246%^archmage of Oblivion%^C081%^ is killed! The power spreads "+
      "across the realm and all %^C087%^experience %^C081%^gained will award an additional %^CRST%^" + power + "%^C081%^ percent!%^CRST%^",
      "event type" : "exp bonus", "length" : 120, "notification" : power + "% Bonus Exp",
      "event name" : "Ended the Archmage of Oblivion", "modifier" : power, "announce" : 1, "announce to" : "world" ]), ])
   );


   return ::die();

}

void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("knockdown "+targ->query_name());
}
