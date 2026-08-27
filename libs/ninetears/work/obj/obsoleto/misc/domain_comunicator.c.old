/*****************************************************************************
*						                   			     *
*	      Kit de Comunicaciones, comun para todos los dominios.   	     *
* 	        	     Khelben, 1997		                 		     *
*       	  Last Modification by MatatunoS 2002				     *
* 	        	Lover of cut and paste :=)			    		     *
*										 		     *
******************************************************************************/

inherit "/obj/armour";


void setup()
{
   set_base_armour("ring");
   set_name("Kit de comunicaciones");
   add_alias("kit");
   add_alias("comunicaciones");
   reset_drop(); // Impide que se pueda dejar en el suelo y que se caiga al morir, asi como darselo a otro.
  // set_wearable(2);
   set_short("%^BOLD%^%^YELLOW%^Kit de %^RED%^Comunicaciones%^RESET%^");
   set_long("%^BOLD%^%^YELLOW%^   Kit de Comunicaciones:%^RESET%^\n\n"
	" Es el kit completo para comunicarse por canales de dominios"
	" y alguna cosa mas, tambien contiene herramientas utiles. Para mas"
	" informacion pon 'help kit'.\n\n");   
   set_value(0);  //barato barato oiga....
   reset_drop();
   call_out("badge_hi",4);
}


// Ni warra, sospecho que al ponertelo o equipartelo o algo, cuando entras al juego sale.. 
// Te reconoce si eres un miembro del dominio Driade, y te saluda, eso significa que llevas el 
// kit del dominio Driade, y que eres miembro del mismo.
// El free_action te permite moverte bien en sitios con agua, y poder hablar y eso, como si estuviera seco.

void badge_hi()
{
   if( ETO && interactive(ETO) && 
       "/d/driade/master.c"->query_member(ETO->query_name()) ) 
   {
      write("%^CYAN%^\n\nLos espiritus de %^BOLD%^Driade %^RESET%^%^CYAN%^te dan la bienvenida mi Lord.%^RESET%^\n\n");
      ETO->add_timed_property("free_action",1,3000000);
   }
      write("\n%^BOLD%^%^RED%^Tu kit de comunicaciones es incorrecto y se desvanece. Clonalo de /obj/misc/kit_comunicaciones.c . Gracias a Leviathan por la ayuda.%^RESET%^\n\n");
	call_out("dest_me", 0);
}

// Utilidades varias del kit

void init()
{
   add_action("do_help","help");
   add_action("do_who","who");
   add_action("exit","exits");
   add_action("show_in", "in");
   add_action("qatt_me", "qatt");
   add_action("do_peace","peace");
   add_action("do_rain","rain");
   add_action("do_times","times");
   add_action("light","light");
   add_action("mudfind","mudfind");

   // Canales
   add_action("sschan","driade");
   add_action("sschan","ss");
   add_action("bfchan","bf");
   add_action("sfchan","sf");
   add_action("mmchan","mm");
   add_action("dlchan","dl");
   add_action("fpchan","fp");
   add_action("umchan","um");
   add_action("ofchan","of");
   add_action("hoerkchan","hoerk");   
   add_action("apriorchan","aprior");
   add_action("omiqchan","omiq");
   add_action("mudlibchan","mudlib");
   add_action("heavenchan","heaven");   
   add_action("radishchan", "radish");
   ::init();
}


// Empieza la fiesta!!            

// Fale.. esto talmente parece que comprueba si eres un miembro del dominio o un lord del dominio.
int domain_member(string name, string verb)
{
   string str;
   
   str = "/d/";
   str += verb;
   str += "/master.c";

   if( str->query_member(name) )
      return 1;
   if(find_player(name)->query_lord())
      return 1;

   return 0;   
}


// Segun mis investigaciones, esto debe de ser la ayuda o algo asi ;-)

int do_help(string arg)
{
    if(!(arg))
	return 0;
    if(arg=="kit")
    {
	write("\n%^BOLD%^%^RED%^Como miembro de un dominio puedes hacer  "
	  "lo siguiente:%^RESET%^\n\n"
	  "  <domain>       :  Envia mensages a otros miembros de <domain>\n"+
	  "  who <domain>   :  Muestra la lista de progamadores de <domain> on line\n"+
	  "  in <domain>    :  Muestra quien esta en <domain> (solo thanes)\n"+
	  "  mudfind <path> :  Busca los objetos <path> clonados en el mud.\n"+
          "  exit           :  Comprueba las salidas de la habitacion en la que estas.\n"+          	  
	  "  qatt           :  Muestra quien esta en peleas. (solo thanes)\n"+
	  "  peace          :  Para las peleas de la habitacion.\n"+
	  "  rain           :  Hacer dinero facilmente-> rain <cuantas> <monedas>\n"+
	  "  light <amt>    :  Ajusta la luz en una habitacion.\n"+ 
	  "  times          :  Da la hora de distintos paises.\n\n");
	return 1;
    }
    else 
      	return 0;
}


// Esta solo mira si eres el thane del dominio o no, o al menos eso parece

int have_power(object ob)
{
   if ( ob->query_thane() || ob->query_lord() )
      return 1;
   else
      return 0;
}


// Utilidad para dar potencia a las luces o quitarla

int light(string str)
{  
   int num;

   num = to_int(str);
   set_light(num);
   return 1;
}

// ni warra de lo que hace aunque lo sospecho.
int mudfind(string str)
{
   object *ob;
   int i;

   if(!str)
      return 0;
   if( file_size(str) < 0 )
   {
      write("El fichero no existe.\n");   
      return 1;
   }
   else
   {
      write("Buscando "+str+".\n\n");
      ob = children(str);
      for(i=0;i<sizeof(ob);i++)
      {		
         write(ob[i]->query_name()+" en "+file_name(environment(ob[i]))+
                ".\n");
      }
   }
   return 1;
}      


// Quien esta en el dominio?

int show_in(string input)
{
    string *doms;
    object *ob;
    int i;
    string str;
    int yep = 0;
    object env;
    string *bass;

    if( !have_power(TP) )
    {
       write("Solo thanes o superior puede hacer esto.\n");
       return 1;
    }

    ob = users();
    for (i=0; i<sizeof(ob); i++) 
    {
	if ((string)ob[i]->query_gender_string() != "blue") 
	{
	    str = file_name(environment(ob[i]));
	    bass = explode (str, "/");
	    doms = get_dir("/d/");
	    if (member_array(input, doms) == -1) { return 0; }
	    if (bass[1] == input) 
	    {
		yep = 1;
		write (ob[i]->query_cap_name()+ " in "+
	        environment(ob[i])->query_short()+ "   ("+
		file_name(environment(ob[i]))+ ")\n");
	    }
	}
    }
    if (yep == 0) 
    {
	write (sprintf("No hay nadie en el dominio %s en este momento. *weep*\n", 
	       capitalize(input)));
	return 1;
    }
    return 1;
}



// Para las peleas actuales de todos los pj y npcs que se encuentran en la room.

int do_peace() 
{
    object *ob;
    object *att;
    object *call;
    int i, s;

    ob=all_inventory(environment(this_player()));
    i=0;
    for(i=0; i<sizeof(ob); i++) 
    {
	if(living(ob[i])) 
	{
	    att=ob[i]->query_attacker_list();
	    call=ob[i]->query_call_outed();
	    for(s=0; s<sizeof(att); s++) 
	    {
		ob[i]->stop_fight(att[s]);
		att[s]->stop_fight(ob[i]);
	    }
	    for(s=0; s<sizeof(call); s++) 
	    {
		ob[i]->stop_fight(call[s]);
		call[s]->stop_fight(ob[i]);
	    }
	}
    }
    write("Levantas tus brazos y gritas: "+
          "%^YELLOW%^DEJAD DE LUCHAR MORTALES !!%^RESET%^\n");
    tell_room(environment(this_player()), this_player()->query_cap_name()+
              " alza sus manos al cielo y grita: %^YELLOW%^DEJAD DE LUCHAR MORTALES !!%^RESET%^\n", ({this_player()}));
    return 1;
} 



// A quien le importa la hora que es en sabediosdonde? no se si se refiere al mud o al mundo mundial...

int do_times() 
{
    if(!this_player()->query_creator()) 
	return 0;
    write("Son las "+ctime(time())+" en Normandia o Noruega o algo asi.\n");
    write("Son las "+ctime(time() - 21600)+" en la costa este.\n");
    write("Son las "+ctime(time() - 25200)+" en el centro del pais.\n");
    write("Son las "+ctime(time() - 28800)+" por la zona de las montanyas.\n");
    write("Son las "+ctime(time() - 32400)+" en la costa del Pacifico.\n");
    return 1;
} 


// Devuelve la cadena de la moneda que usara la siguiente funcion.
string get_type(string str) 
{          
    if(str=="c" || str=="cobre")   
	return "copper";            
    if(str=="b" || str=="estanyo")  
	return "brass";           
    if(str=="s" || str=="plata")        
	return "silver";                 
    if(str=="g" || str=="oro")        
	return "gold";                 
    if(str=="p" || str=="platino")  
	return "platinum";           
    return"none";                  
} 

int do_rain(string str) 
{      

    string type, cktype;      
    int amt;                 

    if(!str) 
    {
	write("Utilizacion: rain <cantidad> <tipo de moneda>\n");      
	return 1;                                             
    }     
    if(sscanf(str,"%d %s",amt,type)!=2) 
    {       
	write("Utilizacion: rain <cantidad> <tipo de moneda>\n");      
	return 1;                                             
    }     
    cktype=get_type(type);        
    if(cktype=="none") 
    {         
	write("Porfavor, utiliza un tipo de moneda existente.\n"); 
	return 1;                                    
    }    
    if(TP->adjust_money(amt, cktype)) 
    {         
        write("te han sido dadas "+amt+" monedas de "+cktype+"\n");
	tell_room(environment(this_player()), this_player()->query_cap_name()+
                  " motions crest at "+this_player()->query_possessive()+
                  " purse, presses a button, and the purse gets"+
                  " visibly larger.\n", this_player());  
	return 1;
    } 
    else 
    {
	write("No ha pasado nada... algo ha ido mal?\n");                           
	return 1;                                                            
    }                                                                      

}                                                        

int qatt_me()
{
    object *ob;
    int i;
    int yep = 0;
    object *fig;
    int f;
    
    if( !have_power(TP) )
    {
       write("Solo los thanes y superiores puede hacer esto.\n");
       return 1;
    }
    
    ob = users();
    for (i=0;i<sizeof(ob);i++)
    {
	if (sizeof(ob[i]->query_attacker_list())) 
	{
	    write ("\n"+ ob[i]->query_cap_name()+ " esta luchando:\n");
	    fig = ob[i]->query_attacker_list();
	    for (f=0;f<sizeof(fig);f++) 
	    {
		write ("\t"+ fig[f]->query_short()+ "\t("+ file_name(fig[f])+ ")\n");
		yep = 1;
	    }
        }
    }
    if (yep == 0) 
    {
	write ("Nadie esta en peleas en este momento.\n");
	return 1;
    }
    return 1;
}

string adjust_string_size(string str,int size) 
{
  int q;
  q=sizeof(explode(str,""));
  if(q<=size) return str;
  return("..."+str[q-(size-3)..q]);
}


//Esto compueba las salidas de una room, te dice a que sitio apuntan, si la room destino apunta hacia esta
// y con que tipo de salida lo hace, y si es correcta.

int exit() 
{
  int i,j;
  mixed* dirs,dirs2;
  mapping opposite = (["norte":"sur","sur":"norte","oeste":"este",
		       "este":"oeste","noroeste":"sudeste",
		       "sudeste":"noroeste","noreste":"sudoeste",
			"sudoeste":"noreste","arriba":"abajo","abajo":"arriba",
		       "fuera":"dentro","dentro":"fuera"]);
  if(!environment(this_player())) 
  {
    write("No estas en ningun sitio.\n");
    return 1;
  }
  dirs = environment(this_player())->query_dest_dir();
  if(!sizeof(dirs)) 
  {
    write("No hay salidas en esta habitacion.\n");
    return 1;
  }
  for(i=0;i<sizeof(dirs);i=i+2) 
  {
    string match;
    printf("%-10s: ",dirs[i][0..8]);
    sscanf(dirs[i+1],"%s.c",dirs[i+1]);
    dirs[i+1] = dirs[i+1]+".c";
    write(adjust_string_size(dirs[i+1],67)+"\n            ");
    if(file_size(dirs[i+1]) == -1)
      write("El fichero "+adjust_string_size(dirs[i+1],42)+"%^BOLD%^RED%^ no existe.%^RESET%^\n");
    else 
    {
      string ppp;
      if(ppp=catch(dirs2 = dirs[i+1]->query_dest_dir())) 
      {
        write(adjust_string_size(dirs[i+1],66)+" no quiere cargarse.\n");
	write(ppp);
      }
      else 
      {
        match = 0;
        if(sizeof(dirs2))
        for(j=0;j<sizeof(dirs2);j=j+2) 
        {
	  sscanf(dirs2[j+1],"%s.c",dirs2[j+1]); 
	  if(file_name(environment(this_player()))==dirs2[j+1])
	    match = dirs2[j];
        }
        if(!match)
  	  write("No hay salida desde "+adjust_string_size(dirs[i+1],30)+
	        " hacia esta habitacion.\n");
        else 
        {
	  if(opposite[dirs[i]] == match)
	    write("Ok.\n");
          else
	    write(" La salida desde "+adjust_string_size(dirs[i+1],24)+
	          " a esta habitacion es: "+match[0..8]+".\n");
        } 
      }
    }
  }
  return 1;
}

string query_rank_string(object ob) 
{

   string type;
   string rank = ob->query_object_type();

   if(rank == "B") 
      type = "Creador";
   if(rank == "P") 
   {
      if((int)this_player()->query_gender() == 2)
         type = "Patron";
      else
         type = "Patron";
   }
   if(rank == "T") 
      type = "Thane";
   if(rank == "D" || rank == "H") 
   {
      //if("/secure/lords"->query_boo(this_player()->query_name()))
         type = "Semi-Dios";
      //else
      //   type = "Alchemist";        
   }
   if(rank == "G") 
     type = "Dios";

  return type;
}

int valid_domain(string str)
{
   string *domains;

   domains = get_dir("/d/");
   if( !sizeof(domains) || (member_array(str, domains) == -1) ) 
      return 0;
   return 1;
}      

int do_who(string str) 
{
   
   object *ob;
   string nam, gende, rank, htype,dom;
   int i;
   string ip;
   
   if( !valid_domain(str) )
      return 0;
   
   ob = users();
   write("\n%^BOLD%^WHITE%^"
         "========================================================================\n"
         "                 %^GREEN%^ CREADORES DE %^CYAN%^"+capitalize(str)+"%^GREEN%^ CONECTADOS AHORA%^WHITE%^                  \n"
         "========================================================================"
          "%^RESET%^\n\n");
   for (i=0; i<sizeof(ob); i++) 
   {
      gende=(ob[i]->query_gender_string());
      nam=(ob[i]->query_name());
      ip=query_ip_number(ob[i]);
      nam = capitalize(nam);
      gende = capitalize(gende);
      htype = query_rank_string(ob[i]); 

	// Una mera comprobacion de sexos
      if (gende == "Mujer")
      	gende="%^BOLD%^MAGENTA%^"+gende+"%^RESET%^";
      else
		if(gende=="Varon")
      		gende="%^BOLD%^CYAN%^"+gende+"%^RESET%^";
		else
			if (gende=="Asexual")
				gende="%^BOLD%^BLACK%^"+gende+"%^RESET%^";
			else
				if (gende=="Bisexual")
					gende="%^BOLD%^CYAN%^Bise%^MAGENTA%^xual%^RESET%^";
				else
					 gende="%^BOLD%^WHITE%^Una ameba%^RESET%^";

					
      if( domain_member((string)ob[i]->query_name() , str) )
	    // lo hacemos asi para que los colores se muestren como tienen que ser.
	    TP->do_efun_write(sprintf("%-15s  %-8s  %-11s %-15s\n", ip, gende, htype, nam));
   }
   write("\n%^BOLD%^WHITE%^========================================================================%^RESET%^\n\n");
   return 1;
}



int sschan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int bfchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}
int fpchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int sfchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int radishchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat.c"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
   return 1;
}

int mmchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int dlchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int umchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int ofchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int hoerkchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int apriorchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int omiqchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int mudlibchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

int heavenchan(string str)
{
   if( domain_member((string)TP->query_name(), query_verb()) )
   {
      "/global/do_chat"->do_chat(str);
      return 1;
   }
   else
      write("No eres miembro del dominio "+query_verb()+".\n");
     
   return 1;
}

