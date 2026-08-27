/*
 * The wonderful singing language of the elves.
 * Was....
 */
string garbler(string mess);

string long() {
  return "De chickenee.\n";
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
  mess = implode(explode(mess, "an"), "un");
  mess = implode(explode(mess, "An"), "Un");
  mess = implode(explode(mess, "au"), "oo");
  mess = implode(explode(mess, "Au"), "Oo");
  mess = implode(explode(mess, "a"), "e");
  mess = implode(explode(mess, "A"), "E");
  mess = implode(explode(mess, "en"), "ee");
  mess = implode(explode(mess, "a"), "e");
  mess = implode(explode(mess, "ew"), "oo");
  mess = implode(explode(mess, "e"), "i");
  mess = implode(explode(mess, "E"), "I");
  mess = implode(explode(mess, "f"), "ff");
  mess = implode(explode(mess, "ir"), "ur");
  mess = implode(explode(mess, "i"), "ee");
  mess = implode(explode(mess, "ow"), "oo");
  mess = implode(explode(mess, "o"), "oo");
  mess = implode(explode(mess, "O"), "Oo");
  mess = implode(explode(mess, "the"), "zee");
  mess = implode(explode(mess, "The"), "Zee");
  mess = implode(explode(mess, "th"), "t");
  mess = implode(explode(mess, "tion"), "shun");
  mess = implode(explode(mess, "v"), "f");
  mess = implode(explode(mess, "V"), "F");
  mess = implode(explode(mess, "w"), "v");
  mess = implode(explode(mess, "W"), "v");
  mess = implode(explode(mess, "."), "bork.bork.bork");
  return capitalize(mess);
}
