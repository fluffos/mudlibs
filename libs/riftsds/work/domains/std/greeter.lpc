/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_CONVERSATION;

void setup()
{
   set_name("Greeter");
   set_gender(1);
   set_proper_name("Greeter");
   set_in_room_desc("The LIMA mudlib greeter stands here, smiling politely.");
   set_long("The greeter stands here patiently, ready to talk to people with questions about the LIMA mudlib. Use "
            "<talk to greeter> to start a conversation.");

   set_options((["hello":"Hello!",
               "greeter":"What do you do?", "where":"Where do I get LIMA?",
              "problems":"I'm having problems setting up LIMA.",

           "compilation":"Where should I report FluffOS compilation problems?",
              "intermud":"How do I get on intermud (I3)?", "str_check":"I'm pretty strong, want a lift?[str>30]",
             "cha_check":"Can I ask you a personal question?[cha>20]",
             "int_check":"I sense an alterior motive?[int>20]",
           "skill_check":"Can you check my skills in chats?[combat/defense>1]",
          "skill_check2":"Can you check my skills in chats?[combat/defense=0]"]));

   set_responses((["hello":"Hello, and welcome to the LIMA mudlib!  I'm designed to answer some basic questions you "
                           "might have about it.",
                 "greeter":"I help people with basic questions and problems with the LIMA mudlib.  I also demonstrate "
                           "LIMA's M_CONVERSATION " +
                               "module, which makes building NPCs who can hold intelligent conversations a snap!  Feel "
                               "free to read my code, its in " +
                               __FILE__ + ". It includes dynamic chats that check stats and more.",
                   "where":"You can find the best current sources for the LIMA mudlib in GitHub on "
                           "https://github.com/fluffos/lima.git (stable) " +
                               "or https://github.com/tsathoqqua/lima.git (development) or see a demo on the Lima "
                               "MUD itself (limalib.dev 7878).",
                "problems":({"!ponder", "See https://www.fluffos.info/build.html, or get your MUD on the intermud "
                                        "network.@@intermud,compilation"}),

             "compilation":
                 "Problems compiling FluffOS should be reported on Github, https://github.com/fluffos/fluffos/issues",
                "intermud":
                    "First, edit config.h and make sure ADMIN_EMAIL is set correctly.  If it isn't, you will not be "
                    "permitted to connect.  " +
                        "Then do 'update /daemons/imud_d'.  You should be on the net.  You can check with 'mudinfo "
                        "<your "
                        "mud name>' from here.  Use 'igossip /on' and 'icode /on' to turn on the standard channels.",
               "str_check":"No, I would like to stay right here.@@int_check",
             "skill_check":"This was only available if you have the right skill rank.",
               "cha_check":"Sure, but I cannot answer.",
               "int_check":"Read my source to see how to check stats for chats.",
             "skill_check":"Your combat/defense rank is at least rank 1.",
            "skill_check2":"I can see you have combat/defense rank at 0."]));

   set_start(({"hello", "greeter", "where", "problems", "str_check", "cha_check", "skill_check", "skill_check2"}));
   set_goodbye("!wave $t");
}
