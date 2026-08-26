// domain logging

void domain_log_file(string file, string message) {
    string *path, logpath;

    // extract domain name
    path = explode( file_name(previous_object()), "/" );
    if (path && path[0] == "d") {
        // does domain have its own log directory?
        logpath = sprintf("/d/%s/logs/", path[1]);
        if (file_size(logpath) == -2) {
            seteuid(geteuid(previous_object()));
            logpath += file;

            // make sure target logfile path isn't a directory
            if (file_size(logpath) != -2) {
                // append to logfile (create if necessary)
                write_file(logpath, message);
            }
        }
    }
}
