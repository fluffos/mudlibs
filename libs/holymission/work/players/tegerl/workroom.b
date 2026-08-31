#define NAME "tegerl"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
        short_desc=CNAME + "' workroom",

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
        /*  "This is the house of "+CNAME+".\n" + */
            "You are in a luxurious cabin at the stern of a big old ship.\n" +
            "The floor, the ceiling and the walls are made of wood. At the\n" +
            "stern side are many windows. This cabin is the workroom of Tegerl.\n" +
            "There are a few chairs, a desk and a shelf.\n" +
            "In a corner you can see a seating accommodation and at the opposite\n" +
            "side a bunk is built in the wall.\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "room/post", "post",
	    "room/church", "church",
            "room/adv_guild", "guild",
            "players/matt/newworld/city/rooms/votebooth", "vote",
            "players/tegerl/wr/corr", "corridor", 
                 });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "walls","The walls are wooden, in one of them is a bunk",
            "floor","The floor is dirty",
            "windows","Those windows give you a look at this beautiful port",
            "port","It is really a lovely port, you really should visit it",
            "desk","This is Tegerl's working place. Don't think it is often used",
            "shelf","There are many books in that shelf, but you wonder if Tegerl ever read one of them",
            "seating","This seems to be Tegerl's favorit place in this room. You can see some bottles",
            "bottles","Beer, what else.....",
            "bunk","When Tegerl is in here, don't disturb, sleeping",
              });
        /* Properties can be set like the following */
        property = ({
                     "no_teleport","no_sneak","no_steal",
                    });
        /* Smell is set like this... */
        smell = "This place is a bit dusty";
    }
}

init()
{
  ::init();
}
