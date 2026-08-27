//Zagros '99
#include "./../path.h"
inherit "/obj/weapon";

string nom;

void setup() 
{
  /*Siempre ke empieces una funcion declara las variables que necesites a principio de todo.*/
  nom = "";  
  set_base_weapon("twohanded sword");
  set_name("espada");
  add_alias("shiraa");
  set_short("%^BOLD%^Shiraa%^RESET%^, la espada curativa");
  set_long("Es la poderosa espada curativa propiedad de "+CREATOR+". Esta destinada a proteger a los nuevos inmortales"
	     " en el paso de su estado de aprendices a creadores. La espada reconoce tanto a su amo orginal como a "
		"cualquiera que lo empunye por primera vez. El rubi rojo que hay en medio de la hoja atravesandola brilla"
		" en el momento en que lo rozas indicando su poder latente. Para activarlo teclea \"vida\".\n");
  set_main_plural("espadas curativas");
  set_enchant(3);
  add_plural("espadas");
  add_plural("shiraas");


}

void destruyeme()
{

  TO->dest_me();
 

}


void init() 
{         
  string nombre;
  ::init();

  if ( nom == "" )  
      nom=(environment(TO)->query_name());
  
  nombre=this_player()->query_name();

  if ( (nombre)!=(nom) && (nombre)!=(CREATOR) && interactive (environment(TO) ) )
  {

    write("\nLa espada empieza a resquebrajarse y se parte en mil pedazos produciendo un fogonazo de luz impresionante."
	" Tu cuerpo se resiente y combulsiona, pero consigues esquivar la muerte en el ultimo momento. No debiste"
	" coger una espada que no fuera tuya.\n");
    this_player()->set_hp(1);
    call_out ("destruyeme", 1);
    return 1;
    
  }
   add_action("regeneradora", "vida");  

}


int regeneradora()
{
 if (TO->query_timed_property("vitae"))
 {
  write("La espada ha perdido su poder temporalmente, vuelve a intentarlo luego cuando se recargue.\n");
  return 1; 
 }
 else
 {
  write("Cruzas la espada sobre tu pecho, imploras a su poder y el rubi rojo empieza a brillar con intensidad.\n"
	  " Al rato sientes como vuelven parte de tus energias perdidas.\n");
  TP->adjust_hp(200);
  say(TP->query_name()+" realiza un extranyo ritual con su espada, esta empieza a brillar con una tonalidad rojiza"
	" y un aura recorre el cuerpo del duenyo cerrando algunas de sus heridas.\n");
  TO->add_timed_property("vitae",1,20);
  return 1;
 }
}





