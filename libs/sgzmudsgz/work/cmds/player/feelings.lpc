// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;
inherit M_GLOB;

#define HEADER  "--------------------------------<  情感词汇  >-------------------------------\n"
#define TRAILER "------------------------<  找到 %4d/%4d  (%3d%%)  >------------------------\n"
#define TOO_DAMN_LONG 15

private void main(string arg)
{
    string * list;
    int count;
    string * too_damn_long;
    string * not_too_long;

    list = sort_array(SOUL_D->list_emotes(), 1);
    count = sizeof(list);

    if ( !arg || arg == "" )
        arg = "*";
    else if ( !has_magic(arg) )
        arg = arg + "*";
    arg = "^"+translate(arg)+"$";
    list = regexp(list, arg);
    if ( !list )
    {
        printf("没有与 '%s' 对应的情感词汇。\n", arg);
        return;
    }
    too_damn_long = filter(list, (: sizeof($1) >= TOO_DAMN_LONG :));
    not_too_long = filter(list, (: sizeof($1) < TOO_DAMN_LONG :));

    if(end_of_pipeline())
      out(HEADER + sprintf("%-#79s\n", implode(not_too_long, "\n")));
    else
      outf("%s\n", implode(not_too_long, "\n"));
    if ( sizeof(too_damn_long) )
    {
      if(end_of_pipeline())
        out("\n特长的词汇：\n");
        out(implode(too_damn_long, "\n") + "\n");
    }
    outf(TRAILER, sizeof(list), count, sizeof(list) * 100 / count);
}

void player_menu_entry(string str)
{
  bare_init();
  main(str);
  done_outputing();
}
