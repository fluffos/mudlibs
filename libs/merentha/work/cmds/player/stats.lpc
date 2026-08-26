// Petrarch
// Merentha Lib 1.0
// <stats>

int command() {
    int x,i=this_player()->getenv("SCREEN");
    if(!i)i=75;
    x=i;
    i=i/3;
    message("command", border(
        arrange_string("%^GREEN%^Strength%^ORANGE%^ "+this_player()->query_stat("strength"),i)+
        arrange_string("%^GREEN%^Constitution %^ORANGE%^"+this_player()->query_stat("constitution"),i)+
        arrange_string("%^GREEN%^Dexterity %^ORANGE%^"+this_player()->query_stat("dexterity"),i)+
        arrange_string("Intelligence%^ORANGE%^ "+this_player()->query_stat("intelligence"),i)+
        arrange_string("%^GREEN%^Wisdom%^ORANGE%^ "+this_player()->query_stat("wisdom"),i)+
        arrange_string("%^GREEN%^Charisma%^ORANGE%^ "+this_player()->query_stat("charisma"),i),"stats",
        x),this_player());
    return 1;
}

string help() {
    return "Syntax: stats\n\nThis command displays your current stats.\
\n\n\
Stats determine all aspects of your being including strength, consitiution, dexterity, intelligence, wisdom and charisma.  There are also other stats like how tall you are, how much you weigh and how well you can see in the dark.\n\
\n\
Stats can be increased as time goes on and are increased automaticlly though use.  Casting a larger number of spells for example will increase your intelligence.\n\
\n\
See also: classes, races\n\
See also: score, skills, cost";
}
