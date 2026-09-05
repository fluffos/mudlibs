#ifndef NEWLINE_H
#define NEWLINE_H

string add_newline(string str) {
  string lchar;

  if (!str) return "\n";

  lchar = str[0..strlen(str)-1];
  return (lchar == "!" || lchar == "." || lchar == "?")
     ? str + "\n"
     : (lchar == "\n")
     ? str
     : str + ".\n";
}

#endif /* NEWLINE_H */

