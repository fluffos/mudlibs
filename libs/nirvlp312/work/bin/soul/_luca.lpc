inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You gravely say: \"It's a Sicilian message.  Luca Brasi sleeps with the fishes.\"\n", "#MN# gravely says: \"It's a Sicilian message.  Luca Brasi sleeps with the fishes.\"\n");
       target("You look at #TN# and say: \"It's a Sicilian message.  Luca Brasi sleeps with the fishes.\"\n", "#MN# looks at #TN# and says: \"It's a Sicilian message.  Luca Brasi sleeps with the fishes.\"\n", "#MN# looks at you and says: \"It's a Sicilian message.  Luca Brasi sleeps with the fishes.\"\n");
       afar("From afar, you tell #TN#: \"It's a Sicilian message.  Luca Brasi sleeps with the fishes.\"\n", "From afar, #MN# tells you: \"It's a Sicilian message.  Luca Brasi sleeps with the fishes.\"\n");
    }
}

int
cmd_luca(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
