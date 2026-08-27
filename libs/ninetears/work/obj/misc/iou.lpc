inherit "/std/object";
string stat();
inherit "/global/auto_load";
mixed auto_string;
string file; //Raskolnikov
#define ETP this_player()
void setup()
{
    set_name("iou");
    add_alias("IOU");
    set_short("IOU");
    set_long("Esto es un IOU, un objeto que por alguna razon se ha quitado del juego, bien puede ser un objeto retirado "+
	"o un objeto que tenga un bug y este siendo reparado\n"+
      "\"reclamar\" intenta recuperar el objeto si ya ha sido puesto en juego otra vez.\n"+
      "\"inspeccionar iou\" para intentar averiguar de que objeto se trata.\n");
}
string stat()
{
    string *path;
    if(!sizeof(auto_string)) return "Nada, algo sin ningun tipo de uso.. tiralo.\n";
    path = explode(auto_string[1],"/");
    if(sizeof(path) < 3) return "Something wierd wat mortal man was not meant to mess with.\n";
    switch(path[0] )
    {
    case "w":
	call_out("dest_me",2,0);
	return "Un objeto perteneciente a los Dioses que no deberia estar en manos de un simple mortal.\n";
	break;
    case "d":
	return "Es un objeto del domionio "+path[1]+" y su nombre es: "+path[sizeof(path)-1]+"\n";
    default:
	return "Es un objeto generico llamado : "+path[sizeof(path)-1]+"\n";
	break;
    }
    return "Que me maten si se que es eso!.\n";
}
mapping query_static_auto_load()
{
    return (["auto_string":auto_string]);
}
void init_static_arg(mapping stuff)
{
    auto_string = stuff["auto_string"];
}
void init()
{
    add_action("try_loading","reclamar");
    add_action("inspect","inspeccionar");
}
mixed add_auto_string(mixed str)
{
    auto_string = str;
    return auto_string;
}
mixed add_object(object ob)
{
    auto_string = create_auto_load( ({ob }) );
    return auto_string;
}
int inspect(string str)
{
    if(str == "iou" || str == "IOU") 
    {
	write(stat());
    }
    notify_fail("O.K. you've looked at everything closely now.\n");
    return 0;
}
int try_loading(string str)
{
    object *olist;
    notify_fail("Nothing happens.\n");
    if(auto_string)
    {
	olist = load_auto_load(auto_string,ETP);
	if(sizeof(olist))
	{
	    write("Un pequenyo demonio aparece y sale corriendo con tu IOU.\n");
	}
    }
    dest_me();
    return 1;
}

// By Radix
int query_iou_object() { return 1; }

//Raskolnikov added the next 2
string query_path() {
    string *old_path;
    old_path = explode(auto_string[1], "/");
    file = old_path[sizeof(old_path)-1];
    old_path -= ({ file });
    return "/"+implode(old_path, "/");
}

string query_file() {
    query_path();
    return file;
}
