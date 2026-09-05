
id(str)
{
   return str == "talker"; 
}

short()
{
   return "A talker"; 
}

reset(arg)
{
    if(arg) return 0;
    remove_call_out("fake_beat");
    call_out("fake_beat", 1);
}

fake_beat()
{
    say("A talker says: Talk.\n");
    remove_call_out("fake_beat");
    call_out("fake_beat", 1);
}
