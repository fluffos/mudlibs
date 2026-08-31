//// Armour for Waterworld level 1 -- Tirun bay
////

#include <std.h>
#include <waterworld.h>

inherit ARMOUR;

int wear_ok;
int extra_worn();
int extra_remove();
////////////////////////////////////////////////////////////////////////
int controller = 5 ;

// Adjust this value if you wish to lengthen or shorten the healing rate
//
////////////////////////////////////////////////////////////////////////

void create() {
       ::create();
            set_name("Soul Bracers");
             set_id(({"soul bracers","bracer","Soul Bracers","bracers"}));
             set_short("The %^BLACK%^%^BOLD%^Soul%^WHITE%^%^BOLD%^ bracer.");
             set_long("The %^BLACK%^%^BOLD%^Soul%^WHITE%^%^BOLD%^ bracer%^RESET%^ of Atlantis. Energy pulses from them like a rhythmic %^RED%^heartbeat%^RESET%^...");
             set_type("bracers");
             set_ac(3);
             set_weight(5+random(15));
             set_limbs(({"right hand","left hand"}));

             set_heart_beat(1);
             set_wear( (: extra_worn :) );
             set_remove( (: extra_remove :) );
             set("read","\n\nForged by the very hands of Poseidon himself!!!!\n\n");

                     }

/// special effects

int extra_worn() {
        object tp;
        tp=this_player();

      if( (tp->query_property("soulbracers"))==0) {
           message("info","Your %^BLACK%^%^BOLD%^soul%^RESET%^ hums as the power of the bracers fill you with %^ORANGE%^%^BOLD%^energy%^RESET%^!!",tp);
           message("info",(tp->query_cap_name())+" hums as the power of the bracers fill them with %^ORANGE%^%^BOLD%^energy%^RESET%^!!",environment(tp),tp);
           tp->set("soulbracers",1);
           return 1;
         }
      else
          {
           message("info","Wearing two sets of these bracers would nullify the effect......\n\n",tp);
           return 0;
            }

    }
int extra_remove() {

        object tp;

         tp=this_player();

        tp->set("soulbracers",0);
         message("info","The hum that surrounded you fads away as you remove the %^BLACK%^%^BOLD%^Soul %^WHITE%^%^BOLD%^Bracers%^RESET%^ from your wrists...",tp);
         message("info","The hum that surrounded "+(tp->query_caps_name())+" fads away as they remove their %^BLACK%^%^BOLD%^Soul %^WHITE%^%^BOLD%^Bracers%^RESET%^ from their wrists...",environment(tp),tp);
          return 1;
       }

void heart_beat() {
        object tp;
        int tp_msp;
        int s_rate;
       int counter;

        if(tp=this_object()->query_worn()) {
                tp_msp=tp->query_max_sp();
                s_rate=((tp_msp)/100);
             if(counter > controller ) tp->add_sp(s_rate);
                 else counter = counter + 1;
              }
    }
