// Petrarch
// Merentha Lib 1.0
// <nickname>

string help() {
    return "\
Syntax: nickname                    - lists all nicknames\n\
        nickname <nick>             - shows what <nick> is aliased to\n\
        nickname add <nick> <long>  - creates nickname\n\
        nickname remove <nick>      - removes a nickname\n\
\n\
Nicknames are used to help you type in short hand.  You can create an nickname as follows:\n\
> nickname add petr Petrarch\n\
\n\
Now whenever you type 'say Hi petr' it is just like typing 'say Hi Petrarch'.\n\
\n\
See also: alias\
";
}

int display_aliases() {
    mapping aliases=([]);
    string *k, *ret=({});
    int i, max=0, lines;
    lines=(this_player()->getenv("SCREEN")?this_player()->getenv("SCREEN"):75);
    aliases=this_player()->query_nickname();
    if(!aliases) this_player()->init_nicknames();
    aliases=this_player()->query_nickname();
    if(!aliases) aliases=([]);
    i=sizeof(k=sort_array(keys(aliases),-1));
    while(i--) if(strlen(k[i])>max) max=strlen(k[i]);
    i=sizeof(k);
    while(i--) ret+=({"%^RED%^"+arrange_string(k[i],max)+": %^ORANGE%^"+aliases[k[i]]+" "});
    i=sizeof(ret);
    while(i--) if(strlen(strip_colours(ret[i]))>max) max=strlen(strip_colours(ret[i]));
    if(max) {
        max=lines/max;
        this_player()->more(border(format_page(ret,max,lines-4),"nickname",lines ));
    } else  
        message("command", "You have no nicknames set.", this_player());
    return 1;
}

varargs int command(string str) {
    string word, alias;
    if(!str) return display_aliases();
    if(sscanf(str, "add %s %s", word, alias)==2) {
        this_player()->add_nickname(word, alias);
        message("command", "Nickname added: "+word+" -> "+alias, this_player());
        return 1;
    } else {
        if(sscanf(str, "remove %s", word)==1) {
            this_player()->remove_nickname(word);
            message("command", "Nickname: "+word+" removed.", this_player());
            return 1;
        } else {
            alias=this_player()->query_nickname(str);
            if(!alias) message("command", "Nickname for "+str+" not found.", this_player());
            else message("command", "Nickname: "+str+" -> "+alias, this_player());
            return 1;
        }
    }
}


