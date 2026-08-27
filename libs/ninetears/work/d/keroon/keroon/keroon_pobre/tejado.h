// #define KEROON "/d/keroon/keroon/keroon_pobre"
void event_enter(object enterer, string message, object donde)
{
	string mess;
	int danyo;
	if (!living(enterer))
		return;

	 {
		if (random(2) && random(enterer->query_dex() + 2*(enterer->query_level())) < 90) {
			mess = "Resbalas del tejado y caes rodando hasta aterrizar en las forjas ";
			danyo = random(175) + 25;
			switch(danyo) {
			case 25..50:
				mess += "provocandote grandes moratones";
				TP->move(FORJAS+"keroon_386.lpc");
		
				break;
				
			case 51..100:
				mess += "rompiendote un brazo";
				TP->move(FORJAS+"keroon_386.lpc");
		
				break;
				
			case 101..150:
				mess += "rompiendote una pierna";
				TP->move(FORJAS+"keroon_386.lpc");
				
				break;
				
			case 151..190:
				mess += "rompiendote una pierna y un brazo";
				TP->move(FORJAS+"keroon_386.lpc");
			
			break;
			
			default:
				mess += "destrozandote la cabeza en la caida";
			}
			
			if (danyo > 191) {
				TP->move(FORJAS+"keroon_386.lpc");
				TP->set_hp(-1);
				mess += " sin poder evitar matarte.\n";
				TP->do_death();
				
				tell_object(enterer, mess);
				tell_room(TO, enterer->QCN + " grita agonicamente cuando se golpea con el suelo.\n", enterer);
				if (enterer->query_hidden())
					enterer->dest_hide_shadow();
			}
			else {
				mess += ".\n";
				tell_object(enterer, mess);
				if (!enterer->query_hidden())
					tell_room(TO, enterer->QCN + " se golpea al caerse del tejado.\n", enterer);
			}
			enterer->really_adjust_hp(-danyo);
		  
		}
	
	}
	
}
