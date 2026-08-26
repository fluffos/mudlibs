// Petrarch
// Merentha Lib 1.0
// <news>

int command() {
int i;
i=this_player()->getenv("SCREEN");
if(!i) i=75;
    if(file_exists("/doc/news/news"))
         this_player()->more(border("%^GREEN%^"+read_file("/doc/news/news"),"news",i));
    else message("news", "There is no news.", this_player());
    return 1;
}
string help() {
return "Syntax: news\n\nThis command allows you to keep current with "+mud_name()+" news.  Any news will be displayed by typing this command.";
}
