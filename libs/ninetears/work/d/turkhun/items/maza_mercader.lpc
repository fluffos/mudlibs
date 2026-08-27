inherit "/obj/weapon";
void setup() {
set_base_weapon("mace");
set_name("mazabarrach");
set_short("Maza de %^BOLD%^CYAN%^Abarrach%^RESET%^");
set_main_plural("Mazas de %^BOLD%^RED%^Abarrach%^RESET%^");
add_plural("mazas"); 
add_alias("maza");
add_alias("abarrach");

set_long("Se trata de un pesado trozo de metal engarzado al final de una larga vara de madera, "
	 "aparentemente es una maza convencional, pero fabricada con los conocimientos surgidos "
	 "de la investigacion en la ciudad de Abarrach.\n");
set_enchant(1);
set_weight(200);
set_twohanded(0);
add_property("no_slice",1);
}

void write_message(string happen,int dam, string str,object me,object him) {


if(happen == "no_pega" || happen == "miss") 
{
	tell_room(environment(me), "La maza de "+me->query_cap_name()+"  ""te golpea sin hacerte danyo.\n",({him,me}));
	tell_object(me,"# Tu golpe no surge el efecto esperado en "+him->query_cap_name()+".\n");
	tell_object(him,"* El ataque de "+me->query_cap_name()+" falla miserablemente.\n");
}
if (dam >0 && dam <= 7)  
{
	tell_room(environment(me), "La maza de "+me->query_cap_name()+" se golpea fuertemente a "+him->query_cap_name()+" provocandole derrames.\n",({him,me}));
	tell_object(me,"# Golpeas fuertemente a "+him->query_cap_name()+" provocandole derrames.\n");
	tell_object(him,"* "+me->query_cap_name()+" te golpea fuertemente provocandote derrames.\n");
}
if (dam >7 && dam <= 17)  
{
	tell_room(environment(me), "%^YELLOW%^La maza de "+me->query_cap_name()+" se incrusta en las costillas de "+him->query_cap_name()+" cortandole la respiracion.%^RESET%^\n",({him,me}));
	tell_object(me,"%^YELLOW%^# Incrustas tu maza en las costillas de "+him->query_cap_name()+" cortandole la respiracion.%^RESET%^\n");
	tell_object(him,"%^YELLOW%^* "+me->query_cap_name()+" te incrusta su maza en las costillas, cortandote la respiracion.%^RESET%^\n");
}
if (dam >17 && dam <= 26)  
{
	tell_room(environment(me), "%^RED%^La maza de "+me->query_cap_name()+" se incrusta en el pecho de "+him->query_cap_name()+" dejandolo sin resuello.%^RESET%^\n",({him,me}));
	tell_object(me,"%^RED%^# Aplastas el pecho de "+him->query_cap_name()+".%^RESET%^\n");
	tell_object(him,"%^RED%^* "+me->query_cap_name()+" te machaca el pecho dejando una sangrante herida.%^RESET%^\n");
}
if (dam >26 && dam < 50)  
{
	tell_room(environment(me),"%^RED%^BOLD%^La maza de "+me->query_cap_name()+" choca violentamente con "+him->query_cap_name()+" dejandolo seriamente aturdido.%^RESET%^\n",({him,me}));
	tell_object(me,"%^RED%^BOLD%^# Golpeas brutalmente el cuerpo de "+him->query_cap_name()+" provocando serios danyos.%^RESET%^\n");
	tell_object(him,"%^RED%^BOLD%^* Tu oponente te golpea brutalmente produciendote contusiones muy serias.%^RESET%^\n");
}
if (dam >= 50)  
{
	tell_room(environment(me),"%^WHITE%^BOLD%^La maza de "+me->query_cap_name()+" destripa BRUTALMENTE partiendo huesos a "+him->query_cap_name()+".%^RESET%^\n",({him,me}));
	tell_object(me,"%^WHITE%^BOLD%^# Tu maza brilla al desgarrar huesos, musculos y nervios de "+him->query_cap_name()+".%^RESET%^\n");
	tell_object(him,"%^WHITE%^BOLD%^* La maza te golpea dolorosamente en tu debil cuerpo, oyes varios huesos romperse y ceder ante tan destructivo golpe.%^RESET%^\n");
}
}
