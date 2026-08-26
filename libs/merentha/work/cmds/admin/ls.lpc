// Petrarch
// Merentha Lib 1.0
// <ls>

varargs int command(string dir) {
string *files, *dirs=({});
int i,j,max;
  if(!dir) dir=this_player()->query_cwd();
  if(dir[0..0]!="/") dir=this_player()->query_cwd()+dir;
  if(file_size(dir)==-1) return notify_fail("Syntax: ls <file>\nFile not found.\n");
  if(file_size(dir)==-2 && dir[<1..] != "/") dir+="/";
  files=get_dir(dir);
  i=sizeof(files);
  while(i--)
      if(file_size(dir+files[i])==-2) dirs+=({files[i]});
  files-=dirs;
  dirs=sort_array(dirs, 1);
  files=sort_array(files, 1);
  i=sizeof(dirs);
  max=1;
  while(i--) {
    dirs[i]="    "+dirs[i]+"/";
    if(strlen(dirs[i])>max) max=strlen(dirs[i]);
  }
  i=sizeof(files);
  while(i--) {
     j=file_size(dir+files[i]);
     if(j/1024)j=j/1024;
     else j=1;
     files[i]=arrange_string(""+(j<10?"  ":(j<100?" ":""))+j,3)+" "+files[i];
     if(strlen(files[i])>max) max=strlen(files[i]);
  }
  max+=3;
  i=this_player()->getenv("SCREEN");
  if(!i) i=75;
  max=i/max;
  dirs+=files;
  i=sizeof(dirs)/max;
  while (i > 0) {
    i-=max;
    message("system", format_page(dirs[0..max-1],max), this_player());
    dirs=dirs[max..<1];
  }
  if(sizeof(dirs)) message("system", format_page(dirs,max), this_player());
  return 1;
}

string help() {
return "Syntax: ls <directory>\n\nDisplays the directory content of the given input directory.  Displays the current working directory if no input is given.";
}
