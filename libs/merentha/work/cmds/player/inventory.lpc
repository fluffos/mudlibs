// Petrarch
// Merentha Lib 1.0
// <inventory>

string help() {
return "Syntax: inventory\n\n\
This command displays the inventory which you are carrying or which \
you are wearing/wielding.";
}

int command() {
    object *inv=all_inventory(this_player());
    mapping worn=([]),carried=([]);
    string *worn_items, *carried_items, *pic;
    string tmp;
    int i=sizeof(inv),j,w,c,p,x,px;
    int total, total_weight;

    if(member_array("left wing", this_player()->query_limbs())==-1) {
        pic=explode(center("\
    _    \n\
   / \\   \n\
   \\_/   \n\
   _|_   \n\
  /| |\\  \n\
 / | | \\ \n\
M  | |  M\n\
   |-|   \n\
   | |   \n\
   | |   \n\
  _| |_  ",13),"\n");
        px=12;
    } else { 
        pic=explode(center("\
       _       \n\
  __  / \\  __  \n\
 /  \\ \\ / /  \\ \n\
/    \\_|_/    \\\n\
|    /| |\\    |\n\
|   / | | \\   |\n\
|  M /| |\\ M  |\n\
| __/ |-| \\__ |\n\
|/    | |    \\|\n\
      | |      \n\
     _| |_     ",19),"\n");
        px=18;
    }
    while(i--) {
        tmp=inv[i]->query_short();
        if(!tmp) tmp=inv[i]->query_name();
        if(!tmp) continue;
        if(inv[i]->query_worn_by() || inv[i]->query_wielded_by()) {
            if(worn[tmp]) worn[tmp]=worn[tmp]+1;
            else worn[tmp]=1;
        } else {
            if(carried[tmp]) carried[tmp]=carried[tmp]+1;
            else carried[tmp]=1;
        }
        total++;
        total_weight+=inv[i]->query_mass();
    }

    i=this_player()->getenv("SCREEN");
    if(!i) i=75;
    i-=px;
    i-=4;
    i=i/2;
    x=i;

    j=sizeof(worn_items=keys(worn));
    while(j--)
        worn_items[j]=arrange_string(consolidate(worn[worn_items[j]], worn_items[j]),i-1);
    j=sizeof(carried_items=keys(carried));
    while(j--)
        carried_items[j]=arrange_string(consolidate(carried[carried_items[j]], carried_items[j]),i-1);

    i=sizeof(pic)-2;
    c=sizeof(carried_items);
    w=sizeof(worn_items);
    p=i;
    if(c>i) i=c;
    if(w>i) i=w;

    tmp="";
    j=-2;
    while(j<i) {
        if(j==-2) {
            tmp+=arrange_string("%^GREEN%^"+center("Carried Items",x),x-1);
            tmp+=arrange_string("%^ORANGE%^"+pic[0],px);
            tmp+=arrange_string("%^GREEN%^"+center("Worn Items",x),x-1);
            tmp+="\n";
            j++;
            continue;
        }
        if(j==-1) {
            tmp+=arrange_string("",x-1);
            tmp+=arrange_string("%^ORANGE%^"+pic[1],px);
            tmp+="\n";
            j++;
            continue;
        }
        tmp+="%^RED%^";
        if(j<c) tmp+=carried_items[j];
        else tmp+=arrange_string("",x-1);
        tmp+="%^ORANGE%^";
        if(j<p) tmp+=pic[j+2];
        else tmp+=arrange_string("",px);
        tmp+="%^RED%^";
        if(j<w) tmp+=worn_items[j];
        else tmp+=arrange_string("",x-1);
        tmp+="\n";
        j++;
    }

    tmp+=center("\nYou are carrying "+total+"/"+this_player()->query_max_items()+" items and "+this_player()->query_holding_mass()+"/"+this_player()->query_max_mass()+" weight",x*2+px);

    i=this_player()->getenv("SCREEN");
    this_player()->more(border(tmp, "inventory", (i?i:75)));
    return 1;
}
