inherit VERB_OB;

void sense_room(object room);
void sense_object(object thing);
void sense_living(object living);
string alignment_description(int alignment);
string force_description(int force);
string health_description(int percent);
string level_description(int difference);
mixed can_sense();

void do_sense_liv(object living)
{
   sense_living(living);
}

void do_sense_obj(object thing)
{
   sense_object(thing);
}

void do_sense()
{
   sense_room(environment(this_body()));
}

mixed can_sense_liv() { return can_sense(); }
mixed can_sense_obj() { return can_sense(); }

mixed can_sense()
{
   object this_body = this_body();

   if (this_body->query_guild_level("jedi"))
   {
      if (!this_body->has_learned_skill("force sense"))
      {
         return "You have not learned how to sense the Force.\n";
      }
   }
   else
   {
      return "Only Jedi know how to sense the Force.\n";
   }

   return 1;
}

void sense_room(object room)
{
   if (room && strlen(room->sense_force()))
   {
      this_body()->learn_skill("force sense", -200);

      tell(this_body(), room->sense_force());

      return;
   }

   tell(this_body(), "You sense nothing unusual here.\n");
}

void sense_object(object thing)
{
   if (thing && strlen(thing->query_force()))
   {
      this_body()->learn_skill("force sense", -100);

      tell(this_body(), thing->query_force() + "\n");

      return;
   }

   tell(this_body(), "You sense nothing unusual about " + thing->short() + ".\n");
}

void sense_living(object living)
{
   object this_body = this_body();
   string pronoun = capitalize(living->query_pronoun());
   string output;

   if (!living->can_feel_force())
   {
      tell(this_body, capitalize(living->short()) + " is not connected to the Force.\n");

      return;
   }

   output = "You sense " + living->short() + ":\n";
   output += pronoun + " is " + force_description(living->query_for()) + ".\n";
   output += pronoun + " is " + level_description(this_body->query_primary_level() - living->query_primary_level()) + " you.\n";
   output += pronoun + " is " + alignment_description(living->query_jedi_alignment()) + ".\n";
   output += pronoun + " is " + health_description((living->query_health() * 100) / living->query_max_health()) + ".\n";

   if (living->has_effect("poison"))
   {
      output += pronoun + " is poisoned.\n";
   }

   if (living != this_body)
   {
      this_body->learn_skill("force sense");
   }

   tell(this_body, output);
}

string alignment_description(int alignment)
{
   switch (alignment)
   {
      case 40..50: return "dedicated to the Light side of the Force";
      case 20..39: return "allied with the Light side of the Force";
      case 10..19: return "aligned with the Light side of the Force";
      case 1..9: return "associated with the Light side of the Force";
      case 0: return "indifferent towards the Force";
      case -9..-1: return "tainted by the Dark side of the Force";
      case -19..-10: return "aligned with the Dark side of the Force";
      case -39..-20: return "allied with the Dark side of the Force";
      case -50..-40: return "consumed by the Dark side of the Force";
   }

   return "is in an odd state of jedi alignment";
}

string force_description(int force)
{
   switch (force)
   {
      case 100..100000: return "incredibly strong with the Force";
      case 90..99: return "very strong with the Force";
      case 80..89: return "strong with the Force";
      case 70..79: return "above average with the Force";
      case 40..69: return "average with the Force";
      case 30..39: return "below average with the Force";
      case 20..29: return "weak in the Force";
      case 10..19: return "very weak in the Force";
      case 1..9: return "incredibly weak in the Force";
      case 0: return "not connected to the Force";
   }

   return "in an odd state of force";
}

string health_description(int percent)
{
   switch (percent)
   {
      case 91..100: return "in top shape";
      case 76..90: return "in decent shape";
      case 61..75: return "slightly injured";
      case 46..60: return "hurting";
      case 31..45: return "badly injured";
      case 16..30: return "terribly injured";
      case 0..15: return "near death";
   }

   return "in an odd state of health";
}

string level_description(int difference)
{
   switch (difference)
   {
      case 10..50: return "much less experienced than";
      case 5..9: return "less experienced than";
      case 1..4: return "slightly less experienced than";
      case 0: return "just as experienced as";
      case -4..-1: return "slightly more experienced than";
      case -9..-5: return "more experienced than";
      case -50..-10: return "much more experienced than";
   }

   return "in an odd state of level difference";
}

void create()
{
   add_rules( ({ "", "LIV", "OBJ" }) );
}