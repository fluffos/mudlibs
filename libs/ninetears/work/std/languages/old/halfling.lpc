string garbler(string mess);
string long() {
  return "The halfling language.\n";
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
  mess = implode(explode(mess, "k"), "bo");
  mess = implode(explode(mess, "r"), "ni");
  mess = implode(explode(mess, "g"), "l");
  mess = implode(explode(mess, "p"), "");
  mess = implode(explode(mess, "t"), "h");
  mess = implode(explode(mess, "i"), "a");
  mess = implode(explode(mess, "e"), "o");
  mess = implode(explode(mess, "a"), "e");
  mess = implode(explode(mess, "d"), "g");
  mess = implode(explode(mess, "o"), "y");
  mess = implode(explode(mess, "h"), "t");
  mess = implode(explode(mess, "v"), "k");
  mess = implode(explode(mess, "I"), "Mei");
  mess = implode(explode(mess, "s"), "d");
  mess = implode(explode(mess, "v"), "s");
  mess = implode(explode(mess, "b"), "r");
  mess = implode(explode(mess, "f"), "v");
  return capitalize(mess);
}
