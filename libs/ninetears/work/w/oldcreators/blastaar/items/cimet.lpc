inherit "/obj/weapon";
void setup()  {
set_base_weapon("scimitar");
set_weight(100);
set_name("Cimitarra %^BOLD%^CYAN%^Eterea%^RESET%^");
set_short("Cimitarra %^BOLD%^CYAN%^Eterea%^RESET%^");
add_alias("cimitarra");
add_alias("eterea");
set_long("Esta arma ha sido personalmente forjada por Blastaar, "
"el Senyor del Mal de la montanya,su poder destructivo es incomparable "
"y de ella emana un aura de maldad sin igual.\n");
add_alias("cimitarra eterea");
add_plural("cimitarras etereas");
add_plural("cimitarras");
add_plural("etereas");
set_main_plural("Cimitarras %^BOLD%^CYAN%^Etereas%^RESET%^");
set_twohanded(0);
set_enchant(1); }
int query_damage_roll()
{
return ::query_damage_roll() + 2;
}
