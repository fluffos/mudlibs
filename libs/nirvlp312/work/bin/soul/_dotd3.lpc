inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You note: Dumb bastard's got them moved into one building.#RET#Dumb little bastard.$N$\n", "#MN# notes: Dumb bastard's got them moved into one building.#RET#Dumb little bastard.$N$\n");
       target("You note to #TN#: Dumb bastard's got them moved into one building.#RET#Dumb little bastard.$N$\n", "#MN# notes to #TN#: Dumb bastard's got them moved into one building.#RET#Dumb little bastard.$N$\n", "#MN# notes to you: Dumb bastard's got them moved into one building.#RET#Dumb little bastard.$N$\n");
       afar("You note to #TN# from afar: Dumb bastard's got them moved into one building.#RET#Dumb little bastard.$N$\n", "#MN# notes to you from afar: Dumb bastard's got them moved into one building.#RET#Dumb little bastard.$N$\n");
    }
}

int
cmd_dotd3(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
