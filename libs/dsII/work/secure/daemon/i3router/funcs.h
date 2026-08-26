// This file written completely by Tim Johnson (Tim@TimMUD)

nosave mapping muds_on_this_fd(int fd){
    return filter_mapping(connected_muds,"value_equals",this_object(),fd);
}
int value_equals(string a,int b, int c){ return b==c; }
nosave mapping muds_not_on_this_fd(int fd){
    return filter_mapping(connected_muds,"value_equals",this_object(),fd);
}
int value_not_equals(string a,int b, int c){ return b!=c; }
