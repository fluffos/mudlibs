inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You wish you were as cool as Pain.#RET#Then you light yourself on fire.$N$\n", "#MN# wishes #MS# were as cool as Pain.#RET#Then #MS# lights #MO#self on fire.$N$\n");
       target("You wish you were as cool as #TN#.$N$\n", "#MN# wishes #MS# were as cool as #TN#.$N$\n", "#MN# wishes #MS# were as cool as you.$N$\n");
       afar("You wish you were as cool as #TN# from afar.$N$\n", "#MN# wishes #MS# were as cool as you from afar.$N$\n");
    }
}

int
cmd_wish(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
