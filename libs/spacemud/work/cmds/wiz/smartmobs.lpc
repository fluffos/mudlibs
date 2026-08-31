/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE: ``smartmobs``
//
//  Shows what the mob is thinking about and where they are
// located.
//
// .. TAGS: RST

inherit CMD;

private
void main(string str)
{

   object *smarts = filter(objects(), ( : $1->is_smart() && clonep($1) :));

   printf("<bld>%-50.50s %-7.7s %-20.20s %s<res>", "Object", "Parses", "Env", "Mood");
   foreach (object s in smarts)
   {
      string name = s->short();
      int parses_made = s->parses_made();
      string env = environment(s) ? environment(s)->short() : "Nowhere";
      string mood = s->emotion_string();
      printf("%-50.50O %-7d %-20.20s %s", s, parses_made, env, mood);
   }
}
