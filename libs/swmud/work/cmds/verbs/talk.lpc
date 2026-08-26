// Last edited by deforce on 06-26-2008
inherit VERB_OB;

void do_talk()
{
   write("Who do you want to talk to?\n");
}

void perform_talk(object liv)
{
   if (!this_body()->query_target())
   {
      liv->begin_conversation();
   }
   else
   {
      write("You are too busy fighting to talk to " + liv->short() + ".\n");
   }
}

void do_talk_liv(object liv)
{
   perform_talk(liv);
}

void do_talk_to_liv(object liv)
{
   perform_talk(liv);
}

void do_talk_with_liv(object liv)
{
   perform_talk(liv);
}

void create()
{
   add_rules ( ({ "", "LIV", "with LIV", "to LIV" }) );
}