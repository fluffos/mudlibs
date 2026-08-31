/* Do not remove the headers from this file! see /USAGE for more info. */

inherit JUNK;

void setup()
{
   string what = choice(({"car", "truck", "motorcycle", "racecar", "horse", "wagon"}));
   string adj = choice(({"small", "metal", "blue", "dented", "old", "rusty"}));
   set_id(what + " toy", what, "toy");
   set_adj(adj);
   set_salvageable((["mechanic":50, "metal":30, "plastic":20]));
   set_long("A small " + adj + " toy, a bit dented and worn. Meant for kids probably?");
   set_weight(1);
}