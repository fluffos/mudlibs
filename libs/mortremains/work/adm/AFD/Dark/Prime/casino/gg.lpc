inherit MONSTER;
int crdN, hand, firstdone, dealer_hand, showed, wager, in_use;
string crdS, crdn, hidden_card;

// I never knew I could play with a full deck :)
void generate_card(int dealer){
  switch(random(12)+2)
 {
  case 2 : crdN = 2; crdn = "2"; break;
  case 3 : crdN = 3; crdn = "3";break;
  case 4 : crdN = 4; crdn = "4";break;
  case 5 : crdN = 5; crdn = "5";break;
  case 6 : crdN = 6; crdn = "6";break;
  case 7 : crdN = 7; crdn = "7";break;
  case 8 : crdN = 8; crdn = "8";break;
  case 9 : crdN = 9; crdn = "9";break;
  case 10 : crdN = 10; crdn = "10";break;
  case 11 : crdN = 10; crdn = "Jack";break;
  case 12 : crdN = 10; crdn = "Queen";break;
  case 13 : crdN = 10; crdn = "King"; break;
 }
   if(dealer == 1) dealer_hand = dealer_hand+ crdN;
  if(!dealer)
 {
  hand = hand+ crdN;
  
  }
  switch(random(4))
  {
   case 0: crdS = "dragons"; break;
   case 1: crdS = "cavebears"; break;
   case 2: crdS = "goblins"; break;
   case 3: crdS = "ogres"; break;
  }
 
  
}

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a slick looking Goblin's Gambit dealer");
  set("long", @ENDLONG
This dealer deals for the Goblin's gambit game.
The object is to obtain a hand score of 29 or
a higher score than the dealer.  If your hand is
valued over 29 you will lose.
  type [play]
ENDLONG
);
  set_name("dealer");
  set("id", ({
    "dealer",
    "gambit dealer",
  }));
  set("race", "human");
  set("attrib1", "sly-looking");  set("attrib2", "neatly dressed");
  set("gender", "male");

  set("no_attack", 1);
}

void init()
 {
  add_action("wager", "wager");
  add_action("play", "play");
  add_action("check", "check");
 }

int wager(string arg)
 {
 int amt;
  if(!arg){
    write("How much would you like to wager?\n");
    return 1;
    }
  amt =atoi(arg);
 if(!amt)
  {  write("How much would you like to wager?\n");
    return 1;
   }
 if(amt > 1000 || amt < 50)
 {
  write("Please wager an amount no less than 50 or greater than 1000 coins.\n");
  return 1;
 }
wager = amt;
if(!TP->debit(wager)){
   write("You lack the funds to wager that many coins!\n");
  return 1;
 }
write("You wager "+wager+" coins\n");
say(TPN+" wagers some money and begins the Goblin's Gambit.\n");
call_other(TO, "play");
return 1;
}
   
int check(){
 if(!hand){
   write("You have to be playing a game to have a hand!\n");
   return 1;
  }
write("Your hand has a value of "+hand+".\n");
write("Do you wish to be dealt another card? [Y/n/q]:");
  input_to("yes_no");
return 1;
}
void void_it(){
       firstdone = 0;
       hand = 0;
       dealer_hand = 0;
       showed = 0;
       wager = 0;
       in_use = 0;
 }

int check_dealer()
{
  if(!showed){
   write("The dealer displays his hidden card which was a "+hidden_card);
  showed = 1;
   }

 if(dealer_hand < 22)
     {
      generate_card(1);
      write("The dealer deals himself the "+crdn+" of "+crdS+".\n");
      check_dealer();
      return 1;
     }
 if (dealer_hand == 29)
  {
   write("The dealer has a 21!\n");
   void_it();
   return 1;
  }
 if (hand == 29)
  {
   write("You have 29!\nYou win!\n");
   TP->credit(wager*6);
   void_it();
   return 1;
  }
 if( dealer_hand < hand )
   { 
    void_it();
     write("You win!\n");
     TP->credit(wager*2);
     return 1;
   }
   if( dealer_hand > hand)
   { 
    void_it();
     write("You lose.\n");
     return 1;
   }
   if(dealer_hand = hand)
   {
    void_it();
    write("You lose because the dealer always wins a push.\n");
    return 1;
  }
check_dealer();
}
  
int play()
 {
  generate_card(0);
  write("The dealer hands you the "+crdn+" of "+crdS+"\n");
  say(TPN+" receives a card.\n");
 if(!wager && !wizardp(TP)){
  write("Please wager an amount before playing the game.\n");
  return 1;
 }
 if(!firstdone)
 {
  
  generate_card(1);
  write("The dealer deals himself a card.\n");
  say("The dealer deals himself a card.\n");
  hidden_card = crdn+" of "+crdS+"\n";
  generate_card(0);
  write("The dealer hands you the "+crdn+" of "+crdS+"\n");
  say(TPN+" receives a card.\n");
  generate_card(1);
  write("The dealer deals himself the "+crdn+" of "+crdS+".\n");
  say("The dealer deals himself a card.\n");
  firstdone =1;
 }
   if(dealer_hand > 29)
  {
   write("The dealer has gone over 29.\n");
   void_it();
   return 1;
  }
 if(hand > 29)
  {
   write("You have gone over 29.\n");
   void_it();
   return 1;
  }
  write("Do you wish to be dealt another card? [y/n/q]:");
  input_to("yes_no");
return 1;
}

int yes_no(string str)
 {
  switch(str)
  {
   case "q" : write("You forfeit your wager.\n"); void_it(); return 1; break;
   case "y": play(); break;
   case "Y" : play();
   case "n" : check_dealer(); return 1; break;
   case "N" : check_dealer(); return 1; break;
   case "wizz" : if(!wizardp(TP)){ check(); break;} else {
            write("Dealer's hidden card = "+hidden_card+"\n");
            write("Dealer's total hand = "+dealer_hand+"\n"); 
            check(); break;
           }
   default: check(); break;
   }
return 1;
}




