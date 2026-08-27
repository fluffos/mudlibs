varargs void tell_room(mixed room, mixed msg, mixed exclude)
{
	if( stringp(msg) ) {
        if( !room || !objectp(room) ) return;
		message( "tell_room", msg, room, exclude );
		return;
	}
    error("Tell_room: Message must be a string.\n");
}
