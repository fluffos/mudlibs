string domain_file(string file) {
  string *bits;
 
  bits = explode(file, "/");

  // wizards
  if(bits[0] == "w" && sizeof(bits) > 2)
    return bits[2];

  // projects
  if(bits[0] == "p" && sizeof(bits) > 2)
    return "PROJECT:" + bits[2];

  // mud core
  if(bits[0] == "room")
    return "BACKBONE";

  return "NONAME";
}
