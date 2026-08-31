inherit "room/room";

#define 

reset(arg) {

    short_desc="Southwest Courtyard";

    long_desc=
      "You have entered the southwest corner of a courtyard. "+
      "The abbey surrounds this courtyard. Stone pathways lead "+
      "you to various parts of the monk's guild. Fragrant flowers "+
      "grow in beds next to the pathways, and in the center of "+
      "the courtyard is a beautiful fountain. The water "+
      "is fresh and clean. The sun reflects off of the water and "+
      "dances across the stones in the bottom of the "+
      "fountain. There is a shade tree here with a bench to rest on. "+
      "The entrance to the guild lies to the south. The monk tailor "+
      "keeps shop to the west, and the courtyard continues to the "+
      "north, east, and northeast.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "fountain","It is bursting forth fresh water",
            "flowers","There are many here",
            "beds","They are full of flowers",
            "room","Yep, this is absolutely, positively a room",
          });

    property=({ "no_teleport" });   


  dest_dir=({
          "/players/misticalla/guild/rooms/courtyard3","north",
          "/players/misticalla/guild/rooms/courtyard4","northeast",
          "/players/misticalla/guild/rooms/courtyard2","east",
          "/players/misticalla/guild/rooms/tailor","west",
          "/players/misticalla/guild/rooms/entrance","south",
           });

    ::reset(arg);

    replace_program("room/room");
}

