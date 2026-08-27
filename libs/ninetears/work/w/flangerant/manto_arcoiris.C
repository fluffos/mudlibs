inherit "/obj/armour"; 

void setup()  
   { 
   set_base_armour("manto");
   set_name("manto del arcoiris");
   set_short("Manto del %^BOLD%^%^CYAN%^A%^GREEN%^r%^RED%^c%^BLUE%^o%^YELLOW%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^MAGENTA%^i%^BLACK%^s%^RESET%^");
   add_alias("manto");
   add_alias("arcoiris");
   set_main_plural("Manto del %^BOLD%^%^CYAN%^A%^GREEN%^r%^RED%^c%^BLUE%^o%^YELLOW%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^MAGENTA%^i%^BLACK%^s%^RESET%^");
   add_plural("mantos del arcoiris");
   add_plural("mantos");
   add_plural("arcoiris");
   set_long("	El magnifico manto del arcoiris, los mil colores concentrados en un trozo"
            " de tela, que cubre el torso de su portador dandole la bendicion de los dioses."
            " Una prenda estupenda.\n\n");
   set_enchant(4000);
   
   } 