#define MONEY "/obj/handlers/money_handler"
inherit "/std/object";
mixed deck;
object env,pot,monmon;
mixed trash_deck;  /* discarded cards :) */


#define pack ({"Ace of Spades","Ace of Diamonds","Ace of Hearts", "Ace of Clubs",\
                 "King of Spades","King of Diamonds","King of Hearts","King of Clubs",\
                 "Queen of Spades","Queen of Diamonds","Queen of Hearts","Queenof Clubs",\
                 "Jack of Spades","Jack of Diamonds","Jack of Hearts","Jack of Clubs"})
#define types ({"Spades","Hearts","Diamonds","Clubs"})

mixed players; /* ({ playername,({ ({cards}) , status, playerob}) }) */
int stat;
#define S_START 0  /* Game has just begun */
#define S_BET 1    /* Betting */
#define S_DRAWING 2  /* Asking players what they want to do */
#define S_DONE  20   /* Player has made a move, now just waiting. */
#define S_STANDING 666
#define S_ACK 3   /* no one here to play... */
#define S_OUT 9    /* Player has come in in the middle of the game */
int hit_f;   /* is equal to 1 when someone has hit */

mixed create_deck();

void create() {
  ::create();
  if (!deck) {
    deck=create_deck();
    trash_deck=({});
    players=({});
    stat=S_ACK;
  }
}

mixed get_eq(int bing) {
  mixed nuts;
  mixed up;
  int i,sop;

  sop=sizeof(players);
  nuts=up=({});
  for (i=0;i<sop;i+=2)
    if (players[i+1][1]!=S_OUT)
      if (players[i+1][1]==bing)
        nuts+=({players[i]});
      else
        up+=({players[i]});
  return ({up,nuts});
}

string p_print(mixed bing) {
  int i;
  string ret;

  ret="";

  for (i=0;i<sizeof(bing);i++)
    if ((sizeof(bing)-2)==i)
      ret+=bing[i] + " and ";
    else
      if ((sizeof(bing)-1)==i)
        ret+=bing[i]+".";
      else
        ret+=bing[i]+",";
  return ret+"\n";
}

int what(string s) {
  string name;
  int which,st;
  mixed wang;

  name=(string)this_player()->query_cap_name();
  which=member_array(name,players);
  if (which==-1)
    return 0;
  st=players[which+1][1];
  switch (st) {
  case S_ACK:
    write("You will have to wait for another player...(dealer can't play [yet])\
n");
    return 1;
  case S_BET:
    write("You need to place a bet.\n");
    break;
  case S_DRAWING:
    if (stat==S_DRAWING)
      write("You can either hit or stand at the moment.\n");
    else
      write("You are waiting for the others to finish betting.\n");
    break;
  case S_STANDING:
    write("You have stood on your hand.  You can do nothing else this round.\n")
;
    break;
  case S_DONE:
    write("You have made your play;  you have to wait on the other players to move.\n");
    break;
  case S_OUT:
    write("You sat down in the middle of a game - you have to wait till the betting round"+
          " before you can play.\n");
    return 1;
    break;
  }
  switch (stat) {
  case S_ACK:
    write("Unfortunately, there is no one to play with.\n");
    break;
  case S_BET:
    wang=get_eq(S_BET);
    printf("People who have yet to bet: %s\n",p_print(wang[1]));
    return 1;
  case S_STANDING:
  case S_DRAWING:
    wang=get_eq(S_DRAWING);
    printf("People who haven't made a move yet: %s",p_print(wang[1]));
    return 1;
  }
  return 1;
}
void setup() {
  set_name("table");
  set_short("table");
  set_long("An old rickety table surronded by chairs.  There is a dealer at the"+
           "far end of the table guarding a pack of cards.  Maybe you can 'sit'down "+
           "and play a game of blackjack with some other players.\n");
  reset_get();
    call_out("net_dead",30);
}

mixed create_deck() {
  mixed d;
  int i,j;

  d=pack;
  for (i=10;i>1;i--) {
    for (j=0;j<4;j++)
      d+=({ i + " of " + types[j]});
  }
  return d;
}

string draw_card() {
  int t,x,i;
  string bing;

  if (!sizeof(deck)) {
    deck=trash_deck;
    trash_deck=({});
  }

  t=time()%20;
  for (i=0;i<t;i++) x=random(sizeof(deck));
  bing=deck[x];
  deck = delete(deck,x,1);
  return bing;
}

int evaluate_hand(mixed hand) {
  mixed bits;
  int i,sum,bing;
  int ace;
  string ding;

  sum=0;
  ace=0;
  if (!sizeof(hand))
    return 0;              /* impossible hopefully... */

  for (i=0;i<sizeof(hand);i++) {
    bits=explode(hand[i]," ");
    bing=0;
    sscanf(bits[0],"%d",bing);
    if (bing)
      sum+=bing;
    else
      if (bits[0]=="Ace") {
        ace++;
        sum+=11;
      }
      else
        sum+=10;
  }
  for (i=0;i<ace;i++)
    if (sum>21)
      sum-=10;
  return sum;
}

void thwap_cards() {
  int i;

  for (i=1;i<sizeof(players);i+=2)
    if (players[i][0]) {
      trash_deck+=players[i][0];
      players[i][0]=({});
    }
}

void check_state();

void find_winner() {
  int i,sop,top,count;
  mixed frogs;
  object winner;
  int cut;
   mixed thing;

  tell_room(env,"Everyone lays down their hands.\n");
  frogs=({});
  sop=sizeof(players);
  for (i=0;i<sop;i+=2)
    tell_room(env,players[i]+ ": " + p_print(players[i+1][0]));
  for (i=1;i<sop;i+=2)
    if (players[i][1]==S_STANDING)
      frogs+=({evaluate_hand(players[i][0])});
    else
      frogs+=({0});
  for (i=0;i<sizeof(frogs);i++)
    if ((frogs[i]>top)&&(frogs[i]<22))
      top=frogs[i];
  count=0;
  for (i=0;i<sizeof(frogs);i++)
    if (frogs[i]==top)
      count++;

  if (top==0) {
    thwap_cards();
    stat=S_START;
    tell_room(env,"Dealer says: You all lost. The money stays in the pot.\n");
    check_state();
    return;
  }

  if (count==1) {
    winner=players[1+member_array(top,frogs)*2][2];
    tell_room(env,"Dealer says:  " + (string)winner->query_cap_name()+
              " takes the pot!\n");
    winner->adjust_money((int)monmon->query_value()/10,"copper");
    monmon->adjust_money(-((int)monmon->query_value()/10),"copper");
    stat=S_START;
    thwap_cards();
    check_state();
    tell_room(env,"The Dealer deals the cards.\n");
  }
  else {
    tell_room(env,"Dealer says: Its a draw - split the pot.\n");
    cut=(int)monmon->query_value()/count;
    thing=({});
    for (i=0;i<sizeof(frogs);i++)
      if (top==frogs[i]) {
        players[(i*2)+1][2]->adjust_money(cut/10,"copper");
        thing+=({players[i*2]});
      }
    monmon->adjust_money(-((int)monmon->query_value()/10),"copper");
    tell_room(env,"Dealer gives money to " + p_print(thing));
    thwap_cards();
    stat=S_START;
    check_state();
  }
}

void check_state() {
  int flag;
  int i,sop;

  sop=sizeof(players);
  switch(stat) {

  case S_ACK:
    if (sizeof(players)>3) {
      stat=S_START;
      tell_room(env,"Dealer says: Enough for a game!  Place your bets.\n"+
                "Dealer passes out the cards.\n");
      check_state();
    }
    break;
  case S_START:
    for (i=0;i<sop;i+=2) {
if (!sizeof(players[i+1][0])) {
      players[i+1][0]=({});
      players[i+1][0]+=({draw_card()});
      players[i+1][0]+=({draw_card()});
    }
      players[i+1][1]=S_BET;
    }
    stat=S_BET;
    break;

  case S_BET:
    flag=1;
    for (i=0;i<sop;i+=2)
      if (players[i+1][1]==S_BET)
        flag=0;
    if (flag) {
      tell_room(env,"Dealer says: The bets are made.  Hit or stand, hit or stand?\n");
      hit_f=0;
      stat=S_DRAWING;
    }
    break;

  case S_DRAWING:
    flag=1;
    for (i=0;i<sop;i+=2)
      if (players[i+1][1]==S_DRAWING)
        flag=0;
    if (flag&&!hit_f) {
      tell_room(env,"Dealer says: Ok, lets see who was lucky today...\n");
      stat=S_START;
      find_winner();
    }
    else {
      if (flag) {
        tell_room(env,"Dealer says:  And another round,  hit or stand?\n");
        hit_f=0;
        for (i=1;i<sop;i+=2)
          if (players[i][1]==S_DONE)
            players[i][1]=S_DRAWING;
      }
    }
    break;
    }
  }


int sit(string s) {
  string n;

  n=(string)this_player()->query_cap_name();
  notify_fail("You are already sitting down.\n");
  if (member_array(n,players)!=-1)
    return 0;
  if (!sizeof(players)||(sizeof(players))&&(stat==S_BET)||(stat==S_ACK)) {
    if (sizeof(players)>2)
      players+=({n,({ ({draw_card(),draw_card()}),S_BET,this_player()})});
    else
      players+=({n,({ ({}),S_ACK,this_player()})});
  }
  else {
    players+=({n,({ ({}),S_OUT,this_player()})});
    write("You sit down.  You will have to wait till the other players"+
          " finish this round before you can enter.\n");
    return 1;
  }
  write("Type 'help table' for instructions.\n");
  tell_room(env,n + " sits down at the table.\n",({this_player()}));
  check_state();
  if (stat==S_BET) {
    write("You sit down - the dealer tosses you a couple of cards.\n");
    write("The Dealer tells you: Place your bet.\n");
  }
  return 1;
}

int bet(string str) {
  int amnt,which;
  string name;
  object bing;

  if (!str) {
    notify_fail("bet <amount>\nAmount is in copper coins (for now)\n");
    return 0;
  }
  name=(string)this_player()->query_cap_name();
  which=member_array(name,players);
  if (which==-1) {
    notify_fail("You aren't in the game.\n");
    return 0;
  }
  if (stat!=S_BET) {
    notify_fail("The dealer isn't accepting bets now.\n");
    return 0;
  }
  if (players[which+1][1] != S_BET) {
    notify_fail("You have already made your bet.\n");
    return 0;
  }

  sscanf(str,"%d",amnt);
  if (amnt*10>(int)this_player()->query_value()) {
    notify_fail("You don't have that much money. You can fold to get out.\n");
    if ((int)this_player()->query_value() < 10)
      tell_room(env,name + " looks in " + (string)this_player()->query_possessive() +
                " purse and gasps.\n",({this_player()}));
    else
      tell_room(env,name + " digs around in "+ (string)this_player()->query_possessive() +
                " purse.\n",({this_player()}));
    return 0;
  }
  this_player()->pay_money(MONEY->create_money_array(amnt*10));
  monmon->adjust_money(amnt,"copper");
  write("Ok.\n");
  tell_room(env,name + " puts "+amnt+" copper coins into the pot.\n",this_player());
  players[which+1][1]=S_DRAWING;
  check_state();
  return 1;
}

int fold(string s);

int hit() {
  string name,card;
  int which;

  name=(string)this_player()->query_cap_name();
  which=member_array(name,players);
  if (which==-1) {
    notify_fail("You aren't in the game.\n");
    return 0;
  }
  if (stat!=S_DRAWING) {
    notify_fail("You can't hit now.\n");
    return 0;
  }
  if (players[which+1][1]!=S_DRAWING) {
    notify_fail("You have already made your play.\n");
    return 0;
  }
  card=draw_card();
   players[which+1][0]+=({card});
  tell_room(env,name + " draws a card.\n",this_player());
  write("You draw the " +card+".\n");
  if (evaluate_hand(players[which+1][0])>21) {
    write("Ack - you busted.\n");
    fold("");
    players[which+1][1]=S_OUT;
    tell_room(env,"Dealer grins happily.\n");
  }
  else
  {
    players[which+1][1]=S_DONE;
    hit_f=1;
  }
    players[which+1][1]=S_DONE;
  check_state();
  return 1;
}

int fold(string s) {
  int which;
  string name;

  name=(string)this_player()->query_cap_name();
  which=member_array(name,players);
  if (which==-1) {
    notify_fail("You are not playing, you can't fold.\n");
    return 0;
  }
  which++;
  if ((players[which][1]!=S_BET)&&(players[which][1]!=S_DRAWING)) {
    notify_fail("You can't fold now.\n");
    return 0;
  }
  players[which][1]=S_OUT;
  write("You fold.\n");
  tell_room(env,name+ " folds.\n",this_player());
  if (sizeof(players[which][0]))
    trash_deck+=players[which][0];
  players[which][0]=({});
  check_state();
  return 1;
}

int cards(string s) {
  int i,j,num;
  string n;

  n=(string)this_player()->query_cap_name();
  if ((j=member_array(n,players))==-1) {
    notify_fail("How could you have any cards?  You're not in the game.\n");
    return 0;
  }
  num=sizeof(players[j+1][0]);
  if (!num)
    write("You have no cards.\n");
  else {
    n="Your hand: ";
    for (i=0;i<num;i++)
      if (i==(num-2))
        n+=players[j+1][0][i]+" and ";
      else
        n+=players[j+1][0][i]+", ";
    write(n+"\n");
  }
  return 1;
}

int stand(string s) {
  int which,flag;
  string name;

  name=(string)this_player()->query_cap_name();
  which=member_array(name,players);

  if (which==-1) {
    notify_fail("You are not playing.\n");
    return 0;
  }
  which++;

  if (stat!=S_DRAWING) {
    notify_fail("You can't stand now!\n");
    return 0;
  }
  if (players[which][1]!=S_DRAWING) {
    notify_fail("You can't stand now!\n");
    return 0;
  }

  players[which][1]=S_STANDING;
  write("Ok.\n");
  tell_room(env,name + " stands.\n",this_player());
  check_state();
  return 1;
}

int leave_bing(object ob) {
  string name;
  int which;

  name=(string)this_player()->query_cap_name();
  which=member_array(name,players);

  if (which==-1)
    return 0;
  if (players[which+1][0])
    trash_deck+=players[which+1][0];
  players=delete(players,which,2);
  write("Ok.\n");
  tell_room(env,name + " gets up from the table.\n",this_player());
  if (sizeof(players)==2) {
    tell_room(env,"Dealer says:  Oh well, there goes the game.\n");
    players[1][1]==S_OUT;
    if ((int)monmon->query_value()) {
      tell_room(env,"Dealer says: House takes the pot.\n");
      monmon->adjust_money(-((int)monmon->query_value()/10),"copper");
    }
    stat=S_ACK;
  }
  else
    if (!sizeof(players))
      stat=S_ACK;
  check_state();
  return 1;
}

int leave(string s) {
   return leave_bing(this_player());
}

int help(string s) {

  if ((s!="table")&&(s!="blackjack"))
    return 0;
  write("Here are the commands of the blackjack table:\n"+
        "   'sit' - sit down and enter a game.\n"+
        "   'bet <amnt>' - bet amnt copper coins.\n"+
        "   'hit - hit, or draw a card\n"+
        "   'stand' - stand, or keep your current hand.\n"+
        "   'leave' - To stop playing.\n"+
        "   'what' - Tells you what you should be doing now. Good if you get confused.\n"+
        "   'cards' - Tells you what cards you are holding.\n\n"+
        "  Here is the usual order of events - after the players sit down at the table "+
        "the dealer will ask them to place their bets.  After all of the bets are made "+
        "then the players can either hit or stand.  This will continue until everyone "+
        "stands on a hand.  Then the cards will be put down and the winner announced."+
        "  If there is a draw, the pot will be split up among the people who tied.  "+
        "Have fun!\n");
  return 1;
}

void init() {
  ::init();
  add_action("quit","quit");
  add_action("sit","sit");
  add_action("help","help");
  add_action("cards","cards");
  add_action("bet","bet");
  add_action("hit","hit");
  add_action("fold","fold");
  add_action("stand","stand");
  add_action("leave","leave");
  add_action("what","what");
  env=environment(this_object());
  if (!monmon) {
    env->add_item("dealer","An old drow who was hired to make sure players abided "+
                  "by the rules.  He grins at you.\n");
    pot=clone_object("/std/container");
    pot->set_name("pot");
    pot->set_short("betting pot");
    pot->set_long("A small iron pot that the players place their bets in.\n");
    pot->move(env);
    pot->reset_get();
    monmon=clone_object("/obj/money");
    monmon->move(pot);
    monmon->reset_get();
  }
}

mixed query_deck() {return deck;}
mixed query_trash() {return trash_deck;}

int dest_me() {
  if (monmon)
    monmon->dest_me();
  if (pot)
    pot->dest_me();
  remove_call_out("net_dead");
  ::dest_me();
  return 1;
}
string long(string str, int dark) {
int i;
  mixed thing;

  thing=({});
  if (!sizeof(players))
    return ::long(str,dark);
  for (i=0;i<sizeof(players);i+=2)
    thing+=({players[i]});

  return ::long(str,dark) + "Sitting at the table: " + p_print(thing);
}

void event_exit(object ob,string mess) {
  int which;
  if ((which=member_array((string)ob->query_cap_name(),players))!=-1)
    leave(mess);
}

int quit(string s) {
  leave(s);
  return 0;
}

void net_dead() {
  int i;

  for (i=1;i<sizeof(players);i+=2)
    if (!interactive(players[i][2])) {
      tell_room(env,"Dealer says: Hey, "+players[i-1]+" is net dead!\n"+
                "Dealer kicks "+players[i-1]+" across the room.\n");
      if (players[i][0])
        trash_deck+=players[i][0];
      players=delete(players,i-1,2);
      if (sizeof(players)==2) {
        tell_room(env,"Dealer says: Ack, game over.\n");
      stat=S_ACK;
      }
    }
  call_out("net_dead",30);
}
