int hunt(string str, object me)
{
   int bonus, i, j, weap_type, damage;
   string weap_name;
   object target;
   object* weap;
   object* list;
   me=this_player();
/*    if(me->query_alignment()>1000)
   {
      notify_fail("Mielikki grants no powers to those who are evil.\n");
      return 0;
   } */
   if(me->query_timed_property("hunt_lockout"))
   {
     notify_fail("Debes tomarte mas tiempo para estudiar a tu oponente "
         "antes de llevar a cabo una maniobra tan calculada.\n");
     return 0;
   }
   if(me->query_gp()<5)
   {
      notify_fail("Te encuentras demasiado fatigado. Seria mejor "
         "descansar un poco antes de intentar cazar a alguien.\n");
      return 0;
   }
   weap=me->query_weapons_wielded();
   if(!sizeof(weap))
   {
     notify_fail("Si tu enemigo es tan debil que puedes usar tus "
         "propias manos para matarlo, tal vez no sea necesaria semejante "
         "fuerza.\n");
      return 0;
   }
   for (j = 0;j<sizeof(weap);j++) {
     if (weap[j]->query_property("no_hunt")) {
        //tell_object(me, "No podras cazar a nadie si no posees las "
        //"armas apropiadas.\n");
		// cuando se dewelve 0 hay que usar un notify_fail
		notify_fail("No podras cazar a nadie si no posees las armas apropiadas.\n");
        return 0;
     }
   }
	// ESTO NO ME MOLA ASI, USAR LOS DE TODOS LOS COMANDOS
   list=find_match(str,environment(me));
   if(!sizeof(list))
   {
      notify_fail("Tan solo puedes cazar alguien presente.\n");
      return 0;
   }
   target=list[0];
   if(target->query_dead())
   {
      notify_fail("Crees en espiritus? Bien, aun si existieran, "
        "usarias mejor tu talento si cazaras alguna otra cosa.\n");
      return 0;
   }
   if(target->query_hidden())
   {
      notify_fail("Tan solo puedes cazar alguien presente.\n");
      return 0;
   }
   if(target==me)
   {
     notify_fail("No seria bueno para tu salud.\n");
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
      //weap_name=weap[i]->query_name();
      weap_name=weap[i]->query_short();
      weap_type=weap[i]->query_attack_type();
      switch(weap_type)
      {
         case 1:
            write("Cortas viciosamente a "+target->query_cap_name()+
               " con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te corta viciosamente "
               "con su "+weap_name+".\n");
            tell_room(environment(me),
               me->query_cap_name()+" corta viciosamente a "+
               target->query_cap_name()+" con su "+weap_name+".\n",
               ({me,target}));
            break;
         case 2:
            write("Machacas brutalmente a "+target->query_cap_name()+
               " con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te machaca brutalmente "
               "con su "+weap_name+".\n");
            tell_room(environment(me),
               me->query_cap_name()+" machaca brutalmente a "+
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
            write("Atacas a "+target->query_cap_name()+" con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te ataca con su "+weap_name+".\n");
            tell_room(environment(me),
               me->query_cap_name()+" ataca a "+target->query_cap_name()+
               " con su "+weap_name+".\n",
               me,target);
            break;
      }
      me->adjust_tmp_tohit_bon(bonus*3);
      me->adjust_tmp_damage_bon(bonus);
      weap[i]->weapon_attack(target,me);
      if(me->query_timed_property("haste_on"))
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
      "Coste GPs: 5\n"
      "When a Ranger is hunting a person, he/she studies his oponent "
      "in order to find a weakness in his/her defenses.  The ranger "
      "then attacks gaining a short advantage.  The ranger can get a "
      "better advantage if the target doesn't even know if the ranger is "
      "there, because the ranger is hidden.  "
      "Once a weakness is exploited, the target will usually take "
      "measures to protect that weakness.  It takes the ranger a "
      "certain amount of time to find another weakness to exploit.  "
      "\n\nSintaxis: cazar <objetivo>\n\n";
}
