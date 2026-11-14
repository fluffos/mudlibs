
#define NOTIFY_PLAYER_DEAD						\
NotifyPlayerDeath(player)						\
{	object ob, geier;						\
									\
	tell_room(environment(TO), BS("Kaum ist "+player->name(WER)+" verendet, kommt von "	\
	+"oben ein Aasgeier heruntergestuerzt und schnappt sich die Leiche "	\
	+"und alle Habseligkeiten!\n"));				\
	geier = clone_object(NPC+"aasgeier");				\
	geier->move(environment(TO), M_GO);				\
	ob = present("leiche",environment(TO));				\
	if(objectp(ob)) ob->remove();					\
	//geier->command("iss leiche");					\
	geier->command("nimm alles");					\
	return 1;							\
}
