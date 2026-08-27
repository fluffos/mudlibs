int mend(string str, object me)
{
   int chance, roll, dice, size, max, hurt, healed;
   object* list;
   object target;
   if(!me) me = this_player();
   if(me->query_alignment()>1000)
   {
      notify_fail("Yvendur no concede este poder a alguien tan malvado.\n");
      return 0;
   }
   if(sizeof(me->query_attacker_list()))
   {
      notify_fail("Estas demasiado ocupado para pensar en mejorar "
         "las cosas ahora.\n");
      return 0;
   }
   if(me->query_gp()<5)
   {
      notify_fail("Estas demasiado cansado para realizar esta tarea apropiadamente.  "
         "Descansa un poco e intentalo de nuevo.\n");
      return 0;
   }
   list=find_match(str,environment(me));
   if(!sizeof(list))
   {
      notify_fail("Mejorar a quien?\n");
      return 0;
   }
   target=list[0];
   if(target->query_timed_property("mended"))
   {
     if(target!=me)
      {  notify_fail("Este objetivo no puede beneficiarse otra vez "
                     "hasta despues de un dia.\n");
         return 0;
      }
      else
        {  notify_fail("No puedes bendar tus heridas hasta que no pase un dia.\n");
	   return 0;
	}    	 
   }
   if(target->query_dead())
   {
      notify_fail("Has hecho tarde para poder mejorar "
         "sus heridas.  "+target->query_cap_name()+" realmente esta "
         "fuera de los reinos.\n");
      return 0;
   }
   if(sizeof(target->query_attacker_list()))
   {
      notify_fail(capitalize(target->query_objective())+
         " esta un poco ocupado en este momento.\n");
      return 0;
   }
   dice=me->query_level()/5;
   size=me->query_wis()/2;
   max=dice*size;
   hurt=target->query_max_hp()-target->query_hp();
   if(hurt<max)
   {
     if(target!=me)
       { notify_fail(target->query_cap_name()+" no esta lo suficientemente "
         "herido para que le administres tus cuidados.\n");
         return 0;
       }
       else
         { notify_fail("No estas suficientemente herido para intentar un bendaje.\n");
	   return 0;
	 }          	 
   }
   
      
   healed=roll(dice,size);
   chance=50+me->query_wis()+me->query_level();
   if(chance>95)
      chance=95;
   roll=roll(1,100);
   if(roll>chance)
   {
      write("Intentas mejorar las heridas de "+target->query_cap_name()+", "
         "pero fallas completamente al reparar sus heridas.\n");
      if(target!=me)
      tell_object(target,me->query_cap_name()+" intenta mejorar tus heridas, "
         "pero falla completamente al reparar el "
         "danyo.\n");
      tell_room(environment(me),me->query_cap_name()+" intenta mejorar las heridas de "+
         target->query_cap_name()+" pero falla completamente al "
         "reparar el danyo.\n",({target,me}));
      target->adjust_hp(healed/3,me);
      me->adjust_gp(-5);
   }
   else
   {
      write("Repones un trozo de benda de tu alrededor y materiales y "
         "bendas satisfactoriamente las heridas de "+target->query_cap_name()+".\n");
      if(target!=me)
      tell_object(target,me->query_cap_name()+" repone un bendaje "
         "y materiales y te benda las heridas satisfactoriamente.\n");
      tell_room(environment(me),me->query_cap_name()+" repone "
         " un bendaje y material para bendar satisfactoriamente las heridas de "+
         target->query_cap_name()+".\n",({target,me}));
      target->adjust_hp(healed,me);
      me->adjust_gp(-5);
   }
   target->add_timed_property("mended",1,600);
   return 1;
}
string help(string str)
{
   return
      "Comando: Mejorar\n"
      "Coste en Pg: 5\n\n"
      "Mejorar, utiliza los concimientos del cuerpo para bendar "
      "las heridas de uno mismo o de otro.  "
      "La efectividad y nivel del exito esta basado en la sabiduria "
      "y nivel de esperiencia que tienes.  "
      "Incluso si el mejorar no ha tenido exito completametente, no es "
      "un fallo ni mucho menos.  "
      "Esto es una curacion sin magia y requiere tiempo y espacio para "
      "administrarlo, esta prohibido hacerlo en medio de "
      "un combate.  Finalmente, mejorar unas heridas no necesariamente "
      "las sana.  Las protege, y las permite sanar mas facilmente. "
      "El cuerpo debe sanar las heridas naturalmente.  "
      "Porque las heridas solo pueden ser mejoradas una vez por dia.  "
      "\n\nSintaxis: mejorar <objetivo>\n\n";
}
