#ifndef NEWLINE_H
#define NEWLINE_H

string add_newline(string str) {
  string lchar;

  if(!str) return "\n";
  lchar = extract(str,strlen(str)-1);
  return (lchar == "!" || lchar == "." || lchar == "?")
     ? str + "\n"
     : (lchar == "\n")
     ? str
     : str + ".\n";
}

#endif
