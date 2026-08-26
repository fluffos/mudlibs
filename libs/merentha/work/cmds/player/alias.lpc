// Petrarch
// Merentha Lib 1.0
// <alias>

string help() {
    return "\
Syntax: alias                       - lists all aliases\n\
        alias <alias>               - shows what <alias> is aliased to\n\
        alias add <alias> <command> - creates alias\n\
        alias remove <alias>        - removes an alias\n\
\n\
Aliases are used to help you type in short hand.  You can create an alias as follows:\n\
> alias add l look\n\
\n\
Now whenever you type 'l' it is just like typing 'look'.\n\
\n\
See also: nickname\
";
}

int display_aliases() {
    mapping aliases=([]);
    string *k, *ret=({});
    int i, max=0, lines;
    lines=(this_player()->getenv("SCREEN")?this_player()->getenv("SCREEN"):75);
    aliases=this_player()->query_alias();
    if(!aliases || !sizeof(aliases)) this_player()->init_aliases();
    aliases=this_player()->query_alias();
    if(!aliases) aliases=([]);
    i=sizeof(k=sort_array(keys(aliases),-1));
    while(i--) if(strlen(k[i])>max) max=strlen(k[i]);
    i=sizeof(k);
    while(i--) ret+=({"%^RED%^"+arrange_string(k[i],max)+": "+"%^ORANGE%^"+aliases[k[i]]+" "});
    i=sizeof(ret);
    while(i--) if(strlen(strip_colours(ret[i]))>max) max=strlen(strip_colours(ret[i]));
    max=lines/max;
    this_player()->more(border(format_page(ret,max,lines-4),"aliases",lines));
    return 1;
}

varargs int command(string str) {
    string word, alias;
    if(!str) return display_aliases();
    if(sscanf(str, "add %s %s", word, alias)==2) {
      this_player()->add_alias(word, alias);
      message("command", "Alias added: "+word+" -> "+alias, this_player());
      return 1;
    } else {
        if(sscanf(str, "remove %s", word)==1) {
          this_player()->remove_alias(word);
          message("command", "Alias: "+word+" removed.", this_player());
          return 1;
        } else {
          alias=this_player()->query_alias(str);
          if(!alias) message("command", "Alias for "+str+" not found.", this_player());
          else message("command", "Alias: "+str+" -> "+alias, this_player());
          return 1;
        }
    }
}


