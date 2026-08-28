inherit MONSTER;

#include "../path.h";

create_monster ()
{
    set_name (({ "dealer", "elf", "shady","Morudwen" }));
    set_short ("A shady looking elf is dealing cards here");
    set_long ("This slender elf looks quite shady and crooked."
    +" He is dressed in all black silken clothes and a ridicul"
    +"ous purple jacket with wide sleeves suitable for hiding "
    +"a couple of extra aces. His icy blue eyes look determined"
    +" and keen.\n");

    set_race ("tanir");
    set_levels (([ "fighter" : 25 ]));
    set_gender (1);
    set_language ("sartog");
    set_alignx (0);
    set_aligny (0);

    set_talk (({ "Just sit down and play some poker, ok?",
        "So, how much are you prepared to lose in poker?",
        "Just to remind you. We do not accept anything else"
       +" but clear cash..."}));

    set_emote (({ "The dealer performs a neat card trick.",
        "The shady elf scratches his chin thoughtfully.",
        "The dealer takes a good look at you.",
        "The shady dealer shuffles a deck of cards behind "
       +"his back"}));

    add_answer("name","The name's Morudwen, though everyone "
    +"around here calls me just Shady.");
    add_answer("job","Well what does it look like, I'm deali"
    +"ng cards here at the Sunflower Tavern and making some "
    +"really good cash here.");
    
    add_money (random(50));
}
