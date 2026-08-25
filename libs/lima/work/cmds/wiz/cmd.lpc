/* Do not remove the headers from this file! see /USAGE for more info. */

// Tsath@Lima, 2023

//: COMMAND
// USAGE:  cmd <monster> <command>
//
// This command will tell a monster to do something.
// It requires that the monster has do_game_command() inherited.
// Cannot be used on players/wizards.
//
// > cmd troll say Hello!
// Bill the Troll says: Hello!

inherit CMD;

private
void main(mixed *arg)
{
   if (arg[0]->is_body())
   {
      tell(arg[0],this_body()->short()+ " tried to make you '"+implode(arg[1]," ")+"' via 'cmd' command.");
      write("Cannot be used on players, use 'force' cmd.");
      return;
   }
   arg[0]->do_game_command(implode(arg[1], " "));
}
