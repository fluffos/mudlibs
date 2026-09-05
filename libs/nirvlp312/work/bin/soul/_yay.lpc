inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You yell \"YAY, YAY, YAYYYY!!\" just like Special Ed.$N$\n", "$MN$ yells \"YAY, YAY, YAYYY!!\" just like Special Ed.$N$\n");
       target("You yell \"YAY, YAY, YAYYYY!!\" at $TN$.$N$\n", "$MN$ yells \"YAY, YAY, YAYYYY!!\" at $TN$.$N$\n", "$MN$ yells \"YAY, YAY, YAYYYY!!\" at you.$RET$You feel your IQ drop a point or two.$N$\n");
       afar("From afar, you yell \"YAY, YAY, YAYYYY!!\" at $TN$.$N$\n", "From afar, $MN$ yells \"YAY, YAY, YAYYYY!!\" at you.$RET$You feel your IQ drop a point or two.$N$\n");
    }
}

int
cmd_yay(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
