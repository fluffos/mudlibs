// This file was replaced with another _to.c command.
#define USAGE return (int) notify_fail("Usage: to [player] [message].\n");
#define TPN this_player()->query("cap_name")
#define TN ob->query("cap_name")

int cmd_to(string str){
   string pl, ms;
   object ob;
   if(!str) USAGE
   sscanf(str, "%s %s", pl, ms);
   if(!ms) USAGE
   ob = present(pl, environment(this_player()));
   if(!ob) return (int) notify_fail("That player isn't here.\n");
   if(ob == this_player())
      return (int)
       notify_fail
          ("Talking to yourself isn't very good for the sanity, you know.\n");
   
  say(sprintf("%s says [to %s]: %s\n", TPN, TN, ms),
        ({ this_player(), ob }));
   printf("You say [to %s]: %s\n", TN, ms);
   tell_object(ob, sprintf("%s says [to you]: %s\n", TPN, ms));
   return 1;
   }
