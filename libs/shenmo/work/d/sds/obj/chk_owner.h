void dismiss(object ob)
{
if ( !ob ) return;
destruct(ob);
return;
}

void check_owner()
{
object ob = this_object();
object me = environment(ob);
if ( !interactive(me) || me->query("sds2/phix")!="done" )
	call_out("dismiss",3+random(7),ob);
}

void init()
{
  check_owner();
}

int query_autoload() { return 1; }

