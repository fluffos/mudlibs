inherit ARMOUR;

#define COLLAR_TYPE_COMBAT 1
#define COLLAR_TYPE_DRAFT 2

int taming_level = 1;
int collar_type = 1;

string collar_type()
{
   return (collar_type == COLLAR_TYPE_COMBAT ? "combat" : "draft");
}

private
internal_set_id()
{
   string type = collar_type();
   set_id(type + " taming collar", type + " collar", "taming collar", "collar");
   set_long("This collar is required to tame wild creatures and use them for " +
            (collar_type == COLLAR_TYPE_COMBAT ? "combat" : "carrying items") + ".");
}

void mudlib_setup()
{
   set_armour_class(1);
   internal_set_id();
   set_slot("head");
   set_weight(0.01);
}

mapping query_recipe()
{
   return (["textile":({0, 1, 0, 0, 0}), "metal":({5, 0, 0, 0, 0})]);
}

void set_combat_collar()
{
   collar_type = COLLAR_TYPE_COMBAT;
   internal_set_id();
}

void set_draft_collar()
{
   collar_type = COLLAR_TYPE_DRAFT;
   internal_set_id();
}

void set_taming_level(int tl)
{
   taming_level = tl;
}

int max_tameable_level()
{
   return taming_level;
}

int is_taming_collar()
{
   return 1;
}

void set_damaged()
{
   this_object()->remove();
}

// Not for non-tameable environments :)
int direct_wear_obj()
{
   if (environment(this_object()) && environment(this_object())->is_tameable())
      return 1;
   else
      return 0;
}