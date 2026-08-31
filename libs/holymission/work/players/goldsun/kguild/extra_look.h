
/* extra_look */


string extra_look() 
{
    string me;
    string poss;
    
    me = capitalize(this_player()->query_pronoun());
    poss = capitalize(this_player()->query_possessive());

    return (
    me+" is great member of the Knight's guild.\n"+
    poss+" beautiful body is athletic and well built");
}





