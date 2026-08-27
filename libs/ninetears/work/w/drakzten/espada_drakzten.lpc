inherit "/obj/weapon";

void setup(){
set_base_weapon("espada_larga");
set_name("espada drakzten");
set_short("%^BOLD%^Espada %^BOLD%^%^GREEN%^Dra%^RESET%^%^GREEN%^kz%^BOLD%^%^GREEN%^ten%^RESET%^");
set_long("Es una bellizima espada larga con filo dorado y mango de oro, es la espada personal del gran Drakzten, es la espada con la cual vencio en batalla al gran lagarto Laren, gracias a el ahora el bosque tralak esta a savo de esa gran amenaza que destruia la naturaleza del bosque.");
set_main_plural("%^BOLD%^Espadas %^BOLD%^%^GREEN%^Dra%^RESET%^%^GREEN%^kz%^BOLD%^%^GREEN%^ten%^RESET%^");
add_plural("espadas");
add_alias("espada");
add_alias("drakzten");
set_enchant(800);
add_timed_property("electrical",100,999999999999999);
reset_drop();
}
void init() {
::init();
add_action("relampago", "llamar");
}
int relampago(string str) {
object objetivo;
if (TO->query_timed_property("cargando")) return notify_fail("La naturaleza aun no puede responder tu llamado.\n");
if (!str) return notify_fail("Uso: llamar <objetivo>\n");
objetivo=find_living( lower_case(str) );
if (!objetivo) return notify_fail(CAP(str)+" no esta aqui.\n");
if (ENV(objetivo)!=ENV(TP)) return notify_fail(objetivo->query_cap_name()+" no esta al alcanze de la naturaleza.\n");
tell_object(TP,"Llamas a la naturaleza desde la "+TO->query_short()+" y aparece un relampago de naturaleza que va directamente hacia "+objetivo->query_cap_name()+".\n");
tell_object(objetivo,TP->query_cap_name()+" le habla a su "+TO->query_short()+" y aparece un relampago que impacta fuertemente contra tu cuerpo cuasandote muy graves heridas.\n");
tell_room(ENV(TP),objetivo->query_cap_name()+" queda profundamente herido cuando le impacta un relampago que provenia de la "+TO->query_short()+" de "+TP->query_short()+".\n",({objetivo,TP}));
objetivo->adjust_hp(-random(400),TP);
TP->attack_by(objetivo);
TO->add_timed_property("cargando",1,00);
return 1;
}
