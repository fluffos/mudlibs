
id(str) { return str=="blood trail"; }
short() { return "Bloody foot prints"; }
long() { this_player()->tell_me("Someone has been bleeding badly."); }
get() { return 0; }

init() { call_out("end",25); }
end(){ destruct(this_object()); }
