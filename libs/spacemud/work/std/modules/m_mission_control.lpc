/*
** Misison control module for NPCs
**
** Tsath, 2020
*/

inherit M_CONVERSATION;

string guild;
object active_mis;
int receives = 0;

void give_to_mission_obj(object ob)
{
   active_mis->receive_item(ob);
}

void given_item(object ob)
{
   call_out("give_to_mission_obj", 2, ob);
}

object query_active_mission()
{
   return active_mis;
}

void set_active_mission(object am)
{
   active_mis = am;
   receives = active_mis->query_receive_items();
}

void end_mission()
{
   active_mis = 0;
   receives = 0;
}

void mission_setup()
{
   set_options((["who":"Hi ... what are you doing here?",
            "missions":"Tell me a bit about missions.", "board":"What is the board for?",
             "channel":"How do we communicate?", "box":"What's in the box??",
          "missionwho":"Who can start missions?", ]));

   set_responses(
       (["who":"I handle the missions that " + capitalize(guild) + " are doing.@@missions,box",
             "missions":"As part of this association you can do misions to help us. The resources or advantages we "
                        "gain will be for the benefit of us all. "
                        "If you're asked to find something, give it to me, and I'll register that you brought it here "
                        "so you gain credit for the task.@@board,missionwho",
                "board":"You can see the missions that we can do there.",
              "channel":"Use 'chan " + guild +
                            " /on' to turn on the guild channel if you haven't already. Information about the ongoing "
                            "missions will be posted there.",
           "missionwho":"Right now, every member of " + capitalize(guild) + ".",
                  "box":"The box contains our resources. You may look in there, but you cannot take from the box.", ]));
   set_start(({"who"}));
   this_object()->add_hook("object_arrived", ( : given_item:));
   this_object()->add_id("mission_ctrl_npc_guild");
}

void set_which_guild(string s)
{
   guild = s;
   mission_setup();
}

mixed indirect_give_obj_to_liv(object ob, object liv)
{
   return receives || "#" + this_object()->query_name() + " is not looking for anything currently.";
}