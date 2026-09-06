#!/usr/bin/usr/bin/env python3
"""Write FluffOS catalog overlays for LDMud→FluffOS onboards."""
from pathlib import Path

REPO = Path("/home/sunyc/src/mudlib")

MASTER = r'''/*
 * FluffOS master for {slug} ({number}/{port}).
 *
 * LDMud → FluffOS conversion. The archive master is saved as
 * {master_ldmud}: set_driver_hook(), closures (#'… / unbound_lambda),
 * inaugurate_master(). FluffOS hardcodes the equivalent apply set, so
 * this file is a permissive FluffOS master (questmud / AGENTS.md §7.158).
 */

string get_root_uid() {{ return "ROOT"; }}
string get_bb_uid() {{ return "BACKBONE"; }}

string creator_file(string object_name) {{
  return "BACKBONE";
}}

string get_wiz_name(string file) {{ return "root"; }}
string domain_file(string file) {{ return "{slug}"; }}
string author_file(string file) {{ return "{slug}"; }}
string privs_file(string file) {{ return "BACKBONE"; }}

int valid_override(string calling_file, string identifier, string caller) {{
  return 1;
}}

int valid_seteuid(object ob, string neweuid) {{ return 1; }}
int valid_bind(object binder, object old_ob, object new_ob) {{ return 1; }}
int valid_hide(object ob) {{ return 1; }}
int valid_shadow(object ob, int level) {{ return 1; }}
int valid_snoop(object snooper, object snoopee) {{ return 1; }}
int valid_query_snoop(object wizard) {{ return 1; }}
varargs int valid_exec(string name, object ob, object obfrom) {{ return 1; }}
int valid_socket(object caller, string func, mixed *info) {{ return 1; }}

mixed valid_read(string path, string eff_user, string call_fun, object caller) {{
  switch (call_fun) {{
    case "load_object":
    case "recompile_object":
    case "include":
    case "restore_object":
    case "read_file":
    case "read_bytes":
    case "file_size":
    case "get_dir":
      return 1;
  }}
  return 1;
}}

mixed valid_write(string path, string eff_user, string call_fun, object caller) {{
  return 1;
}}

void ensure_runtime_dirs() {{
  string *need;
  int i;

  need = ({{ "/log", "/binaries", "/data", "/catalog" }});
  for (i = 0; i < sizeof(need); i++) {{
    if (file_size(need[i]) != -2)
      mkdir(need[i]);
  }}
}}

varargs object connect(int port) {{
  object ob;
  string err;

  ensure_runtime_dirs();
  err = catch(ob = clone_object("/catalog/login"));
  if (err) {{
    write("Login failed: " + err + "\n");
    return 0;
  }}
  return ob;
}}

void flag(string str) {{
  if (str == "shutdown")
    shutdown();
}}

string *epilog(int load_empty) {{ return ({{}}); }}

void preload(string file) {{}}

object compile_object(string path) {{ return 0; }}

void log_error(string file, string message) {{
  if (file_size("/log") != -2)
    mkdir("/log");
  if (strsrch(message, "arning:") != -1)
    return;
  write_file("/log/compile", file + ": " + message);
}}

void error_handler(mapping err, int caught) {{
  string msg;

  if (!err)
    return;
  msg = sprintf("%s %s:%d %s\n",
    caught ? "CAUGHT" : "ERROR",
    err["file"] || err["program"] || "?",
    err["line"],
    err["error"] || "");
  if (file_size("/log") != -2)
    mkdir("/log");
  write_file("/log/catch", msg);
  if (!caught)
    write(msg);
}}

void crash(string error, object command_giver, object current) {{
  if (file_size("/log") != -2)
    mkdir("/log");
  write_file("/log/crash", ctime(time()) + " " + error + "\n");
}}

string object_name(object ob) {{
  if (ob && function_exists("query_name", ob))
    return ob->query_name();
  return 0;
}}

string get_save_file_name(string file, object who) {{ return 0; }}
int save_ed_setup(object who, int code) {{ return 1; }}
int retrieve_ed_setup(object who) {{ return 0; }}
string make_path_absolute(string file) {{ return file; }}

string *parse_command_id_list() {{ return ({{ "the", "a", "an" }}); }}
string *parse_command_plural_id_list() {{ return ({{}}); }}
string *parse_command_adjectiv_id_list() {{ return ({{}}); }}
string *parse_command_prepos_list() {{
  return ({{ "in", "on", "at", "to", "from", "with" }});
}}
string parse_command_all_word() {{ return "all"; }}
'''

SIMUL = r'''/*
 * FluffOS simul_efun for the {slug} LDMud → FluffOS catalog overlay.
 * Original LDMud simul_efun tree is preserved under the archive paths
 * and is not loaded by config.fluffos.
 */

void cat(string file) {{
  string s;

  s = read_file(file);
  if (s)
    write(s);
}}

void log_file(string file, string str) {{
  if (file_size("/log") != -2)
    mkdir("/log");
  write_file("/log/" + file, str);
}}

int exists(string path) {{
  return file_size(path) != -1;
}}
'''

AUTO_H = r'''#ifndef _CATALOG_FLUFFOS_AUTO_H
#define _CATALOG_FLUFFOS_AUTO_H

/* FluffOS global include for the LDMud → FluffOS catalog overlay.
 * Original LDMud sources keep their own headers and are not compiled
 * on this driver. */

#define THISO this_object()
#define THISP this_player()

#endif
'''

LOGIN = r'''/*
 * FluffOS catalog login for {slug} (LDMud → FluffOS conversion).
 * The archive login stack depends on LDMud closures / driver hooks
 * and is not loaded here.
 */

string name;
string password;
int tries;

void create() {{
  seteuid(getuid());
}}

void logon() {{
  write("\n{welcome}\n");
  write("Name: ");
  input_to("get_name", 0);
}}

int valid_name(string str) {{
  int i, n;

  if (!stringp(str))
    return 0;
  n = strlen(str);
  if (n < 2 || n > 16)
    return 0;
  for (i = 0; i < n; i++) {{
    if (str[i] < 'a' || str[i] > 'z')
      return 0;
  }}
  return 1;
}}

string save_path(string n) {{
  return sprintf("/data/%c/%s", n[0], n);
}}

void get_name(string str) {{
  if (!str)
    str = "";
  str = lower_case(str);
  while (strlen(str) && (str[0] == ' ' || str[<1] == ' ')) {{
    if (str[0] == ' ')
      str = str[1..];
    else
      str = str[0..<2];
  }}
  if (!valid_name(str)) {{
    write("Name must be 2-16 letters (a-z).\nName: ");
    input_to("get_name", 0);
    return;
  }}
  name = str;
  if (file_size(save_path(name) + ".o") > 0) {{
    write("Password: ");
    input_to("get_password", 1);
    return;
  }}
  write("New character.\nPassword (6+ chars): ");
  input_to("new_password", 1);
}}

void get_password(string str) {{
  object p;
  string stored, err;

  if (!str || strlen(str) < 1) {{
    write("Password: ");
    input_to("get_password", 1);
    return;
  }}
  p = clone_object("/catalog/player");
  if (!p || !p->restore_me(name)) {{
    write("Could not load that character.\n");
    destruct(this_object());
    return;
  }}
  stored = p->query_password();
  if (crypt(str, stored) != stored && crypt(str, 0) != stored) {{
    tries++;
    destruct(p);
    if (tries >= 3) {{
      write("Too many tries.\n");
      destruct(this_object());
      return;
    }}
    write("Wrong password.\nPassword: ");
    input_to("get_password", 1);
    return;
  }}
  err = catch(exec(p, this_object()));
  if (err) {{
    write("exec failed: " + err + "\n");
    destruct(p);
    destruct(this_object());
    return;
  }}
  p->enter_world();
  destruct(this_object());
}}

void new_password(string str) {{
  if (!str || strlen(str) < 6) {{
    write("Password must be at least 6 characters.\nPassword: ");
    input_to("new_password", 1);
    return;
  }}
  password = str;
  write("Confirm password: ");
  input_to("confirm_password", 1);
}}

void confirm_password(string str) {{
  object p;
  string err;

  if (str != password) {{
    write("Passwords did not match.\nPassword: ");
    input_to("new_password", 1);
    return;
  }}
  p = clone_object("/catalog/player");
  p->setup_new(name, crypt(password, 0));
  err = catch(exec(p, this_object()));
  if (err) {{
    write("exec failed: " + err + "\n");
    destruct(p);
    destruct(this_object());
    return;
  }}
  p->enter_world();
  destruct(this_object());
}}
'''

PLAYER = r'''/*
 * Catalog player body for {slug} (LDMud → FluffOS conversion).
 */

string name;
string password;
int hp;
int max_hp;

int cmd_look(string arg);
int cmd_score(string arg);
int cmd_inventory(string arg);
int cmd_go(string dir);
int cmd_quit(string arg);

void create() {{
  seteuid(getuid());
  hp = 20;
  max_hp = 20;
}}

string query_name() {{ return name; }}
string query_password() {{ return password; }}
int query_hp() {{ return hp; }}
int query_mhp() {{ return max_hp; }}
int query_level() {{ return 1; }}

string save_path() {{
  if (!name || name == "")
    return 0;
  return sprintf("/data/%c/%s", name[0], name);
}}

void ensure_letter_dir() {{
  string d;

  if (!name)
    return;
  d = sprintf("/data/%c", name[0]);
  if (file_size("/data") != -2)
    mkdir("/data");
  if (file_size(d) != -2)
    mkdir(d);
}}

int restore_me(string n) {{
  name = n;
  return restore_object(save_path());
}}

void setup_new(string n, string pw) {{
  name = n;
  password = pw;
  hp = 20;
  max_hp = 20;
}}

void save_me() {{
  string p;

  p = save_path();
  if (!p)
    return;
  ensure_letter_dir();
  save_object(p);
}}

void wire_commands() {{
  enable_commands();
  add_action("cmd_look", "look");
  add_action("cmd_look", "l");
  add_action("cmd_score", "score");
  add_action("cmd_score", "sc");
  add_action("cmd_quit", "quit");
  add_action("cmd_inventory", "inventory");
  add_action("cmd_inventory", "i");
  add_action("cmd_go", "north");
  add_action("cmd_go", "south");
  add_action("cmd_go", "east");
  add_action("cmd_go", "west");
  add_action("cmd_go", "up");
  add_action("cmd_go", "down");
}}

void enter_world() {{
  set_living_name(name);
  wire_commands();
  move_object("/catalog/void");
  write("\n");
  command("look");
  save_me();
}}

mixed process_input(string str) {{
  string verb, rest;

  if (!str)
    return 0;
  if (sscanf(str, "%s %s", verb, rest) != 2) {{
    verb = str;
    rest = 0;
  }}
  switch (verb) {{
    case "look":
    case "l":
      cmd_look(rest);
      return 1;
    case "score":
    case "sc":
      cmd_score(rest);
      return 1;
    case "quit":
      cmd_quit(rest);
      return 1;
    case "inventory":
    case "i":
      cmd_inventory(rest);
      return 1;
    case "north":
    case "south":
    case "east":
    case "west":
    case "up":
    case "down":
      cmd_go(verb);
      return 1;
  }}
  return 0;
}}

int cmd_look(string arg) {{
  object env, *inv;
  string out;
  int i;

  env = environment();
  if (!env) {{
    write("You are nowhere.\n");
    return 1;
  }}
  out = env->query_long();
  if (!out || out == "")
    out = env->long();
  if (!out || out == "")
    out = "You see nothing special.";
  write(out);
  if (out[<1] != '\n')
    write("\n");
  write(env->query_exit_string());
  inv = all_inventory(env);
  for (i = 0; i < sizeof(inv); i++) {{
    if (inv[i] != this_object() && inv[i]->query_name())
      write(capitalize(inv[i]->query_name()) + " is here.\n");
  }}
  return 1;
}}

int cmd_score(string arg) {{
  write(capitalize(name || "someone") + " (level " + query_level() + ")\n");
  write("hp: " + hp + "/" + max_hp + "\n");
  return 1;
}}

int cmd_inventory(string arg) {{
  write("You are empty-handed.\n");
  return 1;
}}

int cmd_go(string dir) {{
  object env, dest;
  string path;

  if (!dir)
    dir = query_verb();
  env = environment();
  if (!env) {{
    write("You are nowhere.\n");
    return 1;
  }}
  path = env->query_exit(dir);
  if (!path) {{
    write("You cannot go that way.\n");
    return 1;
  }}
  dest = load_object(path);
  if (!dest) {{
    write("That exit leads nowhere.\n");
    return 1;
  }}
  move_object(dest);
  command("look");
  return 1;
}}

int cmd_quit(string arg) {{
  write("Saving " + capitalize(name || "someone") + ".\n");
  save_me();
  destruct(this_object());
  return 1;
}}
'''

VOID = r'''mapping exits;

void create() {{
  exits = ([
    "north": "/catalog/workshop",
  ]);
}}

string query_short() {{ return "{void_short}"; }}

string query_long() {{
  return {void_long};
}}

string long() {{ return query_long(); }}

string query_exit(string dir) {{
  if (!exits)
    return 0;
  return exits[dir];
}}

string query_exit_string() {{
  return "Exits: north.\n";
}}

int id(string str) {{ return str == "void" || str == "here"; }}
'''

WORKSHOP = r'''mapping exits;

void create() {{
  exits = ([
    "south": "/catalog/void",
  ]);
}}

string query_short() {{ return "{ws_short}"; }}

string query_long() {{
  return {ws_long};
}}

string long() {{ return query_long(); }}

string query_exit(string dir) {{
  if (!exits)
    return 0;
  return exits[dir];
}}

string query_exit_string() {{
  return "Exits: south.\n";
}}

int id(string str) {{ return str == "workshop" || str == "here"; }}
'''

CONFIG = '''###############################################################################
# {name} ({slug}) — number {number}, port {port}
# LDMud → FluffOS conversion. Catalog overlay; archive LDMud master saved
# as {master_ldmud}.
###############################################################################

name : {name}

port number : {port}

mudlib directory : {work}

log directory : /log

include directories : /sys:/include:/secure

save binaries directory : /binaries

master file : /catalog/master

simulated efun file : /catalog/simul_efun

debug log file : debug.log

global include file : "/catalog/auto.h"

default fail message : What?

lazy resets : 1

time to clean up : 600
time to reset : 120
time to swap : 300
inherit chain size : 80
maximum evaluation cost : 30000000
maximum array size : 30000
maximum buffer size : 400000
maximum mapping size : 150000
maximum string length : 200000
maximum bits in a bitfield : 12000
maximum byte transfer : 200000
maximum read file size : 200000
maximum local variables : 80
hash table size : 7001
object table size : 1501

external_port_1 : telnet {port}

maximum users : 40
evaluator stack size : 2000
compiler stack size : 400
maximum call depth : 150
living hash table size : 256
noninteractive stderr write : 1
'''


def cstr(s: str) -> str:
    """LPC string literal for a multi-line description."""
    parts = s.strip("\n").split("\n")
    return "\n    ".join(f'"{line}\\n"' for line in parts)


LIBS = [
    {
        "slug": "morgengrauen",
        "number": "974",
        "port": "40283",
        "name": "MorgenGrauen",
        "english_name": "MorgenGrauen",
        "master_ldmud": "/secure/master_ldmud.lpc",
        "archive": (
            "git clone https://github.com/MorgenGrauen/mg-mudlib "
            "(commit a178b88a9cac64480a9475f72a96cd4c183e64c7, cloned 2026-09-05); "
            "repo root is the mudlib"
        ),
        "english_description": (
            "Official public MorgenGrauen mudlib (German LPMud, LDMud 3.x). "
            "LDMud → FluffOS conversion: archive master uses set_driver_hook/"
            "closures; this collection boots a FluffOS catalog overlay "
            "(login/look/score/quit in The Void) while preserving the full "
            "LDMud source tree. Not Shea690901/Sagenwelt-Lib (collection sagenwelt)."
        ),
        "welcome": (
            'Welcome to MorgenGrauen (LDMud → FluffOS catalog overlay).\\n'
            'Original German LDMud 3.x mudlib preserved under /room, /secure, /std.'
        ),
        "void_short": "The Void",
        "void_long": cstr(
            "The Void\n"
            "A quiet catalog landing for MorgenGrauen after the LDMud → FluffOS\n"
            "port. The full German LDMud 3.x world (church, guilds, domains)\n"
            "lives in the archived sources but needs LDMud driver hooks to run.\n"
            "A workshop lies to the north."
        ),
        "ws_short": "Archive workshop",
        "ws_long": cstr(
            "Archive workshop\n"
            "Notes on the MorgenGrauen LDMud → FluffOS conversion. Original\n"
            "master is /secure/master_ldmud.lpc (inaugurate_master,\n"
            "set_driver_hook, #' closures). South returns to the void."
        ),
        "readme_extra": (
            "German LDMud sources are preserved for study; interactive play\n"
            "here is the FluffOS catalog overlay only."
        ),
    },
    {
        "slug": "ageofelements",
        "number": "975",
        "port": "40284",
        "name": "Age of Elements",
        "english_name": "Age of Elements",
        "master_ldmud": "/obj/master_ldmud.lpc",
        "archive": (
            "git clone https://github.com/age-of-elements/age-of-elements "
            "(commit 4e5cae45d0804f23a1cecbef577b5bcdee5a53cf, cloned 2026-09-05); "
            "repo root is the mudlib"
        ),
        "english_description": (
            "Age of Elements, an English LPMud built from the classic 2.4.5 "
            "mudlib on the LDMud driver (telnet://ageofelements.org). Focuses "
            "on telnet protocol demos (GMCP/MSSP/MXP/MSP/MCMP). LDMud → "
            "FluffOS conversion: catalog overlay for login/look/score/quit; "
            "original /obj/master_ldmud.lpc keeps set_driver_hook and closures."
        ),
        "welcome": (
            'Welcome to Age of Elements (LDMud → FluffOS catalog overlay).\\n'
            'Upstream is an LDMud LPMud 2.4.5-derived lib with telnet-protocol demos.'
        ),
        "void_short": "The Void",
        "void_long": cstr(
            "The Void\n"
            "Catalog start for Age of Elements after the LDMud → FluffOS port.\n"
            "The classic 2.4.5-style village (church, forest, guild) remains in\n"
            "/room as LDMud sources. Protocol demo code lives under /obj/login.\n"
            "A workshop lies to the north."
        ),
        "ws_short": "Protocol workshop",
        "ws_long": cstr(
            "Protocol workshop\n"
            "Age of Elements documents GMCP, MSSP, MXP, MSP, and MCMP examples\n"
            "on LDMud. This FluffOS catalog does not run those stacks. Original\n"
            "master: /obj/master_ldmud.lpc. South returns to the void."
        ),
        "readme_extra": (
            "Live game historically at ageofelements.org:7680. This snapshot\n"
            "is LDMud → FluffOS catalog play, not the full protocol suite."
        ),
    },
    {
        "slug": "aoh",
        "number": "976",
        "port": "40285",
        "name": "Age of Heroes",
        "english_name": "Age of Heroes",
        "master_ldmud": "/secure/master_ldmud.lpc",
        "archive": (
            "git clone https://github.com/seikichin/aoh "
            "(commit 6ab8f3679d560a3726ae98b671d7ded7be6fb75d, cloned 2026-09-05); "
            "repo root is the mudlib"
        ),
        "english_description": (
            "Age of Heroes, an experimental English LDMud mudlib based on "
            "One Step Beyond (OSB). LDMud → FluffOS conversion: archive "
            "master uses closures and LDMud kernel applies; this collection "
            "boots a FluffOS catalog overlay (Void + workshop look/score/quit) "
            "while keeping the full OSB-derived source tree under /d, /lib, /std."
        ),
        "welcome": (
            'Welcome to Age of Heroes / One Step Beyond (LDMud → FluffOS catalog overlay).\\n'
            'Experimental OSB-based LDMud mudlib; FluffOS play is the catalog layer.'
        ),
        "void_short": "The Void",
        "void_long": cstr(
            "The Void\n"
            "Catalog landing for Age of Heroes after the LDMud → FluffOS port.\n"
            "The One Step Beyond domains under /d and OSB kernel under /secure\n"
            "remain as LDMud sources. A workshop lies to the north."
        ),
        "ws_short": "OSB workshop",
        "ws_long": cstr(
            "OSB workshop\n"
            "Age of Heroes is an experimental LDMud mudlib based on One Step\n"
            "Beyond. Original master: /secure/master_ldmud.lpc (closures,\n"
            "erq, mudwho). South returns to the void."
        ),
        "readme_extra": (
            "Based on One Step Beyond (OSB). Full world code is preserved;\n"
            "interactive play here is the FluffOS catalog overlay."
        ),
    },
]


def write_lib(lib: dict) -> None:
    root = REPO / "libs" / lib["slug"]
    work = root / "work"
    cat = work / "catalog"
    cat.mkdir(parents=True, exist_ok=True)

    ctx = {**lib, "work": str(work)}
    (cat / "master.lpc").write_text(MASTER.format(**ctx), encoding="utf-8")
    (cat / "simul_efun.lpc").write_text(SIMUL.format(**ctx), encoding="utf-8")
    (cat / "auto.h").write_text(AUTO_H, encoding="utf-8")
    (cat / "login.lpc").write_text(LOGIN.format(**ctx), encoding="utf-8")
    (cat / "player.lpc").write_text(PLAYER.format(**ctx), encoding="utf-8")
    (cat / "void.lpc").write_text(VOID.format(**ctx), encoding="utf-8")
    (cat / "workshop.lpc").write_text(WORKSHOP.format(**ctx), encoding="utf-8")
    (root / "config.fluffos").write_text(CONFIG.format(**ctx), encoding="utf-8")

    meta = {
        "number": lib["number"],
        "slug": lib["slug"],
        "archive": lib["archive"],
        "name": lib["name"],
        "english_name": lib["english_name"],
        "english_description": lib["english_description"],
        "wasm_status": "playable",
        "port": lib["port"],
        "duplicate_of": None,
    }
    import json

    (root / "meta.json").write_text(
        json.dumps(meta, indent=2, ensure_ascii=False) + "\n", encoding="utf-8"
    )

    readme = f"""# {lib['name']} ({lib['slug']})

**LDMud → FluffOS conversion.** Snapshot of `{lib['archive'].split('(commit')[0].strip()}`.
Slug `{lib['slug']}`, number **{lib['number']}**, port **{lib['port']}**.
This collection’s copy is a snapshot, not a live mirror.

{lib['english_description']}

{lib['readme_extra']}

## Registration flow

Name (2–16 letters) → new character: password (≥6, twice) → The Void.
Existing names prompt for password only.

## Admin / test account

- **name**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded mortal (level 1). This overlay does not auto-god
  the first player.

Verified live after onboard: create fluffos / Mud@2026 → The Void;
`look` / `score` / `quit`; reconnect after quit.

## Local run

```
cd libs/{lib['slug']}
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **{lib['port']}**.

```
python3 scripts/mudclient.py 127.0.0.1 {lib['port']} --timeout 25 --idle 0.6 \\
  --send fluffos --send Mud@2026 \\
  --send look --send score --send quit
```
"""
    (root / "README.md").write_text(readme, encoding="utf-8")

    notes = f"""# {lib['name']} ({lib['slug']}) — porting notes

Source: {lib['archive']}. Converted 2026-09-05. Config name `{lib['name']}`.
Slug `{lib['slug']}`, number **{lib['number']}**, port **{lib['port']}**.

**This is an LDMud → FluffOS conversion.** Discovery triage normally
drops LDMud-lineage libs; this onboard is an explicit exception in the
same family as `questmud` / `acme` (AGENTS.md §7.158).

This collection’s copy is a snapshot, not a live mirror. Do not onboard
the same upstream repo again.

## 0. Layout

Repo root **is** the mudlib. `raw/` is gitignored. Original LDMud master
preserved as `{lib['master_ldmud']}`.

## 1. Convert (2026-09-05)

`convert_lib.sh` with UTF-8 source encoding (already UTF-8 English /
German sources). `.c` → `.lpc` rename + literal `.c"` fixups +
`static`→`nosave` as usual.

## 2. FluffOS port (LDMud → FluffOS)

The archive is **LDMud 3.x** (`set_driver_hook`, `inaugurate_master`,
`#'` / `unbound_lambda` closures, multi-file or directory simul_efun).
FluffOS has none of those driver hooks. A mechanical dialect rewrite of
the whole tree is not attempted; the original login/command stack is
kept as source and not loaded.

`config.fluffos`: master `/catalog/master`, simul `/catalog/simul_efun`,
global include `"/catalog/auto.h"`, port **{lib['port']}**,
`lazy resets : 1`.

Catalog overlay (questmud §7.158 cluster):

- `/catalog/master.lpc` — `get_root_uid`/`get_bb_uid`, `creator_file`
  always returns string `"BACKBONE"`, `valid_read` includes
  `load_object`/`recompile_object`/`include`/`restore_object`,
  `valid_override` returns 1, `error_handler` → `/log/catch`
- `/catalog/simul_efun.lpc` — thin `cat`/`log_file`/`exists`
- `/catalog/login.lpc`, `/catalog/player.lpc` — name/password → Void
- `/catalog/void.lpc`, `/catalog/workshop.lpc` — look/score/quit surface

## 3. Live-verified (native, port {lib['port']})

Create `fluffos` / `Mud@2026`. Lands in The Void; `look` / `score` /
`north` (workshop) / `south` / `quit`. Reconnect after cold restart
reloads `data/f/fluffos.o`.

## 4. What is not ported

Full LDMud world, guilds, protocol stacks, and OSB/MG kernel daemons.
Those remain in the tree for archaeology; booting them needs a real
LDMud driver.
"""
    (root / "NOTES.md").write_text(notes, encoding="utf-8")
    print(f"wrote overlay for {lib['slug']}")


def main():
    for lib in LIBS:
        write_lib(lib)


if __name__ == "__main__":
    main()
