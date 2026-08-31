//Path connecting Mountains/lodos to Tenebrae

#include <std.h>
#include <shadow.h>
inherit ROOM;

string do_descript();

void create() {
    string desc;
    ::create();
    desc = do_descript();
    set_short("Forest Path");
    set_properties( (["light" : 2, "night light" : 1]) );
    set_property("forest", 1);
    set_listen("default", "The ocassional twig snapping can be heard.");
    set_smell("default", "The scent of pine fills the air.");
    set_long(desc);
    set_exits( (["northeast" : ROOMS+"twentyfour"]) );
    set_items( ([ ({"tree","trees"}) : "The trees are %^GREEN%^dark green%^RESET%^.  They have shed their brown needles all over the ground."
                 ,"needles" : "There are many needles all over the ground."
                 ,"path" : "It seems to be fairly well travelled."
                 ,"roots" : "The roots are large and gnarled."
                 ,({"rock","rocks"}) : "This rock was perhaps a marker for the right way to go."
                 ]) );
}

void reset() {
    int x;
    ::reset();

    if(!present("monster",this_object())) {
        x = random(25)+20;
        while(x >= 25) {
            if(x < 30)
                new(MOB+"snake")->move(this_object());
            else if(x < 35)
                new(MOB+"chipmunk")->move(this_object());
            else if(x < 40)
                new(MOB+"deer")->move(this_object());
            else
                new(MOB+"bug")->move(this_object());
        x = random(45);
        if(present("monster 10",this_object()))
            break;
        }
    }
}

string do_descript() {
    int x, max;
    string ret;
    int *flag;

    flag = ({0,0,0,0,0,0,0,0,0,0});
    max = 3;

    ret = "The forest deepens here and looks the same in every direction.  ";

    for(int i=0;i < max;i++) {
        x = random(100);
        if((x < 10) && (flag[0] == 0)) {
            ret += "The paths all look exactly alike.  ";
            flag[0] = 1;
            }
        else if((x < 20) && (flag[1] == 0)) {
            ret += "It would be very easy to get lost here.  ";
            flag[1] = 1;
            }
        else if((x < 30) && (flag[2] == 0)) {
            ret += "It seems that there are some footprints in the ground here.  ";
            flag[2] = 1;
            }
        else if((x < 40) && (flag[3] == 0)) {
            ret += "This place in the woods looks very familiar.  ";
            flag[3] = 1;
            }
        else if((x < 50) && (flag[4] == 0)) {
            ret += "A large pine stands next to the path.  ";
            flag[4] = 1;
            }
        else if((x < 60) && (flag[5] == 0)) {
            ret += "The sound of an animal scurrying past comes from the underbrush.  ";
            flag[5] = 1;
            }
        else if((x < 70) && (flag[6] == 0)) {
            ret += "The trees sway in a light breeze over the forest.  ";
            flag[6] = 1;
            }
        else if((x < 80) && (flag[7] == 0)) {
            ret += "Large roots poke up from the ground, making travel difficult.  ";
            flag[7] = 1;
            }
        else if((x < 90) && (flag[8] == 0)) {
            ret += "A pile of rocks can be seen a little further into the woods.  ";
            flag[8] = 1;
            }
        else if((x < 100) && (flag[9] == 0)) {
            ret += "The path here curves around a large rock in the middle of the way.  ";
            flag[9] = 1;
            }
    }

    return ret;
}
