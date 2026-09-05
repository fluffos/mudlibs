inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Who would you like to sheepage?$N$\n", "#MN# looks funny.$N$\n");
       target("You trip #TN# and toss a fluffy white wool blanket over #TO#.#RET#You turn and yell, \"Earwax check it out.....a freebie!!!!!\"#RET#You watch in horror as Earwax's eyes light up and he straps on his velcro gloves.$N$\n", "#MN# trips #TN# and tosses a fluffy white wool blanket over #TO#.#RET#MN# turns and yells, \"Earwax check it out.....a freebie!!!!!\"#RET#You watch in horror as Earwax's eyes light up and he straps on his velcro gloves.$N$\n", "#MN# trips you and tosses a fluffy white wool blanket over you.#RET#MN# turns and yells, \"Earwax check it out.....a freebie!!!!!\"#RET#You watch in horror as Earwax's eyes light up and he straps on his velcro gloves.$N$\n");
       afar("You trip #TN# and toss a fluffy white wool blanket over #TO#.#RET#You turn and yell, \"Earwax check it out.....a freebie!!!!!\".#RET#You watch in horror as Earwax's eyes light up and he straps on his velcro gloves.$N$\n", "#MN# trips you and tosses a fluffy white wool blanket over you.#RET#MN# turns and yells, \"Earwax check it out.....a freebie!!!!!\"#RET#You watch in horror as Earwax's eyes light up and he straps on his velcro gloves.$N$\n");
    }
}

int
cmd_sheepage(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
