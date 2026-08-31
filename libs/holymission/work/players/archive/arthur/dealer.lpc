inherit "obj/treasure";
#define TP "this_player" 
 int number1,number2,orig,ammount,numbers,number3,i,numb,started,tgold;
 object tp;
 string nu1,nu2,nu3,nu4,nu5,nu6;
reset (arg) {
if (arg) return;
   set_short("A Craps Dealer");
   set_alias("dealer");
   set_long("This is the Craps dealer.\nIf you want help on how to play craps type 'help craps'\n");
   set_weight(1000);
   set_value(0);
   }
init() {
   add_action("_bet", "bet");
   add_action("_help","help");
   ::init();
   }
get() {return 0;}

_bet(str) {

    if(started) {
      write("Sorry, but someone else is playing right now.\n") ;
      return 1;}
    if(!str) {write("How much do you wish to bet?\n"); return 1;}
    sscanf(str,"%d",ammount);
    if(ammount<1) {write("you cannot bet a negitive number.\n"); return 1;}
    numbers=0;
    tp=this_player();
    tgold=tp->query_money();
    if(tgold<ammount) {
    write("The dealer says: Don't bet more than you have\n"+
    "The dealer kicks you!\nYou gasp in pain.\n");
    tp->reduce_hit_point(200);
    return 1;}
    number1=random(6)+1;
    number2=random(6)+1;
    orig=number1+number2;
    i=0;
    numb=2;
    started=1;
    set_heart_beat(1);
    dice();
    return 1;}
dice() {
number_call();            
    tell_object(tp," -------        -------\n"+
                   "| "+nu1+" |     | "+nu4+" |\n"+
                   "| "+nu2+" |     | "+nu5+" |\n"+
                   "| "+nu3+" |     | "+nu6+" |\n"+
                   " -------        -------\n");
   
    number3=number1+number2;
    if(numbers == 0) {
      if (orig == 7) {
         tell_object(tp,"You Win!\nThe dealer hands you "+ammount+" gold.\n");
         tp->add_money(ammount);
         started = 0;
         set_heart_beat(0);
         return 1;}
      if (orig == 11 || orig == 2) {
         tell_object(tp,"You Loose.\nThe dealer takes "+ammount+" of your gold.\n");
         tp->add_money(-ammount);
         started = 0;
         set_heart_beat(0);
         return 1;}
      }
      
    else {
      if(number3 == orig) {
          tell_object(tp,"You Win!\nThe dealer hands you "+ammount+" gold.\n");
          tp->add_money(ammount);
          started = 0;
          set_heart_beat(0);
          return 1;}
      if(number3 == 7 || number3 == 11) {
           tell_object(tp,"You Loose.\nThe dealer takes "+ammount+" of your gold.\n");
           tp->add_money(ammount);
           started = 0;
           set_heart_beat(0);
           return 1;}
            
      }
    dice_roll();
    }
dice_roll() {
   number1=random(6)+1;
   number2=random(6)+1;
   numbers=1;
   tell_object(tp,"You roll the dice again.\n");
   numb +=1;
  }

heart_beat() {
 i+=1;
 if(i==numb) dice();
}
number_call() {
if(number1==1) {
   nu1="     ";
   nu2="  *  ";
   nu3="     ";}
if(number1==2) {
  nu1="*    ";
  nu2="     ";
  nu3="    *";}
if(number1==3) {
  nu1="*    ";
  nu2="  *  ";
  nu3="    *";}
if(number1==4) {
  nu1="*   *";
  nu2="     ";
  nu3="*   *";}
if(number1==5) {
  nu1="*   *";
  nu2="  *  ";
  nu3="*   *";}
if(number1==6) {
  nu1="*   *";
  nu2="*   *";
  nu3="*   *";}
if(number2==1) {
   nu4="     ";
   nu5="  *  ";
   nu6="     ";}
if(number2==2) {
  nu4="*    ";
  nu5="     ";
  nu6="    *";}
if(number2==3) {
  nu4="*    ";
  nu5="  *  ";
  nu6="    *";}
if(number2==4) {
  nu4="*   *";
  nu5="     ";
  nu6="*   *";}
if(number2==5) {
  nu4="*   *";
  nu5="  *  ";
  nu6="*   *";}
if(number2==6) {
  nu4="*   *";
  nu5="*   *";
  nu6="*   *";}
}
_help(str) {
  if(!str) return 0;
  if(str !="craps") return 0;
  write("This version of craps is very simple, taking no thinking skill at\n"+
        "all. To play just type bet <ammount>, and the dice will roll for\n"+
        "you automagicly.\n\n"+
        "\tIDEA BEHIND THE GAME\n\n"+
        "On the first roll you want to roll a 7 you will win, if you roll\n"+
       "a 11 or 2 you loose.\n"+
        "On the following rolls, the number you rolled on the first roll\n"+
        "wins, and 11 and 7 loose, the rest you roll again.\n");
  return 1;}
