// Bibliotecario by Valar 27/9/02

inherit "/obj/monster";


void setup() {
      set_name("Mini-Levi");
      set_short("Mini-levi");
      add_alias("minilevi");
      add_alias("Bibliotecario");
      add_alias("mini-levi");
      add_alias("bibliotecario");
      set_race("halfling");
      set_language("common");
      set_level(45+random(6));
      set_wimpy(0);
	set_max_hp(1000000);
	set_hp(1000000);
	set_max_gp(500);
	set_gp(500);
      set_random_stats(18, 19);
      
      set_long("Te encuentras ante el viejo y sabio bilbiotecario de los dioses. "
      " Cuando acepto este cargo no penso que seria de por vida. Data de una antigua "
      " estirpe de grandes sabios y eruditos que hace siglos abandonaron el mundo terrenal"
      " para prestar sus conocimientos a los dioses. El tio esta tan aburrido que se pasa"
      " la vida en idle.\n");
      
      add_clone("/w/vilat/espada_hielo_negro",1);
      add_clone("/baseobs/weapons/daga",1);
      
      load_chat(5,
         ({
               1, "'Deseais algo senyor?",
               1, "'En que puedo servirles?",
               1, "'Esta biblioteca recoge las mas antiguas obras de Ninetears",
               1, "'Buscais algun libro en especial?",
               1, "'Llevad cuidado no tropeceis con el suelo",
               1, "'Los libros mas antiguos estan a vuestra disposicion",
               1, "'Cuenta la leyenda que un dia que leviathan se rascaba el culo se le cayo un pelo al estaque de la creacion y naci yo",
          }));
      
	set_kill_xp(10);
	set_guild("mage");
	this_object()->init_equip();
}
