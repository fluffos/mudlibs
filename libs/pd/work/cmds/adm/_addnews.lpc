//  addnews
//  Whit

#define INDENT "     "
#define INDENT2 "       "
#define INDENT3 "          "
#define HEADER "%^BLUE%^%^BOLD%^                            ______________________%^RESET%^\n" \
               "%^BLUE%^     ----------------------%^BOLD%^| %^RESET%^Primal Darkness News%^" \
               "BOLD%^%^BLUE%^ |%^RESET%^%^BLUE%^----------------------%^RESET%^ "
#define FOOTER "%^BLUE%^--------------------------------------------------------------------"
#define STAR   "%^BOLD%^%^GREEN%^*%^RESET%^"

string new_file() {
    return HEADER+"\n\n"+INDENT+FOOTER;
}

int cmd_addnews(string s) {
    string f, fname, *lines, *wr;
    int i, x;
    if(!s || s=="") return notify_fail("Syntax: <addnews [string]>\n");
    fname="/news/news";
    f=read_file(fname);
    if(!f) f=new_file();
    lines=explode(f, "\n");
    i=2;
    lines[i] += "\n"+INDENT2+STAR+"  ";
    wr=explode(wrap(s, 60), "\n");
    x=sizeof(wr);
    lines[i] += wr[0]+"\n";
    for(x=0; x< sizeof(wr); x++) if(x!=0) lines[i] += INDENT3+""+wr[x]+"\n";
    lines[i] += "";
    lines[i]=replace_string(lines[i], "<", "%^BOLD%^%^CYAN%^<%^RESET%^");
    lines[i]=replace_string(lines[i], ">", "%^BOLD%^%^CYAN%^>%^RESET%^");
    write("News added.\n");
    seteuid("News");
    rm(fname);
    write_file(fname, implode(lines, "\n"));
    seteuid(geteuid());
    return 1;
}

