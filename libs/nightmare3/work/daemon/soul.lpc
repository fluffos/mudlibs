/*    /daemon/soul.c
 *    from Nightmare IV
 *    fear a soul from Discworld
 *    created by Pinkfish@Discworld on an unknown date
 *    ported to Nightmare doing very little by Descartes of Borg 940207
 */

#include <soul.h>
#include <save.h>
#include <daemons.h>
#include <security.h>

private mapping __Soul;
nosave private string __Adj, __Chunk;
nosave private object __CurrentTarget;

private void become_emotional(mapping info, string adj, object *who);
private void compile_soul(string str);
private string compile_message(mixed *parts, object *targets);
private string remove_whitespace(string str);
protected string filter_stuff(mixed *parts, object *targets);
private void save_soul();
private void restore_soul();
protected string handle_names(object ob);
private void compile_file(string str);
private void parse_assoc(mapping borg);
private mixed parse_chunk();
private mapping parse_mapping();
private string *parse_array();

void create() {
    string *files;
    int i;

    if(file_exists(SAVE_SOUL+".o")) restore_soul();
    if(!__Soul || !sizeof(__Soul)) {
        __Soul = ([]);
        i = sizeof(files = get_dir(DIR_SOUL_FILES+"/"));
        while(i--) compile_soul(files[i]);
    }
    call_out("save_soul", 60);
}

object *match_living(string nom) {
    object *who;
    object ob;

    if(!nom || nom == "") return ({});
    if(nom == "everyone") {
        who = filter_array(all_inventory(environment(this_player())),
          (: living :));
        return who - ({ this_player() });
    }
    else if(ob = present(lower_case(nom), environment(this_player())))
      return (hiddenp(ob) || ob == this_player()) ? ({}) : ({ ob });
    else return ({});
}

varargs string match_adj(string str, mapping data1, mapping data2) {
    string a, b;

    a = (data1["adverbs"] ? data1["adverbs"] : "");
    b = (data2["adverbs"] ? data2["adverbs"] : "");
    if(str == "" && b[0] == '#' && strlen(b) > 2) b = b[2..strlen(b)-1];
    if(a[0] == '#' || b[0] == '#') return str;
    if(sscanf(sprintf(",%s,%s,", b, a), "%s,"+str+"%s,", a, b)) {
        if(b && strlen(b)) return sprintf("%s%s", str, b);
        else return str;
    }
    return 0;
}

int do_cmd(string verb, string arg) {
    mapping data, info;
    object *target;
    string *args;
    string adj;

    if(!(data = __Soul[verb])) return 0;
    target = ({});
    if(!arg) {
        info = data["noargs"];
        adj = "nothing";
        args = ({ arg = "" });
    }
    if(!info) {
        if(!args) {
            args = explode(arg, " ");
	}
        if(data["prepositions"]) args = args - (string *)data["prepositions"];
        arg = implode(args, " ");
        if(sizeof(args) == 1) {
            if(!sizeof(target = match_living(arg))) {
                if(!(info = data["undirected"])) {
                    message("emote", sprintf("%s whom?", capitalize(verb)),
                      this_player());
                    return 1;
                }
                adj = match_adj(arg, data, info);
            }
            else {
                if(!(info = data["directed"]))
                  return notify_fail("That makes no sense.\n");
                adj = match_adj("", data, info);
            }
        }
        else {
            if(sizeof(target = match_living(args[0]))) {
                if(!(info = data["directed"]))
                  return notify_fail("That makes no sense.\n");
		adj = match_adj(implode(args[1..sizeof(args)-1]," "),data,info);
            }
            else {
                if(sizeof(target = match_living(args[sizeof(args)-1]))) {
                    if(!(info = data["directed"]))
                      return notify_fail("That makes no sense.\n");
                    adj = match_adj(implode(args[0..sizeof(args)-2], " "),
                      data, info);
                }
                else {
                    if(!(info = data["undirected"])) {
                        message("emote", sprintf("%s whom?", capitalize(verb)),
                          this_player());
                        return 1;
                    }
                    adj = match_adj(arg, data, info);
                }
            }
        }
    }
    if(!adj) {
        message("emote", sprintf("What an odd way in which to %s!", verb),
          this_player());
	return 1;
    }
    become_emotional(info, adj, target);
    return 1;
}

void become_emotional(mapping info, string adj, object *who) {
    string cmd;
    int i;

    __Adj = adj;
    __CurrentTarget = 0;
    message("emote", compile_message(info["mymsg"], who), this_player());
    if(!who || !sizeof(who))
      message("emote", compile_message(info["theirmsg"], ({})),
        environment(this_player()), ({ this_player() }));
    else message("emote", compile_message(info["theirmsg"], who),
      environment(this_player()), ({ this_player() }) + who);
    i = sizeof(who);
    while(i--) {
        __CurrentTarget = who[i];
        if(info["obmsg"])
          message("emote", compile_message(info["obmsg"], who), who[i]);
        else message("emote", compile_message(info["theirmsg"], who), who[i]);
      }
  }

void compile_soul(string str) {
    compile_file(sprintf("%s/%s", DIR_SOUL_FILES, str));
}

string compile_message(mixed *parts, object *targets) {
    return filter_stuff(parts, targets);
  }

string compile_names(object *who) {
    int x;

    if((x = sizeof(who)) == 1) return handle_names(who[0]);
    else return implode(map_array(who[1..x-1], "handle_names", this_object()),
      ", ") + " and " + handle_names(who[0]);
  }

protected void save_soul() {
    save_object(SAVE_SOUL);
}

 private void restore_soul() {
    restore_object(SAVE_SOUL);
}

string filter_stuff(mixed *parts, object *targets) {
    string *arr;

    arr = map_array(parts, "handle_part", this_object(), targets) - ({ "" });
    return implode(arr, " ");
  }

string handle_names(object ob) {
    if(!ob) return "";
    if(ob == __CurrentTarget) return "you";
    else return (string)ob->query_cap_name();
  }

string handle_part(mixed part, object *targets) {
    if(stringp(part)) return part;
    else switch(part) {
    case ADJ: return __Adj;
    case TP_NAME: return (string)this_player()->query_cap_name();
    case TP_PRONOUN: return nominative(this_player());
    case TP_POSSESSIVE: return possessive(this_player());
    case TP_NPOSS: return possessive_noun(this_player());
    case TP_FOO: return reflexive(this_player());
    case OB_NAME: return compile_names(targets);
    case OB_PRONOUN: return nominative(targets[0]);
    case OB_POSSESSIVE: return possessive(targets[0]);
    case OB_NPOSS: return possessive_noun(targets[0]);
    case OB_FOO: return reflexive(targets[0]);
    }
    return part + "";
  }

mapping query_soul() { return copy(__Soul); }

 private void compile_file(string file) {
    string *cles;

    if(!(file = read_file(file))) error("Failed to read file.\n");
    file = replace_string(file, "\t", "");
    cles = map_array(explode(file, "\n"), "remove_indentation", this_object());
    filter_array(explode(implode(cles, ""), "$$"), "decode_file",this_object());
  }

protected void decode_file(string str) {
    call_out("define_action", 0, str);
}

protected void define_action(string str) {
    __Chunk = remove_whitespace(str);
    parse_assoc(__Soul);
  }

 private void parse_assoc(mapping borg) {
    string str;
    mixed val;

    if(sscanf(__Chunk, "(%s %s", str, __Chunk) < 2)
      error("Syntax error compiling file in parse_assoc().\n");
    val = parse_chunk();
    __Chunk = __Chunk[1..strlen(__Chunk)-1];
    borg[str] = val;
  }

 private mixed parse_chunk() {
    string str;

    __Chunk = remove_whitespace(__Chunk);
    switch(__Chunk[0]) {
    case '*': return parse_mapping();
    case '[': return parse_array();
    case '(': return error("Syntax error compiling file in parse_chunk().\n");
    }
    if(sscanf(__Chunk, "%s)%s", str, __Chunk) == 2) return str;
    error("sscanf() failed in parse_chunk().\n");
  }

 private mapping parse_mapping() {
    mapping borg;
    int i;

    borg = ([]);
    if(!sscanf(__Chunk, "*(%s", __Chunk))
        error("Failed: sscanf() in parse_mapping().\n");
    while((__Chunk = remove_whitespace(__Chunk))[0] != ')') parse_assoc(borg);
    __Chunk = __Chunk[1..strlen(__Chunk)-1];
    return borg;
  }

 private string *parse_array() {
    string str;

    if(sscanf(__Chunk, "[%s]%s", str, __Chunk) != 2)
      error("Failed: sscanf() in parse_array().\n");
    return map_array(explode(str, " "), "fix_macros", this_object());
  }

protected mixed fix_macros(string foo) {
    if(foo[0] == '$') {
        switch(foo) {
        case "$ADJ": return ADJ;
        case "$TP_NAME": return TP_NAME;
        case "$OB_NAME": return OB_NAME;
        case "$TP_PRONOUN": return TP_PRONOUN;
        case "$OB_PRONOUN": return OB_PRONOUN;
        case "$TP_POSS": return TP_POSSESSIVE;
        case "$OB_POSS": return OB_POSSESSIVE;
        case "$TP_NPOSS": return TP_NPOSS;
        case "$OB_NPOSS": return OB_NPOSS;
        case "$TP_FOO": return TP_FOO;
        case "$OB_FOO": return OB_FOO;
	}
      }
    return foo;
  }

protected string remove_indentation(string str) {
    str = remove_whitespace(str);
    if(!(['(': 1, '[':1, '*':1 ])[str[0]]) return str;
    else return sprintf(" %s", str);
  }

void recompile_soul() {
    string *files;
    int i;

    __Soul = ([]);
    i = sizeof(files = get_dir(DIR_SOUL_FILES+"/"));
    while(i--) compile_soul(files[i]);
    save_soul();
}

 private string remove_whitespace(string str) {
    while(sscanf(str, "    %s", str));
    sscanf(str, "  %s", str);
    sscanf(str, " %s", str);
    return str;
}
