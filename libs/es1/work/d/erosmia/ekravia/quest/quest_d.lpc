/*
	QUEST_D: for general quest making
	written by EGA in 5/4 1995
*/

inherit DAEMON;

void	init_quest();
void	add_scene( string scene_name, string func_name );
void	switch_scene( int scene );
void	signal(string signal);
void	set_flag( string key, mixed value );
void	add_flag( string key, mixed value );
void	delete_flag( string key );
mixed	query_flag( string key );


string	current_scene;
mapping	flags;
mapping	scene_func;

void	init_quest()
{
}

void	add_scene( string scene_name, string func_name )
{
	scene_func[scene_name] = func_name;
}

void	switch_scene( string scene_name )
{
	current_scene = scene_name;
}

void	signal(string signal)
{
	if (!signal)	return;
	call_other(this_object(), scene_func[current_scene], signal);
}

void	set_flag( string key, mixed value )
{
	flags[key] = value;
}

void	add_flag( string key, mixed value )
{
	if (!undefinedp(flags[key]))
		flags[key] += value;
	else
		flags[key] = value;
}

void	delete_flag( string key )
{
	map_delete( flags, key);
}

mixed	query_flag( string key )
{
	return flags[key];
}
