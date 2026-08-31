//Coded by Ace
#include <std.h>
#include <ace.h>
inherit OBJECT;

#define MAX_BET 500
void init() {
    ::init();
    add_action("cmd_play", "play");
    add_action("cmd_toss", "toss");
    add_action("make_bet", "bet");
}
int r1, r2, bet, player=0;
int tell_watchers(string str, object tp);
int bad_bet(object tp);

void create() {
    ::create();
  set_id(({"bones"}));
  set_name("bones");
  set_short("a small set of bones");
  set_long( "There are twelve bones with a number etched "
     "into each bone.  They were made to play the game of bones.");
  set_mass(1);
  set_value(0);
  set_prevent_get("You can only take the bones to play with.");
  set_properties((["no auction":1]));
}
int drop() { 
  message("info", "Not until you're done playing.", this_player());
  return 1;
}
int cmd_play(string str) {
    if(!str) return 0;
    if(str!="bones") return 0;
    if(player==1) return notify_fail("You are already playing.\n");
    player=1; bet=0;
    message("info", "You get the bones.", this_player());
    message("info", this_player()->query_cap_name()+" gets "
      "a set of bones.", environment(this_player()), this_player());
    this_object()->move(this_player());
    return 1;
}
int make_bet(string amount) {
    int b; 
    if(!amount) return 0;
    b=to_int(amount);
    if(player==0) return notify_fail("You must be playing first.\n");
    if(bet!=0) return notify_fail("You've already placed a bet.\n");
    if (b>MAX_BET) return notify_fail("The max bet you can make is "+MAX_BET+" gold.");
    if(b>(int)this_player()->query_money("gold"))
      return notify_fail("You do not have that much gold.\n");
   
    if(b<=0) return bad_bet(this_player());
    this_player()->add_money("gold", -b);
    message("info", "You place a bet for "+b+" gold.", this_player());
    tell_watchers(""+this_player()->query_cap_name()+" places "
      "a bet for "+b+" gold in the game of bones.", this_player());
    bet=b;
    r1=0; r2=0;
    return 1;
}
int cmd_toss(string str) {
    int b1, b2;
    if(!str) return 0;
    if(str!="bones") return 0;
    if(bet==0) return notify_fail("You must bet first.\n");
    if(player==0) return notify_fail("You must be playing first.\n");
    b1=random(6)+1; b2=random(6)+1;
    message("info", "You tossed a "+b1+" and a "+b2+".", this_player());
    tell_watchers(""+this_player()->query_cap_name()+" tossed "
      "a "+b1+" and a "+b2+" in the game of bones.", this_player());
    if( (r1==0) && ((b1+b2==2)||(b1+b2==3)) ) {
      message("info", "You lose.", this_player());
      tell_watchers(""+this_player()->query_cap_name()+" lost.",
        this_player());
    }
    else if( (r1==0) && (b1+b2==12) ) {
      message("info", "You got bones! You lose.", this_player());
      tell_watchers(""+this_player()->query_cap_name()+" got bones "
        "and lost.", this_player());
    }
    else if( (r1==0) && ((b1+b2==7)||(b1+b2==11)) ) {
      message("info", "%^YELLOW%^You win "+bet*2+" gold!%^RESET%^", this_player());
      this_player()->add_money("gold", bet*2);
      tell_watchers(""+this_player()->query_cap_name()+" won!",
        this_player());
    }
    else if(b1+b2==r1+r2) {
      message("info", "%^YELLOW%^You win "+bet*2+" gold!%^RESET%^", this_player());
      this_player()->add_money("gold", bet*2);
      tell_watchers(""+this_player()->query_cap_name()+" won!",
        this_player());
    }
    else if((r1!=0)&&(b1+b2==7)) {
      message("info", "You lose.", this_player());
      tell_watchers(""+this_player()->query_cap_name()+" lost.",
        this_player());
    }
    else {
      message("info", "Toss again.", this_player());
      if(r1==0) {
        r1=b1; r2=b2;
      }
      return 1;
    }
    player=0;
    message("info", "You drop the bones.", this_player());
    message("info", this_player()->query_cap_name()+" drops "
      "a set of bones.", environment(this_player()), this_player());
    this_object()->move(environment(this_player()));
    return 1;
}
int tell_watchers(string str, object tp) {
  object ob;
  if(!str) return 0;
  if(!tp) return 0;
  if(present("bones mat", environment(environment(this_object())))) {
    ob=present("bones mat", environment(environment(this_object())));
    ob->tell(str, tp);
  }
  return 1;
}
int bad_bet(object tp) {
    player=0;
    message("info", "Only people who bet real money can play "
     "the game of bones.", tp);
    message("info", "You drop the bones.", tp);
    message("info", tp->query_cap_name()+" drops "
      "a set of bones.", environment(tp), tp);
    this_object()->move(environment(tp));
    return 1;
}
