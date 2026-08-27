/*Rutseg 10-X-2001 anyade muchas cosas 16-IV-2002 deja de ser instant*/
/* Alegria alegria que el kok estubo aqui como siempre cambiando cosas Dic02*/

#define COSTE_GP 5
#define RECUPERA     15-me->query_level()/4
#define RECUPERACION ( 3>RECUPERA?3:RECUPERA )

int ejecutar_caza(object,object,object*,int);

int hunt(string str, object me)
{
 int bonus,i,j;
 string *objetivo;
 object enemigo= 0,*arma,*list;
 if(!me)
   me= this_player();

 if(me->query_timed_property("cansado_caza"))
  {
   notify_fail("Necesitas concentrarte de nuevo para buscar la posicion correcta.\n");
   return 0;
  }
 if(me->query_gp()<5)
  {
   notify_fail("Tu estas muy cansado para realizar esto ahora.\n");
   return 0;
  }
  arma= filter_array(this_player()->query_held_ob(),"is_weapon",this_player());
  if(!sizeof(arma))
   {
    notify_fail("Intentas cazar con las manos desnudas!!! probablemente, "
		"necesites algun arma para hacerlo. Deberias reconsiderarlo.\n");
    return 0;
   }
  if(me->query_property("pacify_on"))
   {
    notify_fail("Algo impide ejecutar tu caza...\n");
    return 0;
   }
  str= me->expand_nickname(str);
  list= find_match(str,ENV(me));
  if(!sizeof(list))
   {
    /*Si se encontro alguien escondido con el investigar, se le pone          ATP("encontrados",({cap_names}))*/
    if(me->query_property("encontrados"))
    //Comprobacion para evitar bucles en situacion innecesaria
     {
      //Se separan los objetivos del nick
      objetivo= explode(str,",");
      for(i=0;i<sizeof(objetivo) && !enemigo;i++)
       {
	//Se expanden nicks para que funcione con nicks multiples
	objetivo[i]= me->expand_nickname(objetivo[i]);
	//Se compara con encontrados para saber si se les quiere cazar
        if(member_array((objetivo[i]),me->query_property("encontrados"))!=-1)
	 {
	  //Por ultimo se comprueba que el encontrado este en la room
	  list= all_inventory(environment(me));
	  for(j=0;j<sizeof(list) && !enemigo;j++)
           {
	    if(member_array(objetivo[i],list[j]->query_alias())!=-1 ||                objetivo[i]==list[j]->query_name())
	     enemigo= list[j];
	   }
          }
        }
      }
    }
  else
  enemigo= list[0];
   if(!enemigo)
    {
     notify_fail("Desperdicias tus energias intentado cazar un objetivo que no existe.\n");
     me->adjust_gp(-COSTE_GP/2);
     return 0;
    }
 if(enemigo->query_property("pacify_on"))
  {
   notify_fail("Es tan pacifico que no vale la pena atacarle.\n");
   return 0;
  }
 if(enemigo->query_dead())
  {
   notify_fail("Lo intentas con fantasmas?.\n");
   return 0;
  }
 if(enemigo==me)
  {
   notify_fail("Que haces! Estas loco? Como te vas a cazar a ti mismo?\n");
   return 0;
  }
 me->add_timed_property("cansado_caza",1,RECUPERACION);
 if((str= enemigo->query_timed_property("no_recazable")))
  {
   notify_fail(enemigo->query_cap_name()+" es inalcanzable por un ataque tan rapido ya "
	       "que "+str+" le esta atravesando aun con multiples golpes.\n");
   return 0;
  }
 j= sizeof(arma);
 if(enemigo->query_property("bando")>1)
   bonus= me->query_level()*2;
 else
   bonus= me->query_level()*1/2;

 if(!sizeof(me->query_attacker_list()))
  {
   if(sizeof(enemigo->query_attacker_list()) && member_array(enemigo,me->query_call_outed())==-1)
    {
     tell_object(me,"Aprovechas que tu objetivo esta distraido con un oponente.\n");
     bonus+= 3;
    }
  }
 if(me->query_hide_shadow())
  {
   bonus= bonus/j*8/7;
   //Bono por estar escondido en bosque
   if(environment(me)->query_forest())
    {
     tell_object(me,"Surges de la maleza del bosque sorprendiendo a tu enemigo.\n");
     tell_object(enemigo,me->query_cap_name()+" surge de la maleza del bosque "
                 "sorprendiendote!\n");
     tell_room(environment(enemigo),me->query_cap_name()+" surge de la maleza del bosque "
               "sorprendiendo a "+enemigo->query_cap_name()+"\n",({enemigo,me}));
     bonus+= 5;
    }
    ejecutar_caza(me,enemigo,arma,bonus);
    return 1;
  }
 else
  {
   //La mitad si no estas escondido
   bonus= bonus/j*4/7;
  //Si no estas escondido el enemigo se entera de tu movimiento
   tell_object(objetivo,me->query_cap_name()+" ladea su cuerpo buscando una posicion "
               "ventajosa para encararte.\n");
  }
  tell_object(me,"Ladeas tu cuerpo buscando un punto por donde atacar "
              "a "+enemigo->query_cap_name()+".\n");
  call_out("ejecutar_caza",0,me,enemigo,arma,bonus);
	return 1;
}

int ejecutar_caza(object me,object enemigo,object *arma,int bonus)
{
 int i,j= sizeof(arma);
 string nom_arma;

 if(!enemigo || environment(enemigo)!=environment(me))
  {
   tell_object(me,"No encuentras a tu objetivo.\n");
   return 0;
  }
 if(enemigo->query_wis()-me->query_dex()+enemigo->query_level()/5>random(101))
  {
   tell_object(enemigo,"En el ultimo momento consigues esquivar el ataque fulgurante "
               "de "+me->query_cap_name()+"\n.");
   tell_object(me,"Sorprendentemente "+enemigo->query_cap_name()+" logra esquivar tu "
               "ataque!!\n");
   tell_room(environment(enemigo),enemigo->query_cap_name()+" esquiva el ataque "
             "de "+me->query_cap_name()+" con un movimiento instintivo.\n",({me,enemigo}));
  }
 else
  {
   for(i=j;i--;)
    {
     nom_arma= arma[i]->query_name();
     switch(arma[i]->query_attack_type())
      {
       case 1:
       tell_object(TP,"Clavas salvajemente a "+enemigo->query_cap_name()+
	           " tu "+nom_arma+".\n");
       tell_object(enemigo,me->query_cap_name()+" te clava salvajemente "
		   "su "+nom_arma+".\n");
       tell_room(ENV(me),me->query_cap_name()+" clava salvajemente a "
	         +enemigo->query_cap_name()+" su "+nom_arma+".\n",({me,enemigo}));
       break;
       case 2:
       tell_object(TP,"Golpeas brutalmente a "+enemigo->query_cap_name()+" con tu "
	           +nom_arma+".\n");
       tell_object(enemigo,me->query_cap_name()+" te golpea brutalmente "
        	   "con su "+nom_arma+".\n");
       tell_room(ENV(me),me->query_cap_name()+" golpea brutalmente a "
	         +enemigo->query_cap_name()+" con su "+nom_arma+".\n",({me,enemigo}));
       break;
       case 3:
       tell_object(TP,"Empalas despiadadamente a "+enemigo->query_cap_name()+
                   " con tu "+nom_arma+".\n");
       tell_object(enemigo,me->query_cap_name()+" te empala despiadadamente "
	           "con su "+nom_arma+".\n");
       tell_room(ENV(me),me->query_cap_name()+" empala despiadadamente a "
	           +enemigo->query_cap_name()+" con su "+nom_arma+".\n",({me,enemigo}));
       break;
       default:
       tell_object(TP,"Machacas a "+enemigo->query_cap_name()+".\n");
       tell_object(enemigo,me->query_cap_name()+" te machaca con su "+nom_arma+".\n");
       tell_room(ENV(me),me->query_cap_name()+" machaca a "+enemigo->query_cap_name()+
	           " con su "+nom_arma+".\n",({me,enemigo}));
       break;
      }
  //Evitando multiples ataques instant de danyo masivo con el cazar
 if(enemigo->query_player())
    enemigo->add_timed_property("no_recazable",me->query_cap_name(),1);
  //Vamos a poner un limite al cazar, bono 180 entre las dos armas
    bonus= bonus>180/j ? 180/j:bonus;
    me->adjust_tmp_tohit_bon(bonus);
    me->adjust_tmp_damage_bon(bonus);
    arma[i]->weapon_attack(enemigo,me);
    me->adjust_tmp_damage_bon(-bonus);
    me->adjust_tmp_tohit_bon(-bonus);
   }
 }
 enemigo->attack_by(me);
 me->adjust_gp(-COSTE_GP);
 me->attack_ob(enemigo);
 return 1;
}
string help(string str)
{
 return
 "Nombre: Cazar\n"
 "Coste GP: "+COSTE_GP+"\n"
 "Descripcion:\n\n\tCuando un Edhil caza a una persona, el estudia a su oponente "
 "para encontrar sus puntos mas debiles. El Edhil ataca ganando una pequenya ventaja "
 "sobre su oponente, pero para ello ha de mantener una buena posicion, los guerreros "
 "mas experimentados sabran recuperarla con mas facilidad. Esta ventaja es mayor si "
 "esta escondido o si su objetivo esta luchando contra un adversario, tambien el ataque "
 "es mucho mas efectivo cuando el Edhil aprovecha la espesura de los bosques.\nExiste la "
 "posibilidad de que el objetivo logre esquivar el ataque en el ultimo momento.\n"
 "\nUso:\n\tcazar <objetivo>\n\n";
}
