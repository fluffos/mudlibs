#include <std.h>
#include <illuminati.h>
inherit MONSTER;
void create() {

    ::create();
    set_name("rand");
    set_short("%^BOLD%^WHITE%^Rand A'la%^RESET%^");
    set_long("Rand A'la, he creates the Heartstones and Angreal for use by the Illuminati. He radiates a very powerful magical aura, perhaps you shouldn't mess
with him.");
     set_race("human");
     set_level(30);
     set_body_type("human");
     set_gender("male");
     set_id( ({ "rand" }) );
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
 write("%^BOLD%^WHITE%^The sign reads:
%^RESET%^ORANGE%^-----------------------------------------
 [ %^BOLD%^WHITE%^Heartstone %^RESET%^ORANGE%^]
     A heartstone. It is used to heal members from damage. 
                                      ( %^BOLD%^WHITE%^20 gold pieces %^RESET%^ORANGE%^)

 [ %^BOLD%^WHITE%^Lifestone %^RESET%^ORANGE%^]
     A lifestone. It is used to heal large amounts of damage.
                                      ( %^BOLD%^WHITE%^50 gold pieces %^RESET%^ORANGE%^)

 [ %^BOLD%^WHITE%^Angreal %^RESET%^ORANGE%^]
     An angreal. It is used to restore a members mana. 
                                      ( %^BOLD%^WHITE%^30 gold pieces %^RESET%^ORANGE%^)

 [ %^BOLD%^WHITE%^Sa'Angreal %^RESET%^ORANGE%^]
     A Sa'Angreal. More powerful kind of Angreal.
                                      ( %^BOLD%^WHITE%^120 gold pieces %^RESET%^ORANGE%^)

-----------------------------------------%^RESET%^");
 return 1;
}

int fBuy(string str) {
    object oil;
    int numba;
    if(!str) {  
      this_object()->force_me("say Buy what?");
      return 1;
      }
    if(str!="heartstone" && str!="angreal") {
      if(sscanf(str, "%d %s", numba, str) != 2) {
        this_object()->force_me("say I dont have that for sale.");
        return 1;
        }

      }
 switch(str)
 {
 case "heartstone":
 case "heartstones":
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
      write(capitalize(this_object()->query_name())+" hands you "+(string)numba+" heartstones.");
      say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" "+(string)numba+" heartstones.");
      while(numba > 0) {
        oil = new(ILOBJ"heartstone");
        if(numba >= 15)
          oil->set_uses(15);
        else
          oil->set_uses(numba);
        numba -= 15;
        oil->move(this_player());
      }
      return 1;
    }
    command("say You may only 'buy number heartstones'.");
    return 1;
  break;
 case "angreal":
 case "angreals":
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
      write(capitalize(this_object()->query_name())+" hands you "+(string)numba+" angreals.");
      say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" "+(string)numba+" angreals.");
      while(numba--)
        new(ILOBJ"angreal")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write(capitalize(this_object()->query_name())+" hands you an angreal.");
    say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" an angreal.");
    new(ILOBJ"angreal")->move(this_player());
    return 1;
break;
 case "saangreal":
 case "saangreals":
 case "sa'angreal":
 case "sa'angreals":
    if(this_player()->query_money("gold") < 120 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    if(numba) {
      if(numba < 1 || numba > 1000) return 0;
      if(this_player()->query_money("gold") < 120*numba ) {
        this_object()->force_me("say You don't have that much money!");
        return 1;
      }
      this_player()->add_money("gold", -120*numba);
      write(capitalize(this_object()->query_name())+" hands you "+(string)numba+" sa'angreals.");
      say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" "+(string)numba+" sa'angreals.");
      while(numba--)
        new(ILOBJ"saangreal")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -120);
    write(capitalize(this_object()->query_name())+" hands you a sa'angreal.");
    say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" a sa'angreal.");
    new(ILOBJ"angreal")->move(this_player());
    return 1;
break;
}
}

string query_guild() {
       return "illuminati";
}
