/*
*************************************************************************
** 									*
** NOTIFY_PLAYER_DEAD 	->	Aasgeier raubt Spieler aus		*
** TARNUNG			->	ob NPCs attack sind		*
**									*
** date: 01-12-97		(c) Sargola@Silberland			*
*************************************************************************
**
**
*/

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


#define TARNUNG								\
	if(present("\ndreck", TP) || present("\ndumhang",TP) )		\
	{								\
	   if(random(5)==1)						\
	   {								\
		tell_object(TP, "Du wirst trotz der Tarnung erkannt!\n");	\
		TO->Kill(TP);						\
		return 1;						\
	   }								\
	   else								\
	   {								\
		tell_object(TP, "Durch Deine Tarnung erkennt man Dich nicht.\n");	\
		return 1;						\
	   }								\
	}								\
									\
	TO->Kill(TP);							\
	return 1;							

