inherit OBJ;
inherit M_GETTABLE;

#include <syringe_bottle.h>

int query_value();

private string type = keys(liquid_color)[0];
private int fills = 0;
private int max_fills = 0;
private int doses_per_fill = 0;

void mudlib_setup()
{
   add_save(({ "type", "fills", "max_fills", "doses_per_fill" }));
}

varargs void setup(string set_type)
{
   if (strlen(set_type))
   {
      type = set_type;
   }

   fills = liquid_fills[type];
   max_fills = liquid_fills[type];
   doses_per_fill = liquid_doses_per_fill[type];

   set_id("bottle of " + format_liquid_color(type) + " liquid", "bottle", type + " bottle");
   set_long("A bottle that contains " + format_liquid_color(type) + " liquid, which can be used with a syringe.");
   set_mass(10);
}

string query_liquid_type() { return type; }
int query_fills_left() { return fills; }
int deny_alter_value() { return 1; }
int deny_alter_weight() { return 1; }

int get_a_fill()
{
   if (fills > 0)
   {
      fills--;

      if (fills <= 0)
      {
         type = "";
         clear_id();
         set_id("bottle", "empty bottle");
         set_long("An empty bottle.");
      }

      return doses_per_fill;
   }

   return 0;
}

int is_syringe_bottle() { return 1; }

int indirect_fill_obj_with_obj()
{
   if (fills > 0)
   {
      return 1;
   }

   return 0;
}

string fill_description()
{
   if (max_fills <= 0)
   {
      return "not set up properly";
   }

   switch ((fills * 100) / max_fills)
   {
      case 100: return "completely full";
      case 91..99: return "almost full";
      case 81..90: return "more than three quarters full";
      case 71..80: return "three quarters full";
      case 56..70: return "more than half full";
      case 46..55: return "half full";
      case 31..45: return "less than half full";
      case 21..30: return "a quarter full";
      case 11..20: return "less than a quarter full";
      case 1..10: return "almost empty";
      case 0: return "empty";
   }

   return "filled oddly, please tell a wizard";
}

int query_value_pure()
{
   return query_value();
}

int query_value()
{
   if (fills > 0)
   {
      return fills * liquid_value[type] / max_fills;
   }

   return 10;
}

int query_mass()
{
   return 50 + (fills * 250 / max_fills);
}

void do_check_obj()
{
   write("The bottle contains " + format_liquid_color(type) + " liquid.\nIt is " + fill_description() + ".\n");
}