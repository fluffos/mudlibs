#define CREATOR "Gareth"
inherit "/obj/armour"; 

void setup()  
{ 
 	set_base_armour("cota_elfica");

	set_name("cota del bosque");
	set_short("%^BLACK%^%^BOLD%^Cota %^RESET%^del %^GREEN%^Bosque%^RESET%^");  
	set_long("Es una Cota fabricada por los Elfos hace mucho tiempo, pero se dice que una manada de zorros la encontro y la guardaron como tesoro, y que si se les llama vendran a ayudar al poseedor.\n");
	add_alias("cota");
	add_alias("bosque");
  	set_main_plural("cotas del bosque"); 
  	add_plural("cotas");
 	set_enchant(5);
  	add_timed_property("con",20,9999);  	
  	add_property("no_steal",1);
  	reset_drop();
}

void init() {
  	::init();
   	add_action("llamada", "llamar");
	}

int llamada(string str) {
	object *atacantes;
	int i,x,max;

	if (TP->query_dead()) return notify_fail("Estas muerto, no puedes utilizar la Cota.\n");
	if (member_array(TO,TP->query_worn_ob())==-1) return notify_fail("Tienes que tener puesta la Armadura para poder usar su poder.\n");
	if (TO->query_timed_property("cargando")) return notify_fail("El zorro esta descansando en el bosque, es demasiado pronto para llamarlo.\n");
	
	atacantes = TP->query_attacker_list();
	if (!sizeof(atacantes)) return notify_fail("Nadie te esta atacando.\n");	
	tell_object("Llamas al zorro en tu ayuda, y de pronto ves uno de ellos corriendo a toda velocidad"
		" hacia tus atacantes y golpeandolos fuertemente.\n El zorro te hace un gesto de saludo y se va corriendo"
		" al bosque.\n");

	TO->add_timed_property("cargando",1,50);

	for (x=0;x<sizeof(atacantes);x++)

{
	tell_object(atacantes[i], TP->query_cap_name()+" pronuncia unas palabras y un zorro viene corriendo a toda velocidad"
       			" El zorro se dirige hacia ti y te golpea fuertemente, dejandote un dolor por todo el cuerpo.\n",TP);
	atacantes[i]->adjust_hp(-100000,TP);
	atacantes[i]->add_timed_property("passed out",1,20);
	tell_room(environment(TO),TP->query_cap_name()+ " pronuncia unas palabras"
       			" y un zorro aparece a toda velocidad. "
       			" El zorro se dirige a %^BOLD%^"+atacantes[i]->query_cap_name()+"%^RESET%^ y lo golpea "
       			"con gran furia y rapidez. El zorro se va corriendo por donde vino.\n",atacantes[i],TP);
	return 1;
}
}