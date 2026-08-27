inherit "/std/object"; 

int ocupado = 0;

void setup() {
  set_name("cabeza empalada");
  set_short("Cabeza empalada");
  add_alias("cabeza");
  add_adjective("empalada");
  set_long("Ante tus horrorizados ojos se encuentra una cabeza de goblin "
  "empalada bestialmente en un asta de mas de metro y medio que esta "
  "clavada en el suelo. La cara del goblin muerto muestra una grotesca "
  "mueca de horror y dolor que te provoca malestar. Al acercarte un poco "
  "mas, percibes que los ojos del pobre goblin han sido arrancados.\n"
  "El asta posee unos curiosos grabados.\n");
  reset_get();                                   
} /* setup */

void init() {
  ::init();
  add_action("do_leer","leer");
  add_action("do_introducir","introducir");
  ocupado = 0;  
}

int do_leer(string que)
{
  if(!que)
  { 
      notify_fail("Leer que?\n");
      return 0;
  }      
  if(que == "grabados")
  {
      write("No consigues traducir el significado de estos grabados, pero "
            "deduces que se trata de una especie de jeroglifico. Consigues "
            "identificar un humanoide introduciendo la mano en alguna "
            "especie de cavidad. No puedes distinguir apenas la "
            "configuracion de tal accion, puesto que el oxido ha devorado "
            "parte del grabado.\n");
      return 1;
  } else {
      notify_fail("Leer que?\n");
      return 0;  	
  }	
} /* do_leer */

void invoca_goblin(object myp)
{
     ocupado = 1;
     write("Lentamente introduces tu dedo indice y pulgar en cada una "
  	   "de las vacias cuencas oculares. Antes de meterlos del todo, "
  	   "sientes que la cabeza del goblin cobra vida...\n\n");
     call_out("invoca2", 3, myp);
} /* invoca_goblin */

void invoca2(object myp)
{
     write("%^BOLD%^De los ojos del shaman salen sendos haces luminosos "
  	   "que empiezan a girar violentamente en todas direcciones. La "
  	   "cabeza comienza a cobrar vida...%^RESET%^\n\n");
     call_out("invoca3", 3, myp);
} /* invoca2 */

void invoca3(object myp)
{
     write("Bajo la cabeza del goblin y hacia lo largo del asta empieza a "
  	   "generarse una masa putrefacta de carne, que acaba tomando la "
  	   "forma de un cuerpo. Un cuerpo de goblin.\n\n");
     call_out("invoca4", 3, myp);
} /* invoca3 */

void invoca4(object myp)
{
     write("El goblin cobra vida de nuevo, y de sus ojos vuelven a manar "
           "otros haces de luz, que se detienen al encontrar tus ojos. Por "
           "un momento, el tiempo parece detenerse. Tu alma y la del goblin "
           "entran en contacto... puedes ver su pasada vida, puedes percibir su "
           "sufrimiento. Puedes ver como el shaman JZhadra sacrifico a este "
           "goblin, como sacrifico sus ojos a los espiritus del bosque, y "
           "como le decapito violentamente para convertirlo en un mero "
           "adorno ceremonial. Sientes el odio que emana del alma en pena "
           "del goblin.\n\n");
     call_out("invoca5", 6, myp);
} /* invoca4 */

void invoca5(object myp)
{
     write("El goblin emite un profundo grito gutural, que resuena en tu "
           "mente y destroza tu alma. El haz de luz que estaba en contacto con "
           "tus ojos detiene su emision bruscamente.\n"
           "El goblin estalla en cientos de pedazos, su reseco cadaver "
           "se desmenuza en cientos de pedazos que salen volando por doquier...\n"
           "Atomo a atomo, molecula a molecula, el goblin desaparece.\n\n"
           "Notas una extranya sensacion en tus ojos, tu agudeza visual se incrementa, "
           "asi como la fuerza de los mismos.\n\n");
     
     this_player()->add_property("proteccion_ojo", 1);
     this_object()->dest_me();
     ocupado = 0;
} /* invoca4 */

int do_introducir(string que)
{
  object myp = TP;
  if (this_player()->query_property("proteccion_ojo"))
  {
  	write("No parece ocurrir nada...\n");
  	return 0;
  } else
  {
  if (!que)
  {
  	notify_fail("Introducir que?\n");
  	return 0;
  }
  if (que == "dedos en ojos")
  {
  	if (ocupado)
  	{
  		notify_fail("Ya has hecho eso.\n");
  		return 0;
  	} else {
  		invoca_goblin(myp);
  		return 1;
	}
  } else {
  	notify_fail("Introducir que?\n");
  	return 0;
  }
} }
