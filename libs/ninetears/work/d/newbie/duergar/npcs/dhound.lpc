/*  File upgrade by Grimbrand 2-11-96                                   */

inherit "/obj/monster";

void setup() {
   set_level(8);
   set_wimpy(0);
   set_name("hellhound");
   add_alias("hound");
   add_alias("perro");
   add_alias("hell hound");
   add_alias("hell");
   set_main_plural("hellhounds");
   add_plural("hounds");
   add_plural("hell hounds");
   set_short("Hell Hound");
   set_long("   Tienes ante ti un animal polvoriento, de piel roja, " 
            "desnudo de pelaje, y de aspecto canino. En ocasiones,partes "
            "de su piel estallan en llamas,es considerado un enemigo feroz. "
            "Ahora da la sensacion de necesitar volver al infierno del que "
            "proviene, su estancia prolongada en el plano material ha "
            "debilitado sus estranyos poderes."
	    "\n\n");
   set_kill_xp(431);
   set_max_hp(34);
   set_guild("fighter");
   adjust_money(4,"oro");
}


#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
#define MAXDAMAGE 6

mapping valid_attack() {

int two, three, four, five;

two = random(2);
three=random(3);
four=random(4);
five=random(5);

  return ([
   "punch"   :({ AN+" "+({"muerde a ", "aranya a ",})[two]+" "+DN+" en "+
              ({"el brazo","la mano","la pierna","el rostro",})[four]+".\n",
              "Golpeas a "+DN+".\n", AN+" "+({"te muerde", "te aranya",})[two]+
              " en "+({"el brazo","la mano","la pierna","el rostro",})[four]+".\n"}),

   "kick"     :({ AN+" "+({"muerde a ", "aranya a ",})[two]+" "+DN+" en "+
              ({"el brazo","la mano","la pierna","el rostro",})[four]+".\n",
              "Golpeas a "+DN+".\n", AN+" "+({"te muerde", "te aranya",})[two]+
              " en "+({"el brazo","la mano","la pierna","el rostro",})[four]+".\n"}),

   "knee"     :({ AN+" "+({"muerde a ", "aranya a ",})[two]+" "+DN+" en "+
              ({"el brazo","la mano","la pierna","el rostro",})[four]+".\n",
              "Golpeas a "+DN+".\n", AN+" "+({"te muerde", "te aranya",})[two]+
              " en "+({"el brazo","la mano","la pierna","el rostro",})[four]+".\n"}),

   "headbutt" :({ AN+" "+({"muerde a ", "aranya a ",})[two]+" "+DN+" en "+
              ({"el brazo","la mano","la pierna","el rostro",})[four]+".\n",
              "Golpeas a "+DN+".\n", AN+" "+({"te muerde", "te aranya",})[two]+
              " en "+({"el brazo","la mano","la pierna","el rostro",})[four]+".\n"}),
]);
}

