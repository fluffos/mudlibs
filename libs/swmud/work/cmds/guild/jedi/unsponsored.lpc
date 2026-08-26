inherit CMD;

void main(string player_name)
{
   mapping unsponsored = JEDI_SPONSOR_D->query_unsponsored(this_body()->query_userid());

   if (sizeof(unsponsored))
   {
      foreach (string unsponsored_name in keys(unsponsored))
      {
         string elapsed_time = convert_time((time() - unsponsored[unsponsored_name]) / 86400 * 86400);

         if (!strlen(elapsed_time)) { elapsed_time = convert_time((time() - unsponsored[unsponsored_name]) / 3600 * 3600); }
         if (!strlen(elapsed_time)) { elapsed_time = convert_time((time() - unsponsored[unsponsored_name]) / 60 * 60); }
         if (!strlen(elapsed_time)) { elapsed_time = convert_time((time() - unsponsored[unsponsored_name])); }

         outf("You unsponsored %s on %s (%s ago).\n", capitalize(unsponsored_name), ctime(unsponsored[unsponsored_name]), elapsed_time);
      }
   }
   else
   {
      out("You have not unsponsored anyone.\n");
   }
}