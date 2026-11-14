inherit "/std/food";

void create() {
	food::create();

	SetShort("a fried chicken");
	AddId("chicken");
	AddAdjective("fried");
	SetLong("It looks delicious... you get really hungry.\n");
	SetFoodMsgs(({"It tastes delicious.\n"}));
	/* Or, if you wanna let the environment have fun too:
	SetFoodMsgs(({"It tastes delicious.\n",
	  "@@Pl_Name@@ eats a fried chicken.\n"}));
	*/
	SetFoodStuff(10);
	/* Fried chickens are normally alcohol-free and do not heal either
	 */
	SetWeight(750);
	SetValue(0);	/* calculated automatically */
}
