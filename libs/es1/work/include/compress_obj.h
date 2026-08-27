// This include file is created for reduce the mapping of ob_data[] of
// simple items ( which inherit only /std/object/ob.c )
// It is provided by Annihilator@ES
// Ruby@ES add this include file at 95' 6/26

if ( clonep(this_object()) ) {
	set_default_ob(__FILE__);
	return;
}

