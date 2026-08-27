void event_enter(object enterer, string message, object donde)
{
	string mess;
	int danyo;
	if (!enterer || !living(enterer))
		return;
	if (enterer->query_race() != "drow") {
		if (random(2) && random(enterer->query_dex()) < 12) {
			mess = "Tu desconocimiento de esta zona provoca que te pinches con algo que hay en el suelo, ";
			danyo = random(11) + 5;
			switch(danyo) {
			case 5..7:
				mess += "provocandote un pequenyo pinchazo";
				break;
			case 8..10:
				mess += "clavandose en tu pie como una cuchilla";
				break;
			case 11..13:
				mess += "haciendote un profundo corte en el pie";
				break;
			default:
				mess += "desgarrandote el pie... duele!!";
			}
			if (danyo > 13 || random(enterer->query_wis()) < 12) {
				mess += " y no puedes evitar gritar de dolor.\n";
				tell_object(enterer, mess);
				tell_room(TO, enterer->QCN + " grita agonicamente al pincharse con algo.\n", enterer);
				if (enterer->query_hidden())
					enterer->dest_hide_shadow();
			}
			else {
				mess += ".\n";
				tell_object(enterer, mess);
				if (!enterer->query_hidden())
					tell_room(TO, enterer->QCN + " se pincha con algo que no habia advertido.\n", enterer);
			}
			enterer->really_adjust_hp(-danyo);
		}
	}
	//::event_enter(enterer, message, donde);
	// no existe ::event_enter al menos en rooms
}
