int receive(string msg) {
  // we want to do escape sequence translation here...
  // %^COLOR%^, %^RESET%^, %^PUSH%^, %^POP%^, etc.
  //if(nm = TERM_H -> escape_string(previous_object(), msg))
  //  return efun::receive(nm);
  //else
    return efun::receive(msg);
}
