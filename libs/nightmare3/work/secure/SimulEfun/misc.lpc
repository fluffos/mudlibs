varargs int true(mixed args...){
    if(args || !args) return 1;
}

varargs int false(mixed args...){
    if(args || !args) return 0;
}

int tail(string file) {
    string str;
    int diff;

    diff = file_size(file);
    if (diff < 0) return 0;

    diff -= 1024;
    if (diff < 0) diff = 0;
    str = read_bytes(file, diff, 1024);
    if (!str) return 0;
    if (diff) str = str[strsrch(str, "\n")+1..];

    write(str);

    return 1;
}

varargs void tc(string str, object dude){
    string prefix;
    if(previous_object()){
        prefix = file_name(previous_object())+": ";
    }
    else {
        prefix = "";
    }
    if(!dude) dude = find_player("cratylus");
    if(dude){
        tell_object(dude ,prefix+str);
        if(dude) flush_messages(dude);
    }
    debug_message(str);
}

varargs string get_stack( int x) {
    int i, s;
    string list = "";
    string *stack0 = call_stack(0);
    string *stack1 = call_stack(1);
    string *stack2 = call_stack(2);
    for(i = 0, s = sizeof(stack1); i < s; i++){
        list +="\n"+i+":"+identify(stack2[i])+"."+identify(stack1[i])+"."+identify(stack2[i]);
    }

    if(x){
        list += "\n"+ identify(previous_object(-1));
    }

    return list;
}

string dump_socket_status() {
#ifndef __PACKAGE_SOCKETS__
    // The sockets package doesn't exist on this build (e.g. the WASM
    // target, which has no real network stack at all -- see this
    // project's build docs) -- socket_status() itself is an undefined
    // function there, which fails to compile since this is a bare call,
    // not a call_other, and this file lives in simul_efun (a compile
    // failure here takes the whole boot down with it, not just this one
    // admin utility).
    return "(socket status unavailable on this build: no sockets package)\n";
#else
    string ret;
    string *finalsocks, *sock_array = ({});
    int i, quant = sizeof(socket_status());
    for(i = 0; i < quant; i++){
        sock_array += ({ socket_status(i) });
    }
    finalsocks = sock_array;

    ret = @END
Fd    State      Mode       Local Address          Remote Address
--  ---------  --------  ---------------------  ---------------------
END;

    foreach (mixed *item in finalsocks) {
        int memb = member_array(item, finalsocks);
        ret += sprintf("%2d  %|9s  %|8s  %-21s  %-21s\n", memb, item[1], item[2], item[3], item[4]);
    }

    return ret;
#endif
}

