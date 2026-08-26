/* A slot Machine.
** Version 1.2 (10-6-96) Coded by Waxer@AgainstTheFallOfDarkness 
**  if yer a wiz you don't have to pay :)
**  then again, if yer not a wiz, you couldn't read this ;)
**  I think it might give too much money fer a win
*/
inherit OBJECT;
int inserted, inslot;
int pulled;
int value1, value2, value3;
string pic, pic2, pic3;

void message_one(){
  write("The spinning begins to slow down.\n\n\n");
  return;
}
void message_two(){
  write("And the resulting match is....\n\n");
  return;
}
void create()
 {
  set("short", "a slot machine");
  set("long", @EndLong
It needs a long describe.
  Usage: insert # of coins, pull handle, pretty simple ;)
  cost is 20 coins per pull.
     3 bananas : 800 coins
     3 apples : 1500 coins
     3 beach balls : 3000 coins
     3 cherries : 7500 coins
     3 bars : 20,000 coins
EndLong);
  set("id", ({ "machine", "slot machine" }));
  set("prevent_get", 1);
 }

void init()
 {
  add_action("insert_coins", "insert");
  add_action("pull_handle", "pull");
 }

int insert_coins(string number)
 {
   int amt;

   if(!number)
   {
    write("Please specify an amount of coins to insert into the machine.\n");
    return 1;
   }
   if(inserted)
   {
    write("The machine is already ready to be pulled.\n");
    return 1;
   }
   amt = atoi(number);
 
   if(!sscanf(number, "%d coins", amt))
   {
    write("Please specify an amount of coins to insert into the machine.\n");
    return 1;
   }

   if(amt != 20)
   {
    write("Please, insert 20 coins to play.\n");
    return 1;
   }

   if(!TP->debit(20))
   {
    write("It's time for a trip to the bank, for you don't have the 20 coins to play!\n");
    return 1;
   }

   write("You insert your coins and the handle of the machine stands\nready to be pulled.\n");
   inserted = 1;
   return 1;
 }

int pull_handle(string str)
 {
  if(!str || str !="handle")
  {
   write("Pull what?\n");
   return 1;
  }
  if(inslot)
  {
   write("The slot machine is already running!\n");
   return 1;
  }
  if(!inserted && !wizardp(TP))
  {
     write("You have to insert coins for the machine to work!\n");
     return 1;
  }
  write("You pull the handle of the slot machine and the three pictures\nspin vertically behind the glass.\n\n\n");
  say(TPN+" pulls down the handle on the slot machine and waits expectantly.\n");

 switch(random(17))
  {
   case 0..4: value1 = 1;  pic = "A banana"; break;
   case 5..9: value1 = 2;  pic = "An apple";break;
   case 10..13: value1 = 3;  pic = "A beach ball";break;
   case 14..15: value1 = 4;  pic = "A cherry";break;
   case 17: value1 = 5;  pic =  "[BAR]";break;
   default: value1 = 1; pic = "A banana"; break;
  }
 switch(random(17))
  {
   case 0..4: value2 = 1;  pic2 = "A banana"; break;
   case 5..9: value2 = 2;  pic2 = "An apple";break;
   case 10..13: value2 = 3;  pic2 = "A beach ball";break;
   case 14..15: value2 = 4;  pic2 = "A cherry";break;
   case 17: value2 = 5;  pic2 =  "[BAR]";break;
   default: value2 = 1; pic2 = "A banana"; break;
  }
  switch(random(17))
  {
   case 0..4: value3 = 1;  pic3 = "A banana"; break;
   case 5..9: value3 = 2;  pic3 = "An apple";break;
   case 10..13: value3 = 3;  pic3 = "A beach ball";break;
   case 14..15: value3 = 4;  pic3 = "A cherry";break;
   case 17: value3 = 5;  pic3 =  "[BAR]";break;
   default: value3 = 1; pic3 = "A banana"; break;
  }

 call_out("message_one", 3);
 call_out("message_two", 6);
 call_out("finish", 9);
 inslot = 1;
 return 1;
}
int finish()
 {
  printf("%s\t%s\t%s\n", pic, pic2, pic3);

  if(value1==value2 && value2 == value3)
  {
   write("You won!!!\n");
// Could also switch any of the int values, but for clarity's sake...
    switch(pic3)
     {
       case "A banana" : write("Eight hundred coins come pouring out of the machine!\n");
                          TP->credit(800);break;
       case "An apple" : write("One thousand-five hundred coins flood out from the machine.\n");
                          TP->credit(1500); break;
       case "A beach ball" : write("Three thousand coins come flooding out of the machine!\n"); TP->credit(3000); break;
       case "A cherry" : write("Seven thousand-five hundred coins comes pouring forth of the machine!\n");
                          TP->credit(7500); break;
       case "[BAR]" : write("Heads turn all around you as the machine prctically explodes with coins that you won!!!!\n");
                      TP->credit(20000);  break;
     }
     say(TPN+"'s face lights up with joy as "+objective(TP->query("gendor"))+" sees the results.\n");
   inserted = 0;
  inslot = 0;
   return 1;
  }
     write("You sigh with disappointment.\n");
     say(TPN+"'s face scowls with disappointment as "+subjective(TP->query("gender"))+" sees the results.\n");
   inserted = 0;
   inslot = 0;
     return 1;
}



  

