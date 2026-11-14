/* primitive sprintf fn so can load 3.2 mudlib on 3.1.2MSDOS */
/* accepts only %s, used in wizard.c  match_format() */


#ifndef SPRINTF_H
#define SPRINTF_H

varargs string sprintf(string format,
                          mixed arg1,
                          mixed arg2,
                          mixed arg3,
                          mixed arg4,
                          mixed arg5) {
  string pre, print_out;
  int i;
  
  print_out = "";
  while(sscanf(format,"%s\%%s",pre,format) && i < 5) {
    if(format != "" && format[0] != 's') {
      print_out += "%";
      continue;
    }
    format = extract(format,1);
    print_out += pre + ((i == 0)
               ? arg1
               : (i == 1)
               ? arg2
               : (i == 2)
               ? arg3
               : (i == 3)
               ? arg4
               : arg5);
    i++;
  }
  return print_out + format;
}

#endif  
