// Generic line parser to keep server/clients synced.
// This file should be #included! NOT inheritted. I chose to do
// it this way so that I wouldn't have to use this_object()->parse_line()
// so I could save some CPU time.
// Set unparsed_data = "" just before socket_create()

string unparsed_data;

void parse_line(int fd, string msg);


void receive_data(int fd, string msg)
{
   string parse, rest;

//log("RCV: "+fd+"\n"+msg+"\n");
   unparsed_data += msg;

   while(sscanf(unparsed_data,"%s\n%s",parse,rest) == 2)
   {
      unparsed_data = rest;
      parse_line(fd, parse);
   }
}
