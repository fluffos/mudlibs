//   helpful little function to generate mineral maps.
//   -Diewarzau 1/29/96
//   DarkeLIB 1.0

#include <security.h>
#include <dirs.h>

void generate_map(string type, int max_mines, int good_mine) {
  int non_h2o;
  int i, j, idx, *mines;
  int *choice, tmp;
  string *lines, *words, file;

  seteuid(UID_DAMNED_DATA);
  if(!wizardp(this_player())) {
    write("Only wizards may do this.");
    seteuid(getuid());
    return;
  }
  lines = explode(read_file(DIR_DATA_DAMNED+"/world_terrain.db"), "\n");
  non_h2o = 0;
  for(i=0;i<sizeof(lines);i++) {
    words = explode(lines[i], ":");
    j = sizeof(words);
    while(j--)
      if(lower_case(words[j]) != "w") non_h2o++;
  }
  write("Non H2O spaces "+non_h2o);
  mines = allocate(non_h2o);
  choice = allocate(non_h2o);
  i = sizeof(choice);
  while(i--) choice[i] = i;
  i = non_h2o;
  while(i--)
    mines[i] = random(3) + random(5)/3 + random(10)/8;
  for(j=0; j<max_mines; j++) {
    if(!choice || !sizeof(choice)) continue;
    else if(sizeof(choice) == 1) i = 0;
    else i = random(sizeof(choice));
    mines[choice[i]] = good_mine/2 + random(good_mine);
    choice = exclude_array(choice, i);
  }
  file = "/wizards/"+(string)this_player()->query_name();
  if(file_size(file) != -2) {
    write("Can't find your wiz directory!");
    seteuid(getuid());
    return;
  }
  idx = 0;
  file += "/mineral_"+type+".db";
  if(file_exists(file)) rm(file);
  for(i=0; i<sizeof(lines); i++) {
    words = explode(lines[i], ":");
    for(j=0;j<sizeof(words);j++) {
      if(lower_case(words[j]) == "w")
        words[j] = "0";
      else if(idx >= (sizeof(mines)-1)) words[j] = 0;
      else {
        words[j] = sprintf("%d", mines[idx]);
        idx++;
      }
    }
    seteuid(getuid());
    write_file(file, implode(words, ":")+":\n");
    seteuid(UID_DAMNED_DATA);
  }
  write("Mineral file generated: "+
    file);
  seteuid(getuid());
  return;
}

