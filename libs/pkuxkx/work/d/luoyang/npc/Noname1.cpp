//专门反机器人的，不可滥用
//Jason 2009/11/08，加入MXP支持，在Mud中直接显示验证图片。
//mxp在pkuxkx的第一个应用。也是唯一在线download的应用
//其他应用应该尽量使用本地包。

#include <mxp.h>
#include <mudlib.h>

#define MXP_SERVICE_STATUS_FILE "/log/mxp_service_status"

int is_stopped = 0;

int check_timeout();
//string* chdict = ({});
//int dict_size = 0;
void create()
{
        string line;
        int i = 0;
    seteuid(getuid());
    remove_call_out("check_timeout");
    call_out("check_timeout",10);

    remove_call_out("check_mxp_service");
    call_out("check_mxp_service",60);
    
  /*  chdict = allocate(2300);
    line = read_file("/adm/etc/fullme_words.txt",i+1,1);
    while(sizeof(line) > 0)
    {
        line = replace_string(line,"\n","");
        line = replace_string(line,"\r","");
        chdict[i] = line;
        i++;
        dict_size++;
        line = read_file("/adm/etc/fullme_words.txt",i+1,1);
        if(i%100) reset_eval_cost();
    }*/
}
/*
string* chdict = ({"以","成","到","日","民","来","我","部","对","进","多","全","建","他",
        "公","开","们","场","展","时","理","新","方","主","企","资","实","学","报","制","政",
        "济","用","同","于","法","高","长","现","本","月","定","化","加","动","合","品","重",
        "关","机","分","力","自","外","者","区","能","设","后","就","等","体","下","万","元",
        "社","过","前","面","农","也","得","与","说","之","员","而","务","利","电","文","事",
        "可","种","总","改","三","各","好","金","第","司","其","从","平","代","当","天","水",
        "省","提","商","十","管","内","小","技","位","目","起","海","所","立","已","通","入",
        "量","子","问","度","北","保","心","还","科","委","都","术","使","明","着","次","将",
        "增","基","名","向","门","应","里","美","由","规","今","题","记","点","计","去","强",
        "两","些","表","系","办","教","正","条","最","达","特","革","收","二","期","并","程",
        "厂","如","道","际","及","西","口","京","华","任","调","性","导","组","东","路","活",
        "广","意","比","投","决","交","统","党","南","安","此","领","结","营","项","情","解",
        "议","义","山","先","车","然","价","放","世","间","因","共","院","步","物","界","集",
        "把","持","无","但","城","相","书","村","求","治","取","原","处","府","研","质","信",
        "四","运","县","军","件","育","局","干","队","团","又","造","形","级","标","联","专",
        "少","费","效","据","手","施","权","江","近","深","更","认","果","格","几","看","没",
        "职","服","台","式","益","想","数","单","样","只","被","亿","老","受","优","常","销",
        "志","战","流","很","接","乡","头","给","至","难","观","指","创","证","织","论","别",
        "五","协","变","风","批","见","究","支","那","查","张","精","每","林","转","划","准",
        "做","需","传","争","税","构","具","百","或","才","积","势","举","必","型","易","视",
        "快","李","参","回","引","镇","首","推","思","完","消","值","该","走","装","众","责",
        "备","州","供","包","副","极","整","确","知","贸","己","环","话","反","身","选","亚",
        "么","带","采","王","策","真","女","谈","严","斯","况","色","打","德","告","仅","它",
        "气","料","神","率","识","劳","境","源","青","护","列","兴","许","户","马","港","则",
        "节","款","拉","直","案","股","光","较","河","花","根","布","线","土","克","再","群",
        "医","清","速","律","她","族","历","非","感","占","续","师","何","影","功","负","验",
        "望","财","类","货","约","艺","售","连","纪","按","讯","史","示","象","养","获","石",
        "食","抓","富","模","始","住","赛","客","越","闻","央","席","坚","的","味","冰","欢",
        "刀","枪","剑","戟","虎","豹","豺","狼","浑","噩","熙","攘","匆","忙","爱","愚","笨",
        "虫","傻","帽","儿","恋","贱","人","氓","熊","怂","插","菊","阳","斧","钺","钩","叉"});
        */

//产生一个随机字符串，并且写入到/web/下一个临时文件里
//从web访问这个文件，将会以图片的方式显示，当然包括适当的
//干扰，玩家必须在mud里输入这个字符串。
string* generatewebimgcode(int size)
{
        int filesize = 0;
    string* ret = ({});
    string* dict = ({"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R",
        "S","T","U","V","W","X","Y","Z"});
    string code = "";
    string filename = "";

    if(undefinedp(size) || size < 4 || size > 10) size = 4;     

        filesize = file_size("/adm/etc/fullme_dict.txt");
        filesize = filesize/8*8;
        if(filesize == 0)
        {
                code = code + dict[random(sizeof(dict))];
                code = code + dict[random(sizeof(dict))];
                code = code + dict[random(sizeof(dict))];
                code = code + dict[random(sizeof(dict))];
        }
        else
        {
                code = read_bytes("/adm/etc/fullme_dict.txt",random(filesize/8)*8,8);
                code = replace_string(code," ","");
        }       

    //generate uid and create file with those name, with the code inside under /web/antirobot
    //理论上这个文件名可能重复，不过概率不高。没找到guid的lpc算法。
    filename = sprintf("%d%d",time(),random(1000000));
    write_file("/web/antirobot/"+filename,code,1);
    ret += ({code,filename});
    return ret;
}

string* mxpantirobot(object user)
{
        string* info;
        string MUD_HOST;
        info = generatewebimgcode(4);
        tell_object(user,"如果你的客户端不支持MXP，请打开浏览器访问以下链接获取验证码。\r\n");
        if(user->query("env/edu") == 1)
        {
                MUD_HOST = MUD_EDU_WEB;
        }
        else
        {
                MUD_HOST = MUD_WEB;
        }

        tell_object(user,MUD_HOST+"/antirobot/robot.php?filename="+info[1]+"\r\n");
        tell_object(user,"\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
        SendImage(user,info[1]+".jpg",300,100,"left",MUD_HOST+"/antirobot/zmud/");
        return info;
}


//检查/web/antirobot下的所有文件，凡是创建时间超过1分钟的都删除掉
int check_timeout()
{
    int lasttime;
    string* files = get_dir("/web/antirobot/",-1);
    
    for(int i=0;i<sizeof(files);i++)
    {
        lasttime = files[i][2];    
        if(time() - lasttime > 180)
        {
            rm("/web/antirobot/"+files[i][0]);
        }
    }
    remove_call_out("check_timeout");
    call_out("check_timeout",10);    
    return 1;
}

int check_mxp_service()
{
        is_stopped = 0;
        return 0;
        if(file_size(MXP_SERVICE_STATUS_FILE) >= 0)
        {
                is_stopped = 0;
        }
        else
        {
                is_stopped = 1;
        }
    remove_call_out("check_mxp_service");
    call_out("check_mxp_service",10);    
        return 0;
}

int stopped()
{
        return is_stopped;
}
