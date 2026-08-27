inherit "/obj/monster";

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
#define NOMBRE "Methil"

void setup() {
  set_name("methil");
  add_alias("illita");
  set_main_plural(NOMBRE);
  set_short("%^BLACK%^BOLD%^"+NOMBRE+"%^RESET%^, el Desollador Mental");
  set_long(NOMBRE+"\n\nEs el desollador mental de Xerxes.\n\n");
  set_race("monster");
  set_join_fight_mess("El combate da comienzo cuando "+NOMBRE+" se materializa "
                      "ante ti, y empieza a atacarte!\n");
  set_level(99);
  set_thac0(-90);
  set_alineamiento(1,-1);
  set_max_hp(9000);
  set_max_gp(9000);
  set_hp(9000);
  set_gp(9000);
  set_random_stats(90, 99);
  set_wimpy(0);
  adjust_tmp_damage_bon(30+random(10));
  this_object()->init_command("proteger xerxes");
  this_object()->init_command("seguir xerxes");
}

void init() {
  ::init();
  add_action("do_tell","tell");
  add_action("do_tell","t");
  add_action("do_ataca","ataca");
  call_out("first_approach",0,this_player());
}

int first_approach(object ob) {
  write("\nSientes la tenebrosa aura de %^BLACK%^BOLD%^"+NOMBRE+"%^RESET%^ "
        "cerniendose sobre ti.\n\n");
}

int unarmed_attack(object target,object me) {
  object *atacante;
  atacante = (object*)me->query_attacker_list();
  monster::unarmed_attack(atacante[random(sizeof(atacante))],me);
  monster::unarmed_attack(atacante[random(sizeof(atacante))],me);
  monster::unarmed_attack(atacante[random(sizeof(atacante))],me);
  monster::unarmed_attack(atacante[random(sizeof(atacante))],me);
  monster::unarmed_attack(atacante[random(sizeof(atacante))],me);
}

mixed valid_attack() {
 return([
   "knee"  :({AN+" golpea a "+DN+" con sus gelatinosos tentaculos.\n",
            "Golpeas a "+DN+" con tus tentaculos.\n",
            AN+" te golpea con sus tentaculos.\n"}),
   "punch" :({AN+" aplasta a "+DN+" con su cuerpo.\n",
            "Aplastas a "+DN+".\n",
            AN+" te aplasta con su pegajoso cuerpo.\n"}),
   "kick"  :({AN+" destroza a "+DN+" con una poderosa onda mental.\n",
            "Destrozas a "+DN+" con tu onda mental.\n",
            AN+" destroza tu mente con su poderosa onda mental!\n"})  ]);
}

int do_tell(string arg, object ob, int silent) {
  string nombres, resto;
  /*
  if (!ob) {
    if (sscanf(arg,"%s %s",nombres,resto)!=2) {
      ::do_tell(arg, ob, silent);
    }
  } else {
    resto = arg;
  }
  if (!ob) {
    nombres = lower_case(nombres);
    nombres = (string)this_object()->expand_nickNOMBRE(nombres);
    ob = find_player(nombres);
    if (!ob)
      ob = find_living(nombres);
    if (!ob)
      ::do_tell(arg, ob, silent);
  }
  if (ob == this_player()) {
    write("Methil mira con disgusto a "+ob->query_cap_name()+".\n");
    return 0;
  } */
  sscanf(arg,"%s %s",nombres,resto);
  
  do_whisper("xerxes "+TP->query_cap_name()+" ha comunicado '"+resto+"' a "+
           (string)this_object()->expand_nickname(nombres)+".\n");
  ::do_tell(arg, ob, silent);
}
int do_ataca(object quien)
{
  this_object()->attack_ob(quien);
  return 1;
}
