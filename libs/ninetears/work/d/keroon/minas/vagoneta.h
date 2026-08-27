#define NPCSMINAS "/d/keroon/minas/npcs/"
#define ITEMSMINAS "/d/keroon/minas/items/"
#define MINAS "/d/keroon/minas/"

void event_enter(object enterer, string message, object donde)
{
	string mess;
	int danyo;
	if (!living(enterer))
		return;
//	if (enterer->query_race() != "drow")
	 {
		if (random(2) && random(enterer->query_dex()) < 12) {
			mess = "Una vagoneta aparece a toda velocidad de la nada tirada por varios mineros, ";
			danyo = random(11) + 5;
			switch(danyo) {
			case 5..7:
				mess += "provocandote un ligero golpe";
				break;
			case 8..10:
				mess += "causandote un moraton en el pecho";
				break;
			case 11..13:
				mess += "lanzandote fuera de su camino";
				break;
			default:
				mess += "destrozandote el pie al pasar por encima";
			}
			if (danyo > 13 || random(enterer->query_wis()) < 12) {
				mess += " y no puedes evitar gritar de dolor.\n";
				tell_object(enterer, mess);
				tell_room(TO, enterer->QCN + " grita agonicamente cuando algo le golpea.\n", enterer);
				if (enterer->query_hidden())
					enterer->dest_hide_shadow();
			}
			else {
				mess += ".\n";
				tell_object(enterer, mess);
				if (!enterer->query_hidden())
					tell_room(TO, enterer->QCN + " es golpeado por algo que no habia advertido.\n", enterer);
			}
			enterer->really_adjust_hp(-danyo);
		}
	}
	//::event_enter(enterer, message, donde);
	// no existe ::event_enter al menos en rooms
}
