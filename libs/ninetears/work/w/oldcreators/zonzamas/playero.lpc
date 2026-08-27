 inherit "/obj/monster";
 
 void setup() {
       set_name("playero");
       add_adjective("tough");
       set_race("human");
       set_al(30);
       set_short("playero");
       set_main_plural("playeros");
       add_plural("playeros");
       set_level(10);
       set_wimpy(50);
       set_random_stats(9, 15);
       set_str(15);
       set_long(
          "Es un joven apuesto, te mira con lagrimas en los ojos,"
    " parece que le acaban de dar una paliza por sus numerosas heridas,"
    "parece que esta dispuesto a corer a la mas minima senyal de peligro.\n");
       
       adjust_money(random(10),"gold");
       load_chat(30,
          ({
           1,"'Me vas a pegar?\n",
           2,"'No te tengo miedo.\n",
         }));
    
    add_clone("/baseobs/weapons/military_fork",1);
    add_clone("/baseobs/armours/sma_shield",1);
//       init_equip();
 
 } 

