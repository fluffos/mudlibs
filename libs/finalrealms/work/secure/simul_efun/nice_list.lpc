/*
 * Smooshes an array into a nice list one, two, and three! =) -- Magus Nov '96
 */
 
string nice_list(string *list) {
  if(sizeof(list) > 2) {
    list[sizeof(list)-1] = "and "+list[sizeof(list)-1];
    return implode(list, ", ");
  }
  if(sizeof(list) == 2)
    return list[0]+" and "+ list[1];
  if(sizeof(list) < 1) return "";
  return list[0];
}