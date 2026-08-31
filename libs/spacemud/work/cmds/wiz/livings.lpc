/* Do not remove the headers from this file! see /USAGE for more info. */

// Tsath @ Nuke 2, 2020

//: COMMAND
// USAGE ``livings``
//
// Give a count of living things (not players) on the MUD grouped by filename.
//
// .. TAGS: RST

inherit CMD;

void main(string arg)
{
   object *mobs;
   mapping counts = ([]);
   mobs = filter_array(objects(), ( : !$1->is_body() && clonep($1) && $1->attackable() :));
   write("--------------\nLivings found\n--------------\n");

   foreach (object mob in mobs)
   {
      string s = mob->short() + "\t\t" + base_name(mob);
      if (!counts[s])
         counts[s] = 0;
      counts[s]++;
   }

   foreach (string s, int count in counts)
   {
      printf("%s: %d\n", s, count);
   }
   printf("\n");
}
