//  /bin/user/_speak.c
//  written by Valodin, August 1993
//  enables players to speak in racial tongues...or any
//  language for that matter

#include <std.h>
#include <daemons.h>

#define FLUBS ({ "something", "womble", "blarg", "cabbage", "blurgle", "jello", "bing", "migrated", "yellow hephalumps", "furry" })
#define FLUBNUM 10
inherit DAEMON;

void speak(string lang, string str, int prof);
void tell_em(string str, object *ob);
mapping make_speakers(object *ob, string lang);
mapping make_speech(mapping speakers, string str, int prof);

int cmd_speak(string str)
{
   string tmp, lang;
   int prof;

   if(!str)
   {
     write("Speak what?\n");
     return 1;
   }

   if(sscanf(str, "in %s %s", lang, tmp) == 2)
     if((prof = (int)this_player()->query_lang_prof(lang)) == 0)
     {
       write("You don't know how to speak " + lang + ".\n");
       return 1;
     }
     else
       speak(lang, tmp, prof);
   else
     if(!(lang = this_player()->query_primary_lang()))
     {
       write("You need to visit the sage to get your languages fixed.\n");
       return 1;
     }
     else
       speak(lang, str, (int)this_player()->query_lang_prof(lang));
   return 1;
}

void speak(string lang, string str, int prof)
{
   object *speakers;
   mapping speech;
   string cap_name, cap_lang;
   int i;

   speakers = all_inventory(environment(this_player()));
   speakers -= ({ this_player() });
   speakers = filter_array(speakers, "is_living", this_object());
   if(prof != 10)
    str = translate(str, prof);
   cap_lang = capitalize(lang);
   write("You say in " + cap_lang + ": " + str);
   speech = make_speakers(speakers, lang);
   speech = make_speech(speech, str, prof);
   cap_name = this_player()->query_cap_name();
   if(speech[10])
     tell_em(cap_name + " says in " + cap_lang + ": " + str, speech[10]);
   if(speech[0])
     tell_em(cap_name + " says something in " + cap_lang + ".", speech[0]);
   for(i = 1; i < 10; i++)
     if(speech[i])
       tell_em(cap_name + " says in " + cap_lang + ": " + 
	       speech["messages"][i], speech[i]);
}

int is_living(object ob)
{
   return living(ob);
}

void tell_em(string str, object *ob)
{
   int i, obsz;

   for(i = 0, obsz = sizeof(ob); i < obsz; i++)
    message("talk", str, ob[i]);
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

int help()
{
write("Command: speak\nSyntax: speak [in <language>] <text>\n"
      "        This allows you to speak in a language other than common. \n"
       "       Only those around you who understand the language will see the real\n"
       "       text.  The others will see parts of it based on theirspeaking\n"
       "       ability.  If you have problems with languages, visit the sage and ask\n"
       "       him to fix you.\n");
return 1;
}
