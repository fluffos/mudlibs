# 1 "room/death/death_mark.c" 







init()
{

	start_death();

}





get()
{
	return 1;
}





id(str) 
{ 

	return str == "death_mark"; 

}





start_death()
{
	
	object ned, my_host;

	my_host = environment(this_object());

	if (my_host)
	{
		if(living(my_host))
		{
			if(my_host->query_ghost() != 1)
			{
				destruct(this_object());
				return;
			}
		}
		else
			return;
	}
	else
		return;

	say("You see a dark shape gathering some mist... or maybe you're just imagining that.\n");
	write("You can see a dark hooded man standing beside your corpse.\n" +
		"He is wiping the bloody blade of a wicked looking scythe with slow measured\n" +
		"motions. Suddenly he stops and seems to look straight at you with his empty...\n" +
		"no, not empty but.... orbs....\n\n");

	write("Death says: COME WITH ME, MORTAL ONE!\n\n");

	write("He reaches for you and suddenly you find yourself in another place.\n\n");
	move_object(my_host, "/room/death/death_room");

}





query_auto_load()
{

	return "room/death/death_mark:";

}





drop()
{
	return 1;
}
