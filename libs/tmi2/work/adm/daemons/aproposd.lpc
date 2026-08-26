// File: /adm/daemons/aproposd.c
//   - apropos daemon - maintains dictionary
//
// History:
//   Created by Whiplash@TMI - 92/02/11
//   Minor rewrite by Truilkan@TMI - 92/02/11
//   Attic'd prior to TMI Release 1.0.1
//   Rewritten by Robocoder@TMI-2 (04-Jul-93)
//   Leto added some security checks (Dec-21 1994)
//
// See also: /cmds/xtra/_apropos.c, /cmds/adm/_aproposm.c

#include <config.h>
#include <logs.h>
#include <commands.h>
#include <man.h>
#include <uid.h>
#include <driver/origin.h>

#define APROPOS_DATA DATA_DIR "/adm/daemons/apropos"

// This mapping is indexed by phrase; the value is the name of the function
// subdirectory
mapping apropos_phrases;

nosave int already_updating;

// prototypes for local functions
void scan_file(string x, string y);
void hash(string x, string y);
void update_aplist(int x);
void process_dir(string x);

// initialization
void create() {
    string s;

    seteuid(ROOT_UID);
    already_updating = 0;
    if (!restore_object(APROPOS_DATA)) {
        apropos_phrases = allocate_mapping(400);
        save_object(APROPOS_DATA);
    }
}

void query_update() {
    write("Files left to process: " + already_updating + "\n");
}

// scan the doc subdirectories and [re]build apropos database
void update_aplist(int x) {
    string *docdirs;
    string tmp;
    int i, s;

#if 0
    tmp = base_name(previous_object());
    if (!adminp(geteuid(previous_object())) &&
	  tmp != CMD_APROPOSM && tmp != CMD_APROPOS &&
	  tmp != file_name(this_object())) {
	return;
    }
#else
    if (origin() != ORIGIN_CALL_OUT) {
        tmp = base_name(previous_object());
        if (!adminp(geteuid(previous_object())) &&
              tmp != CMD_APROPOSM && tmp != CMD_APROPOS)
            return;
    }
#endif

    if (already_updating) {
        return;
    }
    already_updating = 1;

    // process each subdirectory
//  docdirs = MAN_DIRLIST;
    docdirs = EXTENDED_MAN_DIR_LIST;
    s = sizeof(docdirs);
    for (i = 0; i < s; i++) {
//      call_out("process_dir", 1, docdirs[i]);
        process_dir(docdirs[i]);
    }
    already_updating--;
}

// apropos
//   called by /cmds/xtra/_apropos.c
//   returns an array of strings
//   each string is of the form:
//      doc file name: synopsis containing matching phrase
string *apropos(string str, int quiet) {
    string *r;
    mapping k;
    int i, j, s;

    if (base_name(previous_object()) != CMD_APROPOS)  return ({ });

    if (!str || str == "") {
#ifdef APROPOS_LOG
        log_file(APROPOS_LOG, wrap("apropos(): invalid string, from: " +
              "[" + file_name(previous_object()) + "] " +
              (this_player() ?
              capitalize(geteuid(this_player())) : "unknown") +
              " " + extract(ctime(time()), 4, 15)));
#endif
        return ({ });
    }

    if (!apropos_phrases || !sizeof(apropos_phrases)) {
        if (!already_updating) {
            call_out("update_aplist", 1, 0);
            return ({
"Updating apropos database. This may take a while.  Please try again, later."
	    });
        } else {
            return ({ "Update of apropos database in progress." });
        }
    }

    // find matching phrases
    r = regexp(keys(apropos_phrases), ".*" + str + ".*");

    // prepend phrases with dirname
    if (!quiet) {
        s = sizeof(r);
        for (i = 0; i < s; i++) {
            r[i] = apropos_phrases[r[i]] + ": " + r[i];
        }
    }

    return r;
}

// save_me
//   called via call_out
void save_me() {
    save_object(APROPOS_DATA);
    already_updating = 0;
}

// process_dir
//   called via call_out
void process_dir(string dirname) {
    string *docfiles;
    string *lines;
    int i, s;
    string tmp, tmp2;

//  if (origin() != ORIGIN_CALL_OUT)  return;
    if (origin() != ORIGIN_LOCAL)  return;
    // check this is a directory
//  tmp = man_root + "/" + dirname + "/";
     tmp = dirname + "/";
    if (file_size(tmp) != -2) {
        return;
    }

    docfiles = get_dir(tmp);
    s = sizeof(docfiles);
    already_updating += s;

    // process each file
    for (i = 0; i < s; i++) {
        tmp2 = tmp + docfiles[i];
        if (file_size(tmp2) <= 0 || docfiles[i] == "README") {
            // skip empty files, files I don't have read permission to,
            // ".", ".." and any directories (which I don't know about)
            already_updating--;
            continue;
        }

        // process file
        call_out("scan_file", 1, dirname, tmp2);
    }
}

int process_file(string filename) {
    string *p, tmp;
    int i, j, k, s;

    if (!filename || filename == "")
        return 0;

    if (already_updating) {
        return 0;
    }
    already_updating = 1;

    filename = resolv_path(this_player()->query("cwd"), filename);
    j = strlen(filename);

//  p = MAN_DIRLIST;
    p = EXTENDED_MAN_DIR_LIST;
    s = sizeof(p);
    for (i = 0; i < s; i++) {
//      tmp = man_root + "/" + p[i] + "/";
        tmp = p[i] + "/";
        k = strlen(tmp);
        if (j >= k && tmp == filename[0..k-1])
            break;
    }
    if (i == s) {
	already_updating = 0;
        return 0; // not found
    }

    scan_file( p[i], filename );
    return 1;
}

void scan_file(string dirname, string pathname) {
    string *lines;
    string tmp;
    int i, j, k, s;

    tmp = read_file(pathname);
    lines = (tmp) ? explode(tmp, "\n") : ({ });

    s = sizeof(lines);
    i = member_array("NAME", lines);
    if (i == -1) {
        i = member_array(".SH NAME", lines);
        k = 1;
    } else
        k = 0;

    if (i != -1) {
        // concat NAME lines
        tmp = "";
        if (k)
//          for (j = i+1; j < s && lines[j] != ""; j++) {
            for (j = i+1; j < s && lines[j] != "" && lines[j] != " "; j++) {
                if (lines[j] == ".nf")  continue;
                tmp += " " + lines[j];
            }
        else
            for (j = i+1; j < s && lines[j] != "" && lines[j] != " "; j++) {
                tmp += lines[j];
            }

	// this fix for words that get abbrev'd doesn't work if
	// there's a proper hyphenation at the end of a line
        tmp = replace_string(tmp, "-     ", "");

        call_out( "hash", 1, tmp, dirname );
    } else
	already_updating--; // else NAME not found or lines = ({ })
}

void hash(string tmp, string dirname) {
    string *lines;
    int i, k, s;

    // strip spaces
    lines = explode(tmp, " ");
    s = sizeof(lines);
    for (i = 0, k = 0; i < s; i++) {
        if (lines[i] == "") continue;
        lines[k++] = lines[i];
    }

    // compacting the array should to reduce iterations in the next loop
    lines = exclude_array(lines, k, s);
    s = sizeof(lines);
    tmp = implode(lines, " ");

    // add phrase to database
    apropos_phrases[tmp] = dirname;

    already_updating--;
    if (already_updating == 0)
	save_me();
}

string *query_phrases() {
    return keys(apropos_phrases);
}

string *query_files() {
    return values(apropos_phrases);
}

int compare(string x, string y) {
    return strcmp(x, y);
}
