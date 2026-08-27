//Paris. Feb'00
//Anyadido el load_chat para dar pistas sobre la quest del codazo.
//Kilidor. Ene'02
inherit "/obj/monster";
#include "/d/oficios/guerreros/normal/npcs/path.h"
#define HELP "/d/oficios/guerreros/normal/rooms/room1"
int done = 0;

int reset_done(){ return done = 0; }
int set_done(){ return done = 1; }
int query_donde(){ return done; }

void setup()
{
  set_name("arturo");
  set_short("Arturo");
  set_gender(1);
  set_main_plural("Personas parecidas a Arturo");
  set_race("Humano");
  set_race_ob("/std/races/human");
  set_guild_ob("/std/guilds/warriors/fighter");
  set_str(35);
  set_con(25);
  set_dex(25);
  set_int(25);
  set_wis(25);
  set_cha(25);
  set_long("Es el Rey Arturo, el mejor de los caballeros de este gremio. "
     "Tiene unos musculos enormes, casi los mas grandes que has "
     "conocido. De eso deduces que es bastante fuerte, mejor no "
     "meterse con el. Ayudara a cualquier guerrero que pida 'socorro' a "
     "defenderlo dentro del gremio poniendose rapidamente en berserk al "
     "tiempo que lo protege.\n\n\n"
     "\tTengo nueva funcion: <gracias>\n");
  load_chat(20,
  ({
  	 1,"'El maestro Hinomura ha abierto su dojo para ensenyar sus conocimientos "
  	   "a aquellos que consigan ganarlo en combate.",
  }));
  add_clone("/baseobs/armours/great_helm",1);
  add_clone("/d/oficios/guerreros/normal/weapons/espada_plata",1);
  add_clone("/baseobs/armours/platemail",1);
  //Ahora ya no es necesario add_clone("/d/oficios/guerreros/normal/armours/coraza_plata",1);
  add_clone("/d/oficios/guerreros/nuevos/items/personal",1);
  add_clone("/baseobs/armours/rings",2);
  add_clone("/baseobs/armours/amulet",1);
  add_clone("/baseobs/armours/pendant",1);
  add_clone("/baseobs/armours/shoes",1);
  add_clone("/baseobs/armours/belt",1);
  add_property("espada_guerrero",({"%^BOLD%^Excalibur%^RESET%^",1,10,7,3,1}));
  add_property("nodisarm",1);
  add_property("no_noquear",1);
  init_equip();
  TO->do_command("guild on");
  set_max_hp(400);
  set_level(69);
  set_heart_beat(2);
}

void init()
{
  add_action("do_gracias","gracias");
  ::init(); 
}

void heart_beat()
{
      object *obs = TO->query_attacker_list();
      ::heart_beat();
    
      if(sizeof(obs)>0)
      {
        if(!TO->query_timed_property("flipped") && !random(3))
          "/std/commands/gcritico"->do_command(obs[random(sizeof(obs))],TO);
        if(TO->query_timed_property("flipped")<2 && !random(4))
          "/std/commands/go_berserk"->go_berserk("mec",TO);
        if(!random(4))
          "/std/commands/desarmar"->disarm(obs[random(sizeof(obs))]->query_name(),TO);
      }
}

void do_gracias()
{
  if(TP->query_guild_name()!="Guerrero")
      {
       notify_fail("No eres de este Gremio y sufriras su Ira.\n");
       return 0;
      }
  if(TP->query_race_name()=="Orco"||TP->query_race_name()=="Goblin")
      {
      notify_fail("No eres de este Gremio y sufriras su Ira.\n");
      return 0;
      }
       tell_room(ETO,TO->query_short()+" deja de defender a "+TP->query_cap_name()+".\n",TP);
      TO->sub_melones(TP);
       return 1;
}
void attack_by(object mec)
{
  if(!done)
  {
    
    if(!HELP)
     load_object(HELP);
    HELP->activar(TO);
    done = 1;
  }
  HELP->anyadir(mec);
  if(!random(6))
     do_command("guild @[Defendiendo el Gremio]: "+mec->query_cap_name()+" esta entrando a la fuerza!");
  ::attack_by(mec);
}
      
void titulos(int lvl)
{
  switch(lvl)
  {
    case 0..10: do_command("'Hola, joven discipulo!\n");
    break;
    case 11..16: do_command("'Bienvenido seais, mi pequenyo luchador.\n");
    break;
    case 17..21: do_command("'Hola, soldado, encantado de veros.\n");
    break;
    case 22..26: do_command("'Como fueron las aventuras, gran guerrero?.\n");
    break;
    case 27..31: do_command("'A quien habeis descuartizado hoy, senyor?.\n");
    break;
    case 32..35: do_command("'Tres hurras por el gran guerrero!!.\n");
    break;
    case 36..40: do_command("'Que gran honor teneros aqui, espero que vuestra estancia sea agradable!.\n");
    break;
    case 41..45: do_command("'Me alegra que hayais venido. Vuestro lugar en la mesa os espera para debatir nuevas tacticas de combate Senyor!.\n");
    break;
    case 46..50: do_command("'Es honrosa su presencia, disponga de cuanto necesite durante su estancia Gran Senyor!.\n");
    break;
    default: do_command("'Cuidado, apartaos, que viene, no os interpongais en su camino!. Es el, el Guerrero mas respetado y temido de los Reinos.\n");
  }
}

mixed event_enter(object ob, string mensaje, object donde)
{
  if(living(ob))
    if(ob->query_guild_ob() == "/std/guilds/warriors/fighter" || ob->query_guild_name()== "No guild.")
    {
      if(ob->query_race_name()=="Orco" || ob->query_race_name()=="Goblin")
      {
        do_command("'fuera de mi gremio Perro !!");
        TO->attack_by(ob);
      }
      else 
      {
          TO->set_melones(ob);
          titulos(ob->query_level());
          tell_room(environment(TO),TO->query_short()+" defiende a "+ob->query_cap_name()+".\n");
      }
    }
    else 
    {
      do_command("'fuera de mi gremio Perro !!");
      TO->attack_by(ob);
    }
  return ::event_enter(ob,mensaje,donde);
}
mixed event_exit(object ob,string mensaje, object donde)
{
  if(living(ob))
    if(ob->query_guild_ob() == "/std/guilds/warriors/fighter" || ob->query_guild_name()== "No guild.")
    {
        if(ob->query_race_name()=="Orco" || ob->query_race_name()=="Goblin")
        {
          do_command("'fuera de mi gremio Perro !!");
          TO->attack_by(ob);
        }
        else 
        {
          this_object()->sub_melones(ob);
          tell_room(environment(TO),TO->query_short()+" deja de defender a "+ob->query_cap_name()+".\n");
        }
    }                                      
    else 
    {
      do_command("'huyes de aqui, Cobarde !!");
    }
  return ::event_exit(ob,mensaje,donde);
}

int query_total_ac(){ return -110;}
int query_res() { return 65; }
