/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
//$$ see: color, colours, mode, frames
// USAGE emoji
//      emoji on
//      emoji off
//      emoji list
//
// Typing "emoji" will show if your character is set to ascii like graphics
// from the mud (used for small charts etc). These can be hard to use on
// screen readers, so if you are using a screen reader it can be recommended
// to be 'emoji off'.
//
// Use 'emoji list' for a list of supported emojis.

inherit CMD;
inherit M_WIDGETS;

private
void main(string arg)
{
   if (!arg)
   {
      string simplestate;
      if (i_emoji())
         simplestate = "%^GREEN%^on%^RESET%^";
      else
         simplestate = "%^RED%^off%^RESET%^";

      out("Emojis are " + simplestate + ". " + "Remember to set your client to support unicode.\n" +
          "Use 'emoji list' to see which are supported.\n");
      return;
   }

   if (arg == "on")
   {
      this_user()->query_shell_ob()->set_variable("emoji", 1);
      out("Turning emojis on 🤩. Remember to set your client to support unicode.\n");
   }
   else if (arg == "off")
   {
      this_user()->query_shell_ob()->unset_variable("emoji");
      out("Turning emojis off.\n");
   }
   else if (arg == "list")
   {
      mapping emojis = EMOJI_D->get_emoji_data();

      if (!sizeof(keys(emojis)))
      {
         write("There are no emojis.\n");
      }
      else
      {
         printf("%%^BOLD%%^%-30s %10|s %-10s%%^RESET%%^", "Emoji", "Unicode", "Replacement\n");
         foreach (string key, string * arr in emojis)
         {
            printf("%-30s %10|s %-10s\n", key, arr[0], implode(explode(arr[1],""),"<res>"));
         }
         printf("\n");
      }
   }
   else
   {
      out("Usage: emoji <on/off/list>.\n");
      return;
   }
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}