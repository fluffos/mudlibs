void kill_ob(object who)
{
	who->remove_killer(this_object());
	this_object()->remove_killer(who);
	tell_object(who,name()+"冷冷的看着你。\n");
	return;
}

int accept_fight(object who)
{
	return 0;
}

void die()
{
	powerup(0,1);
	if( environment() )
	{
		all_inventory(environment())->remove_killer(this_object());
		this_object()->remove_all_killer();
	}
	say("\n\n"+name()+"捻须一笑：呵呵，天庭点卯。\n\n");
	return;
}

void unconcious()
{
	die();
}