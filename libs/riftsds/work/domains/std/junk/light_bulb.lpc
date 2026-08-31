/* Do not remove the headers from this file! see /USAGE for more info. */

inherit JUNK;

void setup()
{
   set_id("light bulb", "bulb");
   if (random(2))
   {
      set_adj("broken");
      set_direct_salvage((["copper scrap":1, "glass shard":1]));
   }
   else
      set_direct_salvage((["copper scrap":1, "glass shard":2]));

   set_long("A simple white light bulb, cracked on one side.");
   set_weight(1);
}