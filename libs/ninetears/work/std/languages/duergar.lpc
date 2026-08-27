/*
 * This is the dwarven language hacked by myself, Roan...please forgive.
 */

string garbler(string mess);

string long() {
  return "The duergar language.\n";
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
  mess = implode(explode(mess, "c"), "ka");
  mess = implode(explode(mess, "l"), "d");
  mess = implode(explode(mess, "b"), "bg");
  mess = implode(explode(mess, "p"), "");
  mess = implode(explode(mess, "t"), "it");
  mess = implode(explode(mess, "i"), "y");
  mess = implode(explode(mess, "e"), "a");
  mess = implode(explode(mess, "a"), "e");
  mess = implode(explode(mess, "ck"), "kk");
  mess = implode(explode(mess, "h"), "");
  mess = implode(explode(mess, "ave"), "arv");
  mess = implode(explode(mess, "I"), "Jeg");
  mess = implode(explode(mess, "v"), "ou");
  mess = implode(explode(mess, "n"), "");
  mess = implode(explode(mess, "f"), "k");
mess = implode(explode(mess, "z"), "zha");
mess = implode(explode(mess, "th"), "thr");
mess = implode(explode(mess, "wh"), "wva");
  return capitalize(mess);
}
