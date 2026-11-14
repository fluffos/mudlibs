inherit "/std/thing";
#include <secure/wizlevels.h>

void create() {
  ::create();
  AddId("editor");
}

mapping newmacros;

void edit(string input, string *lines, int line, int echo, 
          string *buffer, object user);
void change_line(string arg, string *lines, int line, int echo, 
                 string *buffer, object user);
void remove_line(string *lines, int line, int echo, 
                 string *buffer, object user);
void delete_lines(string arg, string *lines, int line, int echo, 
                  string *buffer, object user);
void clear_buffer(string *lines, int line, int echo,
                  string *buffer, object user);
void toggle_echo(string arg, string *lines, int line, int echo,
                 string *buffer, object user);
void help(string arg, string *lines, int line, int echo,
          string *buffer, object user);
void include_file(string arg, string *lines, int line, int echo,
                  string *buffer, object user);
void print_lines(string arg, string *lines, int line, int echo,
                 string *buffer, object user);
void quit(string *lines, int line, int echo, string *buffer, object user);
void redisplay(string *lines, int line, int echo, string *buffer, object user);
void substitute(string arg, string *lines, int line, int echo,
                string *buffer, object user);
void write_lines(string arg, string *lines, int line, int echo,
                string *buffer, object user);
void indent(string arg, string *lines, int line, int echo,
                string *buffer, object user);
void insert_buffer(string *lines, int line, int echo,
                string *buffer, object user);
void not_implemented(string *lines, int line, int echo,
                     string *buffer, object user);

void get_desc(string input, string *lines, int line, int echo,
              string *buffer, object user) {
     string newline, *newbuffer;
     newline = input;
     newbuffer = buffer;
     if (input && input ==".") {
        newbuffer[sizeof(newbuffer)-1] =
                 newbuffer[sizeof(newbuffer)-1][0..<3] + ");\n";
        insert_buffer(lines, line, echo, newbuffer, user);
        return;
     }
     if (!newline && newline =="") newline = "\n";
     else newline = "\""+input+"\\n\"+\n";
     write("@");
     newbuffer += ({newline});
     input_to("get_desc", echo, lines, line, echo, newbuffer, user); 
}

void one_arg(string arg, string *lines, int line, int echo,
              string *buffer, object user) {
     string *newbuffer;
     write(arg+"\n");
     newbuffer = ({arg+"\n"});
     insert_buffer(lines, line, echo, newbuffer, user);
}

void two_args(string arg, string *lines, int line, int echo,
              string *buffer, object user) {
     string *newbuffer;
     write(arg+"\n");
     newbuffer = ({arg+"\n"});
     write("Write the description. Type '.' when finished\n@");
     input_to("get_desc", echo, lines, line, echo, newbuffer, user);
}

string get_header(string str, object who) {
   string name;
   if (who) name = capitalize(who->QueryRealName());
   else name = "Someone";
   return "/* "+str+" made by "+name+" on "+ctime(time())+". */\n";
}

/* Make room */
void mkr(string arg, string *lines, int line, int echo,
         string *buffer, object user) {
     string *newbuffer, inh;
     if (!arg || arg=="") inh = "/std/room"; else inh = arg;
     newbuffer = ({ get_header("Room", user) });
     newbuffer += ({"inherit \""+inh+"\";\n", "\n"});
     newbuffer += ({"#include <rooms.h>\n"});
     newbuffer += ({"#include <doors.h>\n"});
     newbuffer += ({"\n", "void create() {\n", "  ::create();\n"});
     write("Creating a room...\n");
     insert_buffer(lines, line, echo, newbuffer, user);
}

/* Make monster */
void mkm(string arg, string *lines, int line, int echo,
         string *buffer, object user) {
     string *newbuffer, inh;
     if (!arg || arg=="") inh = "/std/npc"; else inh = arg;
     newbuffer = ({ get_header("Monster", user) });
     newbuffer += ({"inherit \""+inh+"\";\n", "\n"});
     newbuffer += ({"#include <combat.h>\n"});
     newbuffer += ({"#include <properties.h>\n"});
     newbuffer += ({"\n", "void create() {\n", "  ::create();\n"});
     write("Creating a monster...\n");
     insert_buffer(lines, line, echo, newbuffer, user);
}

/* Make armour */
void mka(string arg, string *lines, int line, int echo,
         string *buffer, object user) {
     string *newbuffer, inh;
     if (!arg || arg=="") inh = "/std/armour"; else inh = arg;
     newbuffer = ({ get_header("Armour", user) });
     newbuffer += ({"inherit \""+inh+"\";\n", "\n"});
     newbuffer += ({"#include <combat.h>\n"});
     newbuffer += ({"#include <propeties.h>\n"});
     newbuffer += ({"\n", "void create() {\n", "  ::create();\n"});
     write("Creating an armour...\n");
     insert_buffer(lines, line, echo, newbuffer, user);
}

/* Make weapon */
void mkw(string arg, string *lines, int line, int echo,
         string *buffer, object user) {
     string *newbuffer, inh;
     if (!arg || arg=="") inh = "/std/weapon"; else inh = arg;
     newbuffer = ({ get_header("Weapon", user) });
     newbuffer += ({"inherit \""+inh+"\";\n", "\n"});
     newbuffer += ({"#include <combat.h>\n"});
     newbuffer += ({"#include <properties.h>\n"});
     newbuffer += ({"\n", "void create() {\n", "  ::create();\n"});
     write("Creating a weapon...\n");
     insert_buffer(lines, line, echo, newbuffer, user);
}

/* Make thing */
void mkt(string arg, string *lines, int line, int echo,
         string *buffer, object user) {
     string *newbuffer, inh;
     if (!arg || arg=="") inh = "/std/thing"; else inh = arg;
     newbuffer = ({ get_header("Item", user) });
     newbuffer += ({"inherit \""+inh+"\";\n", "\n"});
     newbuffer += ({"#include <properties.h>\n"});
     newbuffer += ({"\n", "void create() {\n", "  ::create();\n"});
     write("Creating a thing...\n");
     insert_buffer(lines, line, echo, newbuffer, user);
}

void adetail(string arg, string *lines, int line, int echo, 
             string *buffer, object user) {
     string *newbuffer;
     if (!arg) arg = "nothing";
     if (strlen(arg)>1 && arg[0..1] == "({") {
         write("  AddDetail("+arg+", \n");
         newbuffer = ({"  AddDetail("+arg+", \n"});
     }
     else {
         write("  AddDetail(\""+arg+"\", \n");
         newbuffer = ({"  AddDetail(\""+arg+"\", \n"});
     }
     write("Write the description. Type '.' when finished\n@");
     input_to("get_desc", echo, lines, line, echo, newbuffer, user);
}

void adoor(string arg, string *lines, int line, int echo, 
           string *buffer, object user) {
     write("Not implemented.\n]");
     input_to("edit", echo, lines, line, echo, buffer, user);
}

void list_macros(string pat, mapping macros) {
     string text, *keys, *aus;
     int i;
     keys = m_indices(macros);
     if (!pat || pat=="") aus = keys;
     else {
       aus = ({});
       for (i=0; i<sizeof(keys); i++)
           if (pat == "/lib/string"->ladjcut(keys[i], strlen(pat)))
              aus += ({keys[i]});
     }
     text = "Defined macros are:\n";
     for (i=0; i<sizeof(aus); i++)
         text += aus[i]+": " + macros[aus[i], 0] + "\n";
     "/lib/string"->smore(text,(int)this_player()->QueryPageSize());
}

void get_num(string arg, string mar, string extra) {
     string *valid;
     int x;
     valid = ({ "1", "2", "3" });
     if (!arg || member(valid, arg) < 0) {
        write("Not a valid number. Enter 1, 2, or 3 ");
        input_to("get_num", 0, mar);
        return;
     }
     x = to_int(arg);
     write("Adding macro '"+mar+"' as \n");
     write(extra+"\n");
     newmacros += ([ mar: extra; x ]);
}

void get_string(string arg, string mar) {
     if (!arg || arg=="") {
        write(
        "Enter a string that should be inserted when using macro '"+
        mar+"'.\n");
        input_to("get_string", 0, mar);
        return;
     }
     write("Give a number for the kind of macro (1/2/3) ");
     input_to("get_num", 0, mar, arg);
}

void yes_or_no(string arg, string mar) {
   if (arg == "y" || arg == "Y" || arg == "yes" || arg == "Yes") {
      write("Replacing macro '" + mar +"'.\n");
      write("Enter a string that should be inserted when using macro '"+
       mar + "'.\n");
       input_to("get_string", 0, mar);
       return;
   }
   write("Okay. Keeping macro '" + mar + ".\n");
}

int macro(string arg) {
    string *keys;
    if (!arg || strlen(arg) < 3) {
       notify_fail("Argument must be at least 3 characters long.\n");
       return 0;
    }
    if (!newmacros) newmacros = ([]);
    keys = m_indices(newmacros);
    if (member(keys, arg) > -1) {
       write("Macro exists. Replace it with new one? (y/n) ");
       input_to("yes_or_no", 0, arg);
       return 1;
    }
    write("Enter a string that should be inserted when using macro '"+
     arg + "'.\n");
    input_to("get_string", 0, arg);
    return 1;
}

void do_special(string input, string *lines, int line, int echo,
                string *buffer, object user) {
     string rest, comm, *valid1, *valid2;
     int commnum;
     mapping spec;
     spec = ([ "ssh": "  SetShort(\"@ARG@\");";           1,
               "slo": "  SetLong(";                       2,
               "aid": "  AddId(\"@ARG@\");";              1,
               "swe": "  SetWeight(@ARG@);";              1,
               "sva": "  SetValue(@ARG@);";               1,
               "sis": "  SetIntShort(\"@ARG@\");";        1,
               "sil": "  SetIntLong(";                    2,
               "aex": "  AddExit(@ARG@);";                1,
               "arc": "  AddRoomCmd(@ARG@);";             1,
               "ait": "  AddItem(@ARG@);";                1,
               "aad": "  AddAdjective(\"@ARG@\");";       1,
               "cr1": "void create() {";                  1,
               "cr2": "  ::create();";                    1,
               "in1": "void init() {";                    1,
               "in2": "  ::init();";                      1,
               "re1": "void reset() {";                   1,
               "re2": "  ::reset();";                     1,
               "sme": "  SetIntSmell(";                   2,
               "noi": "  SetIntNoise(";                   2,
               "sin": "  SetIndoors(@ARG@);";             1,
               "ssm": "  SetSmell(";                      2,
               "sno": "  SetNoise(";                      2,
               "inf": "  SetInfo(";                       2,
               "sle": "  SetLevel(@ARG@);";               1,
               "sre": "  SetRace(@ARG@);";                1,
               "sge": "  SetGender(@ARG@);";              1,
               "sna": "  SetName(\"@ARG@\");";            1,
               "ach": "  InitAChats(@ARG@, ";         1,
               "cha": "  InitChats(@ARG@, ";               1,
               "han": "  SetHands(@ARG@);";               1,
               "dex": "  SetDex(@ARG@);";                 1,
               "str": "  SetStr(@ARG@);";                 1,
               "int": "  SetInt(@ARG@);";                 1,
               "con": "  SetCon(@ARG@);";                 1,
               "ali": "  SetAlign(@ARG@);";               1,
               "agg": "  SetAggressive(@ARG@);";          1,
               "sac": "  SetAC(@ARG@);";                  1,
               "swc": "  SetWC(@ARG@);";                  1,
               "sxp": "  SetXP(@ARG@);";                  1,
               "shp": "  SetHP(@ARG@);";                  1,
               "ssp": "  SetSP(@ARG@);";                  1,
               "smh": "  SetMaxHP(@ARG@);";               1,
               "sms": "  SetMaxSP(@ARG@);";               1,
               "swt": "  SetWeaponType(@ARG@);";          1,
               "sdt": "  SetDamType(@ARG@);";             1,
               "swh": "  SetWeaponHands(@ARG@);";         1,
               "sta": "  SetStandard(@ARG@);";            1,
               "hit": "  SetHitObj(@ARG@);";              1,
               "wie": "  SetWieldObj(@ARG@);";            1,
               "sat": "  SetArmourType(@ARG@);";          1,
               "sde": "  SetDefence(@ARG@);";             1,
               "def": "  SetDefendObj(@ARG@);";           1,
               "rem": "  SetRemoveObj(@ARG@);";           1,
               "wea": "  SetWearObj(@ARG@);";             1,
               "adr": "  AddDrink(@ARG@);";               1,
               "afo": "  AddFood(@ARG@);";                1,
               "men": "  SetMenuString(";                 2,
               "ssn": "  SetShopName(\"@ARG@\");";        1,
               "sad": "  SetAddDesc(";                    2,
               "ssf": "  SetShopkeeperFile(\"@ARG@\");";  1,
               "fli": "  ForbidList();";                  1,
               "fid": "  ForbidIdentify();";              1,
               "fap": "  ForbidAppraise();";              1,
               "fse": "  ForbidSell();";                  1,
               "fbu": "  ForbidBuy();";                   1,
               "alt": "  AllowLivingTrade();";            1,
               "ndb": "  NoDustBin();";                   1,
               "aar": "  AddArticle(@ARG@);";             1,
               "asa": "  AddSpecialArticle(@ARG@);";      1,
               "sfk": "  SetFoodKind(\"@ARG@\\n\");";     1,
               "sf1": "  SetFoodMsg1(\"@ARG@\\n\");";     1,
               "sf2": "  SetFoodMsg2(\"@ARG@\\n\");";     1,
               "stu": "  SetFoodStuff(@ARG@);";           1,
               "soa": "  SetFoodSoak(@ARG@);";            1,
               "sfa": "  SetFoodAlc(@ARG@);";             1,
               "svn": "  Set_Vessel_Name(\"@ARG@\");";    1,
               "sdn": "  Set_Drink_Name(\"@ARG@\");";     1,
               "svo": "  Set_Vessel_Volume(@ARG@);";      1,
               "svw": "  Set_Vessel_Weight(@ARG@);";      1,
               "aac": "  add_action(@ARG@);";             1 ]);
     if (newmacros) spec += newmacros;
     valid1 = m_indices(spec);
     valid2 = ({"mkr", "mkm", "mka", "mkw", "mkt", "ado", "ade", "mac"});
     if (strlen(input) < 4) { 
        write("No valid command.\n");
        input_to("edit", echo, lines, line, echo, buffer, user);
        write("]");
        return;
     }
     comm = input[1..3];
     if (strlen(input) > 4) rest = input[4..]; else rest = "";
     if (rest[0..0] == " ") rest = rest[1..];
     commnum = member(valid1, comm);
     if (commnum > -1) {
        int kind;
        string para, argum;
        kind = spec[valid1[commnum], 1];
        para = spec[valid1[commnum], 0];
        argum = "/lib/string"->string_replace(para, "@ARG@", rest);
        if (kind==2) two_args(argum, lines, line, echo, buffer, user);
        else one_arg(argum, lines, line, echo, buffer, user); 
        return;
     }
     commnum = member(valid2, comm);
     if (commnum < 0) {
        write("No such command '"+comm+"'.\n");
        input_to("edit", echo, lines, line, echo, buffer, user);
        write("]");
        return;
     }
     switch (commnum) {
        case 0: mkr(rest, lines, line, echo, buffer, user); break;
        case 1: mkm(rest, lines, line, echo, buffer, user); break;
        case 2: mka(rest, lines, line, echo, buffer, user); break;
        case 3: mkw(rest, lines, line, echo, buffer, user); break;
        case 4: mkt(rest, lines, line, echo, buffer, user); break;
        case 5: adoor(rest, lines, line, echo, buffer, user); break;
        case 6: adetail(rest, lines, line, echo, buffer, user); break;
        case 7: list_macros(rest, spec); break;
        default: not_implemented(lines, line, echo, buffer, user);
     }
}

void do_command(string input, string *lines, int line, int echo, 
                string *buffer, object user) {
     string rest, comm, *valid;
     int commnum;
     valid=({"a", "b", "c", "d", "e", "h", "i", "p", "q", "r", "s", "w", 
             "t", "y"});
     if (strlen(input) < 2) { 
        write("No valid command.\n");
        input_to("edit", echo, lines, line, echo, buffer, user);
        write("]");
        return;
     }
     comm = input[1..1];
     if (strlen(input) > 2) rest = input[2..]; else rest = "";
     commnum = member(valid, comm);
     if (commnum < 0) {
        write("No such command '"+comm+"'.\n");
        input_to("edit", echo, lines, line, echo, buffer, user);
        write("]");
        return;
     }
     switch(commnum) {
         case 0: change_line(rest, lines, line, echo, buffer, user); break;
         case 1: remove_line(lines, line, echo, buffer, user); break;
         case 2: clear_buffer(lines, line, echo, buffer, user); break;
         case 3: delete_lines(rest, lines, line, echo, buffer, user); break;
         case 4: toggle_echo(rest, lines, line, echo, buffer, user); break;
         case 5: help(rest, lines, line, echo, buffer, user); break;
         case 6: include_file(rest, lines, line, echo, buffer, user); break;
         case 7: print_lines(rest, lines, line, echo, buffer, user); break;
         case 8: quit(lines, line, echo, buffer, user); break;
         case 9: redisplay(lines, line, echo, buffer, user); break;
         case 10: substitute(rest, lines, line, echo, buffer, user); break;
         case 11: write_lines(rest, lines, line, echo, buffer, user); break;
         case 12: indent(rest, lines, line, echo, buffer, user); break;
         case 13: insert_buffer(lines, line, echo, buffer, user); break;
         default: not_implemented(lines, line, echo, buffer, user);
     }
}

void not_implemented(string *lines, int line, int echo,
                     string *buffer, object user) {
     write("Not implemented yet.\n]");
     input_to("edit", echo, lines, line, echo, buffer, user);
}

int start_ed(string name, object user) {
  int echo, line, i;
  string *lines, *buffer, temp;
  lines = ({});
  buffer = ({});
  echo = 0;
  if (file_size(name) > 0) {
     temp = read_file(name, 0, 1000);
     lines = explode(temp , "\n");
     for (i=0; i<sizeof(lines); i++) lines[i] += "\n";
  }
  line = sizeof(lines);
  write("Editing ...    ~h for help    ~q cancel    ** or . to end\n]");
  input_to("edit", echo, lines, line, echo, buffer, user);
  return 1;
}

void end_edit(string *lines, object user) {
  write("We finally reached the end ...\n");
}

void edit(string input, string *lines, int line, int echo, 
          string *buffer, object user) {
    string *start, *rest, *temp, newline;
    int actline, num, i;
    if (input && input!="" && input[0..0]=="~") {
       do_command(input, lines, line, echo, buffer, user);
       return;
    }
    if (input && input!="" && input[0..0]=="#") {
       do_special(input, lines, line, echo, buffer, user);
       return;
    }
    if (input == "." || input =="**") {
       end_edit(lines, user);
       return;
    }
    num = sizeof(lines);
    if (input) newline = input+"\n"; else newline = "\n";
    if (line > num) actline = num;
    else actline = line;
    if (actline > 0) start = lines[0..actline-1]; else start = ({});
    if (num > actline) rest = lines[actline..num-1]; else rest = ({});
    temp = start + ({newline}) + rest;
    // for (i=0; i<sizeof(temp); i++) write(temp[i]);
    write("]");
    input_to("edit", echo, temp, actline+1, echo, buffer, user);
}


void help(string arg, string *lines, int line, int echo,
          string *buffer, object user) {
  write("Help:\n\
~p<num1>,<num2> print lines num1 - num2        ~q cancel\n\
~d<num1>,<num2> delete lines num1 - num2       ~r redisplay\n\
~a<line> insert after line <line>              ~h help\n\
~s<str1>,<str2> substitute all patterns        ~y insert buffer\n\
  matching <str1> by <str2>                    ~c clear buffer\n");
  if (IS_WIZARD(user)) write(""+
"~w<num1>,<num2>,<file> writes lines num1 -     ~i<file> include a file\n\
 num 2 to file <file>                           ~b kill last line\n");
  write("~t<num1>,<num2>,<num3>  insert <num3> blanks at the beginnig of\n\
  the lines <num1> to <num2>.\n");
  write(""+
"~e<on|off> turn the echo on/off. If you turn it off it means that others\n\
who might snoop you won't see what you type, but you wont see it either.\n\
So you will have to type 'blind'.\n");
  write("]");
  input_to("edit", echo, lines, line, echo, buffer, user);
}

void change_line(string arg, string *lines, int line, int echo,
                 string *buffer, object user) {
     int num;
     num = to_int(arg);
     num -= 1;
     if (num < 0 || num > sizeof(lines)) {
        num += 1;
        write("No such line "+num+".\n]");
        input_to("edit", echo, lines, line, echo, buffer, user);
        return;
     }
     write("]");
     input_to("edit", echo, lines, num+1, echo, buffer, user);
}

void remove_line(string *lines,int line,int echo,string *buffer,object user) {
     string *start, *rest, *temp, *newbuffer;
     int actline, i;
     actline = line;
     if (sizeof(lines) < 1) {
        input_to("edit", echo, lines, line, echo, buffer, user);
        return;
     }
     if (actline<1 && actline>sizeof(lines)) actline = sizeof(lines);
     if (actline > 1) start = lines[0..actline-2];
     else start = ({});
     if (sizeof(lines) >= actline) rest = lines[actline..];
     else rest = ({});
     temp = start + rest;
     // for (i=0; i<sizeof(temp); i++) write(temp[i]);
     newbuffer = ({lines[actline-1]});
     write("]");
     input_to("edit", echo, temp, actline-1, echo, newbuffer, user);
}

void clear_buffer(string *lines,int line,int echo,string *buffer,object user) {
     write("Cleared buffer\n]");
     input_to("edit", echo, lines, line, echo, ({}), user);
}

void delete_lines(string arg, string *lines, int line, int echo,
                  string *buffer, object user) {
     string a, b, *temp, *newlines;
     int anf, ende;
     if (sscanf(arg, "%s,%s", a, b) < 2) {
         anf = to_int(arg);
         if (anf < 1 || anf > sizeof(lines)) {
            write("No such line '"+anf+"'.\n]");
            input_to("edit", echo, lines, line, echo, buffer, user);
            return;
         }
         write(lines[anf]);
         input_to("edit", echo, lines, line, echo, buffer, user);
         return;
     }
     anf = to_int(a);
     ende = to_int(b);
     if (anf > sizeof(lines) || anf < 1)
        anf = sizeof(lines);
     if (ende < anf) ende = anf;
     if (ende > sizeof(lines)) ende = sizeof(lines);
     temp = lines[anf-1..ende-1];
     newlines = lines - temp;
     write("]");
     input_to("edit", echo, newlines, sizeof(newlines), echo, temp, user);
}

void toggle_echo(string arg, string *lines, int line, int echo,
                  string *buffer, object user) {
     int newecho;
     if (arg == "off") {
        newecho = 0;
        write("Turning echo off.\n");
     }
     else {
        newecho = 1;
        write("Turning echo on.\n");
     }
     write("]");
     input_to("edit", newecho, lines, line, newecho, buffer, user);
}

void include_file(string arg, string *lines, int line, int echo,
                  string *buffer, object user) {
     string temp, file, path, fname, *newbuff, *words;
     int i;
     if (!IS_WIZARD(user)) {
        write("No such command 'i'.\n]");
        input_to("edit", echo, lines, line, echo, buffer, user);
        return;
     }
     if (!arg) {
        write("i<file>!\n]");
        input_to("edit", echo, lines, line, echo, buffer, user);
        return;
     }
     words = explode(arg, "/");
     if (sizeof(words)<2) {
        temp = "/players/"+user->QueryRealName()+"/"+arg;
        words = explode(temp, "/");
     }
     file = words[sizeof(words)-1];
     words -= ({file});
     path = implode(words, "/");
     if (!temp = user->is_dir(path)) {
        write("No such directory: "+path+"\n]");
        input_to("edit", echo, lines, line, echo, buffer, user);
        return;
     }
     fname = path + "/" + file;
     if (file_size(fname)<1) { 
        write("No such file: "+fname+"\n]");
        input_to("edit", echo, lines, line, echo, buffer, user);
        return;
     }
     write("Including "+fname+".\n");
     temp = read_file(fname, 0, 1000);
     newbuff = explode(temp, "\n");
     for (i=0; i<sizeof(newbuff); i++) newbuff[i] += "\n";
     insert_buffer(lines, line, echo, newbuff, user);
}

void print_lines(string arg, string *lines, int line, int echo,
                 string *buffer, object user) {
     string a, b, *temp;
     int anf, ende, i;
     if (sscanf(arg, "%s,%s", a, b) < 2) {
         anf = to_int(arg);
         if (anf < 1 || anf > sizeof(lines)) {
            write("No such line '"+anf+"'.\n]");
            input_to("edit", echo, lines, line, echo, buffer, user);
            return;
         }
         write(lines[anf-1]);
         input_to("edit", echo, lines, line, echo, buffer, user);
         return;
     }
     anf = to_int(a);
     ende = to_int(b);
     if (anf > sizeof(lines) || anf < 1)
        anf = sizeof(lines);
     if (ende < anf) ende = anf;
     if (ende > sizeof(lines)) ende = sizeof(lines);
     temp = lines[anf-1..ende-1];
     for (i=0; i<sizeof(temp); i++) write(temp[i]);
     write("]");
     input_to("edit", echo, lines, line, echo, buffer, user);
}

string spaces(int anz) {
   string ret;
   int i;
   ret = "";
   for (i=0; i<anz; i++) ret += " ";
   return ret;
}

void indent(string arg, string *lines, int line, int echo,
                string *buffer, object user) {
     string a, b, c;
     int anf, ende, anz, i;
     if (sscanf(arg, "%s,%s,%s", a, b, c) < 3) {
         anf = to_int(arg);
         if (anf < 1 || anf > sizeof(lines)) {
            write("No such line '"+anf+"'.\n]");
            input_to("edit", echo, lines, line, echo, buffer, user);
            return;
         }
         anz = to_int(b);
         if (!anz || anz<1) anz = 3;
         lines[anf-1] = spaces(anz) + lines[anf-1];
         input_to("edit", echo, lines, line, echo, buffer, user);
         return;
     }
     anf = to_int(a);
     ende = to_int(b);
     anz = to_int(c);
     if (!anz || anz < 1) anz = 3;
     if (anf > sizeof(lines) || anf < 1)
        anf = sizeof(lines);
     if (ende < anf) ende = anf;
     if (ende > sizeof(lines)) ende = sizeof(lines);
     for (i=anf-1; i<ende; i++) lines[i] = spaces(anz) + lines[i];
     write("]");
     input_to("edit", echo, lines, line, echo, buffer, user);
}

void cancel(string input, string *lines, int line, int echo, 
            string *buffer, object user) {
     if (input=="y" || input=="Y" || input=="yes" || input=="Yes") {
        write("Cancel...\n");
        lines = ({});
        end_edit(lines, user);
        return;
     }
     write("Not cancelling...\n");
     input_to("edit", echo, lines, line, echo, buffer, user);
}

void quit(string *lines, int line, int echo, string *buffer, object user) {
     if (sizeof(lines)) {
        write("Really cancel? ");
        input_to("cancel", echo, lines, line, echo, buffer, user);
        return;
     }
     write("Cancel...\n");
     lines = ({});
     end_edit(lines, user);
}

void redisplay(string *lines, int line, int echo,
               string *buffer, object user) {
     int i;
     write("So far you wrote:\n");
     for (i=0; i<sizeof(lines); i++) write(lines[i]);
     write("]");
     input_to("edit", echo, lines, line, echo, buffer, user);
}

void substitute(string arg, string *lines, int line, int echo,
                 string *buffer, object user) {
     int i;
     string *temp, find, repl;
     if (sscanf(arg, "%s,%s", find, repl) < 2) {
        write("Wrong arguments.\n]");
        input_to("edit", echo, lines, echo, buffer, user);
        return;
     }
     temp = lines;
     for (i=0; i<sizeof(temp); i++) 
         if (sizeof(regexp( ({lines[i]}), find)))
            temp[i] = "/lib/string"->string_replace(lines[i], find, repl);
     write("]");
     input_to("edit", echo, temp, line, echo, buffer, user);
}

void write_lines(string arg, string *lines, int line, int echo,
                 string *buffer, object user) {
     string a, b, c, *temp;
     int anf, ende, i;
     if (!IS_WIZARD(user)) {
        write("No such command 'w'.\n]");
        input_to("edit", echo, lines, line, echo, buffer, user);
        return;
     }
     if (sscanf(arg, "%s,%s,%s", a, b, c) < 3) {
         write("Wrong number of arguments.\n]");
         input_to("edit", echo, lines, line, echo, buffer, user);
         return;
     }
     anf = to_int(a);
     ende = to_int(b);
     if (anf > sizeof(lines) || anf < 1)
        anf = sizeof(lines);
     if (ende < anf) ende = anf;
     if (ende > sizeof(lines)) ende = sizeof(lines);
     temp = lines[anf-1..ende-1];
     for (i=0; i<sizeof(temp); i++) write_file(c, temp[i]);
     write("Written lines "+anf+" - "+ende+" to file: "+c+".\n]");
     input_to("edit", echo, lines, line, echo, buffer, user);
}

void insert_buffer(string *lines, int line, int echo,
                 string *buffer, object user) {
     int actline, num;
     string *temp, *rest, *start;
     num = sizeof(lines);
     if (line > num) actline = num;
     else actline = line;
     if (actline > 0) start = lines[0..actline-1]; else start = ({});
     if (num > actline) rest = lines[actline..num-1]; else rest = ({});
     actline += sizeof(buffer);
     temp = start + buffer + rest;
     write("Inserted ...\n]");
     input_to("edit", echo, temp, actline, echo, buffer, user);
   }
