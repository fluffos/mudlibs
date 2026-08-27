//Paris. Mar'98
inherit "/obj/weapon";

int query_value()
{
	return 76000;
}
void init()
{
	::init();
	add_action("marcar_objeto","marcar");
}
int marcar_objeto(string str) 
{ 
   notify_fail("Te es imposible marcar "+TO->query_name()+" como personal e intrasferible.\n"); 
   if(!str) return(0); 
   if(str != "hacha") return(0); 
 
   if(TP->query_guild_name() !="Mago Guerrero") 
   { 
      tell_object(this_player(), "No tienes el poder suficiente como"
                  " para poder marcar este objeto.\n"); 
      return(1); 
   } 
 
  if(this_object()->query_property("OWNER")) { 
     tell_object(this_player(), TO->query_name()+" ya pertenece a "
                 "alguien.\n"); 
    return(1); 
  } 
 
 
  this_object()->add_property("OWNER", this_player()->query_name()); 
  tell_object(this_player(), TO->query_name()+" es tuyo hasta el fin de "
              "los tiempos.\n"); 
  return(1); 
}

void setup()
{
	set_base_weapon("twohanded axe");
	set_name("hacha");
	set_short("Hacha %^RED%^BOLD%^Runica%^RESET%^");
	set_main_plural("Hacha %^RED%^BOLD%^Runica%^RESET%^");	
	add_alias("hacha runica");
	add_alias("runica");
	add_plural("runicas");
	add_plural("hachas runicas");
	add_attack("atake","fire",3,4,1);        	
        set_enchant(1);
        set_max_cond(500);
        adjust_cond(500);
        set_weight(100);
//	set_genero(1);
	
	set_long("Este hacha de poder inconmensurable fue construida por aquellos "
	         "tiempos por un famoso enano para Elkhar en agradecimiento por "
	         " un favor que hizo este al enano. El arma, forjada del mas puro "
		 " acero enano, fue imbuida magicamente or elkhar en cuanto la "
		 "recibio, de ahi que desprenda ese intenso calor.\n ");
		 
	add_property("guild","Mago Guerrero");
	add_timed_property("messon","El alma se te revuelve en tu interior y el cuerpo "
			"se te acelera al blandir esta poderosa arma.\n",9393939);
	add_timed_property("messoff","Al bajar el arma, sientes un ligero alivio.\n",9393939);
			
	TP->add_timed_property("fire",10,9999999);
}

/*int set_in_use(int i)
{
 if (i == 1)
 {
  TP->add_timed_property("acid",10,9999999);
 }
 return 0;
}*/  
