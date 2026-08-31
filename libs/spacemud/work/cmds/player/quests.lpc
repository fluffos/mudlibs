/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** quests.c
**
** Show you all the quests on the mud.
**
** Created 24-NOV-95, Rust
*/

//: PLAYERCOMMAND
// USAGE
//    ``quests``
//
// Shows you all the quests for the area you are in.
//
// .. TAGS: RST

inherit CMD;
inherit M_FRAME;

nomask private void main()
{
   string domain = explode(base_name(environment(this_body())), "/")[1];
   string footer;
   mapping quests = ([]);
   mapping quest_src = QUEST_D->query_domain_quests(domain);
   string c = "";

   foreach (string quest in keys(quest_src))
   {
      string *parts = explode(quest, ":");
      string main = parts[0];
      string task = parts[1];
      string status;

      if (!quests[main])
      {
         quests[main] = ([]);
         quests[main]["parts"] = ({});
      }

      quests[main]["parts"] += ({task});
      status = this_body()->quest_task(domain, main);
      if (status == "None" || !status)
         status = "NOT_EVEN_STARTED";
      switch (status)
      {
      case "begin":
         status = "Started";
         break;
      case "end":
         status = "Finished";
         break;
      case "NOT_EVEN_STARTED":
      case "":
         status = "Not started";
         break;
      default:
         status = "On your way";
         break;
      }

      quests[main]["task"] = this_body()->quest_task(domain, main);
      quests[main]["status"] = status;
      quests[main]["name"] = QUEST_D->query_quest_name(domain, main);
   }

   frame_init_user();
   set_frame_title("Quests");
   set_frame_header(sprintf("%25-s  %12s   %s\n", "Quest Name", "Quest steps", "Status"));
   set_frame_footer(sprintf("In your current part of %s (%s) there %s %d quest%s available", mud_name(),
                            capitalize(domain), sizeof(quests) == 1 ? "is only" : "are", sizeof(quests),
                            sizeof(quests) == 1 ? "" : "s", ));

   foreach (string quest in keys(quests))
   {
      c += sprintf(" %31-s  %6d   %s\n", capitalize(quests[quest]["name"]), sizeof(quests[quest]["parts"]),
                   quests[quest]["status"], );
   }
   set_frame_content(c);
   outf(frame_render());
}
