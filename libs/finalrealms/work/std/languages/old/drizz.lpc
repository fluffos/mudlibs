string garbler(string mess);
string long (){
   return "Tha lingo of tha chill ranger,Drizzt.\n";
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
    mess = implode(explode(mess, "s "), "z ");
    mess = implode(explode(mess, "was"), "wuz");
    mess = implode(explode(mess, "the"), "tha");
    mess = implode(explode(mess, "to"), "ta");
  return capitalize(mess);
}
