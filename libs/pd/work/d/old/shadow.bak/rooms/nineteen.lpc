//Path connecting Mountains/lodos to Tenebrae

#include <std.h>
#include <shadow.h>
inherit ROOM;

string look_pond();
string do_descript();
void set_here(int x);

int here;

void create() {
    ::create();
    here = 0;
    set_short("Forest Path");
    set_properties( (["light" : 2, "night light" : 1]) );
    set_property("forest", 1);
    set_listen("default", "The ocassional twig snapping can be heard.");
    set_smell("default", "The scent of pine fills the air.");
    set_long((: do_descript :));
    set_exits( (["northeast" : ROOMS+"twenty"]) );
    set_items( ([ ({"tree","trees"}) : "The trees are %^GREEN%^dark green%^RESET%^.  They have shed their brown needles all over the ground."
                 ,"needles" : "There are many needles all over the ground."
                 ,"path" : "It seems to be fairly well travelled."
                 ,"roots" : "The roots are large and gnarled."
                 ,({"rock","rocks"}) : "This rock was perhaps a marker for the right way to go."
                 ,"pond" : (: look_pond :)
                 ]) );
}

void reset() {
    ::reset();

    if(!present("pixie",this_object())) {
        new(MOB"pixie")->move(this_object());
        here = 0;
    }
}

void set_here(int x) { here = x; }

string look_pond() {
    if(here == 1)
        return "The pond has turned a deep red...  Someone must have died.";
    return "A lovely crystal clear pond.";
}

string do_descript() {
    if(here == 1)
        return "This small clearing looks like it once used to be peaceful, but something has disrupted it.  It seems that someone has been viciously murdered here.  The scene here is enough to make even the most battle hardened veteran cringe.  The once peaceful pond has been desecrated.";
    return "A small pixie is sitting here beside a pond crying.  It seems that she has lost her way in this confusing wood and does not know how to get back to her home.  She has her head buried in her lap and doesnt even look up.  She must have been here quite a while.  Poor little Pixie.";
}
