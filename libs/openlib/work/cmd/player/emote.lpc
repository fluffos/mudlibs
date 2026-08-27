// emote.c
//  This command will call the emote_parse func from EMOTE_D to handle
//  the output of the emote.
//  Lol 11/04/95

#include <command.h>
#include <daemons.h>

int main(string str) {
  if(!str) {
    notify_fail("You exist.\n");
  return 0;
  }
  EMOTE_D->emote_parse(str);
  return 1;
}
