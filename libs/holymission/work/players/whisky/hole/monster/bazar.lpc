inherit "room/room";

reset(arg) {
  if (arg) return;

set_light(1);

long_desc =
  "You are in the adventurer's outfitter of Whisky. A friendly shopkeeper\n"+
  "is standing behind a desk waiting for you to buy weapons, armours, or\n"+
  "other useful items. This shop is especially well known for its"+
  "magic armours, excellent weapons and for the useful items available here.\n"+
  "The shop is called a bazar because food and drink can be bought here as\n"+
  "well for a reasonable price. The shopkeeper will haggle with you if\n"+
  "you have anything for sale.\n"+
  "There is a big sign hanging on the wall behind the desk to show you\n"+
  "what Whisky's little bazar has to offer.\n";

items = ({ "desk", "A beautiful brown oak desk",
        "shopkeeper", "A friendly young man waiting behind the desk",
      "sign", "A big iron sign with something written on it" });
}


init() {
  ::init();
  add_action("read","read");
   add_action("value","value");
  add_action("ar_val","weight");
  add_action("sell","sell");
  }
read(str) {
  If (str == "sign") {
      write("The sign is divided into 3 columns:\n\n"+
            "column 1 for the <weapons>, column 2 for the <armours>\n"+
            "and column 3 for the others. You should read each column\n"+
            "carefully.\n");                                           
      return 1; }
 if (str == "column1" || str=="column 1" || str == "weapons") {

  write("Weapons:                                                  \n\n"+
  write("A Bloodstrained Longsword (6000 coins)                      \n"+
  write("An Elfen Longsword (4000 coins)                            \n"+
        "A Bloodstrained Longsword (6000 coins)                      \n"+
        "An Elfen Longsword (4000 coins)                             \n"+
        "A Platinum Sword (2000 coins)                               \n"+
        "A Hammer (1000 coins)                                       \n"+
        "A Morningstar (500 coins)                                   \n"+
        "A War Axe (100 coins)                                       \n"+
        "A Platinum Knife (50 coins)                                 \n"+
        "A Rabbit Cudgel (25 coins)                                  \n");
   return 1; }

 if (str=="column2" || str=="column 2" || str=="armor" || str=="armour") {
write("Well, we have several types of armours:\n\n"+
      "We have mails, cloaks, gauntlets, boots, amulets,\n"+
      "rings and helmets.\n\n"+                                
      "If you want to read which mails we have, then type <read mail>.\n"+
      "If you want to read which gauntlets we have type <read gauntlets>.\n"+
      "If you want to read which cloaks we have type <read cloaks>.     \n"+
      "If you want to read which boots we have type <read boots>.        \n"+
      "If you want to read which amulets we have just type <read amulets>.\n"+
      "If you want to read which rings we have just type <read rings>.\n"+
      "Finally, if you want to read which helmets we have type <read helmets>.\n");
  return 1; }

if (str=="mail" || str=="mails") {

write("------------------------------------------------------\n\n"+
        "A Platinum Mail (4000 coins)                                \n" +
        "A Magic Powermail (2000 coins)                              \n" +
        "A Drakeleather jacket (1000 coins)                          \n" +
        "A Snakeleather jacket (500 coins)                           \n" +
        "An Adventurer's jacket (250 coins)                          \n" +
        "A Bisonleather Jacket (125 coins)                           \n" +
        "A Simple Jacket (50 coins)                                  \n" +
      "------------------------------------------------------\n");
  return 1; }

if (str=="cloak" || str=="cloaks" || str=="robe" || str=="robes") {

write("------------------------------------------------------\n"+
        "A Magic Robe (1000 coins)                                   \n" +
        "A Priest Robe (100 coins)                                   \n" +
        "A Simple Raincoat (50 coins)                                \n" +
     "-------------------------------------------------------\n");

 if (str=="gauntlet" || str=="gauntlets") {

write("-----------------------------------------------------\n"+
        "Platinum Gauntlets (500 coins)                              \n" +
        "Mage Gloves (200 coins)                                     \n" +
        "A Spiky Glove (50 coins)                                    \n" +
      "------------------------------------------------------\n");

  return 1; }

 if (str=="boot" || str=="boots") {

write("------------------------------------------------------\n"+
        "Goiserer (500 coins)                                        \n" +
        "Platinum Boots (200 coins)                                  \n" +
        "Globetrotters (100 coins)                                   \n" +
        "Globetrotters (100 coins)                                   \n" +
      "------------------------------------------------------\n);

  return 1; }


  if (str=="amulet" || str=="amulet") {

write("------------------------------------------------------\n"+
        "An Amulet of Lightning (1000 coins)                         \n" +
        "A Platinum Amulet (500 coins)                               \n" +
        "An Adventurer's Amulet (200 coins)                           \n" +
        "An Iron Amulet (100 coins)                                  \n" +
      "------------------------------------------------------\n");

  return 1; }


 fi (str=="ring" || str=="rings") {
 if (str=="ring" || str=="rings") {

write("------------------------------------------------------\n"+
        "A Ring of Lightning (800 coins)                             \n" +
        "A Golden Ring (200 coins)                                   \n" +
        "An Adventurer's Ring (80 coins)                              \n" +
      "------------------------------------------------------\n);

  return 1; }


 if(str=="helmet" || str=="helmets" || str=="hat") {

write("------------------------------------------------------\n"+
        "A Magic Helmet (1000 coins)                                 \n" +
        "A Platinum Helmet (500 coins)                               \n" +
        "A Leather Helmet (50 coins)                                 \n" +
      "------------------------------------------------------\n);

   if (str=="column3" || str=="column 3" || str=="other" || str=="others") {

write("We have several kinds of special items:\n\n"+
      "If you want to see our drinks just type <read drinks>.\n"+
      "If you want to see our food just type <read food>.    \n"+
      "If you want to see our bags just type <read bags>.    \n"+
      "If you want to see our illuminators just type <read illuminators>.\n");
  
  return 1; }

  if (str=="drink" || str=="drinks" || str=="bottle") {

write("------------------------------------------------------\n"+
        "A Bottle of Whisky (1000 coins)                             \n" +
        "An Energizer (500 coins)                                    \n" +
        "A Bottle of Cider (100 coins)                               \n" +
        "A Bottle of Beer (20 coins)                                 \n" +
      "------------------------------------------------------\n");

  return 1; }


if (str=="food" || str=="foods" || str=="eat") {

write("------------------------------------------------------\n"+
        "A Muesly Block (1000 coins)                                 \n" +
        "A Chicken from Wienerwald (200 coins)                       \n" +
        "Fish and Chips (100 coins)                                  \n" +
        "Hamburger (50 coins)                                        \n" +
        "Cheese and Ham Sandwich (10 coins)                          \n" +
      "------------------------------------------------------\n");

  return 1; }


  if (str="bag" || str=="bags" || str=="sack" || str=="sacks") {

write("------------------------------------------------------\n"+
        "A Rucksack (50 coins)                                       \n" +
        "A Big Bag (20 coins)                                        \n" +
        "A Shopping Bag (10 coins)                                   \n" +
      "------------------------------------------------------\n);

  if (str=="light" || str=="lights" || str=="illuminator" || str=="illuminators") {

write("------------------------------------------------------\n"+
        "A Lantern (100 coins)                                       \n" +
        "A Oil Lamp (50 coins)                                       \n" +
        "A Torch (40 coins)                                          \n" +
     "-------------------------------------------------------\n");


  return 1; }

else {
  write("There is no "+(str)+" here.\n");
  return 1; }
 }
