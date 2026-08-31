inherit "room/room";

#define EXTRA_RESET
#define DEST_DIRS

reset(arg) {
    ::reset(arg);
    EXTRA_RESET
    if(arg) return;
    set_light(1);
    short_desc="Ocean shore";
    long_desc=
"You are on the road leading south next to the ocean shore. Huge waves roll\n"+
"towards the land. You notice seagulls in the far distance.\n";
    dest_dir=DEST_DIRS;
    smell="The air smells salty here";
    items=({ "ocean","The wild green ocean",
             "wave","It rolls exactly in your direction",
             "waves","They roll and roll and roll and ....",
             "tide","The flood is on its highest level",
             "land","Almost as much as water",
             "bird","Yep, it is",
             "birds","Seems to be a group of seagulls",
             "seagull","Moves like a bird",
             "seagulls","Wow, more than one seagull in fact",
             "distance","Seems far away" });
}
