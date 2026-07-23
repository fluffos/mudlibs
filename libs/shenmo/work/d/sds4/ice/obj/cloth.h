void dismiss(object ob)
{
if ( !ob ) return;
write(ob->name()+"闪了几闪，化作一道光芒往天空飞去。\n");
destruct(ob);
return;
}

void check_owner()
{
object ob = this_object();
object me = environment(ob);
if ( interactive(me) )
	call_out("dismiss",1+random(2),ob);
}

void init()
{
check_owner();
}


