/**
 * Basically tracks players on their birthdays, and gives them presents
 * and so forth. It also ensures that they don't get presents twice.
 */

#define BIRTHDAY   "having birthday"

/**
 * The entry point to the handler.
 * @arg who the person who might be having a birthday.
 */
void check_player(object who) {
    if( !who )
        return;

    if( !who->query_is_birthday_today() ) {
        who->remove_property(BIRTHDAY);
        return;
    }

    event( users(), "inform", who->query_cap_name()+" is having a birthday "
        "today!", "birthday");

    call_out("gift_player", 5, who );

} /* check_player() */

/**
 * Colours a string. Works best with no spaces.
 * @arg text string to be coloured
 * @return the coloured string
 */
string colourise( string text ) {
    int i;
    string ret, *colours;

    colours = ({"%^RED%^", "%^BLUE%^", "%^GREEN%^", "%^YELLOW%^"});

    i = 0;
    ret = "";

    while( i < strlen(text) ) {
        ret += colours[i%4] + text[i..i];
        i++;
    }

    return ret + "%^RESET%^";

} /* colourise() */

/**
 * Gives the player gifts.
 * Currently the only gift given is a brace of fireworks above their
 * heads.
 * @arg who the person receiving gifts.
 */
void gift_player( object who ) {
    string year;

    if( !who )
        return;

    if( year = who->query_property(BIRTHDAY) ) {
        if( year == ctime(time())[<4..] )
            return;
        who->remove_property(BIRTHDAY);
    }

    who->add_property( BIRTHDAY, ctime(time())[<4..] );

    tell_object( who, "%^YELLOW%^Happy Birthday, from all of the "+
        mud_name()+" Staff!\n%^RESET%^");

    FIREWORK_H->random_firework( who, "%^BOLD%^%^RED%^H%^BLUE%^A%^GREEN%^P"
        "%^YELLOW%^P%^RED%^Y %^BLUE%^B%^GREEN%^I%^YELLOW%^R%^RED%^T"
        "%^BLUE%^H%^GREEN%^D%^YELLOW%^A%^RED%^Y "+
        colourise( who->query_cap_name()+"!") );

    if( creatorp(who) ) {
        tell_object( who, "A small green gnome wanders up to you and "
            "hands you a large card, muttering something about a birthday "
            "before wandering off again.\n");
        clone_object("/obj/misc/card")->move(who);
    }

} /* gift_player() */
