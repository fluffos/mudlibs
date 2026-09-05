/************************************************************************
*  The Power Ranger Guild Weapon                                        *
*  Created by Beck/Russ Warren for Nirvana                              * 
*  Last Changed 6/27/99                                                *
*************************************************************************/
nosave status wielded;
nosave object wielded_by;
nosave int broke;
nosave int eff_wc;
nosave int misses,hits;
nosave int save_flag,class_of_weapon;
nosave object hit_func;
nosave string type;
nosave string *message_hit;
nosave object PrevWeapon;
nosave int TacticAModifier;
nosave int TacticDModifier;
nosave int Encourage;
nosave object RangerTacticAttack;
nosave object EncourageAttack;

weapon_class() {
   return class_of_weapon;
}
hit(attacker)
{
   if (hit_func)
      return call_other(hit_func,"weapon_hit",attacker);
   return 0;
}
set_class(c) { class_of_weapon = c; }

un_wield(){
   if(Weapon){
      PrevWeapon = Weapon;
      if(!Weapon->query_wielded())
         Weapon = 0;
   }
   call_out("re_wield",2);
}
re_wield(){
   PrevWeapon = 0;
   ENVOB->wield(TO,1);
}
weapon_breaks(){
   if(broke) return 1;
   return 1;
}
count_misses() {
   misses += 1;
   return 1;
}
count_hit_made(w) {
   hits += 1;
   eff_wc=((hits-1)*eff_wc + w)/hits;
   return 1;
}
query_wear() {
   return 0;
}
add_wear(arg) {
   misses = 0;
   hits = 0;
}
fix_weapon() {
   if (!broke) {
      return 0;
   }
   broke = 0;
   return 1;
}
re_break() { 
   broke = 1;
   return 1;
}

query_broke(){return broke;}

SWeapon(ob){
   Weapon = ob;
}
Weapon(){
   return Weapon;
}
SPrevWeapon(ob){
   PrevWeapon = ob;
}
PrevWeapon(){
   return PrevWeapon;
}
AutoGenerate(num){
   int amount1, amount2;
   if(!num){
      write("Usage: autogen <limit> <amount>.\n");
      write("or: autogen off\n");
      return 1; 
   }
   if(num == "off"){
      write("Auto Generation is OFF.\n");
      AutoGen = 0;
      return 1;
   }
   if(sscanf(num,"%d %d",amount1,amount2) !=2){
      write("Usage: autogen <limit> <amount>.\n");
      return 1; 
   }
   if(amount1 < 20 || amount2 < 20){
      write("Both amounts must be greater than 20.\n");
      return 1;
   }
   if(amount2 > amount1){
      write("Your limit must be more than your amount.\n");
      return 1;
   }
   AutoGenLimit = amount1;
   AutoGenAmount = amount2;
   AutoGen = 1;
   write("Auto Generation set to generate <"+AutoGenAmount+"> when SPS > "+AutoGenLimit+".\n");
   return 1;
}
AutoGen(){
   if(AutoGenLimit < 20)
      return;
   if(ENVOB->SP > AutoGenLimit){
      if(ENVOB->SP > AutoGenAmount){
         ARangerPoints(AutoGenAmount);
         MASTER->APowerPoints(AutoGenAmount,RangerAlign);
         ENVOB->add_spell_point(-AutoGenAmount);
         tell_object(ENVOB,"You have generated "+AutoGenAmount+" Power Points.\n");
      }
   }
   return;
}
QPowerWeapon(){
   return PowerWeapon;
}
PowerWeapon(){
   if(!PowerWeapon){
      if(Weapon){
         write("You are already wielding "+Weapon->query_name()+"\n");
         return 1;
      }
      if(!Morphed){
         write("You can only use your Power Weapon when Morphed.\n");
         return 1;
      }
      PowerWeapon = 1;
      tell_room(ENVTP, TPNAME+" yells: Power "+RangerWeapon+"!\n");
      return 1;
   }
   PowerWeapon = 0;
   write("You put away your Power "+RangerWeapon+".\n");
   return 1;
}

SEncourage(attack, name, int num){
   int i;
   string msg;
   if(TP == ENVOB){
      i = random(3);
      msg = ENVOB->NAME+" yells: ";
      if(i == 2)
         msg += "Your days of evil are over "+name+"\n";
      else if (i == 1)
         msg += "You're never gonna win "+name+". Just give up now.\n";
      else
         msg += "Your time is up "+name+". The Power Rangers are here.\n";
      tell_room(ENV(ENVOB),msg);
      Encourage += 1;
   }
   else
      Encourage += 3;
   EncourageAttack = attack;
   if(Encourage > 3*num){
      Encourage =0;
      EncourageAttack = 0;
      tell_object(ENVOB,"You get overly excited and lose your concentration.\n");
   }
}

SRangerTactic(string str, object ob, int i, int j){
   if(!str) return;
   RangerTactic = str;
   write("You now are using "+str+" tactics.\n");
   RangerTacticAttack = ob;
   TacticAModifier = i;
   TacticDModifier = j;
   return 1;
}

QRangerTactic(){ return RangerTactic; }

query_pro_weapon(){ return 1;}

proficiency_hit(ob){
   int enemyhp, enemymhp, enemyper;
   int damage;
   int damage2;
   int temp;
   string name, attacker;
   string skill; string msg;
   mixed *skills;
   hits = 0;misses = 0;

   damage = random(4);

   damage2 = 0;

   name = ENVOB->query_name();
   attacker = (ENVOB->query_attack())->query_name();

   if(Morphed){ damage += ((ENVOB->GLEVEL)/5); }

   if(Ninja){ damage += (ENVOB->GLEVEL)/8); }

   if(PowerWeapon){
      temp = (2*KarateLevel)+random(KarateLevel);
      if(PersonalPower > temp){
         tell_object(ENVOB, "[ "+BOLD+RED+"WEAPON"+OFF+" ] You strike "+attacker+" with your Power "+RangerWeapon+"\n");
         damage2 += KarateLevel;
         damage += (2*KarateLevel);
         APersonalPower(-temp);
         ASkillExp((2*KarateLevel));
      }
   }

   if(AutoGen){
      AutoGen();
   }
   if(Weapon){
      damage += Weapon->weapon_hit(ENVOB->query_attack());
   }

   if(!Weapon){
      if(KarateLevel > random(15)){
         skill = RandomOffense();
         skills = MASTER->UseMartialArts(skill);
         damage += skills[0];
         msg = name+skills[1]+attacker+skills[2];
         if(!Spam)
            tell_object(ENVOB, "[ "+RED+"OFFENSE"+OFF+" ] "+msg+"\n");
         AMartialExp(5);
         if(KarateLevel > random(20)){
            skill = RandomOffense();
            skills = MASTER->UseMartialArts(skill);
            damage += skills[0];
            msg = name+skills[1]+attacker+skills[2];
            if(!Spam)
               tell_object(ENVOB, "[ "+RED+"OFFENSE"+OFF+" ] "+msg+"\n");
            AMartialExp(15);
            if(KarateLevel > random(25)){
               enemyhp = (ENVOB->query_attack())->query_hp();
               enemymhp = (ENVOB->query_attack())->query_mhp();
               enemyper = (enemyhp * 100)/enemymhp;
               if(enemyper < 15 && enemyhp < 40){
                  damage2 += enemyhp;
                  tell_object(ENVOB, "[ "+BOLD+RED+"FATAL"+OFF+" ] You finish "+attacker+" off with a deadly blow\n");
                  AMartialExp(30);
               }
               else {damage -=2; }
            }
         }
      }
   }
   if(RangerTactic){
      if(RangerTactic == "parry"){
         if(TP->query_alt_attack() && TP->query_alt_attack() != TP->query_attack()){
            TacticAModifier += -10;
            TacticDModifier += 5;
         }
         else{
            tell_object(ENVOB,"[ "+BOLD+RED+"TACTIC ERROR"+OFF+" ] You make a critical Tactical Error\n");
            TacticAModifier += -20;
            TacticDModifier += -10;
            RangerTactic = 0;
         }
      }
      else if(RangerTactic == "Wolfpack"){
         if(ENVOB->query_attack() == RangerTacticAttack){
            if((ENVOB->query_attack())->query_attack() != ENVOB ){
               tell_object(ENVOB,"[ "+BOLD+RED+"WOLFPACK"+OFF+" ] You smash "+attacker+" while they are distracted\n");
            }
            else{
               tell_object(ENVOB,"[ "+BOLD+RED+"TACTIC ERROR"+OFF+" ] You make a critical Tactical Error\n");
               TacticAModifier += -20;
               TacticDModifier += -10;
               RangerTactic = 0;
            }
         }
         else {
            TacticAModifier = 0;
            TacticDModifier = 0;
            RangerTactic = 0;
            RangerTacticAttack = 0;
         }
      }
      else
         tell_room(ENVOB,"Error code 2  ... Mail beck this info.\n");
   }
   
   if(Encourage){
      if(ENVOB->query_attack() == EncourageAttack){
         tell_object(ENVOB,BOLD+BLUE+"["+OFF+RED+" ENCOURAGE "+OFF+BOLD+BLUE+"]"+OFF+" You fight with extra vigor.\n");
         if(Encourage > 15)
            Encourage = 15; 
         damage += Encourage;
         Encourage -= 2;
         if(Encourage < 0)
            Encourage = 0;
      }
      else{
         Encourage = 0;
         EncourageAttack = 0;
      }
   }

   ACombatExp(damage);
   if(TacticAModifier > 15)
      TacticAModifier = 15;

   damage += TacticAModifier;

   damage += KarateLevel;

   damage += (KarateExtraLevel/2);

   if(damage < 0) damage = 0;
   ENVOB->set_spell_dam(damage2); 
   if(damage+damage2 > 50){
      damage = 50-damage2;
   }
   return damage;
}

RandomOffense(){
   int i;
   i = sizeof(Offense);
   i = random(i);
   return Offense[i];
}
query_message_hit(tmp) {
   string *mess;
   mess = ({" with hurricane force",BLINK+RED+"DISEMBOWELED"+OFF});
   if (tmp < 32) { mess = ({" with deadly precision",BOLD+RED+"GORED"+OFF}); }
   if (tmp < 29) { mess = ({" to small fragments","massacre"}); }
   if (tmp < 25) { mess = ({" with a bone crushing sound","smashed"}); }
   if (tmp < 22) { mess = ({"","laid the "+GREEN+"Smack"+OFF+" down on"}); }
   if (tmp < 19) { mess = ({" very hard","hit"}); }
   if (tmp < 16) { mess = ({" with reckless abandon","went off on"}); }
   if (tmp < 13) { 
      mess = ({" with a brilliant display of martial arts","stunned"}); }
   if (tmp < 10) { mess = ({"","hit"}); }
   if (tmp < 5) { mess = ({"","beat up"});}
   if (tmp < 3) { mess = ({" with a weak attack","grazed"}); }
   if (tmp == 1) { mess = ({" in the stomach","tickled"});}
   return mess;
}
check_ranger_kill(str){
   object ob;
   ob = present(str, environment(this_player()));
   if(!ob){ return; }
   if(RangerAlign == "Power Ranger"){
      if(Morphed){
         if(ob->query_alignment() > 10){
            write("You can not bring yourself to attack that riteous being.\n");
            ASkillExp(-20);
            ACombatExp(-20);
            return 1;
         }
         if(random(100) < KarateLevel){
            tell_room(ENV(TP), TP->NAME+" yells: Your days of evil are over "+ob->NAME+"!\n");
         }
      }
      if(ob->RangerNPC()){
         write("Zordon tells you: You better not kill fellow Power Rangers!!!\n");
         return 1;
      }
   }
   return;
}

