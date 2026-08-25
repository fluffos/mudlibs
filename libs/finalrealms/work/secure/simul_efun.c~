#ifdef MUD_NAME
string mud_name() { return MUD_NAME; }
#else
string mud_name() { return "fr"; }
#endif

#ifdef VERSION
string version() { return VERSION; }
#else
#ifdef __VERSION__
string version() { return __VERSION__; }
#else
string version() { return "Unknown"; }
#endif
#endif


varargs string extract(string str, int i, int j);

mixed query_strange_inventory(mixed arr) {
    mixed inv;
    object ob;
    mixed desc;
    int i, k;

    inv = ({ });
    for (k=0;k < sizeof(arr); k++) {
	ob = arr[k];
	if (!(desc = (string)ob->short()) || (desc == ""))
	    continue;
	if ((i = member_array(desc, inv)) >= 0)
	    inv[i+1] += ({ ob });
	else
	    inv += ({ desc, ({ ob }) });
    }
    return inv;
}

mixed *delete(mixed *arr, int start, int len) {
    return arr[0..start-1]+arr[start+len..sizeof(arr)];
} /* delete() */

mixed *slice_array(mixed *arr, int start, int fin) {
    return arr[start..fin];
} /* slice_array() */

mixed *insert(mixed *arr, mixed el, int pos) {
    return arr[0..pos-1]+({ el })+arr[pos..sizeof(arr)];
} /* insert() */

varargs mapping filter_mapping(mapping map, string func, mixed ob, mixed extra)
{
    mixed *bing;
    mapping ret;
    int i;

    ret = ([ ]);
    bing = keys(map);
    for (i=0;i<sizeof(bing);i++) {
	if (call_other(ob, func, map[bing[i]], extra))
	    ret[bing[i]] = map[bing[i]];
    }
    return ret;
} /* filter_mapping() */

// Added by Taniwha 1995 efun one didn't
// #include "/secure/simul_efun/pluralize.c"
// added by Baldrick. Dummy for missing efun in new driver.
// Maybe we should remove it again ? not sure, we have a fix (aragorn)

/* Nativeness.. Baldrick. */
#include "/secure/simul_efun/event.c"

#include "/secure/simul_efun/add_a.c"
#include "/secure/simul_efun/log_file.c"
#include "/secure/simul_efun/find_match.c"
#include "/secure/simul_efun/m_delete.c"
#include "/secure/simul_efun/m_indices.c"
#include "/secure/simul_efun/m_sizeof.c"
#include "/secure/simul_efun/m_values.c"
#include "/secure/simul_efun/mappingp.c"
#include "/secure/simul_efun/modified_efuns.c"
// Baldrick.
#include "/secure/simul_efun/notify_fail.c"
#include "/secure/simul_efun/query_ident.c"
#include "/secure/simul_efun/query_number.c"
#include "/secure/simul_efun/replace.c"

// Roll.c, a dicer made by Sojan.
#include "/secure/simul_efun/roll.c"
#include "/secure/simul_efun/stat_string.c"

#include "/secure/simul_efun/shout.c"
#include "/secure/simul_efun/vowel.c"
#include "/secure/simul_efun/write.c"
#include "/secure/simul_efun/multiple_short.c"
#include "/secure/simul_efun/virtual.c"
#include "/secure/simul_efun/snoop_simul.c"
#include "/secure/simul_efun/extract.c"
#include "/secure/simul_efun/minimax.c"
#include "/secure/simul_efun/file_exists.c"

#include "/secure/simul_efun/user_exists.c"
#include "/secure/simul_efun/immortal_exists.c"
#include "/secure/simul_efun/base_name.c"
#include "/secure/simul_efun/arrange_string.c"
#include "/secure/simul_efun/format_page.c"

#include "/secure/simul_efun/pretty_time.c"
#include "/secure/simul_efun/wrap.c"

// Added by Radix
#include "/secure/simul_efun/users.c"
//#include "/secure/simul_efun/file_commands.c"
#include "/secure/simul_efun/files_obj.c"

#include "/secure/simul_efun/uniq_array.c"
#include "/secure/simul_efun/exclude_array.c"
#include "/secure/simul_efun/atoi.c"

// Addedd 8 Nov 93 Chrisy for Driver upgrade to 0.9.18.9
#include "/secure/simul_efun/mudos.c"
// Taniwha 1995, we can use a checked version
#include "/secure/simul_efun/member_array.c"

/* Added feb '95, Baldrick. */
#include "/secure/simul_efun/log_attack.c"

#include "/secure/simul_efun/reload_object.c"
// Added March 96, andy@entropy.demon.co.uk
// security thingy.

/* Raskolnikov */
#include "/secure/simul_efun/children.c"

/* Upgrade to v22b22, Baldrick.  */
#include "/secure/simul_efun/process_string.c";
/* More fun, Baldrick dec '96 */
#include "/secure/simul_efun/mud_long_name.c";
#include "/secure/simul_efun/nice_list.c"
#include "/secure/simul_efun/cpdir.c"

/* Malik */
#include "/secure/simul_efun/secure_log_file.c"

// save_object, hacked by Baldrick.
//#include "/secure/simul_efun/save_object.c"

/* Tail.c, needed after the v22.1 upgrade, Baldrick. */
#include "/secure/simul_efun/tail.c"

//#include "/secure/simul_efun/command.c"
