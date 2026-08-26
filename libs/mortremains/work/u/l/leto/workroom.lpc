/*
 *      Leto's workroom.
 *      (first thing he ever coded on a mud, so kind of historical)
 *      (And it euh, got sort of updated a few times, so sort of
 *      not so historical anymore ;)
 */

#include <mudlib.h>
#include <config.h>
#include <uid.h>

inherit ROOM ;

#define FRIENDS ({"kat","katheryn","leto"})
private int shield;
private string *allowed;

void create() {
        :: create() ;
        seteuid(getuid());

    allowed = FRIENDS ;
    set ("short", "Leto's workroom");
    set ("long", wrap(
		
"Upon entering you immediatly see that this is the room where "
"Leto spends most of his time. There is a table of dark brown wood "
"streaked by fine golden graining, about two meters by one meter and "
"set low on stubby legs in the midst of grey cushions.\n"
"Considering the power of its occupant, the room is small. No more than "
"five metres by four, but with a high ceiling. Light comes from the "
"two slender glazed windows opposite each other on the narrower walls."
"\nThe windows look out from a considerable height, one on to the " 
"northwest fringes of the Sareer and the bordering green of the "
"Forbidden Forrest, the other providing a southwest view over rolling "
"dunes.\n"
));
  //set ("smell", "There is a strong smell of cinnamon here.\n");
  //set ("sound", "There is absolute silence here, Leto ordered that.\n");

    set ("exits", ([ 
                   "away" : "/d/TMI/rooms/quad",
		"new" : "/u/l/leto/new"
                   ]) ) ;
    set ("light", 1);
    set ("item_desc", ([
                         "table" : wrap( 
"The table has an interesting accent on this initial thought. The "
"surface appears as an arrangement demonstrating the idea of clutter. "
"Thin sheets of crystal paper lay scattered across the surface, "
"leaving only glimpses of the wood grain underneath. Fine printing "
"covers some of the paper. One letter draws your attention "
"particularly.\n"),


                       "letter" :
"It contains the following poem.\n\n"
"      Friendship\n\n"
"I send my heart's hoard,\n"
"Across many miles to you.\n"
"Peace, this I find\n"
"Little things you do.\n\n"
"Simple smiles, a hug -\n"
"Special things we share.\n"
"I feel so tranquil,\n"
"When you are with me there.\n\n"

                     ]));
shield = 1;
}
void init()
{
if(getuid(previous_object()) == "leto")  
    {
      add_action("lock","lock");
      add_action("unlock","unlock");
      add_action("eject","eject");
    }
 if(member_array(getuid(previous_object()),allowed)!=-1) return;

else {
     if(shield)
        {
     if( !(member_array(getuid(this_player()), allowed)!=-1) )

                 {
                  write(wrap("Sorry, Leto does not want to be disturbed right "
                             "now. He os probably teaching or having a private"
                             " conversation. Either try and ask him or try "
                             "again later...Thanks.\n"));
           tell_object(find_player("leto"),(this_player()->query("name")+
        " tried to barge in here.\n"));
           this_player()->move(this_player()->query("last_location"));

                 return;
     }
  }
}
}

int
lock()
{
  if(getuid(this_player()) != "leto")
    return 0;
        shield =1;
  write("Room is now locked.\n");
  return 1;
}

int
unlock()
{
  if(getuid(this_player()) != "leto")
    return 0;
  shield=0;
  write("Room is now unlocked.\n");
  return 1;
}

int
eject(string arg)
{
  object ob;
  object last;
  string name;

  if(!arg || arg=="")
    return 0;

  if(getuid(this_player()) != "leto")
    return 0;

  if(!(ob=present(arg,this_object())))
    {
      notify_fail(arg+" is not here\n");
      return 0;
    }

  if(!(last=(object)ob->query("last_location")))
  last=load_object(VOID);
  name=(string)ob->query("cap_name");

  ob->move_player(last,name + " is ejected from the room","");
  return 1;
}
