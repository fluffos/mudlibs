#define LOGS "/d/turkhun/logs/"
#define NPCS "/d/turkhun/npc/"
void crear_criaturas(string tipo,object donde)
{
	  int i;
   if(!donde)
           write_file(LOGS+"handler_criaturas.log","Tipo: "+tipo+". Funcion llamada desde lugar desconocido."+ctime(time())+"\n\n");
   else switch(tipo)
   {
   	
   	
//////////////////////////////////////////////////////////////////////////////////////////
		case "zonaneutral":
		   if(!random(3))
		   	donde->add_clone(NPCS+"genericos/guardia",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "zonamercado":
		   if(!random(2))
			donde->add_clone(NPCS+"ladrones/ladron_que_roba",1);
		   if(!random(3))
		   	donde->add_clone(NPCS+"genericos/guardia",1);
		   if(!random(5))
		   	donde->add_clone(NPCS+"genericos/murcielago",1);
		   if(!random(4))
		   	donde->add_clone(NPCS+"genericos/rata",1);

		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "zonasigiladores":
		   if(!random(2))
			donde->add_clone(NPCS+"ladrones/ladron_que_roba",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"genericos/guardia",1);
		   if(!random(5))
		   	donde->add_clone(NPCS+"genericos/murcielago",1);
		   if(!random(4))
		   	donde->add_clone(NPCS+"genericos/rata",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "zonaluchadores":
		   if(!random(2))
		   	donde->add_clone(NPCS+"genericos/desterrado_takome",1);
		   else
		   	if(!random(2))
				donde->add_clone(NPCS+"genericos/desterrado_dendara",1);
			else
		   		if(!random(2))
					donde->add_clone(NPCS+"genericos/desterrado_kheleb",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"genericos/guardia",1);
		   if(!random(5))
		   	donde->add_clone(NPCS+"genericos/murcielago",1);
		   if(!random(4))
		   	donde->add_clone(NPCS+"genericos/rata",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "zonamagos":
		   if(!random(2))
			donde->add_clone(NPCS+"ladrones/ladron_que_roba",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"genericos/guardia",1);
		   if(!random(5))
		   	donde->add_clone(NPCS+"genericos/murcielago",1);
		   if(!random(4))
		   	donde->add_clone(NPCS+"genericos/rata",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "zonabardos":
		   if(!random(2))
			donde->add_clone(NPCS+"ladrones/ladron_que_roba",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"genericos/guardia",1);
		   if(!random(5))
		   	donde->add_clone(NPCS+"genericos/murcielago",1);
		   if(!random(4))
		   	donde->add_clone(NPCS+"genericos/rata",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "caverna":
		   for (i=1;i<6;i++)
		   if(!random(2))
			donde->add_clone(NPCS+"genericos/murcielago2",1);
		   for (i=1;i<6;i++)
		   if(!random(5))
		   	donde->add_clone(NPCS+"genericos/rata2",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "caminovalle":
		   for (i=1;i<3;i++)
		   	if(!random(2)-1)
		   		donde->add_clone(NPCS+"genericos/pajaro",1);
		   for (i=1;i<6;i++)
		   	if(!random(2))
		   		donde->add_clone(NPCS+"genericos/mariposa",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////		
		case "arboledavalle":
		   if(!random(2))
			donde->add_clone(NPCS+"ladrones/ladron_que_roba",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"genericos/guardia",1);
		   if(!random(5))
		   	donde->add_clone(NPCS+"genericos/murcielago",1);
		   if(!random(4))
		   	donde->add_clone(NPCS+"genericos/rata",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////		
		default:
			if(!random(4))
				donde->add_clone(NPCS+"murcielago",1);
			write_file(LOGS+"handler_criaturas.log","No se encontro del tipo de criatura "+tipo+" en "+file_name(donde)+".\n");
	}// del switch
}// de crear_criaturas
