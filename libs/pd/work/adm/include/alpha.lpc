//  Alphabitization Sefun
//    Whit
string *l_alpha = ({"a","b","c","d","e","f","g","h","i","j",
  "k","l","m","n","o","p","q","r","s","t","u","v","w","x",
  "y","z"});
string *c_alpha = ({"A","B","C","D","E","F","G","H","I","J",
  "K","L","M","N","O","P","Q","R","S","T","U","V","W","X",
  "Y","Z",});
int is_lowercase(string letter) {
    if(strlen(letter) != 1 && strlen(letter) != 0) return error("Invalid argument "
          "type to is_lowercase.  Function only accepts 1 letter.\n"
          "Argument was "+letter+".\n");
    if(member_array(letter, l_alpha)!=-1) return 1;
    return 0;
}
int is_capitalized(string letter) {
    if(strlen(letter) != 1 && strlen(letter) != 0) return error("Invalid argument "
          "type to is_capitalize.  Function only accepts 1 letter.\n"
          "Argument was "+letter+".\n");
    if(member_array(letter, c_alpha)!=-1) return 1;
    return 0;
}
