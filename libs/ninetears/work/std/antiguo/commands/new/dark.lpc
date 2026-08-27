/*** Drow Warrior Dark Globe***/
/* Taniwha 1995 */
/*** level 5 ***/

#define GP_COST 2
#define LEV 5
#define GLOBE_LOCK 200

string help() 
{
  return
    "\n\n"
    "Globo oscuro\n"
    "Level: "+LEV+"\n"
    "Coste en Gp: "+GP_COST+"\n"
    "Descripcion: \n"
    "    Esta es una innata habilidad de los guerreros Drow para "
    "crear un aura de oscuridad, u oscurecer una habitacion. (Aqui globo oscuro) "
    "Esta habilidad puede ser usada solo ocasionalmente, desde el ultimo hasta "
    "que el objetivo se apaga. En el caso de habitaciones, sera muy irregular si se formula "
    "desde fuera. La fuerza de la oscuridad del globo incrementa segun el level del lanzador."
    "\n\n";
}

int dark_globe(string str,object cast)
{
  object target;
  object caster;
  object *olist;
  caster = cast ? cast : this_player();
  if(interactive(caster))
    str = (string)caster->expand_nickname(str);

  if( caster->query_level() < LEV || 
      caster->query_property("dark globe") || 
      caster->query_gp() < GP_COST)
  {
    tell_object(caster,"No puedes excitarte para crear una actitud negativa "
      "y que te aparezca el aura.\n");
    return 1;
  }

  caster->add_timed_property("dark globe",1,GLOBE_LOCK);
  tell_object(caster,"Entras en colera construyendo globos magicos que te transportan "
                     "a la mas absoluta suboscuridad.\n");
  tell_room(environment(caster),caster->query_cap_name()+
    " crea globos de suboscuridad que le envuelven el cuerpo.\n", ({ caster }) );
  if(!str || str =="") 
    target = caster;
  else if(str == "aqui")
    target = environment(caster);
  else
  {
    olist = find_match(str,environment(caster));
    if(sizeof(olist)) 
      target = olist[0];
    else 
      target = caster;
  }

   if(target->query_light() >= 0)
      target->adjust_light(-(5+(int)caster->query_level()/3));
  caster->adjust_gp(-GP_COST);
  return 1;
}
