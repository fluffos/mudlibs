/* An example firebreather, not bottled
 * mimics the drinks served in Orb's minibar
 */
inherit "/std/food";

string pl;

void create() {
	::create();
	SetFoodKind("drink");
	SetShort("a firebreather");
	AddId("firebreather");
	SetLong(
"This object (/d/archwiz/common/health/exdrink1.c) features a drink created "+
"with /std/food.\n"+
"This bottle contains some very fine 25-year-old firebreather.\n");
	SetFoodMsgs(({"Ahhhh... this goes down smoothly.\n"
"The bottle vanishes as part of the intergalactic anti-litter program.\n",
	"@@Pl_Name@@ drinks a whole bottle of firebreather! "
"A bottle vanishes in @@QueryName:"+pl+"@@'s hands.\n"}));
	SetFoodAlc(12);
	SetFoodHeal(25);
	SetWeight(750);	/* grams */
	SetValue(0);	/* calculated automagically */
}
