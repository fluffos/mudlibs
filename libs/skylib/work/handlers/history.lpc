/*  -*- LPC -*-  */

#define SAVE "/save/hist_handler"
#define MAX_HIS 50
#define HISTORY_TIME (3600*24*2)

mapping history;


void create() {
    seteuid(master()->get_root_uid());
    history = ([]);
    unguarded((: restore_object, SAVE :));
    call_out("tidy_history", 2);
} /* create() */

/** Save the current state. */
void save_me() {
    unguarded((: save_object, SAVE :));
} /* save_me() */
/**
 * Keep a mesage from a specified line on the chat stick.
 * @param channel the channel being stored
 * @param start the start string (name)
 * @param mess the message being stored
 */
void add_chat_history(string channel, string start, string mess) {
    mixed *chat_history = history[channel];

    if ( !chat_history )  chat_history = ({ });
    chat_history += ({ ({ start, mess, time() }) });
    if (sizeof(chat_history) > MAX_HIS)
        chat_history = chat_history[1..];
    history[channel] = chat_history;
} /* add_chat_history() */

/**
 * Returns the current chat channel history. The array contains arrays of
 * three elemnts each.,   In each array the first element is the
 * start, the second the mssage and thwe third the time.
 * <p>
 * <code>({  .. ({ start, mess, time }), ({ start, mess, time }), .. })</code>
 * @return an array of the chat channel history.
 * @param channel the channel to get the history of
 */
mixed *query_chat_history(string channel) {
    if(base_name(PO)!="/handlers/channel" && base_name(PO)!="/cmds/player/hi_story")
        return 0;
    return history[channel];
} /* query_chat_history() */


/** @ignore yes */
void dest_me() {
    save_me();
    destruct(this_object());
} /* dest_me() */

/** @ignore yes */
void reset() {
    save_me();
}

/**
 * @ignore yes
 * Clean up old history items.
 */
void tidy_history() {
    string channel;
    int i;

    foreach(channel in keys(history)) {
        for(i = 0; i<sizeof(history[channel]); i++)
            if(history[channel][i][2] < time() - HISTORY_TIME) {
                history[channel] = history[channel][1..];
            } else
                break;
        if(!sizeof(history[channel]))
            map_delete(history, channel);
    }
    save_object(SAVE);
}

/**
 * @ignore yes
 * Zap all the history channels back to nothing.
 */
void reset_history() {
    if (!adminp(previous_object(-1)))
        return;
    history = ([]);
    save_object(SAVE);
} /* reset_history() */
