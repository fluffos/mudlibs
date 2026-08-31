/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Tsath, 2020
*/

inherit ADVERSARY;
inherit M_GUILD_MASTER;

void setup()
{
   set_name("Mr Nakamura");
   set_in_room_desc("Mr Nakamura, a nicely dressed tall asian man stands here.");
   add_id("lead", "nakamura", "boss", "guild lead", "man", "asian", "tall man");
   set_gender(1);
   set_level(100);
   set_proper_name("Mr Nakamura");
   set_long("A nicely dressed man, perhaps Japanese of origin. It would be wise to avoid pissing him off. Try to talk "
            "to him.");
   set_max_health(10000);
   set_options((["who":"Hi ... who are you?", ]));

   set_responses((["who":"I'm Mr Nakamura, pleased to meet you.", ]));
   set_start(({"who"}));
   set_which_guild("yakitori");
}

mixed receive_object(object target, string relation)
{
   if (!this_body())
      return ::receive_object(target, relation);

   if (guild_master_receive(target))
      ::receive_object(target, relation);
   return "";
}