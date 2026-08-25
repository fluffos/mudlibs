string garbler(string mess);
string long (){
  return "Consists of the crude barbarian tongue. \n";
}
mixed garble_say(string start, string mess){
  mess = garbler(mess);
  return ({start, mess});
}
mixed garble_shout(string start, string mess){
  mess = garbler(mess);
  return ({ start, mess });
}
string garbler(string mess){
  mess = implode(explode(mess, "I am"), "Me");
  mess = implode(explode(mess, "very"), "heap");
  mess = implode(explode(mess, "I"), "Me");
  mess = implode(explode(mess, "I will"), "Ah'll");
  mess = implode(explode(mess, "I'll"), "Ah'll");
  mess = implode(explode(mess, "to"), "");
  mess = implode(explode(mess, "they"), "them");
  mess = implode(explode(mess, "we"), "us");
  mess = implode(explode(mess, "aren't"), "not");
  mess = implode(explode(mess, "are not"), "not");
  mess = implode(explode(mess, "are"), "");
  mess = implode(explode(mess, "is"), "");
  return capitalize(mess);
}
