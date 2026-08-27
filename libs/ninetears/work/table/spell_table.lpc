/* This will be the table for spells.
 * It will be the place spells.c will look for when it casts a spell, and the
 * guld will find the spells to add to a player. 
 * This will reduce the memory requirements in the spell array in the player obs
 * But it may be slower than the old system. I am not sure yet tho..
 * Started sept 11 '93 by Baldrick.
 */
/* the complete array will not be finished until I know what I need */
/* it looks like the easiest method is to have two tables, one for sphere/spell
 * and one for spell/filename.. Shame ..*/

/*** Addition of spells and new spheres started by Eerevann Nov 93 ***/

mixed query_spellist()
{
    mixed list;
    int level;
	string guild;

    list = ({ });
    level = this_player()->query_level();
	guild = this_player()->query_guild_name(); // para uso cuando decidamos q es accesible

	switch(level)
	{
	case 14..1000:
	case 11..13:
	case 9..10:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:
        if (guild == "wizthief") {
            if(!this_player()->query_spell("trampa de granizo"))
                list += ({"trampa de granizo"});
            if(!this_player()->query_spell("trampa de bola de fuego"))
                list += ({"trampa de bola de fuego"});
            if(!this_player()->query_spell("conocer alineamiento"))
                list += ({"conocer alineamiento"});
            if(!this_player()->query_spell("detectar invisibilidad"))
                list += ({"detectar invisibilidad"});
            if(!this_player()->query_spell("detectar magia"))
                list += ({"detectar magia"});
            if(!this_player()->query_spell("espejismo"))
                list += ({"espejismo"});
            if(!this_player()->query_spell("globo menor invulnerabilidad"))
                list += ({"globo menor invulnerabilidad"});
            if(!this_player()->query_spell("enjambre de meteoros sombra"))
                list += ({"enjambre de meteoros sombra"});
            if(!this_player()->query_spell("inaudibilidad"))
                list += ({"inaudibilidad"});
            if(!this_player()->query_spell("invisibilidad"))
                list += ({"invisibilidad"});
            if(!this_player()->query_spell("relampago sombra"))
                list += ({"relampago sombra"});
            if(!this_player()->query_spell("toque helado"))
                list += ({"toque helado"});
            if(!this_player()->query_spell("toque vampirico"))
                list += ({"toque vampirico"});
            if(!this_player()->query_spell("resistencia menor acido"))
                list += ({"resistencia menor acido"});
            if(!this_player()->query_spell("resistencia menor agua"))
                list += ({"resistencia menor agua"});
            if(!this_player()->query_spell("resistencia menor aire"))
                list += ({"resistencia menor aire"});
            if(!this_player()->query_spell("resistencia menor electrico"))
                list += ({"resistencia menor electrico"});
            if(!this_player()->query_spell("resistencia menor enfermedad"))
                list += ({"resistencia menor enfermedad"});
            if(!this_player()->query_spell("resistencia menor frio"))
                list += ({"resistencia menor frio"});
            if(!this_player()->query_spell("resistencia menor fuego"))
                list += ({"resistencia menor fuego"});
            if(!this_player()->query_spell("resistencia menor magico"))
                list += ({"resistencia menor magico"});
            if(!this_player()->query_spell("resistencia menor mental"))
                list += ({"resistencia menor mental"});
            if(!this_player()->query_spell("resistencia menor muerte"))
                list += ({"resistencia menor muerte"});
            if(!this_player()->query_spell("resistencia menor proyectiles"))
                list += ({"resistencia menor proyectiles"});
            if(!this_player()->query_spell("resistencia menor tierra"))
                list += ({"resistencia menor tierra"});
            if(!this_player()->query_spell("resistencia menor veneno"))
                list += ({"resistencia menor veneno"});
        }
        else if (guild == "clerigo de gestur") {
	    if(!this_player()->query_spell("bendicion"))
		list += ({"bendicion"});
	    if(!this_player()->query_spell("luz"))
		list += ({"luz"});
	    if(!this_player()->query_spell("oscuridad"))
		list += ({"oscuridad"});
	    if(!this_player()->query_spell("plegaria"))
		list += ({"plegaria"});
	    if(!this_player()->query_spell("curar heridas criticas"))
		list += ({"curar heridas criticas"});
	    if(!this_player()->query_spell("curar heridas serias"))
		list += ({"curar heridas serias"});
	    if(!this_player()->query_spell("curar heridas moderadas"))
		list += ({"curar heridas moderadas"});
	    if(!this_player()->query_spell("curar heridas ligeras"))
		list += ({"curar heridas ligeras"});
	    if(!this_player()->query_spell("causar heridas criticas"))
		list += ({"causar heridas criticas"});
	    if(!this_player()->query_spell("causar heridas serias"))
		list += ({"causar heridas serias"});
	    if(!this_player()->query_spell("causar heridas moderadas"))
		list += ({"causar heridas moderadas"});
	    if(!this_player()->query_spell("causar heridas ligeras"))
		list += ({"causar heridas ligeras"});
	    if(!this_player()->query_spell("palabra sagrada"))
		list += ({"palabra sagrada"});
	    if(!this_player()->query_spell("arma ardiente"))
		list += ({"arma ardiente"});
	    if(!this_player()->query_spell("inmolacion"))
		list += ({"inmolacion"});
	    if(!TP->query_spell("piel robliza"))
	    	list += ({"piel robliza"});
	    if(!this_player()->query_spell("curacion"))
		list += ({"curacion"});
	    if(!this_player()->query_spell("detectar magia"))
		list += ({"detectar magia"});
	    if(!this_player()->query_spell("disipar magia"))
		list += ({"disipar magia"});
	    if(!this_player()->query_spell("conocer alineamiento"))
		list += ({"conocer alineamiento"});
	}
	else if (guild == "paladin" || guild == "antipaladin") {
	    if(!this_player()->query_spell("bendicion"))
		list += ({"bendicion"});
	    if(!this_player()->query_spell("luz"))
		list += ({"luz"});
	    if(!this_player()->query_spell("oscuridad"))
		list += ({"oscuridad"});
	    if(!this_player()->query_spell("plegaria"))
		list += ({"plegaria"});
	    //if(!this_player()->query_spell("sanar"))
		//list += ({"sanar"});
		if (guild == "paladin") {
	    if(!this_player()->query_spell("curar heridas criticas"))
		list += ({"curar heridas criticas"});
	    if(!this_player()->query_spell("curar heridas serias"))
		list += ({"curar heridas serias"});
	    if(!this_player()->query_spell("curar heridas moderadas"))
		list += ({"curar heridas moderadas"});
	    if(!this_player()->query_spell("curar heridas ligeras"))
		list += ({"curar heridas ligeras"});
		}
		else { // antis
	    if(!this_player()->query_spell("causar heridas criticas"))
		list += ({"causar heridas criticas"});
	    if(!this_player()->query_spell("causar heridas serias"))
		list += ({"causar heridas serias"});
	    if(!this_player()->query_spell("causar heridas moderadas"))
		list += ({"causar heridas moderadas"});
	    if(!this_player()->query_spell("causar heridas ligeras"))
		list += ({"causar heridas ligeras"});
		}
	    if(!this_player()->query_spell("tormenta sagrada"))
		list += ({"tormenta sagrada"});
	    //if(!this_player()->query_spell("santuario"))
		//list += ({"santuario"});
	    if(!this_player()->query_spell("detectar magia"))
		list += ({"detectar magia"});
	    if(!this_player()->query_spell("disipar magia"))
		list += ({"disipar magia"});
	    if(!this_player()->query_spell("conocer alineamiento"))
		list += ({"conocer alineamiento"});
	// ESTE TEMPORAL
	    //if(!this_player()->query_spell("palabra sagrada"))
		//list += ({"palabra sagrada"});		
	}
	else if (guild == "mago de agband") {
/****** DE MAGO Y MG ******/
	    if(!this_player()->query_spell("luz"))
		list += ({"luz"});
	    if(!this_player()->query_spell("oscuridad"))
		list += ({"oscuridad"});
	    if(!this_player()->query_spell("detectar magia"))
		list += ({"detectar magia"});
	    if(!this_player()->query_spell("disipar magia"))
		list += ({"disipar magia"});
	    if(!this_player()->query_spell("agrandar"))
		list += ({"agrandar"});
	    //if(!this_player()->query_spell("aliento"))
		//list += ({"aliento"});
	    //if(!this_player()->query_spell("apresuramiento"))
		//list += ({"apresuramiento"});
	    if(!this_player()->query_spell("armadura"))
		list += ({"armadura"});
	    if(!this_player()->query_spell("aura espiritual"))
		list += ({"aura espiritual"});
	    if(!this_player()->query_spell("bola de fuego"))
		list += ({"bola de fuego"});
	    if(!this_player()->query_spell("cegar"))
		list += ({"cegar"});
	    if(!this_player()->query_spell("cono de frio"))
		list += ({"cono de frio"});
	    //if(!this_player()->query_spell("cuerpo de acero"))
		//list += ({"cuerpo de acero"});
	    //if(!this_player()->query_spell("debilitar"))
		//list += ({"debilitar"});
	    //if(!this_player()->query_spell("desintegrar"))
		//list += ({"desintegrar"});
	    //if(!this_player()->query_spell("disco flotante"))
		//list += ({"disco flotante"});
	    //if(!this_player()->query_spell("encantar arma"))
		//list += ({"encantar arma"});
	    if(!this_player()->query_spell("enjambre de meteoros"))
		list += ({"enjambre de meteoros"});
	    if(!this_player()->query_spell("escudo"))
		list += ({"escudo"});
	    //if(!this_player()->query_spell("escudo de fuego"))
		//list += ({"escudo de fuego"});
	    //if(!this_player()->query_spell("escudo de hielo"))
		//list += ({"escudo de hielo"});
	    if(!this_player()->query_spell("espejismo"))
		list += ({"espejismo"});
	    if(!this_player()->query_spell("estallido de fuego"))
		list += ({"estallido de fuego"});
	    //if(!this_player()->query_spell("extirpar maldicion"))
		//list += ({"extirpar maldicion"});
	    if(!this_player()->query_spell("flecha magica"))
		list += ({"flecha magica"});
	    if(!this_player()->query_spell("flecha acida"))
		list += ({"flecha acida"});
	    //if(!this_player()->query_spell("flecha de agua"))
		//list += ({"flecha de agua"});
	    if(!this_player()->query_spell("flecha de aire"))
		list += ({"flecha de aire"});
	    if(!this_player()->query_spell("flecha electrica"))
		list += ({"flecha electrica"});
	    if(!this_player()->query_spell("flecha de hielo"))
		list += ({"flecha de hielo"});
	    //if(!this_player()->query_spell("flecha de llamas"))
		//list += ({"flecha de llamas"});
	    if(!this_player()->query_spell("flecha de piedra"))
		list += ({"flecha de piedra"});
	    if(!this_player()->query_spell("flecha venenosa"))
		list += ({"flecha venenosa"});
	    if(!this_player()->query_spell("globo mayor invulnerabilidad"))
		list += ({"globo mayor invulnerabilidad"});
	    if(!this_player()->query_spell("globo menor invulnerabilidad"))
		list += ({"globo menor invulnerabilidad"});
	    if(!this_player()->query_spell("golpe de rayo"))
		list += ({"golpe de rayo"});
	    if(!this_player()->query_spell("granizo"))
		list += ({"granizo"});
	    if(!this_player()->query_spell("herrumbe"))
		list += ({"herrumbe"});
	    if(!this_player()->query_spell("horrible marchitamiento"))
		list += ({"horrible marchitamiento"});
	    //if(!this_player()->query_spell("infierno"))
		//list += ({"infierno"});
	    //if(!this_player()->query_spell("invocar ayudante"))
		//list += ({"invocar ayudante"});
	    if(!this_player()->query_spell("lentitud"))
		list += ({"lentitud"});
	    if(!this_player()->query_spell("llamarada electrica"))
		list += ({"llamarada electrica"});
	    if(!this_player()->query_spell("manos ardientes"))
		list += ({"manos ardientes"});
	    if(!this_player()->query_spell("meteoros diminutos"))
		list += ({"meteoros diminutos"});
	    //if(!this_player()->query_spell("muro ilusorio"))
		//list += ({"muro ilusorio"});
	    //if(!this_player()->query_spell("niebla letal"))
		//list += ({"niebla letal"});
	    if(!this_player()->query_spell("nube de frio"))
		list += ({"nube de frio"});
	    if(!this_player()->query_spell("nube hedionda"))
		list += ({"nube hedionda"});
	    //if(!this_player()->query_spell("ojo por ojo"))
		//list += ({"ojo por ojo"});
	    //if(!this_player()->query_spell("ola de frio"))
		//list += ({"ola de frio"});
	    if(!this_player()->query_spell("palabra poderosa aturdir"))
		list += ({"palabra poderosa aturdir"});
	    //if(!this_player()->query_spell("piel de piedra"))
		//list += ({"piel de piedra"});
	    //if(!this_player()->query_spell("portal magico"))
		//list += ({"portal magico"});
	    if(!this_player()->query_spell("presa sacudidora"))
		list += ({"presa sacudidora"});
	    //if(!this_player()->query_spell("proteccion contra armas magicas"))
		//list += ({"proteccion contra armas magicas"});
	    //if(!this_player()->query_spell("proteccion contra armas no magicas"))
		//list += ({"proteccion contra armas no magicas"});
	    if(!this_player()->query_spell("proyectil magico menor"))
		list += ({"proyectil magico menor"});
	    if(!this_player()->query_spell("proyectil magico mayor"))
		list += ({"proyectil magico mayor"});
	    if(!this_player()->query_spell("reducir"))
		list += ({"reducir"});
	    if(!this_player()->query_spell("relampago sombra"))
		list += ({"relampago sombra"});
	    if(!this_player()->query_spell("toque helado"))
		list += ({"toque helado"});
	    if(!this_player()->query_spell("toque vampirico"))
		list += ({"toque vampirico"});
	    if(!this_player()->query_spell("tormenta acida"))
		list += ({"tormenta acida"});
	    if(!this_player()->query_spell("tormenta electrica"))
		list += ({"tormenta electrica"});
	    if(!this_player()->query_spell("tormenta de hielo"))
		list += ({"tormenta de hielo"});
/***** RESISTENCIAS *****/
	    if(!this_player()->query_spell("resistencia menor acido"))
		list += ({"resistencia menor acido"});
	    if(!this_player()->query_spell("resistencia menor frio"))
		list += ({"resistencia menor frio"});
	    if(!this_player()->query_spell("resistencia menor fuego"))
		list += ({"resistencia menor fuego"});
	    if(!this_player()->query_spell("resistencia menor veneno"))
		list += ({"resistencia menor veneno"});
	    if(!this_player()->query_spell("resistencia menor agua"))
		list += ({"resistencia menor agua"});
	    if(!this_player()->query_spell("resistencia menor electrico"))
		list += ({"resistencia menor electrico"});
	    if(!this_player()->query_spell("resistencia menor enfermedad"))
		list += ({"resistencia menor enfermedad"});
	    if(!this_player()->query_spell("resistencia menor magico"))
		list += ({"resistencia menor magico"});
	    if(!this_player()->query_spell("resistencia menor mental"))
		list += ({"resistencia menor mental"});
	    if(!this_player()->query_spell("resistencia menor muerte"))
		list += ({"resistencia menor muerte"});
	    if(!this_player()->query_spell("resistencia menor proyectiles"))
		list += ({"resistencia menor proyectiles"});
	    if(!this_player()->query_spell("resistencia menor tierra"))
		list += ({"resistencia menor tierra"});
	    if(!this_player()->query_spell("resistencia menor aire"))
		list += ({"resistencia menor aire"});

	    if(!this_player()->query_spell("resistencia mayor acido"))
		list += ({"resistencia mayor acido"});
	    if(!this_player()->query_spell("resistencia mayor frio"))
		list += ({"resistencia mayor frio"});
	    if(!this_player()->query_spell("resistencia mayor fuego"))
		list += ({"resistencia mayor fuego"});
	    if(!this_player()->query_spell("resistencia mayor veneno"))
		list += ({"resistencia mayor veneno"});
	    if(!this_player()->query_spell("resistencia mayor agua"))
		list += ({"resistencia mayor agua"});
	    if(!this_player()->query_spell("resistencia mayor electrico"))
		list += ({"resistencia mayor electrico"});
	    if(!this_player()->query_spell("resistencia mayor enfermedad"))
		list += ({"resistencia mayor enfermedad"});
	    if(!this_player()->query_spell("resistencia mayor magico"))
		list += ({"resistencia mayor magico"});
	    if(!this_player()->query_spell("resistencia mayor mental"))
		list += ({"resistencia mayor mental"});
	    if(!this_player()->query_spell("resistencia mayor muerte"))
		list += ({"resistencia mayor muerte"});
	    if(!this_player()->query_spell("resistencia mayor proyectiles"))
		list += ({"resistencia mayor proyectiles"});
	    if(!this_player()->query_spell("resistencia mayor tierra"))
		list += ({"resistencia mayor tierra"});
	    if(!this_player()->query_spell("resistencia mayor aire"))
		list += ({"resistencia mayor aire"});

	    if(!this_player()->query_spell("resistir el bien"))
		list += ({"resistir el bien"});
	    if(!this_player()->query_spell("resistir el mal"))
		list += ({"resistir el mal"});
            if(!this_player()->query_spell("muro de fuego"))
                list += ({"muro de fuego"});


	}
     else if (guild == "brujo de urghak") {
        if(!this_player()->query_spell("palabra poderosa matar"))
            list += ({"palabra poderosa matar"});
        if(!this_player()->query_spell("invisibilidad"))
            list += ({"invisibilidad"});
        if(!this_player()->query_spell("inaudibilidad"))
            list += ({"inaudibilidad"});
        if(!this_player()->query_spell("palabra poderosa terremoto"))
            list += ({"palabra poderosa terremoto"});
        if(!this_player()->query_spell("animar muertos"))
            list += ({"animar muertos"});
        if(!this_player()->query_spell("causar enfermedad"))
           list += ({"causar enfermedad"});
        if(!this_player()->query_spell("drenar energia"))
           list += ({"drenar energia"});
        if(!this_player()->query_spell("fumble"))
           list += ({"fumble"});
        if(!this_player()->query_spell("horrible marchitamiento"))
           list += ({"horrible marchitamiento"});
        if(!this_player()->query_spell("toque helado"))
           list += ({"toque helado"});
        if(!this_player()->query_spell("toque vampirico"))
           list += ({"toque vampirico"});
        if(!this_player()->query_spell("withering"))
           list += ({"withering"});
        if(!this_player()->query_spell("wraithform"))
           list += ({"wraithform"});
       }
/****** MAGO GUERRERO ******/
	else if (guild == "mago guerrero") {
	    if(!this_player()->query_spell("luz"))
		list += ({"luz"});
	    if(!this_player()->query_spell("oscuridad"))
		list += ({"oscuridad"});
	    if(!this_player()->query_spell("detectar magia"))
		list += ({"detectar magia"});
	    if(!this_player()->query_spell("disipar magia"))
		list += ({"disipar magia"});
	    //if(!this_player()->query_spell("aliento"))
		//list += ({"aliento"});
	    if(!this_player()->query_spell("apresuramiento"))
		list += ({"apresuramiento"});
	    if(!this_player()->query_spell("armadura"))
		list += ({"armadura"});
	    //if(!this_player()->query_spell("cegar"))
		//list += ({"cegar"});
	    if(!this_player()->query_spell("cono de frio"))
		list += ({"cono de frio"});
	    if(!this_player()->query_spell("cuerpo de acero"))
		list += ({"cuerpo de acero"});
	    if(!this_player()->query_spell("debilitar"))
		list += ({"debilitar"});
	    if(!this_player()->query_spell("desintegrar"))
		list += ({"desintegrar"});
	    if(!this_player()->query_spell("encantar arma"))
		list += ({"encantar arma"});
	    //if(!this_player()->query_spell("escudo de fuego"))
		//list += ({"escudo de fuego"});
	    //if(!this_player()->query_spell("escudo de hielo"))
		//list += ({"escudo de hielo"});
	    if(!this_player()->query_spell("estallido de fuego"))
		list += ({"estallido de fuego"});
	    if(!this_player()->query_spell("extirpar maldicion"))
		list += ({"extirpar maldicion"});
	    if(!this_player()->query_spell("flecha magica"))
		list += ({"flecha magica"});
	    if(!this_player()->query_spell("flecha de agua"))
		list += ({"flecha de agua"});
	    if(!this_player()->query_spell("flecha de aire"))
		list += ({"flecha de aire"});
	    if(!this_player()->query_spell("flecha electrica"))
		list += ({"flecha electrica"});
	    if(!this_player()->query_spell("flecha de hielo"))
		list += ({"flecha de hielo"});
	    if(!this_player()->query_spell("flecha de llamas"))
		list += ({"flecha de llamas"});
	    if(!this_player()->query_spell("flecha de piedra"))
		list += ({"flecha de piedra"});
	    if(!this_player()->query_spell("flecha venenosa"))
		list += ({"flecha venenosa"});
	    //if(!this_player()->query_spell("globo mayor invulnerabilidad"))
		//list += ({"globo mayor invulnerabilidad"});
	    if(!this_player()->query_spell("globo menor invulnerabilidad"))
		list += ({"globo menor invulnerabilidad"});
	    if(!this_player()->query_spell("golpe de rayo"))
		list += ({"golpe de rayo"});
	    if(!this_player()->query_spell("infierno"))
		list += ({"infierno"});
	    if(!this_player()->query_spell("lentitud"))
		list += ({"lentitud"});
	    if(!this_player()->query_spell("manos ardientes"))
		list += ({"manos ardientes"});
	    if(!this_player()->query_spell("meteoros diminutos"))
		list += ({"meteoros diminutos"});
	    //if(!this_player()->query_spell("muro ilusorio"))
		//list += ({"muro ilusorio"});
	    //if(!this_player()->query_spell("niebla letal"))
		//list += ({"niebla letal"});
	    if(!this_player()->query_spell("ojo por ojo"))
		list += ({"ojo por ojo"});
	    if(!this_player()->query_spell("ola de frio"))
		list += ({"ola de frio"});
	    if(!this_player()->query_spell("piel de piedra"))
		list += ({"piel de piedra"});
	    if(!this_player()->query_spell("proteccion contra armas magicas"))
		list += ({"proteccion contra armas magicas"});
	    if(!this_player()->query_spell("proteccion contra armas no magicas"))
		list += ({"proteccion contra armas no magicas"});
	    if(!this_player()->query_spell("proyectil magico menor"))
		list += ({"proyectil magico menor"});
	    if(!this_player()->query_spell("proyectil magico mayor"))
		list += ({"proyectil magico mayor"});
	    if(!this_player()->query_spell("relampago sombra"))
		list += ({"relampago sombra"});
	    if(!this_player()->query_spell("toque helado"))
		list += ({"toque helado"});
	    if(!this_player()->query_spell("toque vampirico"))
		list += ({"toque vampirico"});

	    if(!this_player()->query_spell("resistencia menor acido"))
		list += ({"resistencia menor acido"});
	    if(!this_player()->query_spell("resistencia menor frio"))
		list += ({"resistencia menor frio"});
	    if(!this_player()->query_spell("resistencia menor fuego"))
		list += ({"resistencia menor fuego"});
	    if(!this_player()->query_spell("resistencia menor veneno"))
		list += ({"resistencia menor veneno"});
	    if(!this_player()->query_spell("resistencia menor agua"))
		list += ({"resistencia menor agua"});
	    if(!this_player()->query_spell("resistencia menor electrico"))
		list += ({"resistencia menor electrico"});
	    if(!this_player()->query_spell("resistencia menor enfermedad"))
		list += ({"resistencia menor enfermedad"});
	    if(!this_player()->query_spell("resistencia menor magico"))
		list += ({"resistencia menor magico"});
	    if(!this_player()->query_spell("resistencia menor mental"))
		list += ({"resistencia menor mental"});
	    if(!this_player()->query_spell("resistencia menor muerte"))
		list += ({"resistencia menor muerte"});
	    if(!this_player()->query_spell("resistencia menor proyectiles"))
		list += ({"resistencia menor proyectiles"});
	    if(!this_player()->query_spell("resistencia menor tierra"))
		list += ({"resistencia menor tierra"});
	    if(!this_player()->query_spell("resistencia menor aire"))
		list += ({"resistencia menor aire"});

/* MG no tienen mayores
	    if(!this_player()->query_spell("resistencia mayor acido"))
		list += ({"resistencia mayor acido"});
	    if(!this_player()->query_spell("resistencia mayor frio"))
		list += ({"resistencia mayor frio"});
	    if(!this_player()->query_spell("resistencia mayor fuego"))
		list += ({"resistencia mayor fuego"});
	    if(!this_player()->query_spell("resistencia mayor veneno"))
		list += ({"resistencia mayor veneno"});
	    if(!this_player()->query_spell("resistencia mayor agua"))
		list += ({"resistencia mayor agua"});
	    if(!this_player()->query_spell("resistencia mayor electrico"))
		list += ({"resistencia mayor electrico"});
	    if(!this_player()->query_spell("resistencia mayor enfermedad"))
		list += ({"resistencia mayor enfermedad"});
	    if(!this_player()->query_spell("resistencia mayor magico"))
		list += ({"resistencia mayor magico"});
	    if(!this_player()->query_spell("resistencia mayor mental"))
		list += ({"resistencia mayor mental"});
	    if(!this_player()->query_spell("resistencia mayor muerte"))
		list += ({"resistencia mayor muerte"});
	    if(!this_player()->query_spell("resistencia mayor proyectiles"))
		list += ({"resistencia mayor proyectiles"});
	    if(!this_player()->query_spell("resistencia mayor tierra"))
		list += ({"resistencia mayor tierra"});
	    if(!this_player()->query_spell("resistencia mayor aire"))
		list += ({"resistencia mayor aire"});

ESTOS HECHIZOS SON DE CLERIGO
	    if(!this_player()->query_spell("resistir el bien"))
		list += ({"resistir el bien"});
	    if(!this_player()->query_spell("resistir el mal"))
		list += ({"resistir el mal"});
*/
	}

/****** DE CLERIGA DROW ******/
	else if (guild == "sacerdotisa drow") { // no puesto aun xD
	    if(!this_player()->query_spell("aullido infernal"))
		list += ({"aullido infernal"});
	    if(!this_player()->query_spell("transformacion de simbolo"))
		list += ({"transformacion de simbolo"});
	    if(!this_player()->query_spell("palabra sagrada"))
		list += ({"palabra sagrada"});
	    if(!this_player()->query_spell("paralizar persona"))
		list += ({"paralizar persona"});
	}
	    break;
	}
	return list;
}

string query_spellfilename(string spell)
{
// amos a ver, tenemos 2 opciones, dar aki el path con paladin/luz
// p.e. o mejor quitar lo de la base y devolver solo el fichero, sin path
// y asi en query_spell_dir (o asi xD) del guild podemos poner algo
// asi como "/d/gremios/hechizos/paladin".
	//string BASE;
	string file;
/*	switch(this_player()->query_guild_name()) {
		case "paladin":
		case "antipaladin":
		case "Paladin":
		case "Antipaladin":
			BASE = "paladin/";
			break;
		default :
			BASE = "";
	}*/
    if (spell)
    {
	switch (spell)
	{
	case "bendicion":
		file="bendicion";
		break;
	case "luz":
		file="luz";
		break;
	case "conocer alineamiento":
		file="conocer_alineamiento";
		break;
	case "sanar":
	case "curacion":
		file="sanar";
		break;
	case "curar heridas criticas":
		file="curar_heridas_criticas";
		break;
	case "curar heridas ligeras":
		file="curar_heridas_ligeras";
		break;
	case "curar heridas moderadas":
		file="curar_heridas_moderadas";
		break;
	case "curar heridas serias":
		file="curar_heridas_serias";
		break;
	case "causar heridas criticas":
		file="causar_heridas_criticas";
		break;
	case "causar heridas ligeras":
		file="causar_heridas_ligeras";
		break;
	case "causar heridas moderadas":
		file="causar_heridas_moderadas";
		break;
	case "causar heridas serias":
		file="causar_heridas_serias";
		break;
	case "detectar magia":
		file="detectar_magia";
		break;
	case "disipar magia":
		file="disipar_magia";
		break;
	case "maldicion":
		file="maldicion";
		break;
	case "oscuridad":
		file="oscuridad";
		break;
	case "plegaria":
		file="plegaria";
		break;
	case "santuario":
	case "Santuario":
	case "sanctuary":
		file="sanctuary";
		break;
	case "tormenta sagrada":
		file="tormenta_sagrada";
		break;

/****** MAGO Y MG ******/
	case "agrandar":
		file="agrandar";
		break;
	case "aliento":
		file="aliento";
		break;
	case "apresuramiento":
		file="apresuramiento";
		break;
	case "armadura":
		file="armadura";
		break;
	case "aura espiritual":
		file="armadura_espiritu";
		break;
	case "bola de fuego":
		file="bola_fuego";
		break;
	case "cegar":
		file="cegar";
		break;
	case "cono de frio":
		file="cono_frio";
		break;
	case "cuerpo de acero":
		file="cuerpo_de_acero";
		break;
	case "debilitar":
		file="debilitar";
		break;
	case "desintegrar":
		file="desintegrar";
		break;
	case "disco flotante":
		file="disco_flotante";
		break;
	case "encantar arma":
		file="encantar_arma";
		break;
	case "enjambre de meteoros":
		file="enjambre_meteoros";
		break;
	case "escudo":
		file="escudo";
		break;
	case "escudo de fuego":
		file="escudo_fuego";
		break;
	case "escudo de hielo":
		file="escudo_hielo";
		break;
	case "espejismo":
		file="espejismo";
		break;
	case "estallido de fuego":
		file="estallido_fuego";
		break;
	case "extirpar maldicion":
		file="extirpar_maldicion";
		break;
	case "flecha magica":
		file="flecha";
		break;
	case "flecha acida":
		file="flecha_acida";
		break;
	case "flecha de agua":
		file="flecha_agua";
		break;
	case "flecha de aire":
		file="flecha_aire";
		break;
	case "flecha electrica":
		file="flecha_electrica";
		break;
	case "flecha de hielo":
		file="flecha_hielo";
		break;
	case "flecha de llamas":
		file="flecha_llamas";
		break;
	case "flecha de piedra":
		file="flecha_piedra";
		break;
	case "flecha venenosa":
		file="flecha_veneno";
		break;
	case "globo mayor invulnerabilidad":
		file="globo_mayor_invul";
		break;
	case "globo menor invulnerabilidad":
		file="globo_menor_invul";
		break;
	case "golpe de rayo":
		file="golpe_rayo";
		break;
	case "granizo":
		file="granizo";
		break;
	case "herrumbe":
		file="herrumbe";
		break;
	case "horrible marchitamiento":
		file="horrible_marchitamiento";
		break;
	case "infierno":
		file="infierno";
		break;
	case "invocar ayudante":
		file="invocar_ayudante";
		break;
	case "lentitud":
		file="lentitud";
		break;
	case "llamarada electrica":
		file="llamarada_electrica";
		break;
	case "manos ardientes":
		file="manos_ardientes";
		break;
	case "meteoros diminutos":
		file="meteoros_diminutos";
		break;
	case "muro ilusorio":
		file="muro_ilusorio";
		break;
	case "niebla letal":
		file="niebla_letal";
		break;
	case "nube de frio":
		file="nube_frio";
		break;
	case "nube hedionda":
		file="nube_hedionda";
		break;
	case "ojo por ojo":
		file="ojo_por_ojo";
		break;
	case "ola de frio":
		file="ola_frio";
		break;
	case "palabra poderosa aturdir":
		file="palabra_poderosa_aturdir";
		break;
	case "piel de piedra":
		file="piel_piedra";
		break;
	case "portal magico":
		file="portal_magico";
		break;
	case "presa sacudidora":
		file="presa_sacudidora";
		break;
	case "proteccion contra armas magicas":
		file="proteccion_contra_am";
		break;
	case "proteccion contra armas no magicas":
		file="proteccion_contra_anm";
		break;
	case "proyectil magico menor":
		file="proyectil_magico";
		break;
	case "proyectil magico mayor":
		file="proyectil_magico_mayor";
		break;
	case "reducir":
		file="reducir";
		break;
	case "relampago sombra":
		file="relampago_sombra";
		break;
	case "toque helado":
		file="toque_helado";
		break;
	case "toque vampirico":
		file="toque_vampirico";
		break;
	case "tormenta acida":
		file="tormenta_acida";
		break;
	case "tormenta electrica":
		file="tormenta_electrica";
		break;
	case "tormenta de hielo":
		file="tormenta_hielo";
		break;
	case "resistencia menor acido":
		file="res_men_acido";
		break;
	case "resistencia menor frio":
		file="res_men_frio";
		break;
	case "resistencia menor fuego":
		file="res_men_fuego";
		break;
	case "resistencia menor veneno":
		file="res_men_veneno";
		break;
	case "resistencia menor agua":
		file="res_men_agua";
		break;
	case "resistencia menor electrico":
		file="res_men_electrico";
		break;
	case "resistencia menor enfermedad":
		file="res_men_enfermedad";
		break;
	case "resistencia menor magico":
		file="res_men_magico";
		break;
	case "resistencia menor mental":
		file="res_men_mental";
		break;
	case "resistencia menor muerte":
		file="res_men_muerte";
		break;
	case "resistencia menor proyectiles":
        case "trampa de bola de fuego":
                       file="tr_fireball";
                       break;
        case "trampa de granizo":
                       file="tr_snowball";
                       break;
		file="res_men_proyectiles";
		break;
	case "resistencia menor tierra":
		file="res_men_tierra";
		break;
	case "resistencia menor aire":
		file="res_men_aire";
		break;
	case "resistencia mayor acido":
		file="res_may_acido";
		break;
	case "resistencia mayor frio":
		file="res_may_frio";
		break;
	case "resistencia mayor fuego":
		file="res_may_fuego";
		break;
	case "resistencia mayor veneno":
		file="res_may_veneno";
		break;
	case "resistencia mayor agua":
		file="res_may_agua";
		break;
	case "resistencia mayor electrico":
		file="res_may_electrico";
		break;
	case "resistencia mayor enfermedad":
		file="res_may_enfermedad";
		break;
	case "resistencia mayor magico":
		file="res_may_magico";
		break;
	case "resistencia mayor mental":
		file="res_may_mental";
		break;
	case "resistencia mayor muerte":
		file="res_may_muerte";
		break;
	case "resistencia mayor proyectiles":
		file="res_may_proyectiles";
		break;
	case "resistencia mayor tierra":
		file="res_may_tierra";
		break;
	case "resistencia mayor aire":
		file="res_may_aire";
		break;
	case "resistir el bien":
		file="resist_bien";
		break;
	case "resistir el mal":
		file="resist_mal";
		break;
        case "muro de fuego":
                file="muro_fuego";
                break;


        case "palabra poderosa matar":
                        file="palabra_poderosa_matar";
                        break;
        case "palabra poderosa terremoto":
                        file="palabra_poderosa_terremoto";
                        break;
        case "animar muertos":
                       file="animar_muertos";
                       break;
        case "causar enfermedad":
                       file="causar_enfermedad";
                       break;
        case "drenar energia":
                       file="drenar_energia";
                       break;
        case "invisibilidad":
                       file="invisibilidad";
break;
        case "inaudibilidad":
                       file="inaudibilidad";
break;
        case "fumble":
                       file="fumble";
                       break;
        case "horrible marchitamiento":
                       file="horrible_marchitamiento";
                       break;
        case "toque helado":
                       file="toque_helado";
                       break;
        case "toque vampirico":
                       file="toque_vampirico";
                       break;
        case "enjambre de meteoros sombra":
                       file="enjambre_meteoros_sombra";
                       break;
        case "wraithform":
                       file="wraithform";
                       break;
        case "detectar invisibilidad":
                file="detectar_invisibilidad";
                break;
/**** CLERIGOS */

	case "aullido infernal":
		file="demon_howl";
		break;
	case "palabra sagrada":
		file="holy_word";
		break;
	case "arma ardiente":
		file="arma_ardiente";
		break;
	case "inmolacion":
		file="inmolacion";
		break;
	case "piel robliza":
		file="piel_robliza";
		break;
	case "transformacion de simbolo":
		file="sym_spell";
		break;
	case "paralizar persona":
		file="hold_person";
		break;

	}
	//return (BASE+file);
	return file;
    } /* if (spell) */
    return 0;
} /* query_spellfilename */
