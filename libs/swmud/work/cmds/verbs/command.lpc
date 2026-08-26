inherit VERB_OB;

void do_command_liv_to_str(object living, string str)
{
   living->do_command(this_body(), str);
}

void do_command_liv_str(object living, string str)
{
   do_command_liv_to_str(living, str);
}

void do_command_liv(object living)
{
   write("Command " + living->short() + " to do what?\n");
}

void do_command()
{
   write("Command whom?\n");
}

mixed can_command_liv_to_str()
{
   return 1;
}

mixed can_command_liv_str()
{
   return 1;
}

mixed can_command_liv()
{
   return 1;
}

mixed can_command()
{
   return 1;
}

void create()
{
   add_rules( ({ "", "LIV", "LIV to STR", "LIV STR" }) );
}