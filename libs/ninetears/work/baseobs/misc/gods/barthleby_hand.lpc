// bug corregido, unwear_ob en lugar de unhold_ob, aunque
// se supone que ya deberia estar todo envainado o quitado...
// llamado desde death.c despues de los death para raza y guild
void on_death(object myp, object killed_by)
{
	// TP es el killer, remember
	// keremos solucionar somewhat lo de ke alguien entierre esto
	// y ke no haya mas ke uno y tal XD
	int i, done=0;
	object *ob;

	ob = all_inventory(myp);
	for(i=0;i < sizeof(ob);i++) {
		// atension: tiene q ser iwal q el set_name() del objeto
		if (ob[i]->query_name() == "brazalete de Barthleby") {
			if (!done)
				tell_object(myp, "Al liberarse tu alma, Barthleby reclama su objeto sagrado para si.\n");
			myp->unwear_ob(ob[i]);
			ob[i]->dest_me();
			done = 1;
		}
	}
	myp->remove_property("barthleby_sagrado");
	return;
}
