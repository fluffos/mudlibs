inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"I'll be honest fellas, it was sounding great.#RET#But....I could've used a little more cowbell.\"$N$\n", "#MN# says, \"I'll be honest fellas, it was sounding great.#RET#But....I could've used a little more cowbell.\"$N$\n");
       target("You say, \"I'll be honest #TN#, it was sounding great.#RET#But....I could've used a little more cowbell.\"$N$\n", "#MN# says, \"I'll be honest #TN#, it was sounding great.#RET#But....I could've used a little more cowbell.\"$N$\n", "#MN# tells you, \"I'll be honest, it was sounding great.#RET#But....I could've used a little more cowbell.\"$N$\n");
       afar("[afar] You yell, \"I'll be honest #TN#, it was sounding great.#RET#But....I could've used a little more cowbell.\"$N$\n", "[afar] #MN# yells, \"I'll be honest, it was sounding great.#RET#But....I could've used a little more cowbell.\"$N$\n");
    }
}

int
cmd_cowbell(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
