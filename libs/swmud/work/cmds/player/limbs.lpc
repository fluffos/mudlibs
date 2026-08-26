// Last modified by deforce on 01-14-2007
inherit CMD;
inherit M_ANSI;
inherit ADVERSARY;

string format_limb(string limb);

object body;

private void main(string arg)
{
   string limbs = "";

   if (wizardp(this_body()) && find_body(arg)) { body = find_body(arg); }
   else { body = this_body(); }

   limbs += "Vital:\n" + format_limb("head") + format_limb("torso");
   limbs += "Arms:\n" + format_limb("left arm") + format_limb("right arm");
   limbs += "Hands:\n" + format_limb("left hand") + format_limb("right hand");
   limbs += "Legs:\n" + format_limb("left leg") + format_limb("right leg");
   limbs += "Feet:\n" + format_limb("left foot") + format_limb("right foot");

   out(limbs);
}

string format_limb(string limb)
{
   int health = body->query_limb_health(limb);
   string limb_health = (!health ? "%%^BOLD%%^%%^RED%%^" : "") + "%i/%i" + (!health ? "%%^RESET%%^" : "");

   return sprintf("  %%^CYAN%%^%-11s%%^RESET%%^: " + limb_health + "\n",
      title_capitalize(limb), health, body->query_max_health(limb));
}