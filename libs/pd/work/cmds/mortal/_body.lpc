//      /bin/user/_body.c
//      from the Nightmare Mudlib
//      lists damaged body parts in order of distress
//      created by Descartes of Borg 12 july 1993

#include <std.h>

inherit DAEMON;

int cmd_body(string str) {
    string *limbs, arr, go;
    int i, x;

    if(this_player()->query_ghost()) {
        notify_fail("You have no body to check on!\n");
        return 0;
    }
    go = "";
    i = sizeof(limbs = sort_array((string *)this_player()->query_limbs(),
      "sort_by_damage", this_object()));
  write("%^BLUE%^=+=+=%^BOLD%^(%^WHITE%^ Body %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
  while(i--) {
      x = to_int(percent((int)this_player()->query_dam(limbs[i]),
          (int)this_player()->query_max_dam(limbs[i])));
      if(x > 70)
          arr = "%^BOLD%^%^RED%^"+arrange_string(capitalize(limbs[i])+" %^RESET%^%^CYAN%^is damaged:%^RESET%^ ", 31)+x+" %";
      else
          arr = arrange_string(capitalize(limbs[i])+" %^CYAN%^is damaged:%^RESET%^ ", 31)+x+" %";
      if(x < 10)
          arr = arr + " ";
      if ((i-1) >=0)
       {
        go += arr+"      ";
        x = to_int(percent((int)this_player()->query_dam(limbs[i-1]),
        (int)this_player()->query_max_dam(limbs[i-1])));

        if(x > 70)
            arr = "%^BOLD%^%^RED%^"+arrange_string(capitalize(limbs[i-1])+" %^RESET%^%^CYAN%^is damaged:%^RESET%^ ", 31)+x+" %";
        else
            arr = arrange_string(capitalize(limbs[i-1])+" %^CYAN%^is damaged:%^RESET%^ ", 31)+x+" %";
        if(x < 10)
            arr = arr + " ";
        go +=  arr;
        write(go);
        go="";
        i--;
       }
      else
          write(arr);
    }
  write("%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
  return 1;
}

int sort_by_damage(string alpha, string beta) {
    float a, b;

    a = percent((int)this_player()->query_dam(alpha), 
      (int)this_player()->query_max_dam(alpha));
    b = percent((int)this_player()->query_dam(beta), 
      (int)this_player()->query_max_dam(beta));
    if(a > b) return 1;
    else if( a < b ) return -1;
    else return 0;
}
void help() {
   write("Syntax: body\n\n"+
         "This is a status of the damage done to your limbs.\n"+
         "This is not like hp!  The larger the damage value,\n"+
         "the worse shape you are in. To mcuh damage might allow\n"
         "something to be severed.\n"
         "See also: score\n"
   );
}
