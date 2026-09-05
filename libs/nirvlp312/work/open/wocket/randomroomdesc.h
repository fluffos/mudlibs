get_random_long(){
  switch(random(3)){
  case 0: long_desc = "This is a long of a cave that was the first to return.\n";
          items = ({ "long","its a nice long",
                     "cave","its a nice cave",
                     "first","first isn't an item",
                  });
          break;
  case 1: long_desc = "This is a dark scary cave that was returned second.\n";
          items = ({ "dark","dark isnt an item",
                     "cave","its a nice cave",
                     "second","comes after first",
                  });
          break;
  case 2: long_desc = "Last verse.. same as the first.. a scary scary cave.\n";
          items = ({ "verse","same as the first",
                     "first","the one before second and after third",
                     "cave","its a nice cave",
                  });
          break;
  }
}
