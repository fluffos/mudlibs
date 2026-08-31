#include <std.h>
#include <amun.h>
#include <daemons.h>
inherit MONSTER;
void create() {
    ::create();
    set_property("no bump", 1);
    set_name("Faishyth");
    set_id( ({ "faishyth", "monster" }) );
    set_short("%^BOLD%^%^WHITE%^F%^GREEN%^a%^WHITE%^ishy%^GREEN%^t%^WHITE%^h%^RESET%^");
    set_stats("charisma" , 200);
    set_level(500);
    set_long("%^BOLD%^%^WHITE%^F%^GREEN%^a%^WHITE%^ishy%^GREEN%^t%^WHITE%^h is one of the most beautiful %^YELLOW%^archangels %^WHITE%^from Heaven. She stands tall with bright white hair flowing every so gently in an imaginary breeze. She had bright %^RESET%^%^MAGENTA%^p%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^l%^BOLD%^%^MAGENTA%^e %^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^s %^WHITE%^that can pierce into anyone's soul.%^RESET%^");
    set_gender("female");
    set_race("archangel");
    set_body_type("archangel");
    set_alignment(1500);
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
-----------------------------------------%^RESET%^
 %^BOLD%^%^WHITE%^[ %^BOLD%^%^WHITE%^Vial of %^YELLOW%^Angel's %^RED%^Blood%^WHITE%^ ]
     %^BOLD%^%^WHITE%^Vial of %^YELLOW%^Angel's %^RED%^Blood%^WHITE%^. It is used to heal player's from damage. 
                                      ( 100 gold pieces )

 %^BOLD%^%^WHITE%^[ %^BOLD%^%^YELLOW%^Honey %^BOLD%^%^WHITE%^Ambrosia %^RESET%^%^ORANGE%^Phial%^BOLD%^%^WHITE%^ ]
     %^BOLD%^%^YELLOW%^Honey %^BOLD%^%^WHITE%^Ambrosia %^RESET%^%^ORANGE%^Phial%^BOLD%^%^WHITE%^. This is used to heal large amounts of stamina.
                                      ( 150 gold pieces )

 %^BOLD%^%^WHITE%^[ %^BOLD%^%^WHITE%^L%^RESET%^i%^BOLD%^%^WHITE%^ly %^BOLD%^%^WHITE%^T%^RESET%^e%^BOLD%^%^WHITE%^ars ]
     %^BOLD%^%^WHITE%^L%^RESET%^i%^BOLD%^%^WHITE%^ly %^BOLD%^%^WHITE%^T%^RESET%^e%^BOLD%^%^WHITE%^ars. These are used to restore a player's mana. 
                                      ( 100 gold pieces )
-----------------------------------------");
 return 1;
}

int fBuy(string str) {
    object oil;
    int numba;
    if(!str) {  
      this_object()->force_me("say Buy what?");
      return 1;
      }
    if(str!="blood" && str!="ambrosia" && str!="tears") {
      if(sscanf(str, "%d %s", numba, str) != 2) {
        this_object()->force_me("say I don't have that for sale.");
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
      write(capitalize(this_object()->query_name())+" hands you "+(string)numba+" %^BOLD%^%^WHITE%^vials of %^YELLOW%^Angel's %^RED%^Blood%^WHITE%^.%^RESET%^");
      say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" "+(string)numba+" %^BOLD%^%^WHITE%^vials of %^YELLOW%^Angel's %^RED%^Blood%^WHITE%^.%^RESET%^");
     while(numba--)
        oil = new(SKYOBJ "angels_blood");
        if(numba >= 15)
          oil->set_uses(15);
        else
          oil->set_uses(numba);
        numba -= 15;
        oil->move(this_player());
      return 1;
break;
    }
    command("say You may only 'buy number blood'.");
    return 1;
  break;
 case "phial":
 case "phial":
    if(this_player()->query_money("gold") < 250 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    if(numba) {
      if(numba < 1 || numba > 1000) return 0;
      if(this_player()->query_money("gold") < 250*numba ) {
        this_object()->force_me("say You don't have that much money!");
        return 1;
      }
    this_player()->add_money("gold", -50);
    write(capitalize(this_object()->query_name())+" hands you "+(string)numba+" %^BOLD%^%^YELLOW%^H%^WHITE%^o%^RESET%^%^ORANGE%^n%^BOLD%^%^YELLOW%^e%^WHITE%^y %^RESET%^%^ORANGE%^A%^BOLD%^%^YELLOW%^m%^WHITE%^b%^RESET%^%^ORANGE%^r%^BOLD%^%^YELLOW%^o%^WHITE%^s%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^a %^WHITE%^P%^RESET%^%^ORANGE%^h%^BOLD%^%^YELLOW%^i%^WHITE%^a%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^s.%^RESET%^");
    say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" "+(string)numba+" %^BOLD%^%^YELLOW%^H%^WHITE%^o%^RESET%^%^ORANGE%^n%^BOLD%^%^YELLOW%^e%^WHITE%^y %^RESET%^%^ORANGE%^A%^BOLD%^%^YELLOW%^m%^WHITE%^b%^RESET%^%^ORANGE%^r%^BOLD%^%^YELLOW%^o%^WHITE%^s%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^a %^WHITE%^P%^RESET%^%^ORANGE%^h%^BOLD%^%^YELLOW%^i%^WHITE%^a%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^s.%^RESET%^");
       while(numba--) 
        new(SKYOBJ "honey_ambrosia_phial")->move(this_player());
}
    return 1;
break;
 case "tears":
 case "tears":
    if(this_player()->query_money("gold") < 60 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    if(numba) {
      if(numba < 1 || numba > 1000) return 0;
      if(this_player()->query_money("gold") < 60*numba ) {
        this_object()->force_me("say You don't have that much money!");
        return 1;
      }
      this_player()->add_money("gold", -60*numba);
      write(capitalize(this_object()->query_name())+" hands you "+(string)numba+" %^BOLD%^%^WHITE%^L%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^y %^BOLD%^%^WHITE%^T%^RESET%^e%^BOLD%^%^WHITE%^a%^RESET%^r%^BOLD%^%^WHITE%^s.%^RESET%^");
      say(capitalize(this_object()->query_name())+" hands "+this_player()->query_cap_name()+" "+(string)numba+" %^BOLD%^%^WHITE%^L%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^y %^BOLD%^%^WHITE%^T%^RESET%^e%^BOLD%^%^WHITE%^a%^RESET%^r%^BOLD%^%^WHITE%^s.%^RESET%^");
      while(numba--)
        new(SKYOBJ "lily_tears")->move(this_player());
}
      return 1;
break;
}
}
