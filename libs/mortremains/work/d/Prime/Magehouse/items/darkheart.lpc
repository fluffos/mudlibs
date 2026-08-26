// Darkheart.c
// 3/12/2000
// By Cyanide for Blood

inherit OBJECT;

void create() {
    seteuid(getuid());

    set("short", "the Dark Heart of Longing");
    set("long", @EndLong
The Dark Heart of Longing is made of a single huge ruby, however, the ruby
can be looked into as if it were made of glass. Inside you see two souls,
spinning around one another, one of an evil demon, struggling with a 
sacrifice to the gods, who gave herself willingly and pure of heart. These
forms fight ever on, struggling to win dominance over the other. They meet
in the center forming the channel of power which allows this artifact to
function. The word 'align' is etched into its surface.
EndLong
    );
    set("id", ({ "heart", "dark heart" }) );
    set("mass", 1);
    set("value", 800);
} 

void init() {
    add_action("align", "align");
}

int align(string str) {
    write(@EndText
    
    You may change your alignment traits by entering the following:

    1 - Good            A - Lawful
    2 - Neutral         B - Neutral
    3 - Evil            C - Chaotic

EndText
    );
    write("Enter your choice now: ");
    input_to("align2", 0, TO);
    return 1;
}

int align2(string str) {
    int e, m;
    mapping ali = TP->query_true_alignment();

    if (!str) {
        write("Dark Heart:  Cancelled.\n");
        return 1;
    }

    str = lower_case(str);

    e = keys(ali)[0];
    m = values(ali)[0];

    // void set_true_align(int e, int m)  
    switch(str) {
        case "a" : e =  1; break;
        case "b" : e =  0; break;
        case "c" : e = -1; break;
        case "1" : m =  1; break;
        case "2" : m =  0; break;
        case "3" : m = -1; break;
    }

    TP->set_true_alignment(e, m);

    write("Your alignment is now "+TP->query_align()+".\n");

    return 1;
}

/* EOF */