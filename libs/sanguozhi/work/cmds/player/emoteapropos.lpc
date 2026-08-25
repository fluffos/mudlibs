// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

nomask private void main(string str) {
    if (!str) {
        write("用法：emoteapropos string\n");
        return;
    }

    out(implode(({ "包含 " + str + "的情感词汇有："}) + SOUL_D->emote_apropos(str),"\n"));
}

void player_menu_entry(string str)
{
  bare_init();
  main(str);
  done_outputing();
}
