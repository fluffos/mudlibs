/* A Statue of Xalandre looking sadly into the ocean of Shamyra */

// Created by Taurec, 10 Oct. 1997

#include <properties.h>
#include <macros.h>
#include <npc.h>
inherit "/std/thing";
inherit "/std/npc";

void create()
{
  ::create();
  enable_commands();
  set_living_name("xalandre");
  SetShort("a statue of Xalandre, godess of the waves");
  SetLong("The statue of Xalandre depicts a lovely but sorrowful young woman, "
          "her long hair strewn with seaweed, and two dolphins attend her. "
          "Her sad gaze seems to wander over the ocean of Shamyra, "
          "as if hopelessly seeking a sign of the one she had lost "
          "forever...\n");
  SetNoGet("You try to lift the statue of Xalandre - But as you touch it, "
           "a sudden wind blows from the ocean, and a strong gust almost "
           "makes you collapse. Shocked, you pull your hands back quickly.\n");
  SetSmell("A scent like a fresh seawind seems to come from beneath "
           "the smooth white marble surface of the statue.\n");
  SetNoise("Listening to a statue is fun, isn't it? But wait... "
           "what's that?!? You listen more carefully. And truly! A low "
           "mourning sigh emerges from below the smooth surface of "
           "the statue!\n"); 
  SetValue(333);
  AddId(({"statue","statue of xalandre"}));
  AddAdjective(({"marble","white"}));
  SetShrugMsg("The statue shrugs helplessly and petrifies again.\n");
}

