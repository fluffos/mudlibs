inherit "/obj/weapon";

void setup() {
	set_base_weapon("dirk");
	set_weight(50);
	set_name("horca tricefala");
	set_short("Horca tricefala");
	set_long("Esta sencilla arma es usada por las patrullas que vigilan "
	         "el bosque de Urghak. De sencilla fabricacion, posee tres "
		 "afiladas puas con una ligera inclinacion para causar mayores "
                 "danyos en la carne. Su mango, envuelto en una sucia tira de "
                 "cuero, esta desgastado por el uso.\n");
	add_alias("horca");
	set_main_plural("Horcas tricefalas");
	add_plural("horcas");
	set_twohanded(0);
}

void write_message(string happen, int dam, string w_type, object me, object him)
{
	if (happen == "miss")
	{
		tell_room(ENV(me), me->QCN + " no alcanza a "+him->QCN+".\n", ({me,him}));
		tell_object(me, "# "+him->QCN+" esquiva habilmente tu ataque.\n");
		tell_object(him, "* Esquivas habilmente el ataque de "+me->QCN+".\n");
	}
	/*
	if (happen == "critical")
	{
		tell_room(ENV(me), me->QCN+" eleva con furia su "+w_type+" para descargarlo mortalmente sobre "+him->QCN+".\n",({me,him}));
		tell_object(me, "Elevas tu "+w_type+" furiosamente para descargarlo con todas tus fuerzas sobre "+him->QCN+".\n");
		tell_object(him, "Los musculos de "+me->QCN+" parecen agrandarse al elevar su "+w_type+" para descargarlo sobre ti!\n");
	}
	*/
	switch(dam) {
		case 0:
		tell_room(ENV(me), me->QCN + " roza con su "+w_type+" a "+him->QCN+" sin producirle danyo.\n", ({me,him}));
		tell_object(me, "# Golpeas a "+him->QCN+" sin producirle danyo.\n");
		tell_object(him, "* "+me->QCN+" te golpea con su "+w_type+" sin hacerte ningun rasgunyo.\n");
		break;
		case 1..6:
		tell_room(ENV(me), me->QCN + " raja la cara de "+him->QCN+" con la garra central de su horca.\n", ({me,him}));
		tell_object(me, "# Rajas la cara de "+him->QCN+" con la garra central de tu arma.\n");
		tell_object(him, "* * "+me->QCN+" te raja la cara con la garra central de su arma.\n");
		break;
		case 7..12:
		tell_room(ENV(me), me->QCN + " produce dos sangrantes cortes a "+him->QCN+".\n", ({me,him}));
		tell_object(me, "# Produces dos sangrantes cortes a "+him->QCN+".\n");
		tell_object(him, "* * "+me->QCN+" te produce dos cortes sangrientos con su arma.\n");
		break;
		case 13..19:
		tell_room(ENV(me), me->QCN + " surca la cara de "+him->QCN+" las tres garras de su horca.\n", ({me,him}));
		tell_object(me, "# Surcas la cara de "+him->QCN+" con las tres garras de tu horca.\n");
		tell_object(him, "* * "+me->QCN+" Te deja tres surcos en la cara al darte de lleno con su horca.\n");
		break;
		case 20..39:
		tell_room(ENV(me), me->QCN + " clava su arma en el muslo de "+him->QCN+" dejandoselo dolorido.\n", ({me,him}));
		tell_object(me, "# clavas severamente en el dolorido muslo de "+him->QCN+" las tres garras de tu horca.\n");
		tell_object(him, "* * "+me->QCN+" hunde las tres garras de su horca en tu malherido muslo.\n");
		break;
		case 40..70:
		tell_room(ENV(me), "Cierras los ojos cuando "+me->QCN + " perfora el cuello de "+him->QCN+" y la sangre salpica tu cara.\n", ({me,him}));
		tell_object(me, "# Tu "+w_type+" se hunde en el cuello de "+him->QCN+" salpicandolo todo de sangre.\n");
		tell_object(him, "* * Un agudo dolor recorre tu cuerpo cuando "+me->QCN+" hunde su horca en tu cuello.\n");
		break;
		case 71..90:
		tell_room(ENV(me), me->QCN+" empala el bajo vientre de "+him->QCN+" con un magnifico golpe.\n", ({me,him}));
		tell_object(me, "# Con un magnifico golpe, empalas el bajo vientre de "+him->QCN+", llenando tu arma de visceras.\n");
		tell_object(him, "* * Gritas de dolor cuando tu vientre es salvajemente empalado por la horca de "+me->QCN+".\n");
		break;
		default:
		tell_room(ENV(me), "Realizas una mueca de disgusto cuando ves como "+me->QCN+" arranca parte de la cara de "+him->QCN+" con las garras de su horca!.\n", ({me,him}));
		tell_object(me, "# Tu horca se lleva por delante parte del rostro de "+him->QCN+", que sufre dolorosos y violentos espasmos!.\n");
		tell_object(him, "* * Tus organos faciales son salvajemente arrancados por la horca de "+me->QCN+"!.\n");
	}
}
