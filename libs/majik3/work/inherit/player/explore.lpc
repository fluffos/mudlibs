string explore;
int explore_count;

void
reset_explore ()
{
  explore = "";
  explore_count = 0;
}

void
add_explore (int i)
{
  if (!explore)
    reset_explore();
    
  if (!stringp(explore))
    {
      tell_object (this_object(), "Explore save file corrupt, resetting.\n");
      reset_explore();
    }

  if (test_bit (explore, i))
    return 0;

  explore = set_bit (explore, i);
  explore_count++;

  if (explore_count > EXPLORE_D->query_total())
    explore_count = EXPLORE_D->query_total();
}

int
query_explore ()
{
  return explore_count;
}

int
query_explore_percent ()
{
  int total;

  total = EXPLORE_D->query_total();

  return (explore_count * 100 / (total < 1 ? 1 : total));
}

