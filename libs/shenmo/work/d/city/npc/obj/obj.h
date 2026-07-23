//AddBySnowtu
//防止掉在地上的东西太多...

void dismiss(object ob)
{
message_vision("一阵风吹过，$N被吹走了。\n",ob);
destruct(ob);
return;
}

void check_owner()
{
object ob=this_object();
object who = environment(ob);
if ( !living(who) )
	call_out("dismiss",15+random(10),ob);
return;
}

void init()
{
check_owner();
}

