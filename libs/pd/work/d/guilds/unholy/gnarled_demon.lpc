#include <std.h>
#include <guild.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("a gnarled old demon");
    set_short("a gnarled old Demon");
    set_long("%^BOLD%^%^BLACK%^This demon has %^RED%^g%^BLACK%^n%^RESET%^%^RED%^a%^BOLD%^%^RED%^r%^BLACK%^led arms and legs with %^WHITE%^h%^BLACK%^o%^WHITE%^r%^RED%^n%^BLACK%^s that curl so many times you can see that he is almost as old as %^RED%^Lord Asmodeous%^BLACK%^.%^RESET%^");
    set_race("demon");
    set_level(1000);
    set_body_type("demon");
    set_gender("male");
    set_id( ({ "demon", "monster", "gnarled demon" }) );
}

void init() {
    ::init();
    add_action("fBuy", "buy");
    add_action("fRead", "read");
}

int fRead(string str) {
    if(!str || str!="sign")
	return notify_fail("Read what?\n");
    say (this_player()->query_cap_name()+" reads over the sign.");
    write("The sign reads:
%^BOLD%^%^RED%^-----------------------------------------%^RESET%^
 %^BOLD%^%^BLACK%^[ %^BOLD%^%^RED%^B%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood %^WHITE%^of %^BLACK%^Asmodeus ]%^RESET%^
     %^BOLD%^%^RED%^B%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood %^WHITE%^of %^BLACK%^Asmodeus%^RESET%^. It is used to heal large amounts of stamina.
                                      ( 50 gold pieces )

 %^BOLD%^%^BLACK%^[ Talisman of Asmodeus ]%^RESET%^
     Talisman of Asmodeus. It is used to restore a members mana. 
                                      ( 30 gold pieces )
%^BOLD%^%^RED%^-----------------------------------------%^RESET%^");
 return 1;
}

int fBuy(string str) {
    object oil;
    int numba;
    if(!str) {  
      this_object()->force_me("say Buy what?");
      return 1;
      }
    if(str!="blood" && str!="talisman") {
      if(sscanf(str, "%d %s", numba, str) != 2) {
        this_object()->force_me("say I dont have that for sale.");
        return 1;
        }

      }
 switch(str)
 {
 case "blood":
 case "blood":
    if(this_player()->query_money("gold") < 50 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    if(numba) {
      if(numba < 1 || numba > 1000) return 0;
      if(this_player()->query_money("gold") < 50*numba ) {
        this_object()->force_me("say You don't have that much money!");
        return 1;
      }
      this_player()->add_money("gold", -50*numba);
      write(capitalize(this_object()->query_name())+" hands you
"+(string)numba+" bloods of Asmodeus.");
      say(capitalize(this_object()->query_name())+" hands
"+this_player()->query_cap_name()+" "+(string)numba+" bloods of Asmodeus.");
      while(numba--)
        new("/d/guilds/unholy/blood")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -50);
    write(capitalize(this_object()->query_name())+" hands you bloods of Asmodeus.");
    say(capitalize(this_object()->query_name())+" hands
"+this_player()->query_cap_name()+" bloods of Asmodeus.");
       while(numba > 0) {
        new("/d/guilds/unholy/blood")->move(this_player());
      }
    return 1;
  break;
 case "talisman":
 case "talisman":
    if(this_player()->query_money("gold") < 30 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    if(numba) {
      if(numba < 1 || numba > 1000) return 0;
      if(this_player()->query_money("gold") < 30*numba ) {
        this_object()->force_me("say You don't have that much money!");
        return 1;
      }
      this_player()->add_money("gold", -30*numba);
      write(capitalize(this_object()->query_name())+" hands you
"+(string)numba+" talismans.");
      say(capitalize(this_object()->query_name())+" hands
"+this_player()->query_cap_name()+" "+(string)numba+" talismans.");
      while(numba--)
        new("/d/guilds/unholy/talisman")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write(capitalize(this_object()->query_name())+" hands you talismans.");
    say(capitalize(this_object()->query_name())+" hands
"+this_player()->query_cap_name()+" talismans.");
    new("/d/guilds/unholy/talisman")->move(this_player());
    return 1;
break;
}
}

string query_guild() {
       return "unholy";
}
