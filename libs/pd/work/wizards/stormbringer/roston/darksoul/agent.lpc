#include <std.h>
#include <roston.h>
#include <daemons.h>
inherit MONSTER;
 
string *boycot;
 
 
void create() {
    ::create();
    set_short("a tall man muffled in a black cloak");
    set_id( ({ "tall man", "agent" }) );
    set_name("agent");
    set_long(
      "The man is very tall, with a lean, powerful build.  His face is
hidden in "+
      "the shadows of his hood, and he keeps his cloak pulled close about
him.  "+
      "He is an agent of the Red Death, the assassins' guild.\n\nYou can
"+
      "type \"hit <player name> <amount>\" to put out a contract on
another
"+
      "player.  Any assassin who wishes may take the contract.  For
example, "+
      "you might:\n\nhit wisp 500 regals\n\nto offer a 500-gold-regal "+
      "bounty for Wisp's murder.  Ten percent of the money goes into the
"+
      "guild coffers, while the remainder is given to the first assassin
"+
      "to fulfill the contract.\n\nNeedless to say, putting out contracts
"+
      "on people is an extremely evil act.\n"
    );
    set_class("rogue");
    set_race("human");
    set_level(35);
    set_exp(135);
    set_body_type("human");
    set_id(({ "man", "assassin", "agent", "tall man", "man in cloak" }));
    set_gender("male");
    set_skill("murder",150);
    set_skill("knife",170);
    set_skill("stealth",165);
    boycot =
explode(read_file("/domains/guilds/assassin/BOYCOT",1,500),":");
}
 
void init() {
    ::init();
    add_action("hit","hit");
}
 
int hit(string str) {
    string target_name, currency;
    int amount, i;
    object tp;
 
    i = sizeof(boycot);
    for(i=0;i<(sizeof(boycot)-1);i++){
        if((string)this_player()->query_name()==boycot[i]){
            write("The guild will not take contracts from you.\n");
            return 1;
        }
    }
 
    if(!str) {
        return notify_fail("Hit whom?\n");
    }
    if(this_player()->query_guild()=="assassin"){
        return notify_fail("An assassin putting out a
hit? How...demeaning.\n");
    }
    if(sscanf(str,"%s %d %s",target_name,amount,currency)!=3) {
        return notify_fail("Syntax: hit <player name> <amount>\n");
    }
    tp = this_player();
    write("You whisper your request to the assassins' agent.");
    say(tp->query_cap_name()+" whispers something to the man in the black
"+
      "cloak.");
    if(tp->query_money(currency)<amount) {
        force_me("whisper "+tp->query_name()+" You do not have the money
you
offer.  Do not "+
          "tempt the wrath of the Red Death.");
        return 1;
    }
    write("The agent takes your money and vanishes into the shadows.\nHe
returns a few "+
      "moments later.");
    say(tp->query_cap_name()+" hands something to the black-cloaked man,
who turns and "+
      "vanishes into the shadows.\nHe returns a few moments later.");
    force_me("whisper "+tp->query_name()+" The contract has been put
out.");
    message("other_action","A tall man muffled in a black cloak enters and
posts a notice "+
      "on the board.  He then vanishes back into the"
shadows.",+DARKSOUL"room1");
    tp->add_money(currency,-amount);
    tp->add_contract(target_name,currency,amount);
    BBOARD_D->add_npc_post("Dark_Souls_Board","Agent","-= Contract:
"+capitalize(target_name)+" =-",
      tp->query_cap_name()+" has paid "+amount+" "+((amount==1) ? currency
: pluralize(currency))+" to the Red Death for "+
      "the killing of "+capitalize(target_name)+".  There will be a reward
of "+
      (amount - (amount/10))+" "+(((amount-(amount/10))==1) ? currency :
pluralize(currency))+" for the assassin who carries out this
contract.\n\n"+
      "                                           --The Red Death\n"
    );
    tp->add_alignment(-(80+random(80)));
    return 1;
}
 

