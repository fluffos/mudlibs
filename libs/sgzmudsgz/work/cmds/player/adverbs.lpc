// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;
inherit M_GLOB;

#define HEADER  "--------------------------------<  副词  >-------------------------------\n"
#define TRAILER "-------------------------<  找到 %4d/%4d  (%3d%%)  >------------------------\n"

private void main(string arg)
{
    string * list;
    int count;

    printf("对不起，三国中目前没有副词系统。\n");
    return;
    list = SOUL_D->get_adverbs();
    count = sizeof(list);

    if ( !arg || arg == "" )
        arg = "*";
    else if ( !has_magic(arg) )
        arg = arg + "*";
    arg = "^"+translate(arg)+"$";
    list = regexp(list, arg);
    if ( !list )
    {
        outf("没有与 %s 对应的副词。\n", arg);
        return;
    }

    if(end_of_pipeline())
      outf(HEADER "%-#79s\n" TRAILER, 
                 implode(sort_array(list, 1), "\n"),
                 sizeof(list), count, sizeof(list) * 100 / count);
    else
      outf(HEADER "%s\n" TRAILER, implode(sort_array(list, 1), "\n"),
           sizeof(list), count, sizeof(list) * 100 / count);

}

void player_menu_entry(string str)
{
  bare_init();
  ZBUG(str);
  main(str);
  done_outputing();
}
