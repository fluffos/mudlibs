#define FILES 50
#define ASCIID "/obj/daemons/asciid"

string name;
string called_from_ip;

mapping mask;
mapping names;

int current;
int fn;
int maxfn;

void gather();

#define tell_v(x) if(find_player("vertebraker")) tell_object(find_player("vertebraker"), x)

void reset(status arg)
{
  if(arg) return;

  mask = ([]);
  names = ([]);
  fn = -1;

  current = 97;
  call_out("gather", 1);
}

void gather()
{
  string char;
  string *fs;
  int    i, j;
  string th;

  tell_v("entering gather\n");

  char = (string)ASCIID->get_glyph(current); /* <3 */
  
  if(!mask[char])
  {
    mask[char] = ({ });
  }

  restore_object("pfiles/a/aaron");
  tell_v("aaron name: "+name+"\n");
  if(fn == -1)
  {
    tell_v("woot\n");
    fs = get_dir("/pfiles/"+char+"/*.o");
    tell_v("fs: "+sizeof(fs)+"\n");
    maxfn = sizeof(fs);
    fn ++;
  }
  
  for(i = fn; i < maxfn, j < FILES; i ++, j ++, fn ++)
  {
    th = "pfiles/"+char+"/"+fs[fn][0..-3];
    restore_object(th);
    tell_v("#: "+i+" "+name+"\n");
  }
}



  

  

