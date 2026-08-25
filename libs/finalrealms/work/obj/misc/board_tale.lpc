/* Hamlet July 1995.  This is a heavily hacked collection of scrolls.  
   It's going to look like an NPC and 'tell stories' rather than
   have posts.
 
   Cadogan and Keldaz helped extensively with the text.
 
   BE WARNED:  There are red herrings in here.  Live with it.
*/
 
string MYNAME = "Taleswapper";
string MYLONG = "As you look at this vibrant old man he catches your eye.  "+
                "Suddenly you sense the wisdom of ages hidden behind those "+
                "eyes.  In awe you are drawn to him, hoping to learn but a "+
                "little of what he knows.\n";

#include "mail.h"
inherit "/obj/monster";
 
#include "board.h"
/* Taniwha 1995, a list of immort write only boards, easy to extend */
nosave string *readonly = ({"playerinfo","quests","announcements"});
 
string board_name;
 
mapping being_written;
int action_pri;
 
void setup() {
  board_name = "quests";
  being_written = ([ ]);
  action_pri = 0;
} /* setup() */

string the_date(int i) {
  return ctime(i)[4..9];
} /* the_date() */
 
varargs void set_teller_name(string name, string desc, int gender) {
  MYNAME = capitalize(name);
  set_name(name);
  set_short(name);
  if(desc)
    set_long(desc);
  else
    set_long(MYLONG);
  if(gender)
    set_gender(gender);
  else
    set_gender(1);
  return 1;
} 
 
varargs int subjects(string str, int dark, object player) {
  int i;
  mixed *stuff;
  string ret;
  mapping news_rc;
 
  if(!player)  player = this_player();
 
  if(!interactive(player))  return 1;
 
  if(query_timed_property((string)player->query_name())) {
    tell_object(player,MYNAME+" tells you: Let me rest a moment, child.  "+
                "I tire easily.\n");
    return 1;
  }
    
  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (!sizeof(stuff)) {
    tell_object(player,MYNAME+" sobs.\n\n"+MYNAME+" tells you: Nobody has "+
                "taught me any tales yet!\n");
    return 1;
   }
  news_rc = (mapping)player->query_property(NEWS_RC);
  if (!news_rc)
    news_rc = ([ ]);
  ret = MYNAME+" tells you: I will happily tell you any tale I know: \n";
  for (i=0;i<sizeof(stuff);i++)
    if (news_rc[board_name] < stuff[i][B_TIME])
      ret += sprintf("N %2d: %-=*s\n", i+1, (int)player->query_cols()-6,
             stuff[i][B_SUBJECT]+" (told to me by: "+
             capitalize(stuff[i][B_NAME])+" on "+
                        the_date(stuff[i][B_TIME])+")");
    else
      ret += sprintf("  %2d: %-=*s\n", i+1, (int)player->query_cols()-6,
             stuff[i][B_SUBJECT]+" (told to me by: "+
             capitalize(stuff[i][B_NAME])+" on "+
                        the_date(stuff[i][B_TIME])+")");
 
  add_timed_property(player->query_name(),1,2);
  player->set_finish_func(0);
  player->more_string(ret, "tales");
  return 1;
} /* subjects() */
 
void init() {
  add_action("read", "hear", action_pri);
  add_action("read", "listen", action_pri);
  add_action("subjects", "list", action_pri);
  add_action("subjects", "subjects", action_pri);
  ::init();
 } /* init() */
 
void string_more(string arg, string prompt, object player) {
  object obj;
  player->set_finish_func(0);
  player->more_string(arg, prompt);
} /* string_more() */

varargs int read(string str, object player) {
  int num, i;
  mixed stuff;
  mapping news_rc;
  int herring;
  string subjunk;
 
  if(!player)  player = this_player();
 
  if(!interactive(player))  return 1;
 
  if(query_timed_property((string)player->query_name())) {
    tell_object(player,MYNAME+" tells you: Let me rest a moment, child.  "+
                "I tire easily.\n");
    return 1;
  }
   
  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  news_rc = (mapping)player->query_property(NEWS_RC);
  if (!news_rc)
    news_rc = ([ ]);
  if ((!str) || (str == "tale") || (str == "a tale") || (str == "next tale") ||
      (str == "to a tale") || (str == "to next tale")) {
    i = sizeof(stuff)-1;
    while (i >= 0 && stuff[i][B_TIME] > news_rc[board_name] )
      i--;
    if (i == sizeof(stuff)-1) {
      tell_object(player,MYNAME+" tells you: You have heard all the "+
                  "tales I know!\n");
      return 1;
    }
 
  num = i+2;
  } else if (sscanf(str, "tale %d", num) != 1)
      if(sscanf(str,"to tale %d", num) != 1) {
        tell_object(player,MYNAME+" tells you: Do you want to 'hear tale "+
                    "<number>'?\n");
        return 1;
      }
  if (num < 1 || num > sizeof(stuff)) {
    tell_object(player,MYNAME+" tells you: I do not know a tale of that "+
                "number.\n");
    return 1;
  }
  num --;
  if (news_rc[board_name] < stuff[num][B_TIME]) {
    news_rc[board_name] = stuff[num][B_TIME];
    player->add_property(NEWS_RC, news_rc);
  }
 
  add_timed_property(player->query_name(),1,2);
  
  herring = (int)player->query_cols() - strlen(MYNAME) - 23;
  subjunk = stuff[num][B_SUBJECT][0..herring];
  if(herring < strlen(stuff[num][B_SUBJECT]))
    subjunk += "-\n"+sprintf("%*s%s",(strlen(MYNAME)+12)," ",
                stuff[num][B_SUBJECT][(herring+1)..100]);
                      
  tell_object(player,"\n");
  string_more(sprintf("\n"+MYNAME+" tells you: Ah, so you want to hear "+
              "tale %d.  "+
              "It was told to me by\n%*s%s on %s.  I like to\n%*scall it "+
              "'%s'.\n\n",num+1,(strlen(MYNAME)+12)," ",
              capitalize(stuff[num][B_NAME]), ctime(stuff[num][B_TIME]),
              (strlen(MYNAME)+12)," ",subjunk)+
              BOARD_HAND->get_message(board_name, num),
                 "[Tale "+(num+1)+"]",player);
  return 1;
} /* read() */
 
void event_person_say(object ob, string start, string mess, string lang) {
  string junk, junk2;
  string *said;
  int numb = 0;
  int i;
  
  if(sscanf(mess,"tell %s",junk) != 1)
    if(sscanf(mess,"Tell %s",junk) != 1)
      if(sscanf(mess,"%s tell%s",junk,junk2) != 2)
        if(sscanf(mess,"%s hear%s",junk,junk2) != 2)
          if(sscanf(mess,"%s listen%s",junk,junk2) != 2)
            if(sscanf(mess,"%s know%s",junk,junk2) != 2)
              return 1;
          
  if(sscanf(mess,"%s tale",junk) != 1)
    if(sscanf(mess,"%s stor%s",junk, junk2) != 2)
      return 1;
  
  /* Deal with request for subject list */
  if(sscanf(mess,"%s know%s",junk,junk2) == 2) {
    call_out("subjects",0,"red herring",0,ob);
    return 1;
  }
  
  /* Obviously they wanted a story. */
  mess += " ";    
  said = explode(mess," ");

  for(i=0;(i<sizeof(said) && !numb);i++)
    sscanf(said[i],"%d",numb);
    
  if(numb)
    call_out("read",0,sprintf("tale %d",numb),ob);
  else
    call_out("read",0,"a tale",ob);
    
  return 1;
}

void too_far_away(object ob) {
  tell_object(ob,MYNAME+" tells you: come closer, my child.\n");
  return 1;
}
 
void event_person_tell(object ob, string start, string mess, string lang) {
  if(environment(ob) != environment(this_object())) {
    call_out("too_far_away",0,ob);
    return 1;
  }
  
  event_person_say(ob,start,mess,lang);
  return 1;
}
 
void set_board_name(string str) {
  board_name = str;
   BOARD_HAND->create_board(board_name, 0);
 }
 
void set_datafile(string str) {
  set_board_name(str);
  /*board_name = str;*/
}
 
int query_new_messages() {
  mixed *notes;
  mapping news_rc;
 
  news_rc = (mapping)this_player()->query_property(NEWS_RC);
  if (!news_rc)
    news_rc = ([ ]);
  notes = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (!sizeof(notes)) return 0;
  return (notes[sizeof(notes)-1][B_TIME] > news_rc[board_name]);
} /* query_new_messages() */
 
void adjust_hp(int amt, object who) {
  if(who != this_object()) {
    tell_object(who,"Something about "+MYNAME+" convinces "+
                "you to stop fighting "+query_objective()+".\n");
    who->stop_fight(this_object());
    stop_fight(who);
  }
  return 1;
}

void do_death(object who) {
  return 1;
}

void thepoem(object guest);
string lastpart(int num);
 
void event_enter(object guest, string mess, object from) {
  if(!interactive(guest))
    return 0;
 
  call_out("thepoem",0,guest);
 
  return 1;
}
 
void thepoem(object guest) {
  int num = sizeof((mixed *)BOARD_HAND->get_subjects(board_name));
 
  tell_object(guest,"\n"+MYNAME+" whispers:\n"+
              "  Oh, listen my child and hear me well,\n"+
              "  for I have many brave stories to tell.\n\n"+
              "  The tales I tell bring fortune and fame;\n"+
              "  Listen well and receive the same.\n\n"+
              "  So sit back -- relax, order a drink,\n"+
              "  And give up your cares whilst I speak.\n\n"+
              lastpart(num));
  return 1;
}
 
string lastpart(int num) {
  string wordnum = query_num(num);
 
  if(num == 0)
    return "  Alas, alack!  No tales know I!\n"+
           "  Turn thy head my child, or see me cry.\n";
 
  if( (num>9) && (num<20) )
    switch(num) {
      case 10:  return "  The tales I know number ten,\n"+
                       "  Seek ye journeys and treasures to win?\n";
 
      case 11:  return "  The tales I know, eleven in all;\n"+
                       "  Adventure to those who'd answer the call.\n";
 
      case 12:  return "  Twelve tales of ancient lore I know,\n"+
                       "  The glorious myths of long ago.\n";
 
      case 13:  return "  Thirteen tales to tell have I,\n"+
                       "  When balefire fell with fury from the sky...\n";
 
      case 14:  return "  Fourteen tales to share with you,\n"+
                       "  All destined to bring a day you will rue.\n";
 
      case 15:  return "  Fifteen tales come I to know,\n"+
                       "  Of nefarious deeds from evils below.\n";
 
      case 16:  return "  The tales I know, sixteen all said,\n"+
                       "  All spine chilling yarns to fill you with dread.\n";
 
      case 17:  return "  The tales I know, seventeen when done,\n"+
                       "  Adventure awaits you once the journey's begun.\n";
 
      case 18:  return "  Eighteen tales entrusted to me.\n"+
                       "  With but a word, I'll share them with thee.\n";
 
      case 19:  return "  The tales I know number nineteen;\n"+
                       "  Of mysteries so wonderous, none yet seen.\n";
    }
  else
    switch((num%10)) {
      case 0:  return sprintf("  %s tales I have to share,\n"+
                      "  Adventure awaits thee if ye would dare.\n",
                      capitalize(wordnum));
 
      case 1:  return sprintf("  The tales I know number %s,\n"+
                      "  Of earth and wind and sea and sun.\n",
                      wordnum);
 
      case 2:  return sprintf("  The tales I know number %s,\n"+
                      "  Consider well what I now tell you.\n",
                      wordnum);
 
      case 3:  return sprintf("  The tales I know number %s,\n"+
                      "  Oh my child, will you harken to me?\n",
                      wordnum);
 
      case 4:  return sprintf("  The tales I know number %s,\n"+
                      "  Oh my child, will you listen once more?\n",
                      wordnum);
 
      case 5:  return sprintf("  The tales I know number %s,\n"+
                      "  Oh listen well to stay alive.\n",
                      wordnum);
 
      case 6:  return sprintf("  The tales I know, %s, all told,\n"+
                      "  Tales of horrors and hoarded gold.\n",
                      wordnum);
 
      case 7:  return sprintf("  The tales I know, %s in all;\n"+
                      "  Adventure to those who'd answer the call.\n",
                      wordnum);
 
      case 8:  return sprintf("  The tales I know number %s,\n"+
                      "  Listen to me and seal your fate.\n",
                      wordnum);
 
      case 9:  return sprintf("  The tales I know number %s,\n"+
                      "  Follow my lead and see what you find.\n",
                      wordnum);
    }
}
