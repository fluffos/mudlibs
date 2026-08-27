// This include file is created for reduce the mapping of ob_data[] of
// simple items ( which inherit only /std/object/ob.c )
// It is provided by Annihilator@ES
// Ruby@ES add this include file at 95' 6/26

if ( clonep(this_object()) ) {
	// Fix (AGENTS.md 7.14's "__FILE__ in an #include'd fragment" class):
	// __FILE__ expands to the path of whatever file is textually being
	// scanned at that point -- for a fragment #include'd (not inherited)
	// into another file's create(), that's always this header's own
	// path ("/include/compress_obj.h"), never the includer. The intent
	// here is for a clone to fall back to its own uncloned master copy
	// (which already ran its own create() and holds the real values)
	// for any property this clone doesn't set locally, so this needs
	// the clone's own base file path, not the header's.
	set_default_ob(base_name(this_object()));
	return;
}

