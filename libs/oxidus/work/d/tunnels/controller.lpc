/**
 * @file /d/village/tunnels/controller
 *
 * Virtual controller  object for the tunnels.
 *
 * @created 2024-08-25 - Gesslar
 * @last_modified 2024-08-25 - Gesslar
 *
 * @history
 * 2024-08-25 - Gesslar - Created
 */

inherit STD_VIRTUAL_SERVER;

private void load_tunnels_map();

private mapping tunnels_map = ([]);

void setup() {
  load_tunnels_map();
}

private void load_tunnels_map() {
  string *lines = explode(read_file(__DIR__ "tunnels_map.txt"), "\n");
  int y = 0, z = 0;
  for(int i = 0; i < sizeof(lines); i += 2) {  // Skip every other line
    string line = lines[i];
    int x = 0;

    for(int j = 0; j < sizeof(line); j += 2) {  // Skip every other character
      string char = line[j..j];

      if(char == "O" || char == "X") {
        tunnels_map[sprintf("%d,%d,%d", x, y, z)] = char;
      }

      x++;
    }
    y++;
  }
}

mapping get_tunnels_map() {
  return tunnels_map;
}

object generate_object(string file) {
  string *parts;
  int x, y, z;

  parts = dir_file(file);

  if(sscanf(parts[1], "%d,%d,%d", x, y, z) != 3)
    return 0;

  object result = new(__DIR__ "tunnels_base", parts[1]);

  result->set_virtual_master(__DIR__ "tunnels_base");

  return result;
}
