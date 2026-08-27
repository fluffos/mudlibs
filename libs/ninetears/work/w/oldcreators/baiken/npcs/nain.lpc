// Paris. Abr'99 & Fradess Y2K+1
inherit "/obj/monster";
#include "../path.h"
object wep;

void setup()
{
   set_name("nain");
   set_short("Nain El Maestro de Arckium Krash");
   set_gender(1);
   set_main_plural("Varios enanos parecidos a Nain");
   set_race_ob("/std/races/dwarf");
   
   add_alias("enano");
   set_race("Enano");
   add_plural("enanos");
   
   set_guild_ob("/std/guilds/warriors/khazad");
   
   set_str(50);
   set_cha(20);
   set_con(25);
   set_dex(18);
   set_int(15);
   set_wis(18);
   
   set_max_hp(2000);
   set_max_gp(700);
   set_gp(query_max_gp());
   TO->set_hp(TO->query_max_hp());
   
   set_long("Nain es un robusto enano de una altura inusitada para los de "
           "su raza. Posee largas y trenzadas barbas pelirrojas que adorna "
           "con diversas joyas. Su pelo, rojizo tambien, le cae por detras "
           "del casco y por la frente en salvajes rios de mechones. Tiene "
           "ojos grandes de color avellana, inquisidores, que parecen "
           "poder mirar directamente en tu alma, aunque en realidad lo que "
           "esta haciendo es calcular el precio de tu armadura. Su equipo "
           "esta forjado por el mismo y esta hecho del metal mas preciado que "
           "se pueda encontrar en los reinos: El Mithril. Se dice que ademas "
           "esta encantado con runas de poder que el mismo ha inscrito. Ahora "
           "se dedica a ensenyar a sus tocayos el arte del combate con gran "
           "dedicacion, pues en su mente esta el dia en que arrasen Golthur "
           "y Bendorf.\n");
   
  
  add_loved("guild",({"Khazad","Sin Gremio"}));
   
  add_clone(ITEMS"hacha_mith_tru",1);
  add_clone(ITEMS"mallas_mith",1);
  add_clone(ITEMS"yelmo_mith",1);
  add_clone(ITEMS"botas_mith",1);
  add_clone(ITEMS"anillo_mith",1);
  add_clone(ITEMS"gaunt_mith",1);
  add_clone(ITEMS"pant_mith",1);
   
   set_level(69);
   do_command("guild on");
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

void do_death(object ob)
{
    wep->dest_me();
    wep=clone_object(ITEMS"hacha_mith");
    wep->move(ENV(TO));
    wep->set_identificador(ob->query_cap_name());
    return ::do_death(ob);
}

void attack_by(object ob)
{
  if(!random(5)) 
    TO->do_command("guild @[%^BOLD%^YELLOW%^Mithril's Master%^RESET%^]: "+ob->query_short()+" intenta "
                   "asaltar el %^ORANGE%^Arckium Krash:%^BOLD%^%^WHITE%^, a Romper Cabezas%^RESET%^ !");
  ::attack_by(ob);
}  

void heart_beat()
{
  object *obs = TO->query_attacker_list();
    
  if(sizeof(obs)>0)
  {
    if(!TO->query_timed_property("flipped") && !random(3))
      "/std/commands/noquear"->do_command(obs[random(sizeof(obs))],TO);
    if(TO->query_timed_property("flipped")<2 && !random(4))
      "/std/commands/aguantar"->do_command("mec",TO);
    if(!random(4))
      "/std/commands/desarmar"->disarm(obs[random(sizeof(obs))]->query_name(),TO);
  }
  ::heart_beat();
}
int query_body_ac(){ return 171; }
int query_res(){ return 63; }
int query_tmp_damage_bon(){ return 3;}
int query_tmp_tohit_bon(){ return 30;}
    
mixed event_enter(object ob, string mensaje, object donde)
{
  if(ob->query_property("bando")>1)
    call_out("attack_by",0,ob);
  return ::event_enter(ob,mensaje,donde);
}
