//.oO JaDe Oo.  Junio'01 -modified Mayo'02-

inherit "/obj/weapon";
#define	DEBUG(ob) ( ob->query_creator() || ob->query_property("TEST") )

void setup()
{	
	set_base_weapon("quarterstaff");
	set_name("Vara del %^BOLD%^BLACK%^Avatar%^RESET%^");
	set_short("Vara del %^BOLD%^BLACK%^Avatar%^RESET%^");
	set_long("Vara del Avatar.\n"
		 "Una vara tallada en una oscura madera, casi negra, rugosa al tacto. "
		 "Es bastante ligera, debido a su corta longitud, lo que la hace muy "
		 "manejable. Estrecha en la base, ensanchandose ligeramente hacia la "
		 "parte superior, donde termina con una especie de dedos alargados y "
		 "retorcidos que se cinyen firmemente alrededor de un gran zafiro con "
		 "forma oval. La gema emite pequenyos pulsos azulados de energia.\n");
	set_main_plural("Varas del %^BOLD%^BLACK%^Avatar%^RESET%^");	
	add_alias("vara del avatar");
	add_alias("vara");
        add_plural("varas");
	add_plural("varas del avatar");
        set_enchant(3);
        set_weight(25);
	set_twohanded(1);
 //       add_attack("mace","blunt",2,8,2);
//	add_property("guild",({"nigromante"}));
}

int write_message(object him,object me)
{
  int tmp1=::write_message(him,me);
  int tmp2=-him->spell_damage(-roll(1,6)-me->query_magic_bonus(),"weapon",me);
  int damage=tmp1+tmp2;
  string el=him->query_cap_name();
  string yo=me->query_cap_name();
  string vara=query_short();
  switch (tmp1)
{
 case 0:

   tell_room(environment(me),yo+" no consigue golpear a "+el+".\n",({him,me}));
   tell_object(me,"No consigues golpear a "+el+".\n");
   tell_object(him,yo+" no consigue golpearte.\n");
   break;

 case 1..5:
    
   tell_room(environment(me),yo+" golpea a "+el+" con su "+vara+".\n",({him,me}));
   tell_object(me,"Golpeas a "+el+" con tu "+vara+".\n");
   tell_object(him,yo+" te golpea con su "+vara+".\n");  
   break;

 case 6..15:
    
   tell_room(environment(me),yo+" machaca el brazo de "+el+" con su "+vara+".\n",({him,me}));
   tell_object(me,"Machacas el brazo de "+el+" con tu "+vara+".\n");
   tell_object(him,yo+" machaca tu brazo con su "+vara+".\n");  
   break;

case 16..25:
    
   tell_room(environment(me),yo+" hunde su "+vara+" en el abdomen de "+el+".\n",({him,me}));
   tell_object(me,"Hundes tu "+vara+" en el abdomen de "+el+".\n");
   tell_object(him,yo+" hunde su "+vara+" en tu abdomen.\n");
   break;

 case 26..35:
    
   tell_room(environment(me),yo+" golpea con fuerza la pierna de "+el+" con su "+vara+" haciendole perder el equilibrio.\n",({him,me}));
   tell_object(me,"Golpeas con fuerza la pierna de "+el+" con tu  "+vara+" haciendole perder el equilibrio.\n");
   tell_object(him,yo+" golpea con fuerza tu pierna con su "+vara+" haciendote perder el equilibrio.\n");
   break;
 
 case 36..45:
   
   tell_room(environment(me),"Oyes crujir los huesos de "+el+" cuando "+yo+" le golpea con su    "+vara+".\n",({him,me}));
   tell_object(me,"Oyes crujir los huesos de "+el+" cuando le golpeas con tu "+vara+".\n");
   tell_object(him,"Oyes el crujido de tus huesos cuando "+yo+" te golpea con su "+vara+".\n");  
   break;

case 46..1000:
   
   tell_room(environment(me),""+yo+" golpea brutalmente a "+el+" con su "+vara+" destrozandole el rostro.\n",({him,me}));
   tell_object(me,"Golpeas brutalmente a "+el+" con tu "+vara+" destrozandole el rostro.\n");
   tell_object(him,""+yo+" te golpea brutalmente con su "+vara+" destrozandote el rostro.\n");  
   break;
}
   switch (tmp2)
  { 
    case 1..5:
      tell_object(me,"Tu "+vara+" produce una ligera descarga a "+el+".\n");
      tell_object(him,"La "+vara+" de "+yo+" te produce una ligera descarga.\n");
      tell_room(ENV(me),"La "+vara+" de "+yo+" produce una ligera descarga a "+el+".\n",({him,me}));
      break;
    case 6..10:
      tell_object(me,"Tu "+vara+" produce una descarga a "+el+".\n"); 
      tell_object(him,"La "+vara+" de "+yo+" te produce una descarga.\n");
      tell_room(ENV(me),"La "+vara+" de "+yo+" produce una descarga a "+el+".\n",({him,me}));
      break;
    case 11..15:
      tell_object(me,"Tu "+vara+" electrocuta a "+el+".\n"); 
      tell_object(him,"La "+vara+" de "+yo+" te electrocuta.\n");
      tell_room(ENV(me),"La "+vara+" de "+yo+" electrocuta a "+el+".\n",({him,me}));
      break;
    case 16..1000:
      tell_object(me,el+" se convulsiona horriblemente por la descarga de tu "+vara+".\n");
      tell_object(him,"Te convulsionas horriblemente por la descarga de la "+vara+" de "+yo+".\n");
      tell_room(ENV(me),el+" se convulsiona horriblemente por la descarga de la "+vara+" de "+yo+".\n",({him,me}));
      break;
  }

  if (DEBUG(me)) tell_object(me,"Danyo: "+tmp1+","+tmp2+","+damage+".\n");
    return tmp1+tmp2;
}