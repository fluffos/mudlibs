string workingOn;
string *rooms;

#define FILE "/open/approval/"+workingOn+".txt"

int main(string str)
{
  if(!str && workingOn)
  {
    write("Add what to your writeup?\n");
    return 1;
  }
  if(!workingOn)
  {
    write("Input name to work on: ");
    input_to("getName");
    return 1;
  }
  if(str=="view") { command("dump "+FILE, this_player()); return 1; }
  if(creator(environment(this_player())) == workingOn)
  {
    string fileName;
    fileName = object_name(environment(this_player()));
    sscanf(fileName, "players/"+workingOn+"/%s", fileName);
    fileName = "~/"+fileName;
    write_file(FILE, "["+fileName+"] ");
  }
  write_file(FILE, "-"+str+"\n");
  write("Okay.\n");
  return 1;
}
  
status getName(string str)
{
  if(!str) return main("bleech");
  workingOn = str;
  write("Ok, working on " + str + "\n");
  return 1;
}
