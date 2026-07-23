void dismiss(object ob)
{
if ( !ob ) return;
write(HIG+this_object()->name()+HIG"闪了几闪，化作一道光芒往天空飞去。\n"NOR);
destruct(ob);
}

void check_owner()
{
if ( userp(environment(this_object())) )
      call_out("dismiss",1+random(2),this_object());
}

void init()
{
check_owner();
}

