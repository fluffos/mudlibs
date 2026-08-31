#include <std.h>

inherit OBJECT;

string extra_look();

void create() {
  ::create();
  set_short("Wraith's Picture");
    set_long( (: extra_look() :) );
  set_name("picture12");
  set_id(({"picture12"}));
  set_weight(1);
}

string extra_look() {
  string ret;
ret = write(@ENDTEXT

%^BOLD%^%^WHITE%^                               ,-.
%^BOLD%^%^WHITE%^          ___,---.__          /'|`\          __,---,___
%^BOLD%^%^WHITE%^       ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.
%^BOLD%^%^WHITE%^     ,'        |           ~'\     /`~           |        `.
%^BOLD%^%^WHITE%^    /      ___//              `. ,'          ,  , \___      \
%^BOLD%^%^WHITE%^   |    ,-'   `-.__   _         |        ,    __,-'   `-.    |
%^BOLD%^%^WHITE%^   |   /          /\%^BOLD%^%^RED%^_ %^WHITE%^ `   %^WHITE%^.    |    ,      %^BOLD%^%^RED%^_%^WHITE%^/%^WHITE%^\         %^BOLD%^%^RED%^ \   |
%^BOLD%^%^WHITE%^   \  |          %^WHITE%^ \ %^BOLD%^%^RED%^\`-.___ %^WHITE%^\   |   /%^BOLD%^%^RED%^ ___,-'/ %^WHITE%^/          %^BOLD%^%^RED%^ |  /
%^BOLD%^%^WHITE%^   %^BOLD%^%^RED%^ \  \ %^WHITE%^          | %^BOLD%^%^RED%^`._   `\%^WHITE%^\  |  /%^BOLD%^%^RED%^/'   _,' %^WHITE%^|         %^BOLD%^%^RED%^  /  /
%^BOLD%^%^WHITE%^    %^BOLD%^%^RED%^  `-.\%^WHITE%^         /'  _ %^BOLD%^%^RED%^`---'%^WHITE%^' , . `%^BOLD%^%^RED%^`---' %^WHITE%^_  `\        %^BOLD%^%^RED%^ /,-'
%^BOLD%^%^WHITE%^     %^BOLD%^%^RED%^    ``%^WHITE%^       /     \    ,='/ \`=.    /     \       ''
%^BOLD%^%^WHITE%^                |__   /|\_,--.,-.--,--._/|\   __|
%^BOLD%^%^WHITE%^                /  `./  \\`\ |  |  | /,//' \,'  \
%^BOLD%^%^WHITE%^               /   /     ||--+--|--+-/-|     \   \
%^BOLD%^%^WHITE%^              |   |     /'\_\_\ | /_/_/`\     |   |
%^BOLD%^%^WHITE%^               \   \__, \_     `~'     _/ .__/   /
%^BOLD%^%^WHITE%^                `-._,-'   `-._______,-'   `-._,-'
ENDTEXT);

  return ret;
}

int query_auto_load() {
  if(this_player()->query_name() == "Wraith")
    return 0;
  return 1;
}

