#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"nunchaku", "nunchucks"}));
set_name("nunchaku");
set_short("%^BOLD%^nunchaku%^RESET%^");
set_long("The ancient weapon of the monk, the nunchaku consists of two sticks joined by a chain.  The weapon is extremely difficult to master but its combat potential is nearly unmatched when used properly.");
set_weight(7);
set_value(20);
set_wc((this_player()->query_level()*2/5)+5);
set_ac(3);
set_type("blunt");
set_hands(2);
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object  ob, atk;
   ob = this_player()->query_current_attacker(); 
  
atk = (object)this_player()->query_current_attacker();
if(random(100) > 78) {


if(this_player()->query_level() < 5) {

    
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10));
   
 }

 
if(this_player()->query_level() < 9 && this_player()->query_level() > 4) {
switch (random(3)) {
     case 1:  // Level 5-8
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10)+10);
       break;
     case 2:  // Level 5-8
       write( "Your nunchaku hit "+ob->query_cap_name()+" with extra force.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10)+20);
       break;
     default: // Level 5-8
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = 
(this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10)+10);     
   }
 }
   

if(this_player()->query_level() < 13 && this_player()->query_level() > 8) {
switch (random(4)) {
     case 1:  // Level 9-12
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10)+20);
       break;
     case 2:  // Level 9-12
       write( "Your nunchaku hit "+ob->query_cap_name()+" with extra force.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10)+27);
       break;
      case 3:  // Level 9-12
       write( "You sneak in a quick kick hitting "+ob->query_cap_name()+" solidly.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+25);
       break;
    default: // Level 9-12
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = 
(this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10)+20);     
   }
 }


if(this_player()->query_level() < 17 && this_player()->query_level() > 12) {
switch (random(5)) {
     case 1:  // Level 13-16
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10)+25);
       break;
     case 2:  // Level 13-16
       write( "Your nunchaku hit "+ob->query_cap_name()+" with extra force.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10)+35);
       break;
      case 3:  // Level 13-16
       write( "You sneak in a quick kick hitting "+ob->query_cap_name()+" solidly.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+35);
       break;
      case 4:  // Level 13-16
       write( "You whirl your nunchaku striking "+ob->query_cap_name()+" with two successive shots.");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+40);
       break; 
   default: // Level 13-16
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = 
(this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(10)+25);     
   }
 }


if(this_player()->query_level() < 21 && this_player()->query_level() > 16) {
switch (random(6)) {
     case 1:  // Level 17-20
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(15)+27);
       break;
     case 2:  // Level 17-20
       write( "Your nunchaku hit "+ob->query_cap_name()+" with extra force.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(15)+38);
       break;
      case 3:  // Level 17-20
       write( "You sneak in a quick kick hitting "+ob->query_cap_name()+" solidly.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+40);
       break;
      case 4:  // Level 17-20
       write( "You whirl your nunchaku striking "+ob->query_cap_name()+" with two successive shots.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+45);
       break; 
      case 5:  // Level 17-20
       write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(20)+30);
 this_player()->add_hp(result);
      break; 
   default: // Level 17-20
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = 
(this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(15)+27);     
   }
 }


if(this_player()->query_level() < 25 && this_player()->query_level() > 20) {
switch (random(7)) {
     case 1:  // Level 21-24
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(15)+27);
       break;
     case 2:  // Level 21-24
       write( "Your nunchaku hit "+ob->query_cap_name()+" with extra force.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(15)+38);
       break;
      case 3:  // Level 21-24
       write( "You sneak in a quick kick hitting "+ob->query_cap_name()+" solidly.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+40);
       break;
      case 4:  // Level 21-24
       write( "You whirl your nunchaku striking "+ob->query_cap_name()+" with two successive shots.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+45);
       break; 
      case 5:  // Level 21-24
       write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(20)+30);
 this_player()->add_hp(result);
      break; 
      case 6:  // Level 21-24
       write( "Your nunchaku strikes "+ob->query_cap_name()+" with a deep THUD.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+50);
      break;
    default:  // Level 21-24
       write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(20)+30);
 this_player()->add_hp(result);    
   }
 }


if(this_player()->query_level() < 29 && this_player()->query_level() > 24) {
switch (random(8)) {
     case 1:  // Level 25-28
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(15)+33);
       break;
     case 2:  // Level 25-28
       write( "Your nunchaku hit "+ob->query_cap_name()+" with extra force.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(15)+45);
       break;
      case 3:  // Level 25-28
       write( "You sneak in a quick kick hitting "+ob->query_cap_name()+" solidly.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+45);
       break;
      case 4:  // Level 25-28
       write( "You whirl your nunchaku striking "+ob->query_cap_name()+" with two successive shots.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+50);
       break; 
      case 5:  // Level 25-28
       write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(20)+40);
 this_player()->add_hp(result);
      break; 
      case 6:  // Level 25-28
       write( "Your nunchaku strikes "+ob->query_cap_name()+" with a deep THUD.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+55);
      break;
      case 7:  // Level 25-28
       write( "You MAUL "+ob->query_cap_name()+" repeatedly with the nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+70);
      break;
   default: // Level 25-28
write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(20)+40);
 this_player()->add_hp(result);            
   }
 }


if(this_player()->query_level() < 33 && this_player()->query_level() > 28) {
switch (random(9)) {
     case 1:  // Level 29-32
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(15)+38);
       break;
     case 2:  // Level 29-32
       write( "Your nunchaku hit "+ob->query_cap_name()+" with extra force.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(15)+48);
       break;
      case 3:  // Level 29-32
       write( "You sneak in a quick kick hitting "+ob->query_cap_name()+" solidly.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+48);
       break;
      case 4:  // Level 29-32
       write( "You whirl your nunchaku striking "+ob->query_cap_name()+" with two successive shots.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+54);
       break; 
      case 5:  // Level 29-32
       write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(25)+55);
 this_player()->add_hp(result);
      break; 
      case 6:  // Level 29-32
       write( "Your nunchaku strikes "+ob->query_cap_name()+" with a deep THUD.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+50);
      break;
      case 7:  // Level 29-32
       write( "You MAUL "+ob->query_cap_name()+" repeatedly with the nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+70);
      break;
      case 8:  // Level 29-32
       write( "With sharp precision you find a vital opening causing "+ob->query_cap_name()+" great damage.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+80);
ob->set_paralyzed(2); 
     break;   
    default: // Level 29-32
write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(25)+55);
 this_player()->add_hp(result);            
   }
 }


if(this_player()->query_level() < 37 && this_player()->query_level() > 32) {
switch (random(10)) {
     case 1:  // Level 33-36
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+38);
       break;
     case 2:  // Level 33-36
       write( "Your nunchaku hit "+ob->query_cap_name()+" with extra force.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+48);
       break;
      case 3:  // Level 33-36
       write( "You sneak in a quick kick hitting "+ob->query_cap_name()+" solidly.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(20)+53);
       break;
      case 4:  // Level 33-36
       write( "You whirl your nunchaku striking "+ob->query_cap_name()+" with two successive shots.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+55);
       break; 
      case 5:  // Level 33-36
       write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(25)+65);
 this_player()->add_hp(result);
      break; 
      case 6:  // Level 33-36
       write( "Your nunchaku strikes "+ob->query_cap_name()+" with a deep THUD.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+60);
      break;
      case 7:  // Level 33-36
       write( "You MAUL "+ob->query_cap_name()+" repeatedly with the nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+70);
      break;
      case 8:  // Level 33-36
       write( "With sharp precision you find a vital opening causing "+ob->query_cap_name()+" great damage.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+80);
ob->set_paralyzed(4); 
     break;   
      case 9:  // Level 33-36
       write( "A wicked hit with your nunchaku weakens "+ob->query_cap_name()+".");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+100);
ob->add_sp(-result); 
     break; 
    default: // Level 33-36
write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(25)+65);
 this_player()->add_hp(result);            
   }
 }


if(this_player()->query_level() < 41 && this_player()->query_level() > 36) {
switch (random(11)) {
     case 1:  // Level 37-40
       write( "You smack "+ob->query_cap_name()+" with your nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+45);
       break;
     case 2:  // Level 37-40
       write( "Your nunchaku hit "+ob->query_cap_name()+" with extra force.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+55);
       break;
      case 3:  // Level 37-40
       write( "You sneak in a quick kick hitting "+ob->query_cap_name()+" solidly.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+65);
       break;
      case 4:  // Level 37-40
       write( "You whirl your nunchaku striking "+ob->query_cap_name()+" with two successive shots.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+75);
       break; 
      case 5:  // Level 37-40
       write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(25)+85);
 this_player()->add_hp(result);
      break; 
      case 6:  // Level 37-40
       write( "Your nunchaku strikes "+ob->query_cap_name()+" with a deep THUD.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(25)+95);
      break;
      case 7:  // Level 37-40
       write( "You MAUL "+ob->query_cap_name()+" repeatedly with the nunchaku.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(35)+95);
      break;
      case 8:  // Level 37-40
       write( "With sharp precision you find a vital opening causing "+ob->query_cap_name()+" great damage.");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(35)+100);
ob->set_paralyzed(4); 
     break;   
      case 9:  // Level 37-40
       write( "A wicked hit with your nunchaku weakens "+ob->query_cap_name()+".");
       result = (this_player()->query_skill("blunt")/2)+(this_player()->query_skill("attack")/2)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(35)+110);
ob->add_sp(-result); 
     break; 
       case 10:  // Level 37-40
       write( "%^CYAN%^You channel your faith through the weapon as you demolish "+ob->query_cap_name()+".\nYou feel rejuvinated.%^RESET%^");
       result = (this_player()->query_skill("blunt")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("dexterity"))+(random(35)+115);
this_player()->add_sp((result)/2); 
this_player()->add_mp((result)/2);
this_player()->add_hp((result)/2);
    break; 
   default: // Level 37-40
write( "%^BLUE%^You channel your faith into your weapon and strike "+ob->query_cap_name()+" with resolve.");
       result = (this_player()->query_skill("faith")/3)+(this_player()->query_skill("attack")/3)+(this_player()->query_stats("strength"))+(this_player()->query_stats("wisdom"))+(random(25)+85);
 this_player()->add_hp(result);            
   }
 }

}
}
int query_auto_load() {
if(this_player()->query_race() != "drow-elf") return 0;
if(this_player()->query_subclass() != "priest") return 0;
if(this_player()->query_level() > 24) return 0;
 return 1; 
}
