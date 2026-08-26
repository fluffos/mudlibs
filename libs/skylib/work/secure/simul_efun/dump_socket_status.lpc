
/**
 * This method returns the socket status in a nice string.
 * @return the status of sockets
 */
string dump_socket_status() {
    string ret = @END
Fd    State      Mode       Local Address          Remote Address
--  ---------  --------  ---------------------  ---------------------
END;

    foreach( mixed *item in socket_status() ) {
        ret += sprintf("%2d  %|9s  %|8s  %-21s  %-21s\n",
        item[0], item[1], item[2], item[3], item[4]);
    }

    return ret;

} /* dump_socket_status() */
