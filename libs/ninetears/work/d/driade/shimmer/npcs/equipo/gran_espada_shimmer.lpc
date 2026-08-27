/* Gran Espada de Shimmer By Shimmer */

inherit "/obj/weapon";

void setup() {
	set_base_weapon("scimitar");
	set_name("Gran Espada de %^BOLD%^YELLOW%^Shimmer%^RESET%^");
	set_short("Gran Espada de %^BOLD%^YELLOW%^Shimmer%^RESET%^");
	add_alias("espada");
        add_alias("gran");
	set_long("Es una espada grandiosa y pesada, su hoja es larga y ancha y esta totalmente curvada hacia fuera, "
                 "es el arma usada por los barbaros orcos de alto rango.\n");
	set_main_plural("Grandes Espadas de %^BOLD%^YELLOW%^Shimmer%^RESET%^");
	add_plural("espadas");
        add_plural("grandes"); 
        set_weight(500);
        set_twohanded(0);
}
int query_damage_roll()
{
	return (::query_damage_roll() + random(20) + 20);
}