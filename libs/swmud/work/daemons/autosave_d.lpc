#define CHECK_TIME  30
#define IDLE_TIME   3599
#define NOTIFY_TIME 299
#define SAVE_TIME   599

void check_users();
string list();
string format_idle_time(int time);

private mapping last_time = ([ ]);
private mapping last_notify_time = ([ ]);

void check_users()
{
   int current_time = time();

   foreach (object user in users())
   {
      string username = user->query_userid();

      if (strlen(username) && !last_time[username])
      {
         last_time[username] = current_time;
      }
   }

   foreach (string user in keys(last_time))
   {
      object body = find_body(user);

      if (body)
      {
         int idle_time = query_idle(body->query_link());

         if ((idle_time > IDLE_TIME) && !wizardp(body) && !GROUP_D->member_group(user, "testplayers"))
         {
            tell(body, "You have been idle too long.\n");

            find_user(user)->force_me("quit");
         }
         else if (last_time[user] && ((current_time - last_time[user]) > SAVE_TIME))
         {
            if (idle_time > 120)
            {
               tell(body, "Autosaving." + (idle_time > NOTIFY_TIME ? " (idle " + convert_time(idle_time) + ")" : "") + "\n");

               last_notify_time[user] = current_time;
            }

            body->save_me();
            last_time[user] = current_time;
         }
         else if ((idle_time > NOTIFY_TIME) && last_notify_time[user] && ((current_time - last_notify_time[user]) > NOTIFY_TIME))
         {
            tell(body, "(idle " + convert_time(idle_time) + ")\n");

            last_notify_time[user] = current_time;
         }
      }
      else
      {
         map_delete(last_time, user);
         map_delete(last_notify_time, user);
      }
   }

   call_out((: check_users :), CHECK_TIME);
}

string list()
{
   string output = "";
   int current_time = time();

   foreach (string user in keys(last_time))
   {
      output += sprintf("%-13s: %i\n", capitalize(user), (SAVE_TIME + 1) - (current_time - last_time[user]));
   }

   return output;
}

void create()
{
   if (clonep())
   {
      destruct(this_object());
      return;
   }

   call_out((: check_users :), CHECK_TIME);
}