protected nosave nomask int _log_level = 1;
protected nosave nomask string _log_prefix = "";

void set_log_level(int lvl) { _log_level = lvl ; }
int log_level() { return _log_level ; }
int query_log_level() { return _log_level ; }

void set_log_prefix(string prefix) { _log_prefix = prefix ; }
string log_prefix() { return _log_prefix ; }

varargs void _log(mixed args...) {
    int lvl = -1;
    string message;
    mixed *rest;
    string prefix;
    int no_time;

    if(!sizeof(args))
        return;

    switch(sizeof(args)) {
        case 0:
            return;
        case 1:
            lvl = 1;
            message = args[0];
            break;
        default:
            if(stringp(args)) {
                lvl = 1;
                message = args;
                rest = ({});
            } else {
                if(stringp(args[0])) {
                    lvl = 1;
                    message = args[0];
                    rest = args[1..];
                } else if(intp(args[0]) && stringp(args[1]) && sizeof(args) >= 2) {
                    lvl = args[0];
                    message = args[1];
                    rest = args[2..];
                } else {
                    lvl = 1;
                    message = args[0];
                    rest = args[1..];
                }
            }
            break;
    }

    if(lvl > query_log_level())
        return;

    no_time = lvl < 0;
    lvl = abs(lvl);

    if(query_log_level() >= 2) {
        string *funcs = call_stack(2), func;
        string prep;

        func = funcs[1];
        prep = func;

        if(query_log_level() >= 3) {
            string *lines = call_stack(4), line;
            string *matches;
            string ob;

            line = lines[1];
            matches = pcre_extract(line, "^(/.*/(.*).c):(\\d+)$");
            ob = matches[1];
            line = matches[2];

            if(sizeof(matches) != 3)
                error("Failed to match line: " + line);
            line = matches[2];

            if(query_log_level() > 3) {
                ob = matches[0];
            }  else {
                ob = matches[1];
            }

            prep = sprintf("%s:%s:%s", ob, func, line);
        }

        message = "[" + prep + "] " + message;
    }

    if(strlen(_log_prefix))
        prefix = _log_prefix + " ";
    else
        prefix = "";

    if(no_time == false)
        prefix = sprintf("[%s] %s", ldatetime(), prefix);

    if(sizeof(rest))
        debug(prefix + message, rest...);
    else
        debug(prefix + message);
}
