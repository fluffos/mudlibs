// Last edited by deforce on 11-14-2009
inherit CMD;

private void main(string arg)
{
   object body = find_body(arg);
   mapping delays = ([ ]);
   string output = "";

   if (!wizardp(this_body()) || !body) { body = this_body(); }

   delays = body->query_skill_delays();

   if (sizeof(keys(delays)))
   {
      int time = time();

      foreach (string skill in sort_array(keys(delays), 1))
      {
         if ((delays[skill] - time) > 0)
         {
            output += sprintf("%-30s : %s\n", skill, convert_time(delays[skill] - time));
         }
      }
   }

   if (strlen(output))
   {
      out(output + "\n");
   }
   else
   {
      out("You have no skill delays.\n");
   }
}