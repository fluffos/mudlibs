int herbalism(string str, object me)
{
   object target, my_home, his_home;
   int chance, roll, i;
   object* list;
   if(!me) me = this_player();
   if(me->query_alignment()>9000)
   {
      notify_fail("Yvendur no concede este poder a gente tan diabolica.\n");
      return 0;
   }
   if(sizeof(me->query_attacker_list()))
   {
      notify_fail("Las cosas estan un poco calientes para estar buscando "
         "hierbas y medicinas.\n");
      return 0;
   }
   if(me->query_gp()<5)
   {
      notify_fail("Estas demasiado cansado para buscar plantas medicinales.\n");
         return 0;
   }
   if(!environment(me)->query_outside())
   {
      notify_fail("Una rapida mirada a tu alrededor te dice, "
         "que aqui no hay material apropiado para lo que buscas.\n");
      return 0;
   }
   list=find_match(str,environment(me));
   target=list[0];
   if(target->query_dead())
   {
      notify_fail("Esta pobre alma ya ha salido de los reinos.  "
         "Seria una perdida de tiempo sacarte el veneno del cuerpo.\n");
      return 0;
   }
   if(sizeof(target->query_attacker_list()))
   {
      notify_fail(capitalize(target->query_objective())+
         " esta demasiado ocupado para recibir medicacion ahora.\n");
      return 0;
   }
   if(target->query_timed_property("failed_herbalism"))
   {
      notify_fail("No seria buena idea intentar otra cura "
         "tan pronto despues de fallar, meditalo.  "
         "Casi matas a la pobre alma.\n");
      return 0;
   }
   chance=25+me->query_wis()+me->query_level();
   if(chance>95)
      chance=95;
   roll=roll(1,100);
   write("Comienzas a buscar a tu alrededor alguna hierba o baya salvaje, "
      "con la que intentar una cura.\n");
   tell_room(environment(me),
      me->query_cap_name()+" comienza a buscar alrededor de la zona.\n",
      me);
   my_home=environment(me);
   his_home=environment(target);
   if(roll>chance)
      call_out("failed",5,target,me,his_home,my_home);
   else
      call_out("success",5,target,me,his_home,my_home);
   me->adjust_gp(-5);
   return 1;
}
int failed(object target, object me, object his_home, object my_home)
{
   if(my_home!=environment(me))
   {
      write("Fallas al buscar algo.\n");
      return 1;
   }
   if(his_home!=environment(target))
   {
      write("Viendo que "+target->query_cap_name()+" se ha ido, "
         "dejas de buscar.\n");
      return 1;
   }
   if(target==me)
   write("Te administras la medicacion, pero parece que has fallado.  "
      "Carraspeas violentamente.\n");
   else
   write("Administras la medicacion, pero parece que has fallado.  "+
      target->query_cap_name()+" carraspea violentamente.\n");
   if(target!=me)
   tell_object(target,me->query_cap_name()+" administra la medicacion, "
      "pero parece fallar.  Carraspeas violentamente.\n");
   tell_room(environment(me),me->query_cap_name()+
      " da a "+target->query_cap_name()+" la medicacion, pero "+
      target->query_cap_name()+" carraspea violentamente.\n",
      ({me,target}));
   target->adjust_hp(-roll(1,10),target);
   target->add_timed_property("failed_herbalism",1,1800);
   return 1;
}
int success(object target, object me, object his_home, object my_home)
{
   int i;
   object* obs;
   if(my_home!=environment(me))
   {
      write("Fallas al buscar algo.\n");
      return 1;
   }
   if(his_home!=environment(target))
   {
      write("Viendo que "+target->query_cap_name()+" se ha ido, "
         "dejas de buscar.\n");
      return 1;
   }
   if(target==me)
   write("Te administras la medicacion.  poco a poco te sientes mejor.\n");
   else
   write("Administras la medicacion.  "+target->query_cap_name()+
      " poco a poco se siente curado.\n");
   if(target!=me)
   tell_object(target,me->query_cap_name()+" te administra la medicacion.  "
      "poco a poco te sientes mejor.\n");
   tell_room(environment(me),me->query_cap_name()+" da a "+
      target->query_cap_name()+" la medicacion.  "+
      target->query_cap_name()+" se siente mejor.\n",
      ({me,target}));
   obs=all_inventory(target);
   for(i=0;i<sizeof(obs);i++)
      if((string)obs[i]->query_name()=="poisoned wound")
         obs[i]->dispell_me();
   return 1;
}
string help(string str)
{
   return
      "Herbalismo:\n\n"
      "Coste en Pg: 5\n"
      "Hermbalismo usa todo tu conocimiento sobre las plantas "
      "para crear medicaciones y pociones disenyandolas para neutralizar venenos.  "
      "El exito esta basado en la sabiduria y el nivel.  "
      "El herbalismo puede ser aplicado sobre cualquier ser, pero depende "
      "de la concentracion y el sitio donde estas, "
      "no puede ser aplicado en combate.  "
      "\n\nSintaxis: herbalismo <objetivo>\n\n";
}
