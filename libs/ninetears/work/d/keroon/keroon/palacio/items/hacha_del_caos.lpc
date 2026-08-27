//Valar Febrero 2003
    inherit "/obj/weapon";
    
    void setup() {
     set_base_weapon("hacha_dosmanos");
     set_name("%^BOLD%^BLACK%^Hacha del caos%^RESET%^");
     set_name("hacha del caos");
     set_short("%^BOLD%^BLACK%^Hacha del caos%^RESET%^");
     set_long("El arma digna de un autentico guerrero khurgar. Ligera y contundente contra los enemigos\n");
     add_alias(({"hacha", "caos"}));
     set_main_plural("%^BOLD%^BLACK%^Hachas del caos%^RESET%^");
     add_plural("hachas");
     add_adjective("del caos");
     set_twohanded(2);
     set_enchant(1);
     add_property("race","duergar");
   
     add_property("messon", "Te tiembla el pulso al sentir el poder que irradia este arma. Los dioses estan contigo!\n");
     add_property("messoff", "Tu miedo se esfuma cuando dejas de sostener este alma.\n");
     
     add_property("no_slice", 1);
     add_property("no_hunt", 1);
   }
  
    
      int set_in_use(int i, object miamo)
   {
     if (i) {
             tell_object(miamo,
             "Sientes un fuerte escalofrio por todo tu cuerpo.\n");
     }
     else
     {
             tell_object(miamo,
             "Te sientes agotado al soltar este arma.\n");
     }
     return ::set_in_use(i);
   }
   
   
   int query_damage_roll()
   {
     int res;
   
     if (TP->query_guild_name() == "asesino" && TP->query_spell_effect("emboscando")) {
             //res = ::query_damage_roll() / 2 - random(10) - 3;
             res = random(20) + 9;
             if (res > 15) res = 15;
             //tell_object(TP, "res = "+ res+ "\n");
             return (res > 0) ? res : 1;
     }
     return ::query_damage_roll();
   }
   
