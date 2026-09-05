inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look for someone to nudge.$N$\n", "#CMN# looks for someone to nudge.$N$\n");
       target("You nudge #CTN# in the ribs.$N$\n", "#CMN# nudges #CTN# in the ribs.$N$\n", "#CMN# nudges you in the ribs.$N$\n");
       afar("You nudge #CTN# in the ribs from afar.#RET#How'd you reach that far??$N$\n", "#CMN# nudges you in the ribs from afar. #RET#Impressive reach, eh?$N$\n");
    }
}

int
cmd_nudge(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
