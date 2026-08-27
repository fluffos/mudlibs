// Bibliotecario by Valar 27/9/02

inherit /std/monster


void setup() {
      set_name("Mini-Levi, el bibliotecario");
      set_short("mini-levi");
      set_al(60);
      set_main_plural("bibliotecarios");
      add_alias("bibliotecario");
      set_race("elf");
      set_level(45+random(6));
      set_wimpy(0);
	set_max_hp(100);
	set_hp(100);
	set_max_gp(500);
	set_gp(500);
      set_random_stats(18, 19);
      
      set_long("Te encuentras ante el viejo y sabio bilbiotecario de los dioses. "
      " Cuando acepto este cargo no penso que seria de por vida. Data de una antigua "
      " estirpe de elfos sabios y eruditos que hace siglos abandonaron el mundo terrenal"
      " para prestar sus conocimientos a los dioses.\n");
      
      load_chat(5,
         ({
               1, "Deseais algo senyor?",
               1, "En que puedo servirles?",
               1, "Esta biblioteca recoge las mas antiguas obras de Ninetears",
               1, "Buscais algun libro en especial?",
               1, "Llevad cuidado no tropeceis con el suelo",
               1, "Los libros mas antiguos estan a vuestra disposicion",
          }));
      
	set_kill_xp(10);
	set_guild("mage");
	this_object()->init_equip();
}
