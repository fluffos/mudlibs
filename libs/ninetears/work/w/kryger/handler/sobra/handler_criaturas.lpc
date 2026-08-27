#define LOGS "/d/asgard/valle_sombrio/logs/"
#define NPCS "/d/asgard/npc/"
void crear_criaturas(string tipo,object donde)
{
	  int i;
   if(!donde)
           write_file(LOGS+"handler_criaturas.log","Tipo: "+tipo+". Funcion llamada desde lugar desconocido."+ctime(time())+"\n");
   else switch(tipo)
   {
   	
   	
//////////////////////////////////////////////////////////////////////////////////////////
		case "zona_basta":
		   if(!random(2))
		   	donde->add_clone(NPCS+"sombra",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"polilla",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"aranya",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"rata",1);
		   if(!random(1))
		   	donde->add_clone(NPCS+"babosa",1);
		   if(!random(1))
		   	donde->add_clone(NPCS+"vivora",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "zona_oscura":
		   if(!random(3))
			donde->add_clone(NPCS+"goblin_vs",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "zona_clara":
		   if(!random(3))
			donde->add_clone(NPCS+"orco_vs",1);
		   if(!random(1))
			donde->add_clone(NPCS+"capitan_orco_vs",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "zona_densa":
		   if(!random(2))
			donde->add_clone(NPCS+"oso_vs",1);
		   if(!random(2))
			donde->add_clone(NPCS+"serpiente_vs",1);
		   if(!random(2))
			donde->add_clone(NPCS+"lobo_vs",1);
		   if(!random(2))
			donde->add_clone(NPCS+"cuervo_vs",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "alrededores_del_templo":
		   if(!random(2))
		   	donde->add_clone(NPCS+"sombra",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"polilla",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"aranya",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"rata",1);
		   if(!random(1))
		   	donde->add_clone(NPCS+"babosa",1);
		   if(!random(1))
		   	donde->add_clone(NPCS+"vivora",1);d_clone(NPCS+"",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "ruinas_del_templo":
		   if(!random(2))
		   	donde->add_clone(NPCS+"sombra",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"polilla",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"aranya",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"rata",1);
		   if(!random(1))
		   	donde->add_clone(NPCS+"babosa",1);
		   if(!random(1))
		   	donde->add_clone(NPCS+"vivora",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
		case "templo_abandonado":
		   if(!random(2))
		   	donde->add_clone(NPCS+"sombra",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"polilla",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"aranya",1);
		   if(!random(2))
		   	donde->add_clone(NPCS+"rata",1);
		   if(!random(1))
		   	donde->add_clone(NPCS+"babosa",1);
		   if(!random(1))
		   	donde->add_clone(NPCS+"vivora",1);
		break;
//////////////////////////////////////////////////////////////////////////////////////////
	}// del switch
}// de crear_criaturas
