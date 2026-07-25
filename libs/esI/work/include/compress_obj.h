// This include file is created for reduce the mapping of ob_data[] of
// simple items ( which inherit only /std/object/ob.c )
// It is provided by Annihilator@ES
// Ruby@ES add this include file at 95' 6/26

if ( clonep(this_object()) ) {
	// NB: this file is pasted into ~40 different objects' create()
	// bodies via #include, one line before this comment; __FILE__ here
	// tracks the PHYSICAL include file ("/include/compress_obj.h")
	// rather than the file it was pasted into, so it can never be used
	// to identify "my own blueprint". base_name(this_object()) gives
	// the actual compiling file's path at runtime instead, which is
	// what every call site actually wants (a call_other()-reachable
	// blueprint to fall back to for unset properties).
	set_default_ob(base_name(this_object()));
	return;
}

