#include <std.h>
#include <tirun.h>

inherit ROOM;

int chairs, fireplace;

void create() {
    ::create();
    set_smell("default", "Thick dust makes breathing difficult.");
    set_listen("default", "Silence.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
        "%^CYAN%^The looks of this house chill the bones.%^RESET%^\n"
        "This is the sitting room, a place that probably was quite comfortable and "
        "busy while the house was still active.  A large, cracked chandelier hangs "
        "from the middle of the room.  Large chairs, covered with sheets, sit like "
        "immobile ghosts throughout the room.  A large stone fireplace is in the "
        "northern wall.  The only door goes back into the entrance.");
    set_items(
        (["chandelier" : "The chandelier hangs precariously by only a few supporting strands.",
          "chairs" : "The chairs sit randomly around the room.  Who knows what could be under those sheets.",
          "mantle" : "The mantle is bare, except for a very suspicious looking picture.",
          "picture" : 

"X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n"
"                          ,,'``````````````',,\n"
"                       ,'`                   `',\n"
"                     ,'                         ',\n"
"                   ,'          ;       ;          ',\n"
"      (           ;             ;     ;             ;     (\n"
"       )         ;              ;     ;              ;     )\n"
"      (         ;                ;   ;                ;   (\n"
"       )    ;   ;    ,,'```',,,   ; ;   ,,,'```',,    ;   ;\n"
"      (    ; ',;   '`          `',   ,'`          `'   ;,' ;\n"
"       )  ; ;`,`',  _--~~~~--__   ' '   __--~~~~--_  ,'`,'; ;     )\n"
"      (    ; `,' ; :  /       \\~~-___-~~/       \\  : ; ',' ;     (\n"
" )     )   )',  ;   -_\\  o    /  '   '  \\    o  /_-   ;  ,'       )   (\n"
"(     (   (   `;      ~-____--~'       '~--____-~      ;'  )     (     )\n"
" )     )   )   ;            ,`;,,,   ,,,;',            ;  (       )   (\n"
"(     (   (  .  ;        ,'`  (__ '_' __)  `',        ;  . )     (     )\n"
" )     \\/ ,\".). ';    ,'`        ~~ ~~        `',    ;  .(.\", \\/  )   (\n"
"(   , ,'|// / (/ ,;  '        _--~~-~~--_        '  ;, \\)    \\|', ,    )\n"
",)  , \\/ \\|  \\\\,/  ;;       ,; |_| | |_| ;,       ;;  \\,//  |/ \\/ ,   ,\n"
",   .| \\_ |\\/ |#\\_/;       ;_| : `~'~' : |_;       ;\\_/#| \\/| _/ |.   ,\"\n"
"(,'  )  \\\\\\#\\ \\##/)#;     :  `\\/       \\/   :     ;#(\\##/ /#///  (  ',)#\n"
" ) | \\ |/ /#/ |#( \\; ;     :               ;     ; ;/ )#| \\#\\ \\| / | ( |)\n"
" |.\\\\ |\\_/#| /#),,`   ;     ;./\\_     _/\\.;     ;   `,,(#\\ |#\\_/| //.| /\n"
"\\\\_/# |#\\##/,,'`       ;     ~~--|~|~|--~~     ;       `',,\\##/#| #\\_// \\\n"
" ##/#  #,,'`            ;        ~~~~~        ;            `',,#  #\\##  /\n"
"###@,,'`                 `',               ,'`                 `',,@####|\n"
",,'`                        `',         ,'`                        `',,##\n"
"                               ~~-----~~                               `'\n"
"X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X\n\n\n"

"  The picture is attached to some switch...  perhaps if you pulled the picture something would happen.\n"

    ]) );
    set_exits( ([ "east" : ROOMS"hhouse/1" ]) );
    chairs = 0;
    fireplace = 0;
}

void init() {
  ::init();
  add_action("search", "search");
  add_action("look", "look");
  add_action("pull", "pull");
  add_action("enter", "enter");
}

void reset() {
  ::reset();
  chairs = 0;
  fireplace = 0;
}

int search(string str) {
  if(!str) return 0;

  if(str != "chairs")
    return 0;

  if(chairs)
    return 0;

  write("                     _..-'(                       )`-.._\n"
"                   ./'. '||\\\\.       (\\_/)       .//||` .`\\.\n"
"                ./'.|'.'||||\\\\|..    )O O(    ..|//||||`.`|.`\\.\n"
"             ./'..|'.|| |||||\\`````` '`\"'` ''''''/||||| ||.`|..`\\.\n"
"           ./'.||'.|||| ||||||||||||.     .|||||||||||| |||||.`||.`\\.\n"
"          /'|||'.|||||| ||||||||||||{     }|||||||||||| ||||||.`|||`\\\n"
"         '.|||'.||||||| ||||||||||||{     }|||||||||||| |||||||.`|||.`\n"
"        '.||| ||||||||| |/'   ``\\||``     ''||/''   `\\| ||||||||| |||.`\n"
"        |/' \\./'     `\\./         \\!|\\   /|!/         \\./'     `\\./ `\\|\n"
"        V    V         V          }' `\\ /' `{          V         V    V\n"
"        `    `         `               V               '         '    '");
  say(this_player()->query_cap_name()+" lifts up a sheet and a bat flies out at them!");
  write("\nA bat flies out at you when you lift the sheet!");
  new(ROOMS"hhouse/bat")->move(this_object());
  new(ROOMS"hhouse/bat")->move(this_object());
  chairs = 1;
  return 1;
}

int look(string str) {
  if(!str)
    return 0;

  if(str != "fireplace")
    return 0;

  if(fireplace == 0)
    write("The fireplace is made of heavy stone with a wooden mantle.");
  else
    write("There is no back to the fireplace!  It leads to a secret passage that you could probably enter.  The picture on the mantle is tipped over.");
  return 1;
}

int pull(string str) {
  if(!str)
    return notify_fail("Pull what?\n");

  if(str != "picture")
    return notify_fail("You cannot pull that.\n");

  write("As you pull on the picture, you hear a rumbling come from the fireplace.");
  say("As "+this_player()->query_cap_name()+" pulls on the picture, the fireplace emits a low rumble for a second.");
  if(fireplace)
    fireplace = 0;
  else
    fireplace = 1;

  return 1;
}

int enter(string str) {
  if(!str)
    return 0;

  if(str != "passage")
    return 0;

  if(fireplace == 0)
    return 0;

  write("You climb through the passage.");
  say(this_player()->query_cap_name()+" climbs into the fireplace.");
  this_player()->move(ROOMS"hhouse/hall");
  this_player()->describe_current_room(1);
  return 1;
}
