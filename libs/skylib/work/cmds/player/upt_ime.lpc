
inherit COMMAND_BASE;

int cmd() {
    mapping map;
    int up;

    up = uptime();
    map = rusage();

    write( sprintf("%s has been up for %s.\nThe load average is %s.\n"
        "This has taken %.2f%% of the CPU and %.2fMB of memory.\n"
        "The next scheduled reboot will take place in %s.\n",
        mud_name(), time_string( up, 2 ), query_load_average(),
        ( ( map["stime"] + map["utime"] ) / 10.0 ) / up,
        memory_info() / 1024000.0,
        time_string( SHUTDOWN_H->query_shutdown() * 60, 2 ) ) );

    return 1;

} /* cmd() */
