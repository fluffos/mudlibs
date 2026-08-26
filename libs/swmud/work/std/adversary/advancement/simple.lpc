// Last edited by deforce on 03-22-2010
void save_me();

private int experience = 0;

int query_experience()
{
   return experience;
}

void add_experience(int x)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("add " + x + " experience to " + this_object()->short(), previous_object(-1)); }

   experience += x;

   if (experience < 0) { experience = 0; }

//   if (this_body()->query_link()) { save_me(); }
}

void subtract_experience(int x)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("subtract " + x + " experience from " + this_object()->short(), previous_object(-1)); }

   add_experience(x * -1);
}

void set_experience(int x)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + "'s experience to " + x, previous_object(-1)); }

   experience = x;
}