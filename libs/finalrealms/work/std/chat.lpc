#define MONSTER_HAND "/obj/handlers/monster_hand"
string *story;
int which_story;
int in_talk;
mixed talk_string;
int chat_chance, achat_chance;
mixed *chat_string, *achat_string;
void expand_mon_string(string str);
mixed query_chats() { return chat_string+achat_string+talk_string; }

void create()
{

    talk_string = ({ });
    which_story = 0;
    story = ({ });
}

void load_chat(int chance, string *c_s)
{
    int i;
    if (!chat_string)
      { chat_string = ({ 0, ({ }) }); }
    for (i=0;i<sizeof(c_s);i+=2)
    {
	chat_string[1] += ({ c_s[i], c_s[i+1] });
	chat_string[0] += c_s[i];
    } /* for.. */
    chat_chance = chance;
}

void set_chat_chance(int i) { chat_chance = i; }
int query_chat_chance() { return chat_chance; }
void set_chat_string(string *chat) { chat_string = chat; }
string *query_chat_string() { return chat_string; }

void add_chat_string(mixed weight, mixed chat)
{
    int i;

    if (pointerp(weight))
	for (i=0;i<sizeof(weight);i+=2)
	    add_chat_string(weight[i], weight[i+1]);
    else if (member_array(chat, chat_string[1]) == -1) 
    {
	chat_string[1] += ({ weight, chat });
	chat_string[0] += weight;
    }
}

void remove_chat_string(mixed chat)
{
    int i;

    if (pointerp(chat))
	for (i=0;i<sizeof(chat);i++)
	    remove_chat_string(chat[i]);
    else if ((i = member_array(chat, chat_string[1])) != -1) 
    {
	chat_string[0] -= chat_string[1][i-1];
	chat_string[1] = delete(chat_string[1], i-1, 2);
    }
}

void load_a_chat(int chance, string *c_s) 
{
    int i;
    if (!achat_string)
    { achat_string = ({ 0, ({ }) }); }
    for (i=0;i<sizeof(c_s);i+=2) 
    {
	achat_string[1] += ({ c_s[i], c_s[i+1] });
	achat_string[0] += c_s[i];
    }
    achat_chance = chance;
}

void set_achat_chance(int i) { achat_chance = i; }
int query_achat_chance() { return achat_chance; }
void set_achat_string(string *chat) { achat_string = chat; }
string *query_achat_string() { return achat_string; }

void add_achat_string(mixed weight, mixed chat)
{
    int i;

    if (pointerp(weight))
	for (i=0;i<sizeof(weight);i+=2)
	    add_achat_string(weight[i], weight[i+1]);
    else if (member_array(chat, achat_string[1]) == -1) 
    {
	achat_string[1] += ({ chat });
	achat_string[0] += weight;
    }
}


void remove_achat_string(mixed chat) 
{
    int i;

    if (pointerp(chat))
	for (i=0;i<sizeof(chat);i++)
	    remove_achat_string(chat[i]);
    else if ((i = member_array(chat, achat_string[1])) != -1) 
    {
	achat_string[0] -= achat_string[1][i-1];
	achat_string[1] = delete(achat_string[1], i-1, 1);
    }
}

/* does the basic chat handling */
void chatter(int chance, mixed chat)
{
    int i,j;

    if( !sizeof(chat) ) 
	return;
    if (sizeof(story) )
    {
	if(which_story < sizeof(story))
	    expand_mon_string(story[which_story++]);
	else
	{
	    story = 0;
	    which_story = 0;
	}
    }
    else if( random(1000) < chance )
    {
	i = random(chat[0]+1);
	j=0;
	while ( (i -= chat[1][j]) >0)
	    j += 2;
	if (pointerp(chat[1][j+1]))
	    story = chat[1][j+1];
	else 
{
	    expand_mon_string(chat[1][j+1]);
}
    }
}
void chat_now() { chatter(chat_chance,chat_string); }
void do_achat() { chatter(achat_chance,achat_string); }
void set_talk_string(mixed arr) { talk_string = arr; }
mixed query_talk_string() { return talk_string; }

void add_talk_string(string cat, mixed do_this) 
{
    talk_string += ({ cat, do_this });
}

void remove_talk_string(string cat) 
{
    int i;

    if ((i=member_array(cat, talk_string)) == -1)
	return ;
    talk_string = delete(talk_string, i, 2);
}

void catch_talk(string str) 
{
    string s1, s2;
    int i;

    if (in_talk)
	return ;

    in_talk = 1;
    for (i=0;i<sizeof(talk_string);i+=2)
	if (sscanf(str, "%s"+talk_string[i]+"%s", s1, s2))
	    if (stringp(talk_string[i+1]))
		call_other(this_object(), talk_string[i+1], str, s1, s2);
	    else if (pointerp(talk_string[i+1]))
		call_other(talk_string[i+1][0], talk_string[i+1][1], str, s1, s2);

    in_talk = 0;
}
void expand_mon_string(string str) 
{
    object current;
    int FOUND = 0;
    if (!stringp(str)) 
      return;
/* Added bit by Bishop so it will find the room the object
 * is in.  Allows rooms and items to chat */
    current = this_object();
/* Basically finds the current object and checks if it is a room, if
 * not, then checks its environment and so on until no environment
 * or finds a room.  The messages then goto that room. */
    while (!FOUND)
      {
	if (current->query_property("location"))
	  {
	    FOUND=1;
	  }
	if (!FOUND)
	  {
	    current = environment(current);
	    if (!current)
              return;
	  }
      }
    switch (str[0]) 
    {
    case ':' :
      tell_room(current,this_object()->query_short()+" "+
		(string)MONSTER_HAND->expand_string(TO,str[1..1000],0,0)+"\n");
      break;
    case '\'' :
    case '"' :
    case '@' :
    case '\'':
      command((string)MONSTER_HAND->expand_string(TO,str,0,0));
      break;
    case '#': /* execute function */
      call_other(TO,str[1..1000]);
      break;
    default :
      tell_room(current,(string)MONSTER_HAND->expand_string(TO,str,0,0)+"\n");
    }
}
