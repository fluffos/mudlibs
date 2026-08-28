//  /bin/user/_speak.c
//  written by Valodin, August 1993
//  enables players to speak in racial tongues...or any
//  language for that matter
// Modified by Geldron 031196 to fix say bug

#include <std.h>
#include <daemons.h>

inherit DAEMON;
#define FLUENT 10
#define NO_SKILL 0

void speak(string lang, string str, int prof);
void tell_em(string str, object *ob);
mapping make_speakers(object *ob, string lang);
mapping make_speech(int* prof_keys, string str);

int cmd_say(string str)
{
  string tmp, lang;
  int prof;

  if (!str)
  {
    return notify_fail("Speak what?\n");
  }

  if (!(lang = this_player()->query_primary_lang()))
  {
    return notify_fail("You need to visit the sage to get your languages fixed.\n");
    ;
  }
  else
    speak(lang, str, (int)this_player()->query_lang_prof(lang));
  return 1;
}

void speak(string lang, string str, int prof)
{
  object *speakers;
  mapping speaker_map;
  mapping speech;
  int *prof_keys;
  string cap_name, cap_lang, foo;
  int k;

  if (this_player() && environment(this_player()))
    speakers = all_inventory(environment(this_player()));
  else
    speakers = ({});
  speakers -= ({this_player()});
  speakers = filter_array(speakers, "is_living", this_object());
  if (this_player()->is_player())
    foo = "";
  else
    foo = "\n";
  str = translate(str, prof);
  cap_lang = capitalize(lang);
  write(sprintf("You say in %s: %s",cap_lang,str));
  speaker_map = make_speakers(speakers, lang);

  prof_keys = keys(speaker_map);
  speech = make_speech(prof_keys, str);

  cap_name = this_player()->query_cap_name();

  for (int i = 0; i < sizeof(prof_keys); i++) {
      if(prof_keys[i] == NO_SKILL)
        tell_em(foo + cap_name + " says something in " + cap_lang + ".", speaker_map[prof_keys[i]]);
      else if (prof_keys[i] == FLUENT)
        tell_em(foo + cap_name + " says in " + cap_lang + ": " + str, speaker_map[prof_keys[i]]);
      else
        tell_em(sprintf("%s %s says in %s: %s",foo,cap_name,cap_lang,speech[prof_keys[i]]), speaker_map[prof_keys[i]]);
  }

}

int is_living(object ob)
{
  return living(ob);
}

void tell_em(string str, object *ob)
{
  message("talk", str, ob);
}

mapping make_speakers(object *ob, string lang)
{
  mapping speakers;
  int i, obsz, z;

  speakers = ([]);
  for (i = 0, obsz = sizeof(ob); i < obsz; i++)
  {
    z = ob[i]->query_lang_prof(lang);
    if (!speakers[z])
      speakers[z] = ({ob[i]});
    else
      speakers[z] += ({ob[i]});
  }
  return speakers;
}

mapping make_speech(int * profs, string str)
{
  mapping speech;

  speech = ([]);
  for (int i = 0; i < sizeof(profs); i++)
    speech[profs[i]] = translate(str, profs[i]);
  return speech;
}

int help()
{
  write("Command: say\nSyntax: say <text>\n"
        "        This allows you to speak in a language other than common. \n"
        "       Only those around you who understand the language will see the real\n"
        "       text.  The others will see parts of it based on theirspeaking\n"
        "       ability.  If you have problems with languages, visit the sage and ask\n"
        "       him to fix you.  \n"
        "       NOTE: Use the 'speak' command to change your default language.");
  return 1;
}
