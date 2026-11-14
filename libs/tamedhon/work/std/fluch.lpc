inherit "std/thing" ;

#include <properties.h>
#include <language.h>

#define TP           this_player()
#define NAME         TP -> QueryProp(P_NAME)
#define SP           (TP -> QueryProp(P_SP))
#define HEAL(am)     TP -> SetProp(P_SP, SP + (am))
#define IS_VISIBLE(ob) (ob -> short())

string text;
int i;

void create()
{
  ::create() ;
  SetProp(P_WEIGHT, 0) ;
  SetProp(P_NEVERDROP, 1);
  SetProp(P_NODROP, 1) ;
  SetProp(P_NOBUY, 1) ;
  SetProp(P_VALUE, 1) ;
  
  SetProp(P_SHORT, 0) ;
  SetProp(P_NAME, "fluch") ;
  SetProp(P_GENDER, 1) ;
  SetProp("creator",this_interactive());
  write_file("/log/fluch.log",dtime(time())+": "+
    this_object()->QueryProp("creator")+
    " hat einen Fluch erzeugt.\n");

  AddId("\nfluch") ;
}

void init()
{

  ::init();
  if (QueryProp("creator")!=lower_case(this_player()->QueryProp(P_NAME)))
  {
  text=dtime(time())+": "+
    this_object()->QueryProp("creator")+
    " hat "+this_player()->QueryProp(P_NAME)+" verflucht.";

//  i=call_other("/p/service/querolin/listen/logger", "log", 
//               "/log/fluch.log", text);
  // tell_object(find_player("querolin"),break_string("i:"+i, 20));
  }

  if (last_reboot_time() > 810566501)
    this_player()->SetProp(P_PERM_STRING,this_object());
  else {
  
/*  add_action("do_ask", "frage") ;
  add_action("do_ask", "frag") ;*/

  add_action("do_say", "sag") ;
  add_action("do_say", "sage") ;
  add_action("do_say","'",1) ;
  add_action("do_tell", "teile") ;
  add_action("do_shout", "rufe") ;
  }
}

string permutate_string(string str)
{
  return str ;
}

int do_say(string str)
{
  object pl, *list ;
  string bla ;

  int i ;
  if(!(str==TP->_unparsed_args()))
    return 0 ;

  if(!present(this_object(), TP))
    return 0 ;

  list = all_inventory(environment(TP)) ;
  bla = permutate_string(str) ;
  for(i = 0; i < sizeof(list); i++)
  {
    pl = list[ i ] ;
    if(living(pl))
      if(pl != TP)
	tell_object(pl, TP -> name(WER) + " sagt: " + bla + "\n") ;
      else
	write("Du sagst: " + str + "\n") ;
  }

  return 1 ;
}

#define SHOUT_SP 30

int do_shout(string str)
{
  object pl, *list ;
  int i,chars ;
  string bla ;

  if(!(str=TP->_unparsed_args()))
    return 0 ;

  if(!present(this_object(), TP))
    return 0 ;
 
  chars=sizeof(str);
  if(SP < chars)
  {
    write("Du hast nicht mehr genug Magiepunkte.\n") ;
    return 1 ;
  }
  HEAL(-chars) ;
  SetProp(P_SP,QueryProp(P_SP)-chars) ;
  
  write("Du rufst: " + str + "\n") ;
  list = users() ;
  bla = permutate_string(str) ;
  for(i = 0; i < sizeof(list); i++)
  {
    pl = list[ i ] ;
    if(pl != TP)
      tell_object(pl, TP -> name(WER) + " ruft: " + bla + "\n") ;
  }
  return 1 ;
}

int do_tell(string str)
{
  string who, message ;
  object pl ;

  if(!(str=TP->_unparsed_args()))
    return 0 ;

  if(!present(this_object(), TP))
    return 0 ;

  if(sscanf(str, "%s mit %s", who, message) < 2)
    return 0 ;

  if((pl = find_player(who)) && IS_VISIBLE(pl))
  {
    tell_object(pl, TP -> name(WER) + " teilt Dir mit: " + 
		 permutate_string(message) + "\n") ;
    write("Du teilst " + capitalize(who) + " mit: " + message + "\n") ;
  }
  else
    write("Kein solcher Spieler eingeloggt.\n") ;
  return 1 ;
}

// short()
// {
// }

int QueryFluch()
{
  return 1 ;
}

