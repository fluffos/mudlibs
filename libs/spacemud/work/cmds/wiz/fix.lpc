/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE: ``fix <body>``
//
// Checks a player body, and fixes possible issues needed
// for it to work. This command is mostly useful for bodies using limbs.
//
// .. TAGS: RST

inherit CMD;
inherit M_WIDGETS;
inherit CLASS_LIMB;

object user;

#define FIX_PAUSE 2

#define ISSUE 0
#define GOOD 1
#define FIXED 2

private
varargs void wrfix(string out, int type)
{
   string *cols = ({"<198>", "<047>", "<015>"});
   write((type != 2 ? on_off_widget(type) : "     ") + cols[type] + " " + out + "<res>");
}

varargs void fix_body(object body, int step)
{
   switch (step)
   {
   case 0:
      wrfix("Diagnosing " + body->query_name() + " ...", FIXED);
      if (body != this_body())
         tell(body,
              "Your body is being diagnosed by " + this_body()->query_name() + ". Leave combat, then stand still.");
      user = this_body();
      break;
   case 1:
      // Check 1, is our body_style still a valid style in BODY_D, otherwise fallback to humanoid.
      if (BODY_D->body_exist(body->query_body_style()))
         wrfix(body->query_name() + " body style: " + body->query_body_style() + " is in BODY_D",
               BODY_D->body_exist(body->query_body_style()));
      else
      {
         body->update_body_style("humanoid");
         wrfix(body->query_name() + " body style: " + body->query_body_style() +
                   " does not exist, falling back to humanoid.",
               FIXED);
      }
      break;
   case 2:

      // Check 2, is torso limb still valid.
      {
         class limb torso = (class limb)body->get_health()["torso"];
         class limb nl = new (class limb);
         mixed dl = disassemble_class(torso);
         mixed dnl = disassemble_class(nl);

         wrfix("Torso limb has " + sizeof(dl) + " class members, a new limb has " + sizeof(dnl) +
                   ". Did you change to or from LIMB_SHIELDS in <config.h>?",
               sizeof(dl) == sizeof(dnl));

         if (sizeof(dl) != sizeof(dnl))
         {
            body->update_body_style(body->query_body_style());
            wrfix(body->query_name() + " body style: " + body->query_body_style() + " broken, giving a new one.",
                  FIXED);
         }
      }
      break;

   case 3:
      // Check 3, do we have stats?
      {
         int stats = body->query_carrying_stat() + body->query_health_stat() + body->query_physical_dmg_stat() +
                     body->query_agility_stat() + body->query_social_stat() + body->query_mental_stat() +
                     body->query_reflex_stat();

         wrfix("Checking if any known stat is > 0", stats != 0);
         if (!stats)
         {
            body->init_stats();
            stats = body->query_carrying_stat() + body->query_health_stat() + body->query_physical_dmg_stat() +
                    body->query_agility_stat() + body->query_social_stat() + body->query_mental_stat() +
                    body->query_reflex_stat();
            wrfix(body->query_name() + " rerolled stats.", stats != 0);
         }
      }

      break;
   default:
      wrfix("Repairing " + body->query_name() + " done.", FIXED);
      tell(body, "Your body has been repaired. Feel any better?");
      user = 0;
      return;
      break;
   }

   call_out("fix_body", FIX_PAUSE, body, ++step);
}

private
void main(mixed *arg)
{
   if (objectp(arg[0]))
      arg = arg[0];

   if (user)
   {
      wrfix("The 'fix' command is currently used by " + user->query_name() + ". Please, try again later.", ISSUE);
      return;
   }

   if (arg->is_body())
   {
      fix_body((object)arg);
   }
}