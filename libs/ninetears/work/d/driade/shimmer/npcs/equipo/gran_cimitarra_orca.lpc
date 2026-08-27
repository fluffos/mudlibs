/* Gran Cimitarra Orca By Shimmer */

inherit "/obj/weapon";

void setup() {
	set_base_weapon("scimitar");
	set_name("Gran Cimitarra %^BOLD%^GREEN%^Orca%^RESET%^");
	set_short("Gran Cimitarra %^BOLD%^GREEN%^Orca%^RESET%^");
	add_alias("cimitarra");
        add_alias("gran");
        add_adjective("orca");
	set_long("Es una espada grandiosa y pesada, su hoja es larga y ancha y esta totalmente curvada hacia fuera, "
                 "es el arma usada por los barbaros orcos de alto rango.\n");
	set_main_plural("Grandes Cimitarras %^BOLD%^GREEN%^Orcas%^RESET%^");
	add_plural("cimitaras");
        add_plural("grandes"); 
        set_weight(500);
        set_twohanded(1);
}
int query_damage_roll()
{
	return (::query_damage_roll() + random(5) + 3);
}