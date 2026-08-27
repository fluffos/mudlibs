#define LOGS "/d/faeleen/handlers/"
#define NPCS "/d/faeleen/npc/"
void crear_criaturas(string tipo,object donde)
{
   if(!donde)
           write_file(LOGS+"handler_criaturas.log","Tipo: "+tipo+". Funcion llamada desde lugar desconocido."+ctime(time())+"\n");
   else switch(tipo)
   {
		case "playa_faeleen":
		   if(!random(3))
		   	donde->add_clone(NPCS+"tortuga",random(3));
		   if(!random(3))
			donde->add_clone(NPCS+"cangrejo",random(3));
		   if(!random(3))
			donde->add_clone(NPCS+"gaviota",1);
		break;
		case "orilla_playa":
          if(!random(3))
		   	donde->add_clone(NPCS+"tortuga",random(3));
		  if(!random(3))
			donde->add_clone(NPCS+"cangrejo",random(3));
		  if(!random(3))
			donde->add_clone(NPCS+"gaviota",1);
		break;
		case "zona_rocosa":
		  if(!random(3))
		    donde->add_clone(NPCS+"turista",1);
		break;
		case "grutas_playa":
		  if(!random(2))
		   donde->add_clone(NPCS+"aranya",random(3));
		  if(!random(2))
		   donde->add_clone(NPCS+"rata",random(3));
		break;
		case "espigones_playa":
		   if(!random(3))
			donde->add_clone(NPCS+"pescador",1);
		break;
		case "faro_playa":
          if(!random(3))
			donde->add_clone(NPCS+"turista",1);
		break;
		case "acantilado_playa":
		  if(!random(3))
			donde->add_clone(NPCS+"turista",1);
		break;
		case "mirador_playa":
		   if(!random(3))
			donde->add_clone(NPCS+"turista",1);
		break;


   }// del switch
}// de crear_criaturas
