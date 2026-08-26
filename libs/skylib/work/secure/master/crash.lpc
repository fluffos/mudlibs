
/** @ignore yes */
void crash( string crash_mess, object command_giver, object current_object ) {
    object thing, *things;
    string str;

    if( PO && sizeof( call_stack() ) > 1 ) {
        write("Sorry, crash() can only be called by the driver.\n");
        return;
    }

    reset_eval_cost();

    str = "\n"+ ctime( time() ) +":\n";

    if( current_object )
        str += "current object: "+file_name( current_object )+" ("+
               (string)current_object->query_name()+")\n";

    if( command_giver )
        str += "command giver: "+file_name( command_giver )+" ("+
               (string)command_giver->query_name()+")\n";

    if( query_verb() )
        str += "command given: "+query_verb()+"\n";

    str += "crash reason: "+crash_mess+"\n";

    things = efun::users();

    str += "["+implode( things->query_name(), ", ")+"]\n";

    unguarded( (: write_file, "/log/CRASH", str :) );

    foreach( thing in things ) {
        efun::tell_object( thing, "MudOS shouts: Oh no!  I have to crash "+
            "the driver now!\n("+crash_mess+")\n");
        catch( thing->quit() );
    }

} /* crash() */
