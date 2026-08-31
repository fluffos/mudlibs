#include <std.h>

inherit OBJECT;

string extra_look();

void create() {
  ::create();
  set_short("Nightshade's Picture");
    set_long( (: extra_look() :) );
  set_name("picture");
  set_id(({"picture"}));
  set_weight(1);
}

string extra_look() {
  string ret;
ret = "\n  .OOOOOOOOOOOOOOO @@                                   @@ OOOOOOOOOOOOOOOO.\n  OOOOOOOOOOOOOOOO @@                                    @@ OOOOOOOOOOOOOOOO\n  OOOOOOOOOO'''''' @@                                    @@ ```````OOOOOOOOO\n  OOOOO'' aaa@@@@@@@@@@@@@@@@@@@@\"\"\"            ";
ret += "       \"\"\"\"\"\"\"\"\"@@aaaa `OOOO\n  OOOOO,\"\"\"\"@@@@@@@@@@@@@@\"\"\"\"                                     a@\"\" OOOA\n  OOOOOOOOOoooooo,                                            |OOoooooOOOOOS\n  OOOOOOOOOOOOOOOOo,                                     ";
ret += "     |OOOOOOOOOOOOC\n  OOOOOOOOOOOOOOOOOO                                         ,|OOOOOOOOOOOOI\n  OOOOOOOOOOOOOOOOOO @                                       |OOOOOOOOOOOOOI\n  OOOOOOOOOOOOOOOOO'@                                        OOOOOOOOOOOOOOb\n  OOOOOOOOOOOOOOO'a'      ";
ret += "                                   |OOOOOOOOOOOOOy\n  OOOOOOOOOOOOOO''                                           aa`OOOOOOOOOOOP\n  OOOOOOOOOOOOOOb,..                                          `@aa``OOOOOOOh\n  OOOOOOOOOOOOOOOOOOo                                    ";
ret += "       `@@@aa OOOOo\n  OOOOOOOOOOOOOOOOOOO|                                             @@@ OOOOe\n  OOOOOOOOOOOOOOOOOOO@                               aaaaaaa       @@',OOOOn\n  OOOOOOOOOOOOOOOOOOO@                        aaa@@@@@@@@\"\"        @@ OOOOOi\n  OOOOOOOOOO~~ aaaaaa\"a         ";
ret += "        aaa@@@@@@@@@@\"\"            @@ OOOOOx\n  OOOOOO aaaa@\"\"\"\"\"\"\"\" \"\"            @@@@@@@@@@@@\"\"               @@@|`OOOO'\n  OOOOOOOo`@@a                  aa@@  @@@@@@@\"\"         a@        @@@@ OOOO9\n  OOOOOOO'  `@@a               @@a@@   @@\"\"           a@@   a     |@@@ OOOO3\n  `OOOO'   ";
ret += "    `@    aa@@       aaa\"\"\"          @a        a@     a@@@',OOOO'\n";

  return ret;
}

int query_auto_load() {
  if(this_player()->query_name() == "nightshade")
    return 1;
  return 0;
}
