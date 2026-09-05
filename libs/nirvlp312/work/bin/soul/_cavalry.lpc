inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You hold a large stone over your head.#RET#You say: \"Cavalry's here; cavalry's a frightened guy with a rock, but it's here.\"$N$\n", "#CMN# holds a large stone over #MP# head.#RET##CMN# says: \"Cavalry's here; cavalry's a frightened guy with a rock, but it's here.\"$N$\n");
       target("You hold a large stone over your head, showing #CTN#.#RET#You say: \"Cavalry's here; cavalry's a frightened guy with a rock, but it's here.\"$N$\n", "#CMN# holds a large stone over #MP# head showing #CTN#.#RET##CMN# says: \"Cavalry's here; cavalry's a frightened guy with a rock, but it's here.\"$N$\n", "#CMN# holds a large stone over #MP# head showing you.#RET##CMN# says: \"Cavalry's here; cavalry's a frightened guy with a rock, but it's here.\"$N$\n");
       afar("$HW$[afar]$N$ You hold a large stone over your head, showing #CTN#.#RET#$HW$[afar]$N$ You say: \"Cavalry's here; cavalry's a frightened guy with a rock, but it's here.\"$N$\n", "$HW$[afar]$N$ #CMN# holds a large stone over #MP# head showing you.#RET#$HW$[afar]$N$ #CMN# says: \"Cavalry's here; cavalry's a frightened guy with a rock, but it's here.\"$N$\n");
    }
}

int
cmd_cavalry(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
