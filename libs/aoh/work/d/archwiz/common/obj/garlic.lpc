inherit "std/food";

void create() {
 ::create();
 SetAds(({"white","clove","of","stinky"}));
 SetIds(({"clove","garlic","spice"}));
 SetShort("a clove of garlic");
 SetSmell("It stinks!!!\n");
 SetLong(
"A white clove of garlic. Vampires won't like this.\n");
 SetWeight(300);
 SetFoodKind("food");
 SetFoodStuff(0);
 SetFoodHeal(2);
 SetFoodMsgs(({"You eat the garlic.\n","@@Pl_Name@@ eat some garlic.\n"}));
 SetValue(5);
}

int consume(string str) {
  if (!this_player()) return 0;
  if (!id(str)) return 0;
  this_player()->SetSmell(this_player()->QueryName()+" smells of garlic!\n");
  ::consume(str);
  return 1;
}
