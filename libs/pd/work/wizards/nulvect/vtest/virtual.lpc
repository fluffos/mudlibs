#include <std.h>

inherit VIRTUALMAP;

mixed *map = ({
({
  "#-#-# #-#",
  "|      X|",
  "#-#-#-#-#-#",
}),
({
  "+   +",
  ".",
  "+",
}),
({
  "#-#-#",
  ".",
  "#-#",
}),
});

void create() {
  set_mapfile("/wizards/nulvect/vtest/mymap");
  set_descfile("/wizards/nulvect/vtest/descs");
  set_special_exits("0,1,0", ([ "out" : "/wizards/nulvect/workroom" ]) );
  ::create();
}
