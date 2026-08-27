inherit "/std/vaults/vault_room";

void setup ()
{
	::setup(); // IMPRESCINDIBLE AKI
  set_short ("%^BOLD%^WHITE%^Armeria del guild%^RESET%^: El Baul\n\n");
  set_guild_owner(({"paladin"}));
	set_saqueable(1);	// se puede saquear con opts por defecto.

  set_long ("%^BOLD%^WHITE%^Armeria del guild%^RESET%^: El Baul\n\n"+
     "Te encuentras en una habitacion muy asegurada con una puerta de un "+
"material que parece acero. Afortunadamente estaba abierta para ti. Ves un gran "+
"baul en la habitacion que tiene aspecto de ser usado con mucha frecuencia. "+
"Tambien puedes ver un cartel.\n\n");
  add_item("baul","Es un gran cofre de madera tallada ricamente y con refuerzos de metal.");
  set_light (60);

  add_exit ("sur", "/room/paladines/barracks", "corridor");
}

int clean_up()
{
 return 1;
}
