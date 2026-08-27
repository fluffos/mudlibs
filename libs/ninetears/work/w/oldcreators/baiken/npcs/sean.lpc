// Paris. Abr'99
inherit "/obj/monster";
#include "path.h"
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
      else {
        TO->sub_melones(TP);
        tell_room(ENV(TO),"Sean deja de defender a "+TP->query_cap_name()+".\n",TP);
        tell_object(TP,"Sean deja de defenderte.\n");
      }
    }
    else {
      do_command("'huyes de aqui, Cobarde !!");
    }
    return ::event_exit(ob,mensaje,donde);
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
     else {
      TO->do_command("'Buenos dias Guerrero");
        TO->add_melones(TP);
        tell_room(ENV(TO),"Sean defiende a "+TP->query_cap_name()+".\n",TP);
        tell_object(TP,"Sean te defiende.\n");
     }
    }
    else 
    {
      do_command("'Hoy sufriras cerdo !!");
      TO->attack_by(ob);
    }
  return ::event_enter(ob,mensaje,donde);
}

void setup()
{
   set_name("sean");
   set_short("Sean McGregor");
   set_gender(1);
   set_main_plural("personajes que se parecen bastante a Sean McGregor");
   set_race_ob("/std/races/human");
   
   add_alias("humano");
   set_race("Humano");
   add_plural("humanos");
   
   set_guild_ob("/std/guilds/warriors/fighter");
   
   set_str(29); /* Soy mas Power que naide ;) */
   set_cha(20);
   set_con(18);
   set_dex(18);
   set_int(15);
   set_wis(18);
   
   set_max_hp(1000);
   set_max_gp(300);
   set_gp(query_max_gp());
   TO->set_hp(TO->query_max_hp());
   
   set_long("Delante de ti tienes un impresionante Humano. Viste una simple "
            "armadura de cuero, pues tal es la fuerza de su brazo y tal su "
            "destreza en el manejo de la espada, que la confianza en sus "
            "posibilidades es lo mejor que tiene. Ademas, su espada tiene "
            "tal nombre en los reinos que es temida por todos sus contrincantes. "
            "El arma es la mayor expresion de su condicion de herrero y tan solo "
            "obedece el mandato de su duenyo, por lo que al morir este ella "
            "muere tambien cuando otro guerrero la empunya.\n");
   
   load_chat(5, ({1, ":te mira con curioso interes.",
                  1, "'Si tienes algun problema con tu personal, prueba a "
                     "poner reconvertir y rehacer.",
                  1, "'Si no sabes lo que hay que hacer, arrodillate.", 
                  1, "'Pedir por pedir no tendra su recompensa, tambien "
                     "hace falta sacrificio."}));  
                     
   load_a_chat(5, ({1, "'No eres nadie comparado conmigo, recuerdalo al morir !",
                     1, "'Creias que seria facil venir y derrotarme, verdad ?",
                     1, ":hace unas magnificas fintas",}));
   
   add_loved("guild",({"Guerrero","Sin Gremio"}));
   
   add_clone("/d/oficios/guerreros/nuevos/items/personal",1);
   new("/baseobs/weapons/bastard_sword")->move(this_object());
   new("/baseobs/armours/studded")->move(this_object());    
   new("/baseobs/armours/helm")->move(this_object());
   
   set_level(47);
   add_timed_property("sense-life",1,10000000000);
   add_property("espada_guerrero",({"Mordiente",1,8,6,3,1}));
   add_property("nodisarm",1);
   this_object()->init_equip();
}

int unarmed_attack(object target,object me)
{
   object *lista;
   int i;
   lista=(object *)me->query_attacker_list();
   i=random(sizeof(lista));
   monster::unarmed_attack(lista[i],me);
   monster::unarmed_attack(lista[i],me);
}
int query_res(){ return 68; }
int query_total_ac(){ return -17; }
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
