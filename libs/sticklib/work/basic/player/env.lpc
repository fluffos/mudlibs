/*
 * This object file contains the basic system for environment variables,
 * set_env and query_env functions, and other functions related to them,
 * such as the terminal highlite option.
 *
 * 010993 Starbyt
 *
 */

mapping Env;

int
set_env (mixed env, mixed val)
{
    if (!Env)
	Env = ([ ]);

    if (!val)
	Env = m_delete (Env, env);
    else {
	if (!intp(val) && !stringp(val)) return 0;
	Env[env] = val;
    }
    return 1;
}

mixed
query_env (mixed env)
{
    if (!env || !Env)
	return Env;

    return Env[env];
}


/*
  terminal effects

  we support all vt100 standard terminal modes:
  normal text, dim text, bright text, underlined, flashing, inversed

  with ansi text dim text is replaced with blue colour and flashing text
  by red.

  no other terminal types supported, yet.
*/

string /* reset terminal and clear screen */
term_clear() {
    switch (Env["term"]) {
    case "ansi": case "vt100": return "\033[0m\033[c";
    default: return ""; }
}

string
term_reset() {
    switch (Env["term"]) {
    case "ansi": case "vt100": return "\033[0m";
    default: return ""; }
}

string  /* bright text on. vt100 and ansi: bold */
term_bright_on() {
    /* temp fix */
    if (!Env) Env = ([ ]);
    switch (Env["term"]) {
    case "ansi": case "vt100": return "\033[1m";
    default: return ""; }
}

string
term_bright_off() {
    switch (Env["term"]) {
    case "ansi": case "vt100": return "\033[0m";
    default: return "";
    }
}

string /* dim txet. */
term_dim_on() {
    switch (Env["term"]) {
    case "vt100": return "\033[2m";
    case "ansi":  return "\033[35m"; /* ansi simulates dim with blue */
    default: return ""; }
}

string
term_dim_off() {
    switch (Env["term"]) {
    case "vt100": return "\033[0m";
    case "ansi": return "\033[0m";
    default: return ""; }
}

string
bright_text(string s)
{
    return term_bright_on() + s + term_bright_off();
}

string
dim_text(string s)
{
    return term_dim_on() + s + term_dim_off();
}
