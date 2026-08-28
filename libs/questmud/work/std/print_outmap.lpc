// coded by C

#define VMAP	"/room/out/outmap"
#define OUTPUT  "/log/OUTMAP_DATA"

void get_map() {
  int i, length, written_lines;
  string *mapdata, line;
  mapdata = VMAP->query_mapdata();
  length = strlen(mapdata[0]);
  write("SIZE: "+sizeof(mapdata)+", LENGTH: "+length+"\n");
  for(i = 0; i < sizeof(mapdata) - 1; i++) {
    written_lines += write_file(OUTPUT, mapdata[i]);  
  }

  write("Done. Lines written "+written_lines+" (loop through "+i+")\n");
}
