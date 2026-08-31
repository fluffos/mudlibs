/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Tsath 2020
*/

private
int durability = -1;
private
int max_dura = -1;
private
int current_max_dura = -1;

int has_durability()
{
   return 1;
}

void set_max_durability(int md)
{
   if (md == 0)
      return;
   current_max_dura = md;
   max_dura = md;
}

nomask int original_max_durability()
{
   if (max_dura == -1)
      max_dura = current_max_dura;
   return max_dura;
}

nomask int max_durability()
{
   return current_max_dura;
}

void set_damaged_durability()
{
   durability = 1 + random(current_max_dura * 0.1);
}

void reset_durability()
{
   durability = max_durability();
}

void durability_after_repair()
{
   current_max_dura = current_max_dura * (1 - (random(5) / 100.0));
   durability = max_durability();
}

int query_durability()
{
   if (durability == -1)
      reset_durability();
   return durability;
}

int direct_repair_obj()
{
   return (durability < current_max_dura);
}

int durability_percent()
{
   return (100 * query_durability() / max_durability());
}

int missing_durability()
{
   if (durability == -1)
      reset_durability();
   return current_max_dura - durability;
}

string durability_extra_long()
{
   return sprintf("The durability is %d%%.", durability_percent());
}

void decrease_durability(int d)
{
   d = abs(d);
   if (durability == -1)
      reset_durability();
   durability -= d;
   if (durability < 0)
      durability = 0;
}

void increase_durability(int d)
{
   d = abs(d);
   if (durability == -1)
      reset_durability();
   durability += d;
   if (durability > current_max_dura)
      durability = current_max_dura;
}

void internal_setup()
{
   this_object()->add_save(({"durability", "current_max_dura"}));
}