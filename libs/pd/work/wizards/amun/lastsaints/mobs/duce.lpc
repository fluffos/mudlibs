#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Duce");
    set_short("Il Duce");
    set_long("Duce is the wisest of the Last Saints and therfore holds all the things that help you heal.");
    set_race("human");
    set_level(1000);
    set_body_type("human");
    set_gender("male");
    set_id( ({ "duce" }) );
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
%^BOLD%^%^YELLOW%^-----------------------------------------%^RESET%^
 %^BOLD%^%^WHITE%^[ %^YELLOW%^Lux %^WHITE%^Amulet ]%^RESET%^
     %^BOLD%^%^WHITE%^A %^YELLOW%^Lux %^WHITE%^Amulet. It is used to heal members from damage. 
                                      ( 20 gold pieces )

 %^BOLD%^%^WHITE%^[ %^CYAN%^Holy %^WHITE%^Water ]%^RESET%^
     %^BOLD%^%^CYAN%^Holy %^WHITE%^Water. It is used to heal large amounts of stamina.
                                      ( 50 gold pieces )

 %^BOLD%^%^WHITE%^[ %^RESET%^%^ORANGE%^Beads%^BOLD%^%^WHITE%^ ]%^RESET%^
     %^RESET%^%^ORANGE%^Beads%^BOLD%^%^WHITE%^. It is used to restore a members mana. 
                                      ( 30 gold pieces )
%^BOLD%^%^YELLOW%^-----------------------------------------%^RESET%^");
 return 1;
}

int fBuy(string str) {
    object oil;
    int numba;
    if(!str) {  
      this_object()->force_me("say Buy what?");
      return 1;
      }
    if(str!="lus amulet" && str!="holy water" && str!="beads") {
      if(sscanf(str, "%d %s", numba, str) != 2) {
        this_object()->force_me("say I dont have that for sale.");
        return 1;
        }

      }
 switch(str)
 {
 case "lux amulet":
 case "lux amulet":
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    if(numba) {
      if(numba < 1 || numba > 1000) return 0;
      if(this_player()->query_money("gold") < 20*numba ) {
        this_object()->force_me("say You don't have that much money!");
        return 1;
      }
      this_player()->add_money("gold", -20*numba);
      write(capitalize(this_object()->query_name())+" hands you "+(string)numba+" lux amulets.");
      say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" "+(string)numba+" lux amulets.");
      while(numba > 0) {
        oil = new(GUILDOBJ+"lux_amulet");
        if(numba >= 15)
          oil->set_uses(15);
        else
          oil->set_uses(numba);
        numba -= 15;
        oil->move(this_player());
      }
      return 1;
    }
    command("say You may only 'buy number lux amulet'.");
    return 1;
  break;
 case "holy water":
 case "holy water":
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
      write(capitalize(this_object()->query_name())+" hands you "+(string)numba+" holywaters.");
      say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" "+(string)numba+" holy waters.");
      while(numba--)
        new(GUILDOBJ"holy_water")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -50);
    write(capitalize(this_object()->query_name())+" hands you holy waters.");
    say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" holy waters.");
       while(numba > 0) {
        new(GUILDOBJ"holy_water")->move(this_player());
      }
    return 1;
break;
 case "beads":
 case "beads":
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
      write(capitalize(this_object()->query_name())+" hands you "+(string)numba+" beads.");
      say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" "+(string)numba+" beads.");
      while(numba--)
        new(GUILDOBJ+"beads")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write(capitalize(this_object()->query_name())+" hands you beads.");
    say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" beads.");
    new(GUILDOBJ+"beads")->move(this_player());
    return 1;
break;
}
}

string query_guild() {
       return "last saints";
}
