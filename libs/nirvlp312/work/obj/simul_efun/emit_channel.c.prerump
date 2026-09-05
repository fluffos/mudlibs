/*
// emit_channel.c
//
// This file defines the emit_channel function, which
// is used to echo messages to people ona particular channel.
// Written by Shadowhawk the NUISANCE
*/


#pragma strict_types
#pragma save_types

/*
// This function accepts the channel name to emit to, and
// the message to emit.  It returns the number of people echoed to.
*/

int
emit_channel(string channel, string message) {
  int index, count;
  object *people;

    if(channel != "risque" && channel != "wiz" && channel != "admin" && channel != "announce" && channel != "jukebox")
  if(message) message = (string)"/obj/verte/text_sanitizer"->sanitize_text(message);
/* Inserted for channel history -Feld 7-2-99 */
  "/obj/user/chistory.c"->add_history(channel,message);

  people = users();
  count = 0;
  for (index = 0; index < sizeof(people); index++)
  {
/* 
    if (people[index]->on_channel(channel)) {
Announce must go through, -Bp part of emit chg over*/
    if(!people[index]) continue;
    if( (people[index]->on_channel(channel) && !people[index]->query_muffled()) || channel == "announce") {
      string ColorMsg;
      if(this_player() && (int)this_player()->is_player())
        if(ColorMsg = (string)people[index]->get_ansi_pref(channel))
          tell_object(people[index], ColorMsg+message+"[0m");
       else tell_object(people[index], message);
      count++;
    }
  }
  return count;
}
