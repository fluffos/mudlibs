/* A room in the house of joan */

#include <rooms.h>
#include <doors.h>
inherit "/p/houses/common/room/home";

void config() {
  object sign;

  SetIntShort("Parlor of Joan and Mistral");
  SetIntLong("Welcome to the house of Joan and Mistral.\n");
  AddExit("up","./012");
  AddExit("south","./111");
  AddExit("north","./garden1");
  AddExit("west","./001");
  AddExit("east","./021");
/*  AddExit("hartward","/d/archwiz/common/room/city/shop"); */
  AddItem("/p/houses/common/obj/sofa",REFRESH_NONE);
  AddItem("/p/houses/common/obj/playernews",REFRESH_NONE);
//  AddItem("/players/mistral/obj/box",REFRESH_REMOVE);
//  AddItem("/players/mistral/obj/sign",REFRESH_NONE);
  sign=present("sign",this_object());
  if (sign)
    {
    sign->SetText("Feel free to take the box with you - Joan & Mistral");
    sign->SetRO();
    }
  AddDetail("sand dollar","There is a very strange painting on the sand dollar.\nIt is a painting of a man and woman standing in a forest of \ngiant trees. The man is dressed in long fringed buckskin trousers\nand shirt. He has a strange long bow and quarrel slung over his\nshoulder. His black hair is long and he wears a beaded band\naround his head. An eagle feather dangles down the back of his\nhead from the band. He lovingly holds a woman. She wears a beaded \nwhite buckskin dress. She has long black hair too. Her arms are around \nhis waist while her head lay upon his chest. They stand in front of \na conical dwelling decorated with geometric shapes. A horse with \nstrange markings stands quietly next to them.    \n");
  SetEnter("south");
}
