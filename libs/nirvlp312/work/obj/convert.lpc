/*
 * Money Converter
 *
 * This will convert all players' copper coins to give a message of
 * how many platinum, gold, silver, and copper coins they have.
 * When a player receives money, it will automatically renew all
 * coins into lowest denominator amounts; first platinum, then gold
 * then silver, and finally copper
 *
 */

#define GOLD   1000
#define SILVER 100
#define COPPER 1

string convert(int i) {
  string tmp;

  tmp = "";
  if    (i >= GOLD)   tmp += (i/GOLD + " gold ");
  while (i >= GOLD)   i -= GOLD;
  if    (i >= SILVER) tmp += (i/SILVER + " silver ");
  while (i >= SILVER) i -= SILVER;
  if    (i) tmp += (i + " copper ");
  return tmp;
}

