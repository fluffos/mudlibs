// The infamous BANDIT!
// Variacion sobre el de Tzarnis en la Ciudad de la Luz

inherit "/obj/monster";
int i;
string color;

void setup() {
      i=random(4);
      switch(i)
        { case 0: color="marron"; break;
          case 1: color="verdoso"; break;
          case 2: color="negruzco"; break;
          case 3: color="azul cielo"; break;
        }
      set_name("a_bandido");
      set_al(0);
      set_guild_ob("/std/guilds/rogues/thief");
      set_guild("rogues/thief");
      set_short("Bandido");
      set_race("human");
      set_level(30+random(3));
      set_wimpy(0);
      add_alias("bandido");
      set_main_plural("Bandidos");
      add_plural("bandidos");
      set_random_stats(15, 19);
      set_dex(25);
      set_long("Es un humano que merodea la ciudad de Onoran, como una plaga que son "
               "esperan un descuido de algun viajero confiado. Viste un turbante "
               "en la cabeza y capa de piel gigantesca, sus ojos son de color "+color+". "
               "Debe medir entre un metro setenta y dos metros. No te fies de el.\n");
      adjust_money(10+random(20),"plata");
      load_chat(40,
         ({
               1, "'A ver si pillo un pardillo descuidado.",
               1, ":se mueve rapidamente a tu alrededor.",
               1, ":se limpia las unyas con la punta de su daga.",
               1, ":te muestra el carnet de 'Chorizo Titulado'.",
               1, "'Dame aaaaargoo!!!.",
          }));
      load_a_chat(90,
         ({
               1, "'te voy a dejar las costillas molidas!!",
               1, "'ladrones a mi! me ataca "+TP->query_cap_name()+ "!!.",
               1, "'muereeeeeeeee!!",
               1, "'tios como tu me los desayuno yo todos los dias !!",
               1, "'no sabes pegar mas fuerte? ven ke te muela los huesos!!",
          }));

      if(i==2)
       {  clone_object("/baseobs/weapons/short_sword")->move(TO);
          clone_object("/baseobs/weapons/short_sword")->move(TO);
          set_dex(22);
       }
      else
      clone_object("/baseobs/weapons/dagger")->move(TO);
      clone_object("/baseobs/armours/leather")->move(TO);
      this_object()->init_equip();
      set_join_fight_mess("un bandido entra en el combate.\n");

} /* setup() */

void init()
{
  ::init();
  TO->add_known_command("apunyalar");
  TO->add_known_command("robar");
  TO->add_known_command("esconderse");

}

void event_enter(object ob, string msg, object don)
{
TO->do_command("esconderse");	
if (random(30)==1)
	TO->do_command("apunyalar "+ob->query_cap_name());
else
   if(i>1) TO->do_command("robar monedas a "+ob->query_cap_name());
}

void heart_beat()
{
	TO->do_command("esconderse");	
::heart_beat();
}
