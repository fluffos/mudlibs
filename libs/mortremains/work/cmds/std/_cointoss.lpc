// Cyanide, 12 Sep 1999

inherit DAEMON;

#define COIN ({ "heads", "tails" })

int cmd_cointoss() {
    write("You toss a coin into the air!\n");
    say(TPN+" tosses a coin into the air!\n");

    tell_room(environment(TP), "It lands on "+
      COIN[random(2)] +"!\n");
    return 1;
}

string help () {
    return(wrap("This command allows you to "+
	"flip a coin and get a random result.") );
}
