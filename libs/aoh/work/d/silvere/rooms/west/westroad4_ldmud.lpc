// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added regions/coordinates
//                Auryn    [12-May-1999]  description, details, flowerbed


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>
#include <macros.h>

inherit SILBASEROOM;


string CheckFlowerbed()
{
   switch(({int})NIGHTDAY->QuerySeason())
   {
      case WINTER: return
         "Snow covers the flowerbed, and no plants are to be seen.\n";
         break;
      case SPRING: return
        "The first tender buds venture through the freshly "
              "thawed ground.\n";
         break;
      case SUMMER: return
         "The flowers are in full bloom, displaying a myriad of colours "
              "and filling the air with a sweet fragrance.\n";
         break;
      case AUTUMN: return
         "The summer flowers have withered, making room for asters and "
             "dahlias. They glow in golden, deep red and purple colours, "
             "transforming the flowerbed into a fiery carpet.\n";
         break;
   }
   return 0;
}

string CheckFlowers()
{
  switch(({int})NIGHTDAY->QuerySeason())
    {
    case WINTER: return
	   "It is winter, and there are no flowers.\n";
    break;
    case SPRING: return
	   "The flowers are not yet in bloom. The first buds are "
	   "just showing as a sprinkling of light green on the "
	   "black soil.\n";
    break;
    case SUMMER: return
	   "The flowers are blooming in every colour imaginable. "
	   "Their sweet fragrance fills the air, overlaying even "
	   "the odour wafting over from the poorer quarters of the "
	   "city.\n";
    break;
    case AUTUMN: return
	   "Asters and dahlias blossom in the flowerbed. They seem "
	   "to virtually glow in all shades of gold, red and "
	   "purple.\n";
    break;
    }
   return 0;
}

string CheckSnow()
{
if (({int})NIGHTDAY->QuerySeason()==WINTER)
  return "Snow covers the flowerbed.\n";
else
  return "It is much too warm for snow. Wait until winter if you want to "
    "see some.\n";
}

string SmellFlowers()
{
  switch(({int})NIGHTDAY->QuerySeason())
    {
    case WINTER: return
	   "There are no flowers here to sniff at.\n";
    break;
    case SPRING: return
	   "The flowers are not yet in bloom, and the buds don't "
	   "smell of anything.\n";
    break;
    case SUMMER: return
	   "You inhale deeply the wonderful scent of the flowers.\n";
    break;
    case AUTUMN: return
	   "The asters and dahlias, while vividly coloured, don't "
	   "have the sweet scent of the flowers blooming in summer.\n";
    break;
    }
   return 0;
}


string SmellRoom()
{
  switch(({int})NIGHTDAY->QuerySeason())
    {
    case WINTER: return
	   "The air is cold and smells of salt and snow.\n";
    break;
    case SPRING: return
	   "You smell the first traces of spring in the air.\n";
    break;
    case SUMMER: return
	   "The air is filled with the fragrance of the flowers "
	   "growing here, and a less pleasant odour wafting over "
	   "from the city's poorer quarters.\n";
    break;
    case AUTUMN: return
	   "You sense a smell of salt and fish from the harbour, "
	   "as well as a decidedly unpleasant odour coming from the "
	   "slums.\n";
    break;
    }
    return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Westway. An alley leads south to a shop.");
   Set(P_INT_LONG,
"A narrow alley branches off Westway here and leads south to a small shop. "
"A flowerbed has been planted in the middle of the boulevard, protected "
"from careless feet by a low wrought-iron fence. @@TimeMsg@@\n"
);


AddVItem(
	 ([ P_IDS: ({"alley"}),
	 P_ADS: ({"narrow"}),
	 P_LONG:
	 "The alley winds its way south between the houses.\n"
	  ]) );

AddDetail( ({"westway","boulevard"}),"Westway runs from the harbour in the "
"west to the palace in the east. Many shops line the boulevard. Whatever "
"you might be looking for, chances are that you will find it there.\n");

AddDetail("shops","Westway is the main business street of Silvere. Provided "
"you have the money, you will probably find whatever you are looking for in "
"one of the many shops.\n");

AddDetail( ({"shop","small shop"}),"You can't see the shop from here very "
"well. Just go south down the alley and you'll find it.\n");

AddVItem(
	 ([ P_IDS: ({"flowerbed"}),
	 P_LONG: SF(CheckFlowerbed)
	 ]) );

AddVItem(
	 ([ P_IDS: ({"snow"}),
	 P_LONG: SF (CheckSnow)
	  ]) );
AddVItem(
	 ([ P_IDS:({"fence"}),
	 P_ADS: ({"low","iron","wrought-iron"}),
	 P_LONG: "The fence is only about knee high (for a human, that is.) "
	 "It is painted white and ensures that no careless passers-by trample "
	 "the flowers.\n"
	  ]) );

AddDetail("houses","The houses are painted in bright, friendly colours. "
	  "Most of them contain a shop on the ground floor.\n");

AddVItem(
	 ([ P_IDS: ({"buds","flowers","asters","dahlias","plants"}),
	 P_ADS: ({"tender","green","golden","deep red","purple"}),
	 P_LONG: SF(CheckFlowers),
	 P_SMELL: SF(SmellFlowers)
	  ]) );

Set(P_TIME_MSG,
    ([ DAY_DEFAULT_MSG: "The many shops along the boulevard are open. All "
                        "around you, people are going after their business, "
                        "filling the streets with life.",
    NIGHT_DEFAULT_MSG:  "It is night, and the streets are empty.",
    ND_SUNRISE:         "The shops are still closed, but as the sun rises, "
                        "the first people start emerging from their houses.",
    ND_SUNSET:          "As the sun sets, the merchants close their shops."
     ]) );


   Set(P_INT_WIZMSG,
" SOUTH: to a small shop.\n\
 WEST:  to the harbour and the temple of Xalandre.\n\
 EAST:  deeper into the city.\n");


   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -150,10,0 }), C_SILVERE }) );

   Set(P_INT_SMELL, SF(SmellRoom));

   Set(P_NOWAY_MSG,
"You bump into a wall. You can't help feeling a little bit ridiculous.\n");

   AddExit("west",   SIL_WEST("westroad3"));
   AddExit("east",   SIL_WEST("westroad5"));
   AddExit("south",  SIL_WEST("westshop1"));
}

