inherit M_SAVE;

// Standard variables for setup
private int range_base = 0;

// Modification variables
private int range_bonus = 0;

void mudlib_setup()
{
   add_save(({ "range_base", "range_bonus" }));
}

int is_ranged_weapon() { return 1; }

void set_range_base(int x)
{
   range_base = x;
}

int query_range_base(object target)
{
   return range_base;
}

void set_range_bonus(int x)
{
   range_bonus = x;
}

void add_range_bonus(int x)
{
   range_bonus += x;
}

int query_range_bonus()
{
   return range_bonus;
}

void reset_range_bonus()
{
   range_bonus = 0;
}

int query_range()
{
   if ((range_base + range_bonus) > 0)
   {
      return (range_base + range_bonus);
   }

   return 0;
}