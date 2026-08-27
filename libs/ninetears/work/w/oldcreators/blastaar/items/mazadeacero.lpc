inherit "/obj/weapon";
void setup() {
set_base_weapon("twohanded_mace");
set_name("maza");
set_short("Maza de %^BOLD%^Acero%^RESET%^");
set_main_plural("Mazas de %^BOLD%^Acero%^RESET%^");
add_plural("mazas"); 
set_long("Esta maza increiblemente grande brilla "
"con el fulgor del acero proveniente de las montanyas "
"Salvajes.Este arma ha sido confeccionada para el "
"Senyor del Bosque empirico, comandante de los "
"ejercitos del mal que arrasaron la ciudad humana "
"y primer lugarteniente de las hordas de Blastaar, "
"el Senyor de las Montanyas.\n");
set_enchant(8);
set_weight(6000);
set_twohanded(1);
}
void write_message(string happen,int dam, string str,object me,object him) {
if (dam <= 0)   { 
tell_room(environment(me), "La maza de "+me->query_cap_name()+"  ""te golpea sin hacerte danyo.\n",({him,me}));
tell_object(me,"Tu mazazo no surge el efecto esperado en "  ""+him->query_cap_name()+".\n");
tell_object(him,"El mazazo de "+me->query_cap_name()+""  " falla miserablemente.\n");
}
if (dam >0 && dam < 20)  {
tell_room(environment(me), "%^RED%^La maza  "  " de "+me->query_cap_name()+" golpea a "+him->query_cap_name()+""  "en el pecho dejandolo sin resuello.%^RESET%^\n",({him,me}));
tell_object(me,"%^RED%^Golpeas a  "+me->query_cap_name()+".%^RESET%^\n");
tell_object(him,"%^RED%^"+me->query_cap_name()+" te machaca el pecho " "seriamente.%^RESET%^\n");
}
if (dam >20 && dam < 50)  {
tell_room(environment(me),"%^RED%^BOLD%^ La maza de "	  ""+me->query_cap_name()+" choca violentamente "	" a "+him->query_cap_name()+" dejandolo seriamente aturdido.%^RESET%^\n",({me,him}));
tell_object(me,"%^RED%^BOLD%^Golpeas brutalmente el cuerpo "  "de "+him->query_cap_name()+" danyandolo seriamente.%^RESET%^");
tell_object(him,"%^RED%^BOLD%^Tu oponente te golpea brutalmente "  "produciendote contusiones muy serias.%^RESET%^\n");
}
if (dam >= 50)  {
tell_room(environment(me),"%^WHITE%^BOLD%^La maza de "	  " "+me->query_cap_name()+" golpea BRUTALMENTE "  "partiendo huesos a "+him->query_cap_name()+".%^RESET%^\n",({me,him}));
tell_object(me,"%^WHITE%^BOLD%^Tu maza brilla al macerar huesos, musculos y nervios "  "de "+him->query_cap_name()+".%^RESET%^\n");
tell_object(him,"%^WHITE%^BOLD%^La maza te golpea dolorosamente en tu debil cuerpo, "	  "oyes varios huesos romperse y carne " "ceder ante tal golpe destructivo.%^RESET%^\n");
}
return;
}
