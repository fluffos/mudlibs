
inherit NPC;
inherit __DIR__"join";

void join( object ob )
{
	ob->add_team_member( this_object() );
	this_object()->set_leader( ob );
	this_object()->set_temp("leader",ob);
	if( ob->is_fighting() ) this_object()->join_fight( ob );
}
void die()
{
	object ob = this_object()->query_leader();
	if( !ob ) ::die();
	ob->add_temp("call_out_beast",-1);
	ob->dismiss_team( this_object() );
	::die();
}
