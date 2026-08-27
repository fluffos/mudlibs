// RECOMPENSA POR MATAR A DRAKULL

#define SLICERDROW "guerrero drow"
#define SLICERELFO "guerrero elfo"
#define SLICE_CMD  "slice"

void do_recompensa(object env, object ob)
{
	if (ob != TP) {
		tell_object(TP, "Se ha producido un error, avisa a un inmortal.\n");
		return;
	}
	if (ob->query_dead())
		return;
	if (ob->query_guild_name() != SLICERDROW &&
		ob->query_guild_name() != SLICERELFO)
		return;
	if (!ob->query_property("emote")) {
		ob->add_property("emote",1);
		tell_object(ob, "Aprendes a mostrar emociones.\n");
		tell_room(ENV(ob), ob->QCN+" aprende a mostrar sus emociones.\n", ob);
	}
	return;
	//if (member_array(SLICE_CMD, ob->query_known_commands()) != -1)
	//	return;
	call_out("do_rec", 4, env, ob);
}

void do_rec(object env, object ob)
{
	tell_object(TP, "\nTe has fijado en Drakull cuando le has dado la estocada final.\n"
	"Sin duda su mirada penetrante ha hecho mella en ti.\n"
	"Su rapidez con las armas te ha impresionado, su potencia mortal tambien.\n");
	tell_room(ENV(TP), TP->QCN + " se queda pensativo por un momento.\n", ob);
	call_out("do_rec0", 6, env, ob);
}

void do_rec0(object env, object ob)
{
	tell_object(ob, "Recuerdas como movia las armas... recuerdas...\n");
	if (ob->query_level() < 20) {
		tell_object(ob, "\nAl final, no le das mas importancia al asunto.\n");
		tell_room(ENV(ob), ob->QCN + " parece salir al fin de su asombro sin darle mayor importancia.\n");
		return;
	}
	tell_object(ob, "\nConsigues darte cuenta del secreto de tanta rapidez,\n"
		"y decides usar esa mortal combinacion de golpes en el futuro.\n");
	tell_room(ENV(ob), ob->QCN + " esboza una amplia sonrisa demoniaca, parece que ha cambiado algo en el.\n", ob);
	ob->add_known_command(SLICE_CMD);
	return;
}
