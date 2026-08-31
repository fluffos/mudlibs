/* Do not remove the headers from this file! see /USAGE for more info. */

/* Random GEM by Tsath 2020, April (Covid-19 days) */

inherit OBJ;
inherit M_GETTABLE;

string *gem_size = ({"fine", "tiny", "small", "medium", "large", "giant"});
string *gem_shape = ({"unworked", "round", "oval", "heart-shaped", "drop-shaped", "pentagon"});
string *gem_cut = ({"cabochon", "point", "table", "single", "rose", "brilliant"});
string *gem_colour =
    ({"bright chrimson", "blood rod", "orange", "bright yellow", "yellow ochre", "lime green", "forest green", "teal",
      "sky blue", "cerulean", "phtalo blue", "violet", "lavender", "pink", "brown", "gray", "white", "clear", "black"});

int gsize;
int gshape;
int gcut;
int gcolour;
int rolled;
int value_cap = 64;

void set_value(float value);

float query_value()
{
   return query_value();
}

int randomize_gem()
{
   int roll = random(64);

   if (roll > value_cap)
      roll = value_cap;

   if (roll < 32)
      return 0;
   if (roll < 48)
      return 1;
   if (roll < 56)
      return 2;
   if (roll < 60)
      return 3;
   if (roll < 62)
      return 4;
   if (roll < 63)
      return 5;
}

// If sold to merchant, just remove the item, don't sell it again.
int destroyable()
{
   return 1;
}

int gem_value()
{
   return (1 + gsize) * (1.0 + (gshape / 3.0) + (gcut / 10.0) + (gcolour / 5.0));
}

void roll_gem()
{
   int value = 0;
   if (!rolled)
   {
      gsize = randomize_gem();
      gshape = randomize_gem();
      gcut = randomize_gem();
      gcolour = random(sizeof(gem_colour));
      rolled = 1;
   }
   set_adj(gem_size[gsize]);
   set_id(gem_shape[gshape] + " " + gem_colour[gcolour] + " gem", gem_colour[gcolour] + " gem", "gem");
   set_value(gem_value());
   set_long("This " + gem_shape[gshape] + " " + gem_colour[gcolour] + " gem, has a " + gem_cut[gcut] + ". " +
            "It is of a " + gem_size[gsize] + " size.");
#ifdef USE_SIZE
   set_size(0);
#endif
#ifdef USE_MASS
   set_weight(0.1 * (gsize * 1));
#endif
}

void mudlib_setup(int vc)
{
   set_id("gem");
   if (vc > 0)
      value_cap = vc;
   call_out("roll_gem", 1);
}

void internal_setup()
{
   this_object()->add_save(({"rolled", "gsize", "gshape", "gcolour", "gcut"}));
}