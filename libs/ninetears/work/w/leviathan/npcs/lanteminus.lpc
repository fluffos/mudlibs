inherit "/obj/monster";
void setup()
{
set_name("lanteminus");
add_alias("atlante");
add_plural("Lanteminus");
set_short("Lanteminus");
set_long("Es un atlante de enorme estatura, de caracter afable en extremo fue obligado a tomar las "
         "armas al servicio de su emperador en contra de su voluntad. Su verdadera pasion es la poesia, "
         "arte que domina con escasa pericia componiendo verdaderas aberraciones poeticas.\n");
set_race("atlante");
set_guild("warrior");
set_random_stats(25,30);
set_dex(30);
set_str(50);
set_level(25+random(5));
set_gender(1);
set_al(-100);
set_aggressive(0);
set_wimpy(0);
set_max_hp(2000);
set_hp(2000);
adjust_money(2+random(3),"platinum");
add_clone("/baseobs/weapon/bastardsword",2);
load_chat (100,
  ({
  1,"'Tu mirada es triste, tus ojos hermosos, tu boca parece coral y tu cara.... mmmm tu cara... PARECE UNA ANGUILA!\n",
  2,"Lanteminus se inspira con la brisa marina.\n",
  }));
  set_heart_beat(2);
}
 
void heart_beat()
{
      object *obs = TO->query_attacker_list();
      ::heart_beat();
    
      if(sizeof(obs)>0)
      {
        if(TO->query_timed_property("flipped")<2 && !random(4))
          "/d/gremios/comandos/go_berserk"->go_berserk("mec",TO);
      }
}
