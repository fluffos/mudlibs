// Licenciado bajo los terminos de la GNU General Public License
// Espada Mortifera - (c) Tyrael, Septiembre '01
// REFORMAR para usar happen y calcular_critico()

inherit "/obj/weapon";

#define GOD_HAND "/obj/handlers/god_handler"

int enfurecida = 1;

void setup() {
	set_base_weapon("bastard sword");
	//set_name("Espada %^BOLD%^%^BLACK%^Mortifera%^RESET%^");
	set_name("espada mortifera");
	// el set name no se usa con colores normalmente, pero aparece si se
	// usan mensajes de hostias con el nombre de la arma
	set_short("Espada %^BOLD%^%^BLACK%^Mortifera%^RESET%^");
	set_long("Es el regalo del Dios del Mal, Tyrael, a su sumo "
	         "sacerdote. Es pequenya, pero muy precisa.\n");
	add_alias(({"espada", "mortifera"}));
	set_main_plural("Espadas %^BOLD%^%^BLACK%^Mortiferas%^RESET%^");
	add_plural("espadas");
	//add_adjective("mortifera");
	set_twohanded(0);
	set_enchant(2);
	reset_drop();
	add_property("nosteal", 1);
//	add_property("guild", {"warrior", "paladin"});
}

/* BUG, cuando el ke la lleva palma, this_player es el asesino y le sale a
el el msg... */
/* Workaround: ponemos propiedad estatica en la hacha con el nombre
	del ke la empunya. */
/* BUG, el desarmar no esta en juego hasta conseguir que al desarmar
   esta arma, se quite del array de armas empunyadas del tio */
int set_in_use(int i, object amo)
{
	if (i) {
        // seguimos siendo el sumo?
	// sale 2 veces el mensaje dunno wai (parece q solo al equip)
		if (!GOD_HAND->query_high_priest("tyrael") ||
		GOD_HAND->query_high_priest("tyrael")[0] != amo->query_name()) {
			tell_object(amo, "Tu "+query_short()+" se disuelve en la nada al no reconocerte como su duenyo.\n");
			notify_fail("");
			amo->remove_property("tyrael_sagrado");
                        call_out("dest_me", 0, 0);
                        return 0; // no se pone!
 		}
		tell_object(amo,
		"Sonries maliciosamente, sabes que Tyrael te dara fuerzas para acabar con tus enemigos.\n");
		tell_room(ENV(amo), amo->QCN+" sonrie maliciosamente.\n", amo);
		/* por si acaso */
		remove_static_property("duenyo");
		add_static_property("duenyo", amo->query_cap_name());
	}
	else
	{
		remove_static_property("duenyo");
	}
	return ::set_in_use(i);
}

int query_damage_roll()
{
	/* cambiar lo de enfurecida q ta chapucero */
	if (random(100) < 4)
		enfurecida = 2;
	if (TP->query_guild_name() == "guerrero drow")
		return (::query_damage_roll() + random(6) + random(3)) * enfurecida;
	if (TP->query_guild_name() == "asesino" && TP->query_spell_effect("emboscando"))
		return 14 + random(3);
	return (::query_damage_roll() + random(16) + 5) * ((enfurecida == 2) ? 3 : 1);
}

void event_ambush(int danio, object me, object him)
{
	if (danio > him->query_hp()) {  // dies
		tell_room(ENV(me), "La "+TO->query_name()+" de "+me->QCN+" grita: "
		"MUEEREEEEE !!\n", ({me}));
		tell_object(me, "Tu "+TO->query_name()+" grita: MUEEREEEEE !!\n");
	}
	return;
}
/*
mixed *calcular_critico(int danio, object me, object him)
{
	tell_object(me, "calculando critico\n");
	tell_object(TP, "calculando critico\n");
	return ({danio*2, "critical",});
}
*/
void write_message(string happen, int dam, string w_type, object me, object him)
{
	if (enfurecida == 2) {
		enfurecida = 1;
		tell_room(ENV(me), "La "+w_type+" de "+me->QCN + " grita: "+upper_case(him->QCN)+", TU VIDA ES MIA !!\n", me);
		tell_object(me, "Notas dolor cuando tu arma grita: "+upper_case(him->QCN)+", TU VIDA ES MIA !!\n");
		me->really_adjust_hp(-random(8)+1);
	}
	switch(dam) {
		case 0:
		tell_room(ENV(me), me->QCN + " impacta lascivamente con su "+w_type+" sobre la armadura de "+him->QCN+".\n", ({me,him}));
		tell_object(me, "Empotras lascivamente tu "+w_type+" contra la armadura de "+him->QCN+" sin producirle danyo.\n");
		tell_object(him, me->QCN+" empotra lascivamente su "+w_type+" contra tu armadura.\n");
		break;
		case 1..8:
		tell_room(ENV(me), me->QCN + " produce un cortecillo sobre la piel de "+him->QCN+" con su "+w_type+".\n", ({me,him}));
		tell_object(me, "Produces un pequenyo corte a "+him->QCN+" con tu "+w_type+".\n");
		tell_object(him, me->QCN+" te produce un pequenyo cortecillo con su "+w_type+".\n");
		break;
		case 9..15:
		tell_room(ENV(me), me->QCN + " raja el antebrazo de "+him->QCN+" con su "+w_type+", dejando un color negro en la herida.\n", ({me,him}));
		tell_object(me, "Rajas el antebrazo de "+him->QCN+" con tu "+w_type+".\n");
		tell_object(him, me->QCN+" te raja el antebrazo con su "+w_type+".\n");
		break;
		case 16..23:
		tell_room(ENV(me), "La "+w_type+" de "+me->QCN + " corta la carne de "+him->QCN+" con un armonico tajo limpio.\n", ({me,him}));
		tell_object(me, "Con un armonico movimiento, tu "+w_type+" corta la carne de "+him->QCN+" de un tajo limpio.\n");
		tell_object(him, me->QCN+" se mueve armonicamente y te corta la carne de un tajo limpio.\n");
		break;
		case 24..30:
		tell_room(ENV(me), me->QCN + " entierra su "+w_type+" en la carne de "+him->QCN+" destrozando organos vitales.\n", ({me,him}));
		tell_object(me, "Entierras tu "+w_type+" en la carne de "+him->QCN+" destrozando organos vitales.\n");
		tell_object(him, me->QCN+" entierra su "+w_type+" en tu carne destrozandote organos vitales.\n");
		break;
		case 31..40:
		tell_room(ENV(me), "La "+w_type+" de "+me->QCN + " penetra el cuerpo de "+him->QCN+" desgarrando carne y rompiendo huesos.\n", ({me,him}));
		tell_object(me, "Tu "+w_type+" penetra el cuerpo de "+him->QCN+" desgarrando la carne y rompiendo sus huesos.\n");
		tell_object(him, "La "+w_type+" de "+me->QCN+" parece cobrar vida al penetrar en ti desgarrandote la carne y rompiendote los huesos.\n");
		break;
		case 41..52:
		tell_room(ENV(me), "Te pringas de %^RED%^sangre %^RESET%^cuando "+me->QCN+" abre el cuello de "+him->QCN+" deslizando su "+w_type+" de un lado al otro.\n", ({me,him}));
		tell_object(me, "Tu "+w_type+" se tinye de %^RED%^rojo %^RESET%^cuando abres brutalmente el cuello de "+him->QCN+" de un lado al otro.\n");
		tell_object(him, "Tu %^RED%^sangre %^RESET%^sale a borbotones de tus yugulares cuando "+me->QCN+" te abre el cuello con su "+w_type+".\n");
		break;
		case 53..90:
		tell_room(ENV(me), "Las %^ORANGE%^visceras %^RESET%^de "+him->QCN+" vuelan por los aires cuando la "+w_type+" de "+me->QCN+" bate sus entranyas girando en su interior.\n", ({me,him}));
		tell_object(me, "Las %^ORANGE%^visceras %^RESET%^de "+him->QCN+" vuelan sobre ti cuando haces girar tu "+w_type+" en su interior.\n");
		tell_object(him, "Sientes un vacio en tu interior al ver tus %^BOLD%^%^ORANGE%^visceras %^RESET%^saliendo a presion de tu cuerpo gracias al batido que "+me->QCN+" hace con su "+w_type+".\n");
		break;
		default:
		tell_room(ENV(me), "Las %^ORANGE%^visceras %^RED%^ensangrentadas %^RESET%^y las costillas de "+him->QCN+" se desploman cuando "+me->QCN+" abre en canal su abdomen y torax.\n", ({me,him}));
		tell_object(me, "Abres brutalmente en canal a "+him->QCN+" viendo como se desploman sus %^ORANGE%^visceras %^RED%^ensangrentadas %^RESET%^y sus costillas al son del crujir de sus huesos.\n");
		tell_object(him, "La vista se te nubla y sientes tu cuerpo separado de tu alma cuando "+me->QCN+" te abre en canal de forma brutal.\n");
	}
}
