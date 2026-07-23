
void check_owner()
{
object me = this_player();
object ob = this_object();
string name = ob->query("name");

if ( userp(me) )
	{
	message_vision(HIB"\n天空乌云密布，呼的伸出一只大手，将"NOR+name+HIB"一把抓去！\n"NOR);
	destruct(ob);
	}
return;
}

void init()
{
check_owner();
}

