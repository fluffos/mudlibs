// A simple, cheap tallow candle for the chandler's shop
// Tune [22Apr99]

inherit "/obj/candle";

void create()
{
   ::create();
   SetLong("A tallow candle.\n");
   SetShort("a cheap tallow candle");
   AddAdjective( ({ "cheap", "tallow" }) );    
   SetValues(10, 0);   // candle worth 10, wick 0
}

varargs string QueryLong()
{
   if (QueryBurning())
      return "A cheap tallow candle. It is burning.\n";
   return ::QueryLong();
}
