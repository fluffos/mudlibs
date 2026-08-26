// Last edited by deforce on 11-09-2009

private mapping tracked_races = ([ ]);
private mapping tracked_directions = ([ ]);
private mapping tracked_times = ([ ]);

void add_tracked(object living, string race, string direction)
{
   string file = file_name(living);
   while (sizeof(tracked_races) >= 5)
   {
      string last_object = keys(tracked_races)[0];

      map_delete(tracked_races, last_object);
      map_delete(tracked_directions, last_object);
      map_delete(tracked_times, last_object);
   }

   tracked_races[file] = race;
   tracked_directions[file] = direction;
   tracked_times[file] = time();
}

mapping query_tracked()
{
   mapping temp = ([ ]);

   foreach (string living in keys(tracked_races))
   {
      if (living)
      {
         temp += ([ living : ({ tracked_races[living], tracked_directions[living], tracked_times[living] }) ]);
      }
   }

   return temp;
}