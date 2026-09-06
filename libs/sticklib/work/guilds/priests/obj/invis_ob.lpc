get() { return 1; }
drop() { return 1; }

inv_time(arg) {
    call_out("back_to_vis",arg,0);
    return 1;
}

back_to_vis() {
    environment(this_object())->vis();
    destruct(this_object());
    return 1;
}

init() {
    add_action("quit","quit");
}

quit() { this_player()->vis(); destruct(this_object()); }
