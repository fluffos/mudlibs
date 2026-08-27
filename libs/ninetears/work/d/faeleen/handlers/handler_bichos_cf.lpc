#define LOGS "/d/faeleen/handlers/"
#define NPCS "/d/faeleen/npc/"
void crear_criaturas(string tipo,object donde)
{
   if(!donde)
           write_file(LOGS+"handler_criaturas.log","Tipo: "+tipo+". Funcion llamada desde lugar desconocido."+ctime(time())+"\n");
   else switch(tipo)
   {
		case "faeleen_pobre":
		   if(!random(2))
		   	donde->add_clone(NPCS+"obrero_faeleen",1);
		   if(!random(2))
			donde->add_clone(NPCS+"mujer_pobre_faeleen",1);
		   if(!random(2))
			donde->add_clone(NPCS+"granuja_faeleen",1);
		   if(!random(2))
			donde->add_clone(NPCS+"hombre_pobre_faeleen",1);
		break;

   }// del switch
}// de crear_criaturas
