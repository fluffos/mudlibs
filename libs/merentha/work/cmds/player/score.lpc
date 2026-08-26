// Petrarch
// Merentha Lib 1.0
// <score>

string money_string(int j) {
mapping money=this_player()->query_money();
string *types=keys(money), ret="";
int i=sizeof(types),m;
  
if(!i) ret="You have no money.";
else {
  while(i--) {
    if (m=this_player()->query_money(types[i])) 
      types[i]="%^ORANGE%^"+m+" %^GREEN%^"+types[i];
    else types-=({types[i]});
  }
  ret=format_page(types,3,j);
}
return ret;
}

int command() {
    int x,i=this_player()->getenv("SCREEN");
    string line="__BORDER_LINE__";
    if(!i)i=75;
    x=i;
    x=i;
    i-=13;
    i=i/3;
    message("command", border(
        "%^RED%^ Name   : %^GREEN%^"+this_player()->query_cap_name()+
        ", "+this_player()->query_gender()+" "+capitalize(this_player()->query_race())+
        "\n Score  : %^ORANGE%^"+this_player()->query_exp()+
        " (level "+this_player()->query_level()+
        " "+(this_player()->query_class()?this_player()->query_class():"child")+
        ")\n"+
        line+
        "\n%^RED%^ Vitals : "+arrange_string("%^GREEN%^Health %^ORANGE%^"+this_player()->query_hp()+"("+this_player()->query_max_hp()+")",i)+
        arrange_string("%^GREEN%^Magic %^ORANGE%^"+this_player()->query_mp()+"("+this_player()->query_max_mp()+")",i)+
        arrange_string("%^GREEN%^Stamina %^ORANGE%^"+this_player()->query_sp()+"("+this_player()->query_max_sp()+")",i)+
        "\n"+
        line+
        "\n%^RED%^ Stats  : "+
        arrange_string("%^GREEN%^Strength %^ORANGE%^"+this_player()->query_stat("strength"),i)+
        arrange_string("%^GREEN%^Constitution %^ORANGE%^"+this_player()->query_stat("constitution"),i)+
        arrange_string("%^GREEN%^Dexterity %^ORANGE%^"+this_player()->query_stat("dexterity"),i)+
        "\n          "+
        arrange_string("%^GREEN%^Intelligence %^ORANGE%^"+this_player()->query_stat("intelligence"),i)+
        arrange_string("%^GREEN%^Wisdom %^ORANGE%^"+this_player()->query_stat("wisdom"),i)+
        arrange_string("%^GREEN%^Charisma %^ORANGE%^"+this_player()->query_stat("charisma"),i)+
        "\n"+
        line+
        "\n%^RED%^ Money  : "+
        money_string(i*3)
        ,"score",x),this_player());
    return 1;
}
string help() {
    return "Syntax: score\n\nThis command displays your current score and vital statistics.\n\nSee also: stats, skills, cost, money";
}
