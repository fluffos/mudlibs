/* A Krud table.
** Coded by Waxer@AFD 10/7/96
*/

inherit OBJECT;
int first, bet;

void create()
 {
  set("short", "a Krud table");
  set("long", @EndLong
It needs a long describe.
   The object of the game is to get %^BOLD%^9%^RESET%^ or a %^BOLD%^15%^RESET%^
   or the first number you rolled.  If you get a
   %^BOLD%^9%^RESET%^ or %^BOLD%^15%^RESET%^ %^RED%^before%^RESET%^ you hit the number you originally
   rolled but %^RED%^after%^RESET%^ your first roll, you lose.
   on two eight sided dice.
   Oh, and don't roll double 1's either ;)
   to place a bet use [bet] amount, then roll the dice.
EndLong);
  set("id", ({ "table", "krud table" }));
  set("prevent_get", 1);
 }

void init()
 {
  add_action("place_bet", "bet");
  add_action("roll_em", "roll");
 }

int place_bet(string coins)
 {
  if(!coins){
   write("You must place a bet by [bet] <amount>\n");
   return 1;
  }
  if(!atoi(coins)){
     write("You must bet a monetary amount.\n") ;
     return 1;
   }
  if(!TP->debit(atoi(coins))){
     write("You don't have the resources to bet that amount\n");
     return 1;
   }
  bet = atoi(coins);
  write("You place a bet of "+coins+" coins.\n");
}

void void_it(){
  first = 0;
  bet = 0;
}

int roll_em()
 {
   int die1, die2, total;
 die1 = random(8)+1;
 die2 = random(8)+1;
 total = die1 + die2;
 if(!bet && !wizardp(TP))
 {
  write("You must first place a bet before rolling the dice.\n");
  return 1;
 }
 if(!first)
  {
   first = total;
   printf("Your first roll is [%d] and [%d].\n", die1, die2);
   if(total ==2)
    {
     write("A roll of double ones is an automatic loss.\n");
     void_it();
     return 1;
    }
   if(total == 9 || total == 15)
   {
    write("You roll a "+total+" winning your first roll!\n");
   void_it();
   TP->credit(bet*4);
   return 1;
   }
   write("Continue playing? [y/n]:\n");
   input_to("roll_again");
   return 1;
  }
 printf("Your roll is [%d] and [%d].\n", die1, die2);
 if(total ==2)
 {
  write("A roll of double ones is an automatic loss.\n");
  void_it();
  return 1;
 }
 if(total == 9 || total == 15)
  {
   void_it();
   write("A total roll of 9 or 15 after your initializing roll, you lose.\n");
   return 1;
   }
 if(total == first)
  {
   void_it();
   write("You rolled a "+total+" which was your original roll!\n");
   TP->credit(bet*3);
   return 1;
  }
   write("Continue playing? [y/n]:\n");
   input_to("roll_again");
return 1;
}

int roll_again(string str){
  switch(str)
  {
   case "y": roll_em(); break;
   case "Y" : roll_em(); break;
   case "n" : void_it();return 1; break;
   case "N" : void_it();return 1; break;
   default: roll_em(); break;
  }
return 1;
}

