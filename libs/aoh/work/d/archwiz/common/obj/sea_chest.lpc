/*
* This is an old rusty chest
* It is used by the octopus who creates the shell
* for the collectors-quest.
*/

#include "path.h"

inherit "/obj/chest";

int allow_enter(int method,mixed extra)
{
  if (blueprint(previous_object())==OBJ("shell")) return 1;
  return ::allow_enter(method,extra);
}

void create()
{
  (::create());
  SetIds(({"chest"}));
  SetAds(({"old","heavy","rusty"}));
  SetShort("an old heavy chest");
  SetLong(
"Seaweed and small shells cover the chest. The lock looks "
"old and rusty. Many scratches are on it and you wonder "
"why it didn't break into pieces as you touched it. "
"A small sign on the chest reads: At on.is. "
"You wonder if this might have been the owner of the "
"chest. If so he must have forgotten it.\n");
// Remark: At on.is  are the remains of the word "Atlantis"
  SetWeight(50000);
  SetMaxWeight(60000);
  SetNoGet("It's far too heavy for you.\n");
  SetValue(1);
}
