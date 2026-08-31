//Coded by Ace
#include <std.h>
#include <ace.h>
inherit OBJECT;

#define MAX_BET 500
void init() {
    ::init();
    add_action("cmd_spin", "spin");
    add_action("make_bet", "bet");
}
mapping betters;

void create() {
    ::create();
  set_id(({"roulette wheel", "roulette", "wheel"}));
  set_name("roulette");
  set_short("a roulette wheel");
  set_long( "The roulette wheel contains 37 numbers, from zero "
     "to thirty-six.");
  set_mass(1);
  set_value(0);
  set_prevent_get("You can't take the roulette wheel!");
  betters=([ ]);
}
int make_bet(string str) {
    int b;
    string where, amount, *players;

    if(!str) return 0;
    sscanf(str, "%s on %s", amount, where);
    if(amount==0) return notify_fail("bet <amount> on <place>\n");
    if(where==0) return notify_fail("bet <amount> on <place>\n");
    b=to_int(amount);
    if(b>(int)this_player()->query_money("gold"))
      return notify_fail("You do not have that much gold.\n");
    if(b<=0) return notify_fail("You can't bet that much.\n");
    if (b>MAX_BET) return notify_fail("You can't bet that much.\n");
    players=keys(betters);
    for(int i=0; i<sizeof(players); ++i) {
      if(this_player()->query_cap_name()==players[i])
        return notify_fail("You've already placed a bet.\n");
    }
    this_player()->add_money("gold", -b);
    message("info", "You place a bet for "+amount+" on "+where+".",
      this_player());
    betters+=([ this_player()->query_cap_name() : ({ amount, where }) ]);
    return 1;
}
int cmd_spin(string str) {
    int amount, spin, a, b, c, d, e, f;
    string *s, where, sspin, *players;
    object ob;

    if(!str) return 0;
    if(str!="wheel") return 0;
    if(this_player()->query_name()!="Greg the Roulette Guy")
      return notify_fail("Only the Roulette Guy can spin the wheel.\n");
    players=keys(betters);
    spin=random(27);
    sspin=""+spin+"";
message("info", "%^CYAN%^Greg says%^RESET%^: Betting "
      "is closed.", environment(this_player()) );
    message("info", this_player()->query_cap_name()+" spins the "
      "roulette wheel.", environment(this_player()) );
    message("info", "The ball stops on "+spin+".",
      environment(this_player()) );
    message("info", "%^CYAN%^Greg says%^RESET%^: Place your bets!",
      environment(this_player()) );
    for(int i=0; i<sizeof(players); ++i) {
      s=betters[players[i]];
      ob=find_player(lower_case(players[i]));
      amount=to_int(s[0]);
      where=s[1];
      if(where==sspin) {
message("info", "%^BOLD%^%^BLUE%^Greg shouts:%^RESET%^ "+ob->query_cap_name()+" won "+35*amount+" at the roulette table!", users());
        message("info", "You win "+35*amount+" gold.", ob);
message("info", "%^CYAN%^Greg says%^RESET%^: We have a winner!", environment(this_player()) );
        ob->add_money("gold", 35*amount);
      }
      else if( (where=="even")&&(spin%2==0) ) {
       message("info", "You win "+amount*5/4+" gold.", ob);
message("info", "%^CYAN%^Greg says%^RESET%^: We have a winner!", environment(this_player()) );
        ob->add_money("gold", amount*5/4);
      }
      else if( (where=="odd")&&(spin%2!=0) ) {
       message("info", "You win "+amount*5/4+" gold.", ob);
message("info", "%^CYAN%^Greg says%^RESET%^: We have a winner!", environment(this_player()) );
        ob->add_money("gold", amount*5/4);
      }
      else if( (where=="low")&&((spin>0)&&(spin<19)) ) {
       message("info", "You win "+amount*4/3+" gold.", ob);
message("info", "%^CYAN%^Greg says%^RESET%^: We have a winner!", environment(this_player()) );
        ob->add_money("gold", amount*4/3);
      }
      else if( (where=="high")&&(spin>18) ) {
       message("info", "You win "+amount*4/3+" gold.", ob);
message("info", "%^CYAN%^Greg says%^RESET%^: We have a winner!", environment(this_player()) );
        ob->add_money("gold", amount*4/3);
      }
      else if( (where=="first")&&((spin>0)&&(spin<13)) ) {
        message("info", "You win "+2*amount+" gold.", ob);
message("info", "%^CYAN%^Greg says%^RESET%^: We have a winner!", environment(this_player()) );
        ob->add_money("gold", 2*amount);
      }
      else if( (where=="second")&&((spin>12)&&(spin<25)) ) {
        message("info", "You win "+2*amount+" gold.", ob);
message("info", "%^CYAN%^Greg says%^RESET%^: We have a winner!", environment(this_player()) );
        ob->add_money("gold", 2*amount);
      }
      else if( (where=="third")&&(spin>24) ) {
        message("info", "You win "+2*amount+" gold.", ob);
message("info", "%^CYAN%^Greg says%^RESET%^: We have a winner!", environment(this_player()) );
        ob->add_money("gold", 2*amount);
      }
      else if( sscanf(where, "%d and %d and %d and %d and %d and %d", a, b, c, d, e, f)==6 ) {
        if( (a==spin)||(b==spin)||(c==spin)||(d==spin)||(e==spin)||(f==spin) ) {
          message("info", "You win "+5*amount+" gold.", ob);
          ob->add_money("gold", 5*amount);
        }
      }
      else if( sscanf(where, "%d and %d and %d and %d", a, b, c, d)==4 ) {
        if( (a==spin)||(b==spin)||(c==spin)||(d==spin) ) {
          message("info", "You win "+8*amount+" gold.", ob);
          ob->add_money("gold", 8*amount);
        }
      }
      else if( sscanf(where, "%d and %d and %d", a, b, c)==3 ) {
        if( (a==spin)||(b==spin)||(c==spin) ) {
          message("info", "You win "+11*amount+" gold.", ob);
          ob->add_money("gold", 11*amount);
        }
      }
      else if( sscanf(where, "%d and %d", a, b)==2 ) {
        if( (a==spin)||(b==spin) ) {
          message("info", "You win "+17*amount+" gold.", ob);
          ob->add_money("gold", 17*amount);
        }
      }
    }
    betters=([]);
    return 1;
}

