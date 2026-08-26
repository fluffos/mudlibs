inherit CMD;

#define WIDTH this_user()->query_screen_width()

void show_help();

private void main(string arg)
{
   mapping areas = MORGUE_D->get_areas();

   string domain;
   string room;

   if (!arg)
   {
      if (sizeof(areas))
      {
         outf("A player who dies here would end up at %s", MORGUE_D->query_morgue(file_name(environment(this_body()))));
      }
      else { out("There are no morgue areas set.\n"); }

      return;
   }
   else if (sscanf(arg, "add %s %s", domain, room) == 2)
   {
      if ((strlen(domain) >= 2) && (strlen(room) > 3))
      {
         MORGUE_D->add_area(domain, room);

         if (areas[domain])
         {
            out("Morgue room updated for " + domain + "\n");
         }
         else
         {
            out("Morgue room added for " + domain + "\n");
         }
      }
      else
      {
         out("Invalid domain or room.\n");
      }
   }
   else if (sscanf(arg, "remove %s", domain) == 1)
   {
      if ((strlen(domain) > 2) && areas[domain])
      {
         MORGUE_D->remove_area(domain);

         out("Morgue room removed for " + domain + "\n");
      }
   }
   else if (arg == "list")
   {
      if (sizeof(areas))
      {
         outf("%-35s  %-43s", "Domain", "Area");
         out(repeat_string("-", (WIDTH - 1)) + "\n");

         if (adminp(this_body()))
         {
            foreach (string directory in sort_array(keys(areas), 1))
            {
               outf("%-35s  %-" + (WIDTH - 37) + "s\n", directory[0..35], areas[directory]);
            }
         }
         else
         {
            foreach (string directory in sort_array(keys(areas), 1))
            {
               SECURE_D->query_domain_members("admin");

               outf("%-35s  %-" + (WIDTH - 37) + "s\n", directory[0..35], areas[directory]);
            }
         }
      }
      else { out("There are no morgue areas set.\n"); }

      return;
   }
   else if (arg == "help")
   {
      show_help();

      return;
   }
}

void show_help()
{
   out("Usage: morgue                      - Show the location where a player would end up if they died in the current room.\n");
   out("       morgue add <domain> <room>  - Add or update a morgue for one of your domains.\n");
   out("       morgue remove <domain>      - Remove a morgue from one of your domains.\n");
   out("       morgue list                 - List all morgues, sorted by domain.\n");
   out("       morgue help                 - Show this info.\n");
}