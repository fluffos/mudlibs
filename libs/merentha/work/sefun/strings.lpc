#include <daemons.h>

string right_align(string str, int size) {
  if(!size) return str;
  if(strlen(str)>size) return str;
  while(strlen(str)<size) str=" "+str;
  return str;
}

string strip_colours(string str) {
    mapping cols=COLOUR_D->query_ansi();
    string *colours=keys(cols);
    int i=sizeof(colours);
    while(i--) if(str) str=replace_string(str, "%^"+colours[i]+"%^", "");
    return str;
}

string restore_colours(string str) {
    mapping cols=COLOUR_D->query_ansi();
    string *colours=keys(cols);
    int i=sizeof(colours);
    while(i--) str=replace_string(str,cols[colours[i]], "%^"+colours[i]+"%^");
    return str;
}

varargs string arrange_string(string str, int i) {
    if(!i || i<2) i=75;
    i+=(strlen(str)-strlen(strip_colours(str)));
    if(strlen(str)>=i) return str[0..(i-1)];
    i-=strlen(str);
    while(i--) str+=" ";
    return str;
}  

varargs string wrap(string str, int i, int j) {
    if(!str) return "";
    if(!j) return terminal_colour(str, COLOUR_D->query_ansi(),(i?i:75));
    return restore_colours(terminal_colour(str, COLOUR_D->query_ansi(),(i?i:75)));
}

varargs string center(string str, int i) {
    string *strs=explode(wrap(str, (i?i:75), 1), "\n");
    string tmp;
    int x=sizeof(strs);
    if (!i || i< 10) i=75;
    while(x--) {
        tmp=arrange_string("",to_int((i-strlen(strip_colours(strs[x])))/2));
        strs[x]=tmp+strs[x]+tmp;
    }
    return implode(strs, "\n");
}

varargs string border(string str, string title, int i) {
    string *strs=explode(wrap(str, (i?i-4:71), 1), "\n");
    string tmp, line="|";
    int x=sizeof(strs), y;

    if(!i || i<10) i=75;
    y=i-2;
    while(y--) line+="-"; line+="|";
    i-=4;
    y=0;
    while(y<x) {
      if(strs[y]=="__BORDER_LINE__") {
         strs[y]="%^RESET%^%^BLUE%^"+line;
         y++;
         continue;
      }
      sscanf(strs[y], "%%^%s%%^%s", tmp, strs[y]);
      if(!tmp) tmp="";
      strs[y]="%^RESET%^%^BLUE%^|%^RESET%^ "+arrange_string(replace_string((tmp!=""?"%^"+tmp+"%^":"")+strs[y],"\n", ""), i)+" %^RESET%^%^BLUE%^|";
      y++;
    }
    str="";
    x=i+4;
    while(x--) str+="-";
    tmp=" %^RESET%^%^BLUE%^`"+str[2..<3]+"'";
    if(title)
        str=arrange_string(str, (i-strlen(title))/2)+"%^BOLD%^%^BLUE%^<%^MAGENTA%^ "+title+" %^BOLD%^%^BLUE%^>%^RESET%^%^BLUE%^"+arrange_string(str, (i-strlen(title))/2);
    if( i%2 != strlen(str)%2) str+="-";
    str=" ,"+str[2..<3]+".";
    return "%^RESET%^%^BLUE%^"+str+"\n"+implode(strs, "\n")+"\n"+tmp;
}

varargs string format_page(string *items, int cols, int i) {
    string tmp="";
    int x, y, z=sizeof(items);
    if(!i) i=75;
    if(!cols) cols=2;
    i-=cols+1;
    for(x=0;x<z;x+=cols) {
        for(y=0;y<cols;y++)
            if(z>x+y)
                tmp+=arrange_string(items[x+y], to_int(i/cols));
        if(z>x+y) tmp+="\n";
    }
    return tmp+"\n";
}

