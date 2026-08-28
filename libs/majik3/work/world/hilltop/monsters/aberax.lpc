inherit MONSTER;

aberax (string x)
{
  call_out ("aberax_say", random(strlen(x) / 5), x);
}

aberax_say (string x)
{
  "/command/mortal/say"->main(x);
}

create_monster ()
{
  set_name (({"aberax", "astrologer", "thari" }));
  set_short ("Aberax, the mad astrologer");
  set_long ("Aberax is a rather old man. He has a reputation of a mad"+
    " but when you look into his eyes you see a very wise and old man.\n");
  set_race ("thari");
  set_gender (1);
  set_levels (([ "fighter" : 1 + random(3), "caster" : 20 + random(10) ]));

  set_talk (({"the end of world is coming!",
              "we all will die soon!",
              "I know it, someday all three moons will explode!",
              "I am messenger of the gods, I need to warn mortals!",
              "death, it will come soon",
              "darkness will fall on the majik",
              "we can't prevent it!",
              "It is impossible",
              "soon it will happen!",
              "I AM NOT MAD!!!",
              "Why you stare at me!",
              "Go away before I get angry!",
              "In fact I am angry already..",
              "I am angry for the gods!",
              "Gods hate us, they will destroy our world someday",
              "DON'T YOU TRUST ME?",
              "You will see it soon..",
              "NAMHAS SAID IT TO ME!",
              "Uhm...",
              "Urghhrh..",
              "ME NO MAD!",
              "HOW MANY TIMES I NEED TO SAY YOU THAT?",
              "This waiting is boring but someday it will happen!",
             }));

     add_money (random(10));
}

init_monster ()
{
  add_action ("do_say", "say");
}

string
you_me (string w)
{
  string *s;
  w = lower_case (w);
  
  s = explode(w, " ");

  for (int i=0;i<sizeof(s);i++)
    {
      if (s[i] == "i")
        s[i] = "you";
      else if (s[i] == "me")
        s[i] = "you";
      else if (s[i] == "you")
        s[i] = "me";
      else if (s[i] == "my")
        s[i] = "your";
      else if (s[i] == "your")
        s[i] = "my";
      else if (s[i] == "yours")
        s[i] = "mine";
      else if (s[i] == "mine")
        s[i] = "yours";
      else if (s[i] == "am")
        s[i] = "are";
      else if (s[i] == "aberax")
        s[i] = "me are";
    }

  w = implode(s, " ");

  return w;
}

string
wword ()
{
  return ({ "when", "why", "where", "how" })[random(3)];
}    

do_say (string str)
{
  string *verbp = ({ "go", "have", "be", "try", "eat", "take",
    "help", "make", "get", "jump", "write", "type", "fill",
    "put", "turn", "compute", "think", "drink", "blink",
    "crash", "crunch", "add" });

  string *wpred = ({ "why", "where", "when", "what", "which", "how" }); 

  string *punts = ({ "please go on",
                     "tell me more",
                     "i see",
                     "what does that indicate",
                     "but why be concerned about it",
                     "just tell me how you feel" });

  string *dpred = ({ "do", "can", "should", "would" });

  string *s;
  int i;

  str = you_me (str);

  if (strsrch(str, "bye") > -1)
    aberax ("goodbye!");
  else if (strsrch(str, "hello") > -1)
    aberax ("hi!");
  else if (strsrch(str, "you are") > -1)
    {
      i = strsrch(str, "you are");
      aberax ("please tell me "+wword()+" you are "+str[i+8..]);
    }
  else if (strsrch(str, "you have") > -1)
    {
      i = strsrch(str, "you have");
      aberax ("how long have you had "+str[i+9..]);
    }
  else if (strsrch(str, "you feel") > -1)
    aberax ("i sometimes feel the same way");
  else if (strsrch(str, "because") > -1)
    aberax ("is that really the reason?");
  else if (strsrch(str, "yes") > -1)
    {
      i = strsrch(str, "yes");
      aberax ("how can you be so sure "+str[i+4..]);
    }
  else if (strsrch(str, "me are") > -1)
    {
      i = strsrch(str, "me are");
      aberax ("oh yeah i am "+str[i+7..]);
    }
  else if (strsrch(str, "do me think") > -1)
    aberax ("i think you should answer that yourself");
  else if (strsrch(str, "dream") > -1)
    aberax ("for dream analysis see freud");
  else if (strsrch(str, "love") > -1)
    aberax ("all is fair in love and war");
  else if (strsrch(str, "no") > -1)
    aberax ("dont be so negative");
  else if (strsrch(str, "maybe") > -1)
    aberax ("be more decisive!");
  else if (strsrch(str, "you") > -1)
    aberax (punts[random(6)]);
  else
    {
      s = explode(str, " ");
      for (i=0;i<sizeof(s);i++)
        {
          if (member_array(s[i], verbp) > -1)
            {
              aberax ("why do you want me to "+s[i]+" "+implode(s[i+1..], " "));
              break;
            }
          else if (member_array(s[i], wpred) > -1)
            {
              aberax ("you tell me "+s[i]);
              break;
            }
          else if (member_array(s[i], dpred) > -1)
            {
              aberax ("perhaps i "+s[i]+" "+implode(s[i+1..], " "));
              break;
            }
       }
    }

  return 0;
}
