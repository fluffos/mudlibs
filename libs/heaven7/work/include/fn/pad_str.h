#ifndef PAD_STR_H
#define PAD_STR_H

string pad_str(string prefix,string str,int len) {
  int pad_len, i;
  string pad, tmp_str, new_str;

  pad_len = strlen(prefix);
  pad = "                                             "+
        "                                             ";
  pad = extract(pad,0,pad_len-1);
  str = prefix + str + " "; /* space flags end of string */
  new_str = "";
  if(len < 1 || len > 79) len = 75; /* line length */
  while(str && strlen(str)) {
    if(new_str != "") str = "\n"+ pad+str;
    tmp_str = extract(str,0,len); /* get 1 line */
    for(i = strlen(tmp_str)-1; i >= pad_len && tmp_str[i] != ' '; i--);
    if(i <= pad_len) i = strlen(tmp_str)-2; /* no spaces! */
    tmp_str = extract(str,0,i);
    str = extract(str,i+1);
    new_str += tmp_str;
  }
  return new_str +"\n";
}

#endif
