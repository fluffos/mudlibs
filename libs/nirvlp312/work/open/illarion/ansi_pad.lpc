#define ESC ""
#define NORM ESC+"[2;37;0m"
string ansi_pad(string str,int limit) {
  status neg;
  int x,ansi_skip,truelen;
  string *chars;
  string spad;
  chars=explode(str,"");
  ansi_skip=0;
  truelen=0;
  if(limit<0) {
    neg=1;
    limit=-limit;
  }
  for(x=0;x<sizeof(chars);x++) {
    if(ansi_skip) {
      if(chars[x]=="m")
        ansi_skip=0;
      continue;
    }
    if(chars[x]==ESC) {
      ansi_skip=1;
      continue;
    }
    truelen++;
    if(truelen>=limit) break;
  }
  if(truelen<limit)
    spad=pad("",limit-truelen);
  else
    spad="";
  if(neg)
    return spad+extract(str,0,x)+NORM;
  else
    return extract(str,0,x)+spad+NORM;
}

varargs string ansi_format(string str,int cols) {
  int x,ansi_skip,truelen,last_ws;
  string *chars;
  status good_ws,final_newline;
  chars=explode(str,"");
  ansi_skip=0;
  truelen=0;
  good_ws=0;
  final_newline=0;
  if(cols==0) cols=78;
  else if(cols < 10) cols=10;
  for(x=0;x<sizeof(chars);x++) {
    if(ansi_skip) {
      if(chars[x]=="m") {
        ansi_skip=0;
      }
      continue;
    }
    if(chars[x]==ESC) {
      ansi_skip=1;
      continue;
    }
    if(chars[x]==" ") {
      good_ws=1;
      last_ws=x;
    }
    if(chars[x]=="\n") {
      truelen=0;
      good_ws=0;
      final_newline=1;
      continue;
    }
    truelen++;
    final_newline=0;
    if(truelen>=cols) {
      if(good_ws) {
        chars[last_ws]="\n";
        x=last_ws; 
      } else {
        chars[x]+="\n";
        final_newline=1;
      }
      truelen=0;
      good_ws=0;
    }
  
  }
  return implode(chars,"")+(final_newline?"":"\n");
}
