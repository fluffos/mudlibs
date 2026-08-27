// Objeto sagrado de Barthleby
// Tyrael - Sep '01
// Tyrael - Bugs corregidos y adaptado a nuevo set_in_use() Ene '02

/* The example armour.. */

#define GOD_HAND "/obj/handlers/god_handler"

inherit "/obj/armour"; 

void setup()  
  { 
  /* THIS HAS TO BE THE FIRST LINE !!!! */
  set_base_armour("bracers");  /* Will set up most of the armour for you */

  set_name("brazalete de Barthleby");   /* The name is an identifier **/ 
add_alias("brazalete");
  set_short("Brazalete de %^BOLD%^Bar%^BLUE%^thl%^WHITE%^eby%^RESET%^");

  set_main_plural("Brazaletes de %^BOLD%^Bar%^BLUE%^thl%^WHITE%^eby%^RESET%^");
add_plural("brazaletes");
	add_adjective("de barthleby");
  set_long("Esto es el Brazalete Sagrado de Barthleby, que tan solo "
	"posee su Alto Sacerdote.\n");
	set_enchant(1);
	reset_drop(); // no lo podemos dar 
	add_property("nosteal", 1); // no se si aki pinta mucho, por si acaso
} 

/* BUG, cuando el ke la lleva palma, this_player es el asesino y le sale a
el el msg... */
/* Workaround: ponemos propiedad estatica en la hacha con el nombre
	del ke la empunya. */
int set_in_use(int i, object duenyo)
{
	if (i) {
	// en principio aki TP es siempre el duenyo, pero por seguridad...
	// seguimos siendo el sumo?
		if (!GOD_HAND->query_high_priest("barthleby") ||
		GOD_HAND->query_high_priest("barthleby")[0] != duenyo->query_name()) {
			tell_object(duenyo, "El Brazalete se oscurece lentamente al no reconocerte como el Sumo Sacerdote de Barthleby, para finalmente destruirse en mil pedazos.\n");
			notify_fail("");
			duenyo->remove_property("barthleby_sagrado");
			call_out("dest_me", 0, 0);
			return 0; // no se pone el brazalete!
		}
		clone_object("/baseobs/misc/gods/shadows/barthleby_sh")->setup_shadow(duenyo);
		tell_object(duenyo,
		"Notas el poder del Bien fluir a traves del Brazalete.\n");
		/* por si acaso */
		remove_static_property("duenyo");
		add_static_property("duenyo", duenyo);
	}
	else
	{
	// recordatorio: al morir, TP es el killer.
		duenyo->dest_barthleby_shadow();
		if (duenyo->QCN == ((object)(query_static_property("duenyo")))->QCN) {
			tell_object(duenyo,
			"Al quitarte el Brazalete te sientes mas vulnerable.\n");
		}
		remove_static_property("duenyo");
	}
	return ::set_in_use(i);
}
