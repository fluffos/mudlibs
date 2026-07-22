// Board Remote Console
// ÁôÑÔ°æÖÕ¶ËÌ¨
// creator: fuyo@XAJH creat time: 1997.11
// modify by fan modify time: 98-2-8

inherit COMBINED_ITEM;
//inherit ITEM;

#define BOARD_PATH "/d/board/"

nosave string *bname;

void get_board_text(mapping mail, string str);
int getbname();
int do_view(string arg);
int do_read(string arg);
int do_post(string arg);
int do_discard(string arg);
//for autoload
void set_amount(int v);
int query_autoload();

void create()
{
       set_name("ÁôÑÔ°æÖÕ¶ËÌ¨", ({ "Remote Board Console","RBC","rbc","console"}) );
       set("unit", "¸ö");
       set("no_drop", "1");
       set("no_get","1");
       set("base_unit","¸ö");
       set_amount(1);
       seteuid(ROOT_UID);
}

string long()
{
       int i;
       int size;
       string ttp,names;

       if ( !(size=getbname())) return 0;
       names="Board ID            Board Name\n";
       names+="-------------------------------------------------------------------\n";
       for(i=0;i<size;i++) {
               sscanf(bname[i],"%s.c",ttp);
               names+=sprintf("%-20s%s\n", ttp, (BOARD_PATH+bname[i])->short() );
       }
	names+="-------------------------------------------------------------------\n";
	names+=sprintf(MUD_NAME+"µ±Ç°ÁôÑÔ°åÊýÁ¿Îª£º%d¡£\n\n    Commands: viewb readb postb discardb \n\n",size);
       return names;
}

void init()
{
       object ob=this_player();
       bname=allocate(40);
       if( ob && environment()==ob && wizardp(ob) ) {
               add_action("do_view","viewb");
               add_action("do_read", "readb");
               add_action("do_post", "postb");
               add_action("do_discard", "discardb");
       }
}
 
int do_view(string arg)
{
       int i;
       int size;
       string ttp;

       if ( !(size=getbname())) return 0;
       
       if(!arg) {
               for(i=0;i<size;i++) {
                       sscanf(bname[i],"%s.c",ttp);
                       printf("%-20s%s", ttp,((BOARD_PATH+bname[i])->short()+"\n"));
               }
       }
       else {
               if ( strsrch(arg,".c") ==-1 )
                       arg=arg+".c";
               if ( member_array(arg,bname) == -1)
                       return notify_fail("ÄãÒªä¯ÀÀ¸öÁôÑÔ°æ£¿\n");
               write((BOARD_PATH+arg)->long()+"\n");                  
       }
       return 1;
}

int do_read(string arg)
{
       int i;
       string *tt;

       if ( !getbname()) return 0;
       
       if ( !arg ) return 0;

       tt = explode(arg," ");
       if ( sizeof(tt)<2 ) 
               return notify_fail("ÁôÑÔ°æÖÕ¶ËÌ¨ÔÄ¶ÁÖ¸Áî¸ñÊ½£ºread <ÁôÑÔ°æÃû³Æ> <ÁôÑÔ±àºÅ>|new|next\n");
       if ( strsrch(tt[0],".c") ==-1 )
               tt[0]=tt[0]+".c";
       
       if ( member_array(tt[0],bname) == -1)
               return notify_fail("ÄãÒªÔÄ¶ÁÄÄ¸öÁôÑÔ°æ£¿\n");
       write((BOARD_PATH+tt[0])->name());
       return (BOARD_PATH+tt[0])->do_read(tt[1]);
}

int do_post(string arg)
{
       int i;
       string *tt;

       if ( !getbname()) return 0;

       if ( !arg ) return 0;
       
       tt = explode(arg," ");
       if ( sizeof(tt)<2 ) 
               return notify_fail("ÁôÑÔ°æÖÕ¶ËÌ¨ÁôÑÔÖ¸Áî¸ñÊ½: post <ÁôÑÔ°æÃû³Æ> <±êÌâ>\n");
       if ( strsrch(tt[0],".c") ==-1 )
               tt[0]=tt[0]+".c";
       
       if ( member_array(tt[0],bname) == -1)
               return notify_fail("ÄãÒªÔÚÄÄ¸öÁôÑÔ°æÁôÑÔ£¿\n");

       return (BOARD_PATH+tt[0])->do_post(tt[1]);
}

int do_discard(string arg)
{
       int i;
       string *tt;

       if ( !getbname()) return 0;
       if ( !arg ) return 0;
       
       tt = explode(arg," ");
       if ( sizeof(tt)<2 ) 
               return notify_fail("ÁôÑÔ°æÖÕ¶ËÌ¨É¾³ýÖ¸Áî¸ñÊ½: discard <ÁôÑÔ°æÃû³Æ> <ÁôÑÔ±àºÅ>\n");
       if ( strsrch(tt[0],".c") ==-1 )
               tt[0]=tt[0]+".c";
       
       if ( member_array(tt[0],bname) == -1)
               return notify_fail("ÄãÒªÔÚÄÄ¸öÁôÑÔ°æÉ¾³ýÁôÑÔ£¿\n");

       return (BOARD_PATH+tt[0])->do_discard(tt[1]);
}

int getbname()
{
       string dir;
       int i,sizeboard;
       mixed *file;
       sizeboard=0;
       dir = BOARD_PATH;

       if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )
               dir += "/";

       file = get_dir(dir, -1);

       if( !sizeof(file)) {
               if (file_size(dir) == -2)
                       return notify_fail("ÁôÑÔ°æÄ¿Â¼ÊÇ¿ÕµÄ¡£\n");
               else
                       return notify_fail("Ã»ÓÐÕâ¸öÄ¿Â¼¡£\n");
       }
       
       for(i=0;i<sizeof(file);i++) {
               if(strsrch(file[i][0],".c")==-1) continue;
               bname[sizeboard++]=sprintf("%s",file[i][0]);
       }

       return sizeboard;
}

// for autoload
void set_amount(int v)
{
       if( v < 0 ) error("combine:set_amount less than 1.\n");
       if ( v==0 ) call_out("destruct_me", 1);
       else { 
               if (v>1) write("Äú½«ÉíÉÏµÄ"+this_object()->name()+"¸üÐÂÁË¡£\n");
               amount = 1;
       }
}

int query_autoload() { 
        return 1;
}

