// a card game - 17+4
// I think you know it?!
// made by Magictcs - 14 aug 97

#include <properties.h>
#include <ansi.h>
#include <path.h>
#include <sykorath.h>

inherit "/std/thing";

// some internal variables
string *cards;
string *dealcard=({});
string iplayer;

// colours of card game: diamonds,hearts,clubs,spades
// pictures are: 7,8,9,10,Jack,Queen,King,Ace
string *unmixed=({
  "d7","h7","c7","s7",
  "d8","h8","c8","s8",
  "d9","h9","c9","s9",
  "d10","h10","c10","s10",
  "dJack","hJack","cJack","sJack",
  "dQueen","hQueen","cQueen","sQueen",
  "dKing","hKing","cKing","sKing",
  "dAce","hAce","cAce","sAce",
  });

// values for the cards: 7=7,8=8,9=9,10=10,jack=2,queen=3,king=4,ace=1 (or 11?)
mapping vals;

//******************
// property handling
//******************
string *QueryCards() { return cards; }
string *SetCards(string *new) { cards=new; return cards;}
mapping QueryVals() { return vals; }
string QueryIPlayer() { return iplayer; }
string SetIPlayer(string ipl) { iplayer=ipl; return iplayer;}

void mix_cards() {
  string *tmp;
  int i,pos;
  cards=({});
  tmp=unmixed;                       // copy array!
  for (i=0;i<32;i++) {
    pos=random(sizeof(tmp));         // find one free element in tmp
    cards+=({ tmp[pos] });           // copy random element from tmp to cards
    tmp-=({ tmp[pos] });             // then remove the element in tmp
  }
}

// use the card description and makes a readable string (with color) out of it
string printcard(string card) {
  string ret;
  switch (card[0]) {
    case 'd': ret="%^MAGENTA%^diamond "; break;
    case 'h': ret="%^RED%^heart "; break;
    case 'c': ret="%^GREEN%^club "; break;
    case 's': ret="%^BLUE%^spade "; break;
  }
  ret+=card[1..]+"%^RESET%^";
  return ret;
}

// calculates the number of points
// returns an string as output
string calc_points(string *c) {
  int i,points,numace,acepoints;
  points=0;
  numace=0;
  for (i=0;i<sizeof(c);i++) {
    if (c[i][1..]=="Ace") numace++;
    points+=vals[c[i][1..]];           // [1..] - ignore the color!
  }
  if (numace==0) return itoa(points)+" points";
  if (numace==2 && sizeof(c)==2) return "%^RED%^the best set of card%^RESET%^";
  acepoints=points;
  if (numace && (acepoints+10)<=21) {
    acepoints+=10;                     // ace counts 11 (but 1 is added)
    return itoa(points)+" or "+itoa(acepoints)+" points";
  }
  return itoa(points)+" points";
}

// calculates the maximal number reached
// returns integer!
int calc_int_points(string *c) {
  int i,points,numace,acepoints;
  points=0;
  numace=0;
  for (i=0;i<sizeof(c);i++) {
    if (c[i][1..]=="Ace") numace++;
    points+=vals[c[i][1..]];           // [1..] - ignore the color!
  }
  if (numace==0) return points;
  if (numace==2 && sizeof(c)==2) return 22;   // lost :)
  acepoints=points;
  if (numace && (acepoints+10)<=21) {
    acepoints+=10;                     // ace counts 11 (but 1 is added)
    return acepoints;
  }
  return points;
}

// checks if the player has won the game
// return number of points, if player has more points than dealer
// a value of 21 or 22 is == won (22==2 aces)
// return 0 if player lost it
int check_won(string *c) {
  int i,numace,plpoints,dpoints;
  plpoints=0;
  dpoints=0;
  numace=0;
  // first calculate the player:
  for (i=0;i<sizeof(c);i++) {
    if (c[i][1..]=="Ace") numace++;
    plpoints+=vals[c[i][1..]];           // [1..] - ignore the color!
  }
  if (numace==2 && sizeof(c)==2) return 22;       // won - only two aces!
  if (numace && (plpoints+10)<=21)     // max. one ace can be counted as 11!
    plpoints+=10;                    // ace counts 11 (but 1 is added)
  if (plpoints==21) return 21;          // won

  // now calculate the dealer
  numace=0;
  for (i=0;i<sizeof(dealcard);i++) {
    if (dealcard[i][1..]=="Ace") numace++;
    dpoints+=vals[dealcard[i][1..]];           // [1..] - ignore the color!
  }
  if (numace==2 && sizeof(dealcard)==2) return 0;       // won - only two aces!
  if (numace && (dpoints+10)<=21)      // max. one ace can be counted as 11!
    dpoints+=10;                       // ace counts 11 (but 1 is added)
  if (dpoints==21) return 0;           // won
  // if dpoints>21???? noe oder?

  if (dpoints>=plpoints) return 0;     // dealer wins
  return plpoints;                     // player wins
}

//**************
// play the game
//**************
int cmd_play(string str) {
  if (!str) { notify_fail("Play the game?\n"); return 0; }
  if (str!="game" && str!="the game") {
    if (strstr(str,"game")!=-1)
      notify_fail("Use: play game\n",NOTIFY_NOT_VALID);
    else notify_fail("Play the game?\n");
    return 0;
  }
  if (iplayer!=0) {
    write("The dealer says: Uhh sorry - I play actually with someone else.\n");
    return 1;
  }
  iplayer=TP->QueryRealName();
  write("You start to play the game.\n"
    "You will start with two cards from the stack. The goal is to get 21 "
    "points. If you got more than 21 you lost the game. Exact 21 points and "
    "you win the game. If you have less than 21 points you can get an "
    "additional card if you type 'card', or you can type 'enough'.\n"
    "If you have less than 21 points, the dealer will get his cards. If the "
    "dealer gets equal or more (but not more than 21) points than you, he "
    "will win the game, else you will win it.\n"
    "Btw. the Ace can be calculated as 1 point or 11 points!\n"
    "Ah yes and a double Ace on start of game will win too.\n"); 
  show(NAME+" starts a new game.\n");
  TP->Set("card174",1);                 // store temp  prop in player
  call_out("give_first_cards",1,TP);    // give first cards to player & dealer
  return 1;
}

// give two cards to player, one to dealer
void give_first_cards(object pl) {
  string *c;
  if (!pl) return;                      // don't deal with no objects
  pl->Set("cards",({}));                // reset the cards in the player
  dealcard=({});                       // reset the dealers cards
  if (sizeof(cards)<=14) {
// check if player is playing needed!!
    write("The dealer says: ups no cards left.\nI will mix them again.\n");
    mix_cards();
  }
  write("The dealer gives you a card. It is a "+printcard(cards[0])+".\n");
  c=pl->Query("cards")+({cards[0]});
  pl->Set("cards",c);
  cards-=({ cards[0] });                 // remove card from stack
  write("The dealer gives himself a card. It is a "+printcard(cards[0])+".\n");
  dealcard+=({ cards[0] });
  cards-=({ cards[0] });
  write("The dealer gives you a second card. It is a "+
    printcard(cards[0])+".\n");
  c=pl->Query("cards")+({cards[0]});
  pl->Set("cards",c);
  cards-=({ cards[0] });
  write("You have now : "+calc_points(pl->Query("cards"))+".\n");
  if (check_won(pl->Query("cards"))>=21) {
    write("The dealer says: Wow you are a lucky man. You won this game with "
      "the first two cards!\n");
    iplayer=0;
  }
}


//***********************
// get an additional card
//***********************
// get the next card (card number >2!!)
int cmd_card(string str) {
  string *c;
  int i;
  if (!TP) return 0;                      // don't deal with no objects
  if (str) { notify_fail("Use a simple 'card' to get an additional card.\n");
             return 0; }
  // player who is playing wants a new card?
  if (iplayer!=TP->QueryRealName()) {
    if (iplayer==0) {
      notify_fail("Start a new game with 'play game'.\n");
      return 0;
    }
    notify_fail("There is another player playing the game!\n");
    return 0;
  }
  if (!sizeof(cards)) {                   // there is a card left
    write("The dealer says: ups no cards left.\nI will mix them again.\n");
    mix_cards();
  }
  write("The dealer gives you an additional card. It is a "+
    printcard(cards[0])+".\n");
  c=TP->Query("cards")+({cards[0]});
  TP->Set("cards",c);
  cards-=({ cards[0] });                 // remove card from stack
  write("You hold now:\n");
  for (i=0;i<sizeof(c)-2;i++) {
    write(printcard(c[i])+", ");
  }
  write(printcard(c[i])+" and ");
  write(printcard(c[i+1])+".\n");
  write("You have now : "+calc_points(TP->Query("cards"))+".\n");
  if (check_won(TP->Query("cards"))>21) {
    write("The dealer says: Oh sorry, you have lost the game.\n");
    iplayer=0; 
  }
  return 1;
}

//****************************
// dealer will check his cards
//****************************
int cmd_enough(string str) {
  int playercards,own;

  if (!TP) return 0;                      // don't deal with no objects
  if (str) { notify_fail("Use a simple 'enough' to let the dealer "
             "finishs the game.\n"); return 0; }
  if (iplayer!=TP->QueryRealName()) {
    if (iplayer==0) {
      notify_fail("Start a new game with 'play game'.\n");
      return 0;
    }
    notify_fail("There is another player playing the game!\n");
    return 0;
  }
  // the dealer stops the game in each case!
  iplayer=0;                // no game is running
  write("The dealer checks his cards.\n");
  // store the amount of the player
  playercards=calc_int_points(TP->Query("cards"));
  own=calc_int_points(dealcard);
//  write("player: "+playercards+", own: "+own+"\n");
  if (own>=playercards) {
    write("The dealer says: Oh cool I have won the game without playing.\n");
    return 1; 
  }
  while ((own<=playercards) && own<=21) {
    write("The dealer says: hmm have to take an additional card.\n");
    write("The dealer gives himself a card. It is a "+
          printcard(cards[0])+".\n");
    dealcard+=({ cards[0] });
    cards-=({ cards[0] });
    own=calc_int_points(dealcard);
//    write("player: "+playercards+", own: "+own+"\n");
    if ((sizeof(dealcard)==2) && (own==22)) {        // two aces
      write("The dealer cries loud: Yeah strike - I won with two Aces!\n");
      return 1;
    }
  }
  if (own>21) {
    write("The dealer hmms, I have too much - you won the game.\n");
    return 1;
  }
  write("Yeah, I won the game with "+calc_points(dealcard)+"! Coool.\n");
  return 1;
}

//**************************************************************
// overloaded the QueryLong function to allow looking at 'cards'
//**************************************************************
string QueryLong() {
  if (!TP) return 0;
  if (strstr(QueryLastId()||"","cards")!=-1) {
    return "You see 32 cards of a normal card game.\n";
  }
  return
  "It is a card game, mostly used for playing the wellknown '17+4' game.\n"
  "You can take a look at the cards to see what cards are used here.\n"
  "If you want to try a game - type: 'play game'\n";
}

//*******
// create
//*******
create() {
  ::create();
  SetShort("a card game");
//  SetNoGet("The card game belongs to this table.\n");
  SetIds(({"game","cards"}));
  SetAds(({"card"}));
  vals=([
    "7"     : 7,
    "8"     : 8,
    "9"     : 9,
    "10"    : 10,
    "Jack"  : 2,
    "Queen" : 3,
    "King"  : 4,
    "Ace"   : 1
    ]);
  iplayer=0;
  call_out("mix_cards",1);
}

//*****
// init
//*****
init() {
  ::init();
  add_action("cmd_play","play");
  add_action("cmd_enough","enough");
  add_action("cmd_card","card");
}

