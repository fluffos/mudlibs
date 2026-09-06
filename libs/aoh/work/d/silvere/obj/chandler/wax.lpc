// A wax candle for the chandler's shop in Silvere
// Tune [22Apr99]

inherit "/obj/candle";

void create()
{
   ::create();
   SetLong("A smooth, white candle of pure beeswax.\n");
   SetShort("a beeswax candle");
   AddAdjective( ({ "white", "beeswax", "wax", "smooth", "pure" }) );
   SetValues(18, 0);   // candle worth 18, wick 0
}

varargs string QueryLong()
{
   if (QueryBurning())
      return "A smooth, white candle of pure beeswax. It is burning.\n";  
   return ::QueryLong();
}
