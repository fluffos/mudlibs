int hunt(string str, object me)
{
   int bonus, i, weap_type, damage;
   string weap_name;
   object target;
   object* weap;
   object* list;
   me=this_player();
   if(me->query_alignment()>9000)
   {
      notify_fail("Yvendur no concede este poder a gente tan malevola .\n");
      return 0;
   }
   if(me->query_timed_property("hunt_lockout"))
   {
     notify_fail("Debes tomarte mas tiempo para estudiar a tu oponente "
         "antes de calcular tu maniobra para poder ejecutarla "
         "con exito.\n");
      return 0;
   }
   if(me->query_gp()<5)
   {
      notify_fail("Estas bastante fatigado ahora.  "
         "Intenta recuperarte un poco antes de intentar cazar algo.\n");
      return 0;
   }
   weap=me->query_weapons_wielded();
   if(!sizeof(weap))
   {
     notify_fail("Si este objetivo es mas debil que tu puedes usar tus manos "
         "para matarlo, probablemente no necesitas usar esta fuerza "
         "contra el.  Sera mejor que lo reconsideres.\n");
      return 0;
   }
   list=find_match(str,environment(me));
   if(!sizeof(list))
   {
      notify_fail("Solo puedes cazar a alguien que este presente.\n");
      return 0;
   }
   target=list[0];
   if(target->query_dead())
   {
      notify_fail("Tu crees en fantasmas?  bien, incluso si existen, "
        "tu talento podria ser mejorado si cazaras a alguien "
         "con vida.\n");
      return 0;
   }
   if(target==me)
   {
     notify_fail("Wooooooa ! Estas loco ? Cazandote a ti mismo ?\n");
      return 0;
   }
   if(me->query_hide_shadow())
      bonus=(me->query_level())/(sizeof(weap));
   else
      bonus=((me->query_level())/(sizeof(weap))/2);
   if(target->query_alignment()>0)
      bonus*=2;
   for(i=0;i<sizeof(weap);i++)
   {
      weap_name=weap[i]->query_name();
      weap_type=weap[i]->query_attack_type();
      switch(weap_type)
      {
         case 1:
            write("Cortas viciosamente en trozitos a "+target->query_cap_name()+
               " con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te corta viciosamente "
               "con su "+weap_name+".\n");
            tell_room(environment(me),
               me->query_cap_name()+" corta viciosamente a "+
               target->query_cap_name()+" con su "+weap_name+".\n",
               ({me,target}));
            break;
         case 2:
            write("Aporreas brutalmente a "+target->query_cap_name()+
               " con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te aporrea brutalmente "
               "con su  "+weap_name+".\n");
            tell_room(environment(me),
               me->query_cap_name()+" aporrea brutalmente a "+
               target->query_cap_name()+" con su "+weap_name+".\n",
               ({me,target}));
            break;
         case 3:
            write("Empalas cruelmente a "+target->query_cap_name()+
               " con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te empala cruelmente "
               "con su "+weap_name+".\n");
            tell_room(environment(me),
               me->query_cap_name()+" empala cruelmente a "+
               target->query_cap_name()+" con su "+weap_name+".\n",
               ({me,target}));
            break;
         default:
            write("Atraviesas a "+target->query_cap_name()+" un pulmon.\n");
            tell_object(target,me->query_cap_name()+" te atraviesa "
               "un pulmon con su "+weap_name+".\n");
            tell_room(environment(me),
               me->query_cap_name()+" atraviesa a "+target->query_cap_name()+
               " un pulmon con su "+weap_name+".\n",
               me,target);
            break;
      }
      me->adjust_tmp_tohit_bon(bonus*3);
      me->adjust_tmp_damage_bon(bonus);
      weap[i]->weapon_attack(target,me);
      me->adjust_tmp_damage_bon(-bonus);
      me->adjust_tmp_tohit_bon(-bonus*3);
   }
   target->attack_by(me);
   me->adjust_gp(-5);
   me->add_timed_property("hunt_lockout",1,7);
   return 1;
}
string help(string str)
{
   return
      "Cazar:\n\n"
      "Coste en Pg: 5\n"
      "Cuando un ranger esta cazando a una persona, estudia a su oponente "
      "para encontrar sus puntos debiles en su defensa.  El ranger "
      "luego ataca obteniendo una pequenya ventaja.  El ranger puede "
      "conseguir mejor ventaja si el objetivo no sabe incluso que el esta "
      "alli, porque el ranger esta oculto.  "
      "una vez se explota un punto debil, el objetivo normalmente toma "
      "medidas de proteccion que le debilitan.  Esto le da al ranger "
      "un cierto espacio de tiempo para encontrar otro puntodebil a explotar.  "
      "\n\nSintaxis: cazar <objetivo>\n\n";
}
