#include <properties.h>
#include <language.h>
inherit "std/thing";

int    alter;
object furzer;

void create()
{
  ::create();
  SetProp(P_SHORT, 0);
  SetProp(P_LONG, 0);
  SetProp(P_NAME, "Etwas");
  SetProp(P_GENDER, 1);
  SetProp(P_ARTICLE,0);
  SetProp(P_NOGET,"Häh?\n");
  AddId("_furz_");
  alter = 0;
  set_heart_beat(1);
}

void heart_beat()
{
  int i;

  if (!alter)
    say("Fürchterlicher Gestank erfüllt den Raum.\n");
  alter++;
  if (!random(10))
  {
    i = random (5);
    if (i==0 && furzer)
      say(furzer->name(WESSEN,1)+" Furz stinkt wirklich grauenerregend.\n");
    if (i==1)
      say("Du hältst Dir die Nase zu.\n");
    if (i==2)
      say("Widerliche Dünste erfüllen den Raum.\n");
    if (i==3 && furzer)
      say("Der Furz riecht, als würde " + furzer->name() +" innerlich verfaulen.\n");
    if (i==4 && furzer)
      say("Du musst Dich beinah übergeben, als " + furzer->name(WESSEN,1) + " Furz in Deine Nase kriecht.\n"); 
  }
  if (alter==45 && furzer) {
      say(furzer->name(WESSEN,1) + " widerlicher Furz hat sich endlich verzogen.\n");
      destruct(this_object());
    }
}

void set_furzer (object wer)
{
  furzer = wer;
}
