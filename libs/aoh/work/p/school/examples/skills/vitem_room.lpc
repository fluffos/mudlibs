/*     This is a demo room for OSB
*
*      It shows the use of vitem skills (search)
*
*   (c) Softbyte@OSB 22dec97
*
*
*/


#include <rooms.h>
#include <skills.h>
#include <regions.h>
#include <moving.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <herbs.h>
#include <math.h>


inherit "/std/room";


//************************************************************************ 
//                   Main create
//************************************************************************ 
create()
{
string vitem;
  ::create();

  SetIntShort("a nice meadow");
  SetIntLong(
  "You are standing on a nice meadow. Just in its center some dense bushes "
  "are standing. Maybe you can check them out.\n");
  AddDetail(({"nice meadow","meadow"}),#'QueryIntLong);
  vitem=AddDetail(({"bush","bushes","dense bushes"}),
	"A good couple of small dense bushes. At one part they look freshly "
	"cut, so they might be worth of being searched.\n");

  SetIntLight(25);
  SetOutdoors(1);

  Set(P_REGION, REGION_MEADOW);
  Set(P_TEMPERATURE,20);
  SetCoordinates( ({2000,2700,0}));


  // You can find some herbs here..They are added with a
  // conventional id array ({"meadow","herb","herbs"})
  AddSkill(SK_SEARCH,"herbs",750,({"meadow","herb","herbs"}),
    ([WOODHERBS(1000,1000)]));

  // Here we add the search command for the bushes via a vitem
  // it will enable the bushes to be searched with all keywords
  // the above added detail reacts to, i.e. "bush","bushes","dense bushes"
  // The advantage is that you need to write the ids only once!
  // Depending on the skill check either the below coded functions
  // int OnSucceedSearchingBushes() or
  // int OnFailSearchingBushes()
  // are called
  AddSkill(SK_SEARCH,"bushes",50,vitem);


}

//************************************************************************ 
//                   Searching functions
//************************************************************************ 
// These functions will handle the successful or failed searching of the
// bushes. The functions provide a couple of variable arguments which 
// you most likely will not need. So these default implementation will
// suffice
// Using the full argument function, i.e.
// mixed OnSucceedSearchingBushes(object who,int skill,string arg,
//                                string extra,mixed p)
// would give you the following values
// who=Softbyte skill=678 arg=vitem#4 extra=NULL p=0
// [p would be the additional mapping argument you could supply to the
//  AddSkill command as last argument, i.e. the WOODHERBS in the herbs
//  AddSkill command. It will simply be forwarded to your function]

mixed OnSucceedSearchingBushes()
{
object ob;
  msg_write(CMSG_GENERIC,
  "You search through the bushes but find nothing of interest. "
  "But just as you want to stop you notice a small amulet there.\n");
  ob=clone_object("/std/thing");
  ob->SetShort("a small amulet");
  ob->SetLong("Only for demonstration purpose.\n");
  ob->AddId(({"amulet","small amulet"}));
  ob->SetValue(0);
  ob->move(this_object());
  return 1;
}
mixed OnFailSearchingBushes()
{
  msg_write(CMSG_GENERIC,
  "Ouch..there are some thornes...\n");
  return 1;
}

