inherit MONSTER;


#include "../path.h";
init_monster()
{
    if (THIS->query_race() == "tanir")
    {
	call_out("do_greet", 1);
    }
}
do_greet()
{
    command ("say May the sun shine on your path friend elf");
    command ("bow");
}

create_monster ()
{
    set_name (({ "guard", "elf", "tanir", "warrior" }));
    set_short ("Valiant elven warrior stands here in guard");
    set_long ( "Young may this elf be, but he is seasoned "
               "warrior and handles his sword with delicate "
               "grace. His golden blonde hair rests on his "
               "shoulders. He looks keenly at you in case "
               "you'd start making troubles. \n");
      
    set_race ("tanir");
    set_levels (([ "fighter" : 15 ]));
    set_gender (1);
    set_language ("alande");
    set_alignx (500);
    set_alignx (500);

    set_talk (({ "Ah, what a nice weather it is.",
	"Sol'daran is a wonderful city, enjoy its miracles and "
       +"stay out of trouble, ok?",
	"Elen sila lumenn' omentielvo."}));

    set_emote (({ "The guard eyes you taking measure of you.",
	"The guard yawns tiredly. ",
	"The guard looks at the sky and shakes his head."}));


    add_money (random(50));
}
