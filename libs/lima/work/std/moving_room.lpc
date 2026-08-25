/* Do not remove the headers from this file! see /USAGE for more info. */

inherit INDOOR_ROOM;

mapping dests = ([]);
mapping distances = ([]);

int default_distance = 6;
string where;
string travelling_to;
function in_progress;
int progress_delay;

int query_distance(string destination)
{
   return distances[where + ":" + destination] || default_distance;
}

int query_in_motion()
{
   return !!travelling_to;
}

string query_where()
{
   return where;
}

string query_location()
{
   return dests[where];
}

void arrive()
{
   where = travelling_to;
   travelling_to = 0;
   remove_call_out("do_progress");
   load_object(evaluate_path(dests[where], 0, 1))->arrived(this_object());
}

void do_progress()
{
   evaluate(in_progress);
   call_out("do_progress", progress_delay);
}

void move_to(string dest)
{
   int dist;

   if (!dests[dest])
      error("Invalid destination '" + dest + "' in " + previous_object() + ".\n");
   if (travelling_to)
      error("In motion.\n");

   if (where)
   {
      if (dests[where])
         load_object(evaluate_path(dests[where], 0, 1))->departed(this_object());
      else
      {
         error("Destination '" + where + "' not found.");
         return;
      }
      dist = query_distance(dest);
      travelling_to = dest;
      where = 0;
      call_out(( : arrive:), dist);
      if (progress_delay)
         call_out("do_progress", progress_delay);
   }
   else
   {
      /* initial move */
      where = dest;
   }
}

//: FUNCTION set_destinations
// Set a mapping between names and locations. The names can be in the format::
//  "church
//  or
//  "2/church" - this format allows the elevator user to use 'push 2' etc.
// Make sure to use the same names when setting distances.
void set_destinations(mapping m)
{
   dests = m;
}

void set_default_distance(int x)
{
   default_distance = x;
}

//: FUNCTION set_distance
// Set distance between destinations.
void set_distance(string d1, string d2, int dist)
{
   distances[d1 + ":" + d2] = dist;
   distances[d2 + ":" + d1] = dist;
}

void set_in_progress(function f, int delay)
{
   in_progress = f;
   progress_delay = delay;
}
