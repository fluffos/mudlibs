    /* Vilat 01.09.2002 - Migrando al castellano */
    // Las antiguas denominaciones se mantendran validas hasta el 1 de Octubre, asi que hay un mes para migrar.
    // Despues hasta el 1 de Enero de 2003 seguiran como comentario por si algo fallase o alguien no hubiese actualizado sus objetos.
    // El 1 de Enero se eliminaran por completo las antiguas denominaciones

int *lookup_shield_data(string name) {
  	int *armour_data;

/* Elementos de armour_data: 
 *  0: Coste en monedas de oro. Los valores negativos indican monedas de plata.
 *  1: Coste en monedas de oro de un arma encantada (+1), un arma (+2) multiplicaria este
     	valor por 2, mientras que un arma (+3) lo haria por 4, un arma (+3), por 8 y
     	asi sucesivamente (crece de forma exponencial).
 *  2: Peso. 
 *  3: Tamanyo (De 1 [anillos] a 20 [armadura completa]).
 *  4: AC.
 *  5: Material: 
      	1.- Madera (supongo que esto esta obsoleto y es de la epoca de los escudos)
     	2.- Metal
     	3.- Cuero
     	4.- Ropa
 *  6: Numero de dados que se lanzan para determinar el danyo.
 *  7: Numero de caras de dichos dados.
 *  8: Modificador al danyo.
 */

  	switch(name) {
	
/*
    		case "wooden shield":
*/
    		case "madera":
      		armour_data=({   1,  1000,  40, 5, 10, 1, 1, 6, 1 }); 
      		break;
      		    
/*
    		case "buckler":
*/
    		case "rodela":
      		armour_data=({   1,  1500,  30, 5, 10, 2, 1, 4, 1 }); 
      		break;
      		
/*
    		case "small shield":
		case "escudo pequenyo": // Estara obsoleto aunq este en espanyol
*/
		case "pequenyo":
      		armour_data=({   3,  2000, 120, 5, 15, 2, 1, 8, 2 }); 
      		break;
      		
/*
    		case "shield":
    		case "medium shield":
		case "escudo mediano": // Tb estara obsoleto
*/
		case "mediano":
      		armour_data=({   7,  2500, 100, 6, 20, 2, 1,10, 2 }); 
      		break;

/*
	    	case "large shield":
		case "escudo grande": // Otro obsoleto (es mas facil q tengan una sola palabra)
*/
		case "grande":
	      	armour_data=({  10,  3000, 150, 8, 30, 2, 1,12, 2 }); 
	      	break;
	      	
/*
	      	case "escudo corporal": // Tb caducara en octubre
*/
	      	case "corporal":
      		armour_data=({  50,  7500, 250,14, 40, 2, 2, 8, 3 }); 
      		break;

// Estos escudos especiales de momento los dejo como estan
		case "escudo templanza":
      		armour_data=({ 100,  1000, 400,16, 70, 2, 3, 9, 1 }); 
      		break;

		case "escudo del demonio":
      		armour_data=({ 100,  1000, 400,16, 70, 2, 5, 8, 1 }); 
      		break;
      		
      		case "escudo negro":
      		armour_data=({ 150,  1500, 350,14, 70, 2, 3, 9, 1 }); 
      		break;
	
		default:
      		armour_data=({   3,  2000, 120, 5, 15, 2, 1, 8, 2 }); 
      		break;
  		}
  	return armour_data;
	}
