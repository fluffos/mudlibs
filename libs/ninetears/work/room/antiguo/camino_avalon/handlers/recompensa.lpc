// RECOMPENSA POR MATAR AL OGRO
// NO ES NECESARIO USARLO, PERO SIRVE COMO EJEMPLO

#define OBJETO  "/room/camino_avalon/objs/piel_ogro"
//#define OBJETO  "/room/camino_avalon/objs/brazalete_ogro"
object objeto;

void do_recompensa(object env, object ob)
{
	if (ob != TP) {
		tell_object(TP, "Se ha producido un error, avisa a un inmortal.\n");
		return;
	}
	if (ob->query_dead())
		return;
	tell_object(ob, "Arrancas un trozo de la piel del Ogro como trofeo.\n");
	tell_room(ENV(ob), ob->QCN+" arranca un trozo de la piel del Ogro y se la guarda como trofeo.\n", ob);
	objeto = clone_object(OBJETO);
	objeto->move(ob);
	objeto->add_property("duenyo", ob->QCN);
	return;
}
