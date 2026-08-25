/*
 * The wonderful singing language of the elves.
 */
string garbler(string mess);

string long() {
  return "Consists of the standard human language.\n";
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
  mess = implode(explode(mess, "k"), "v");
  mess = implode(explode(mess, "r"), "g");
  mess = implode(explode(mess, "g"), "r");
  mess = implode(explode(mess, "p"), "t");
  mess = implode(explode(mess, "t"), "p");
  mess = implode(explode(mess, "y"), "i");
  mess = implode(explode(mess, "e"), "a");
  mess = implode(explode(mess, "a"), "e");
  mess = implode(explode(mess, "d"), "m");
  mess = implode(explode(mess, "m"), "d");
  mess = implode(explode(mess, "h"), "s");
  mess = implode(explode(mess, "t"), "b");
  mess = implode(explode(mess, "I"), "Jeg");
  mess = implode(explode(mess, "s"), "h");
  mess = implode(explode(mess, "v"), "k");
  mess = implode(explode(mess, "f"), "v");
  return capitalize(mess);
}
