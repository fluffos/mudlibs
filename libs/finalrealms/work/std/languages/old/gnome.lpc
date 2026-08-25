/*
 * The dwarven-like language of the Gnomes
 */
string garbler(string mess);

string long() {
  return "The gnomish language.\n";
}

mixed garble_say(string start, string mess) {
  mess = garbler(mess);
  return ({ start, mess });
}

mixed garble_shout(string start, string mess) {
  mess = garbler(mess);
  return ({ start, mess });
}
string garbler(string mess)
{
  mess = lower_case(mess);
  mess = implode(explode(mess, "c"), "kr");
  mess = implode(explode(mess, "l"), "d");
  mess = implode(explode(mess, "b"), "kk");
  mess = implode(explode(mess, "p"), "");
  mess = implode(explode(mess, "t"), "it");
  mess = implode(explode(mess, "n"), "b");
  mess = implode(explode(mess, "e"), "a");
  mess = implode(explode(mess, "a"), "e");
  mess = implode(explode(mess, "d"), "r");
  mess = implode(explode(mess, "ck"), "kk");
  mess = implode(explode(mess, "h"), "");
  mess = implode(explode(mess, "ave"), "ath");
  mess = implode(explode(mess, "I"), "Jeg");
  mess = implode(explode(mess, "s"), "kha");
  mess = implode(explode(mess, "v"), "ou");
  mess = implode(explode(mess, "n"), "");
  mess = implode(explode(mess, "f"), "k");
  return capitalize(mess);
}
