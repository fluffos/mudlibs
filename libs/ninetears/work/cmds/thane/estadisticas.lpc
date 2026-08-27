#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
 
string colorea(int numero)
{
        switch(numero)
        {
                case 1..3:
                        return ""+numero+"";
                case 4..6:
                        return "%^ORANGE%^"+numero+"%^RESET%^";
                case 7..10:
                        return "%^RED%^"+numero+"%^RESET%^";
                default:
                        return "%^BOLD%^RED%^"+numero+"%^RESET%^";
        }
}
protected int cmd(string tipo, object me) 
{
        object *ob;
        mapping estadistica= ([ ]),gremio= ([ ]),bando= ([ ]),nivel= ([ ]);
        string *cual;
        int i;
        if(!TP->query_creator())
        {
                notify_fail("No deberias jugar con los artefactos de los inmortales.\n");
                TO->dest_me();
                return 0;
        }
        tell_object(TP,"Estadisticas de players:\n\n");
        ob= users();
        for(i=sizeof(ob)-1;i>=0;i--)
        {
                if(ob[i]->query_short() == "logon") 
                  continue;
                if(gremio[tipo= ob[i]->query_guild_name()])
                        gremio[tipo]++;
                else
                        gremio+= ([ tipo:1 ]);
                switch(ob[i]->query_property("bando"))
                {
                        case 1:
                                tipo= "bueno";
                                break;
                        case 2:
                                tipo= "malo";
                                break;
                        case 3:
                                tipo= "drow";
                                break;
                        case 4:
                                tipo= "inmortal";
                                break;
                        default:
                                tipo= "sin bando";
                                break;
                }
                if(bando[tipo])
                        bando[tipo]++;
                else
                        bando+= ([ tipo:1 ]);
                switch(ob[i]->query_level())
                {
                        case 0..5:
                                tipo= "newbies";
                                break;
                        case 6..15:
                                tipo= "novatos";
                                break;
                        case 16..26:
                                tipo= "iniciados";
                                break;
                        case 27..34:
                                tipo= "maestros";
                                break;
                        case 35..45:
                                tipo= "expertos";
                                break;
                        case 46..100:
                                tipo= "viciados";
                                break;
                }
                if(ob[i]->query_creator())
                        tipo= "creador";
                if(nivel[tipo])
                        nivel[tipo]++;
                else
                        nivel+= ([ tipo:1 ]);
                if(ob[i]->query_gender_string()=="blue")
                        continue;
                cual= explode(file_name(environment(ob[i])),"/");
                if(member_array(cual[1],get_dir("/d/"))!=-1 || cual[0]=="w" || cual[0]=="room")
                {
                        if(cual[0]=="room")
                                tipo= "heaven";
                        else
                                tipo= cual[1];
                        if(estadistica[tipo])
                                estadistica[tipo]++;
                        else
                                estadistica+= ([ tipo:1 ]);
                }
        }
        tell_object(this_player(),"--%^BOLD%^RED%^NIVELES%^RESET%^--\n");
        cual= keys(nivel);
        for(i=sizeof(cual)-1;i>=0;i--)
                tell_object(this_player(),cual[i]+": "+colorea(nivel[cual[i]])+" ");
        tell_object(this_player(),"\n--%^YELLOW%^GREMIOS%^RESET%^--\n");
        cual= keys(gremio);
        for(i=sizeof(cual)-1;i>=0;i--)
                tell_object(this_player(),cual[i]+": "+colorea(gremio[cual[i]])+"\n");
        tell_object(this_player(),"--%^BOLD%^BANDOS%^RESET%^--\n");
        cual= keys(bando);
        for(i=sizeof(cual)-1;i>=0;i--)
                tell_object(this_player(),cual[i]+": "+colorea(bando[cual[i]])+" ");
        tell_object(this_player(),"\n--%^BOLD%^GREEN%^DOMINIOS%^RESET%^--\n");
        cual= keys(estadistica);
        for(i=sizeof(cual)-1;i>=0;i--)
                tell_object(this_player(),cual[i]+": "+colorea(estadistica[cual[i]])+"\n");
        return 1;
}
