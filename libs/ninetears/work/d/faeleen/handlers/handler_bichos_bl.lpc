#define LOGS "/d/faeleen/handlers/"
#define NPCS "/d/faeleen/npc/"
void crear_criaturas(string tipo,object donde)
{
   if(!donde)
           write_file(LOGS+"handler_criaturas.log","Tipo: "+tipo+". Funcion llamada desde lugar desconocido."+ctime(time())+"\n");
   else switch(tipo)
   {
		case "bosque_lobos":
		   if(!random(3))
		   	donde->add_clone(NPCS+"lobo",1);
		   
		break;
		case "claro_bosque_lobos":
			if(!random(3))
			 donde->add_clone(NPCS+"lobo",1);
		break;

   }// del switch
}// de crear_criaturas
