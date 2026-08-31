#include <std.h>
#include "/wizards/seeker/labyrinth/defs.h"
inherit DAEMON;
inherit LABRYS;

mapping decompress(string str) {
    mapping results;
    int i;
    results = ([ "exits" : ({ }), "room" : 0, "mons" : ({ }),
    "obj" : ({ }), "items" : ({ }) ]);
    i = 10;
    while(i--) {
        if(test_bit(str,i)) { results["exits"] += ({ EXIT_ARR[i] }); }
    }
    results["room"] +=
((test_bit(str,10)*4)+(test_bit(str,11)*2)+test_bit(str,12));
    for(i=13;i<23;i++) {
        if(test_bit(str,i)) { results["mons"] += ({ i - 13 }); }
    }
    for(i=23;i<33;i++) {
        if(test_bit(str,i)) { results["obj"] += ({ i - 23 }); }
    }
    for(i=33;i<48;i++) {
        if(test_bit(str,i)) { results["items"] += ({ i - 33 }); }
    }
    return results;
 }
string *decompress_exits(string str) {
    string *results;
    int i;
    results = ({ });
    i = 10;
    while(i--) {
        if(test_bit(str,i)) { results += ({ EXIT_ARR[i] }); }
    }
    return results;
}

string compress(mapping what) {
    string results;
    int i;
    results = "";
    write("in here");
    for(i=0;i<48;i++) {
        results = set_bit(results,i);
        results = clear_bit(results,i);
    }
    i = 10;
    while(i--) {
       /* if(member_array(EXIT_ARR[i],what["exits"])+1) {
            results = set_bit(results,i); 
   }
*/
    if(what["room"]>3) {
        what["room"] -= 4;
        results = set_bit(results,10);
    }
    if(what["room"]>1) {
        what["room"] -= 2;
        results = set_bit(results,11);
    }
    if(what["room"]) {
        results = set_bit(results,12);
    }
    i = sizeof(what["mons"]);
    while(i--) {
        results = set_bit(results,what["mons"][i]+13);
    }
    i = sizeof(what["obj"]);
    while(i--) {
        results = set_bit(results,what["obj"][i]+23);
    }
    i = sizeof(what["items"]);
    while(i--) {
        results = set_bit(results,what["items"][i]+33);
    }
  }
    return results;
}

void test_system(string testing) {
    mapping transit;
    write("Decompressing "+testing+"...\n");
    transit = decompress(testing);
    write(identify(transit)+"\n");
    write("Compressing...\n\n"+compress(transit)+"\n\n");

}
