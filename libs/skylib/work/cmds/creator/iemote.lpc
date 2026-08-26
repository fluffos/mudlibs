
inherit COMMAND_BASE;

int cmd(string args) {
    string *words, who, where;
    int index;
    
    if(!args || args=="")
        return notify_fail("Syntax: iemote user@mudname <action>\n");

    if((index = member_array('@',args)) == -1)
        return notify_fail("Syntax: iemote user@mudname <action>\n");
        
    who = args[0..(index-1)];
    words = explode(args[(index+1)..]," ");
    for(int i=0;i<sizeof(words);i++){
      if(INTERMUD_H->mud_exists(implode(words[0..i]," "))){
         where = INTERMUD_H->mud_exists(implode(words[0..i]," "));
         args = implode(words[(i+1)..]," ");
      }
    }

    INTERMUD_H->emote(who, where, args);
    tell_object(TP,sprintf("You emote to %s@%s: %s@%s %s\n",
        capitalize(who), where, TP->query_cap_name(),
        mud_name(), args) );
    return 1;
} /* cmd() */
