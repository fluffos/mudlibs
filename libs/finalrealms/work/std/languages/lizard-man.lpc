/*
 * The hissing language of the lizard-men.
 */
string garbler(string mess);

string long() {
  return "Consists of the hissing lizard-man language.\n";
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
  mess = implode(explode(mess, "k"), "ssk");
  mess = implode(explode(mess, "r"), "rr");
  mess = implode(explode(mess, "g"), "s");
  mess = implode(explode(mess, "p"), "ssp");
  mess = implode(explode(mess, "t"), "tss");
  mess = implode(explode(mess, "y"), "i");
  mess = implode(explode(mess, "e"), "a");
  mess = implode(explode(mess, "a"), "e");
  mess = implode(explode(mess, "d"), "");
  mess = implode(explode(mess, "ick"), "issk");
  mess = implode(explode(mess, "b"), "");
  mess = implode(explode(mess, "ave"), "ass");
  mess = implode(explode(mess, "I"), "Ssa");
  mess = implode(explode(mess, "j"), "gh");
  mess = implode(explode(mess, "v"), "sou");
  mess = implode(explode(mess, "q"), "");
  mess = implode(explode(mess, "f"), "fs");
  return capitalize(mess);
}
