// Last edited by deforce on 11-09-2009
inherit VERB_OB;

void track();
string format_info(mapping info, object ignored);
string format_elapsed_time(int time);

void do_track()
{
   object this_body = this_body();

   if (this_body->query_guild_level("bounty hunter"))
   {
      if (!this_body->has_learned_skill("tracking"))
      {
         write("You have not learned how to identify tracks.\n");
      }
      else if (this_body->get_target())
      {
         write("You are unable to concentrate on the tracks here when you're already in combat.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to study the tracks leading out of this area.\n");
      }
      else if (!sizeof(environment(this_body)->query_tracked()))
      {
         write("There are no tracks leading out of this area.\n");
      }
      else if ((sizeof(environment(this_body)->query_tracked()) == 1)
         && (keys(environment(this_body)->query_tracked())[0] == file_name(this_body)))
      {
         write("There are no tracks leading out of this area besides your own.\n");
      }
      else
      {
         this_body->add_skill_delay(2);

         if (this_body->test_skill("tracking", this_body->query_guild_level("bounty hunter") * 10))
         {
            track();
         }
         else
         {
            write("You are unable to determine anything about the tracks in this area.\n");
         }
      }
   }
   else
   {
      write("Only bounty hunters know how to study tracks.\n");
   }
}

void track()
{
   object this_body = this_body();
   int level = this_body->query_guild_level("bounty hunter");
   int rank = to_int(floor(this_body->query_skill("tracking") / 100.0));

   write("\n" + format_info(environment(this_body)->query_tracked(), this_body));
}

string format_info(mapping info, object this_body)
{
   string text = "";
   string data;

   foreach (string being in keys(info))
   {
      if (being != file_name(this_body))
      {
         data = info[being];

         if (data[0] == 0) { continue; }

         text += title_capitalize(add_article(data[0])) + " passed through here";

         if (this_body->test_skill("tracking", this_body->query_guild_level("bounty hunter") * 8))
         {
            text += " " + format_elapsed_time(time() - data[2]) + " ago";

            if (this_body->test_skill("tracking", this_body->query_guild_level("bounty hunter") * 5))
            {
               text += ", going " + data[1];
            }
         }

         text += ".\n";
      }
   }

   return text;
}

string format_elapsed_time(int time)
{
   string output = "";

   if (time > 59)
   {
      if (time > 3599)
      {
         if (time > 86399)
         {
            output += (time / 86400) + " day" + ((time / 86400) > 1 ? "s" : "");

            time = time % 86400;
         }

         if (strlen(output))
         {
            output += ", ";
         }

         output += (time / 3600) + " hour" + ((time / 3600) > 1 ? "s" : "");

         time = time % 3600;
      }

      if (strlen(output))
      {
         output += ", ";
      }

      output += (time / 60) + " minute" + ((time / 60) > 1 ? "s" : "");
   }
   else
   {
      return "less than a minute";
   }

   return "about " + output;
}

void create()
{
   add_rules( ({ "" }) );
}