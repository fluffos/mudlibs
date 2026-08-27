// Viajero. Gestur 

inherit "/obj/monster";
#define TIEMPO 100

void setup()
{
   object objeto;
   set_al(-40);
   set_gender(random(2)+1);
   if (query_gender()==1)
   {
      set_name("viajero");
      set_short("viajero cansado");
      set_main_plural("viajeros cansados");
      add_alias("cansado");
      add_plural("cansados");
      add_plural("viajeros");
      set_long("Es un viajero con aspecto de estar cansado. Tal vez este "
               "realizando la ruta Anduar-Dendara a pie.\n");
   }
   else
   {
      set_name("viajera");
      set_short("viajera cansada");
      set_main_plural("viajeras cansadas");
      add_alias("cansada");
      add_plural("cansadas");
      add_plural("viajeras");
      set_long("Es una viajera con aspecto de estar cansada. Tal vez este "
               "realizando la ruta Anduar-Dendara a pie.\n");
   }
   add_alias("humano");
   add_plural("humanos");
   set_race_ob("/std/races/human");
   set_wimpy(25);
   set_random_stats(10, 14);
   set_cha(10+random(4));
   set_level(2+random(5));
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Que duro es esto de ir de Anduar a Dendara a pie.",
            1, ":resopla de cansancio.",
       }));
       
   objeto=new("/baseobs/weapons/quarterstaff");
   objeto->set_name("baston");
   objeto->add_alias("baston");
   objeto->set_short("baston para andar");
   objeto->set_main_plural("bastones para andar");
   objeto->add_plural("bastones");
   objeto->set_long("Es un baston usado por las personas con dificultades "
                    "para andar o simplemente para cansarse menos. Por "
                    "su forma puede ser utilizado como arma.\n");
   objeto->set_genero(0);
   objeto->move(this_object());
   objeto=new("/baseobs/armours/cape");
   objeto->move(this_object());
   this_object()->init_equip();
   add_move_zone("carretera");
}/*setup*/
