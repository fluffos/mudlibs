/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE: ``scripts``
//
// Shows status of scripted NPCs.
//
// .. TAGS: RST

inherit CMD;
inherit M_WIDGETS;

private
void main(string str)
{

   object *scripted = filter(objects(), ( : $1->query_running_script() && clonep($1) :));

   if (!sizeof(scripted))
   {
      printf("Currently, there are no scripts running.");
      return;
   }

   printf("<bld>%-20.20s %-30.30s %-14.14s %-8.8s %s<res>", "Who", "Env", "Script", "Type", "Status");
   foreach (object s in scripted)
   {
      string name = s->short();
      string env = environment(s) ? environment(s)->short() : "Nowhere";
      string bar = repeat_string(" ", 30);
      string script = "";
      string type;
      int *status = s->status();
      if (status)
      {
         script = s->query_running_script();
         type = s->current_step();
         bar = green_bar(status[0], status[1], 30);
         printf("%-20.20s %-30.30s %-14.14s %-8.8s %s %s", name, env, script, type, bar,
                "[" + status[0] + "/" + status[1] + "]");
      }
   }
}
