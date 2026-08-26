// 22 May 98   Cyanide created the file.
// Edited by caledor to make the lamerbot

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "calewiz");
    set("short", "Lamerbot "+
      (random(1000) + 100) );
    set("long", wrap(
        "This is a Lamerbot, a massive technomagical construct "+
        "designed for educational Purposes for you"+
        "...") );
    set("id", ({ "bot", "lamerbot", "lamer" }) );
    set_name( query("short") );
    set_size(8);
    set("weapon_name", "Joke");
    set_verbs( ({ "laugh", "joke", "annouy" }) );
    set("damage", ({ -7, -7 }) );
    set("armor_class", 90);
    set("natt", 3);
    set_level(15);
    set("chat_chance", 15);
    set("chat_output", ({
      "Lamerbot vocalizes: # Knock, Knock. #\n",
      "Lamerbot vocalizes: # An Dwarf walks out of a pub,   OH! #\n",
      "Lamerbot vocalizes: # Whos there? #\n",
      "Lamerbot vocalizes: # Why did the Andriod cross the road? #\n",
      "Lamerbot vocalizes: # To get to the next millenium! #\n",
      "Lamerbot vocalizes: # Har, Har, Har! #\n",
      "Lamerbot vocalizes: # How many copbots does it take to skrew in a plutonium enhancer? #\n",
      "Lamerbot vocalizes: # If I had a credit everytime I heard that one! #\n",
      "Off in the distance you swear you can hear a drummer!\n",
      "LamerBot vocalizes: # And then I Vocalized, That is my foot! #\n",
      "The LamerBot picks his electronic butt.\n",
    }) );
    set("att_chat_output", ({
      "LamerBot vocalizes: # Prepare to be Vouged! #\n"
    }) );
}
