inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "¡˙Ã∂");
        set("long",
"[1;31m’‚¿ÔæÕ «¡˙Ã∂£¨“ª÷ªæﬁ¡˙≈Ãæ·‘⁄’‚¿Ô£¨ø¥º˚”–»ÀΩ¯¿¥£¨∑¢≥ˆ\n"
"“ª…˘’ÃÏæﬁ∫£¨»ª∫Û±„∑¢∆¡Àπ•ª˜°£Ã˝ÀµÀ¸ ÿª§◊≈æ´¡ÈÕı¡Ùœ¬¿¥µƒ±¶≤ÿ°£\n"
"”–ø’µƒª∞£¨À—À˜(search)“ªœ¬ªÚ–Ìª·”– ’ªÒ°£\n"
);
        set("exits", ([ 
              // "south" : __DIR__"spirit6", 
           ]));
        set("objects", ([ 
             "/quest/tulong/npc/dragon" : 1,
          ]));
        set("book_count", 7);

        set("no_magic", 1);
	setup();
} 

void init()
{
  add_action ("do_search","search"); 
  add_action ("do_quit","train");}

int do_quit(string arg){
        write(this_player()->query("name")+"£¨¡˙“≤ «ø…“‘—±µƒ√¥£ø£°\n");
        return 1;
} 
int do_search (string arg)
{
  object who = this_player ();
  object where = this_object ();
  object book;

 if (query("book_count") < 1) 
  {
    message_vision ("$NÀƒ¥¶À—À˜¡À“ª∑¨£¨ ≤√¥“≤√ª”–’“µΩ°£\n",who);  
    message_vision ("“≤–Ì «±ªƒ√π‚¡À°£\n",who);  
    return 1;
  }
        if (  present("night's diary", who) ) {
                return notify_fail("ƒ„∂º”–’‚±æ È¡À£¨ªπ“™’“ ≤√¥°£\n");
          }
 if (who->query_temp("mark/diary")) 
   {
    message_vision ("$NÀƒ¥¶À—À˜¡À“ª∑¨£¨ ≤√¥“≤√ª”–’“µΩ°£\n",who);  
    message_vision ("ø¥—˘◊” «≤ªƒ‹∂‡ƒ√µƒ°£\n",who);  
    return 1;
  }

  if (random(10))
  {
    message_vision ("$NÀƒ¥¶À—À˜¡À“ª∑¨£¨ ≤√¥“≤√ª”–’“µΩ°£\n",who);  
  }
  else
  {
    book = new ("/quest/tulong/obj/diary");
    message_vision ("$Næπ¥”ø› ˜“∂º‰’“≥ˆ“ª±æ"+YEL"“π≥Ω»’º«"NOR+"£°\n",who,book);
     who->set_temp("mark/diary", 1);
    book->move(who);  
message("channel:rumor", HIR"°ææ´¡È…ÒΩÁ°øƒ≥»À£∫"+this_player()->query("name")+"’“µΩ“π≥Ω»’º«¿≤°£\n"NOR, users());
   add("book_count", -1);
  }
  return 1;
}

void reset()
{
        ::reset();
        delete("exits/north");
}
