void create()
{
object me;
me=this_player();
write("\n"+sort_string(environment(me)->query("long"),20,10));
}
