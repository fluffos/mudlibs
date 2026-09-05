#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alt_name("bastard sword");
    set_alias("sword");
set_name("An iron bastard sword of the humakti");
    set_short("An "+BOLD+BLK+"Iron"+NORM+" bastard sword of the Humakti");
    set_long("This finely forged sword is made of the metal Iron, a coveted\n"+
    "metal for adventurers.  The runes enscribed along the blade absorb all\n"+
    "the light hitting it.  It looks deadly.\n");
set_read("You can not read the runes but know the death rune is prevelant.\n");
set_class(19);
    set_weight(3);
    set_type("sword");
    set_weight(3);
    set_value(3000);
    set_hit_func(this_object());
}

query_save_flag(){ return 1; }

weapon_hit(attacker){
int sph;
sph = random(9);
if(sph==0){
write("The "+BOLD+BLK+"Iron"+NORM+" bastard sword bites deep into the skin.\n");
}
if(sph==1){
write(RED+"Blood"+NORM+" runs down the iron blade.\n");
}
if(sph==2){
write(BOLD+BLK+"Iron"+NORM+" bites deep into its advosary.\n");
}
if(sph==3){
write(BOLD+"\n"+"\n"+
"                                   @@@@@@   \n"+
"                                   @@@@@@   \n"+ 
"                                   @@@@@@   \n"+
"                                @@@@@@@@@@@@     \n"+ 
"                                @@@@@@@@@@@@     \n"+
"                                @@@@@@@@@@@@     \n"+
"                                   @@@@@@   \n"+
"                                   @@@@@@   \n"+ 
"                                   @@@@@@   \n"+
"                                   @@@@@@   \n"+
"                                   @@@@@@   \n"+
"                                   @@@@@@   \n"+ 
"                                   @@@@@@   \n"+
"                                   @@@@@@   \n"+ 
"                                   @@@@@@   \n"+
"                                   @@@@@@ \n\n"+
""+NORM+"a"+BOLD+BLK+" death"+NORM+" rune explodes with power....\n"+NORM);
say(BOLD+BLK+"\nDeath"+NORM+BOLD+" explodes into "+NORM+attacker->query_name()+".\n\n");
return 8;
}
if(sph==4){
write("A"+BOLD+BLK+" death "+NORM+"rune glows with power.\n");
say("A"+BOLD+BLK+ "death "+NORM+" rune glows feeding on "+NORM+attacker->query_name()+".\n");
return 3;
}
if(sph==5){
write(BOLD+"\n"+"\n"+
"                             @@@@@          @@@@@\n"+ 
"                              @@@@@        @@@@@ \n"+
"                               @@@@@      @@@@@  \n"+ 
"                                @@@@@    @@@@@   \n"+
"                                 @@@@@  @@@@@    \n"+
"                                  @@@@@@@@@@     \n"+
"                                    @@@@@@   \n"+ 
"                                    @@@@@@   \n"+
"                                    @@@@@@   \n"+
"                                    @@@@@@   \n"+
"                                    @@@@@@   \n"+ 
"                                    @@@@@@   \n"+
"                                    @@@@@@   \n"+ 
"                                    @@@@@@   \n"+
"                                    @@@@@@ \n\n"+
""+NORM+"a"+BOLD+BLK+" truth"+NORM+" rune explodes...\n"+NORM);
say(BOLD+"Truth explodes from the death blade"+NORM+".\n\n");
if(attacker->query_alignment() > 0) {
this_player()->add_hit_point(-10);
write("message, if you want one.");
return 0;}
return 8;
}

}
