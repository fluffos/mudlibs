inherit "/obj/weapon";

void setup() {
   set_base_weapon("dagger");
   set_name("Baston de los %^BOLD%^Tormentos%^RESET%^");
   set_short("Baston de los %^BOLD%^Tormentos%^RESET%^");
   add_alias("baston");
   set_long("Esto es un baston de madera, util para ayudar apoyar al caminar o defenderse en caso de necesidad.\n");
   set_main_plural("Bastones de los %^BOLD%^Tormentos%^RESET%^");
   add_property("noslice",1);
   set_twohanded(1);    
}


int query_damage_roll()
{
   return ::query_damage_roll() + random(40);
}

void write_message(string happen,int dam,string str,object me,object him) 
{
	  if(dam <= 0)
	  {
	    tell_room(ENV(me),me->query_cap_name()+" balancea su "
		"baston sin llegar a alcanzar a "+him->query_cap_name()+".\n"
		,({him,me}));
	  write("Balanceas tu baston sin ser capaz de alcanzar a "+him->query_cap_name()+".\n");
	  tell_object(him,me->query_cap_name()+" balancea su baston sin llegar a alcanzarte.\n");
	  }
	  else if(dam <11)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" golpea levemente en el costado a "+him->query_cap_name()+".\n"
		,({him,me}));
	  write("Golpeas levemente a "+him->query_cap_name()+" en el costado con tu baston.\n");
	  tell_object(him,me->query_cap_name()+" te golpea levemente en el costado con su baston.\n");
	  }	
	  else if(dam >10 && dam < 22)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" golpea el abdomen de "+him->query_cap_name()+" produciendole dolorosos moratones.\n",({him,me}));
	  write("Golpeas el abdomen de "+him->query_cap_name()+" con tu baston produciendole dolorosos moratones.\n");
	  tell_object(him,me->query_cap_name()+" te golpea el abdomen con su baston produciendote dolorosos moratones.\n");
	}	
	else if(dam>21 && dam<50)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" machaca el torso de "+him->query_cap_name()+" con un agil movimiento de su baston destrozandole las costillas.\n" ,({him,me}));
	  write("Con un agil movimiento de tu Baston de los %^BOLD%^Tormentos%^RESET%^ machacas el torso de "+him->query_cap_name()+" destrozandole las costillas.\n");
	  tell_object(him,me->query_cap_name()+" con un agil movimiento de su Baston de los %^BOLD%^Tormentos%^RESET%^ te machaca el torso destrozandote las costillas.\n");
	}
		else
	  {
	  tell_room(ENV(me),me->query_cap_name()+" dibuja un simbolo en el aire con su Baston de los %^BOLD%^Tormentos%^RESET%^ "
		"que acaba impactando brutalmente en la cabeza de "+him->query_cap_name()+" desfigurandole el rostro. Su cara "
		"comienza a %^RED%^BOLD%^sangrar%^RESET%^ abundantemente.\n",({him,me}));
	  write("Dibujas un simbolo en el aire con tu Baston de los %^BOLD%^Tormentos%^RESET%^ impactando brutalmente "
	  	"sobre la cabeza de "+him->query_cap_name()+" desfigurandole el rostro. Su cara comienza "
                "a %^RED%^BOLD%^sangrar%^RESET%^ abundantemente.\n");
	  tell_object(him,me->query_cap_name()+" dibuja un simbolo en el aire con su Baston de los %^BOLD%^Tormentos%^RESET%^ "
	  	"para luego impactar brutalmente en tu cabeza desfigurandote el rostro. Tu cara comienza "
                "a %^RED%^BOLD%^sangrar%^RESET%^ abundantemente.\n");
	}

}