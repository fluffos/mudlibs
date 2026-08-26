/**
 * Concept derived from The Dreamings creators command;  Galileo
 * 19 July 1999 - Queue put in a check for net dead creators, driver doesn't
 * seem to like it when you call query_idle() on net dead people
 * Modified For Divided Sky; Shaydz
 * @change Rewrote a wee little to make it a few times faster
 * - Sandoz, May 2002.
 */

inherit COMMAND_BASE;

/** @ignore yes */
varargs string get_colour( string person, string *leaders ) {
    // leader mode.
    if( !leaders )
        return "%^CYAN%^";

    if( member_array( person, leaders ) != -1 )
        return "%^CYAN%^";
    if( DOMAIN_H->query_member("learning", person ) &&
        sizeof( DOMAIN_H->query_domains(person) ) == 1 )
        return "%^YELLOW%^";
    return "%^WHITE%^";

} /* get_colour() */

/** @ignore yes */
int cmd( string str ) {
    string *creators, *leaders, option;
    function f;

    if( str == "leader" || str == "leaders") {
        creators = DOMAIN_H->query_leaders();
        option = "leaders";
    } else if( DOMAIN_H->query_domain(str) ) {
        leaders = DOMAIN_H->query_leaders(str);
        creators = DOMAIN_H->query_creators(str);
        option = str;
    } else {
        leaders = DOMAIN_H->query_leaders();
        creators = DOMAIN_H->query_creators();
        option = "creators";
    }

    if( str != "all" && str != "sage")
        creators -= DOMAIN_H->query_members("sage");
    if( str != "all" && str != "afterlife")
        creators -= DOMAIN_H->query_members("afterlife");

    f = function( string name, string *leaders ) {
            int last;
            object ob;

            ob = find_player(name);
            last = ob ? ob->query_last_log_on() : PLAYER_H->test_last(name);

            return sprintf("%s%s%-16s %-26s %-15s%s", get_colour( name,
                leaders ), ( DOMAIN_H->query_member("sage", name ) ?
                "*" : ( DOMAIN_H->query_member("afterlife", name ) ?
                "+" : " ") ), CAP(name), ( ob ? "Currently Logged In" :
                ctime(last) ), ( ob ? ( !interactive(ob) ?
                "Net dead" : "Idle: "+query_idle(ob) / 60 ) :
                time_string( time() - last, 1 ) ), "%^RESET%^");
    };

    creators = map( creators, f, leaders );
    str = create_table( ({ CAP(option), "creator" }), creators, 0 );

    tell_object( TP, str );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "", (: cmd(0) :),
      "<string'leaders(s)|sage|afterlife|all'>", (: cmd($4[0]) :) });
} /* query_patterns() */
