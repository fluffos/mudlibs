//Kryger 2003//

void poner_bichos(string tipo,object donde, int cantidad) {
	int i;
	for(i=0;i<cantidad;i++) switch(tipo) {
	// La parte interesante del handler empieza aqui
		case "zona_basta": 
		switch(random(10)) { 
			case 0: 
			case 1:
			clone_object("/d/asgard/npc/sombra")->move(donde);break; 
			case 2: 
			case 3:
			clone_object("/d/asgard/npc/polilla")->move(donde);break;
			case 4: 
			case 5:
			clone_object("/d/asgard/npc/rata")->move(donde);break;
			case 6:
			case 7:
			clone_object("/d/asgard/npc/aranya")->move(donde);break;
			case 8:
			clone_object("/d/asgard/npc/babosa")->move(donde);break;
			case 9:
			clone_object("/d/asgard/npc/vibora")->move(donde);break;
			}
		break; // Importante al acabar una zona
		case "tipo2": // Espacios para otras zonas
		case "tipo3":
		case "tipoN":
		}
	}