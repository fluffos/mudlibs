
private nosave string _nf;

/** @ignore yes */
void enable_commands() {
    set_this_player(PO);
    LIVING_H->enable_commands(PO);
} /* enable_commands() */

/** @ignore yes */
void set_living_name( string name ) {
    LIVING_H->set_living_name( name, PO );
} /* set_living_name() */

/** @ignore yes */
int living( object ob ) { return LIVING_H->living(ob); }

/** @ignore yes */
int _notify_fail( string mess ) {
    _nf = mess;
    return 0;
} /* _notify_fail() */

/** @ignore yes */
string query_notify_fail() { return _nf; }

/** @ignore yes */
int command( string cmd ) {
    int eval = eval_cost();
    evaluate( bind( (: call_other, PO, "_process_input", cmd :), PO ) );
    return eval - eval_cost();
} /* command() */
