//      /bin/user/_shout.c
//      from the Nightmare Mudlib
//      the shout command
//      created by Descartes of Borg september 1992
//      rewritten by Descartes 930823
//      rewritten by Valodin using Valodin's languages 930823

#include <std.h>

inherit DAEMON;

void tell_em(string prefix, string str, object *ob);
mapping make_speakers(object *ob, string lang);
mapping make_speech(mapping speakers, string str, int prof);
void shout_out(string lang, string str, int prof);

int cmd_shout(string str) {
    string lang, tmp;
    int prof;

    if(this_player()->query_ghost()) {
        message("my_action", "You moan mournfully.", this_player());
        return 1;
    }
    if(!str) {
        message("my_action", "Sore throat?", this_player());
        return 1;
    }
    if(environment(this_player())->query_property("no shout")) {
        message("my_action", "Your voice does not travel very far.", 
          this_player());
        return 1;
    }
    if((string)this_player()->query_name() == "guest") {
	notify_fail("No shouting priviledges for Guest.\n");
	return 0;
    }
    if(!creatorp(this_player()) && !high_mortalp(this_player()) &&
      (int)this_player()->query_sp() < 60) {
	notify_fail("You are too tired.\n");
	return 0;
    }
    if(strlen(str) > 250)
    {
         notify_fail("That is too much for other players to handle.\n");
         return 0;
    }
    if(!creatorp(this_player()) && !high_mortalp(this_player()))
      this_player()->add_sp(-60);
    if(sscanf(str, "in %s %s", lang, tmp) == 2)
      if((prof = (int)this_player()->query_lang_prof(lang)) == 0)
	{
	  write("You don't know how to speak " + lang + ".");
	  return 1;
	}
      else
	shout_out(lang, tmp, prof);
    else
      if(!(lang = this_player()->query_primary_lang()))
	{
	  write("You need to visit the sage to get your languages fixed.");
	  return 1;
	}
      else
	shout_out(lang, str, (int)this_player()->query_lang_prof(lang));
    return 1;
}
     
void shout_out(string lang, string str, int prof)
{
   object *speakers;
   mapping speech;
   string cap_name, cap_lang;
   int i;

    
    
   speakers = users();
   speakers -= ({ this_player() });
   speakers = filter_array(speakers, "is_online", this_object());
   if(prof != 10)
     str = translate(str, prof);
   cap_lang = capitalize(lang);
   tell_em("You shout in " + cap_lang + ": ", str, ({ this_player() }));
   speech = make_speakers(speakers, lang);
   speech = make_speech(speech, str, prof);
   cap_name = this_player()->query_cap_name();
   if(speech[10])
     tell_em(cap_name + " shouts in " + cap_lang + ": ", str, speech[10]);
   if(speech[0])
     tell_em(cap_name + " shouts something in " + cap_lang + ".", "", 
	     speech[0]);
   for(i = 1; i < 10; i++)
     if(speech[i])
       tell_em(cap_name + " shouts in " + cap_lang + ": ", 
	       speech["messages"][i], speech[i]);
}

int is_online(object ob)
{
   if(!ob || ob->query_blocked("shout"))
     return 0;
   return 1;
}

void tell_em(string prefix, string str, object *ob)
{
   int i, obsz;

   for(i = 0, obsz = sizeof(ob); i < obsz; i++)
    message("shout", prefix+str, ob[i]);
}

mapping make_speakers(object *ob, string lang)
{
  mapping speakers;
  int i, obsz, z;

  speakers = ([]);
  for(i = 0, obsz = sizeof(ob); i < obsz; i++)
  {
    z = ob[i]->query_lang_prof(lang);
    if(!speakers[z])
      speakers[z] = ({ ob[i] });
    else
      speakers[z] += ({ ob[i] });
  }
  return speakers;

}

mapping make_speech(mapping speakers, string str, int prof)
{
  int i;

  speakers["messages"] = ([]);
  for(i = 1; i < 10; i++)
    if(speakers[i])
      speakers["messages"][i] = translate(str, i);
  return speakers;
}


void help() {
    message("help",
      "Syntax: <shout (in [language]) [message]>\n\n"
      "Sends a shout in whatever language to the entire mud."
      "Misuse of this power may result in action from law.",
      this_player()
    );
}
