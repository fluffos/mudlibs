// Petrarch
// Merentha Lib 1.0
// help.c

#include <std.h>

inherit DAEMON;

string *get_help_menu(string topic) {
    string *topics;
    int i;
    if(!topic) topic="categories";
    switch (topic) {
    case "categories":
        topics=({"applies","efuns","sefuns","lfuns"});
        return topics;
        break;
    case "applies":
        return get_dir("/doc/man/applies/");
        break;
    case "efuns":
        return get_dir("/doc/man/efuns/");
        break;
    case "sefuns":
        return get_dir("/doc/man/sefuns/");
        break;
    case "lfuns":
        return get_dir("/doc/man/lfuns/");
        break;
    }
    return ({});
}

void do_help(string topic, int x) {
    string *topics;
    int max,i;
    if(!x) x=75;
    if(!topic || topic=="" || topic=="main") topic="categories";
    i=sizeof(topics=get_help_menu(topic));
    while(i--) if(strlen(topics[i])>max) max=strlen(topics[i]);
    max=x/(max+3);
    if(max<3) max=3;
    this_player()->more(border("%^RED%^\
Please select from the menu below a topic to get the man page on:\n\n"+
        "%^GREEN%^"+format_page(topics,max,x-4)+"\n"+
border(
"%^ORANGE%^\
<q> to quit.\n\
<main> to return to the main menu\n\
<enter> to display topic menu\
",0,37),"Welcome to the "+mud_name()+" Man System",x), 0, 0, this_object(),"return_topic_menu", topic, x);
    if(in_input(this_player())) return;
    message("prompt", "%^GREEN%^Man Topic: ", this_player());
    input_to("get_topic", topic, x);
}

void return_topic_menu(string topic, int x) {
    message("prompt", "%^GREEN%^Man Topic: ", this_player());
    input_to("get_topic", topic, x);
}

string colourize(string str) { 
 str=replace_string(str, "\n\n", "\n%^GREEN%^\n");
 str=replace_string(str, "See Also:", "%^BOLD%^%^WHITE%^See also:");
 str=replace_string(str, "See also:", "%^BOLD%^%^WHITE%^See also:");
 return str;
}

void get_topic(string topic, string category, int x) {
    object cmd;
    string help_file;
    if(!topic || topic=="" || !category) {
        do_help(category,x);
        return;
    }
    if(topic=="main") {
        do_help(0,x);
        return;
    }
    if(topic=="q") return;
    if(member_array(topic,get_help_menu(category))==-1) {
        if(topic!="") message("help", "Topic "+topic+" not found in category "+category+".", this_player());
        message("prompt", "%^GREEN%^Man Topic: ", this_player());
        input_to("get_topic", category, x);
        return;
    }
    if(category=="categories") {
        do_help(topic,x);
        return;
    }
    switch(category) {
    case "applies":
        if(file_exists("/doc/man/applies/"+topic)) help_file=read_file("/doc/man/applies/"+topic);
        if(help_file) help_file="\n"+help_file;
        break;
    case "efuns":
        if(file_exists("/doc/man/efuns/"+topic)) help_file=read_file("/doc/man/efuns/"+topic);
        if(help_file) help_file="\n"+help_file;
        break;
    case "sefuns":
        if(file_exists("/doc/man/sefuns/"+topic)) help_file=read_file("/doc/man/sefuns/"+topic);
        if(help_file) help_file="\n"+help_file;
        break;
    case "lfuns":
        if(file_exists("/doc/man/lfuns/"+topic)) help_file=read_file("/doc/man/lfuns/"+topic);
        if(help_file) help_file="\n"+help_file;
        break;
    }
    if(!help_file) help_file="\nThe topic "+topic+" has no man file.";
    this_player()->more(border("%^RED%^Topic: "+topic+colourize("\n"+help_file)+
        "\n"+border("%^ORANGE%^<q> to quit\n\
<main> to return to the main menu\n\
<enter> to display topic menu\
",0,37),"Welcome to the "+mud_name()+" Man System",x),0,0,this_object(),"return_help_file", category, x);
    if(in_input(this_player())) return;
    message("prompt", "%^GREEN%^Man Topic: ", this_player());
    input_to("get_topic", category, x);
}

void return_help_file(string category, int x) {
    message("prompt", "%^GREEN%^Man Topic: ", this_player());
    input_to("get_topic", category, x);
}

void get_help_file(string topic, int x) {
    object ob;
    string *dirs=({"/doc/man/applies/","/doc/man/sefuns/","/doc/man/efuns/","/doc/man/lfuns/"});
    string help_file;
    int i;
    if(!x) x=75;
    i=sizeof(dirs);  
    while(i--) 
        if(file_exists(dirs[i]+topic)) {
            help_file=read_file(dirs[i]+topic);
//            help_file=replace_string(help_file,"\n\n","XXX-XXX");
//            help_file=replace_string(help_file,"\n"," ");
//            help_file=replace_string(help_file,"XXX-XXX","\n\n");
            this_player()->more(border(colourize("%^GREEN%^"+help_file),mud_name()+" Man: "+topic,x));
            return;
        }
    message("help", "Topic: "+topic+" could not be found in the man system.", this_player());
}

