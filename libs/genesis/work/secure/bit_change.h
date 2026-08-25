/*
 * secure/bit_change.h
 *
 * FluffOS PORT NOTE: this header never shipped in the upstream repo at
 * all -- per bit_change.lpc's own docstring, it's an admin-authored
 * per-run configuration file ("you must alter the bit_change.h header
 * file accordingly ... run with a root or archwizard euid"), not
 * stable mudlib content. bit_change.lpc is a one-shot maintenance
 * utility for migrating wizard-bit banks after a domain merge/split,
 * never invoked during normal play or boot. This is a template with
 * safe no-op defaults (an empty domain and an empty change mapping),
 * matching the tool's own documented expectation that an admin edits
 * this file before actually running it -- not invented migration
 * content.
 *
 * DOMAIN  - the domain whose playerfiles/bit banks to operate on.
 * CHANGE  - mapping describing the bit change(s) to apply; each value
 *           is a ({ command, source_group, source_bit, dest_group,
 *           dest_bit }) array, indexed by the INDEX_* constants below.
 *           Since CHANGE is empty here, the foreach loops that iterate
 *           it never execute and these indices are never actually
 *           dereferenced -- only their distinctness matters to compile.
 * LOGFILE - where this tool logs the bits it changed.
 * ALLOWED - the wizard name to tell_object() progress updates to.
 */
#define DOMAIN ""
#define CHANGE ([ ])
#define INDEX_COMMAND      0
#define INDEX_SOURCE_GROUP 1
#define INDEX_SOURCE_BIT   2
#define INDEX_DEST_GROUP   3
#define INDEX_DEST_BIT     4
#define LOGFILE "/log/bit_change"
#define ALLOWED ROOT_UID
