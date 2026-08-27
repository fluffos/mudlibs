//#pragma save_binary

// The standard social guild token
// Due to variant of all the social guilds, this file supplys only default functions
// Created by Kyoko 4-7-94

object owner;
string social_class_name;

void create()
{
	this_object()->set( "prevent_drop", 1 );
	this_object()->set( "prevent_get", 1 );
	this_object()->set( "prevent_insert", 1 );
}

init()
{
	object obj;

	// Update the old owner
	if( owner && living(owner) ) {
		owner->delete( "social_guilds/"+social_class_name );
		this_object()->unapply_stat();
	}
	owner = environment( this_object() );
	if( living(owner) ) {
		// Destruct old guild token if exists.
		owner->set("social_guilds/"+social_class_name, this_object() );
		this_object()->apply_stat();
	}
	else this_object()->remove();
}

// Define this function to enable this object be auto-loaded when a player
// login. 
int query_auto_load()
{
	return 1;
}

void set_social_class_name(string arg)
{
	social_class_name = arg;
}

object get_owner()
{
	return owner;
}
