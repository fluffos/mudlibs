#pragma save_binary
/*
   mudlib:  Basis
   file:    /bin/daemon/emoted.c
   author:  Truilkan
   created: 1992/09/25

   modified by Truilkan to run on tmi-2 on 1992/11/09
*/

// Use the /t suffix if you want to edit the targeted version of the emotion.
// To enter something in any of the fields, just add something on the line after
// the header for it.  For example, any lines entered between the .me line, and
// the .others line will be the message displayed to the user of the command.

// For reference, the replaceable parameters are:

//   $N = name of user       $n = name of target
//   $S = subjective of user $O = objective of user  $P = possessive of user
//   $s =   ''     '' target $o =   ''    '' target  $p =    ''   '' target

//   $M = modifier (only appears if user ends command with " .")
//   $m = modifier (always appears unless user types own modifier or " .")
//   $V = verb (defaults to command name.  can be set with .verb)
//   $G = possessive of user (either $N's or 'your' depending)
//   $g = possessive of target ('' $n's '')
//   $Q = preceding possessive (i.e. hers, his, its, hirs, yours) for user
//   $q = '' for target

//   For $S, $O, $P, $s, $o, $p:

//   subjective = (he, she, it, sie), objective = (him, her, it, hir),
//   possessive = (his, her, its, hir)

// Mobydick added a lower_case() so that "kiss Psyche" would work as
// well as "kiss psyche" does.
// Pallando fixed lower_case() for the case someone just types "kiss"

#include <config.h>
#include <daemons.h>
#include <emoted.h>

inherit SAVE_D;

mapping temotes, emotes;

mixed *
copy_array(mixed *array)
{
    if (!pointerp(array))
        return 0;
    else
        return array[0..(sizeof(array) - 1)];
}

int
query_prevent_shadow()
{
        return 1;
}

void
create()
{
	temotes = ([]);
	emotes = ([]);
	set_persistent(1); // cause create()/remove() to load/save data
	seteuid(getuid());
	save::create();       // restore the datafile
}

string *
query_keys()
{
	return uniq_array(keys(temotes) + keys(emotes));
}

string *
query_emotes()
{
	return keys(emotes);
}

string *
query_temotes()
{
	return keys(temotes);
}

string
to_string(mapping entry)
{
	string result, *fields, val;
	int x;

	result = 0;
	if (mapp(entry)) {
		result = "";
		fields = FIELDS;
		for (x = 0; x < sizeof(fields); x++) {
			if (entry && !undefinedp(val = entry[x])) {
				result += (fields[x] + "\n");
				result += (val + "\n");
			}
		}
		result += ".end\n";
	}
	return result;
}


mapping
to_mapping(string body)
{
	int i, size, x, start;
	string *lines, *fields, *stop_fields;
	mapping new_entry;

	if (!body) {
		return 0;
	}
	lines = explode(body, "\n");
	size = sizeof(lines);
	new_entry = ([]);
	fields = FIELDS;
	stop_fields = STOP_FIELDS;
	for (x = 0; x < sizeof(fields); x++) {
		i = member_array(fields[x], lines) + 1;
		if (!i) {
			continue;
		}
		if ((i < size) && ((member_array(lines[i], stop_fields) == -1))) {
			new_entry[x] = "";
			start = i;
			for (;(i < size)&&(member_array(lines[i],stop_fields) == -1);i++) {
				if (i != start) {
					new_entry[x] += "\n" + lines[i];
				} else {
					new_entry[x] += lines[i];
				}
			}
		}
	}
	return new_entry;
}

// return a processed map to its original form

mapping
unprocess(mapping entry)
{
	string *words, line, field;
	mapping new_entry;
	int *idx, j, k;

	if (!entry) {
		return 0;
	}
	idx = keys(entry);
	new_entry = allocate_mapping(sizeof(entry));
	for (j = 0; j < sizeof(idx); j++) {
		if ((idx[j] == e_verb) || (idx[j] == e_verb2)) {
			new_entry[idx[j]] = entry[idx[j]];
		} else {
			words = entry[idx[j]];
			line = "";
			for (k = 0; k < sizeof(words); k++) {
				field = words[k];
				if (field[0] == 'X') {
					field = field[1..(strlen(field) - 1)];
				} else {
					field = "$" + field;
				}
				line += field;
			}
			new_entry[idx[j]] = line;
		}
	}
	return new_entry;
}

// query an emote without a target

string
query_emote(string verb)
{
	return to_string(unprocess(emotes[verb]));
}

// query an emote with a target

string
query_temote(string verb)
{
	return to_string(unprocess(temotes[verb]));
}

// process: convert the map into a form that may be parsed more efficiently

mapping
process(mapping entry)
{
	string *words, line;
	int *idx;
	int j;

	if (!entry) {
		return 0;
	}
	idx = keys(entry);
	for (j = 0; j < sizeof(idx); j++) {
		if ((idx[j] != e_verb) && (idx[j] != e_verb2)) {
			line = entry[idx[j]];
			words = explode(line, "$");
			if (line[0] != '$') {
				words[0] = "X" + words[0];
			}
			entry[idx[j]] = words;
		}
	}
	return entry;
}

// add a temote

void
add_temote(string verb, string body)
{
	if (!body) {
		return;
	}
	temotes[verb] = process(to_mapping(body));
}

// add an emote

void
add_emote(string verb, string body)
{
	mapping entry;

	if (!body) {
		return;
	}
	entry = to_mapping(body);
	if (undefinedp(entry[e_target])) {
		emotes[verb] = process(entry);
	} else {
		add_temote(verb, body);
	}
}

void
delete_emote(string verb)
{
	map_delete(emotes, verb);
}

void
delete_temote(string verb)
{
	map_delete(temotes, verb);
}

string
apostrophed(string name)
{
	int len;

	len = strlen(name);
	if (name[len - 1] == 's') {
		return name + "'";
	} else {
		return name + "'s";
	}
}

string
cap_it(string str, int do_cap)
{
	if (do_cap) {
		return capitalize(str);
	} else {
		return str;
	}
}

// make the substitutions for the various $variables

string
substitute(string verb, string verb2, int kind, string rest, string *words,
	string *modifier, object me, object target)
{
	string name, pronoun, mo, remainder, temp;
	string plural, plural2;
	int j, forced, do_cap;

	for (j = 0; j < sizeof(words); j++) {
		forced = 0;
		if (!j) {
			do_cap = 1;
		} else if (words[j][0] == 'c') {
			words[j] = words[j][1..(strlen(words[j]) - 1)];
			do_cap = 1;
		} else {
			do_cap = 0;
		}
		remainder = words[j][1..(strlen(words[j]) - 1)];
		switch (words[j][0]) {
			case 'X' :  // empty replacement (necessary)
				words[j] = remainder;
				break;
			case 'V' :
				if (kind == e_me) {
					words[j] = cap_it(verb, do_cap) + remainder;
				} else {
					if (!plural) {
						plural = pluralize_verb(verb);
					}
					words[j] = cap_it(plural, do_cap) + remainder;
				}
				break;
			case 'W' :
				if (kind == e_me) {
					words[j] = cap_it(verb2, do_cap) + remainder;
				} else {
					if (!plural2) {
						plural2 = pluralize_verb(verb2);
					}
					words[j] = cap_it(plural2, do_cap) + remainder;
				}
				break;
			case 'N' :  // my name
				if (kind == e_me) {
					name = "you";
				} else {
					name = (string)me->query("cap_name");
				}
				words[j] = cap_it(name, do_cap) + remainder;
				break;
			case 'n' : // name of the target
				if (target == me) {
					switch (kind) {
						case e_me :
							name = "yourself";
							break;
						case e_others :
						case e_target :
							if (!mo) {
								mo = objective((string)me->query("gender"));
							}
							name = cap_it(mo, do_cap) + "self"; break;
							break;
						default :
							break;
					}
				} else {
					if (target) {
						if (kind == e_target) {
							name = "you";
						} else {
							name = (string)target->query("cap_name");
						}
					} else {
						name = "";
					}
				}
				words[j] = cap_it(name, do_cap) + remainder;
				break;
			case 'Q' :
				if (kind == e_me) {
					pronoun = "yours";
				} else {
					pronoun = ppossessive((string)me->query("gender"));
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			case 'q' :
				if (kind == e_target) {
					pronoun = ppossessive((string)target->query("gender"));
				} else {
					pronoun = "yours";
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			case 'G' :
				if (kind == e_me) {
					pronoun = "your";
				} else {
					pronoun = apostrophed((string)me->query("cap_name"));
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			case 'g' :
				if ((kind == e_target) || ((kind == e_me) && (me == target))) {
					pronoun = "your";
				} else if (target == me) {
					pronoun = possessive((string)target->query("gender"));
				} else {
					pronoun = apostrophed((string)target->query("cap_name"));
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			case 'm' :
				forced = 1;
			case 'M' : // replace with extra text or default
				temp = remainder;
				if ((!forced && (rest == ".")) || (forced && !rest)) {
					if (pointerp(modifier)) {
						rest = substitute(verb, verb2, kind, "",
								modifier, 0, me, target);
					}
				}
				if (!rest || (rest == ".")) {
					int rlen;

					rest = "";
					rlen = strlen(temp);
					if (rlen && (temp[0] == ' ')) {
						temp = temp[1..(rlen - 1)];
					}
				}
				words[j] = cap_it(rest, do_cap) + temp;
				break;
			case 'S' : // subjective pronoun for me
				if (kind == e_me) {
					pronoun = "you";
				} else {
					pronoun = subjective((string)me->query("gender"));
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			case 's' : // subjective pronoun for target
				if (kind == e_target) {
					pronoun = "you";
				} else {
					pronoun = subjective((string)target->query("gender"));
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			case 'P' :  // possessive pronoun for me
				if (kind == e_me) {
					pronoun = "your";
				} else {
					pronoun = possessive((string)me->query("gender"));
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			case 'p' :  // possessive pronoun for target
				if (kind == e_target) {
					pronoun = "your";
				} else {
					pronoun = possessive((string)target->query("gender"));
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			case 'O' :  // objective pronoun for me
				if (kind == e_me) {
					pronoun = (target == me) ? "yourself" : "you";
				} else {
					pronoun = objective((string)me->query("gender"));
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			case 'o' :  // objective pronoun for target
				if (kind == e_target) {
					pronoun = "you";
				} else {
					if ((kind == e_me) && (target == me)) {
						pronoun = "yourself";
					} else {
						pronoun = objective((string)target->query("gender"));
					}
				}
				words[j] = cap_it(pronoun, do_cap) + remainder;
				break;
			default :  // words[j] unchanged
				break;
		}
	}
	return implode(words, "");
}

string
punctuate(string result)
{
	int len, ch, ch2;

	if ((len = strlen(result)) < 3) {
		return result;
	}
	ch = result[len - 1];
	ch2 = result[len - 2];
	if ((ch == '.') && (ch2 == ' ')) {
		return result[0 .. (len - 3)] + ".";
	}
	if (ch == ' ') {
		result = result[0..(len - 2)];
		ch = result[len - 2];
	}
	if ((ch != '.') && (ch != '!') && (ch != '?')) {
		return result + ".";
	} else {
		return result;
	}
}

varargs void
do_emote(string verb, string verb2, string rest, mapping entry, object me,
	object target, int test, int same_super)
{
	string result, *mods, *words, *values, *def;

	mods = copy_array(entry[e_modifier]);
	def = entry[e_me];
	if (!def) {
		if (target) {
			def = ({"N ", "V ", "M at ", "n"});
		} else {
			def = ({"N ", "V ", "M"});
		}
	}
	if (def[0] != "X*empty") {
		result = substitute(verb, verb2, e_me, rest, copy_array(def),
			mods, me, target);
		result = punctuate(result);
		if (target && !same_super) {
			result = "*" + result;
		}
		if (test) {
			write("me:\n" + result + "\n");
		} else {
			write(result + "\n");
		}
	}
	if (target && (target != me)) {
		mods = copy_array(entry[e_modifier]);
		if (!(values = entry[e_target])) {
			values = entry[e_others];
			if (!values) {
				values = def;
			}
		}
		if (values && (values[0] != "X*empty")) {
			result = substitute(verb, verb2, e_target, rest,
				copy_array(values), mods, me, target);
			result = punctuate(result);
			if (target && !same_super) {
				result = "*" + result;
			}
			if (test) {
				write("target:\n" + result + "\n");
			} else {
				tell_object(target, result + "\n");
			}
		}
	}
	if (!target || same_super) {
		mods = copy_array(entry[e_modifier]);
		if (!(values = entry[e_others])) {
			values = def;
		}
		if (values) {
			result = substitute(verb, verb2, e_others, rest,
				copy_array(values), mods, me, target);
			result = punctuate(result);
			if (test) {
				write("others:\n" + result + "\n");
			} else {
				say(result + "\n", target);
			}
		}
	}
}

varargs int
parse(string command, string rest, int test)
{
	string head, tail, verb, verb2;
	object target, me;
	mapping entry, tentry;
	int same_super;

	entry = emotes[command];
	tentry = temotes[command];
	same_super = 0;
	if (!rest) {
		rest = (string)this_player()->getenv(command);
	}
	if (!mapp(entry) && !mapp(tentry)) { // not a recognized emote
		return 0;
	}
	me = this_player();
	if (rest && (sscanf(rest, "%s %s", head, tail) != 2)) {
		head = rest;
		tail = 0;
	}
	if(head) head = lower_case(head);
	if (rest) {
		if (mapp(tentry)) {
   seteuid(getuid(this_player()));
   if(head) target = find_player(head);
		if(!target)  target = present(head, environment(me));
   seteuid(getuid(this_object()));
			if (target && me) {
				same_super = (environment(target) == environment(me));
			}
			if (target && (wizardp(me) || same_super)) {
				rest = tail;
				if (!rest)
					rest = (string)this_player()->getenv(command);
			} else {
				target = 0;
			}
		}
	}
	if (target && living(target)) {
		if (!(verb = tentry[e_verb])) {
			verb = command;
		}
		verb2 = tentry[e_verb2];
		do_emote(verb, verb2, rest, tentry, me, target, test, same_super);
	} else {
		if (!entry) {
			return 0;
		}
		if (!(verb = entry[e_verb])) {
			verb = command;
		}
		verb2 = entry[e_verb2];
		do_emote(verb, verb2, rest, entry, me, target, test, same_super);
	}
	return 1;
}
