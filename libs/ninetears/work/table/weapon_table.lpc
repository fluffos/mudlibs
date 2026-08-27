    /* Vilat 01.09.2002 - Migrando al castellano */
    // Las antiguas denominaciones se mantendran validas hasta el 1 de Octubre, asi que hay un mes para migrar.
    // Despues hasta el 1 de Enero de 2003 seguiran como comentario por si algo fallase o alguien no hubiese actualizado sus objetos.
    // El 1 de Enero se eliminaran por completo las antiguas denominaciones

int *lookup_weapon_data(string name) {
    	int *weapon_data;
 
    /* Elementos de weapon_data:
     *  1: Coste en monedas de oro. Los valores negativos indican monedas de plata.
     *  2: Coste en monedas de oro de un arma encantada (+1), un arma (+2) multiplicaria este
     		valor por 2, mientras que un arma (+3) lo haria por 4, un arma (+3), por 8 y
     		asi sucesivamente (crece de forma exponencial).
     *  3: Peso.
     *  4: Tipo de danyo:
     		1.- Corte
     		2.- Contundente
     		3.- Perforacion
     *  5: Numero de dados que se lanzan para determinar el danyo.
     *  6: Numero de caras de dichos dados.
     *  7: Modificador al danyo.
     *  8: Material:
     		1.- Madera
     		2.- Metal
     		3.- Cuero
     		
     *  Un arma sera considerada a dos manos por defecto si su danyo maximo es mayor que 8.
     *  Si el danyo maximo de un arma es menor que 8 pero queremos que sea a dos manos, usaremos 
     *  'set_twohanded(1);' en el setup().
    */

	// Algunas armas de metal (hachas, mazas) estan puestas de madera en lugar de metal.
	// Esto se debe a que la resistencia de un arma se calcula segun el material,
	// y estas armas tienen el mango de madera, por lo que es facil que se rompan.

    	switch(name) {
    		// Espadas
/*
		case "short sword":
*/
    		case "esp_corta":
		weapon_data=({10,1000, 30, 3, 1, 6, 0, 2 }); 
		break;

/*
    		case "scimitar":
    		case "long sword":
*/
    		case "esp_larga":
    		case "cimitarra":
		weapon_data=({15,1500, 40, 1, 1, 8, 0, 2 }); 
		break;

/*
    		case "broad sword":
*/

    		case "esp_ancha":
		weapon_data=({25,2500,100, 1, 2, 4, 0, 2 }); 
		break;
		
/*
		case "bastard sword":
*/
    		case "esp_bastarda":
		weapon_data=({25,2500,100, 1, 4, 5,-1, 2 }); 
		break;

/*
    		case "twohanded sword":
*/
    		case "espadon":
    		case "mandoble":
		weapon_data=({50,5000,150, 1, 2, 8, 2, 2 }); 
		break;
		
		// Hachas
/*
    		case "hand axe":
*/
    		case "hacha_mano":
		weapon_data=({ 1, 100, 50, 1, 1, 3, 0, 1 }); 
		break;


/*
    		case "battle axe":
*/
    		case "hacha_batalla":
		weapon_data=({ 5, 500, 70, 1, 1, 8, 0, 1 }); 
		break;
		
/*
    		case "twohanded axe":
*/
    		case "hacha_guerra":
    		case "hacha_dosmanos":
		weapon_data=({50,5000,180, 1, 2, 8, 2, 2 }); 
		break;

    		case "hacha de oneex":
		weapon_data=({800,5000,300,1, 5, 6, 2, 2 }); 
		break;
		
		// Martillos, bastones y mazas
/*
    		case "war hammer":
*/
    		case "martillo":
		weapon_data=({ 2, 200, 60, 2, 1, 4, 2, 1 }); 
		break;

/*
    		case "club":
*/
    		case "garrota":
    		case "garrote":
		weapon_data=({ 3, 300, 30, 2, 1, 6, 0, 1 }); 
		break;
		
/*
    		case "quarterstaff":
*/
    		case "baston":
		weapon_data=({ 5, 500, 40, 2, 1, 6, 0, 1 }); 
		break;

/*
    		case "mace":
*/
    		case "maza":
		weapon_data=({ 8, 800,100, 2, 1, 6, 1, 1 }); 
		break;

/*
    		case "twohanded_staff":
*/
    		case "baston_pesado":
		weapon_data=({ 8, 800,100, 2, 1,12, 0, 1 }); 
		break;
		
    		case "morning_star": /* Lo dejo practicamente iwal, basicamente es una maza de metal */
    		case "morning star":
		weapon_data=({10,1000,120, 2, 2, 4, 1, 2 }); 
		break;

/*
    		case "twohanded_mace":
*/
    		case "maza_pesada":
		weapon_data=({12,1300,100, 2, 1,11, 1, 1 }); 
		break;
		
		case "martillo_pesado": /* Nuevo */
		weapon_data=({15,1400,150, 2, 2, 6, 1, 2 }); 
		break;

		// Armas de Asta		
/*
    		case "spear":
*/
    		case "lanza":
		weapon_data=({ 3, 300, 60, 3, 1, 5, 0, 1 }); 
		break;

/*
    		case "awl pike":
*/
    		case "pica":
		weapon_data=({ 5, 500,120, 3, 1, 6, 3, 1 }); 
		break;		
		
/*
    		case "halberd": 
*/
    		case "alabarda":
		weapon_data=({10,1000,150, 2, 1, 5, 0, 1 }); 
		break;

/*
    		case "trident":
*/
    		case "tridente":
		weapon_data=({15,1500, 50, 3, 1, 6, 1, 1 }); 
		break;

		// Cuchillo, dagas y estiletes
/*
    		case "dirk":
*/
    		case "estilete":
    		case "cortaplumas":
		weapon_data=({-5,  50, 10, 3, 1, 3, 0, 2 }); 
		break;

/*
     		case "knife":
*/
     		case "cuchillo":
     		case "navaja":
		weapon_data=({ 2, 200, 10, 1, 1, 4, 0, 2 }); 
		break;

/*
    		case "dagger":
*/
    		case "punyal":
    		case "daga":
		weapon_data=({ 2, 200, 10, 3, 1, 4, 0, 2 }); 
		break;
		
		// Arrojadizas y proyectiles (usadas en cuerpo a cuerpo)		
/*
    		case "dart":
*/
    		case "dardo":
		weapon_data=({-5,  50,  5, 3, 1, 3, 0, 2 }); 
		break;

/*
    		case "javelin":
*/
    		case "jabalina":
		weapon_data=({ 1, 100, 20, 3, 1, 3, 0, 1 }); 
		break;

/*
    		case "arrow":
*/
    		case "flecha":
		weapon_data=({ 4, 400, 10, 3, 1, 3, 0, 1 }); 
		break;

/*
    		case "bow":
*/
    		case "arco":
		weapon_data=({10,1000, 50, 2, 1, 1, 0, 1 }); 
		break;

		// Herramientas
/*
    		case "sickle":
*/
    		case "hoz":
		weapon_data=({ 1, 100, 30, 1, 1, 3, 1, 2 }); 
		break;
		
		case "azada": /* Nuevo */
		weapon_data=({ 4, 400, 60, 2, 1, 4, 1, 1 }); 
		break;		
		
/*
    		case "polearm":
*/
    		case "horca":
		weapon_data=({ 5, 500, 70, 3, 1, 6, 0, 1 }); 
		break;

/*
		case "fauchard":
*/
		case "guadanya":
    		weapon_data=({ 5, 500,700, 1, 1, 6, 1, 1 }); 
		break;
				
/*
    		case "glaive":
*/
    		case "guadanya_pesada":
		weapon_data=({ 6, 600,800, 1, 1, 8, 1, 1 }); 
		break;
		
/*
    		case "pick":
*/
    		case "pico":
		weapon_data=({ 8, 800, 60, 3, 1, 6, 0, 1 }); 
		break;    		
		
/*
		case "pitchfork":
*/
    		case "horca_larga":
		weapon_data=({ 8, 800,100, 3, 2, 4, 1, 1 }); 
		break;
		
		// Otros
/*
    		case "whip":
*/
    		case "latigo":
		weapon_data=({-3,  30, 20, 2, 1, 2, 0, 3 }); 
		break;

/*
   		case "flail":
*/
   		case "flagelo":
   		case "mayal":
   		case "mangual":
		weapon_data=({15,1500,150, 2, 1, 6, 2, 1 }); 
		break;

    		default: 
weapon_data=({1,1,1,1,1,1,1,1});
    		break;
    		}
    	return weapon_data;
	}
