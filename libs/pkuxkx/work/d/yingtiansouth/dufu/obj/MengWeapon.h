int Consume()
{
	if (!environment())
	return 0;
	if (this_object()->query("consumed")>3)
	{
		tell_object(environment(),this_object()->query("name")+"磨损严重，终于报废了。\n");
		destruct(this_object());
	}
	else
	{
		this_object()->add("consumed",1);
		remove_call_out("Consume");
		call_out("Consume",20);
	}
	return 1;
}

