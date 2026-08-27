// llamado desde death.c despues de los death para raza y guild
void on_death(object myp, object killed_by)
{
	// keremos solucionar somewhat lo de ke alguien entierre esto
	// y ke no haya mas ke uno y tal XD
	int i, done=0;
	object *ob;

	ob = all_inventory(myp);
	for(i=0;i < sizeof(ob);i++) {
		if (ob[i]->query_name() == "espada mortifera") {
			if (!done)
				tell_object(myp, "Al morirte, Tyrael reclama su objeto sagrado, tal vez un perdedor no lo merezca.\n");
			myp->unhold_ob(ob[i]); // aki es asi pq es espada
			ob[i]->dest_me();
			done = 1;
		}
	}
	myp->remove_property("tyrael_sagrado");
	return;
}
